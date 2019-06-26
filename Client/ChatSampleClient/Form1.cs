using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Net.Sockets;
using YanaPOnlineUtil.Stream;

namespace ChatSampleClient
{
	public partial class Form1 : Form
	{
		/// <summary>
		/// ソケット
		/// </summary>
		Socket Sock = null;

		/// <summary>
		/// バッファ長
		/// </summary>
		private static readonly int BufferSize = 2048;

		/// <summary>
		/// バッファ
		/// </summary>
		private byte[] Buffer = new byte[BufferSize];

		public Form1()
		{
			InitializeComponent();
		}

		// フォームが読み込まれた。
		private void Form1_Load(object sender, EventArgs e)
		{
			try
			{
				Sock = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
				Sock.Connect("127.0.0.1", 1234);
				Sock.BeginReceive(Buffer, 0, BufferSize, SocketFlags.None, new AsyncCallback(ReceiveCallback), Sock);
			}
			catch(Exception Ex)
			{
				MessageBox.Show("接続に失敗しました。\n" + Ex.Message);
				Sock = null;
			}
		}

		// 送信ボタンが押された。
		private void SendButton_Click(object sender, EventArgs e)
		{
			SendData();
		}
		
		/// <summary>
		/// データ送信
		/// </summary>
		private void SendData()
		{
			string SendText = InputField.Text;
			InputField.Text = "";
			ChatField.Text += "SEND:" + SendText + Environment.NewLine;

			if (Sock == null) { return; }

			byte[] SendBuffer = Encoding.UTF8.GetBytes(SendText);
			Sock.Send(SendBuffer);
		}

		/// <summary>
		/// 受信コールバック
		/// </summary>
		/// <param name="Result">受信結果</param>
		private void ReceiveCallback(IAsyncResult Result)
		{
			var Sk = Result.AsyncState as Socket;

			var RecvSize = -1;
			try
			{
				RecvSize = Sk.EndReceive(Result);
			}
			catch { return; }

			if (RecvSize > 0)
			{
				MemoryStreamReader StreamReader = new MemoryStreamReader(Buffer);
				PacketBroadcastMessage Packet = new PacketBroadcastMessage();
				if(!StreamReader.Serialize(Packet))
				{
					ChatField.Text += "PACKET SERIALIZE ERROR." + Environment.NewLine;
					return;
				}

				ChatField.Text += "RECV FROM " + Packet.Uuid + ":" + Packet.Message + Environment.NewLine;
				Sk.BeginReceive(Buffer, 0, BufferSize, SocketFlags.None, ReceiveCallback, Sk);
			}
		}

	}
}
