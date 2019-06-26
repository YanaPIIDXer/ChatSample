#ifndef __PEER_H__
#define __PEER_H__

#include "YanaPServer/Peer/PeerBase.h"

using namespace YanaPServer::Peer;
using namespace YanaPServer::Socket;

class Server;

// Peer
class Peer : public CPeerBase
{
	
public:

	// コンストラクタ
	Peer(Server *pInServer, int InUuid, ISocket *pInSocket);

	// デストラクタ
	virtual ~Peer();

	// データを受信した。
	virtual void OnRecv(const char *pData, unsigned int Size);

	// UUID取得.
	int GetUuid() const { return Uuid; }

private:

	// サーバ
	Server *pServer;

	// UUID
	int Uuid;

};

#endif		// #ifndef __PEER_H__
