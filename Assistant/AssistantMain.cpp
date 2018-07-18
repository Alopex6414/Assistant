/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017~2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		AssistantMain.cpp
* @brief	This Program is Assistant Project.
* @author	Alopex/Helium
* @version	v1.00a
* @date		2018-07-15	v1.00a	alopex	Create Project
*/
#include "AssistantMain.h"

//------------------------------------------------------------------
// @Function:	 CAssistantMain()
// @Purpose: CAssistantMain构造函数
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
CAssistantMain::CAssistantMain()
{
	m_pD3D9Device = NULL;
	m_pMainBackGround = NULL;
	m_pMainBackMenu = NULL;
	m_pMainLogo = NULL;
	m_pMainApps = NULL;

	m_pMainLua = NULL;
}

//------------------------------------------------------------------
// @Function:	 ~CAssistantMain()
// @Purpose: CAssistantMain析构函数
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
CAssistantMain::~CAssistantMain()
{
	SAFE_DELETE(m_pMainApps);

	SAFE_DELETE(m_pMainApps);
	SAFE_DELETE(m_pMainLogo);
	SAFE_DELETE(m_pMainBackMenu);
	SAFE_DELETE(m_pMainBackGround);
}

//------------------------------------------------------------------
// @Function:	 CAssistantMain()
// @Purpose: CAssistantMain构造函数
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
CAssistantMain::CAssistantMain(IDirect3DDevice9* pD3D9Device)
{
	m_pD3D9Device = pD3D9Device;
	m_pMainBackGround = NULL;
	m_pMainBackMenu = NULL;
	m_pMainLogo = NULL;
	m_pMainApps = NULL;

	m_pMainLua = NULL;
}

