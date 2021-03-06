#include "ros/ros.h"
#include "sensor_msgs/Range.h"
#include "std_msgs/Int32.h"
#include <iostream>

sensor_msgs::Range msg1;

void number_callback(const sensor_msgs::Range::ConstPtr& msg0){
    ROS_INFO("The robot is %lf away from the wall", msg0->range);
    msg1.range = msg0->range;
}

int main(int argc, char **argv){
    ros::init(argc, argv,"stopping_sense");
    ros::NodeHandle node2_obj;
    ros::Subscriber stopping_sense_subscriber= node2_obj.subscribe("/sensor_data", 10, number_callback);
    ros::Publisher warning_signal_publisher = node2_obj.advertise<std_msgs::Int32>("/warning_signal", 1);
    ros::Rate loop_rate(5);
    std_msgs::Int32 msg2;
    while(ros::ok()){
        if(msg1.range >= 5) // I put the limit as 5 meaning if the sensor detects our robot is less 5 units away from the wall it will publish signal which will decide if it should give warning signal or no warning
        msg2.data=1;
        else if(msg1.range < 5 && msg1.range > 0)
        msg2.data=0;
        else if(msg1.range == -1)
        msg2.data=-1;
        warning_signal_publisher.publish(msg2);
        msg1.range = -1;
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}