#include "Peer.h"
#include "../Server/Server.h"

// コンストラクタ
Peer::Peer(Server *pInServer, int InUuid, ISocket *pInSocket)
	: CPeerBase(pInSocket)
	, pServer(pInServer)
	, Uuid(InUuid)
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
