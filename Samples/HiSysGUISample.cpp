#include "HiEasyX.h"

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
		break;
	}

	return 0;
}

void OnCheck(bool checked)
{
	if (checked)
	{
		MessageBox(nullptr, L"Checked", L"tip", MB_OK);
	}
}

HiEasyX::Canvas canvas_wnd2;

void OnEdit(std::wstring wstrText)
{
	canvas_wnd2.Clear();
	canvas_wnd2.CenterText(wstrText.c_str());
}

int main()
{
	HiEasyX::Window wnd(640, 480, EW_NORMAL, 0, WndProc2);
	HiEasyX::Canvas canvas;
	wnd.BindCanvas(&canvas);

	btn.Create(wnd.GetHandle(), 20, 50, 80, 25, L"Hello");

	btn.SetFont(14, 0, L"Arial");

	//btn.Enable(false);
	//btn.Show(false);

	btn.SetFocus(true);

	HiEasyX::SysGroupBox groupbox(wnd.GetHandle(), 10, 20, 120, 90, L"Group 1");

	HiEasyX::SysStatic text(wnd.GetHandle(), 20, 80, 60, 20, L"Static");
	HiEasyX::SysStatic pic(wnd.GetHandle(), 20, 150, 60, 60);

	HiEasyX::Canvas img(60, 60);
	img.FillCircle(30, 30, 30, true, BLUE, WHITE);

	pic.Image(true, &img);

	HiEasyX::SysCheckBox check(wnd.GetHandle(), 20, 220, 100, 25, L"Msg box");
	check.Check(true);
	check.RegisterMessage(OnCheck);

	//HiEasyX::SysGroup group(wnd.GetHandle());

	HiEasyX::SysGroupBox radio_group[2];
	radio_group[0].Create(wnd.GetHandle(), 20, 260, 150, 100, L"Radio group 1");
	radio_group[1].Create(wnd.GetHandle(), 20, 368, 150, 100, L"Radio group 2");

	HiEasyX::SysRadioButton radio[2][3];
	for (int i = 0; i < 2; i++)
	{
		HiEasyX::SysGroup group(wnd.GetHandle());

		for (int j = 0; j < 2; j++)
		{
			radio[i][j].Create(
				wnd.GetHandle(),
				40, 250 + (i * 3 + j + 1) * 35,
				100, 25,
				L"Radio [" + std::to_wstring(i) + L"]"
				L"[" + std::to_wstring(j) + L"]"
			);
		}
	}

	radio[0][0].RegisterMessage(OnCheck);
	radio[0][0].Check(true);

	HiEasyX::SysEdit edit;
	edit.PreSetStyle(true, false, true, true);
	edit.Create(wnd.GetHandle(), { 200,300,500,450 },
		L"News !\r\n"
		L"Use HiEasyX right now, for a better experience !\r\n"
	);
	edit.SetFont(14, 0, L"Consolas");
	//edit.ReadOnly(true);
	//edit.RightAlign(true);
	edit.Uppercase(true);
	//edit.NumberOnly(true);
	edit.RegisterMessage(OnEdit);

	edit.SetSel(5, edit.GetTextLength() - 10);
	//edit.SetTextBkColor(PURPLE);

	HiEasyX::SysComboBox combobox;
	combobox.PreSetEtyle(false, false, true);
	combobox.Create(wnd.GetHandle(), 150, 50, 200, 200, L"");
	TCHAR Planets[9][10] = {
		TEXT("Mercury"), TEXT("Venus"), TEXT("Terra"), TEXT("Mars"),
		TEXT("Jupiter"), TEXT("Saturn"), TEXT("Uranus"), TEXT("Neptune"),
		TEXT("Pluto")
	};
	for (int i = 0; i < 9; i++)
	{
		combobox.AddString(Planets[i]);
	}
	//combobox.SelectString(L"Mars");
	combobox.SetSel(3);

	HiEasyX::Window wnd2(640, 480);
	wnd2.BindCanvas(&canvas_wnd2);
	HiEasyX::SysButton btnImage(wnd2.GetHandle(), 20, 20, 120, 40, L" Button && pic");
	img.ZoomImage_Alpha(20, 20);
	btnImage.Image(true, &img, true);

	OnEdit(edit.GetText());
	wnd2.Redraw();

	int i = 0;
	while (wnd.isAlive())
	{
		int c = btn.GetClickCount();
		if (c || wnd.isSizeChanged())
		{
			i += c;
			canvas.Clear();
			canvas.Circle(100, 100, 70);

			canvas.SetTextEscapement(-200);
			canvas.SetTextOrientation(-200);
			canvas.SetTypeface(L"Arial");
			canvas.SetFont(160);
			canvas.SetTextColor(BLACK);
			canvas.OutTextXY(60, 20, L"Hi, EasyX");

			canvas.SetTextEscapement(0);
			canvas.SetTextOrientation(0);
			canvas.SetTypeface(L"Arial");
			canvas.SetFont(24);
			canvas.SetTextColor(RED);
			canvas.CenterText_Format(6, L"%d", i);

			wnd.Redraw();
		}

		if (edit.isEdited())
		{
			wnd2.Redraw();
		}

		HiEasyX::DelayFPS(60);
	}

	return 0;
}
