#include "my.h"

int count=0;

int main()
{
	pid_t p1,p2,p3;
	int sum=0,x=0;
	int pipefd1[2],pipefd2[2];
	char buf1[10];
	char buf2[10];
	memset(buf1,0,sizeof(buf1));
	memset(buf2,0,sizeof(buf2));
	
	if(pipe(pipefd1)<0||pipe(pipefd2)<0)
	{
		perror("pipe failed!\n");
		return -1;
	}
	p1=fork();
	int s1,s2,s3,r1,r2,r3;
	
	if(p1<0){
		perror("fork1 failed!\n");
		return -1;
	}
	else if(p1==0)
	{
		close(pipefd1[0]);
		printf("parent fork first!\n");
		count+=1;
		printf("chid1 pid=%d,ppid=%d,count=%d\n",getpid(),getppid(),count);

		for(int i=1;i<4097;i++)
		{
			sprintf(buf1,"%d",i);
			write(pipefd1[1],buf1,sizeof(buf1));
		}		
		close(pipefd1[1]);
		exit(99);
	}
	else{
		p2=fork();
	
		if(p2<0){
			perror("fork2 failed!\n");
			return -1;
		}
		else if(p2==0)
		{
			close(pipefd1[1]);
			close(pipefd2[0]);
			printf("parent fork sercond!\n");
			count+=1;
			printf("chid2 pid=%d,ppid=%d,count=%d\n",getpid(),getppid(),count);

			for(int i=1;i<4097;i++)
			{
				read(pipefd1[0],buf2,sizeof(buf2));
				sscanf(buf2,"%d",&x);
				printf("%d\n",x);
				sprintf(buf1,"%d",x);
				write(pipefd2[1],buf1,sizeof(buf1));
			}				
	
			close(pipefd1[0]);
			close(pipefd2[1]);
			exit(34);
		}
		else{
			p3=fork();
	
			if(p3<0){
				perror("fork3 failed!\n");
				return -1;
			}
			else if(p3==0)
			{
				close(pipefd2[1]);
				printf("parent fork third!\n");
				count+=1;
				printf("chid3 pid=%d,ppid=%d,count=%d\n",getpid(),getppid(),count);
				for(int i=1;i<4096;i++)
				{
					read(pipefd2[0],buf2,sizeof(buf2));
					sscanf(buf2,"%d",&x);
					sum=sum+x;
				}
				printf("Result: sum=%d\n",sum);
				close(pipefd2[0]);
				exit(77);
			}
			else{
				printf("parent waitting !\n");
				r1=wait(&s1);
				r2=wait(&s2);
				r3=wait(&s3);
				count+=1;	printf("r1=%d,s1=%d,r2=%d,s2=%d,r3=%d,s3=%d\n",r1,WEXITSTATUS(s1),r2,WEXITSTATUS(s2),r3,WEXITSTATUS(s3));
				printf("parent pid=%d,count=%d\n",getpid(),count);	
				printf("parent is running.\n");
				return 0;
			}
		}
		
	}

}
