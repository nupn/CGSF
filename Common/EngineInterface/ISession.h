#ifndef ISESSION_H_
#define ISESSION_H_
#include "INetworkEngine.h"
#include "IEngine.h"
#include "ISessionService.h"

class ISession
{
  public:  
	ISession(){}
    virtual ~ISession() {};

	void SetOwner(INetworkEngine* pOwner){m_pOwner = pOwner;}

	virtual void SendInternal(char* pBuffer, int BufferSize, int ownerSerial = -1) = 0;

	void OnConnect(int Serial, bool bServerObject = false)
	{
		m_pSessionService = m_pOwner->GetEngine()->CreateSessionService();
		m_pSessionService->SetSerial(Serial);
		m_pOwner->GetEngine()->OnConnect(Serial, bServerObject);
	}

	void OnDisconnect(int Serial, bool bServerObject = false)
	{
		m_pOwner->GetEngine()->OnDisconnect(Serial, bServerObject);
		delete m_pSessionService;
	}

	bool OnReceive(char* pData, unsigned short Length, bool bServerObject = false)
	{
		return m_pSessionService->OnReceive(pData, Length, bServerObject);
	}

	/*
	bool SendRequest(BasePacket* pPacket)
	{
		return m_pSessionService->SendRequest(this, pPacket);
	}*/

protected:

private:
	INetworkEngine* m_pOwner;
	ISessionService* m_pSessionService;
};


#endif  // ISESSION_H_