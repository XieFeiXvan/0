///////////////////////////////////////////////////////////
//
//	HiEasyX ʹ��ʾ��
//
//	չʾ����δ���رմ�����Ϣ
//	
//	��ͼ����Դ������ https://codebus.cn/dudugang/drawing
//

#include "HiEasyX.h"
#include <time.h>

int x;								// X ������
int y;								// y ������
int g_multiples = 0;				// �����������ǶԻ��Ƚǽ��иı�
float g_PI = (float)3.1415;			// Բ����
float g_radianAngle;				// ��ʼ�ǵĻ���
int w = 830;						// ���ڿ�
int h = 580;						// ���ڸ�

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

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return HIWINDOW_DEFAULT_PROC;
		break;
	}

	return 0;
}

int main()
{
	// ������ͼ���ڣ���ָ�����ڹ��̺���
	hiex::initgraph_win32(w, h, false, L"", WndProc);

	// ���ñ���ɫ
	setbkcolor(WHITE);

	while (true)
	{
		// ����һ����ͼ����
		// ����ֻ������һ�����ڣ����Բ���Ҫָ��Ŀ���ͼ����
		// �������Ҫ���� BEGIN_TASK_WND() �ָ꣬��Ŀ���ͼ����
		BEGIN_TASK();

		// ����һЩ���ƣ����ڵ��õĶ��� EasyX ��ͼ����������ע��
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

		// HiEasyX Ĭ��ʹ��˫�����ͼ���˴������ͼ����
		// ע�⣺һ�λ�ͼ��������������Դ˺��β���� BEGIN_TASK �� END_TASK �������ã�
		END_TASK();

		// ���ڴ��ڹ��̺����� WM_PAINT ��Ϣ�ڻ�ͼʱ������ǿ���ػ�
		// ����û���Զ��崰�ڹ��̺��������Ե�ȻҲҪ���ô˺�ǿ���ػ�
		FLUSH_DRAW();

		while (true)
		{
			// ���ڴ�С�ı�ʱ�ػ�
			if (hiex::isWindowSizeChanged())
			{
				break;
			}

			// �����ڱ��رգ����������
			if (!hiex::isAnyWindow())
			{
				return 0;
			}

			Sleep(10);
		}
	}
}

