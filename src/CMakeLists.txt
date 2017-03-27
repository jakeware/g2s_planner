# add node library
add_executable(g2s_planner_node
  g2s_planner_node.cc
)

# add node upstream dependencies
target_link_libraries(g2s_planner_node
  ${catkin_LIBRARIES}
  g2s_planner_ros
)

# install node
install(TARGETS g2s_planner_node
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
  )

# add nodelet library
add_library(g2s_planner_nodelet
  g2s_planner_nodelet.cc
)

# add nodelet upstream dependencies
target_link_libraries(g2s_planner_nodelet
  ${catkin_LIBRARIES}
  g2s_planner_ros
)

# install nodelet
install(TARGETS g2s_planner_nodelet
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
  )
