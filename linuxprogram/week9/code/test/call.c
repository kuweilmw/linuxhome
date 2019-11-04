#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()

{

printf("call:pid-> %d\n",getpid());

printf("call:ppid-> %d\n",getppid());

system("/home/rlk/test/week9/test");
printf("after call");
return 0;

 }
