cmake_minimum_required (VERSION 3.0)
include("GNUInstallDirs")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(PluginName "Bookmarks")

find_package(Qt5 5.0.0 REQUIRED Widgets)

add_library(${PluginName} SHARED
	Bookmarks.cpp
	Bookmarks.h
	BookmarkWidget.cpp
	BookmarkWidget.h
	BookmarksModel.cpp
	BookmarksModel.h
	Bookmarks.ui
)

target_link_libraries(${PluginName} Qt5::Widgets edb)

install (TARGETS ${PluginName} DESTINATION ${CMAKE_INSTALL_LIBDIR}/edb)

set_property(TARGET ${PluginName} PROPERTY CXX_EXTENSIONS OFF)
set_property(TARGET ${PluginName} PROPERTY CXX_STANDARD 14)
set_property(TARGET ${PluginName} PROPERTY LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
set_property(TARGET ${PluginName} PROPERTY RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

if (ENABLE_JUMBO_BUILD)
	enable_jumbo_build(${PluginName})
endif()
