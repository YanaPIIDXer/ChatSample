using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using YanaPOnlineUtil;
using YanaPOnlineUtil.Stream;

namespace ChatSampleClient
{
	/// <summary>
	/// メッセージブロードキャストパケット
	/// </summary>
	public class PacketBroadcastMessage : ISerializable
	{

		/// <summary>
		/// UUID
		/// </summary>
		public int Uuid;

		/// <summary>
		/// メッセージ
		/// </summary>
		public string Message;

		/// <summary>
		/// コンストラクタ
		/// </summary>
		public PacketBroadcastMessage()
		{
			Uuid = 0;
			Message = "";
		}

		/// <summary>
		/// シリアライズ
		/// </summary>
		/// <param name="Stream">ストリーム</param>
		/// <returns>成功したらtrueを返す</returns>
		public bool Serialize(IMemoryStream Stream)
		{
			if(!Stream.Serialize(ref Uuid)) { return false; }
			if(!Stream.Serialize(ref Message)) { return false; }
			return true;
		}
	}
}
