include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
)

set(gammaray_scriptenginedebugger_plugin_srcs
  scriptenginedebugger.cpp
  ../../singlecolumnobjectproxymodel.cpp
  ../../util.cpp
  ../../3rdparty/kde/kidentityproxymodel.cpp
)
qt4_automoc(${gammaray_scriptenginedebugger_plugin_srcs})
qt4_wrap_ui(gammaray_scriptenginedebugger_plugin_srcs scriptenginedebugger.ui)

gammaray_add_plugin(gammaray_scriptenginedebugger_plugin gammaray_scriptenginedebugger.desktop ${gammaray_scriptenginedebugger_plugin_srcs})
target_link_libraries(gammaray_scriptenginedebugger_plugin
  ${QT_QTCORE_LIBRARY}
  ${QT_QTGUI_LIBRARY}
  ${QT_QTSCRIPT_LIBRARY}
  ${QT_QTSCRIPTTOOLS_LIBRARY}
)
