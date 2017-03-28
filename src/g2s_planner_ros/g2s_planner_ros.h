// Copyright 2017 Massachusetts Institute of Technology
#pragma once

#include <csignal>
#include <memory>

#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"

#include "g2s_planner/g2s_planner.h"

namespace g2s_planner {

class G2SPlannerRos {
 public:
  explicit G2SPlannerRos(volatile std::sig_atomic_t* stop_signal_ptr);

  void Run();

  volatile std::sig_atomic_t* stop_signal_ptr_;

 private:
  void GetParams(G2SPlannerParams& g2s_planner_params);
  void InitSubscribers();
  void InitPublishers();

  // callbacks

  // publishers

  // subscribers

  // params
  G2SPlannerParams params_;

  std::unique_ptr<G2SPlanner> g2s_planner_ptr_;
  ros::NodeHandle nh_;
  ros::NodeHandle pnh_;
  tf2_ros::TransformListener tf_listener_;
  tf2_ros::Buffer tf_buffer_;
};
}  // namespace g2s_planner
