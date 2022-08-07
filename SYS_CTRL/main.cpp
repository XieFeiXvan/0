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
			rct.left, rct.top, rct.right, rct.bottom,
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
		break;
	}

	case WM_CTLCOLOREDIT://����Edit��ɫ
	{
		if (GetDlgItem(hWnd, IDC_EDIT) == (HWND)lParam)//�����1�Ǿ�̬�ı����ID
		{
			SetTextColor((HDC)wParam, RGB(0, 122, 204));
			//SetBkMode((HDC)wParam, TRANSPARENT);
			return (INT_PTR)CreateSolidBrush(RGB(255, 0, 0));
			//return (BOOL)((HBRUSH)GetStockObject(NULL_BRUSH));
		}
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

int main()
{
	initgraph();

	HiEasyX::SetWndProcFunc(nullptr, WndProc);
	HiEasyX::init_end();

	closegraph();
	return 0;
}
