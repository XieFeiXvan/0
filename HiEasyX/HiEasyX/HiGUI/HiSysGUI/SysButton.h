////////////////////////////////////
//
//	SysControlBase.h
//	HiSysGUI �ؼ���֧���ؼ�����
//

#pragma once

#include "SysControlBase.h"

namespace HiEasyX
{
	class SysButton : public SysControlBase
	{
	protected:

		void RealCreate(HWND hParent) override;

	public:

		SysButton();

		SysButton(HWND hParent, RECT rct, std::wstring strText = L"");

		SysButton(HWND hParent, int x, int y, int w, int h, std::wstring strText = L"");

	};
}
