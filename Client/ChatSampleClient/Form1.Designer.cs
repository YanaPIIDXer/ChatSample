namespace ChatSampleClient
{
	partial class Form1
	{
		/// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		/// <param name="disposing">マネージド リソースを破棄する場合は true を指定し、その他の場合は false を指定します。</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing && (components != null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows フォーム デザイナーで生成されたコード

		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
		/// </summary>
		private void InitializeComponent()
		{
			this.InputField = new System.Windows.Forms.TextBox();
			this.SendButton = new System.Windows.Forms.Button();
			this.ChatField = new System.Windows.Forms.RichTextBox();
			this.SuspendLayout();
			// 
			// InputField
			// 
			this.InputField.Location = new System.Drawing.Point(30, 404);
			this.InputField.Name = "InputField";
			this.InputField.Size = new System.Drawing.Size(634, 22);
			this.InputField.TabIndex = 0;
			// 
			// SendButton
			// 
			this.SendButton.Location = new System.Drawing.Point(685, 403);
			this.SendButton.Name = "SendButton";
			this.SendButton.Size = new System.Drawing.Size(75, 23);
			this.SendButton.TabIndex = 1;
			this.SendButton.Text = "送信";
			this.SendButton.UseVisualStyleBackColor = true;
			this.SendButton.Click += new System.EventHandler(this.SendButton_Click);
			// 
			// ChatField
			// 
			this.ChatField.Location = new System.Drawing.Point(39, 12);
			this.ChatField.Name = "ChatField";
			this.ChatField.ReadOnly = true;
			this.ChatField.Size = new System.Drawing.Size(721, 373);
			this.ChatField.TabIndex = 2;
			this.ChatField.Text = "";
			// 
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(800, 450);
			this.Controls.Add(this.ChatField);
			this.Controls.Add(this.SendButton);
			this.Controls.Add(this.InputField);
			this.Name = "Form1";
			this.Text = "ChatSampleClient";
			this.Load += new System.EventHandler(this.Form1_Load);
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.TextBox InputField;
		private System.Windows.Forms.Button SendButton;
		private System.Windows.Forms.RichTextBox ChatField;
	}
}

