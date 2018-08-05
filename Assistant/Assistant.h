/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017~2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		Assistant.h
* @brief	This Program is Assistant Project.
* @author	Alopex/Helium
* @version	v1.00a
* @date		2018-07-14	v1.00a	alopex	Create Project
*/
#pragma once

#ifndef __ASSISTANT_H_
#define __ASSISTANT_H_

//Include Common Header File
#include "Common.h"

//Include Assistant Header File
#include "AssistantStart.h"
#include "AssistantMain.h"

//Class Definition
class CAssistant
{
private:
	DirectGraphics* m_pDirectGraphics;

private:
	CCerasusfps* m_pCerasusfps;

private:
	float m_fTimeSum;

public:
	CAssistantStart* m_pAssistantStart;
	CAssistantMain* m_pAssistantMain;

protected:
	void AssistantDrawStatic();
	void AssistantDrawFPS();

public:
	CAssistant();
	~CAssistant();

	BOOL AssistantInit();		//Assistant初始化
	void AssistantRelease();	//Assistant释放

	void AssistantUpdate();		//Assistant同步
	void AssistantRender();		//Assistant渲染
};

#endif	//!__ASSISTANT_H_
