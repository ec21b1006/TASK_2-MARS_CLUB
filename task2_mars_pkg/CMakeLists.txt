cmake_minimum_required(VERSION 3.0.2)
project(task2_mars_pkg)
find_package(catkin REQUIRED COMPONENTS
  roscpp
  sensor_msgs
)
catkin_package()
include_directories(
  ${catkin_INCLUDE_DIRS}
)
add_executable(sensor_data src/sensor_data.cpp)
add_executable(stopping_sense src/stopping_sense.cpp)
add_executable(warning_signal src/warning_signal.cpp)
target_link_libraries(sensor_data ${catkin_LIBRARIES})
target_link_libraries(stopping_sense ${catkin_LIBRARIES})
target_link_libraries(warning_signal ${catkin_LIBRARIES})