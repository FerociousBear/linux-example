#!/bin/sh
gcc so_test.c -fPIC -shared -o libtest.so
gcc test.c -ldl -o test
