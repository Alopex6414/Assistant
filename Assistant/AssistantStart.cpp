/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017~2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		AssistantStart.cpp
* @brief	This Program is Assistant Project.
* @author	Alopex/Helium
* @version	v1.00a
* @date		2018-07-14	v1.00a	alopex	Create Project
*/
#include "AssistantStart.h"

//------------------------------------------------------------------
// @Function:	 CAssistantStart()
// @Purpose: CAssistantStart构造函数
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
CAssistantStart::CAssistantStart()
{
	m_pD3D9Device = NULL;
	m_pMainBackGround = NULL;
	m_pMainLogo = NULL;
	m_pMainCopy = NULL;
	m_pMainLua = NULL;
}

//------------------------------------------------------------------
// @Function:	 ~CAssistantStart()
// @Purpose: CAssistantStart析构函数
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
CAssistantStart::~CAssistantStart()
{
	SAFE_DELETE(m_pMainLua);
	SAFE_DELETE(m_pMainCopy);
	SAFE_DELETE(m_pMainLogo);
	SAFE_DELETE(m_pMainBackGround);
}

//------------------------------------------------------------------
// @Function:	 CAssistantStart()
// @Purpose: CAssistantStart构造函数
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
CAssistantStart::CAssistantStart(IDirect3DDevice9* pD3D9Device)
{
	m_pD3D9Device = pD3D9Device;
	m_pMainBackGround = NULL;
	m_pMainLogo = NULL;
	m_pMainCopy = NULL;
	m_pMainLua = NULL;
}

