#include "HiEasyX.h"

int main()
{
	hiex::Window wnd(300, 200);

	// �༭��
	hiex::SysEdit edit;
	edit.PreSetStyle({ true, false, true, true });	// Ԥ����ʽ���Բ��ô����ṹ�壬ֱ�Ӽ�д������
	edit.Create(wnd.GetHandle(), 10, 10, 280, 140, L"Type here~");
	edit.SetFont(24, 0, L"΢���ź�");

	// ��ť
	hiex::SysButton btn;
	btn.Create(wnd.GetHandle(), 190, 160, 100, 30, L"Submit");

	while (wnd.IsAlive())
	{
		// ���°�ťʱ��������ʾ������ı�
		if (btn.IsClicked())
			MessageBox(wnd.GetHandle(), edit.GetText().c_str(), L"Submit", MB_OK);
		Sleep(50);
	}

	return 0;
}