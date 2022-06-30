#include "ros/ros.h"
#include "sensor_msgs/Range.h"
#include <iostream>
int main(int argc, char **argv){
    ros::init(argc, argv, "sensor_data");
    ros::NodeHandle node_obj;
    ros::Publisher sensor_data_publisher = node_obj.advertise<sensor_msgs::Range>("/sensor_data", 10); // "/numbers" is the topic name
    ros::Rate loop_rate(5);
    srand(time(0));
    while( ros::ok()){
        sensor_msgs::Range msg;
        msg.range = (double(rand())/double(RAND_MAX))*(20);
        ROS_INFO("The sensor gives distance = %lf", msg.range);
        sensor_data_publisher.publish(msg);
        loop_rate.sleep();
    }
    return 0;
}