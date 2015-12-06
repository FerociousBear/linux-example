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
#include <pthread.h>
#include "so_test.h"
int gSec;
pthread_t id_a;

static  __attribute__((constructor)) void so_init()
{
	printf("%s\n",__func__);
}

static  __attribute__((destructor)) void so_exit()
{
	printf("%s l:%d\n",__func__,__LINE__);
	//pthread_exit(0);
	pthread_join(id_a,NULL);
	printf("%s l:%d\n",__func__,__LINE__);
}

void* thread(void* data)
{
	int sec = *(int*)data;
	printf("%s l:%d\n",__func__,__LINE__);
	sleep(sec);
	printf("%s l:%d\n",__func__,__LINE__);
}

void test_a()
{
	printf("this is in test_a...\n");
	int ret;
	gSec = 4;
	ret=pthread_create(&id_a,NULL,thread,&gSec);
	if(ret!=0){
		printf ("Create pthread error!\n");
	}
} 

void test_b()
{
	printf("this is in test_b...\n");
} 

void test_c()
{
	printf("this is in test_c...\n");
} 
