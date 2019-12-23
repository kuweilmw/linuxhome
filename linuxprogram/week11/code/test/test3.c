#include "my.h"

int main(){
 int pid,s;
 if((pid=fork())<0){
	perror("failed to fork\n");
	return -1;
 }
 else if(pid==0){
	printf("%d : child is running now!\n",getpid());
	printf("%d : child is exit now!\n",getpid());
	while(1);
	exit(120);
 }
 else{
	printf("%d : parent is waiting zombie now !\n",getpid());
	while((pid = wait(&s))!=1){
		if(WIFEXITED(s)){
			printf("chile %d exit normally.exit code=%d \n",pid,WEXITSTATUS(s));	
		}
		else if(WIFSIGNALED(s)){
			printf("chile %d exit signal.signal no=%d \n",pid,WTERMSIG(s));
		}
		else{
			printf("NOT know!\n");
		}
	}
	printf("%d : parent is exiting now !\n",getpid());
 }
	exit(0);
}
