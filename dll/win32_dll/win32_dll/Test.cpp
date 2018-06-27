#include "Test.h" 
#include "windows.h" //using MessageBox 
#include  "tchar.h"  //using  _T

void f(void) 
{
	MessageBox(0,_T("f()is come form Test.DLL "),0,0); 
}
