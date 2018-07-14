/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		PlumProcess.h
* @brief	This Program is PlumProcess DLL Project.
* @author	Alopex/Helium
* @version	v1.00a
* @date		2018-1-30	v1.00a	alopex	Create Project.
*/
#pragma once

#ifndef __PLUMPROCESS_H_
#define __PLUMPROCESS_H_

//Include Windows Header File
#include <Windows.h>
#include <TlHelp32.h>

//Include C/C++ Running Header File
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <tchar.h>

//Macro Definition
#ifdef PRUNUS_EXPORTS
#define PLUMPROCESS_API	__declspec(dllexport)
#else
#define PLUMPROCESS_API	__declspec(dllimport)
#endif

#define PLUMPROCESS_CALLMODE __stdcall

//Class Definition
class PLUMPROCESS_API CPlumProcess
{
private:
	DWORD m_dwProcessID;	//����ID
	DWORD m_dwThreadID;		//�߳�ID
	HANDLE m_hProcess;		//���̾��
	HANDLE m_hThread;		//�߳̾��

public:
	CPlumProcess();			//����
	~CPlumProcess();		//����

	virtual DWORD PLUMPROCESS_CALLMODE PlumProcessGetProcessID(void) const;					//��ȡ����ID
	virtual DWORD PLUMPROCESS_CALLMODE PlumProcessGetThreadID(void) const;					//��ȡ�߳�ID
	virtual HANDLE PLUMPROCESS_CALLMODE PlumProcessGetProcessHandle(void) const;			//��ȡ���̾��
	virtual HANDLE PLUMPROCESS_CALLMODE PlumProcessGetThreadHandle(void) const;				//��ȡ�߳̾��

	virtual void PLUMPROCESS_CALLMODE PlumProcessSetProcessID(DWORD dwProcessID);			//���ý���ID(������)
	virtual void PLUMPROCESS_CALLMODE PlumProcessSetThreadID(DWORD dwThreadID);				//��ȡ�߳�ID(������)

	virtual BOOL PLUMPROCESS_CALLMODE PlumProcessStartProcessA(const char* strProcessName);		//PlumProcess��������(��������)(ASCII)
	virtual BOOL PLUMPROCESS_CALLMODE PlumProcessStartProcessW(const wchar_t* strProcessName);	//PlumProcess��������(��������)(Unicode)
	virtual BOOL PLUMPROCESS_CALLMODE PlumProcessStartProcessNoCloseA(const char* strProcessName);		//PlumProcess�������̲��رս����߳̾��(��������)(ASCII)
	virtual BOOL PLUMPROCESS_CALLMODE PlumProcessStartProcessNoCloseW(const wchar_t* strProcessName);	//PlumProcess�������̲��رս����߳̾��(��������)(Unicode)

	virtual BOOL PLUMPROCESS_CALLMODE PlumProcessStartProcessA(const char* strProcessName, const char* strProcessCmd);			//PlumProcess��������(��������)(������)(ASCII)
	virtual BOOL PLUMPROCESS_CALLMODE PlumProcessStartProcessNoCloseA(const char* strProcessName, const char* strProcessCmd);	//PlumProcess��������(��������)(������)(ASCII)

	virtual BOOL PLUMPROCESS_CALLMODE PlumProcessIsProcessExistA(const char* strProcessName);	//PlumProcess�������Ƿ����(��������)(ASCII)
	virtual BOOL PLUMPROCESS_CALLMODE PlumProcessIsProcessExistW(const wchar_t* strProcessName);//PlumProcess�������Ƿ����(��������)(Unicode)
};

#endif // !__PLUMPROCESS_H_
