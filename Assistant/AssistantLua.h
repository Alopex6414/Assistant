/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017~2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		AssistantLua.h
* @brief	This Program is Assistant Project.
* @author	Alopex/Helium
* @version	v1.00a
* @date		2018-07-15	v1.00a	alopex	Create Project
*/
#pragma once

#ifndef __ASSISTANTLUA_H_
#define __ASSISTANTLUA_H_

//Include Common Header File
#include "Common.h"

//Class Definition
class CAssistantLua
{
private:
	lua_State * L;

private:
	char m_chFile[MAX_PATH];
	char m_chPath[MAX_PATH];

public:
	CAssistantLua(const char* szFile);
	~CAssistantLua();

	BOOL AssistantLuaInit();
	void AssistantLuaGetGlobalInt(const char* szVar, int& nValue);
	void AssistantLuaGetGlobalFloat(const char* szVar, float& fValue);
	void AssistantLuaGetGlobalDouble(const char* szVar, double& dValue);

};

#endif // !__ASSISTANTLUA_H_
