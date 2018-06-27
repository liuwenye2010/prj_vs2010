
// mfc_dialogDlg.h : header file
//

#pragma once
#include "afxwin.h"

#define  WM_MYMSG01  WM_USER+101 // lwy: define an user message 


// Cmfc_dialogDlg dialog
class Cmfc_dialogDlg : public CDialogEx
{
// Construction
public:
	Cmfc_dialogDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MFC_DIALOG_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg LRESULT OnMyMsg(WPARAM wParam, LPARAM lParam); //lwy: user define msg hanlder function 
	
	DECLARE_MESSAGE_MAP()
public:
	// user added button 1 lwy
	CButton m_btn1;
	afx_msg void OnBnClickedButton1();
	// //add button variable 
	CButton m_btn2;
	afx_msg void OnBnClickedButton2();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnClose();
	afx_msg void OnBnClickedButton3_SendUserMessage();
	afx_msg void OnBnClickedButton4_ShowModelessDialog();
};
