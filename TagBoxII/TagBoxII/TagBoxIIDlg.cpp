
// TagBoxIIDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "TagBoxII.h"
#include "TagBoxIIDlg.h"
#include "afxdialogex.h"
#include <tchar.h>
#include "CMainGameDlg.h"
#include"CPictureEx.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	
	
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CTagBoxIIDlg 对话框
			 


CTagBoxIIDlg::CTagBoxIIDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TAGBOXII_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CTagBoxIIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);


	DDX_Control(pDX, IDC_PngBtn, m_img1);

	DDX_Control(pDX, IDC_test, m_test);
}

BEGIN_MESSAGE_MAP(CTagBoxIIDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DRAWITEM()
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, &CTagBoxIIDlg::OnBnClickedButtonClose)
	ON_BN_CLICKED(IDC_Startbtn, &CTagBoxIIDlg::OnBnClickedStartbtn)
	ON_BN_CLICKED(IDC_BUTTON2, &CTagBoxIIDlg::OnBnClickedButton2)
	ON_WM_MOUSEMOVE()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CTagBoxIIDlg 消息处理程序

BOOL CTagBoxIIDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标


	// TODO: 在此添加额外的初始化代码


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
	

	//初始化按钮
	image.Load(_T("E:\\标记方格\\备选按钮3.png"));
	image2.Load(_T("E:\\标记方格\\备选按钮1.png"));

	m_static.SubclassDlgItem(IDC_Aboutst, this);
	m_font.CreatePointFont(170, _T("宋体"));
	m_static.SetFont(&m_font);
	m_static2.SubclassDlgItem(IDC_Startst, this);
	m_static2.SetFont(&m_font);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CTagBoxIIDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。
void TransparentPNG(CImage* png)
{
	for (int i = 0; i < png->GetWidth(); i++)  				//遍历像素处理
	{
		for (int j = 0; j < png->GetHeight(); j++)
		{
			byte* pucColor = (byte*)(png->GetPixelAddress(i, j));
			pucColor[0] = pucColor[0] * pucColor[3] / 255;
			pucColor[1] = pucColor[1] * pucColor[3] / 255;
			pucColor[2] = pucColor[2] * pucColor[3] / 255;
		}
	}
}

void CTagBoxIIDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		//CDialog::OnPaint(); 
  //添加代码对话框背景贴图
		CPaintDC   dc(this);
		CRect   rect;
		GetClientRect(&rect);    //获取对话框长宽      
		CDC   dcBmp;             //定义并创建一个内存设备环境
		dcBmp.CreateCompatibleDC(&dc);             //创建兼容性DC
		CBitmap   bmpBackground;
		bmpBackground.LoadBitmap(IDB_BITMAP2);    //载入资源中图片
		BITMAP   m_bitmap;                         //图片变量               
		bmpBackground.GetBitmap(&m_bitmap);       //将图片载入位图中
		 //将位图选入临时内存设备环境
		CBitmap* pbmpOld = dcBmp.SelectObject(&bmpBackground);
		//调用函数显示图片StretchBlt显示形状可变
		dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcBmp, 0, 0, m_bitmap.bmWidth, m_bitmap.bmHeight, SRCCOPY);

	
		//2.获得绘制区域（获得图片控件相对窗口的位置）
		m_img1.GetWindowRect(&rect);
		ScreenToClient(&rect);
		CDialogEx::OnPaint();
		//绘制图片
		TransparentPNG(&image);//透明化处理png
		image.Draw(dc, rect);

		
		m_test.GetWindowRect(&rect);
		ScreenToClient(&rect);
		CDialogEx::OnPaint();
		//绘制图片
		TransparentPNG(&image2);//透明化处理png
		image2.Draw(dc, rect);

	}


	
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CTagBoxIIDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTagBoxIIDlg::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	CDialogEx::OnDrawItem(nIDCtl, lpDrawItemStruct);
}


void CTagBoxIIDlg::OnBnClickedButtonClose()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnOK();
}



void CTagBoxIIDlg::OnBnClickedStartbtn()//按钮响应控件
{
	// TODO: 在此添加控件通知处理程序代码
	ShowWindow(SW_HIDE);//隐藏第一个对话框
	CMainGameDlg GameDlg;
	GameDlg.DoModal();//建立模态对话框

}


void CTagBoxIIDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CAbout ADlg;
	ADlg.DoModal();//关于
}




void CTagBoxIIDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	CDialogEx::OnMouseMove(nFlags, point);
}



HBRUSH CTagBoxIIDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if (pWnd->GetDlgCtrlID() == IDC_Startbtn || pWnd->GetDlgCtrlID() == IDC_AboutBtn) //获取控件ID
	{
		pDC->SetBkMode(TRANSPARENT); //设置背景透明
		return HBRUSH(GetStockObject(NULL_BRUSH)); //返回透明画刷
	}

	if (pWnd->GetDlgCtrlID() == IDC_Aboutst || pWnd->GetDlgCtrlID() == IDC_Startst) //获取控件ID
	{
		pDC->SetBkMode(TRANSPARENT); //设置背景透明
		pDC->SetTextColor(RGB(255, 255, 255));
		return HBRUSH(GetStockObject(NULL_BRUSH)); //返回透明画刷
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}
