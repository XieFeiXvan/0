////////////////////////////////////
//
//	SysRadioButton.h
//	HiSysGUI �ؼ���֧����ѡ��
//

#pragma once

#include "SysControlBase.h"

namespace HiEasyX
{
	class SysRadioButton : public SysControlBase
	{
	private:
		bool m_bChecked = false;
		void (*m_pFunc)(bool checked) = nullptr;

	protected:

		void RealCreate(HWND hParent) override;

	public:

		SysRadioButton();

		SysRadioButton(HWND hParent, RECT rct, std::wstring strText = L"");

		SysRadioButton(HWND hParent, int x, int y, int w, int h, std::wstring strText = L"");

		LRESULT UpdateMessage(UINT msg, WPARAM wParam, LPARAM lParam, bool& bRet) override;

		// ע������Ϣ
		void RegisterMessage(void (*pFunc)(bool checked));

		// ��ȡѡ��״̬
		bool isChecked() const { return m_bChecked; }

		void Check(bool check);
	};
}
