#pragma once


// CMainGame 对话框
#define SIZE 50//棋盘行列
class CMainGameDlg : public CDialog
{
	DECLARE_DYNAMIC(CMainGameDlg)

public:
	CMainGameDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CMainGameDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	bool TimerOn;
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	
	afx_msg void OnPaint();
public:
	void TagStyle(int x, int y);//设计标签
	void MeanPoint(CPoint p);//确定点击有效位置
	void Background(CDC* pDC);//绘制棋盘
	void Tag();//初始标签放置
	void limit(int x, int y); //胜负条件判断
	int TagBox[50][50];//棋盘位置
	CPoint p;//保存点信息
	int w,h, n, a,b;//n是已经放置的标签个数，a=0未选定，a=1已选定，b=1放置标签,w,h标记选定的点
	int i, j;//坐标
	int count=0;
	int digit = 0;//计时器数字
	int k;//判断是否需要初始化
	afx_msg void OnClickedRestart();
	afx_msg void OnClickedExit();
	afx_msg void OnTimer(UINT_PTR nIDEvent);//定时器
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);//鼠标点击事件
	afx_msg void OnClickedStart();
	afx_msg void OnClickedWay();
};
