






#if 0 
#include <windows.h>
#include <stdio.h>

//https://docs.microsoft.com/en-us/windows/desktop/Sync/using-waitable-timer-objects

int main()
{
    HANDLE hTimer = NULL;
    LARGE_INTEGER liDueTime;

    liDueTime.QuadPart = -100000000LL;

    // Create an unnamed waitable timer.
    hTimer = CreateWaitableTimer(NULL, TRUE, NULL);
    if (NULL == hTimer)
    {
        printf("CreateWaitableTimer failed (%d)\n", GetLastError());
        return 1;
    }

    printf("Waiting for 10 seconds...\n");

    // Set a timer to wait for 10 seconds.
    if (!SetWaitableTimer(hTimer, &liDueTime, 0, NULL, NULL, 0))
    {
        printf("SetWaitableTimer failed (%d)\n", GetLastError());
        return 2;
    }

    // Wait for the timer.

    if (WaitForSingleObject(hTimer, INFINITE) != WAIT_OBJECT_0)
        printf("WaitForSingleObject failed (%d)\n", GetLastError());
    else printf("Timer was signaled.\n");

    return 0;
}


#else 

#pragma comment(lib,"user32")
#include <stdio.h>
#include <time.h>
#include <sys/timeb.h>
#include <windows.h>
#include <stdint.h> 
char datestr[16];
char timestr[16];
char mss[4];


void log(char *s) {
    struct tm *now;
    struct timeb tb;
 
    ftime(&tb);
    now=localtime(&tb.time);
    sprintf(datestr,"%04d-%02d-%02d",now->tm_year+1900,now->tm_mon+1,now->tm_mday);
    sprintf(timestr,"%02d:%02d:%02d",now->tm_hour     ,now->tm_min  ,now->tm_sec );
    sprintf(mss,"%03d",tb.millitm);
    printf("%s %s.%s %s",datestr,timestr,mss,s);
}


VOID CALLBACK myTimerProc1(
  HWND hwnd, // handle of window for timer messages
  UINT uMsg, // WM_TIMER message
  UINT idEvent, // timer identifier
  DWORD dwTime // current system time
) {
 log("In myTimerProc1\n");
}


VOID CALLBACK myTimerProc2(
  HWND hwnd, // handle of window for timer messages
  UINT uMsg, // WM_TIMER message
  UINT idEvent, // timer identifier
  DWORD dwTime // current system time
) {
 log("In myTimerProc2\n");
}


void test_time_elapse(uint32_t ms_delay) ; 
int main() {
    int i;
    MSG msg;
 
	test_time_elapse(100); 


    SetTimer(NULL,0,1000,myTimerProc1);
    SetTimer(NULL,0,2000,myTimerProc2);
    for (i=0;i<20;i++) {
        Sleep(500);
        log("In main message loop !! \n");
        if (GetMessage(&msg,NULL,0,0)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
 
    }
    return 0;
}

#endif 

//1. SetTimer - 多种用法, 需要窗口
//2. SetWaitableTimer - 多种用法, 内核对象
//3. CreateTimerQueueTimer - 内核对象+线程池(稍显复杂)
//4. Task Scheduler - Windows 定期管理服务 (services可能会被禁用) 



class CTimeoutTimer
{
  public:
    CTimeoutTimer(DWORD dwTimeOut /*ms*/) : m_dwTimeOutValue(dwTimeOut),
                                            m_dwStartTime(0)
    {
    }

    // Specifies the timer out value.
    void SetTimeOutValue(DWORD dwTimeOut /*ms*/)
    {
        m_dwTimeOutValue = dwTimeOut;
    }

    // Resets the elapsed time.
    void Reset()
    {
        m_dwStartTime = timeGetTime();
    }

    // Return TRUE if time is up.
    BOOL IsTimeOut() const
    {
        BOOL bTimeOut = FALSE;
        DWORD dwCurTime = timeGetTime();
        if ((dwCurTime - m_dwStartTime) > m_dwTimeOutValue)
        {
            bTimeOut = TRUE;
        }
        return bTimeOut;
    }

    // Return delta time.
    DWORD GetDeltaTime() const
    {
        return timeGetTime() - m_dwStartTime;
    }

  private:
    CTimeoutTimer();
    ULONG m_dwTimeOutValue;
    ULONG m_dwStartTime;
};


void test_time_elapse(uint32_t ms_delay) 
{
	  CTimeoutTimer ttimer(0);
		uint32_t download_interval;
		ttimer.Reset();

		Sleep(ms_delay);

	 printf( "\nTotal time  : %d ms \n", download_interval);
}	