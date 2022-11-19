#pragma once


// CPlayway 对话框

class CPlayway : public CDialogEx
{
	DECLARE_DYNAMIC(CPlayway)

public:
	CPlayway(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CPlayway();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Way };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
private:
	CFont m_font1;
	CFont m_font2;
	CStatic m_staticW1;
	CStatic m_staticW2;
	
public:
	afx_msg void OnBnClickedBackbtn();
};
