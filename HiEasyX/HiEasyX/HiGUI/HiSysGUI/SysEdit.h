////////////////////////////////////
//
//	SysEdit.h
//	HiSysGUI �ؼ���֧�������
//

#pragma once

#include "SysControlBase.h"

#include <graphics.h>

namespace HiEasyX
{
	class SysEdit : public SysControlBase
	{
	private:

		// �༭������
		struct Property
		{
			bool left_align = true;			// ���������
			bool right_align = false;		// �����Ҷ���
			bool uppercase = false;			// ��������ת��д
			bool lowercase = false;			// ��������תСд
			bool password = false;			// �����
			bool read_only = false;			// ֻ��
			bool number_only = false;		// ����������
		} m_property;

		long m_lBasicStyle = WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER;
		void (*m_pFunc)(std::wstring wstrText) = nullptr;
		bool m_bEdited = false;

		COLORREF m_cBk = WHITE;
		COLORREF m_cTextBk = WHITE;
		COLORREF m_cText = BLACK;
		HBRUSH hBk = nullptr;

		// Ӧ�����õ�����
		void ApplyProperty();

	protected:

		void RealCreate(HWND hParent) override;

	public:

		SysEdit();

		SysEdit(HWND hParent, RECT rct, std::wstring strText = L"");

		SysEdit(HWND hParent, int x, int y, int w, int h, std::wstring strText = L"");

		~SysEdit() override;

		// �ڴ����ؼ�ǰԤ����ʽ
		void PreSetStyle(
			bool multiline,					// �����ı�
			bool center_text = false,		// �ı�����
			bool vscroll = false,			// ӵ�д�ֱ������
			bool auto_vscroll = false,		// �Զ���ֱ����
			bool hscroll = false,			// ӵ��ˮƽ������
			bool auto_hscroll = false		// �Զ�ˮƽ����
		);

		LRESULT UpdateMessage(UINT msg, WPARAM wParam, LPARAM lParam, bool& bRet) override;

		// ע��������Ϣ
		void RegisterMessage(void (*pFunc)(std::wstring wstrText));

		// �����ı��Ҷ���
		void RightAlign(bool enable);

		// �Զ�ת��д
		void Uppercase(bool enable);

		// �Զ�תСд
		void Lowercase(bool enable);

		// �����
		void Password(bool enable);

		// ֻ��
		void ReadOnly(bool enable);

		// ������
		void NumberOnly(bool enable);

		// ��ȡ������볤��
		int GetMaxTextLength();

		// ����������볤��
		void SetMaxTextLength(int len);

		// ���ÿؼ�����ɫ
		void SetBkColor(COLORREF color);

		// �����ı�����ɫ
		void SetTextBkColor(COLORREF color);

		// �����ı���ɫ
		void SetTextColor(COLORREF color);

		// ��ȡ���ѡ������
		void GetSel(int* begin, int* end);

		// ���ùر�ѡ������
		// end Ϊ -1 �ɱ�ʾ��β
		void SetSel(int begin, int end);

		// ����ѡ�е��ı�
		void Copy();

		// ����ѡ�е��ı�
		void Cut();

		// �Ӽ��а�����ı�����ǰλ��
		void Paste();

		// ɾ��ѡ�е��ı�
		void Delete();

		// �滻ѡ�е��ı�
		void Replace(std::wstring wstrText);

		// �Ƿ񱻱༭
		bool isEdited();
	};
}
