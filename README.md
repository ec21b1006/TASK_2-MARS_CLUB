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
>
![alt text](https://github.com/ec21b1006/TASK_2-MARS_CLUB/tree/main/reference_ss/topics.png)
>
>In the above screenshot you can see teleop_key(node) is publishing to a topic named **_turtle1_** and the turtlesim is subscribing to the same topic. Also here we can see one more topic **_turtle2_** is present and it is subscribed by the turtlesim(node). That is why we can see two turtles in the simulation window.

#### Services
>It has **_ROS Server_** that provides the service and **_ROS Client_** that consumes the service. Unlike topics, service is one-time communication in which a client sends a **request**, then the server sends back a **response**.
>
![alt text](https://github.com/ec21b1006/TASK_2-MARS_CLUB/tree/main/reference_ss/services.png)
>
>Here you can see in the screenshot. I spawned a second turtle by the name _"turtle2"_ using a rosservice _/spawn_ .

#### Actions
>An action is an asynchronous call to another node’s functionality. “Asynchronous” means you don’t have to wait for the result. You can do other things pending the result.
>
>The node that provides the functionality has to implement an **_Action Server_** {Dosa shop(see the last example)}. The node that uses the functionality has to use an **_Action Client_** {online ordering system(see the last example)}.


>Now to understand more about services and actions we will take an example of buying dosa

1. Go the Dosa shop
    1. Place your order(**request**).
    2. _Wait for the order._
    3. Get the Dosa(**response**).
2. Order online
    1. Place your order(**request**).
    2. Order confirmation notice(**feedback**).
    3. Possibly cancel the order(**cancel**).
    4. Check up your order status once in a while(**status**).
    5. _Do other things._
    6. Dosa is delivered(**response**).

>Option 1(Going to Dosa shop) is similar to a ROS Service, while option 2 is similar to a ROS Action.