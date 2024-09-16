//#define _XOPEN_SOURCE  500
#include "Python.h"

#include <stdio.h>

// Code for determining page size swiped from Python's mmapmodule.c
#if defined(HAVE_SYSCONF) && defined(_SC_PAGESIZE)
static int
my_getpagesize(void)
{
    printf("%d\n", 2);
	return sysconf(_SC_PAGESIZE);
}
#elif defined(HAVE_SYSCONF)
static int
my_getpagesize(void)
{
    printf("%d\n", 3);
	return sysconf(_SC_PAGESIZE);
}
#elif defined(_SC_PAGESIZE)
static int
my_getpagesize(void)
{
    printf("%d\n", 4);
	return sysconf(_SC_PAGESIZE);
}
#else
#include <unistd.h>
#define my_getpagesize getpagesize
#endif

int main(void) {
    printf("%d\n", my_getpagesize());

    return 0;
}
