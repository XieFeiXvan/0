////////////////////////////////////
//
//	SysCheckBox.h
//	HiSysGUI �ؼ���֧����ѡ��
//

#pragma once

#include "SysControlBase.h"

namespace HiEasyX
{
	class SysCheckBox : public SysControlBase
	{
	private:
		bool m_bChecked = false;
		void (*m_pFunc)(bool checked) = nullptr;

	protected:

		void RealCreate(HWND hParent) override;

	public:

		SysCheckBox();

		SysCheckBox(HWND hParent, RECT rct, std::wstring strText = L"");

		SysCheckBox(HWND hParent, int x, int y, int w, int h, std::wstring strText = L"");

		LRESULT UpdateMessage(UINT msg, WPARAM wParam, LPARAM lParam, bool& bRet) override;

		// ע������Ϣ
		void RegisterMessage(void (*pFunc)(bool checked));

		// ��ȡѡ��״̬
		bool isChecked() const { return m_bChecked; }

		void Check(bool check);
	};
}
