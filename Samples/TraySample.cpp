////////////////////////////
//
//	HiEasyX ʹ��ʾ��
//
//	���ٴ�������ͼ��
//

#include "HiEasyX.h"

// �������̲˵���ѡ�� ID
#define IDC_A	101
#define IDC_B	102
#define IDC_C	103
#define IDC_D	104

// �Զ�����̺���
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	// ��ʶ�Ƿ񵥻���������ͼ��
	static bool flag = false;

	switch (msg)
	{
		// �����ͼ��Ϣ
	case WM_PAINT:
		if (hiex::SetWorkingWindow(hWnd))
		{
			hiex::BeginTask();
			setbkcolor(SKYBLUE);
			cleardevice();
			settextstyle(32, 0, L"system");
			settextcolor(BLACK);
			outtextxy(20, 20, L"Windows Tray Icon Creation Sample");
			if (flag)
			{
				settextstyle(26, 0, L"system");
				settextcolor(PURPLE);
				outtextxy(20, 60, L"You pressed the tray icon.");
			}
			hiex::EndTask();
		}
		break;

		// ����������Ϣ
	case WM_TRAY:
	{
		switch (lParam)
		{
			// �����������ͼ��
		case WM_LBUTTONDOWN:
			flag = true;					// ��ǰ���
			hiex::EnforceRedraw();		// �����ػ�
			break;
		}
	}
	break;

	default:
		return HIWINDOW_DEFAULT_PROC;
		break;
	}

	return 0;
}

// �������̲˵��¼�
void OnMenu(UINT uId)
{
	switch (uId)
	{
	case IDC_A:
		MessageBox(GetHWnd(), L"A", L"Tip", MB_OK);
		break;
	case IDC_C:
		MessageBox(GetHWnd(), L"C", L"Tip", MB_OK);
		break;
	case IDC_D:
		MessageBox(GetHWnd(), L"D", L"Tip", MB_OK);
		break;
	}
}

int main()
{
	// ����һ���Զ�����̺����Ļ�ͼ����
	HWND hWnd1 = hiex::initgraph_win32(640, 480, EW_NORMAL, L"HiEasyX & Tray", WndProc);

	// �����˵�
	HMENU hMenu = CreatePopupMenu();
	AppendMenu(hMenu, MF_STRING, IDC_A, L"ѡ�� A");
	AppendMenu(hMenu, MF_STRING, IDC_B, L"ѡ�� B");
	AppendMenu(hMenu, MF_SEPARATOR, 0, NULL);				// �ָ���
	AppendMenu(hMenu, MF_STRING, IDC_C, L"ѡ�� C");
	EnableMenuItem(hMenu, IDC_B, MF_GRAYED);				// ����һ��ѡ��

	hiex::CreateTray(L"The first");					// ��������
	hiex::SetTrayMenu(hMenu);							// �������̲˵�
	hiex::SetTrayMenuProcFunc(OnMenu);					// �������̲˵���Ӧ����

	//
	// ע�⣺
	//	��ʾ����Ϊ����ʾ���������������ڣ��ֱ���һ������ͼ�ꡣ
	//	����ʵ��Ӧ���м���������������һ���������һ�����̾͹��ˡ�
	//	��������ͼ���ѹ̶�����Ϊ����ͼ�ꡣ
	//	HiEasyX �������̹���ֻ�����˼򵥷�װ������и�����Ҫ����������ʵ�֡�
	//

	// �����ڶ�������
	hiex::initgraph_win32(200, 120, EW_NORMAL, L"The Second Window");

	// ��ʱ�����������ڣ�Ϊ��ֹ��ͻ����������
	if(hiex::BeginTask())
	{
		setbkcolor(LIGHTSKYBLUE);
		cleardevice();
		settextcolor(BLACK);
		outtextxy(20, 20, L"The Second Window");

		// �����˵�
		HMENU hMenu2 = CreatePopupMenu();
		AppendMenu(hMenu2, MF_STRING, IDC_D, L"ѡ�� D");

		hiex::CreateTray(L"The second");				// ��������
		hiex::SetTrayMenu(hMenu2);						// �������̲˵�
		hiex::SetTrayMenuProcFunc(OnMenu);				// �������̲˵���Ӧ����
	
		hiex::EndTask();
		hiex::EnforceRedraw();
	}

	hiex::SetWorkingWindow(hWnd1);						// ������Ȩ������һ������
	SetForegroundWindow(hWnd1);

	hiex::init_end();									// �����Ⱥ�
	return 0;
}

