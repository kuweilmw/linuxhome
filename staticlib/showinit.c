#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
int show(int *a,int n){
	int i;
	for(i=0;i<n;i++){
		printf("a[%d]=%d\n",i,a[i]);		
	}
    return 0;
}
int init(int *a,int n){
	int i;
	srand((int)time(0));
	for(i=0;i<n;i++){
		a[i]=1+(int)(1000.0*rand()/(RAND_MAX+1.0));
	}
}
