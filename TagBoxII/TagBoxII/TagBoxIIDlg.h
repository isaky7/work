
// TagBoxIIDlg.h: 头文件
//

#pragma once
#include "CPictureEx.h"
#include"CMainGameDlg.h"
#include"CAbout.h"

// CTagBoxIIDlg 对话框
class CTagBoxIIDlg : public CDialogEx
{
// 构造
public:
	CTagBoxIIDlg(CWnd* pParent = nullptr);	// 标准构造函数
	CBitmap m_BKGround;
	//--------- 窗口标题栏 ------------------------------------
	CString m_Caption;						// 窗体标题
	int m_CaptionHeight;					// 标题栏的高度
	int m_TitleDrawHeight;				// 标题栏实际的绘制高度
	int m_ButtonWidth;						// 按钮位图宽度
	int m_ButtonHeight;					// 按钮高度
	int m_BorderWidth;						// 边框宽度
	int m_BorderHeight;					// 边框高度
	COLORREF m_CapitonColor;		// 标题字体颜色
	CFont m_CaptionFont;				// 标题字体
	CRect m_TitleRc;							// 标题栏区域
	

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAGBOXII_DIALOG };
#endif
	
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
protected:
	HBITMAP m_bmp;             // 位图
	int m_iWidth;                  // 位图的宽
	int m_iHeight;                 // 位图的高

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	CFont m_font;
	CStatic m_static;
	CStatic m_static2;


public:
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnBnClickedButtonClose();
	
	
	
	afx_msg void OnBnClickedStartbtn();
	afx_msg void OnBnClickedButton2();
	
	CStatic m_img1;
    
	
	CImage image;
	CImage image2;
	CImage image3;
	CStatic m_test;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
