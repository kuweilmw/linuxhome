#include "my.h"

int main(){
	pid_t r;
	int r_num=0;
	int i,s;
	char a;
	int pipefd[2];
	char buf[4096];
	memset(buf,0,sizeof(buf));
	if(pipe(pipefd)<0)
	{
		perror("pipe failed!\n");
		return -1;
	}
	r=fork();
	if(r<0){
		perror("fork failed!\n");
		return -1;
	}
	else if(r==0)
	{
		
		close(pipefd[1]);
		if(r_num=read(pipefd[0],buf,4096)>0)
			printf("child read from pipe: %s,total= %d \n",buf,r_num);
		close(pipefd[0]);
		exit(0);
	}
	else{
		char buf2[4096];
		
		for(i=0;i<100;i++){
			strcpy(buf2[i],i);

		}
		close(pipefd[0]);
		if(r_num=write(pipefd[1],buf2,4096)!=-1)
			printf("parent is work!\n");
		close(pipefd[1]);
		return 0;
	}
}
