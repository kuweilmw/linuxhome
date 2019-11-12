#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int g=10;

int main(){
 int s = 20;
 static int k = 30;
 pid_t pid;
 pid = fork();
 if(pid<0)
 {
 	perror("fork defalut!");
	exit;
 }
 else if(pid == 0){
	printf("child pid:%d :address:s: %16p,g:%16p,k:%16p\n",getpid(),&s,&g,&k);
	g=100;
	s=200;
	k=300;
	
	printf("child s:%d,g:%d,k:%d\n",s,g,k);
	return 0;
 }
 else{
	sleep(2);
	printf("parent pid:%d :address:s: %16p,g:%16p,k:%16p\n",getpid(),&s,&g,&k);
    printf("parent s:%d,g:%d,k:%d\n",s,g,k);
	return 0;
 }


}
