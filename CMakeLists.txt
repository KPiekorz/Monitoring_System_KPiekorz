cmake_minimum_required(VERSION 3.15)
project(Monitoring_System_KPiekorz)

set(CMAKE_CXX_STANDARD 14)

add_executable(Monitoring_System_KPiekorz scr/main.cpp scr/Packet.cpp inc/Packet.h scr/Sequence.cpp inc/Sequence.h scr/TimeHistory.cpp inc/TimeHistory.h scr/Spectrum.cpp inc/Spectrum.h scr/Alarm.cpp inc/Alarm.h)