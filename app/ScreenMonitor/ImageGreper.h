#pragma once
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/thread.hpp>

#include <set>
class ImageSelector;
class ImageGreper
{
public:
	boost::thread * m_t;
	int m_iNumShot;
	int m_iDuration;
	std::set<ImageSelector*> m_obsevers;
public:
	ImageGreper();
	~ImageGreper();

	void GetImage(const int& numShot);
	
private:
	void Start();
	void ThreadMain();

	HRESULT SavePixelsToFile32bppPBGRA(UINT width, UINT height, UINT stride, LPBYTE pixels, LPWSTR filePath, const GUID &format);
	HRESULT Direct3D9TakeScreenshots(UINT adapter, UINT count);

	void UpdateObserver();
};

