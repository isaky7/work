#pragma once
class CGame
{
	void SetHandle(HWND hWnd);//设置输出窗口句柄
	bool EnterFrame(DWORD dwTimer);//进入游戏帧
	void OnMouseMove(UINT nFlags, CPoint point); //鼠标控键
	void OnLButtonUp(UINT nFlags, CPoint point);//左键抬起事件
private:
	HWND m_hWnd;
	//窗口
};

