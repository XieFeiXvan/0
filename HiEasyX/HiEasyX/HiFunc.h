////////////////////////////
//
//	HiFunc.h
//	HiEasyX ��ĳ��������
//

#pragma once

#include <Windows.h>
#include <WinUser.h>
#include <graphics.h>

// �洢������Ļ�Ĵ�С��Ϣ������ʾ����
struct ScreenSize
{
	int left;	// ����ʾ�������Ͻ� x ����
	int top;	// ����ʾ�������Ͻ� y ����
	int w;		// ����ʾ�����ܺͿ��
	int h;		// ����ʾ�����ܺ͸߶�
};

// ��ȡ����ʾ����С��Ϣ
ScreenSize GetScreenSize();

// ��ȡͼ��ߴ�
// ���Է���ش��� IMAGE ָ��Ϊ�գ���ָ������ͼ���ڵ����
void GetImageSize(IMAGE* pImg, int& width, int& height);

// �õ� IMAGE ����� HBITMAP
HBITMAP Image2Bitmap(IMAGE* img);

// HBITMAP ת HICON
HICON Bitmap2Icon(HBITMAP hBmp);

// ��ȷ��ʱ����(���Ծ�ȷ�� 1ms������ ��1ms)
// by yangw80<yw80@qq.com>, 2011-5-4
void HpSleep(int ms);

// ���Ƿ�λ�ھ�����
bool isInRect(int x, int y, RECT rct);

// ��ȡ ExMessage �� EM ��Ϣ����
UINT GetExMessageType(ExMessage msg);
