#include "my.h"
#define NUM_THREADS 4

void hello(void *t)
{
	pthread_t my_tid;
	my_tid=pthread_self();
	printf("\tThread %d:my tid is %lx,Hello world\n",t,my_tid);
}

int main()
{
	pthread_t tid;
	int rv,t,j,sum;
	
	for(t=0;t<NUM_THREADS;t++)
	{
		sum=0;
		for(j=0;j<=100;j++)
		sum=sum+j;
		rv=pthread_create(&tid,NULL,(void*(*)())hello,(void*)sum);
		if(rv!=0)
		{
			printf("thread create falied!\n");
			return -1;
		}
		printf("thread create %lx!\n",tid);
	}
	printf("Good bye!\n");
	pthread_exit(NULL);
}
