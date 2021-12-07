cmake_minimum_required(VERSION 3.20)
project(HW_22 C)

set(CMAKE_C_STANDARD 99)

add_executable(HW_22 main.c Date.c Date.h AirportManager.c AirportManager.h Airport.c Airport.h Flight.c Flight.h Plane.c Plane.h Airline.c Airline.h Checker.c Checker.h StringFunc.h StringFunc.c)
