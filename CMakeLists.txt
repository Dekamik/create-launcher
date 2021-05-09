cmake_minimum_required(VERSION 3.19)
project(create_launcher C)

set(CMAKE_C_STANDARD 99)

add_executable(create-launcher main.c utils/strutils.c utils/strutils.h args/args.c args/args.h utils/fileutils.c utils/fileutils.h args/argsint.c args/argsint.h)