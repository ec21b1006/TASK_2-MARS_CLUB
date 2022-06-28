# TASK_2-MARS_CLUB

## 1.How does communication take place in ROS?
---
>Communication mostly takes place by ROS nodes with the help of ROS MASTER. First let me define what is a node.
>>**NODES** are basically executable files that uses ROS master to communicate with other nodes. ROS MASTER is nothing but a part of ROS that facilitates this communication between nodes.
>Now further going on, the ROS nodes use **messages** to communicate.
>>**Messages** are simple text files containing data structures defined by user in which nodes can communicate.
>From here, to share information Nodes **_publish-** messages to a topic or topics and another node/nodes that wants to receive information will **_subscribe_** to those topic or topics.