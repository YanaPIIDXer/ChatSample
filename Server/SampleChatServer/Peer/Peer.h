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

	// �R���X�g���N�^
	Peer(Server *pInServer, int InUuid, ISocket *pInSocket);

	// �f�X�g���N�^
	virtual ~Peer();

	// �f�[�^����M�����B
	virtual void OnRecv(const char *pData, unsigned int Size);

	// UUID�擾.
	int GetUuid() const { return Uuid; }

private:

	// �T�[�o
	Server *pServer;

	// UUID
	int Uuid;

};

#endif		// #ifndef __PEER_H__
