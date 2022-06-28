# TASK_2-MARS_CLUB

### 1. How does communication take place in ROS?

>Communication mostly takes place by ROS nodes with the help of ROS MASTER. First let me define what is a node.
>>**NODES** are basically executable files that uses ROS master to communicate with other nodes. ROS MASTER is nothing but a part of ROS that facilitates this communication between nodes.
>
>Now further going on, the ROS nodes use **messages** to communicate.
>
> **Messages** are simple text files containing data structures defined by user in which nodes can communicate.
>
>From here, to share information Nodes **_publish_** messages to a topic or topics and another node/nodes that wants to receive information will **_subscribe_** to those topic or topics. ROS master ensures that publisher and subscribers find each other easily.

### 2. What are the different types of node-to-node communication in ROS? Also state two applications of each type.

> 1. Topics
> 2. Services
> 3. Actions

#### TOPICS
>As I have discussed in the previous answer **Topics** implement a publish/subscribe communication mechanism, one of the most common ways to exchange data in ROS system. Basically ROS nodes publish messages to the topics and also subscribes messages from the topics. In this communication the rate for sending/receiving data is high.
![alt text](https://github.com/ec21b1006/TASK_2-MARS_CLUB/tree/main/reference_ss/topics.png)
In the above screenshot you can see teleop_key(node) is publishing to a topic named **_turtle1_** and the turtlesim is subscribing to the same topic. Also here we can see one more topic **_turtle2_** is present and it is subscribed by the turtlesim(node). That is why we can see two turtles in the simulation window.


