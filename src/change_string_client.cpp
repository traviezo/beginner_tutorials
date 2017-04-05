/* Copyright 2017 Christian */

/**
 * This tutorial demonstrates writing a simple client sevice to call a service server.
 */
#include <ros/ros.h>
#include <std_srvs/Empty.h>
#include "std_msgs/String.h"

int main(int argc, char **argv) {
 /**
   * The ros::init() function needs to see argc and argv so that it can perform
   * any ROS arguments and name remapping that were provided at the command line.
   * For programmatic remappings you can use a different version of init() which takes
   * remappings directly, but for most command-line programs, passing argc and argv is
   * the easiest way to do it.  The third argument to init() is the name of the node.
   *
   * You must call one of the versions of ros::init() before using any other
   * part of the ROS system.
   */
  ros::init(argc, argv, "chgString_client_node");
  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the last
   * NodeHandle destructed will close down the node.
   */  
  ros::NodeHandle nh;
  /**
   * chgStringClient creates a client for the change_string service.
   * The ros::ServiceClient object is used to call the service later on. 
   */
  ros::ServiceClient chgStringClient = nh.serviceClient<std_srvs::Empty>("change_string");
  /**  
   * Service class contains two members, request and response.
   */
  std_srvs::Empty::Request req;
  
  std_srvs::Empty::Response resp;
  /**
   * Call the service. Since service calls are blocking, it will return once the call is done.
   * If call succeeds, call() will return true and the value in srv.response will be valid.
   * If the call does not succeed, call() will return false and the value in srv.response will be invalid. 
   */
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
