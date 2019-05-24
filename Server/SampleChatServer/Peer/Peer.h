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
	Peer(Server *pInServer, ISocket *pInSocket);

	// �f�X�g���N�^
	virtual ~Peer();

	// �f�[�^����M�����B
	virtual void OnRecv(const char *pData, unsigned int Size);

private:

	// �T�[�o
	Server *pServer;

};

#endif		// #ifndef __PEER_H__
