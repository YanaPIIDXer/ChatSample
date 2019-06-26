#ifndef __PACKETMESSAGE_H__
#define __PACKETMESSAGE_H__

#include "YanaPServer/Util/Serializable.h"

using namespace YanaPServer::Util;
using namespace YanaPServer::Util::Stream;

// メッセージブロードキャストパケット
class PacketBroadcastMessage : public ISerializable
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
