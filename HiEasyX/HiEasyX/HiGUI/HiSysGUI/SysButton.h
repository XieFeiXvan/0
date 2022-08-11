////////////////////////////////////
//
//	SysButton.h
//	HiSysGUI �ؼ���֧����ť
//

#pragma once

#include "SysControlBase.h"

#include <graphics.h>

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

		// ����ͼƬ
		// reserve_text	������ť�е�����
		void Image(bool enable, IMAGE* img = nullptr, bool reserve_text = false);

		// ��ȡ���´���
		int GetClickCount();

		// �ж��Ƿ��°���
		// ����ʹ�� GetClickCount���˺������ܶ�ʧ���´�����Ϣ
		bool isClicked();
	};
}
