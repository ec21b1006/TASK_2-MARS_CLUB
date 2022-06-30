#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <iostream>

void number_callback(const std_msgs::Int32::ConstPtr& msg2){
    if(msg2->data==-1)
    ROS_INFO("NO data received");
    else if(msg2->data==0)
    ROS_INFO("! ! ! WARNING ! ! !");
    else if(msg2->data==1)
    ROS_INFO("NO WARNING");
}

int main(int argc, char **argv){
    ros::init(argc, argv,"warning_signal");
    ros::NodeHandle node4_obj;
    ros::Subscriber warning_signal_subscriber= node4_obj.subscribe("/warning_signal", 10, number_callback);
    ros::spin();
    return 0;
}