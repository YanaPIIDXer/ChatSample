#include "Server.h"
#include <functional>
#include "../Peer/Peer.h"

// �R���X�g���N�^
Server::Server()
	: CApplicationBase(std::bind(&Server::OnPeerConnected, this, std::placeholders::_1))
{
}

// �f�X�g���N�^
Server::~Server()
{
}

// �u���[�h�L���X�g
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


// Peer����.
CPeerBase *Server::CreatePeer(ISocket *pSocket)
{
	return new Peer(this, pSocket);
}

// �X�V.
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


// Peer���ڑ����Ă����B
void Server::OnPeerConnected(PeerPtr pPeer)
{
	PeerList.push_back(pPeer);
}
