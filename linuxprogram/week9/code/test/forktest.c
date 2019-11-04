#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int global1=0;
int global2=0;

int main(){
 int i = 10;
 static int k = 20;
 pid_t pid;
 pid = fork();
 if(pid<0)
 {
 	perror("fork defalut!");
	exit;
 }
 else if(pid == 0){
	printf("child pid:%d,ppid:%d,address:i: %d,global1:%d,global2:%d\n",getpid(),getppid(),&i,&global1,&global2);
	global1=999;
	global2=1000;
	i=12;
	k=19;
 }
 else{
	printf("parent pid:%d,ppid:%d,address:i: %d,global1:%d,global2:%d\n",getpid(),getppid(),&i,&global1,&global2);
    printf("parent i:%d,global1:%d,global2:%d,k:%d\n",i,global1,global2,k);
 }


}
