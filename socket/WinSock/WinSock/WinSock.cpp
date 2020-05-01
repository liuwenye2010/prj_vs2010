// WinSock.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#if 0 
int _tmain(int argc, _TCHAR* argv[])
{
	
	return 0;
}
#else 


#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>

// Need to link with Ws2_32.lib
#pragma comment(lib, "ws2_32.lib")


int __cdecl main()
{

    WORD wVersionRequested;
    WSADATA wsaData;
    int err;

/* Use the MAKEWORD(lowbyte, highbyte) macro declared in Windef.h */
    wVersionRequested = MAKEWORD(2, 2);

    err = WSAStartup(wVersionRequested, &wsaData);
    if (err != 0) {
        /* Tell the user that we could not find a usable */
        /* Winsock DLL.                                  */
        printf("WSAStartup failed with error: %d\n", err);
        return 1;
    }

/* Confirm that the WinSock DLL supports 2.2.*/
/* Note that if the DLL supports versions greater    */
/* than 2.2 in addition to 2.2, it will still return */
/* 2.2 in wVersion since that is the version we      */
/* requested.                                        */

    if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2) {
        /* Tell the user that we could not find a usable */
        /* WinSock DLL.                                  */
        printf("Could not find a usable version of Winsock.dll\n");
        WSACleanup();
        return 1;
    }
    else
        printf("The Winsock 2.2 dll was found okay\n");
        

/* The Winsock DLL is acceptable. Proceed to use it. */

/* Add network programming using Winsock here */

/* then call WSACleanup when done using the Winsock dll */





#if 1

  char szHost[256];  
  gethostname(szHost,256); 
  fprintf(stdout,"\t gehostname: %s\n",szHost); 
  hostent *pHost=gethostbyname(szHost);  
  in_addr addr;  
         
  char *p=pHost->h_addr_list[0];  
  memcpy(&addr.S_un.S_addr,p,pHost->h_length);  
  char *szIp=inet_ntoa(addr);  
  fprintf(stdout,"\t  %s\n",szIp); 


#endif 









    
    WSACleanup();

}




#endif 
