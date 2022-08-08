#include "SysControlBase.h"

#include "../../HiWindow.h"

namespace HiEasyX
{
	HWND SysControlBase::CreateControl(HWND hParent, LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle)
	{
		CREATESTRUCT c;
		c.lpCreateParams = 0;
		c.hInstance = 0;
		c.hMenu = (HMENU)(long long)AllocID();
		c.hwndParent = hParent;
		c.cy = GetHeight();
		c.cx = GetWidth();
		c.y = GetY();
		c.x = GetX();
		c.style = dwStyle;
		c.lpszName = lpszWindowName;
		c.lpszClass = lpszClassName;
		c.dwExStyle = 0;

		return (HWND)SendMessage(hParent, WM_SYSCTRL_CREATE, 0, (LPARAM)&c);
	}

	SysControlBase::SysControlBase()
	{
	}

	SysControlBase::SysControlBase(HWND hParent, RECT rct, std::wstring strText)
	{
		Create(hParent, rct, strText);
	}

	SysControlBase::SysControlBase(HWND hParent, int x, int y, int w, int h, std::wstring strText)
	{
		Create(hParent, x, y, w, h, strText);
	}

	SysControlBase::~SysControlBase()
	{
	}

	void SysControlBase::UpdateRect(RECT rctOld)
	{
		SetWindowPos(GetHandle(), 0, GetX(), GetY(), GetWidth(), GetHeight(), 0);
	}

	HWND SysControlBase::Create(HWND hParent, RECT rct, std::wstring strText)
	{
		if (!GetHandle())
		{
			SetRect(rct);
			RealCreate(hParent);
			SetText(strText);
		}
		return GetHandle();
	}

	HWND SysControlBase::Create(HWND hParent, int x, int y, int w, int h, std::wstring strText)
	{
		if (!GetHandle())
		{
			SetRect(x, y, w, h);
			RealCreate(hParent);
			SetText(strText);
		}
		return GetHandle();
	}

	bool SysControlBase::isEnable()
	{
		return IsWindowEnabled(GetHandle());
	}

	void SysControlBase::Enable(bool enable)
	{
		EnableWindow(GetHandle(), enable);
	}

	bool SysControlBase::isVisible()
	{
		return IsWindowVisible(GetHandle());
	}

	void SysControlBase::Show(bool show)
	{
		ShowWindow(GetHandle(), show ? SW_SHOW : SW_HIDE);
	}

	bool SysControlBase::isFocused()
	{
		HWND wnd;//���ھ��
		wnd = GetActiveWindow();//��õ�ǰ����Ĵ��ھ��
		DWORD SelfThreadId = GetCurrentThreadId();//��ȡ������߳�ID
		DWORD ForeThreadId = GetWindowThreadProcessId(wnd, NULL);//���ݴ��ھ����ȡ�߳�ID
		AttachThreadInput(ForeThreadId, SelfThreadId, true);//�����߳�
		wnd = GetFocus();//��ȡ�������뽹��Ĵ��ھ��
		AttachThreadInput(ForeThreadId, SelfThreadId, false);//ȡ�����ӵ��߳�
		SendMessage(wnd, WM_CHAR, WPARAM('a'), 0);//����һ������Ϣ

		return true;
	}

	std::wstring SysControlBase::GetText()
	{
		int len = GetWindowTextLength(GetHandle());
		WCHAR* buf = new WCHAR[len + 1];
		ZeroMemory(buf, sizeof WCHAR * (len + 1));
		GetWindowText(GetHandle(), buf, len);
		std::wstring str = buf;
		delete[] buf;
		return str;
	}

	void SysControlBase::SetText(std::wstring wstr)
	{
		SetWindowText(GetHandle(), wstr.c_str());
	}

	int SysControlBase::GetID()
	{
		return GetDlgCtrlID(GetHandle());
	}

	int AllocID()
	{
		static int id = 10086;
		return id++;
	}
}
