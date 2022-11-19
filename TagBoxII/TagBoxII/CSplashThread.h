#pragma once



// CSplashThread
#include"CSplashDlg.h"
class CSplashThread : public CWinThread
{
	DECLARE_DYNCREATE(CSplashThread)

protected:
	CSplashThread();           // 动态创建所使用的受保护的构造函数
	virtual ~CSplashThread();
	CSplashDlg* m_pSplashDlg;
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	void HideSplash();
protected:
	DECLARE_MESSAGE_MAP()
};


