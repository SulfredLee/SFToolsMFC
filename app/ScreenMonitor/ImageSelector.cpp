#include "stdafx.h"
#include "ImageSelector.h"


ImageSelector::ImageSelector()
{
}


ImageSelector::~ImageSelector()
{
}

void ImageSelector::Init()
{

}

void ImageSelector::ImgSelector_Dataline(boost::shared_ptr<FullImage> ptr)
{
	m_imageQ.push(ptr);
}