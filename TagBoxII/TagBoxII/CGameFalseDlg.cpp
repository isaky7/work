// CGameFalseDlg.cpp: 实现文件
//

#include "pch.h"
#include "TagBoxII.h"
#include "CGameFalseDlg.h"
#include "afxdialogex.h"


// CGameFalseDlg 对话框

IMPLEMENT_DYNAMIC(CGameFalseDlg, CDialogEx)

CGameFalseDlg::CGameFalseDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_false, pParent)
{

}

CGameFalseDlg::~CGameFalseDlg()
{
}

void CGameFalseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CGameFalseDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CGameFalseDlg 消息处理程序


BOOL CGameFalseDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CGameFalseDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
}


HBRUSH CGameFalseDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}
