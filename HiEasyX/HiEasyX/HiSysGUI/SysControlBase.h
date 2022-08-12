////////////////////////////////////
//
//	SysControlBase.h
//	HiSysGUI �ؼ���֧���ؼ�����
//

#pragma once

#include "../HiContainer.h"

#include <windowsx.h>
#include <string>

namespace HiEasyX
{
	// ֧�ֵ�ϵͳ�ؼ�����
	enum SysControlType
	{
		SCT_Unknown,
		SCT_Group,
		SCT_GroupBox,
		SCT_Static,
		SCT_Button,
		SCT_CheckBox,
		SCT_RadioButton,
		SCT_Edit,
		SCT_ComboBox,
	};

	class SysControlBase : public Container
	{
	private:

		HFONT m_hFont = nullptr;

	protected:

		HWND m_hWnd = nullptr;
		HWND m_hParent = nullptr;
		int m_nID = 0;
		SysControlType m_type = SCT_Unknown;

		// �����ؼ�
		HWND CreateControl(HWND hParent, LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle);

		// ʵ�ʵ��õĴ����ؼ�����
		virtual void RealCreate(HWND hParent) = 0;

	public:

		SysControlBase();

		virtual ~SysControlBase();

		void UpdateRect(RECT rctOld) override;

		// ������Ϣ���˺��������û�����
		// bRet ����������Ƿ񷵻�ֵ
		virtual LRESULT UpdateMessage(UINT msg, WPARAM wParam, LPARAM lParam, bool& bRet);

		// ע���ؼ�ֻ�ܴ���һ��
		HWND Create(HWND hParent, RECT rct, std::wstring strText = L"");

		// ע���ؼ�ֻ�ܴ���һ��
		HWND Create(HWND hParent, int x, int y, int w, int h, std::wstring strText = L"");

		HWND GetHandle() const { return m_hWnd; }

		// ��ȡ�ؼ�����
		SysControlType GetControlType() const { return m_type; }

		bool isEnable();

		void Enable(bool enable);

		bool isVisible();

		void Show(bool show);

		bool isFocused();

		void SetFocus(bool focused);

		int GetTextLength();

		std::wstring GetText();

		void SetText(std::wstring wstr);

		HFONT GetFont();

		void SetFont(int h, int w = 0, std::wstring typeface = L"");

		int GetID();

	};

	// �Զ�����ؼ� ID
	int AllocID();
}
