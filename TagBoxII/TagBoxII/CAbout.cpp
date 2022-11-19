// CAbout.cpp: 实现文件
//

#include "pch.h"
#include "TagBoxII.h"
#include "CAbout.h"
#include "afxdialogex.h"


// CAbout 对话框

IMPLEMENT_DYNAMIC(CAbout, CDialogEx)

CAbout::CAbout(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ABOUTBOX, pParent)
{

}

CAbout::~CAbout()
{
}

void CAbout::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAbout, CDialogEx)
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CAbout 消息处理程序


HBRUSH CAbout::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if (pWnd->GetDlgCtrlID() == IDC_STATIC1|| pWnd->GetDlgCtrlID() == IDC_STATIC2)//控件ID
	{	pDC->SetTextColor(RGB(255, 0, 0));//设置颜色
	pDC->SetBkMode(TRANSPARENT);
	return (HBRUSH)::GetStockObject(NULL_BRUSH);
}
		if (pWnd->GetDlgCtrlID() ==IDC_aboutgif)//控件ID
		{
			pDC->SetBkColor(TRANSPARENT); return (HBRUSH)::GetStockObject(NULL_BRUSH);
		}
		
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void CAbout::OnPaint()//重绘对话框
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
	CRect   rect;
	GetClientRect(&rect);												// 获取对话框长宽      
	CRect  rect2;
	GetClientRect(&rect2);
	CDC   dcBmp;															// 定义并创建一个内存设备环境
	dcBmp.CreateCompatibleDC(&dc);						// 创建兼容性DC
	CBitmap   bmpBackground;
	bmpBackground.LoadBitmap(IDB_BITMAP6);    // 载入资源中图片
	BITMAP   m_bitmap;												// 图片变量               
	bmpBackground.GetBitmap(&m_bitmap);			// 将图片载入位图中

	//将位图选入临时内存设备环境
	CBitmap* pbmpOld = dcBmp.SelectObject(&bmpBackground);

	//调用函数显示图片StretchBlt显示形状可变
	dc.SetStretchBltMode(COLORONCOLOR);			// 防止 bmp 图片压缩后失真
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcBmp, 0, 0, m_bitmap.bmWidth, m_bitmap.bmHeight, SRCCOPY);
	
}


BOOL CAbout::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
