cmake_minimum_required(VERSION 3.8)
project(oxts_ins VERSION 0.1.0)

# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2_kdl REQUIRED)
find_package(oxts_msgs REQUIRED)

add_executable(oxts_ins 
               src/conversions/convert.cpp 
               src/conversions/convert_node.cpp
               src/conversions/wrapper.cpp
               src/lib/NComRxC.c
               src/lib/nav_conversions.cpp
)

# Add component library for composition
add_library(oxts_ins_component SHARED
               src/oxts_ins_component.cpp
               src/conversions/convert.cpp
               src/conversions/wrapper.cpp
               src/lib/NComRxC.c
               src/lib/nav_conversions.cpp
)

ament_target_dependencies(oxts_ins 
                          rclcpp
                          std_msgs
                          sensor_msgs
                          geometry_msgs
                          nav_msgs
                          tf2
                          tf2_kdl
                          oxts_msgs)

ament_target_dependencies(oxts_ins_component
                          rclcpp
                          rclcpp_components
                          std_msgs
                          sensor_msgs
                          geometry_msgs
                          nav_msgs
                          tf2
                          tf2_kdl
                          oxts_msgs)

target_include_directories(oxts_ins PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

target_include_directories(oxts_ins_component PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

# Register component with pluginlib
rclcpp_components_register_nodes(oxts_ins_component "oxts_ins::OxtsInsComponent")
set(node_plugins "${node_plugins}oxts_ins::OxtsInsComponent;$<TARGET_FILE:oxts_ins_component>\n")

install(TARGETS oxts_ins
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY include/
  DESTINATION include)

install(TARGETS oxts_ins_component
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

install(DIRECTORY 
        config urdf rviz
        DESTINATION share/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
