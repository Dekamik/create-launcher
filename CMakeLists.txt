cmake_minimum_required(VERSION 3.19)
project(create_launcher C)

set(CMAKE_C_STANDARD 99)

add_executable(create-launcher main.c strutils.c strutils.h args.h)