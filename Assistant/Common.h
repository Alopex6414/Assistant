/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017~2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		Common.h
* @brief	This Program is Assistant Project.
* @author	Alopex/Helium
* @version	v1.00a
* @date		2018-07-13	v1.00a	alopex	Create Project
*/
#pragma once

#ifndef __COMMON_H_
#define __COMMON_H_

//Include Cerasus d3d9 Dynamic Link Library
#include "DirectCommon.h"
#include "DirectFont.h"
#include "DirectGraphics.h"
#include "DirectGraphics2D.h"
#include "DirectGraphics3D.h"
#include "DirectInput.h"
#include "DirectMesh.h"
#include "DirectSafe.h"
#include "DirectShow.h"
#include "DirectSound.h"
#include "DirectSprite.h"
#include "DirectSurface.h"
#include "DirectTexture.h"

#include "Cerasusfps.h"
#include "CerasusUnit.h"

//Include Prunus Win32 Dynamic Link Library
#include "PlumCommon.h"
#include "PlumCipherA.h"
#include "PlumCrypt.h"
#include "PlumPack.h"
#include "PlumConsole.h"
#include "PlumFile.h"
#include "PlumGraphics.h"
#include "PlumIni.h"
#include "PlumLog.h"
#include "PlumPath.h"
#include "PlumProcess.h"
#include "PlumThread.h"

//Include Windows Header File
#include "WinMain.h"
#include "WinProcess.h"
#include "WinUtilities.h"

//Include Common Library
#pragma comment(lib, "Cerasus.lib")
#pragma comment(lib, "Prunus.lib")

#endif // !__COMMON_H_

