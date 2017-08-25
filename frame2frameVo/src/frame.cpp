#include "frame2frameVo/frame.h"

namespace VO
{

Frame::Frame() :
  id_(-1), time_stamp_(-1), camera_(nullptr)
{

}

Frame::Frame( long id, double time_stamp, SE3 T_c_w, Camera::Ptr camera, Mat color, Mat depth ) :
  id_(id), time_stamp_(time_stamp), T_c_w_(T_c_w), camera_(camera), color_(color), depth_(depth)
{

}

Frame::Ptr createFrame()
{
  static long id = 0;
  return std::shared_ptr<Frame>( new Frame( id++ ) );
}

double Frame::findDepth( const cv::KeyPoint& kp )
{
  int x = cvRound( kp.pt.x );
  int y = cvRound( kp.pt.y );
  unsigned short d = depth_.ptr<unsigned short>(y)[x];
  if ( d != 0 )
  {
    return double(d) / camera_->depth_scale_;
  }
  else
  {
    int dx[4] = {-1,  0, 1, 0};
    int dy[4] = { 0, -1, 0, 1};
    for( int i = 0; i < 4; ++i )
    {
      d = depth_.ptr<unsigned short>(y+dy[i])[x+dx[i]];
      if ( d != 0 )
      {
        return double(d) / camera_->depth_scale_;
      }
    }
  }
  return -1.0;
}


}
