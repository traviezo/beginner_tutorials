# beginner_tutorials
ROS beginner tutorial

## Overview
The ROS package beginner_tutorials serves as a tutorial that shows how to write basic publisher and subscriber nodes. The package consists of 2 nodes: a talker and a listener node. The purpose of the talker node is to publish a string message to the network. The purpose of the subscriber node is to listen and receive the messages coming from the talker node. The beginner_tutorials also contains a CMakelist.txt and a package.xml files that provide the the building configuration of the package. There is also a results folder which contains the results obtained from the talker/listener and from the cppcheck and cpplint tools. 

## How to build and run beginner_tutorials
In order to build the beginner_tutorials ROS package do the following:

1. Move to directory containing your catking workspace:
   cd ~/catkin_ws 
2. Once inside catkin_ws build all packages inside workspace:
   catkin_make 

   After Build has completed successfully you can run the nodes as follows:

1. Open a terminal session by typing: 
   ctrl + alt + T 
2. Start Roscore by typing:
   roscore 
3. Open a second terminal session by typing:
   ctrl + alt + T 
4. Run the talker node by typing:
   rosrun beginner_tutorials talker 
5. Open a thrid terminal session by typing:
   ctrl + alt + T 
6. Run the listener node by typing:
   rosrun beginner_tutorials listener 

   Once both nodes are running you will be able to see the published messages in the second console screen as well as the received message in the third terminal.

## ROS service nodes 
The server service and client service nodes are ROS nodes that overwrite the messages being published by the talker node. The server node was implemented using and Empty call. The empty call takes no service arguments and only calls the callback function when the server service node is called. This node overwrites the talker node messages published in the chatter topic.

## How to build service nodes
It really is very similar as the steps used above for the beginner tutorials nodes talker and listener. The main difference in this case, is the use of a roslaunch file that will run all nodes at once when invoke.
As usual in order to build all nodes type catkin_make inside the catkin workspace.
After all nodes are built without errors, the run the roslaunch file as follows:
roslaunch beginner_tutorials beginner_tutorials.launch 

## How to inspect TF frames
In order to inspect tf frames you first need to run the node as follows: rosrun beginner_tutorials talker
Then you can use the command tf_echo as follows:  rosrun tf tf_echo /world /talk
You can also inspect the tf tree by making use of the rqt_tf_tree command:  rosrun rqt_tf_tree rqt_tf_tree

## How to run rostest
In order to run rostest you first need to build the tests as follows:  catkin_make tests
This command will compile the rostests in your package and created the respective executables. Then you can run the test as follows: rosrun beginner_tutorials tfTest
After running this node you shall see the tests results printed in the screen.

## Recording a rosbag file
In order to record topics in bag file you can do it either by running the rosbag file as a node as follows:
rosbag record -O alltopics.bag -a
Or you could mak it part of your ros launch file. Please see the tfTest launch file in the launch folder for further details on how to added to a lunch file.

## How to play a rosbag file
You need to type the ros command:
rosbag play alltopics.bag 


