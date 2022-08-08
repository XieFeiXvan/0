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
	private:
		int m_nClickCount = 0;
		void (*m_pFunc)() = nullptr;

	protected:

		void RealCreate(HWND hParent) override;

	public:

		SysButton();

		SysButton(HWND hParent, RECT rct, std::wstring strText = L"");

		SysButton(HWND hParent, int x, int y, int w, int h, std::wstring strText = L"");

		LRESULT UpdateMessage(UINT msg, WPARAM wParam, LPARAM lParam, bool& bRet) override;

		// ע������Ϣ
		void RegisterMessage(void (*pFunc)());

		// ��ȡ���´���
		int GetClickCount();
	};
}
