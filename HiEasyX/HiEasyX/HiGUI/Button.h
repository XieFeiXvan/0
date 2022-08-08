////////////////////////////////////
//
//	Button.h
//	HiGUI �ؼ���֧����ť�ؼ�
//

#pragma once

#include "ControlBase.h"

namespace HiEasyX
{
	// ��ť�ؼ�
	class Button : public ControlBase
	{
	protected:

		bool m_bEnableClassicStyle = false;			// �Ƿ�ʹ�þ�����ʽ

		virtual void InitColor();

	public:

		// ��ť��ɫ���ã��ִ���ʽ��
		COLORREF m_cBorder_Normal = MODERN_BORDER_GRAY;
		COLORREF m_cBackground_Normal = MODERN_FILL_GRAY;
		COLORREF m_cBorder_Hovered = MODERN_BORDER_BLUE;
		COLORREF m_cBackground_Hovered = MODERN_FILL_BLUE;
		COLORREF m_cBorder_Pressed = MODERN_BORDER_PRESSED_BLUE;
		COLORREF m_cBackground_Pressed = MODERN_FILL_PRESSED_BLUE;

		COLORREF m_cText_Disabled = LIGHTGRAY;
		COLORREF m_cBorder_Disabled = GRAY;
		COLORREF m_cBackground_Disabled = GRAY;

		COLORREF m_cClassicNormalBorder3D = GRAY;			// δ����ʱ�� 3D �߿���ɫ��������ʽ��
		COLORREF m_cClassicPressedBorder3D = LIGHTGRAY;		// ����ʱ�� 3D �߿���ɫ��������ʽ��

		Button();

		Button(int x, int y, int w, int h, std::wstring wstrText = L"");

		void SetEnable(bool enable) override;

		virtual void EnableClassicStyle(bool enable);
		
		void UpdateMessage(ExMessage msg) override;

		void Draw(bool draw_child = true) override;
	};
}

