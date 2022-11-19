// CPlayway.cpp: 实现文件
//

#include "pch.h"
#include "TagBoxII.h"
#include "CPlayway.h"
#include "afxdialogex.h"
#include"CMainGameDlg.h"

// CPlayway 对话框

IMPLEMENT_DYNAMIC(CPlayway, CDialogEx)

CPlayway::CPlayway(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Way, pParent)
{

}

CPlayway::~CPlayway()
{
}

void CPlayway::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

}


BEGIN_MESSAGE_MAP(CPlayway, CDialogEx)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BackBtn, &CPlayway::OnBnClickedBackbtn)
END_MESSAGE_MAP()


// CPlayway 消息处理程序


BOOL CPlayway::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	// TODO:  在此添加额外的初始化
	CRect   temprect(0, 0, 1100, 800);//绘制窗口矩形大小宽高
	CWnd::SetWindowPos(NULL, 0, 0, temprect.Width(), temprect.Height(), SWP_NOZORDER | SWP_NOMOVE);//设置客户区大小

	ShowWindow(SW_NORMAL);
	CRect rtDesk;
	CRect rtDlg;
	::GetWindowRect(::GetDesktopWindow(), &rtDesk);
	GetWindowRect(&rtDlg);
	int iXpos = rtDesk.Width() / 2 - rtDlg.Width() / 2;
	int iYpos = rtDesk.Height() / 2 - rtDlg.Height() / 2;
	SetWindowPos(NULL, iXpos, iYpos, 0, 0, SWP_NOOWNERZORDER | SWP_NOSIZE | SWP_NOZORDER);//对话框居中

	m_staticW1.SubclassDlgItem(IDC_Way1, this);
	m_font1.CreatePointFont(300, _T("宋体"));
	m_font2.CreatePointFont(200, _T("宋体"));
	m_staticW1.SetFont(&m_font1);
	m_staticW2.SubclassDlgItem(IDC_Way2, this);
	m_staticW2.SetFont(&m_font2);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CPlayway::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
	CRect rect;
	GetClientRect(&rect);												// 获取对话框长宽      
	CDC   dcBmp;															// 定义并创建一个内存设备环境
	dcBmp.CreateCompatibleDC(&dc);						// 创建兼容性DC
	CBitmap   bmpBackground;
	bmpBackground.LoadBitmap(IDB_BITMAP4);    // 载入资源中图片
	BITMAP   m_bitmap;												// 图片变量               
	bmpBackground.GetBitmap(&m_bitmap);			// 将图片载入位图中

	//将位图选入临时内存设备环境
	CBitmap* pbmpOld = dcBmp.SelectObject(&bmpBackground);

	//调用函数显示图片StretchBlt显示形状可变
	dc.SetStretchBltMode(COLORONCOLOR);			// 防止 bmp 图片压缩后失真
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcBmp, 0, 0, m_bitmap.bmWidth, m_bitmap.bmHeight, SRCCOPY);

}


HBRUSH CPlayway::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if (pWnd->GetDlgCtrlID() == IDC_Way1 || pWnd->GetDlgCtrlID() == IDC_Way2) //获取控件ID
	{
		pDC->SetBkMode(TRANSPARENT); //设置背景透明
		pDC->SetTextColor(RGB(255, 255, 255));
		return HBRUSH(GetStockObject(NULL_BRUSH)); //返回透明画刷
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void CPlayway::OnBnClickedBackbtn()
{
	// TODO: 在此添加控件通知处理程序代码
	ShowWindow(SW_HIDE);//隐藏第一个对话框
	CMainGameDlg backDlg;
	backDlg.DoModal();//建立模态对话框
}
