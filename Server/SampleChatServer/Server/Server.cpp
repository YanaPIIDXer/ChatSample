#include "Server.h"
#include <functional>
#include "../Peer/Peer.h"
#include "../Packet/PacketMessage.h"
#include "YanaPOnlineUtil/Stream/MemorySizeCaliculator.h"
#include "YanaPOnlineUtil/Stream/MemoryStreamWriter.h"
#include <iostream>

// コンストラクタ
Server::Server()
	: CApplicationBase(std::bind(&Server::OnPeerConnected, this, std::placeholders::_1))
	, NextUuid(1)
{
}

// デストラクタ
Server::~Server()
{
}

// ブロードキャスト
void Server::Broadcast(Peer *pFrom, const char *pData, unsigned int Size)
{
	PacketBroadcastMessage Packet;
	Packet.Uuid = pFrom->GetUuid();
	Packet.Message = pData;

	CMemorySizeCaliculator SizeCaliculator;
	Packet.Serialize(&SizeCaliculator);

	CMemoryStreamWriter StreamWriter(SizeCaliculator.GetSize());
	if (!Packet.Serialize(&StreamWriter))
	{
		std::cout << "Packet Serialize Failed." << std::endl;
		return;
	}

	for (auto It = PeerList.begin(); It != PeerList.end(); ++It)
	{
		if (!It->expired() && It->lock().get() != pFrom)
		{
			It->lock()->Send(StreamWriter.GetBuffer(), StreamWriter.GetSize());
		}
	}
}


// Peer生成.
CPeerBase *Server::CreatePeer(ISocket *pSocket)
{
	int Uuid = NextUuid;
	NextUuid++;
	return new Peer(this, Uuid, pSocket);
}

// 更新.
bool Server::Update()
{
	for (auto It = PeerList.begin(); It != PeerList.end();)
	{
		if (It->expired())
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
