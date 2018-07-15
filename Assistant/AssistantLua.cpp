/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017~2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		AssistantLua.cpp
* @brief	This Program is Assistant Project.
* @author	Alopex/Helium
* @version	v1.00a
* @date		2018-07-15	v1.00a	alopex	Create Project
*/
#include "AssistantLua.h"

//Lua Script类

//------------------------------------------------------------------
// @Function:	 CAssistantLua()
// @Purpose: CAssistantLua构造函数
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
CAssistantLua::CAssistantLua(const char* szFile)
{
	int nSize = 0;

	nSize = strlen(szFile);

	L = luaL_newstate();
	memset(m_chFile, 0, MAX_PATH);
	memset(m_chPath, 0, MAX_PATH);
	memcpy_s(m_chFile, MAX_PATH, szFile, nSize);
}

//------------------------------------------------------------------
// @Function:	 ~CAssistantLua()
// @Purpose: CAssistantLua析构函数
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
CAssistantLua::~CAssistantLua()
{
	if (L) lua_close(L);
}

//------------------------------------------------------------------
// @Function:	 AssistantLuaInit()
// @Purpose: CAssistantLua初始化
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
BOOL CAssistantLua::AssistantLuaInit()
{
	CPlumPath::PlumPathGetLocalPathA(m_chPath, MAX_PATH);
	strcat_s(m_chPath, m_chFile);

	int nRet = -1;

	nRet = luaL_loadfile(L, m_chPath);
	if (nRet)
	{
		return FALSE;
	}

	nRet = lua_pcall(L, 0, 0, 0);
	if (nRet)
	{
		return FALSE;
	}

	return TRUE;
}

//------------------------------------------------------------------
// @Function:	 AssistantLuaGetGlobalInt()
// @Purpose: CAssistantLua获取Int变量
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
void CAssistantLua::AssistantLuaGetGlobalInt(const char * szVar, int & nValue)
{
	lua_getglobal(L, szVar);
	nValue = (int)lua_tonumber(L, -1);
}

//------------------------------------------------------------------
// @Function:	 AssistantLuaGetGlobalFloat()
// @Purpose: CAssistantLua获取单浮点变量
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
void CAssistantLua::AssistantLuaGetGlobalFloat(const char * szVar, float & fValue)
{
	lua_getglobal(L, szVar);
	fValue = (float)lua_tonumber(L, -1);
}

//------------------------------------------------------------------
// @Function:	 AssistantLuaGetGlobalDouble()
// @Purpose: CAssistantLua获取双浮点变量
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
void CAssistantLua::AssistantLuaGetGlobalDouble(const char * szVar, double & dValue)
{
	lua_getglobal(L, szVar);
	dValue = (double)lua_tonumber(L, -1);
}
