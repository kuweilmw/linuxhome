#include "my.h"
static int share=0;
static pthread_rwlock_t rwlock;

void *reader(void *param)
{
	int i = (int)param;
	while(1)
	{
		pthread_rwlock_rdlock(&rwlock);
		fprintf(stderr,"reader--%d:the share = %d\n",i,share);
		pthread_rwlock_unlock(&rwlock);
	}
	return NULL;
}

void *writer(void *param)
{
	int i = (int)param;
	while(1)
	{
		pthread_rwlock_rdlock(&rwlock);
		share++;
		fprintf(stderr,"reader--%d:the share = %d\n",i,share);
		pthread_rwlock_unlock(&rwlock);
		sleep(1);
	}
	return NULL;
}

int main()
{
	pthread_t tid[TN];
	pthread_rwlockattr_t rwlock_attr;
	pthread_rwlockattr_init(&rwlock_attr);
	#ifdef WRITER_FIRST
		pthread_rwlockattr_serkind_np(&rwlock_attr,PIHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP);
	#endif
	pthread_rwlock_rdlock(&rwlock);
	for(i=0;i<TN;i++)
	{
		if(i%2==0)
			ret=pthread_create(&tid[i],NULL,reader,(void *)i);
		else
			ret=pthread_create(&tid[i],NULL,writer,(void *)i);
		if(ret!=0)
		{
		perror("thread1 init failed!\n");
		exit(1);
		}
	}
	return 0;
}