// ScreenMonitor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ScreenMonitor.h"
#include "ImageGreper.h"
#include "ImageSelector.h"
#include "ImageSaver.h"

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
	ImageSaver imSa;

	std::set<ImageSelector*> imSeObservers;
	imSeObservers.insert(&imSe);
	imGr.Init(10, imSeObservers);

	std::set<ImageSaver*> imSaObservers;
	std::vector<cv::Rect> ROIs;
	std::vector<int> IDs;
	cv::Rect myROI(10, 10, 100, 100);
	ROIs.push_back(myROI);
	IDs.push_back(10);
	imSaObservers.insert(&imSa);
	imSe.Init(ROIs, IDs, 5, imSaObservers);

	imSa.Init("I:\\WorkShop\\Software_Dev\\SFToolsMFC\\");

	imGr.Start();
	imSe.Start();
	imSa.Start();
	
	//Sleep(5000);
	//imGr.EndThread();
	imGr.m_t->join();

	return nRetCode;
}
