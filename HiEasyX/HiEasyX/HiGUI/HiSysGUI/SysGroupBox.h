////////////////////////////////////
//
//	SysGroupBox.h
//	HiSysGUI �ؼ���֧�������
//

#pragma once

#include "SysControlBase.h"

namespace HiEasyX
{
	// ע�⣺����򱳾������� Bug��������ʹ��
	// �����ؼ�ʱ��Ҫ���˿ؼ���Ϊ���ؼ��������޷������ؼ�
	class SysGroupBox : public SysControlBase
	{
	protected:

		void RealCreate(HWND hParent) override;

	public:

		SysGroupBox();

		SysGroupBox(HWND hParent, RECT rct, std::wstring strText = L"");

		SysGroupBox(HWND hParent, int x, int y, int w, int h, std::wstring strText = L"");
	};
}