//------------------------------------------------------------------
// @Function:	 AssistantMainInit()
// @Purpose: CAssistantMain初始化
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
BOOL CAssistantMain::AssistantMainInit()
{
	HRESULT hr;

	//初始化lua脚本
	BOOL bRet = FALSE;
	m_pMainLua = new CAssistantLua("\\script\\AssistantMain.lua");
	bRet = m_pMainLua->AssistantLuaInit();
	if (!bRet)
	{
		return FALSE;
	}

	//PlumPack解包纹理
	CPlumPack cPlumPackBk;
	CPlumPack cPlumPackMenu;
	CPlumPack cPlumPackLogo;
	CPlumPack cPlumPackApp;
	char chBackGroundTex[8192] = { 0 };
	char chBackGround[MAX_PATH] = { 0 };
	char chBackMenuTex[4096] = { 0 };
	char chBackMenu[MAX_PATH] = { 0 };
	char chLogoTex[4096] = { 0 };
	char chLogo[MAX_PATH] = { 0 };
	char chAppTex[2048] = { 0 };
	char chApp[MAX_PATH] = { 0 };

	CPlumPath::PlumPathGetLocalPathA(chBackGround, MAX_PATH);
	strcat_s(chBackGround, "\\data\\AssistantMain_bk.pak");
	cPlumPackBk.PlumUnPackFileStoreInMemoryA(chBackGround, chBackGroundTex, sizeof(chBackGroundTex));

	CPlumPath::PlumPathGetLocalPathA(chBackMenu, MAX_PATH);
	strcat_s(chBackMenu, "\\data\\AssistantMain_mn.pak");
	cPlumPackMenu.PlumUnPackFileStoreInMemoryA(chBackMenu, chBackMenuTex, sizeof(chBackMenuTex));

	CPlumPath::PlumPathGetLocalPathA(chLogo, MAX_PATH);
	strcat_s(chLogo, "\\data\\AssistantMain_logo.pak");
	cPlumPackLogo.PlumUnPackFileStoreInMemoryA(chLogo, chLogoTex, sizeof(chLogoTex));

	CPlumPath::PlumPathGetLocalPathA(chApp, MAX_PATH);
	strcat_s(chApp, "\\data\\AssistantMain_app.pak");
	cPlumPackApp.PlumUnPackFileStoreInMemoryA(chApp, chAppTex, sizeof(chAppTex));

	//Lua参数读取
	int nBackGroundWidth = 0;
	int nBackGroundHeight = 0;
	int nBackGroundTextureWidth = 0;
	int nBackGroundTextureHeight = 0;
	int nBackMenuWidth = 0;
	int nBackMenuHeight = 0;
	int nBackMenuTextureWidth = 0;
	int nBackMenuTextureHeight = 0;

	m_pMainLua->AssistantLuaGetGlobalInt("MainBackGroundWidth", nBackGroundWidth);
	m_pMainLua->AssistantLuaGetGlobalInt("MainBackGroundHeight", nBackGroundHeight);
	m_pMainLua->AssistantLuaGetGlobalInt("MainBackTextureWidth", nBackGroundTextureWidth);
	m_pMainLua->AssistantLuaGetGlobalInt("MainBackTextureHeight", nBackGroundTextureHeight);

	m_pMainLua->AssistantLuaGetGlobalInt("MainBackMenuWidth", nBackMenuWidth);
	m_pMainLua->AssistantLuaGetGlobalInt("MainBackMenuHeight", nBackMenuHeight);
	m_pMainLua->AssistantLuaGetGlobalInt("MainBackMenuTextureWidth", nBackMenuTextureWidth);
	m_pMainLua->AssistantLuaGetGlobalInt("MainBackMenuTextureHeight", nBackMenuTextureHeight);

	//初始化参数
	CUUintEx sUintBack = { 0 };
	sUintBack.nScreenWidth = USER_SCREENWIDTH;
	sUintBack.nScreenHeight = USER_SCREENHEIGHT;
	sUintBack.pTextureArr = chBackGroundTex;
	sUintBack.nTextureArrSize = sizeof(chBackGroundTex);
	sUintBack.nTextureWidth = nBackGroundTextureWidth;
	sUintBack.nTextureHeight = nBackGroundTextureHeight;
	sUintBack.rcUnit = { 0, 0, nBackGroundWidth, nBackGroundHeight };
	sUintBack.rcUnitTex = { 0, 0, nBackGroundWidth, nBackGroundHeight };
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

	CUUintEx sUintMenu = { 0 };
	sUintMenu.nScreenWidth = USER_SCREENWIDTH;
	sUintMenu.nScreenHeight = USER_SCREENHEIGHT;
	sUintMenu.pTextureArr = chBackMenuTex;
	sUintMenu.nTextureArrSize = sizeof(chBackMenuTex);
	sUintMenu.nTextureWidth = nBackMenuTextureWidth;
	sUintMenu.nTextureHeight = nBackMenuTextureHeight;
	sUintMenu.rcUnit = { 0, 0, nBackMenuWidth, nBackMenuHeight };
	sUintMenu.rcUnitTex = { 0, 0, nBackMenuWidth, nBackMenuHeight };
	sUintMenu.fUnitAlpha = 1.0f;
	sUintMenu.sCoordsTransformPara.sWorldTransformPara.sScalePara.fScaleX = 1.0f;
	sUintMenu.sCoordsTransformPara.sWorldTransformPara.sScalePara.fScaleY = 1.0f;
	sUintMenu.sCoordsTransformPara.sWorldTransformPara.sScalePara.fScaleZ = 1.0f;
	sUintMenu.sCoordsTransformPara.sWorldTransformPara.sRotatePara.fRotateX = 0.0f;
	sUintMenu.sCoordsTransformPara.sWorldTransformPara.sRotatePara.fRotateY = 0.0f;
	sUintMenu.sCoordsTransformPara.sWorldTransformPara.sRotatePara.fRotateZ = 0.0f;
	sUintMenu.sCoordsTransformPara.sWorldTransformPara.sTranslatePara.fTranslateX = 0.0f;
	sUintMenu.sCoordsTransformPara.sWorldTransformPara.sTranslatePara.fTranslateY = 0.0f;
	sUintMenu.sCoordsTransformPara.sWorldTransformPara.sTranslatePara.fTranslateZ = 0.0f;

	return TRUE;
}

//------------------------------------------------------------------
// @Function:	 AssistantMainReset()
// @Purpose: CAssistantMain重置
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
void CAssistantMain::AssistantMainReset()
{
}

//------------------------------------------------------------------
// @Function:	 AssistantMainUpdate()
// @Purpose: CAssistantMain刷新
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
void CAssistantMain::AssistantMainUpdate(float fDeltaTime)
{
}

//------------------------------------------------------------------
// @Function:	 AssistantMainRender()
// @Purpose: CAssistantMain渲染
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
void CAssistantMain::AssistantMainRender(float fDeltaTime)
{
}
