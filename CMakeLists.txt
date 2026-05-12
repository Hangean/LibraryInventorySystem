cmake_minimum_required(VERSION 4.2)
project(Library_Inventory_System)

set(CMAKE_CXX_STANDARD 20)

add_executable(Library_Inventory_System main.cpp
        Item.h
        Shelf.h
        LibraryInventory.h
        Book.h
        Movie.h
        Magazine.h
        Helper.h
        Helper.cpp
        Item.cpp
        Shelf.cpp
        LibraryInventory.cpp
        Book.cpp
        Movie.cpp
        Magazine.cpp)
