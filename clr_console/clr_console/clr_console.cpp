// clr_console.cpp : main project file.

#include "stdafx.h"
#include <stdio.h>  
#include <stdarg.h>


int my_printf( const char *format, ... ); 
using namespace System;

int main(array<System::String ^> ^args)
{
    //Console::WriteLine(L"Hello World");
    //return 0;


	int a = 0 ; 
	int b = 1 ; 
	my_printf("the value is %d, %d \r\n",a, b); 
	printf("the value is %d, %d \r\n",a, b); 
	getchar(); 

}


int my_printf( const char *format, ... )
{
  va_list ap;
  int str_l;
  va_start(ap, format);
  str_l =vprintf(format, ap); //  call vprintf() instead of printf() using the variable arguments "varargs" capabilities of C.
  va_end(ap);
  return str_l;
}