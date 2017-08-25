#include "frame2frameVo/camera.h"

namespace VO
{

Vector3d Camera::world2camera( const Vector3d& p_w, const SE3& T_c_w )
{
  return T_c_w * p_w;
}

Vector3d Camera::camera2world( const Vector3d& p_c, const SE3& T_c_w )
{
  return T_c_w.inverse() * p_c;
}

Vector2d Camera::camera2pixel( const Vector3d& p_c )
{
  Vector2d p_p;
  p_p(0, 0) = fx_ * p_c(0, 0) / p_c(2, 0) + cx_ ;
  p_p(1, 0) = fy_ * p_c(1, 0) / p_c(2, 0) + cy_ ;
  return p_p;
}

Vector3d Camera::pixel2camera( const Vector2d& p_p, double depth )
{
  Vector3d p_c;
  p_c(0, 0) = ( p_p(0, 0) - cx_ ) / fx_ * depth;
  p_c(1, 0) = ( p_p(1, 0) - cy_ ) / fy_ * depth;
  p_c(2, 0) = depth;
  return p_c;
}

Vector3d Camera::pixel2world( const Vector2d& p_p, const SE3& T_c_w )
{
  return T_c_w.inverse() * pixel2camera( p_p );
}

Vector3d Camera::world2pixel( const Vector3d& p_w, const SE3& T_c_w )
{
  return camera2pixel( T_c_w * p_w );
}

}
