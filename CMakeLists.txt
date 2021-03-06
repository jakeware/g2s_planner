cmake_minimum_required(VERSION 2.8.3)

# Configure CCache if available
find_program(CCACHE_FOUND ccache)
if (CCACHE_FOUND)
  set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
  set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache)
endif (CCACHE_FOUND)

project(g2s_planner)

set(CMAKE_VERBOSE_MAKEFILE FALSE)

add_definitions("-std=c++11")
if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif (NOT CMAKE_BUILD_TYPE)

# find catkin dependencies
set(REQ_CATKIN_PKGS
  roscpp
  nodelet
  fla_utils
  tf2_ros
)
find_package(catkin REQUIRED COMPONENTS ${REQ_CATKIN_PKGS})

# find system dependencies
find_package(PCL 1.7 REQUIRED COMPONENTS common)
find_package(Eigen3 3.2 EXACT REQUIRED)
find_package(Boost 1.54 REQUIRED)

# add_message_files(...)
# add_service_files(...)
# add_action_files(...)
# generate_messages(...)

# setup downstream dependencies
catkin_package(
 INCLUDE_DIRS src
 LIBRARIES ${PROJECT_NAME}
 CATKIN_DEPENDS ${REQ_CATKIN_PKGS}
 DEPENDS Boost PCL Eigen3
)

# setup global include directories
include_directories(
  src
  ${EIGEN3_INCLUDE_DIR}
  ${PCL_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}
  ${catkin_INCLUDE_DIRS}
)

# g2s_nodelet
add_subdirectory("src")

# g2s_planner_ros wrapper library
add_subdirectory("src/g2s_planner_ros")

# g2s_planner library
add_subdirectory("src/g2s_planner")
