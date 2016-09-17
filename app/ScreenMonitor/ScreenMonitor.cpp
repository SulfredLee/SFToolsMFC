// ScreenMonitor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ScreenMonitor.h"
#include "ImageGreper.h"
#include "ImageSelector.h"
#include "ImageSaver.h"
#include "ROISelector.h"

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
	ROISelector ROISel;

	imGr.m_observers_ROI.insert(&ROISel);
	imGr.Direct3D9TakeScreenshots(0, 1);
	imGr.m_observers_ROI.erase(&ROISel);
	ROISel.StartGetROI();

	std::set<ImageSelector*> imSeObservers;
	imSeObservers.insert(&imSe);
	imGr.Init(10, imSeObservers);

	std::set<ImageSaver*> imSaObservers;
	imSaObservers.insert(&imSa);
	imSe.Init(ROISel.m_ROIs, ROISel.m_IDs, 5, imSaObservers);

	imSa.Init("I:\\WorkShop\\Software_Dev\\SFToolsMFC\\");

	imGr.Start();
	imSe.Start();
	imSa.Start();
	
	//Sleep(5000);
	//imGr.EndThread();
	imGr.m_t->join();

	return nRetCode;
}
