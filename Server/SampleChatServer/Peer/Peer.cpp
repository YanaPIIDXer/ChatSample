#include "Peer.h"
#include "../Server/Server.h"

// �R���X�g���N�^
Peer::Peer(Server *pInServer, int InUuid, ISocket *pInSocket)
	: CPeerBase(pInSocket)
	, pServer(pInServer)
	, Uuid(InUuid)
{
}

// �f�X�g���N�^
Peer::~Peer()
{
}

// �f�[�^����M�����B
void Peer::OnRecv(const char *pData, unsigned int Size)
{
	pServer->Broadcast(this, pData, Size);
}
