#include "Server.h"
#include <functional>
#include "../Peer/Peer.h"
#include "../Packet/PacketMessage.h"
#include "YanaPOnlineUtil/Stream/MemorySizeCaliculator.h"
#include "YanaPOnlineUtil/Stream/MemoryStreamWriter.h"
#include <iostream>

// �R���X�g���N�^
Server::Server()
	: CApplicationBase(std::bind(&Server::OnPeerConnected, this, std::placeholders::_1))
	, NextUuid(1)
{
}

// �f�X�g���N�^
Server::~Server()
{
}

// �u���[�h�L���X�g
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


// Peer����.
CPeerBase *Server::CreatePeer(ISocket *pSocket)
{
	int Uuid = NextUuid;
	NextUuid++;
	return new Peer(this, Uuid, pSocket);
}

// �X�V.
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


// Peer���ڑ����Ă����B
void Server::OnPeerConnected(PeerPtr pPeer)
{
	PeerList.push_back(pPeer);
}
