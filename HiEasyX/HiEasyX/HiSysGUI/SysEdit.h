/**
 * @file	SysEdit.h
 * @brief	HiSysGUI �ؼ���֧�������
 * @author	huidong
*/

#pragma once

#include "SysControlBase.h"

#include <graphics.h>

namespace HiEasyX
{
	/**
	 * @brief ϵͳ�����ؼ�
	*/
	class SysEdit : public SysControlBase
	{
	private:

		/**
		 * @brief �༭������
		*/
		struct Property
		{
			bool left_align = true;			///< ���������
			bool right_align = false;		///< �����Ҷ���
			bool uppercase = false;			///< ��������ת��д
			bool lowercase = false;			///< ��������תСд
			bool password = false;			///< �����
			bool read_only = false;			///< ֻ��
			bool number_only = false;		///< ����������
		} m_property;

		long m_lBasicStyle = WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER;
		void (*m_pFunc)(std::wstring wstrText) = nullptr;
		bool m_bEdited = false;

		COLORREF m_cBk = WHITE;
		COLORREF m_cTextBk = WHITE;
		COLORREF m_cText = BLACK;
		HBRUSH hBk = nullptr;

		/**
		 * @brief Ӧ�����õ�����
		*/
		void ApplyProperty();

	protected:

		void RealCreate(HWND hParent) override;

	public:

		SysEdit();

		SysEdit(HWND hParent, RECT rct, std::wstring strText = L"");

		SysEdit(HWND hParent, int x, int y, int w, int h, std::wstring strText = L"");

		~SysEdit() override;

		/**
		 * @brief �ڴ����ؼ�ǰԤ��ؼ���ʽ
		 * @param [in] multiline			�����ı�
		 * @param [in] center_text		�ı�����
		 * @param [in] vscroll			ӵ�д�ֱ������
		 * @param [in] auto_vscroll		�Զ���ֱ����
		 * @param [in] hscroll			ӵ��ˮƽ������
		 * @param [in] auto_hscroll		�Զ�ˮƽ����
		*/
		void PreSetStyle(
			bool multiline,
			bool center_text = false,
			bool vscroll = false,
			bool auto_vscroll = false,
			bool hscroll = false,
			bool auto_hscroll = false
		);

		LRESULT UpdateMessage(UINT msg, WPARAM wParam, LPARAM lParam, bool& bRet) override;

		/**
		 * @brief ע��������Ϣ
		 * @param [in] pFunc ��Ϣ��Ӧ����
		*/
		void RegisterMessage(void (*pFunc)(std::wstring wstrText));

		/**
		 * @brief �����ı��Ҷ���
		 * @param [in] enable �Ƿ������Ҷ���
		*/
		void RightAlign(bool enable);

		/**
		 * @brief �Զ�ת��д
		 * @param [in] enable �Ƿ�����ת��д
		*/
		void Uppercase(bool enable);

		/**
		 * @brief �Զ�תСд
		 * @param [in] enable �Ƿ�����תСд
		*/
		void Lowercase(bool enable);

		/**
		 * @brief ���������
		 * @param [in] enable �Ƿ����������
		*/
		void Password(bool enable);

		/**
		 * @brief ����ֻ��
		 * @param [in] enable �Ƿ�����ֻ��
		*/
		void ReadOnly(bool enable);

		/**
		 * @brief ���ý�����
		 * @param [in] enable �Ƿ����ý���������
		*/
		void NumberOnly(bool enable);

		/**
		 * @brief ��ȡ������볤��
		*/
		int GetMaxTextLength();

		/**
		 * @brief ����������볤��
		 * @param [in] len ������볤��
		*/
		void SetMaxTextLength(int len);

		/**
		 * @brief ���ÿؼ�����ɫ
		 * @param [in] color �ؼ�����ɫ 
		*/
		void SetBkColor(COLORREF color);

		/**
		 * @brief �����ı�����ɫ
		 * @param [in] color �ı�����ɫ
		*/
		void SetTextBkColor(COLORREF color);

		/**
		 * @brief �����ı���ɫ
		 * @param [in] color �ı���ɫ 
		*/
		void SetTextColor(COLORREF color);

		/**
		 * @brief ��ȡ���ѡ������
		 * @param [out] begin	�����ʼλ��
		 * @param [out] end		ѡ�����λ��
		*/
		void GetSel(int* begin, int* end);

		/**
		 * @brief ���ù��ѡ������
		 * @param [in] begin 	�����ʼλ��
		 * @param [in] end 		ѡ�����λ�ã�Ϊ -1 �ɱ�ʾ��β��
		*/
		void SetSel(int begin, int end);

		/**
		 * @brief ����ѡ�е��ı�
		*/
		void Copy();

		/**
		 * @brief ����ѡ�е��ı�
		*/
		void Cut();

		/**
		 * @brief �Ӽ��а�����ı�����ǰλ��
		*/
		void Paste();

		/**
		 * @brief ɾ��ѡ�е��ı�
		*/
		void Delete();

		/**
		 * @brief �滻ѡ�е��ı�
		 * @param [in] wstrText �滻�ı�
		*/
		void Replace(std::wstring wstrText);

		/**
		 * @brief �ж��Ƿ񱻱༭
		*/
		bool isEdited();
	};
}