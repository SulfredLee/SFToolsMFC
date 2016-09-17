#pragma once
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>

#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>

#include <set>

#include "myThread.h"
#include "FullImage.h"
class ImageSelector;
class ImageGreper :
	public myThread
{
public:
	std::set<ImageSelector*> m_obsevers;
private:
	int m_iNumShot;
	int m_iDuration;
public:
	ImageGreper();
	~ImageGreper();

	void Init(const int& numShot,
		const std::set<ImageSelector*>& observers);

	//Override
	void ThreadMain();
private:
	HRESULT SavePixelsToFile32bppPBGRA(UINT width, UINT height, UINT stride, LPBYTE pixels, LPWSTR filePath, const GUID &format);
	HRESULT Direct3D9TakeScreenshots(UINT adapter, UINT count);
	void ConvertImage(const UINT& width, const UINT& height, const UINT& stride, const LPBYTE& pixels, const std::string& timeStamp);

	void UpdateObserver(boost::shared_ptr<FullImage> ptr);
};

