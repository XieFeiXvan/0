////////////////////////////////////
//
//	ProgressCtrl.h
//	HiGUI �ؼ���֧���������ؼ�
//

#pragma once

#include "ControlBase.h"

#include <time.h>

namespace HiEasyX
{
	// �������ؼ�
	class ProgressCtrl : public ControlBase
	{
	protected:

		bool m_bEnableAnimation = true;					// �Ƿ����ö���Ч��

		int m_nLightPos = 0;							// ��Դλ��
		clock_t m_tClock = 0;							// ������һ�ζ����Ļ���ʱ��
		float m_fSpeedRatio = 0.4;						// �����ٶȣ�ÿ�뾭���ܳ��ȵĶ��٣�

		float m_fLenRatio = 0.8f;						// ��������Ч������ռ��

		float m_fBarColorLightness = 0.35f;				// ��������ɫ����
		float m_fBarLightLightness = 0.41f;				// ��������Դ����

		COLORREF m_cBar;								// ��������ɫ�����������Ȳ�����

		float m_fH = 0;									// ɫ����Ϣ
		float m_fS = 0;									// ���Ͷ���Ϣ

		int m_nPos = 0;									// ����������
		int m_nLen = 100;								// �����ܳ���

	public:

		ProgressCtrl();

		ProgressCtrl(int x, int y, int w, int h, int len);

		// ��ȡ�ܳ���
		virtual int GetLen() const { return m_nLen; }

		virtual void SetLen(int len);					// �����ܳ���

		// ��ȡ����
		virtual int GetProcess() const { return m_nPos; }

		virtual void SetProcess(int pos);				// ���ý���

		virtual void Step();							// ���ȼ�һ

		// ��ȡ��������ɫ
		virtual COLORREF GetBarColor() const { return m_cBar; }

		virtual void SetBarColor(COLORREF cBar);		// ���ý�������ɫ

		// ��ȡ��������״̬
		virtual bool GetAnimationState() const { return m_bEnableAnimation; }

		// �����Ƿ����ö���
		virtual void EnableAnimation(bool enable);

		void Redraw(bool draw_child = true) override;
	};
}

