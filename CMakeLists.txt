cmake_minimum_required(VERSION 3.8)
project(AdjacencyMatrix)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp AdjMGraph.cpp AdjMGraph.h SeqList.h AdjMGraphCreate.h AdjMGraphTraverse.h)
add_executable(AdjacencyMatrix ${SOURCE_FILES} AdjMGraph.cpp AdjMGraph.h SeqList.h AdjMGraphCreate.h AdjMGraphTraverse.h)