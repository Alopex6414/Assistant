/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017, Alopex/Helium
*     All rights reserved.
*
* @file		WinProcess.cpp
* @brief	This Program is WinProcess DLL Project.
* @author	Alopex/Helium
* @version	v1.00a
* @date		2017-11-29
*/
#include "WinProcess.h"
#include "WinUtilities.h"

#include "Assistant.h"

CAssistant* g_pAssistant = NULL;

float g_fLastTime = 0.0f;
float g_fCurrentTime = 0.0f;
float g_fDeltaTime = 0.0f;

//------------------------------------------------------------------
// @Function:	 SetWindowParameterCallBack(void)
// @Purpose: WinMain设置窗口相关参数回调函数
// @Since: v1.00a
// @Para: None
// @Return: WndPara*
//------------------------------------------------------------------
WndPara* SetWindowParameterCallBack(void)
{
	WndPara* pWindowParameter = new WndPara;
	pWindowParameter->nWndWidth = USER_SCREENWIDTH;//窗口宽度
	pWindowParameter->nWndHeight = USER_SCREENHEIGHT;//窗口高度
	pWindowParameter->lpszTitle = USER_WINDOWTITLE;//窗口标题名称
	pWindowParameter->wIcon = USER_WINDOWICON;//窗口标题图标
	return pWindowParameter;
}

//------------------------------------------------------------------
// @Function:	 InitWindowExtraCallBack(void)
// @Purpose: WinMain初始化窗口相关内容回调函数(DirectX 初始化)
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
BOOL InitWindowExtraCallBack(void)
{
	g_pAssistant = new CAssistant();
	return g_pAssistant->AssistantInit();
}

//------------------------------------------------------------------
// @Function:	 ReleaseWindowExtraCallBack(void)
// @Purpose: WinMain释放窗口相关内容回调函数(DirectX 释放)
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
void ReleaseWindowExtraCallBack(void)
{
	g_pAssistant->AssistantRelease();
	SAFE_DELETE(g_pAssistant);
}

//------------------------------------------------------------------
// @Function:	 Direct3DRenderCallBack(void)
// @Purpose: Direct3D渲染相关回调函数(DirectX 渲染)
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
void Direct3DRenderCallBack(void)
{
	g_fLastTime = (float)timeGetTime()*0.001f;
	g_pAssistant->AssistantUpdate();
	g_pAssistant->AssistantRender();
	g_fCurrentTime = (float)timeGetTime()*0.001f;
	g_fDeltaTime = g_fCurrentTime - g_fLastTime;
}