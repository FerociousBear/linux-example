/*
 * =====================================================================================
 *
 *       Filename:  so_test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/21/2015 09:39:41 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include "so_test.h"
static  __attribute__((constructor)) void so_init()
{
	printf("%s\n",__func__);
}

static  __attribute__((destructor)) void so_exit()
{
	printf("%s\n",__func__);
}

void test_a()
{
	printf("this is in test_a...\n");
} 

void test_b()
{
	printf("this is in test_b...\n");
} 

void test_c()
{
	printf("this is in test_c...\n");
} 
