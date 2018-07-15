/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017~2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		Assistant.cpp
* @brief	This Program is Assistant Project.
* @author	Alopex/Helium
* @version	v1.00a
* @date		2018-07-14	v1.00a	alopex	Create Project
*/
#include "Assistant.h"

//------------------------------------------------------------------
// @Function:	 CAssistant()
// @Purpose: CAssistant���캯��
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
CAssistant::CAssistant()
{
	m_pDirectGraphics = NULL;
	m_pCerasusfps = NULL;

	m_pAssistantStart = NULL;

	m_fTimeSum = 0.0f;
}

//------------------------------------------------------------------
// @Function:	 ~CAssistant()
// @Purpose: CAssistant��������
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
CAssistant::~CAssistant()
{
	SAFE_DELETE(m_pAssistantStart);

	SAFE_DELETE(m_pCerasusfps);
	SAFE_DELETE(m_pDirectGraphics);
}

//------------------------------------------------------------------
// @Function:	 AssistantInit()
// @Purpose: CAssistant��ʼ��
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
BOOL CAssistant::AssistantInit()
{
	HRESULT hr;
	BOOL bRet = FALSE;
	IDirect3DDevice9* pD3D9Device = NULL;

	//DirectGraphics��ʼ��
	m_pDirectGraphics = new DirectGraphics();
	hr = m_pDirectGraphics->DirectGraphicsInit(g_hWnd, true, USER_SCREENWIDTH, USER_SCREENHEIGHT);
	if (FAILED(hr))
	{
		MessageBox(g_hWnd, _T("DirectGraphics��ʼ��ʧ��!"), _T("����"), MB_OK | MB_ICONERROR);
		return FALSE;
	}

	hr = m_pDirectGraphics->DirectGraphicsFontInit(20);
	if (FAILED(hr))
	{
		MessageBox(g_hWnd, _T("DirectFont��ʼ��ʧ��!"), _T("����"), MB_OK | MB_ICONERROR);
		return FALSE;
	}

	pD3D9Device = m_pDirectGraphics->DirectGraphicsGetDevice();

	//Cerasusfps��ʼ��
	m_pCerasusfps = new CCerasusfps(pD3D9Device);
	hr = m_pCerasusfps->CCerasusfpsInit(20);
	if (FAILED(hr))
	{
		MessageBox(g_hWnd, _T("Cerasusfps��ʼ��ʧ��!"), _T("����"), MB_OK | MB_ICONERROR);
		return FALSE;
	}

	//AssistantStart��ʼ��
	m_pAssistantStart = new CAssistantStart(pD3D9Device);
	bRet = m_pAssistantStart->AssistantStartInit();
	if (!bRet)
	{
		return FALSE;
	}

	return TRUE;
}

//------------------------------------------------------------------
// @Function:	 AssistantRelease()
// @Purpose: CAssistant�ͷ�
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
void CAssistant::AssistantRelease()
{
	SAFE_DELETE(m_pCerasusfps);
	SAFE_DELETE(m_pDirectGraphics);
}

//------------------------------------------------------------------
// @Function:	 AssistantUpdate()
// @Purpose: CAssistantͬ��
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
void CAssistant::AssistantUpdate()
{
	HRESULT hr;

	hr = m_pDirectGraphics->DirectGraphicsTestCooperativeLevel();
	if (hr != S_OK)
	{
		if (hr == D3DERR_DEVICELOST)
		{
			return;
		}

		if (hr == D3DERR_DEVICENOTRESET)
		{
			m_pAssistantStart->AssistantStartReset();

			m_pCerasusfps->CCerasusfpsReset();
			m_pDirectGraphics->DirectGraphicsReset();
		}

	}

	m_fTimeSum += g_fDeltaTime;

	m_pAssistantStart->AssistantStartUpdate(g_fDeltaTime);

}

//------------------------------------------------------------------
// @Function:	 AssistantRender()
// @Purpose: CAssistant��Ⱦ
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
void CAssistant::AssistantRender()
{
	m_pDirectGraphics->DirectGraphicsBegin();

	//AssistantStart���Ƴ���
	m_pAssistantStart->AssistantStartRender(g_fDeltaTime);

	//DirectGraphics������Ϣ
	AssistantDrawStatic();
	AssistantDrawFPS();

	m_pDirectGraphics->DirectGraphicsEnd();
}

//------------------------------------------------------------------
// @Function:	 AssistantDrawStatic()
// @Purpose: CAssistant������Ļ�Կ���Ϣ
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
void CAssistant::AssistantDrawStatic()
{
	RECT Rect;

	GetClientRect(g_hWnd, &Rect);

	//Direct3D �����Կ���Ϣ
	Rect.top += 0;
	m_pDirectGraphics->DirectGraphicsFontDrawTextAdapterType(&Rect, DT_TOP | DT_LEFT, D3DXCOLOR(1.0f, 0.5f, 0.5f, 1.0f));

	//Direct3D ������Ļ�ֱ���
	Rect.top += 20;
	m_pDirectGraphics->DirectGraphicsFontDrawTextScreen(&Rect, DT_TOP | DT_LEFT, D3DXCOLOR(1.0f, 1.0f, 0.5f, 1.0f));

	//Direct3D ���ƻ���ģ��
	Rect.top += 20;
	m_pDirectGraphics->DirectGraphicsFontDrawTextFormat(&Rect, DT_TOP | DT_LEFT, D3DXCOLOR(1.0f, 1.0f, 0.5f, 1.0f));

}

//------------------------------------------------------------------
// @Function:	 AssistantDrawFPS()
// @Purpose: CAssistant����fps��Ϣ
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
void CAssistant::AssistantDrawFPS()
{
	m_pCerasusfps->CCerasusfpsGetfps();				//Direct3D��ȡfps
	m_pCerasusfps->CCerasusfpsDrawfps(g_hWnd);		//Direct3D����fps
}