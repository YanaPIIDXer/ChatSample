#include "Peer.h"
#include "../Server/Server.h"

// コンストラクタ
Peer::Peer(Server *pInServer, ISocket *pInSocket)
	: CPeerBase(pInSocket)
	, pServer(pInServer)
{
}

// デストラクタ
Peer::~Peer()
{
}

// データを受信した。
void Peer::OnRecv(const char *pData, unsigned int Size)
{
	pServer->Broadcast(this, pData, Size);
}
