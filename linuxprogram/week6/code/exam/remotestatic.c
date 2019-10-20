#include "mylib.h"
#include <stdio.h>

int main(){
	int a[10],NUM=10;
	init(a,NUM);
	show(a,NUM);
	printf("max:%d\n",max(a,NUM));
	printf("sum:%d\n",sum(a,NUM));

	return 0;
}
