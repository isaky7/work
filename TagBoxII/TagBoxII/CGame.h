#pragma once
class CGame
{
	void SetHandle(HWND hWnd);//����������ھ��
	bool EnterFrame(DWORD dwTimer);//������Ϸ֡
	void OnMouseMove(UINT nFlags, CPoint point); //���ؼ�
	void OnLButtonUp(UINT nFlags, CPoint point);//���̧���¼�
private:
	HWND m_hWnd;
	//����
};

