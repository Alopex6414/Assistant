/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017~2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		AssistantStart.h
* @brief	This Program is Assistant Project.
* @author	Alopex/Helium
* @version	v1.00a
* @date		2018-07-14	v1.00a	alopex	Create Project
*/
#pragma once

#ifndef __ASSISTANTSTART_H_
#define __ASSISTANTSTART_H_

//Include Common Header File
#include "Common.h"

//Include AssistantLua Header File
#include "AssistantLua.h"

//Class Definition
class CAssistantStart
{
private:
	IDirect3DDevice9* m_pD3D9Device;

private:
	CCerasusUnit* m_pMainBackGround;	//开始界面背景
	CCerasusUnit* m_pMainLogo;			//开始界面logo
	CCerasusUnit* m_pMainCopy;			//开始界面copy

protected:
	CAssistantLua* m_pMainLua;			//Lua Script

public:
	CAssistantStart();
	~CAssistantStart();

	CAssistantStart(IDirect3DDevice9* pD3D9Device);

	BOOL AssistantStartInit();
	void AssistantStartReset();
	void AssistantStartUpdate(float fDeltaTime);
	void AssistantStartRender(float fDeltaTime);

};

#endif // !__ASSISTANTSTART_H_
