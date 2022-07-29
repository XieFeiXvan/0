#pragma once

#include "HiMacro.h"
#include "HiFunc.h"
#include "HiCanvas.h"
#include "HiMouseDrag.h"

#include <ctime>
#include <string>
#include <vector>
#include <list>

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

	// �ؼ���Ϣ
	enum CtrlMessage
	{
		CM_OTHER,						// δ�����ʶ��������Ϣ
		CM_HOVER,						// ��ͣ
		CM_HOVER_OVER,					// ��ͣ����
		CM_PRESS,						// ����
		CM_PRESS_OVER,					// ���½���
		CM_CLICK,						// ����
		CM_DOUBLE_CLICK,				// ˫��
		CM_FOCUS,						// ��ȡ����
		CM_FOCUS_OVER,					// ��ʧ����

	};

	class ControlBase;

	// �ؼ���Ϣ������
	// _Ctrl	����ؼ�ָ��
	// _MsgId	������Ϣ��ʶ����
	// _ExMsg	������ϸ��Ϣ�������ѱ任���ؼ���
	typedef void (*MESSAGE_PROC_FUNC)(ControlBase* _Ctrl, int _MsgId, ExMessage _ExMsg);

	// ֧�־�̬�ຯ����Ϊ�ؼ���Ϣ������
	typedef void (*MESSAGE_PROC_FUNC_CLASS)(void* _This, ControlBase* _Ctrl, int _MsgId, ExMessage _ExMsg);

	class ControlBase : public Container
	{
	protected:

		bool m_bEnabled = true;										// �Ƿ����
		bool m_bVisible = true;										// �Ƿ�ɼ�

		std::wstring m_wstrText;									// �ؼ��ı�

		Canvas m_canvas;											// ����
		BYTE m_alpha = 255;											// ͸����
		bool m_bUseCanvasAlpha = false;								// �Ƿ�ʹ�û��������͸������Ϣ
		bool m_isAlphaCalculated = false;							// �����Ƿ��Ѿ�����͸�������ɫ

		COLORREF m_cBorder = MODEN_BORDER_GRAY;						// �߿���ɫ
		COLORREF m_cBackground = CLASSICGRAY;						// ����ɫ
		COLORREF m_cText = BLACK;									// �ı���ɫ

		bool m_bEnableBorder = true;								// �Ƿ���Ʊ߿�
		int m_nBorderThickness = 1;									// �߿��ϸ

		bool m_bCompleteFirstSetRect = false;						// �Ƿ��Ѿ���ɵ�һ����������

		ControlBase* m_pParent = nullptr;							// ���ؼ�
		std::list<ControlBase*> m_listChild;						// �ӿؼ�

		bool m_bAutoSizeForChild = false;							// Ϊ�ӿؼ��Զ��ı��С�����ɿؼ�

		MESSAGE_PROC_FUNC m_funcMessageProc = nullptr;				// ��Ϣ������
		MESSAGE_PROC_FUNC_CLASS m_funcMessageProc_Class = nullptr;	// ���󶨵���Ϣ�������Ǿ�̬�ຯ�������¼���ַ
		void* m_pCalledClass = nullptr;								// ���󶨵���Ϣ�������Ǿ�̬�ຯ�������¼����ָ��

		bool m_bHovered = false;									// ����Ƿ���ͣ
		bool m_bPressed = false;									// ����Ƿ���
		bool m_bFocused = false;									// �Ƿ�ӵ�н���

		// �ػ��ӿؼ�
		virtual void RedrawChild();

		// ת����Ϣ
		virtual ExMessage& TransformMessage(ExMessage& msg);

		// �ַ���Ϣ���û�����
		virtual void CallUserMsgProcFunc(int msgid, ExMessage msg);

		// �ӿؼ��������
		virtual void ChildRectChanged(ControlBase* pChild);

	public:

		ControlBase();

		ControlBase(std::wstring wstrText);

		ControlBase(int x, int y, int w = 0, int h = 0, std::wstring wstrText = L"");

		virtual ~ControlBase();

		ControlBase* GetParent() { return m_pParent; }

		// ���ø��ؼ����ڲ����� AddChild��
		virtual void SetParent(ControlBase* p);

		virtual bool isAutoSizeForChild() const { return m_bAutoSizeForChild; }

		// Ϊ�ӿؼ��Զ��ı��С�����ɿؼ��������ɸ����겿�֣�
		virtual void EnableAutoSizeForChild(bool enable);

		std::list<ControlBase*>& GetChildList();

		virtual void AddChild(ControlBase* p, int offset_x = 0, int offset_y = 0);

		virtual void RemoveChild(ControlBase* p);

		virtual void UpdateRect();

		virtual bool isEnabled() const { return m_bEnabled; }

		virtual void SetEnable(bool enable);

		virtual bool isVisible() const { return m_bVisible; }

		virtual void SetVisible(bool visible);

		virtual Canvas& GetCanavs() { return m_canvas; }

		virtual COLORREF GetBkColor() const { return m_cBackground; }

		virtual void SetBkColor(COLORREF color);

		virtual COLORREF GetTextColor() const { return m_cText; }

		virtual void SetTextColor(COLORREF color);

		virtual void EnableBorder(bool bEnableBorder, COLORREF color = BLACK, int thickness = 1);

		virtual void SetAlpha(BYTE alpha, bool bUseCanvasAlpha, bool isAlphaCalculated);

		virtual std::wstring GetText() const { return m_wstrText; }

		virtual void SetText(std::wstring wstr);

		virtual void Draw_Text(int nTextOffsetX = 0, int nTextOffsetY = 0);

		// �ػ滭��
		virtual void Redraw(bool draw_child = true);

		// ��Ⱦ�ؼ�
		virtual void Render(Canvas* dst);

		// ������Ϣ��Ӧ����
		virtual void SetMsgProcFunc(MESSAGE_PROC_FUNC func);

		// ������Ϣ��Ӧ����Ϊ��̬�ຯ��
		virtual void SetMsgProcFunc(MESSAGE_PROC_FUNC_CLASS static_class_func, void* _this);

		// ������Ϣ
		virtual void UpdateMessage(ExMessage msg);

		// �Ƿ���ͣ
		virtual bool isHovered() const { return m_bHovered; }

		// �Ƿ�ӵ�н���
		virtual bool isFocused() const { return m_bFocused; }

		// �Ƿ���
		virtual bool isPressed() const { return m_bPressed; }
	};

	// ��̬���ı���ͼ�񣩿ؼ�
	class Static : public ControlBase
	{
	public:

		struct Char
		{
			TCHAR ch;
			COLORREF cText;
			COLORREF cBk;
		};

	protected:

		std::vector<Char> m_vecText;
		ImageBlock* m_pImgBlock = nullptr;

	public:

		Static();

		Static(int x, int y, int w, int h, std::wstring wstrText = L"");

		virtual std::vector<Char> Convert(std::wstring wstrText);

		virtual std::wstring Convert(std::vector<Char> vecText);

		virtual std::vector<Char>& GetTextVector() { return m_vecText; }

		virtual void ClearText();

		virtual void AddText(
			std::wstring wstr,
			bool isSetTextColor = false,
			COLORREF cText = 0,
			bool isSetBkColor = false,
			COLORREF cBk = 0
		);

		void SetText(std::wstring wstrText) override;

		void SetText(std::vector<Char> vecText);

		// ��ȡ�����ͼ��
		virtual ImageBlock* GetImage() { return m_pImgBlock; }

		// ������ʾͼ��
		virtual void SetImage(ImageBlock* pImgBlockmg);

		void Draw_Text(int nTextOffsetX = 0, int nTextOffsetY = 0) override;

		void Redraw(bool draw_child = true) override;
	};

	// ��ť�ؼ�
	class Button : public ControlBase
	{
	protected:

		bool m_bEnableClassicStyle = false;			// �Ƿ�ʹ�þ�����ʽ

		void InitColor()
		{
			m_cBorder = m_cBorder_Normal;
			m_cBackground = m_cBackground_Normal;
		}

	public:

		// ��ť��ɫ���ã��ִ���ʽ��
		COLORREF m_cBorder_Normal = MODEN_BORDER_GRAY;
		COLORREF m_cBackground_Normal = MODEN_FILL_GRAY;
		COLORREF m_cBorder_Hovered = MODEN_BORDER_BLUE;
		COLORREF m_cBackground_Hovered = MODEN_FILL_BLUE;
		COLORREF m_cBorder_Pressed = MODEN_BORDER_PRESSED_BLUE;
		COLORREF m_cBackground_Pressed = MODEN_FILL_PRESSED_BLUE;

		COLORREF m_cBorder_Disabled = GRAY;
		COLORREF m_cBackground_Disabled = GRAY;

		COLORREF m_cClassicNormalBorder3D = GRAY;			// δ����ʱ�� 3D �߿���ɫ��������ʽ��
		COLORREF m_cClassicPressedBorder3D = LIGHTGRAY;		// ����ʱ�� 3D �߿���ɫ��������ʽ��

		Button();

		Button(int x, int y, int w, int h, std::wstring wstrText = L"");

		void SetEnable(bool enable) override;

		virtual void EnableClassicStyle(bool enable);

		void UpdateMessage(ExMessage msg) override;

		void Redraw(bool draw_child = true) override;
	};

	// �������ؼ�
	class ProgressCtrl : public ControlBase
	{
	protected:

		bool m_bEnableAnimation = true;					// �Ƿ����ö���Ч��

		int m_nLightPos = 0;							// ��Դλ��
		clock_t m_tClock = 0;							// ������һ�ζ����Ļ���ʱ��
		int m_nSpeed = 30;								// �����ٶȣ�����ÿ�룩

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

	// �������ؼ�
	class ScrollBar : public ControlBase
	{
	public:

		// ��������Ϣ
		struct ScrollBarInfo
		{
			int btnW, btnH;			// ��ͨ��ť�ߴ�
			int slider_free_len;	// �������ռ�ݵ����س���
			int slider_move_len;	// ���鶥������ƶ������س���
			int slider_len;			// �������س���
		};

	protected:

		int m_nBtnHeight = 20;				// ��ť�߶ȣ���ֱ����ʱ��Ч��
		int m_nBtnWidth = 20;				// ��ť��ȣ�ˮƽ����ʱ��Ч��

		bool m_bHorizontal = false;			// �Ƿ�ˮƽ����

		int m_nDrawInterval = 7;			// ���Ƽ�϶

		// ��ť
		Button m_btnTop;
		Button m_btnUp;
		Button m_btnDown;
		Button m_btnBottom;
		Button m_btnDrag;
		MouseDrag m_MouseDrag;
		bool m_bDragging = false;			// �Ƿ������϶�
		int m_nSliderSpeed = 20;			// ��ס��ťʱ����ÿ�����е����ݳ���
		clock_t m_tPressed = 0;				// ��ť��ס��ʱ

		float m_fPos = 0;					// ��������λ��
		int m_nLen = 0;						// �����ܳ���
		float m_fPosRatio = 0;				// ��������λ�ñ���

		ScrollBarInfo m_info = {};			// ��������Ϣ

		int m_nViewLen = 10;				// ��Ұ���ݳ���
		float m_fViewRatio = 1;				// ��Ұ��Χռ�ܳ��ȵı�

		bool m_bSliderPosChanged = false;	// ��ǻ���λ�øı�

		RECT m_rctOnWheel = { 0 };			// ��Ӧ������Ϣ�����򣨿ͻ������꣩
		bool m_bSetOnWheelRct = false;		// �Ƿ������˹�����Ϣ����Ӧ����

		// ��ʼ��
		virtual void Init();

		// ��Ӧ��ť��Ϣ
		static void OnButtonMsg(void* pThis, ControlBase* pCtrl, int msgid, ExMessage msg);

		// ���»���λ������
		virtual void UpdateSliderRect();

		// ����λ�ñ���
		void UpdatePosRatio();

		// ������Ұ����
		void UpdateViewRatio();

		// ���¹�������Ϣ
		void UpdateScrollBarInfo();

	public:

		ScrollBar();

		ScrollBar(int x, int y, int w, int h, int len, int pos, bool bHorizontal = false);

		int GetButtonHeight() const { return m_nBtnHeight; }

		// ���ð�ť�߶ȣ���ֱ����ʱ��Ч��
		void SetButtonHeight(int h);

		int GetButtonWidth() const { return m_nBtnWidth; }

		// ���ð�ť��ȣ�ˮƽ����ʱ��Ч��
		void SetButtonWidth(int w);

		// �Ƿ������϶�
		bool isDragging() const { return m_bDragging; }

		// ��ȡ��������λ��
		int GetSliderContentPos() const { return (int)m_fPos; }

		// ���û�������λ��
		void SetSliderContentPos(float pos);

		// �ƶ����������λ��
		void MoveSlider(float d);

		// ��ȡ���������ݳ���
		int GetContentLength() const { return m_nLen; }

		// ���ù��������ݳ���
		void SetContentLength(int len);

		int GetViewLength() const { return m_nViewLen; }

		// ������Ұ���ݳ���
		void SetViewLength(int len);

		int GetSliderSpeed() const { return m_nSliderSpeed; }

		// ���ð��°�ťʱ����������ٶȣ�ÿ�뾭�������ݳ��ȣ�
		void SetSliderSpeed(int speed);

		bool isHorizontal() const { return m_bHorizontal; }

		// ����ˮƽ����
		void EnableHorizontal(bool enable);

		// ����λ���Ƿ�ı�
		bool isSliderPosChanged();

		// ��ȡ��Ӧ������Ϣ������δ�Զ���ʱ���ؿ�����
		RECT GetOnWheelRect() const { return m_rctOnWheel; }

		// ������Ӧ������Ϣ�����򣨿ͻ������꣩
		void SetOnWheelRect(RECT rct);

		void UpdateRect() override;

		void UpdateMessage(ExMessage msg) override;

		void Redraw(bool draw_child = true) override;

	};

	class test : public ScrollBar
	{
	protected:
		static void OnButtonMsg(void* pThis, ControlBase* pCtrl, int msgid, ExMessage msg);
	};

	//class EditBox
	//{
	//public:
	//
	//	RECT m_rct;
	//
	//	COLORREF m_cLine;
	//	COLORREF m_cBackground;
	//
	//
	//	void Create(RECT rct)
	//	{
	//		m_rct = rct;
	//	}
	//
	//	void Show()
	//	{
	//		setlinecolor(m_cLine);
	//		setfillcolor(m_cBackground);
	//		fillrectangle(m_rct.left, m_rct.top, m_rct.right, m_rct.bottom);
	//
	//	}
	//
	//};

};
