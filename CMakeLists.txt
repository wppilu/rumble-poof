cmake_minimum_required(VERSION 3.26)
project(poof_fishing C)

set(CMAKE_C_STANDARD 11)

add_executable(poof_fishing main.c
        01/03_narcissus.c
        01/02_exchangeCoin.c
        01/01_powerSeriesSum.c)
