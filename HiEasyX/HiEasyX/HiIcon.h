//////////////////////////
//
//	HiIcon.h
//	HiEasyX ���ͼ��ģ��
//	
//	���ڴ洢 HiEasyX ͼ��
//

#pragma once

#include <graphics.h>

// ͼ���С
#define HIICON_WIDTH	64
#define HIICON_HEIGHT	64

namespace HiEasyX
{
	// ��ȡͼ���Դ�
	DWORD* GetIconImageBuffer();

	// ��ȡͼ������Դ�Ŀ�����
	IMAGE* GetIconImage();
};
