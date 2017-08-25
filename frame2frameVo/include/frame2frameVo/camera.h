#ifndef CAMERA_H_
#define CAMERA_H_

#include "frame2frameVo/common.h"

namespace VO
{

class Camera
{
public:
  typedef std::shared_ptr<Camera> Ptr;

  Camera() {  }

  Camera( double fx, double fy, double cx, double cy, double depth_scale ) :
    fx_(fx), fy_(fy), cx_(cx), cy_(cy), depth_scale_(depth_scale)
  {  }


public:
  double fx_, fy_, cx_, cy_, depth_scale_;  // camera intrinsic paramter

  Vector3d world2camera( const Vector3d& p_w, const SE3& T_c_w );
  Vector3d camera2world( const Vector3d& p_c, const SE3& T_c_w );
  Vector2d camera2pixel( const Vector3d& p_c );
  Vector3d pixel2camera( const Vector2d& p_p, double depth=1 );
  Vector3d pixel2world ( const Vector2d& p_p, const SE3& T_c_w );
  Vector3d world2pixel ( const Vector3d& p_w, const SE3& T_c_w );


};

}




















#endif
