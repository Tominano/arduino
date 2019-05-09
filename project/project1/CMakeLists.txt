cmake_minimum_required(VERSION 3.10)
include(/home/tamas/Desktop/ar/ArduinoProjects/project/arduino_diecimila_crosscompile.cmake)

include_directories(${ArduinoCode_SOURCE_DIR}/libarduinocore)
LINK_DIRECTORIES(${ArduinoCode_SOURCE_DIR}/libarduinocore)

link_libraries(arduinocore)

add_executable(project1 project.cpp)
