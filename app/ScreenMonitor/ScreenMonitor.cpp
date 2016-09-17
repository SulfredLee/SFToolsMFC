// ScreenMonitor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ScreenMonitor.h"
#include "ImageGreper.h"
#include "ImageSelector.h"

#include <vector>
#include <set>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// The one and only application object

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;
	ImageGreper imGr;
	ImageSelector imSe;

	std::set<ImageSelector*> imSeObservers;
	imSeObservers.insert(&imSe);

	imGr.Init(1, imSeObservers);

	std::vector<cv::Rect> ROIs;
	std::vector<int> IDs;
	cv::Rect myROI(10, 10, 100, 100);
	ROIs.push_back(myROI);
	IDs.push_back(10);
	imSe.Init(ROIs, IDs, 5);

	imGr.Start();
	imSe.Start();
	
	//Sleep(5000);
	//imGr.EndThread();
	imGr.m_t->join();

	return nRetCode;
}
