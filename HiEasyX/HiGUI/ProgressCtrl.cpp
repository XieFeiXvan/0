#include "ProgressCtrl.h"

namespace HiEasyX
{
	ProgressCtrl::ProgressCtrl()
	{
		SetBarColor(GREEN);
	}

	ProgressCtrl::ProgressCtrl(int x, int y, int w, int h, int len)
	{
		m_nLen = len;
		SetRect(x, y, w, h);
		SetBarColor(GREEN);
	}

	void ProgressCtrl::SetLen(int len)
	{
		m_nLen = len;
	}

	void ProgressCtrl::SetProcess(int pos)
	{
		m_nPos = pos;
	}

	void ProgressCtrl::Step()
	{
		if (m_nPos + 1 <= m_nLen)
		{
			m_nPos++;
		}
	}

	void ProgressCtrl::SetBarColor(COLORREF cBar)
	{
		float h, s, l;
		RGBtoHSL(cBar, &h, &s, &l);
		m_fH = h;
		m_fS = s;
		m_cBar = HSLtoRGB(h, s, m_fBarColorLightness);
	}

	void ProgressCtrl::EnableAnimation(bool enable)
	{
		m_bEnableAnimation = enable;
	}

	void ProgressCtrl::Redraw(bool draw_child)
	{
		ControlBase::Redraw(false);

		// 绘制结束位置
		int nEnd = (int)((m_nPos / (float)m_nLen) * (GetWidth() - 2));

		m_canvas.SolidRectangle(
			{ 1,1,nEnd,GetHeight() - 2 },
			true, m_cBar
		);

		// 绘制动画效果
		if (m_bEnableAnimation)
		{
			// 动画进度
			if (m_tClock == 0)	m_tClock = clock();
			float fProcess = (
				((clock() - m_tClock) / (float)CLOCKS_PER_SEC)	// 经过时长
				/ (1 / m_fSpeedRatio)							// 总时长
				);
			if (fProcess >= 1)
			{
				fProcess = 0;
				m_tClock = clock();
			}

			int nAnimationLen = (int)(m_nPos / (float)m_nLen * GetWidth() * m_fLenRatio);		// 动画效果长度
			int nAnimationLenHalf = nAnimationLen / 2;										// 动画效果半长
			int draw_pos = (int)((nEnd + nAnimationLen) * fProcess) - nAnimationLenHalf;	// 光源绘制 x 坐标
			for (int i = -nAnimationLenHalf; i < nAnimationLenHalf; i++)
			{
				int pos = i + draw_pos;		// 当前绘制 x 坐标

				// 当前绘制亮度
				float l = (m_fBarColorLightness - m_fBarLightLightness) * (abs(i) / (float)nAnimationLenHalf) + m_fBarLightLightness;
				if (pos >= 1 && pos <= nEnd)
				{
					m_canvas.Line(
						pos, 1, pos, GetHeight() - 2,
						true, HSLtoRGB(m_fH, m_fS, l)
					);
				}
			}
		}

		if (draw_child)
		{
			RedrawChild();
		}
	}
}
