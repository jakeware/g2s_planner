// Copyright 2017 Massachusetts Institute of Technology

#include <csignal>
#include <memory>

#include "ros/ros.h"

#include "fla_utils/param_utils.h"

#include "g2s_planner_ros/g2s_planner_ros.h"
#include "g2s_planner/g2s_planner.h"
#include "g2s_planner/g2s_planner_params.h"

namespace g2s_planner {

G2SPlannerRos::G2SPlannerRos(volatile std::sig_atomic_t* stop_signal_ptr)
  : stop_signal_ptr_(stop_signal_ptr),
    nh_(),
    pnh_("~"),
    tf_listener_(tf_buffer_) {
  tf_buffer_.setUsingDedicatedThread(true);
}

void G2SPlannerRos::GetParams(G2SPlannerParams& params) {
  fla_utils::SafeGetParam(pnh_, "test_param", params.test_param_);
}

void G2SPlannerRos::InitSubscribers() {
  // not yet implemented
}

void G2SPlannerRos::InitPublishers() {
  // not yet implemented
}

void G2SPlannerRos::Run() {
  G2SPlannerParams params;
  GetParams(params);
  InitSubscribers();
  InitPublishers();

  // start mapping thread
  g2s_planner_ptr_ = std::unique_ptr<G2SPlanner>(new G2SPlanner(stop_signal_ptr_, params));
  g2s_planner_ptr_->Run();

  // handle ros callbacks
  ros::spin();
}

}  // namespace g2s_planner
