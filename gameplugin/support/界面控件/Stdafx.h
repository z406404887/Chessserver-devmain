#pragma once

//////////////////////////////////////////////////////////////////////////////////

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN
#endif

#ifndef WINVER
#define WINVER 0x0501
#endif

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0501
#endif

#ifndef _WIN32_WINDOWS
#define _WIN32_WINDOWS 0x0510
#endif

#ifndef _WIN32_IE
#define _WIN32_IE 0x0500
#endif

#define _ATL_ATTRIBUTES
#define _AFX_ALL_WARNINGS
#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS

//////////////////////////////////////////////////////////////////////////////////

//MFC 文件
#include <AfxWin.h>
#include <AfxExt.h>
#include <AfxCmn.h>
#include <AfxDisp.h>

//其他文件
#include "Other\SkinSB.h"
#include "Other\Detours.h"

//图片控件
#import "ImageOle.dll" named_guids

//////////////////////////////////////////////////////////////////////////////////
//链接代码

#pragma comment (lib,"Other/SkinSB.lib")
#pragma comment (lib,"Other/Detours.lib")

//#pragma comment (lib,"WHImage.lib")
//#pragma comment (lib,"ServiceCore.lib")
//#pragma comment (lib,"FGuilib.lib")
//#pragma comment (lib,"FGuimfcFactory.lib")

//////////////////////////////////////////////////////////////////////////////////
