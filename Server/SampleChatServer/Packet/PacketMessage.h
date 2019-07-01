#ifndef __PACKETMESSAGE_H__
#define __PACKETMESSAGE_H__

#include "YanaPOnlineUtil/Serializable/Serializable.h"

using namespace YanaPOnlineUtil;
using namespace YanaPOnlineUtil::Stream;

// ���b�Z�[�W�u���[�h�L���X�g�p�P�b�g
class PacketBroadcastMessage : public ISerializable
{

public:

	// UUID
	int Uuid;

	// ���b�Z�[�W
	std::string Message;

	// �V���A���C�Y
	virtual bool Serialize(IMemoryStream *pStream) override
	{
		if (!pStream->Serialize(&Uuid)) { return false; }
		if (!pStream->Serialize(&Message)) { return false; }

		return true;
	}
};

#endif		// #ifndef __PACKETMESSAGE_H__
