/**
 * @brief 	�� 0 �׶Σ���ʼ����
 * @note
 * 			�����У�������ķ�ʽչ���� HiEasyX �ĵ��÷�ʽ <p>
 *			�ں���������У������ٽ��� BEGIN_TASK() ϵ�к� <p>
 *
 * @attention
 *			BEGIN_TASK() ��ֱ��Ϊ��ǰ���������������� <p>
 *			�������������ʱ����Ҫʹ�� BEGIN_TASK_WND() �������񣬲�ָ�����񴰿� <p>
 *
 * @author 	huidong <mailhuid@163.com>
 * @date 	2023.01.12
*/

#include "HiEasyX.h"		// ���� HiEasyX ͷ�ļ�

int main()
{
	initgraph();			// ��ʼ������

	BEGIN_TASK();			// ����ͬ�� EasyX���������񣬱�ʶ��ʼ����

	circle(320, 240, 100);	// ��Բ

	END_TASK();				// ����ͬ�� EasyX����ɻ��ƣ���������

	REDRAW_WINDOW();		// ����ͬ�� EasyX��ˢ����Ļ��ʹ�ղŻ��Ƶ�������ʾ����

	getmessage(EM_KEY);		// ������˳�

	closegraph();			// �رմ���
	return 0;
}
