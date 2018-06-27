#pragma once


// CDlgModeless dialog

class CDlgModeless : public CDialog
{
	DECLARE_DYNAMIC(CDlgModeless)

public:
	CDlgModeless(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgModeless();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	virtual void OnOK();
	virtual void OnCancel();
public:
	afx_msg void OnDestroy();
};
