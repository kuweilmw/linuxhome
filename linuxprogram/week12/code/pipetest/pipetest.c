#include "my.h"

int main(){
	pid_t r;
	int r_num=0;
	int i;
	int pipefd[2];
	char buf[4096];
	
		//memset(buf2,0,sizeof(buf2));
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
	//	int buf2[4096];
		close(pipefd[0]);
	//	for(i=0;i<4096;i++)
	//		buf2[i]=i;
		if(r_num=write(pipefd[1],"123456789",10)!=-1)
			printf("parent is work!\n");
		close(pipefd[1]);
		return 0;
	}

}
