#ifndef __PACKETMESSAGE_H__
#define __PACKETMESSAGE_H__

#include "YanaPOnlineUtil/Serializable/Serializable.h"
#include "YanaPOnlineUtil/Stream/MemoryStream.h"

using namespace YanaPOnlineUtil;
using namespace YanaPOnlineUtil::Stream;

// メッセージブロードキャストパケット
class PacketBroadcastMessage : public Serializable::ISerializable
{

public:

	// UUID
	int Uuid;

	// メッセージ
	std::string Message;

	// シリアライズ
	virtual bool Serialize(IMemoryStream *pStream) override
	{
		if (!pStream->Serialize(&Uuid)) { return false; }
		if (!pStream->Serialize(&Message)) { return false; }

		return true;
	}
};

#endif		// #ifndef __PACKETMESSAGE_H__
