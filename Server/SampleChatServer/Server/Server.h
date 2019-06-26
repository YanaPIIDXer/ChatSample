#ifndef __SERVER_H__
#define __SERVER_H__

#include "YanaPServer/Application/ApplicationBase.h"
#include <vector>

using namespace YanaPServer::Application;
using namespace YanaPServer::Peer;
using namespace YanaPServer::Socket;

class Peer;

// サーバ
class Server : public CApplicationBase
{

public:

	// コンストラクタ
	Server();

	// デストラクタ
	virtual ~Server();

	// ブロードキャスト
	void Broadcast(Peer *pFrom, const char *pData, unsigned int Size);

protected:

	// Peer生成.
	virtual CPeerBase *CreatePeer(ISocket *pSocket) override;

	// 更新.
	virtual bool Update() override;

private:

	// Peerが接続してきた
	void OnPeerConnected(PeerPtr pPeer);


	// Peerリスト
	std::vector<PeerPtr> PeerList;

	// 次のＵＵＩＤ
	int NextUuid;

};

#endif		// #ifndef __SERVER_H__
