/**
 * @brief 	�� 3 �׶Σ�ʹ�û������л���
 * @note
 * 			Canvas ��װ�� EasyX �����л�ͼ������ʹ�ø����㣬����֧��͸��ͨ���� <p>
 *			�����������ʹ��ڰ󶨣���ֱ���ڻ����ϻ�ͼ�� <p>
 *
 * @author 	huidong <mailhuid@163.com>
 * @date 	2023.01.13
*/

#include "HiEasyX.h"

int main()
{
	hiex::Window wnd;
	wnd.Create();				// ��������

	hiex::Canvas canvas;
	wnd.BindCanvas(&canvas);	// �󶨴��ڵĻ�����֮��Ϳ���ֱ���ڻ����ϻ���

	bool first = true;
	while (wnd.IsAlive())
	{
		if (wnd.IsSizeChanged() || first)
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
