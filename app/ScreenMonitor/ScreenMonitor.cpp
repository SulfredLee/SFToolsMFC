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
	ImageGreper imgGrp;
	ImageSelector imgSel;
	ImageSaver imgSav;
	ROISelector ROISel;

	imgGrp.m_observers_ROI.insert(&ROISel);
	imgGrp.Direct3D9TakeScreenshots(0, 1);
	imgGrp.m_observers_ROI.erase(&ROISel);
	ROISel.StartGetROI();

	std::set<ImageSelector*> imSeObservers;
	imSeObservers.insert(&imgSel);
	imgGrp.Init(1, imSeObservers);

	std::set<ImageSaver*> imSaObservers;
	imSaObservers.insert(&imgSav);
	double threshold = 50; // threshold is percentage
	imgSel.Init(ROISel.m_ROIs, ROISel.m_IDs, threshold, imSaObservers);

	imgSav.Init(".\\");

	imgGrp.Start();
	imgSel.Start();
	imgSav.Start();
	
	//Sleep(5000);
	//imGr.EndThread();
	imgGrp.m_t->join();

	return nRetCode;
}
