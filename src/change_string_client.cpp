#include <ros/ros.h>
#include <std_srvs/Empty.h>
#include "std_msgs/String.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "chgString_client_node");
  
  ros::NodeHandle nh;

  ros::ServiceClient chgStringClient = nh.serviceClient<std_srvs::Empty>("change_string");
  
  std_srvs::Empty::Request req;
  
  std_srvs::Empty::Response resp;

  bool success = chgStringClient.call(req, resp);

  if(success)
  {
    ROS_INFO_STREAM("Client Service call succedded..!");
  }
  else
  {
    ROS_ERROR_STREAM("Failed to call change_string service..!!");
  }
}
