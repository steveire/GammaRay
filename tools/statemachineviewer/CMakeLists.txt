if(GRAPHVIZ_FOUND)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${GRAPHVIZ_INCLUDE_DIR}
)

set(gammaray_statemachineviewer_plugin_srcs
  # this part depends on graphviz
  gvgraph/gvgraph.cpp
  gvgraph/gvgraphitems.cpp

  statemachineview.cpp
  statemachineviewer.cpp
  statemachinewatcher.cpp

  transitionmodel.cpp
  statemodel.cpp

  ${CMAKE_SOURCE_DIR}/util.cpp
)
qt4_automoc(${gammaray_statemachineviewer_plugin_srcs})
qt4_wrap_ui(gammaray_statemachineviewer_plugin_srcs statemachineviewer.ui)

set(gammaray_statemachineviewer_plugin_libs
  ${QT_QTCORE_LIBRARY}
  ${QT_QTGUI_LIBRARY}

  ${GRAPHVIZ_GRAPH_LIBRARY}
  ${GRAPHVIZ_GVC_LIBRARY}
)

gammaray_add_plugin(gammaray_statemachineviewer_plugin gammaray_statemachineviewer.desktop ${gammaray_statemachineviewer_plugin_srcs})
target_link_libraries(gammaray_statemachineviewer_plugin ${gammaray_statemachineviewer_plugin_libs})

add_executable(statemachineviewer_test
  gvgraph/gvgraph.cpp
  gvgraph/gvgraphitems.cpp

  test_main.cpp
)
target_link_libraries(statemachineviewer_test ${gammaray_statemachineviewer_plugin_libs})

endif()
