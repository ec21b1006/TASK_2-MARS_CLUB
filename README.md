# TASK_2-MARS_CLUB

### Q1. How does communication take place in ROS?

>Communication mostly takes place by ROS nodes with the help of ROS MASTER. First let me define what is a node.
>>**NODES** are basically executable files that uses ROS master to communicate with other nodes. ROS MASTER is nothing but a part of ROS that facilitates this communication between nodes.
>
>Now further going on, the ROS nodes use **messages** to communicate.
>
> **Messages** are simple text files containing data structures defined by user in which nodes can communicate.
>
>From here, to share information Nodes **_publish_** messages to a topic or topics and another node/nodes that wants to receive information will **_subscribe_** to those topic or topics. ROS master ensures that publisher and subscribers find each other easily.

### Q2. What are the different types of node-to-node communication in ROS? Also state two applications of each type.

> 1. Topics
> 2. Services
> 3. Actions

#### TOPICS
>As I have discussed in the previous answer **Topics** implement a publish/subscribe communication mechanism, one of the most common ways to exchange data in ROS system. Basically ROS nodes publish messages to the topics and also subscribes messages from the topics. In this communication the rate for sending/receiving data is high.
>
![alt text](https://github.com/ec21b1006/screenshots/blob/main/topics.png)
>
>In the above screenshot you can see teleop_key(node) is publishing to a topic named **_turtle1_** and the turtlesim is subscribing to the same topic. Also here we can see one more topic **_turtle2_** is present and it is subscribed by the turtlesim(node). That is why we can see two turtles in the simulation window.
>
##### APPLICATIONS
* Turtlesim
* Voting system

#### Services
>It has **_ROS Server_** that provides the service and **_ROS Client_** that consumes the service. Unlike topics, service is one-time communication in which a client sends a **request**, then the server sends back a **response**.
>
![alt text](https://github.com/ec21b1006/screenshots/blob/main/services.png)
>
>Here you can see in the screenshot. I spawned a second turtle by the name _"turtle2"_ using a rosservice _/spawn_ .
>
##### APPLICATIONS
* Spawning a simulation
* Finding a distance between point A to point B


#### Actions
>An action is an asynchronous call to another node’s functionality. “Asynchronous” means you don’t have to wait for the result. You can do other things pending the result.
>
>The node that provides the functionality has to implement an **_Action Server_** {Dosa shop(see the last example)}. The node that uses the functionality has to use an **_Action Client_** {online ordering system(see the last example)}.
>
![alt text](https://www.theconstructsim.com/wp-content/uploads/2017/12/ros_action.png)
>
>Here you can see Actions provides more features than a services does. For example- goal, cancel, status, result, feedback.
>
##### APPLICATIONS 
* moving a simulation to a certain angle/parameter
* counting system with a limit

#####  Now to understand more about services and actions we will take an example of buying dosa

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

Option 1(Going to Dosa shop) is similar to a ROS Service, while option 2 is similar to a ROS Action.

### Q3. In the above question, you have mentioned applications of the different types of node-to-node communication. For each application, propose a possible ROS architecture (graphically / pictorially) that could be used to implement it. (For your reference, the ROS architecture for communication between two nodes is provided)

> REFER to my screenshots(reference_ss);

### Q4. Is there a way to see or generate this architecture of node communication in ROS using a utility or software? If yes, mention it.

> Yes, after executing commands for both of the nodes you can tyoe **rqt_graph** in the terminal to see this same architecture.

### Q5. What are the different sensors and actuators involved in each subsystem of a typical rover?

>**MOBILITY**
* In rovers mostly there are 6 motors that turn the wheels, so the rover can move forward or backwards, and the 4 motors that turn the outer wheels around their axes, so the rover is maneuverable.
* They also have a gear box on each motor with a fixed, very high ratio(a few thousand) for low speed and very high torque.
* The current to each motor is independently controlled and monitored.
* Also in motors, Brushed motors are good to go as brushless motors require permanent magnets whereas brushed motors can use electromagnets both for stator and rotor, also electromagnets are quite invulnerable against mechanical shock.

>**POWER**
* For power rover can rely on mainly two things- power installed in them and multi-panel solar array.
* Power installed in them- This can be in the form of some batteries or better option is radioactive isotope that generates electricity from the heat of radioactive decay.
* Multi-panel solar array- It converts the solar power into the electrical power that gets stored in a battery that can be used by the rover.

>**NAVIGATION & COMMUNICATION**
* A number of cameras having different optics for some specific task are installed in a rover for navigationing along with these some science investigation cameras also get added.
* Antennas for signal transferring also play an important role in the navigation subsystem.
* Talking about antennas rovers have low-gain(can send and receive info in every direction) and high-gain antennas(can send beam of info in specific direction).

>**ROBOTIC ARM & TEMPERATURE SENSOR**
* TORQUE sensors to know that how much force it is applying on the object to lift or examine.
* CAMERA(microscopic imager) sensors on top of the manipulator which gives a visual feedback to researchers for further investigation.
* Spectrometers are also installed to analyze the elemental composition of rocks and soil.
* An abrasion tool that grinds away the outer surface of to expose fresh material.
* Temperature sensors are required so that the components inside the rover can't get damaged.

### Q6. Consider that there is a bot in front of a wall with a distance/proximity sensor mounted on it. This bot should stop moving once it reaches a certain distance from the wall. Design a ROS node communication system of three nodes to achieve this. (It is not needed to prepare a robot simulation, only basic node communication is required.)
### The 1st node contains the sensor i.e., it should generate the sensor data (current distance from the wall).
### The 2nd node obtains the sensor data from the 1st node and decides when the bot should stop moving. It also sends a warning signal to the 3rd node.
### The 3rd node waits for a warning from the 2nd node and prints out the warning on the terminal, once received.
>
[!alt text](https://github.com/ec21b1006/screenshots/blob/main/Q6_rqt_graph.png)
>
>I have uploaded the PACKAGE for this question in this same repositery.

