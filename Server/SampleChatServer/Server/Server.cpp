#include "Server.h"
#include <functional>
#include "../Peer/Peer.h"

// コンストラクタ
Server::Server()
	: CApplicationBase(std::bind(&Server::OnPeerConnected, this, std::placeholders::_1))
{
}

// デストラクタ
Server::~Server()
{
}

// ブロードキャスト
void Server::Broadcast(Peer *pFrom, const char *pData, unsigned int Size)
{
	for (auto It = PeerList.begin(); It != PeerList.end(); ++It)
	{
		if (It->expired() && It->lock().get() != pFrom)
		{
			It->lock()->Send(pData, Size);
		}
	}
}


// Peer生成.
CPeerBase *Server::CreatePeer(ISocket *pSocket)
{
	return new Peer(this, pSocket);
}

// 更新.
bool Server::Update()
{
	for (auto It = PeerList.begin(); It != PeerList.end();)
	{
		if (!It->expired())
		{
			It = PeerList.erase(It);
		}
		else
		{
			++It;
		}
	}

	return true;
}


// Peerが接続してきた。
void Server::OnPeerConnected(PeerPtr pPeer)
{
	PeerList.push_back(pPeer);
}
