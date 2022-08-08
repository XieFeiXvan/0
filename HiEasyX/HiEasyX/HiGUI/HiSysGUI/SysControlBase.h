////////////////////////////////////
//
//	SysControlBase.h
//	HiSysGUI �ؼ���֧���ؼ�����
//

#pragma once

#include "../Container.h"

#include <string>

namespace HiEasyX
{
	enum SysControlType
	{
		SCT_Unknown,
		SCT_Button,
		SCT_EditBox,
	};

	class SysControlBase : public Container
	{
	protected:

		HWND m_hWnd = nullptr;

		SysControlType m_type = SCT_Unknown;

		// �����ؼ�
		HWND CreateControl(HWND hParent, LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle);

		// ʵ�ʵ��õĴ����ؼ�����
		virtual void RealCreate(HWND hParent) = 0;

	public:

		SysControlBase();

		SysControlBase(HWND hParent, RECT rct, std::wstring strText = L"");

		SysControlBase(HWND hParent, int x, int y, int w, int h, std::wstring strText = L"");

		virtual ~SysControlBase();

		void UpdateRect(RECT rctOld) override;

		HWND Create(HWND hParent, RECT rct, std::wstring strText = L"");

		HWND Create(HWND hParent, int x, int y, int w, int h, std::wstring strText = L"");

		HWND GetHandle() const { return m_hWnd; }

		SysControlType GetControlType() const { return m_type; }

		bool isEnable();

		void Enable(bool enable);

		bool isVisible();

		void Show(bool show);

		bool isFocused();

		//void 

		std::wstring GetText();

		void SetText(std::wstring wstr);
		
		int GetID();
		
	};

	// �Զ�����ؼ� ID
	int AllocID();
}
