/**
 * @brief 	�� 2 �׶Σ������ര��
 * @note
 * 			������ EasyX ����������ʾ���ֱ�������������ͼ������ <p>
 *			���Ƿֱ��ǡ��ַ��󡱺͡��������� <p>
 *
 * @author 	huidong <mailhuid@163.com>
 * @date 	2023.01.13
*/

#include "HiEasyX.h"

// EasyX ʾ�����ַ���
void CharacterArray()
{
	// ��ʱ����
	static clock_t tRecord = 0;
	static int  x, y, i = 0;
	static char c;

	// ��һ�λ��ƣ����û�ͼ����
	if (!tRecord)
	{
		settextstyle(16, 8, _T("Courier"));
		settextcolor(GREEN);
		setbkcolor(BLACK);
		cleardevice();
	}

	// ��ʱ����
	if (clock() - tRecord >= 10)
	{
		// �����λ����ʾ���������ĸ
		for (int j = 0; j < 3; j++)
		{
			x = (rand() % 80) * 8;
			y = (rand() % 20) * 24;
			c = (rand() % 26) + 65;
			outtextxy(x, y, c);
		}

		// ���߲���һ��������
		line(0, i, 639, i);

		tRecord = clock();

		if (i >= 479)	i = -1;
		i++;
	}
}

// EasyX ʾ������������
void OnMouse()
{
	ExMessage m;
	while (peekmessage(&m, EM_MOUSE))
	{
		switch (m.message)
		{
		case WM_MOUSEMOVE:
			putpixel(m.x, m.y, RED);		// ����ƶ���ʱ�򻭺�ɫ��С��
			break;

		case WM_LBUTTONDOWN:
			if (m.ctrl)						// ����������ͬʱ������ Ctrl ��
				rectangle(m.x - 10, m.y - 10, m.x + 10, m.y + 10);
			else
				rectangle(m.x - 5, m.y - 5, m.x + 5, m.y + 5);
			break;
		}
	}
}

int main()
{
	// �����������
	srand((unsigned)time(NULL));

	// ����������ͼ����
	HWND hWnd1 = hiex::initgraph_win32(640, 480, false, L"�ַ���");
	HWND hWnd2 = hiex::initgraph_win32(640, 480, false, L"������ʾ��");

	while (true)
	{
		// ������ 1 δ���ر�
		if (hiex::IsAliveWindow(hWnd1))
		{
			BEGIN_TASK_WND(hWnd1);	// ���ô��� 1 ΪĿ���ͼ���ڣ�������һ����ͼ����
			CharacterArray();		// ����
			END_TASK();				// ��������
			REDRAW_WINDOW();		// ˢ�»������ݵ�����
		}

		// ������ 2 δ���ر�
		if (hiex::IsAliveWindow(hWnd2))
		{
			BEGIN_TASK_WND(hWnd2);
			OnMouse();
			END_TASK();
			REDRAW_WINDOW();
		}

		// �����д��ڶ����رգ����������
		if (!hiex::IsAnyWindow())
		{
			break;
		}

		// ���� CPU ռ��
		Sleep(!(clock() % 77) ? 50 : 1);
	}

	return 0;
}
