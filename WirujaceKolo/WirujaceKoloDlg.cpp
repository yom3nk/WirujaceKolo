
// WirujaceKoloDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "WirujaceKolo.h"
#include "WirujaceKoloDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CWirujaceKoloDlg dialog

CWirujaceKoloDlg::CWirujaceKoloDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_WIRUJACEKOLO_DIALOG, pParent),
	m_circle1(CPoint(100, 100), 50, RGB(255, 0, 0)),
	m_circle2(CPoint(300, 100), 50, RGB(0, 255, 0)),
	m_circle3(CPoint(100, 300), 50, RGB(0, 0, 255)),
	m_circle4(CPoint(300, 300), 50, RGB(255, 255, 0))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWirujaceKoloDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CWirujaceKoloDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()

	ON_BN_CLICKED(IDC_START1, &CWirujaceKoloDlg::OnStart1)
	ON_BN_CLICKED(IDC_STOP1, &CWirujaceKoloDlg::OnStop1)
	ON_BN_CLICKED(IDC_START2, &CWirujaceKoloDlg::OnStart2)
	ON_BN_CLICKED(IDC_STOP2, &CWirujaceKoloDlg::OnStop2)
	ON_BN_CLICKED(IDC_START3, &CWirujaceKoloDlg::OnStart3)
	ON_BN_CLICKED(IDC_STOP3, &CWirujaceKoloDlg::OnStop3)
	ON_BN_CLICKED(IDC_START4, &CWirujaceKoloDlg::OnStart4)
	ON_BN_CLICKED(IDC_STOP4, &CWirujaceKoloDlg::OnStop4)

	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CWirujaceKoloDlg message handlers

BOOL CWirujaceKoloDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	SetWindowText(_T("Wiruj¹ce Ko³o - Oktawian £oboda 26133"));

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);	
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CWirujaceKoloDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CWirujaceKoloDlg::OnPaint()
{
	CClientDC dc(this); 

	m_circle1.Update();
	m_circle1.Draw(&dc);

	m_circle2.Update();
	m_circle2.Draw(&dc);

	m_circle3.Update();
	m_circle3.Draw(&dc);

	m_circle4.Update();
	m_circle4.Draw(&dc);
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CWirujaceKoloDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CWirujaceKoloDlg::OnStart1() { m_circle1.Start(); }
void CWirujaceKoloDlg::OnStop1() { m_circle1.Stop(); }
void CWirujaceKoloDlg::OnStart2() { m_circle2.Start(); }
void CWirujaceKoloDlg::OnStop2() { m_circle2.Stop(); }
void CWirujaceKoloDlg::OnStart3() { m_circle3.Start(); }
void CWirujaceKoloDlg::OnStop3() { m_circle3.Stop(); }
void CWirujaceKoloDlg::OnStart4() { m_circle4.Start(); }
void CWirujaceKoloDlg::OnStop4() { m_circle4.Stop(); }