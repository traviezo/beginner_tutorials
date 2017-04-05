#include <ros/ros.h>
#include <std_srvs/Empty.h>
#include "std_msgs/String.h"
#include <sstream>

bool replaceString(std_srvs::Empty::Request &req, std_srvs::Empty::Response &resp)
{
  ROS_INFO_STREAM("Modifying string...");
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "chgString_server_node");

  ros::NodeHandle nh;
  
  ros::ServiceServer server = nh.advertiseService("change_string", &replaceString);

  ros::Publisher serverPub = nh.advertise<std_msgs::String>("chatter", 1000);

  ros::Rate rate(10);

  while(ros::ok())
  {

    std_msgs::String msg;

    std::stringstream ss;

    ss<<"Hello ENPM808X 2017 class...!!!";

    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());

    serverPub.publish(msg);

    ros::spinOnce();

    rate.sleep();
  }
}
