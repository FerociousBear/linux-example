#!/bin/sh
gcc so_test.c -fPIC -shared -o libtest.so
gcc test.c -L. -ltest -o test
