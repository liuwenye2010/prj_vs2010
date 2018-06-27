
// mfc_apiView.h : interface of the Cmfc_apiView class
//

#pragma once


class Cmfc_apiView : public CView
{
protected: // create from serialization only
	Cmfc_apiView();
	DECLARE_DYNCREATE(Cmfc_apiView)

// Attributes
public:
	Cmfc_apiDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~Cmfc_apiView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in mfc_apiView.cpp
inline Cmfc_apiDoc* Cmfc_apiView::GetDocument() const
   { return reinterpret_cast<Cmfc_apiDoc*>(m_pDocument); }
#endif

