cmake_minimum_required(VERSION 2.8)
project(demo)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(RCC_RESOURCES demo.qrc)
set(CMAKE_BUILD_TYPE Debug)
find_package(Qt5Widgets REQUIRED)
#include_directories(${Qt5Widgets_INCLUDES})
add_definitions(${Qt5Widgets_DEFINITIONS})
set(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")
add_executable(${PROJECT_NAME} ${RCC_RESOURCES} main.cpp 
	MainWindow.cpp
	MainWidget.cpp
	AboutDialog.cpp
	)
target_link_libraries(${PROJECT_NAME} ${Qt5Widgets_LIBRARIES})
