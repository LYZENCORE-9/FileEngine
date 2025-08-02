cmake_minimum_required(VERSION 3.24)

project(INITests)

#if("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU")
	SET(GCC_COVERAGE_COMPILE_FLAGS "-static -g -O0")
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
	#endif()


add_library(FILEENGINE_INI_FILE 	    OBJECT      "source/INI/iem-ini-file.cpp")
add_library(FILEENGINE_INI_WRITE 	    OBJECT      "source/INI/iem-ini-write.cpp")
add_library(FILEENGINE_INI_READ 	    OBJECT      "source/INI/iem-ini-read.cpp")

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} FILEENGINE_INI_FILE)
target_link_libraries(${PROJECT_NAME} FILEENGINE_INI_WRITE)
target_link_libraries(${PROJECT_NAME} FILEENGINE_INI_READ)



