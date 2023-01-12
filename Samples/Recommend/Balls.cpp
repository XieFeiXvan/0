/**
 * @brief	͸��С��߽���ײʾ��
 * @note	��ʾ��������ʾ HiCanvas ��͸��ͨ����������ͼ��
 * @author	huidong <mailhuid@163.com>
 * @date	2023.01.12
*/

#include "HiEasyX.h"

// С������
#define BALL_NUM 14

// С��뾶
#define RADIUS 70

// ����
struct Ball
{
	hiex::ImageBlock img;
	float x, y;
	float vx, vy;
};

hiex::SysButton btn;			// ��ť
bool show_outline = false;		// �Ƿ���ʾ����

int main()
{
	hiex::Window wnd(640, 480);			// ��������
	hiex::Canvas canvas;				// ������������
	wnd.BindCanvas(&canvas);			// �����ںͻ�����

	// �ֶ�ˢ��˫����
	//hiex::EnableAutoFlush(false);

	canvas.Clear(true, BLACK);			// ���ñ���ɫΪ��ɫ����ջ���

	// ������ť�����ڵ�������Ƿ���ʾ����
	btn.Create(wnd.GetHandle(), 50, 50, 120, 30, L"Hide outline");
	btn.RegisterMessage([]() {
		show_outline = !show_outline;
	btn.SetText(show_outline ? L"Show outline" : L"Hide outline");
		});

	// ��ʼ�������
	srand((UINT)time(nullptr));

	hiex::Scene scene;		// ����
	hiex::Layer layer;		// ͼ��

	Ball balls[BALL_NUM];	// С��

	// ��ʼ��С��
	for (auto& i : balls)
	{
		// λ�ú��ٶȵĳ�ʼ��
		i.x = (float)(rand() % canvas.GetWidth());
		i.y = (float)(rand() % canvas.GetHeight());
		i.vx = rand() % 5 * (rand() % 2 ? 2.0f : -2.0f);
		i.vy = rand() % 5 * (rand() % 2 ? 2.0f : -2.0f);
		if (i.vx == 0)
			i.vx = 3;
		if (i.vy == 0)
			i.vy = 3;

		// С���ͼ�������
		i.img.CreateCanvas(RADIUS * 2, RADIUS * 2);
		i.img.GetCanvas()->Clear();
		i.img.GetCanvas()->SolidCircle(RADIUS, RADIUS, RADIUS, true, rand() % 0xffffff);
		ReverseAlpha(i.img.GetCanvas()->GetBuffer(), i.img.GetCanvas()->GetBufferSize());

		// ����ͼ���͸����
		i.img.alpha = 200;
		i.img.bUseSrcAlpha = true;

		// ����ͼ��鵽ͼ��
		layer.push_back(&i.img);
	}

	// ����ͼ�㵽����
	scene.push_back(&layer);

	// ��ѭ�������ڹرջ��°���ʱ�˳���
	while (wnd.IsAlive() && !peekmessage(nullptr, EM_CHAR))
	{
		for (auto& i : balls)
		{
			i.x += i.vx;
			i.y += i.vy;

			// ��ײ�ж�
			if (i.x - RADIUS < 0)
			{
				i.x = RADIUS;
				i.vx = -i.vx;
			}
			if (i.x + RADIUS > canvas.GetWidth())
			{
				i.x = (float)canvas.GetWidth() - RADIUS;
				i.vx = -i.vx;
			}
			if (i.y - RADIUS < 0)
			{
				i.y = RADIUS;
				i.vy = -i.vy;
			}
			if (i.y + RADIUS > canvas.GetHeight())
			{
				i.y = (float)canvas.GetHeight() - RADIUS;
				i.vy = -i.vy;
			}

			// ����λ��
			i.img.SetPos((int)i.x - RADIUS, (int)i.y - RADIUS);
		}

		if (wnd.BeginTask())
		{
			// ��Ⱦ����
			scene.Render(canvas.GetImagePointer(), show_outline);

			// �ֶ�ˢ��˫����
			//wnd.FlushDrawing();

			wnd.EndTask();
			wnd.Redraw();
		}

		// ƽ��֡��
		hiex::DelayFPS(24);
	}

	return 0;
}
