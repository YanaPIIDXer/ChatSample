#ifndef __SERVER_H__
#define __SERVER_H__

#include "YanaPServer/Application/ApplicationBase.h"
#include <vector>

using namespace YanaPServer::Application;
using namespace YanaPServer::Peer;
using namespace YanaPServer::Socket;

class Peer;

// �T�[�o
class Server : public CApplicationBase
{

public:

	// �R���X�g���N�^
	Server();

	// �f�X�g���N�^
	virtual ~Server();

	// �u���[�h�L���X�g
	void Broadcast(Peer *pFrom, const char *pData, unsigned int Size);

protected:

	// Peer����.
	virtual CPeerBase *CreatePeer(ISocket *pSocket) override;

	// �X�V.
	virtual bool Update() override;

private:

	// Peer���ڑ����Ă���
	void OnPeerConnected(PeerPtr pPeer);


	// Peer���X�g
	std::vector<PeerPtr> PeerList;

	// ���̂t�t�h�c
	int NextUuid;

};

#endif		// #ifndef __SERVER_H__
