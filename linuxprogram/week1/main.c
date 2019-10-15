#include "uhead.h"


int main(){
  	struct timeval tv1,tv2,tv3,tv4;
  	struct timezone tz;
	int a[NUM];
	struct arg t;
	urand(a,NUM);
	show(a,NUM);
	writefile(a, NUM, "old.txt");	
	t = uoperater(a,NUM);
	gettimeofday (&tv1, &tz);
	syssort(a,NUM);
	gettimeofday (&tv2, &tz);
	writefile(a, NUM, "new.txt");
	gettimeofday (&tv3, &tz);
    mysort(a,NUM);
	gettimeofday (&tv4, &tz);
	printf("time1:%d\n",tv2.tv_usec-tv1.tv_usec);
	printf("time2:%d\n",tv4.tv_usec-tv3.tv_usec);
	printf("sum=%d,ave=%f\n",t.sum,t.ave);
	showfile("old.txt");
	showfile("new.txt");
	return 0;
}
