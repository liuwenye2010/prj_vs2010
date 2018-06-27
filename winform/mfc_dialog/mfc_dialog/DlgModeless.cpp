// DlgModeless.cpp : implementation file
//

#include "stdafx.h"
#include "mfc_dialog.h"
#include "DlgModeless.h"
#include "afxdialogex.h"

extern CDlgModeless *g_dlgModeless; 
// CDlgModeless dialog

IMPLEMENT_DYNAMIC(CDlgModeless, CDialog)

CDlgModeless::CDlgModeless(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgModeless::IDD, pParent)
{

}

CDlgModeless::~CDlgModeless()
{
}

void CDlgModeless::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgModeless, CDialog)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDlgModeless message handlers


void CDlgModeless::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	CDialog::OnOK();
	DestroyWindow();// lwy: destory window , sendout WM_DESTORY Messsage 
}


void CDlgModeless::OnCancel()
{
	// TODO: Add your specialized code here and/or call the base class

	CDialog::OnCancel();
	DestroyWindow();// lwy: destory window , sendout WM_DESTORY Messsage 
}


void CDlgModeless::OnDestroy()
{
	CDialog::OnDestroy();

	// TODO: Add your message handler code here
	delete this ; //lwy :destory modeless dialog self 
	g_dlgModeless = NULL; // lwy : reset 
}
