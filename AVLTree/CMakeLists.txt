cmake_minimum_required(VERSION 3.21)
project(AVLTree)

set(CMAKE_CXX_STANDARD 14)

add_executable(AVLTree main.cpp  BST.cpp BST.h AVLTree.cpp AVLTree.h BinNode.cpp BinNode.h BinTree.cpp BinTree.h)