#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>


int main(){
 int i;
 FILE *fp;
 char buf[100];
 fp=fopen("/home/rlk/test/week10/filetest.txt","w");
 pid_t pid;
 pid = fork();
 if(pid<0)
 {
 	perror("fork defalut!");
	exit;
 }
 else if(pid == 0){

	
 printf("input write1 words :");
 scanf("%s",buf);	
 getchar();
 if(fp==NULL) 
 {
	printf("\nopen file error");
	getchar();
 }
 fwrite(buf, strlen(buf), 1, fp);
 fclose(fp);
	return 0;
 }
 else{
 sleep(10);
 printf("input write2 words :");
 scanf("%s",buf);	
 getchar();
 if(fp==NULL) 
 {
	printf("\nopen file error");
	getchar();
 }
 fwrite(buf, strlen(buf), 1, fp);
 fclose(fp);
	return 0;
 }


}
