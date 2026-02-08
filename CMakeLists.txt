cmake_minimum_required(VERSION 4.0)
project(Tugas_Lab_PROYEKPRAKTIKUM C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Tugas_Lab_PROYEKPRAKTIKUM
        book.c
        book.h
        data.c
        data.h
        main.c
        sort_buku.c
        sort_buku.h
        transaction.c
        transaction.h)
