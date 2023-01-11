/**
 * @file	HiGdiPlus.h
 * @brief	HiEasyX ��� Gdi+ ��ͼģ��
 * @author	huidong
*/

#pragma once

#include <Windows.h>
#include <gdiplus.h>

namespace HiEasyX
{
	/**
	 * @brief ���� GDI+
	*/
	void Gdiplus_Starup();

	/**
	 * @brief �ر� GDI+
	*/
	void Gdiplus_Shutdown();

	/**
	 * @brief ת�� COLORREF �� Gdiplus::Color
	 * @param[in] color				ԭ��ɫ
	 * @param[in] reserve_alpha		�Ƿ��� COLORREF �е� alpha ֵ
	 * @return ת����� Gdiplus::Color ɫֵ
	*/
	Gdiplus::Color ConvertToGdiplusColor(COLORREF color, bool reserve_alpha = false);
	
	/**
	 * @brief ����
	*/
	void Gdiplus_Line(
		HDC hdc,
		float x1,
		float y1,
		float x2,
		float y2,
		Gdiplus::Color color,
		float width,
		Gdiplus::SmoothingMode smoothing_mode
	);

	void Gdiplus_Polygon(
		HDC hdc, 
		int points_num, 
		Gdiplus::PointF* points,
		Gdiplus::Color color, 
		float width, 
		Gdiplus::SmoothingMode smoothing_mode
	);

	void Gdiplus_Rectangle(HDC hdc, float x, float y, float w, float h, Gdiplus::Color color, float width, Gdiplus::SmoothingMode smoothing_mode);


};
