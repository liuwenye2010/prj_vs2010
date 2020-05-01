
// mfc_gui_dialog.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Cmfc_gui_dialogApp:
// See mfc_gui_dialog.cpp for the implementation of this class
//

class Cmfc_gui_dialogApp : public CWinApp
{
public:
	Cmfc_gui_dialogApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern Cmfc_gui_dialogApp theApp;