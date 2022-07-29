////////////////////////////////////
//
//	Container.h
//	HiGUI �ؼ���֧����������
//

#pragma once

#include <Windows.h>

namespace HiEasyX
{
	// ��������
	class Container
	{
	protected:

		RECT m_rct = {};						// ��������

	public:

		Container();

		virtual ~Container();

		virtual void UpdateRect() = 0;			// ����������Ϣ��Ӧ

		RECT GetRect() const { return m_rct; }

		void SetRect(int x, int y, int w, int h);

		void SetRect(RECT rct);

		POINT GetPos() const { return { m_rct.left,m_rct.top }; }

		int GetX() const { return m_rct.left; }

		int GetY() const { return m_rct.top; }

		void SetPos(int x, int y);

		void SetPos(POINT pt);

		void MoveRel(int dx, int dy);

		int GetWidth() const { return m_rct.right - m_rct.left; }

		void SetWidth(int w);

		int GetHeight() const { return m_rct.bottom - m_rct.top; };

		void SetHeight(int h);

		void Resize(int w, int h);
	};
}