//------------------------------------------------------------------
// @Function:	 AssistantStartInit()
// @Purpose: CAssistantStart初始化
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
BOOL CAssistantStart::AssistantStartInit()
{
	HRESULT hr;

	//初始化lua脚本
	BOOL bRet = FALSE;
	m_pMainLua = new CAssistantLua("\\script\\AssistantStart.lua");
	bRet = m_pMainLua->AssistantLuaInit();
	if (!bRet)
	{
		return FALSE;
	}

	//PlumPack解包纹理
	CPlumPack cPlumPackBack;
	CPlumPack cPlumPackLogo;
	CPlumPack cPlumPackCopy;
	char chBackGroundTex[10240] = { 0 };
	char chBackGround[MAX_PATH] = { 0 };
	char chLogoTex[10240] = { 0 };
	char chLogo[MAX_PATH] = { 0 };
	char chCopyTex[4096] = { 0 };
	char chCopy[MAX_PATH] = { 0 };

	CPlumPath::PlumPathGetLocalPathA(chBackGround, MAX_PATH);
	strcat_s(chBackGround, "\\data\\AssistantStart_a.pak");
	cPlumPackBack.PlumUnPackFileStoreInMemoryA(chBackGround, chBackGroundTex, sizeof(chBackGroundTex));

	CPlumPath::PlumPathGetLocalPathA(chLogo, MAX_PATH);
	strcat_s(chLogo, "\\data\\AssistantStart_b.pak");
	cPlumPackLogo.PlumUnPackFileStoreInMemoryA(chLogo, chLogoTex, sizeof(chLogoTex));

	CPlumPath::PlumPathGetLocalPathA(chCopy, MAX_PATH);
	strcat_s(chCopy, "\\data\\AssistantStart_c.pak");
	cPlumPackCopy.PlumUnPackFileStoreInMemoryA(chCopy, chCopyTex, sizeof(chCopyTex));

	//初始化参数
	CUUintEx sUintBack = { 0 };
	sUintBack.nScreenWidth = USER_SCREENWIDTH;
	sUintBack.nScreenHeight = USER_SCREENHEIGHT;
	sUintBack.pTextureArr = chBackGroundTex;
	sUintBack.nTextureArrSize = sizeof(chBackGroundTex);
	sUintBack.nTextureWidth = 1024;
	sUintBack.nTextureHeight = 1024;
	sUintBack.rcUnit = { 0, 0, 960, 720 };
	sUintBack.rcUnitTex = { 0, 0, 960, 720 };
	sUintBack.fUnitAlpha = 1.0f;
	sUintBack.sCoordsTransformPara.sWorldTransformPara.sScalePara.fScaleX = 1.0f;
	sUintBack.sCoordsTransformPara.sWorldTransformPara.sScalePara.fScaleY = 1.0f;
	sUintBack.sCoordsTransformPara.sWorldTransformPara.sScalePara.fScaleZ = 1.0f;
	sUintBack.sCoordsTransformPara.sWorldTransformPara.sRotatePara.fRotateX = 0.0f;
	sUintBack.sCoordsTransformPara.sWorldTransformPara.sRotatePara.fRotateY = 0.0f;
	sUintBack.sCoordsTransformPara.sWorldTransformPara.sRotatePara.fRotateZ = 0.0f;
	sUintBack.sCoordsTransformPara.sWorldTransformPara.sTranslatePara.fTranslateX = 0.0f;
	sUintBack.sCoordsTransformPara.sWorldTransformPara.sTranslatePara.fTranslateY = 0.0f;
	sUintBack.sCoordsTransformPara.sWorldTransformPara.sTranslatePara.fTranslateZ = 0.0f;

	CUUintEx sUintLogo = { 0 };
	sUintLogo.nScreenWidth = USER_SCREENWIDTH;
	sUintLogo.nScreenHeight = USER_SCREENHEIGHT;
	sUintLogo.pTextureArr = chLogoTex;
	sUintLogo.nTextureArrSize = sizeof(chLogoTex);
	sUintLogo.nTextureWidth = 512;
	sUintLogo.nTextureHeight = 128;
	sUintLogo.rcUnit = { 297, 295, 662, 360 };
	sUintLogo.rcUnitTex = { 0, 0, 365, 65 };
	sUintLogo.fUnitAlpha = 1.0f;
	sUintLogo.sCoordsTransformPara.sWorldTransformPara.sScalePara.fScaleX = 1.0f;
	sUintLogo.sCoordsTransformPara.sWorldTransformPara.sScalePara.fScaleY = 1.0f;
	sUintLogo.sCoordsTransformPara.sWorldTransformPara.sScalePara.fScaleZ = 1.0f;
	sUintLogo.sCoordsTransformPara.sWorldTransformPara.sRotatePara.fRotateX = 0.0f;
	sUintLogo.sCoordsTransformPara.sWorldTransformPara.sRotatePara.fRotateY = 0.0f;
	sUintLogo.sCoordsTransformPara.sWorldTransformPara.sRotatePara.fRotateZ = 0.0f;
	sUintLogo.sCoordsTransformPara.sWorldTransformPara.sTranslatePara.fTranslateX = 0.0f;
	sUintLogo.sCoordsTransformPara.sWorldTransformPara.sTranslatePara.fTranslateY = 0.0f;
	sUintLogo.sCoordsTransformPara.sWorldTransformPara.sTranslatePara.fTranslateZ = 0.0f;

	CUUintEx sUintCopy = { 0 };
	sUintCopy.nScreenWidth = USER_SCREENWIDTH;
	sUintCopy.nScreenHeight = USER_SCREENHEIGHT;
	sUintCopy.pTextureArr = chCopyTex;
	sUintCopy.nTextureArrSize = sizeof(chCopyTex);
	sUintCopy.nTextureWidth = 512;
	sUintCopy.nTextureHeight = 64;
	sUintCopy.rcUnit = { 334, 380, 625, 396 };
	sUintCopy.rcUnitTex = { 0, 0, 291, 16 };
	sUintCopy.fUnitAlpha = 1.0f;
	sUintCopy.sCoordsTransformPara.sWorldTransformPara.sScalePara.fScaleX = 1.0f;
	sUintCopy.sCoordsTransformPara.sWorldTransformPara.sScalePara.fScaleY = 1.0f;
	sUintCopy.sCoordsTransformPara.sWorldTransformPara.sScalePara.fScaleZ = 1.0f;
	sUintCopy.sCoordsTransformPara.sWorldTransformPara.sRotatePara.fRotateX = 0.0f;
	sUintCopy.sCoordsTransformPara.sWorldTransformPara.sRotatePara.fRotateY = 0.0f;
	sUintCopy.sCoordsTransformPara.sWorldTransformPara.sRotatePara.fRotateZ = 0.0f;
	sUintCopy.sCoordsTransformPara.sWorldTransformPara.sTranslatePara.fTranslateX = 0.0f;
	sUintCopy.sCoordsTransformPara.sWorldTransformPara.sTranslatePara.fTranslateY = 0.0f;
	sUintCopy.sCoordsTransformPara.sWorldTransformPara.sTranslatePara.fTranslateZ = 0.0f;

	//CCerasusUnit初始化背景
	m_pMainBackGround = new CCerasusUnit(m_pD3D9Device);
	hr = m_pMainBackGround->CCerasusUnitInit(sUintBack);
	if (FAILED(hr))
	{
		return FALSE;
	}

	//CCerasusUnit初始化Logo
	m_pMainLogo = new CCerasusUnit(m_pD3D9Device);
	hr = m_pMainLogo->CCerasusUnitInit(sUintLogo);
	if (FAILED(hr))
	{
		return FALSE;
	}

	//CCerasusUnit初始化Copy
	m_pMainCopy = new CCerasusUnit(m_pD3D9Device);
	hr = m_pMainCopy->CCerasusUnitInit(sUintCopy);
	if (FAILED(hr))
	{
		return FALSE;
	}

	return TRUE;
}

