//////////////////////////////////////////////////
//
//	�� 3 �׶Σ�ʹ�û������л���
//
//	Canvas ��װ�� EasyX �����л�ͼ������
//	ʹ�ø����㣬����֧��͸��ͨ����
//	�����У��������ʹ��ڰ󶨣���ֱ���ڴ����ϻ�ͼ��
//

#include "HiEasyX.h"

int main()
{
	hiex::Window wnd;
	wnd.Create();				// ��������

	hiex::Canvas canvas;
	wnd.BindCanvas(&canvas);	// �󶨴��ڵĻ�����֮��Ϳ���ֱ���ڻ����ϻ���

	bool first = true;
	while (wnd.isAlive())
	{
		if (wnd.isSizeChanged() || first)
		{
			canvas.Clear();		// ʹ�û�������ʱ����������������
			canvas.Circle(
				canvas.GetWidth() / 2,
				canvas.GetHeight() / 2,
				100
			);

			wnd.Redraw();		// ���跢�ʹ����ػ���Ϣ

			first = false;
		}

		Sleep(clock() % 77 ? 1 : 50);
	}

	return 0;
}
