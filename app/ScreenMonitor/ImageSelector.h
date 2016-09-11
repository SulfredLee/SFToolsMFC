#pragma once
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/lockfree/queue.hpp>


#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>

#include <vector>

#include "FullImage.h"
class ImageSelector
{
public:
	std::vector<cv::Rect> m_ROIs;
	std::vector<int> m_imageCode;	
	boost::lockfree::queue<boost::shared_ptr<FullImage> > m_imageQ;
public:
	ImageSelector();
	~ImageSelector();

	void Init();

	void ImgSelector_Dataline(boost::shared_ptr<FullImage> ptr);
};

