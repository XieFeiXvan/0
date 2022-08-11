////////////////////////////////////
//
//	SysStatic.h
//	HiSysGUI �ؼ���֧����̬�ؼ�
//

#pragma once

#include "SysControlBase.h"

#include <graphics.h>

namespace HiEasyX
{
	class SysStatic : public SysControlBase
	{
	protected:

		void RealCreate(HWND hParent) override;

	public:

		SysStatic();

		SysStatic(HWND hParent, RECT rct, std::wstring strText = L"");

		SysStatic(HWND hParent, int x, int y, int w, int h, std::wstring strText = L"");

		// �����ı�����
		void Center(bool center);

		// ����ͼƬ
		void Image(bool enable, IMAGE* img = nullptr);
	};
}
