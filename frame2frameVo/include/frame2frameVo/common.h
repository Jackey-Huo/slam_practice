#ifndef COMMON_H_
#define COMMON_H_


#include <Eigen/Core>
#include <Eigen/Geometry>
using Eigen::Vector2d;
using Eigen::Vector3d;

#include <sophus/se3.h>
#include <sophus/so3.h>
using Sophus::SE3;
using Sophus::SO3;

#include <opencv2/core/core.hpp>
#include <opencv2/core/types.hpp>
using cv::Mat;

#include <vector>
#include <string>
#include <memory>
#include <iostream>







#endif // COMMON_H_

