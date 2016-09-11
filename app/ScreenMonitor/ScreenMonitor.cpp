// ScreenMonitor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ScreenMonitor.h"
#include "ImageGreper.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// The one and only application object

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;
	ImageGreper im;
	im.Init(1);
	im.Start();
	
	Sleep(5000);
	im.EndThread();
	im.m_t->join();

	return nRetCode;
}
