
// mfc_dialogDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mfc_dialog.h"
#include "mfc_dialogDlg.h"
#include "afxdialogex.h"
#include "DlgModeless.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CDlgModeless *g_dlgModeless= NULL ; // define global modeless dialog pointer 
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// Cmfc_dialogDlg dialog




Cmfc_dialogDlg::Cmfc_dialogDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cmfc_dialogDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cmfc_dialogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_btn1);
	DDX_Control(pDX, IDC_BUTTON2, m_btn2);
}

BEGIN_MESSAGE_MAP(Cmfc_dialogDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &Cmfc_dialogDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Cmfc_dialogDlg::OnBnClickedButton2)
	ON_WM_CREATE()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON3, &Cmfc_dialogDlg::OnBnClickedButton3_SendUserMessage)
	ON_MESSAGE(WM_MYMSG01,OnMyMsg)  //lwy: user message map 
	ON_BN_CLICKED(IDC_BUTTON4, &Cmfc_dialogDlg::OnBnClickedButton4_ShowModelessDialog)
END_MESSAGE_MAP()


// Cmfc_dialogDlg message handlers

BOOL Cmfc_dialogDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

void Cmfc_dialogDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void Cmfc_dialogDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR Cmfc_dialogDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cmfc_dialogDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
    PostQuitMessage(0);// exit out the program
}


void Cmfc_dialogDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	MessageBox(_T("Weather Good!"),_T("reminder"),MB_OK); // using SDK api
	AfxMessageBox(IDS_MYSTR0);//using MFC api 

	CString str; 
	CTime t = CTime::GetCurrentTime();
	CString str1 = t.Format(_T("%Y%m%d"));
	CString str2 = t.Format(_T("%H%M%S"));
	AfxFormatString2(str,IDS_MYSTR0,str1,str2);
	AfxMessageBox(str);//using MFC api 
}


int Cmfc_dialogDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here

	return 0;
}


void Cmfc_dialogDlg::OnClose()
{
	// TODO: Add your message handler code here and/or call default

	CDialogEx::OnClose();
}


void CAboutDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: Add your message handler code here
	MessageBox(_T("Window thread destory"),_T("Window thread destory"),MB_OK); 
}

//lwy: user define msg hanlder function 
LRESULT Cmfc_dialogDlg::OnMyMsg(WPARAM wParam, LPARAM lParam)
{
	 AfxMessageBox((CString)(char*)wParam);
	 return 0; 
}

void Cmfc_dialogDlg::OnBnClickedButton3_SendUserMessage()
{
	// TODO: Add your control notification handler code here
	char  szText[]= "Visual C++ 2010 Message"; 
	SendMessage(WM_MYMSG01,(UINT)szText,0); 
}


void Cmfc_dialogDlg::OnBnClickedButton4_ShowModelessDialog()
{
	// TODO: Add your control notification handler code here
	if(g_dlgModeless == NULL)
	{
		g_dlgModeless = new CDlgModeless; 
		g_dlgModeless->Create(CDlgModeless::IDD,this);// create modeless dialog 
	}
	g_dlgModeless->ShowWindow(SW_SHOW); //show modeless dialog 
	g_dlgModeless->SetActiveWindow();
}
