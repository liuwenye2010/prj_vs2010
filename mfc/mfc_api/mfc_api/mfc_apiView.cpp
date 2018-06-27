
// mfc_apiView.cpp : implementation of the Cmfc_apiView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "mfc_api.h"
#endif

#include "mfc_apiDoc.h"
#include "mfc_apiView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cmfc_apiView

IMPLEMENT_DYNCREATE(Cmfc_apiView, CView)

BEGIN_MESSAGE_MAP(Cmfc_apiView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cmfc_apiView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Cmfc_apiView construction/destruction

Cmfc_apiView::Cmfc_apiView()
{
	// TODO: add construction code here

}

Cmfc_apiView::~Cmfc_apiView()
{
}

BOOL Cmfc_apiView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Cmfc_apiView drawing

void Cmfc_apiView::OnDraw(CDC* /*pDC*/)
{
	Cmfc_apiDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// Cmfc_apiView printing


void Cmfc_apiView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cmfc_apiView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void Cmfc_apiView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void Cmfc_apiView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void Cmfc_apiView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cmfc_apiView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cmfc_apiView diagnostics

#ifdef _DEBUG
void Cmfc_apiView::AssertValid() const
{
	CView::AssertValid();
}

void Cmfc_apiView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cmfc_apiDoc* Cmfc_apiView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cmfc_apiDoc)));
	return (Cmfc_apiDoc*)m_pDocument;
}
#endif //_DEBUG


// Cmfc_apiView message handlers
