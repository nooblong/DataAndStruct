cmake_minimum_required(VERSION 3.14)
project(DataAndStruct)

set(CMAKE_CXX_STANDARD 11)

add_executable(DataAndStruct
        Exception.h
        Linear_List/main1.cpp
        Linear_List/SeqLIst.h
        Link_List/main2.cpp
        Link_List/linkList.h
        Stack/main3.cpp
        Stack/SeqStack.h
        Stack/Stack.h Stack/dSeqStack.h Stack/linkStack.h Stack/calculator.cpp Stack/calculator.h)
