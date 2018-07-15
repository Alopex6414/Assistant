/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017~2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		AssistantMain.h
* @brief	This Program is Assistant Project.
* @author	Alopex/Helium
* @version	v1.00a
* @date		2018-07-15	v1.00a	alopex	Create Project
*/
#pragma once

#ifndef __ASSISTANTMAIN_H_
#define __ASSISTANTMAIN_H_

//Include Common Header File
#include "Common.h"

//Include AssistantLua Header File
#include "AssistantLua.h"

//Class Definition
class CAssistantMain
{
private:
	IDirect3DDevice9* m_pD3D9Device;

private:
	CCerasusUnit* m_pMainBackGround;	//主界面背景
	CCerasusUnit* m_pMainBackMenu;		//主界面菜单
	CCerasusUnit* m_pMainLogo;			//主界面Logo
	CCerasusUnit* m_pMainApps;			//主界面Apps

protected:
	CAssistantLua * m_pMainLua;			//Lua Script

public:
	CAssistantMain();
	~CAssistantMain();

	CAssistantMain(IDirect3DDevice9* pD3D9Device);

	BOOL AssistantMainInit();
	void AssistantMainReset();
	void AssistantMainUpdate(float fDeltaTime);
	void AssistantMainRender(float fDeltaTime);

};

#endif // !__ASSISTANTMAIN_H_

