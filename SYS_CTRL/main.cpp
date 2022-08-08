#include "../HiEasyX/HiEasyX.h"

#define IDC_EDIT 101

HWND editWindow = nullptr;

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static HFONT hFont;//���徲̬�������

	switch (msg)
	{
	case WM_CREATE:
	{
		//��ȡ�ͻ������ڴ�С����
		RECT rct;
		GetClientRect(hWnd, &rct);
		//����edit�༭���ڣ��Ӵ��ڣ����ӣ��б߿򣬶��У�ʶ��enterΪ�س���ʧȥ������겻��ʧ
		editWindow = CreateWindow(
			L"EDIT",
			nullptr,
			WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE | ES_WANTRETURN | ES_NOHIDESEL | WS_VSCROLL | ES_AUTOVSCROLL,
			0, 100, rct.right, rct.bottom,
			hWnd,
			(HMENU)IDC_EDIT,
			nullptr,
			nullptr
		);

		hFont = CreateFont(
			24, 0, 0, 0, 0,
			FALSE, FALSE,
			0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS,
			L"Consolas");
		//��������
		//HWND hStatic = CreateWindow("STATIC", "��̬�ı�", WS_CHILD | WS_VISIBLE, 10, 10, 100, 25, hwnd, (HMENU)IDC_FILTER_STATIC, g_hInstance, NULL);//������̬�ı�
		SendMessage(editWindow, WM_SETFONT, (WPARAM)hFont, TRUE);//��������������Ϣ	

		//Edit_SetPasswordChar(editWindow, L'*');

		Edit_SetText(editWindow, L"ע�⣺\r\n�ո�");
		Edit_SetReadOnly(editWindow, true);

		break;
	}

	case WM_CTLCOLOREDIT://����Edit��ɫ
	{
		if (editWindow == (HWND)lParam)//�����1�Ǿ�̬�ı����ID
		{
			SetTextColor((HDC)wParam, RGB(0, 122, 204));
			SetBkColor((HDC)wParam, RGB(30, 30, 30));
			//SetBkMode((HDC)wParam, TRANSPARENT);
			return (INT_PTR)CreateSolidBrush(RGB(30, 30, 30));
			//return (LRESULT)GetStockObject(WHITE_BRUSH);
		}
		break;
	}

	case WM_SIZE:
	{
		RECT rct;
		GetClientRect(hWnd, &rct);
		//Edit_SetRect(editWindow, &rct);
		SetWindowPos(editWindow, 0, 0, 100, rct.right, rct.bottom, 0);
		break;
	}

	case WM_PAINT:
	{
		BEGIN_TASK_WND(hWnd);

		circle(30, 30, 30);

		END_TASK();

		break;
	}

	case WM_DESTROY:
	{
		DeleteObject(hFont);//ɾ���������������
		PostQuitMessage(0);
		break;
	}

	default:
		return HIWINDOW_DEFAULT_PROC;
		break;

	}

	return 0;
}


HiEasyX::SysButton btn;

LRESULT CALLBACK WndProc2(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static HINSTANCE hInstance = GetModuleHandle(0);
	static HWND hBtn = nullptr;

	switch (msg)
	{
	case WM_CREATE:
	{
		hBtn = CreateWindow(L"Button", L"Press me", WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON, 10, 10, 80, 25, hWnd, nullptr, hInstance, 0);
		break;
	}

	case WM_PAINT:
		BEGIN_TASK_WND(hWnd);
		circle(100, 100, 70);
		END_TASK();
		break;


	case WM_COMMAND:
	{
		int id = LOWORD(wParam);
		if (id == btn.GetID())
		{
			btn.SetText(L"!!");
		}
		break;
	}

	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return HIWINDOW_DEFAULT_PROC;	// ��ʶʹ��Ĭ����Ϣ��������������

		// ��Ҫ��Ĭ�Ϸ�ʽ��������ʹ�ô����
		//return DefWindowProc(hWnd, msg, wParam, lParam);
		break;
	}

	return 0;
}

int main()
{
	HiEasyX::Window wnd(640, 480, EW_NORMAL, 0/*, WndProc2*/);
	HiEasyX::Canvas canvas;
	wnd.BindCanvas(&canvas);

	btn.Create(wnd.GetHandle(), 10, 50, 80, 25, L"Hello");

	//btn.Enable(false);
	//btn.Show(false);

	btn.SetFocus(true);

	int i = 0;
	while (wnd.isAlive())
	{
		i += btn.GetClickCount();
		canvas.Clear();
		canvas.CenterText_Format(6, L"%d", i);
		wnd.Redraw();
		Sleep(100);
	}
	return 0;

	HiEasyX::init_end();
	return 0;
}
