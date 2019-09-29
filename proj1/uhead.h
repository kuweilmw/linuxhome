#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h>
#include <fcntl.h>

#define NUM 300
#define BUFFER_SIZE 64
struct arg{
	int sum;
	float ave;
};


void show(int *a,int n);
void urand(int *a,int n);
struct arg uoperater(int *a,int n);
int compar(const void *a,const void *b);
void syssort(int *a,int n);
void mysort(int *a,int n);
//int gettimeofday (struct timeval * tv, struct timezone * tz);
int writefile(int*, int, const char*);
int showfile(const char*);
