// CMainGame.cpp: 实现文件
//

#include "pch.h"
#include "TagBoxII.h"
#include "CMainGameDlg.h"
#include "afxdialogex.h"
#include"CPlayway.h"
#include"CGameFalseDlg.h"
#include"gdiplus.h"
// CMainGame 对话框

IMPLEMENT_DYNAMIC(CMainGameDlg, CDialog)

CMainGameDlg::CMainGameDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG2, pParent)
{

}

CMainGameDlg::~CMainGameDlg()
{
}

void CMainGameDlg::DoDataExchange(CDataExchange* pDX)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			TagBox[i][j] = -1;
		}
	}
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMainGameDlg, CDialog)
	ON_WM_PAINT()
	ON_COMMAND(ID_32772, &CMainGameDlg::OnClickedRestart)
	ON_COMMAND(ID_32773, &CMainGameDlg::OnClickedExit)
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_32774, &CMainGameDlg::OnClickedStart)
	ON_COMMAND(ID_32775, &CMainGameDlg::OnClickedWay)
END_MESSAGE_MAP()


// CMainGame 消息处理程序


BOOL CMainGameDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

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

	m_static1.SubclassDlgItem(IDC_point, this);
	m_font.CreatePointFont(170, _T("宋体"));
	m_static1.SetFont(&m_font);
	m_static2.SubclassDlgItem(IDC_point2, this);
	m_static2.SetFont(&m_font);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CMainGameDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialog::OnPaint()
	CRect   rect;
	GetClientRect(&rect);												// 获取对话框长宽      
	CDC   dcBmp;															// 定义并创建一个内存设备环境
	dcBmp.CreateCompatibleDC(&dc);						// 创建兼容性DC
	CBitmap   bmpBackground;
	bmpBackground.LoadBitmap(IDB_BITMAP3);    // 载入资源中图片
	BITMAP   m_bitmap;												// 图片变量               
	bmpBackground.GetBitmap(&m_bitmap);			// 将图片载入位图中

	//将位图选入临时内存设备环境
	CBitmap* pbmpOld = dcBmp.SelectObject(&bmpBackground);

	//调用函数显示图片StretchBlt显示形状可变
	dc.SetStretchBltMode(COLORONCOLOR);			// 防止 bmp 图片压缩后失真
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcBmp, 0, 0, m_bitmap.bmWidth, m_bitmap.bmHeight, SRCCOPY);


	//游戏绘制
	CDC* pDC = GetDC();
	ReleaseDC(pDC);

	Tag();
	
		CPen pen(PS_SOLID, 2, RGB(0, 0, 0));
		dc.SelectObject(pen);
		for (int i = 0; i < (SIZE + 1)/*下在格子里，要多画一条线*/; i++)
		{
			dc.MoveTo(450, 100 + i * 30);
			dc.LineTo(1050, 100 + i * 30);
		}//绘制棋盘横线
		for (int i = 0; i < (SIZE + 1); i++)
		{
			dc.MoveTo(450 + i * 30, 100);
			dc.LineTo(450 + i * 30, 700);
		}//绘制棋盘竖线
	
		
		for (i = 0; i < 50; i++) {
		for (j = 0; j < 50; j++) {
			if (TagBox[i][j]) { TagStyle(i, j); }
		}
	}
}

void CMainGameDlg::TagStyle(int x, int y)
{
}

void CMainGameDlg::MeanPoint(CPoint p)
{
	for (i = 0; i <= 50; i++) {
		for (j = 0; j <= 50; j++) {
			
		}
	}
}

void CMainGameDlg::Background(CDC* pDC)
{
	

}



void CMainGameDlg::Tag()
{
}

void CMainGameDlg::limit(int x, int y)
{
	if (TagBox[x][y] == 1) {
		if (TagBox[x+ 1][y] == 1 && TagBox[x - 1][y] == 1 && TagBox[x][y - 1] == 1 && TagBox[x][y + 1] == 0) {
			count++;
		}
		else if (TagBox[x + 1][y] == 1 && TagBox[x - 1][y] == 1 && TagBox[x][y - 1] == 0 && TagBox[x][y + 1] == 1) {
			count++;
		}
		else if (TagBox[x + 1][y] == 1 && TagBox[x - 1][y] == 0 && TagBox[x][y - 1] == 1 && TagBox[x][y + 1] == 1) {
			count++;
		}
		else if (TagBox[x + 1][y] == 0 && TagBox[x - 1][y] == 1 && TagBox[x][y - 1] == 1 && TagBox[x][y + 1] == 0) {
			count++;
		}
		else {
			//显示挑战失败；
			digit = 0;
			ShowWindow(SW_HIDE);//隐藏第一个对话框
			CGameFalseDlg  FalseDlg;
			FalseDlg.DoModal();//建立模态对话框
			//失败动画
		}
		if (digit == 60) {
			//游戏结束得分为
			ShowWindow(SW_HIDE);//隐藏第一个对话框
			CGameFalseDlg  FalseDlg;
			FalseDlg.DoModal();//建立模态对话框
		}
	}
}


void CMainGameDlg::OnClickedRestart()
{
	// TODO: 在此添加命令处理程序代码
	a = 0; count = 0;
	digit = 0;
	OnPaint();
}


void CMainGameDlg::OnClickedExit()
{
	// TODO: 在此添加命令处理程序代码
	CDialog::OnCancel();
}




void CMainGameDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	digit++;
	char ch[3];
	_itoa_s(digit, ch, 10);
	CString text(ch);
	SetDlgItemTextW(IDC_point, text);
	CDialog::OnTimer(nIDEvent);
}


void CMainGameDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	MeanPoint(p);
	limit(i,j);
	TagStyle(i, j);


	//
	i = -1; j = -1;
	p = point;
	MeanPoint(p);
	if (b == 1) {
		if (TagBox[i][j] == 1) {
			w = i, h = j; a = 1;
		}
		else if (TagBox[i][j] == 0 && a == 1) {
		}
	}
	CDialog::OnLButtonDown(nFlags, point);
}


void CMainGameDlg::OnClickedStart()
{
	// TODO: 在此添加命令处理程序代码
	if (TimerOn == false) {
		SetDlgItemTextW(ID_32774,_T("暂停游戏"));
		TimerOn = true;
		digit = 0;
		SetTimer(1, 1000, NULL);
	}
	else {
		TimerOn = false;
		KillTimer(1);
	}
}


void CMainGameDlg::OnClickedWay()
{
	// TODO: 在此添加命令处理程序代码
	ShowWindow(SW_HIDE);//隐藏第一个对话框
	CPlayway WayDlg;
	WayDlg.DoModal();//建立模态对话框
}
