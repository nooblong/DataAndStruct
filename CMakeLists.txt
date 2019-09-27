cmake_minimum_required(VERSION 3.14)
project(DataAndStruct)

set(CMAKE_CXX_STANDARD 11)

add_executable(DataAndStruct Linear_List/main1.cpp Exception.h List.h Linear_List/SeqLIst.h Link_List/main2.cpp Link_List/linkList.h DoubleLinkList/main3.cpp DoubleLinkList/DoubleLinkList.cpp DoubleLinkList/DoubleLinkList.h)