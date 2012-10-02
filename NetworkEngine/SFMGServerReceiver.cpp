#include "stdafx.h"
#include "SFMGServerReceiver.h"


SFMGServerReceiver::SFMGServerReceiver(void)
{
}


SFMGServerReceiver::~SFMGServerReceiver(void)
{
}

void SFMGServerReceiver::notifyRegisterSocket(ASSOCKDESCEX& sockdesc, SOCKADDR_IN& ip)
{
	printf(" Connected %d\n", sockdesc.assockUid);

	SFPacket* pCommand = PacketPoolSingleton::instance()->Alloc();
	pCommand->SetPacketType(SFCommand_Connect);
	pCommand->SetOwnerSerial(sockdesc.assockUid);

	LogicGatewaySingleton::instance()->PushPacket(pCommand);

	Synchronized es(&m_SessionLock);
	m_SessionMap.insert(std::make_pair(sockdesc.assockUid, sockdesc));
}

void SFMGServerReceiver::notifyReleaseSocket(ASSOCKDESCEX& sockdesc)
{
	printf("Disconnected %d\n", sockdesc.assockUid);

	SFPacket* pCommand = PacketPoolSingleton::instance()->Alloc();
	pCommand->SetPacketType(SFCommand_Disconnect);
	pCommand->SetOwnerSerial(sockdesc.assockUid);

	LogicGatewaySingleton::instance()->PushPacket(pCommand);

	Synchronized es(&m_SessionLock);
           
	m_SessionMap.erase(sockdesc.assockUid);

	sockdesc.psender->releaseSocketUniqueId(sockdesc.assockUid);
}

void SFMGServerReceiver::notifyMessage(ASSOCKDESCEX& sockdesc, size_t length, char* data)
{
	m_BufferAnalyzer.AddTransferredData(data, length);

	int ErrorCode = PACKETIO_ERROR_NONE;

	SFPacket* pPacket = PacketPoolSingleton::instance()->Alloc();

	while(TRUE ==  m_BufferAnalyzer.GetPacket(*pPacket, ErrorCode))
	{
		pPacket->SetPacketType(SFCommand_Data);
		pPacket->SetOwnerSerial(sockdesc.assockUid);

		LogicGatewaySingleton::instance()->PushPacket(pPacket);

		pPacket = PacketPoolSingleton::instance()->Alloc();
		pPacket->Initialize();
	}

	PacketPoolSingleton::instance()->Release(pPacket);

	if(ErrorCode != PACKETIO_ERROR_NONE)
	{
//////////////////////////////////////////////////////////////////////////
//이 부분 처리를 고민해야 한다.
//////////////////////////////////////////////////////////////////////////
		SFASSERT(0);
		return;
	}
}

void SFMGServerReceiver::notifyConnectingResult(INT32 requestID, ASSOCKDESCEX& sockdesc, DWORD error)
{

}

BOOL SFMGServerReceiver::Send(int Serial, USHORT PacketID, char* pMessage, int BufSize )
{
	int HeaderSize = sizeof(SFPacketHeader);

	SFPacket PacketSend;

	PacketSend.SetPacketID(PacketID);

	PacketSend.MakePacket((BYTE*)pMessage, BufSize, CGSF_PACKET_OPTION);

	return Send(Serial, &PacketSend);
}

BOOL SFMGServerReceiver::Send(int Serial, SFPacket* pPacket)
{
	Synchronized es(&m_SessionLock);

	SessionMap::iterator iter = m_SessionMap.find(Serial);

	if(iter == m_SessionMap.end())
	{
		return FALSE;
	}

	iter->second.psender->postingSend(iter->second, pPacket->GetHeaderSize() + pPacket->GetDataSize(), (char*)pPacket->GetHeader());

	return TRUE;
}

