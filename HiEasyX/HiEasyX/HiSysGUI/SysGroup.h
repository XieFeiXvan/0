////////////////////////////////////
//
//	SysGroup.h
//	HiSysGUI �ؼ���֧��������
//

#pragma once

#include "SysControlBase.h"

namespace HiEasyX
{
	class SysGroup : public SysControlBase
	{
	protected:

		void RealCreate(HWND hParent) override;

	public:

		SysGroup();

		SysGroup(HWND hParent);

		void Create(HWND hParent);
	};
}
