//
// Created by SongZichen on 2019-05-13.
//
#pragma once
#ifndef __FACEALIGN_H__
#define __FACEALIGN_H__

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include "net.h"
#include <string>
#include <sstream>
#include <vector>
#include <time.h>
#include <algorithm>
#include <map>
#include <iostream>
#include <cmath>

using namespace std;
/*
??????points?
0,5 ?? 1,6 ??
2,7 ?? 3,8 ?? 4,9 ??
*/
class FaceAlign {

public:
	FaceAlign();
	~FaceAlign();
	pair<cv::Mat, string> align(cv::Mat& img, const vector<float>& landmarks, int desired_size = 160, float padding = 0.1);	// 返回对齐的图像和相对应的位置信息

private:
	string getPos(const vector<float>& points); // 用于判断是左脸右脸还是中间脸，points[0] points[1] points[2] 之间的差的比例代表左右
	vector<float> list2colmatrix(const vector<pair<float, float>>& pts_list); // 矩阵转换
	pair<cv::Mat, cv::Mat> find_tfrom_between_shapes(const vector<float>& from_shape, const vector<float>& to_shape);
};

#endif