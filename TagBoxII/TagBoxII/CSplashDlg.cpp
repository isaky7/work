// CSplashDlg.cpp: 实现文件
//

#include "pch.h"
#include "TagBoxII.h"
#include "CSplashDlg.h"
#include "afxdialogex.h"


// CSplashDlg 对话框

IMPLEMENT_DYNAMIC(CSplashDlg, CDialog)

CSplashDlg::CSplashDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DEMO_DIALOG, pParent)
{

}

BOOL CSplashDlg::OnInitDialog()
{
	this->MoveWindow(0, 0, 1200, 800);//动画窗口大小
	ShowWindow(SW_NORMAL);
	CRect rtDesk;
	CRect rtDlg;
	::GetWindowRect(::GetDesktopWindow(), &rtDesk);
	GetWindowRect(&rtDlg);
	int iXpos = rtDesk.Width() / 2 - rtDlg.Width() / 2;
	int iYpos = rtDesk.Height() / 2 - rtDlg.Height() / 2;
	SetWindowPos(NULL, iXpos, iYpos, 0, 0, SWP_NOOWNERZORDER | SWP_NOSIZE | SWP_NOZORDER); 
	
	//加入以下部分设置Static字体
	
	return true;
}
CSplashDlg::~CSplashDlg()
{
}

void CSplashDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

}


BEGIN_MESSAGE_MAP(CSplashDlg, CDialog)
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CSplashDlg 消息处理程序


HBRUSH CSplashDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void CSplashDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialog::OnPaint()
	CRect   rect;
	GetClientRect(&rect);												// 获取对话框长宽      
	CDC   dcBmp;															// 定义并创建一个内存设备环境
	dcBmp.CreateCompatibleDC(&dc);						// 创建兼容性DC
	CBitmap   bmpBackground;
	bmpBackground.LoadBitmap(IDB_BITMAP7);    // 载入资源中图片
	BITMAP   m_bitmap;												// 图片变量               
	bmpBackground.GetBitmap(&m_bitmap);			// 将图片载入位图中

	//将位图选入临时内存设备环境
	CBitmap* pbmpOld = dcBmp.SelectObject(&bmpBackground);

	//调用函数显示图片StretchBlt显示形状可变
	dc.SetStretchBltMode(COLORONCOLOR);			// 防止 bmp 图片压缩后失真
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcBmp, 0, 0, m_bitmap.bmWidth, m_bitmap.bmHeight, SRCCOPY);
}

