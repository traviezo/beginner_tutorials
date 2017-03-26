# beginner_tutorials
ROS beginner tutorial

## Overview
The ROS package beginner_tutorials serves as a tutorial that shows how to write basic publisher and subscriber nodes. The package consists of 2 nodes: a talker and a listener node. The purpose of the talker node is to publish a string message to the network. The purpose of the subscriber node is to listen and receive the messages coming from the talker node. The beginner_tutorials also contains a CMakelist.txt and a package.xml files that provide the the building configuration of the package. There is also a results folder which contains the results obtained from the talker/listener and from the cppcheck and cpplint tools. 

## How to build and run beginner_tutorials
In order to build the beginner_tutorials ROS package do the following:
1. Move to directory containing your catking workspace:
   cd ~/catkin_ws <enter>
2. Once inside catkin_ws build all packages inside workspace:
   catkin_make <enter>
After Build has completed successfully you can run the nodes as follows:
1. Open a terminal session by typing:
   ctrl + alt + T <enter>
2. Start Roscore by typing:
   roscore <enter>
3. Open a second terminal session by typing:
   ctrl + alt + T <enter>
4. Run the talker node by typing:
   rosrun beginner_tutorials talker <enter>
5. Open a thrid terminal session by typing:
   ctrl + alt + T <enter>
6. Run the listener node by typing:
   rosrun beginner_tutorials listener <enter>
Once both nodes are running you will be able to see the published messages in the second console screen as well as the received message in the third terminal.
