#include "pch.h"
#include "CWirujaceKolo.h"

#define _USE_MATH_DEFINES
#include "math.h"

CWirujaceKolo::CWirujaceKolo(CPoint center, int radius, COLORREF color) : m_bRunning(false), m_dAngle(0), m_center(center), m_radius(radius), m_color(color) {}

void CWirujaceKolo::Start() {
    m_bRunning = true;
}

void CWirujaceKolo::Stop() {
    m_bRunning = false;
}

void CWirujaceKolo::Update() {
    if (m_bRunning) {
        m_dAngle += 0.001;
        if (m_dAngle >= 2 * M_PI) m_dAngle = 0;
    }
}

void CWirujaceKolo::Draw(CClientDC* dc) {
    CBrush brush(m_color);
    CBrush* pOldBrush = dc->SelectObject(&brush);

    int x = m_center.x + (int)(m_radius * cos(m_dAngle));
    int y = m_center.y + (int)(m_radius * sin(m_dAngle));

    dc->Ellipse(x - m_radius, y - m_radius, x + m_radius, y + m_radius);
    dc->SelectObject(pOldBrush);
}