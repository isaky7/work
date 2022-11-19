#pragma once


// CGameFalseDlg 对话框

class CGameFalseDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CGameFalseDlg)

public:
	CGameFalseDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CGameFalseDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_false };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
