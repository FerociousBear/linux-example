/*
* =====================================================================================
*
*       Filename:  test.c
*
*    Description:  
*
*        Version:  1.0
*        Created:  11/21/2015 09:47:09 PM
*       Revision:  none
*       Compiler:  gcc
*
*         Author:  YOUR NAME (), 
*        Company:  
*
* =====================================================================================
*/
#include <dlfcn.h>
#include "so_test.h"
static  __attribute__((constructor(101))) void initA()
{
	printf("%s\n",__func__);
}

static  __attribute__((destructor(101))) void exitA()
{
	printf("%s\n",__func__);
}

static  __attribute__((constructor(102))) void initB()
{
	printf("%s\n",__func__);
}

static  __attribute__((destructor(102))) void exitB()
{
	printf("%s\n",__func__);
}

int main()
{
	const char* path = "libtest.so";
	void (*func)();
	void* handle = dlopen(path, RTLD_NOW);
	if (handle == NULL)
	{
		fprintf(stderr, "Failed to open libaray %s error:%s\n", path, dlerror());
		return -1;
	}

	func = dlsym(handle, "test_a");
	func();
	func = dlsym(handle, "test_b");
	func();
	func = dlsym(handle, "test_c");
	func();
	//dlclose(handle);
	return 0; 
}
