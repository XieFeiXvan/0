////////////////////////////////////
//
//	SysComboBox.h
//	HiSysGUI �ؼ���֧����Ͽ�
//

#pragma once

#include "SysControlBase.h"

namespace HiEasyX
{
	class SysComboBox : public SysControlBase
	{
	private:

		long m_lBasicStyle = WS_CHILD | WS_VISIBLE | WS_TABSTOP | CBS_DROPDOWN | CBS_HASSTRINGS | CBS_AUTOHSCROLL;
		int m_nSel = -1;
		bool m_bSelChanged = false;
		bool m_bEdited = false;
		void (*m_pFuncSel)(int sel, std::wstring wstrSelText) = nullptr;
		void (*m_pFuncEdit)(std::wstring wstrText) = nullptr;

		// �û������� CBS_SIMPLE ͬʱ��������
		// �������Ҫ����ʵ��
		bool m_bSimple_No_Edit = false;

	protected:

		void RealCreate(HWND hParent) override;

	public:

		SysComboBox();

		SysComboBox(HWND hParent, RECT rct, std::wstring strText = L"");

		SysComboBox(HWND hParent, int x, int y, int w, int h, std::wstring strText = L"");

		// �ڴ����ؼ�ǰԤ����ʽ
		void PreSetEtyle(
			bool always_show_list,	// �Ƿ�������ʾ�б�
			bool editable,			// �Ƿ�ɱ༭
			bool sort				// �Ƿ��Զ�����
		);

		LRESULT UpdateMessage(UINT msg, WPARAM wParam, LPARAM lParam, bool& bRet) override;

		// ע��ѡ����Ϣ
		void RegisterSelMessage(void (*pFunc)(int sel, std::wstring wstrSelText));

		// ע��༭��Ϣ
		void RegisterEditMessage(void (*pFunc)(std::wstring wstrText));

		// ��ȡѡ�е�����
		int GetSel() const { return m_nSel; }

		// ����ѡ�е�����
		void SetSel(int sel);

		// ѡ�����ָ���ı���һ��
		// �����Ƿ�ѡ��ɹ�
		bool SelectString(std::wstring wstrText);

		// ������
		void AddString(std::wstring wstrText);

		// ������
		void InsertString(int index, std::wstring wstrText);

		// ɾ����
		void DeleteString(int index);

		// ��ȡ�б���������
		int GetCount();
		
		// ����б�
		void Clear();

		// ��ʾ�б�
		void ShowDropdown(bool enable);

		// ѡ�����Ƿ�仯
		bool isSelChanged();

		// �Ƿ񱻱༭
		bool isEdited();
	};
}
