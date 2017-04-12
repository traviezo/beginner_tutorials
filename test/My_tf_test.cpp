#include <ros/ros.h>
#include <ros/service_client.h>
#include <gtest/gtest.h>
#include <tf/transform_broadcaster.h>


TEST(TESTSuite, tfBroadcast) {
  tf::TransformBroadcaster tfBroadcaster;
  tf::Transform transform;
  transform.setOrigin(tf::Vector3(0.2,0.0,0.3));
  tf::Quaternion tfQuatrn;
  tfQuatrn.setRPY(0,0,1);
  transform.setRotation(tfQuatrn);
  EXPECT_EQ(tf::Vector3(0.2,0.0,0.3),transform.getOrigin());
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "tf_talker");
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