//------------------------------------------------------------------
// @Function:	 AssistantStartReset()
// @Purpose: CAssistantStart重置
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
void CAssistantStart::AssistantStartReset()
{
	m_pMainBackGround->CCerasusUnitReset();
	m_pMainLogo->CCerasusUnitReset();
	m_pMainCopy->CCerasusUnitReset();
}

//------------------------------------------------------------------
// @Function:	 AssistantStartUpdate()
// @Purpose: CAssistantStart刷新
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
void CAssistantStart::AssistantStartUpdate(float fDeltaTime)
{
	static float fTimeSum = 0.0f;

	fTimeSum += fDeltaTime;

	if (fTimeSum < 0.5f)	//开始时间0.0s~0.5s时保持黑色屏幕,Alpha通道值为0.0f
	{
		m_pMainBackGround->CCerasusUnitGetAlpha() = 0.0f;	//背景Alpha通道值为0.0f
		m_pMainLogo->CCerasusUnitGetAlpha() = 0.0f;			//LogoAlpha通道值为0.0f
		m_pMainCopy->CCerasusUnitGetAlpha() = 0.0f;			//版权Alpha通道值为0.0f

		m_pMainLogo->CCerasusUnitGetTranslateZ() = -100.0f;
		m_pMainCopy->CCerasusUnitGetTranslateZ() = -100.0f;
	}
	else if (fTimeSum < 3.0f)	//开始时间0.5s~3.0s时背景渐变,Alpha通道值增加
	{
		//Alapha通道值变化
		m_pMainBackGround->CCerasusUnitGetAlpha() += 0.01f;
		if (m_pMainBackGround->CCerasusUnitGetAlpha() >= 1.0f)
		{
			m_pMainBackGround->CCerasusUnitGetAlpha() = 1.0f;
		}

		m_pMainLogo->CCerasusUnitGetAlpha() += 0.01f;
		if (m_pMainLogo->CCerasusUnitGetAlpha() >= 1.0f)
		{
			m_pMainLogo->CCerasusUnitGetAlpha() = 1.0f;
		}

		m_pMainCopy->CCerasusUnitGetAlpha() += 0.01f;
		if (m_pMainCopy->CCerasusUnitGetAlpha() >= 1.0f)
		{
			m_pMainCopy->CCerasusUnitGetAlpha() = 1.0f;
		}

		//图元位移变换
		m_pMainLogo->CCerasusUnitGetTranslateZ() += 1.0f;
		if (m_pMainLogo->CCerasusUnitGetTranslateZ() >= -1.0f)
		{
			m_pMainLogo->CCerasusUnitGetTranslateZ() = -1.0f;
		}

		m_pMainCopy->CCerasusUnitGetTranslateZ() += 1.0f;
		if (m_pMainCopy->CCerasusUnitGetTranslateZ() >= -1.0f)
		{
			m_pMainCopy->CCerasusUnitGetTranslateZ() = -1.0f;
		}
	}
	else
	{
		m_pMainBackGround->CCerasusUnitGetAlpha() = 1.0f;	//背景Alpha通道值为0.0f
		m_pMainLogo->CCerasusUnitGetAlpha() = 1.0f;			//LogoAlpha通道值为0.0f
		m_pMainCopy->CCerasusUnitGetAlpha() = 1.0f;			//版权Alpha通道值为0.0f

		m_pMainLogo->CCerasusUnitGetTranslateZ() = -1.0f;
		m_pMainCopy->CCerasusUnitGetTranslateZ() = -1.0f;
	}

	m_pMainBackGround->CCerasusUnitPaddingVertexAndIndex();
	m_pMainLogo->CCerasusUnitPaddingVertexAndIndex();
	m_pMainCopy->CCerasusUnitPaddingVertexAndIndex();
}

//------------------------------------------------------------------
// @Function:	 AssistantStartRender()
// @Purpose: CAssistantStart渲染
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
void CAssistantStart::AssistantStartRender(float fDeltaTime)
{
	m_pMainBackGround->CCerasusUnitMatrixTransform();
	m_pMainBackGround->CCerasusUnitSetAlphaBlendEnable();
	m_pMainBackGround->CCerasusUnitSetRenderState();
	m_pMainBackGround->CCerasusUnitRender();
	m_pMainBackGround->CCerasusUnitSetAlphaBlendDisable();

	m_pMainLogo->CCerasusUnitMatrixTransform();
	m_pMainLogo->CCerasusUnitSetAlphaBlendEnable();
	m_pMainLogo->CCerasusUnitSetRenderState();
	m_pMainLogo->CCerasusUnitRender();
	m_pMainLogo->CCerasusUnitSetAlphaBlendDisable();

	m_pMainCopy->CCerasusUnitMatrixTransform();
	m_pMainCopy->CCerasusUnitSetAlphaBlendEnable();
	m_pMainCopy->CCerasusUnitSetRenderState();
	m_pMainCopy->CCerasusUnitRender();
	m_pMainCopy->CCerasusUnitSetAlphaBlendDisable();
}
