# add g2s_planner_ros library
add_library(g2s_planner_ros
  g2s_planner_ros.cc
  )

target_link_libraries(g2s_planner_ros
  g2s_planner
  ${catkin_LIBRARIES}
  ${PCL_LIBRARIES}
  )

install(TARGETS g2s_planner_ros
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
  )
