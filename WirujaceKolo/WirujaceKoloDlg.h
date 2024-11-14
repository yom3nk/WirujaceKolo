
// WirujaceKoloDlg.h : header file
//

#pragma once

#include "CWirujaceKolo.h"

// CWirujaceKoloDlg dialog
class CWirujaceKoloDlg : public CDialogEx
{
// Construction
public:
	CWirujaceKoloDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WIRUJACEKOLO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	CWirujaceKolo m_circle1;
	CWirujaceKolo m_circle2;
	CWirujaceKolo m_circle3;
	CWirujaceKolo m_circle4;

	afx_msg void OnStart1();
	afx_msg void OnStop1();
	afx_msg void OnStart2();
	afx_msg void OnStop2();
	afx_msg void OnStart3();
	afx_msg void OnStop3();
	afx_msg void OnStart4();
	afx_msg void OnStop4();

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
