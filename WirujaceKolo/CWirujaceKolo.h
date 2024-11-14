#pragma once
#include <afxwin.h>

class CWirujaceKolo : public CObject
{
public:
    CWirujaceKolo(CPoint center, int radius = 50, COLORREF color = RGB(0, 0, 255));
    void Start();
    void Stop();
    void Update();
    void Draw(CClientDC* dc);

    CPoint GetCenter() const { return m_center; }
    int GetRadius() const { return m_radius; }

private:
    bool m_bRunning;
    double m_dAngle;
    CPoint m_center;
    int m_radius;
    COLORREF m_color;
};
