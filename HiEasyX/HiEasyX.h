////////////////////////////////////////////////////
//
//	HiEasyX.h
//	HiEasyX ��ͷ�ļ�
//	�ÿ���� EasyX ʵ�����ڴ��ڡ���ͼ��UI ����෽���ȫ������
//
//	�桡������Ver 0.2 (alpha)
//	�������ߣ�huidong <mailhuid@163.com>
//	���뻷����VisualStudio 2022 | EasyX_20220610 | Windows 10 
//	��Ŀ��ַ��https://github.com/zouhuidong/HiEasyX
//	�������ڣ�2022.07.20
//	����޸ģ�2022.08.11
//

#pragma once

#define __HIEASYX_H__

#include "HiEasyX/HiDef.h"
#include "HiEasyX/HiMacro.h"
#include "HiEasyX/HiFunc.h"
#include "HiEasyX/HiFPS.h"
#include "HiEasyX/HiDrawingProperty.h"
#include "HiEasyX/HiMouseDrag.h"
#include "HiEasyX/HiMusicMCI.h"
#include "HiEasyX/HiGif.h"

// δѡ��ʹ��ԭ�� EasyX
#ifndef _NATIVE_EASYX_
#include "HiEasyX/HiWindow.h"
#include "HiEasyX/HiSysGUI/HiSysGUI.h"
#endif /* _NATIVE_EASYX_ */

#include "HiEasyX/HiCanvas.h"
#include "HiEasyX/HiGUI/HiGUI.h"


// HiEasyX �����ռ���д
namespace hiex = HiEasyX;

// ���ݾɰ� EasyWin32 �����ռ䣬�뾡��ʹ�� HiEasyX �����ռ�
namespace EasyWin32 = HiEasyX;

