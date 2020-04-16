cmake_minimum_required(VERSION 3.14)
project(DataAndStruct)

set(CMAKE_CXX_STANDARD 11)

add_executable(DataAndStruct
        Exception.h
        Linear_List/main1.cpp
        Linear_List/SeqLIst.h
        Link_List/main2.cpp
        Link_List/linkList.h
        Stack/main4.cpp
        Stack/SeqStack.h
        Stack/Stack.h
        Stack/dSeqStack.h
        Stack/linkStack.h
        Stack/calculator.cpp
        Stack/calculator.h
        Queue/Queue.h
        Queue/seqQueue.h
        DoubleLinkList/main3.cpp
        Queue/main5.cpp
        Queue/seqQueue1.h
        Queue/seqQueue2.h
        Queue/linkQueue.h
        String/String.cpp
        String/String.h
        String/main6.cpp
        Tree/main7.cpp
        Tree/binaryTree.h
        Tree/BinaryLinkTree.h
        Graph/graph.h
        Graph/adjMatrix.h
        Graph/main8.cpp
        Graph/adjList.h
        Homework/no2.cpp
        Homework/main.cpp Homework/no3.cpp)
