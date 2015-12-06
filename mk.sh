#!/bin/sh
gcc so_test.c -lpthread -fPIC -shared -o libtest.so
gcc test.c -ldl -o test
