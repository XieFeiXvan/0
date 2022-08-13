///////////////////////////////////////////////////////////
//
//	�� 4 �׶Σ����ش��ڹ��̺���
// 
//	�����У���ʾ��������ش��ڹ��̺��������ڹرմ���ʱ����ȷ��
// 
//	��������	���Ӿ��������
//	ԭ �� ��	����ө����
//

#include "HiEasyX.h"

int w = 830;	// ���ڿ�
int h = 580;	// ���ڸ�

// ���ڹ��̺���
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CLOSE:

		// �رմ���ʱ��ʾ�Ƿ�ȷ�Ϲر�
		if (MessageBox(hWnd, L"ȷ���رմ��ڣ�", L"��ʾ", MB_OKCANCEL | MB_ICONWARNING) == IDOK)
		{
			DestroyWindow(hWnd);
		}
		break;

	default:
		return HIWINDOW_DEFAULT_PROC;
		break;
	}

	return 0;
}

// �Ӿ��������
// ���ߣ���ө����
// ���ͣ�https://codebus.cn/dudugang/drawing
void Draw()
{
	int x;								// X ������
	int y;								// y ������
	int g_multiples = 0;				// �����������ǶԻ��Ƚǽ��иı�
	float g_PI = (float)3.1415;			// Բ����
	float g_radianAngle;				// ��ʼ�ǵĻ���

	cleardevice();
	setcolor(RGB(185, 230, 0));
	setfillcolor(RGB(185, 230, 0));
	solidrectangle(10, 10, getwidth() - 10, getheight() - 10);
	for (size_t j = 0; j < 11.0 / h * getheight() - 0.5; j++)
	{
		for (size_t i = 0; i < 16.0 / w * getwidth() - 0.5; i++)
		{
			x = 15 + 50 * (int)i;
			y = 15 + 50 * (int)j;
			g_radianAngle = 0 + g_multiples * g_PI / 4;
			i < 15 ? g_multiples++ : g_multiples = g_multiples;
			rectangle(x, y, x + 50, y + 50);
			setfillcolor(RGB(250, 250, 250));
			solidcircle(x + 25, y + 25, 20);
			setfillcolor(RGB(80, 80, 80));
			solidpie(x + 5, y + 5, x + 50 - 5, y + 50 - 5, g_radianAngle, g_radianAngle + g_PI);
			setfillcolor(RGB(158, 2, 251));
			solidcircle(x + 25, y + 25, 15);
		}
	}
}

int main()
{
	// ������ͼ���ڣ���ָ�����ڹ��̺���
	hiex::initgraph_win32(w, h, false, L"", WndProc);
	
	hiex::AutoExit();	// ���ڹر�ʱ���Զ��˳�����

	while (true)
	{
		BEGIN_TASK();
		Draw();
		END_TASK();
		FLUSH_DRAW();

		while (!hiex::isWindowSizeChanged())
			Sleep(50);
	}
}

