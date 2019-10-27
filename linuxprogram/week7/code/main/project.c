#include "head.h"

 void menu1(){
  printf("-------------操作选项-----------\n");
  printf("0:退出 \n");
  printf("1:创建新文件 \n");
  printf("2:写文件 \n");
  printf("3:读文件 \n");
  printf("4:修改文件权限 \n");
  printf("5:查看当前文件的权限修改文件权限\n");
  printf("--------------------------------\n");
 
  
  printf("按数字键选择要执行的操作: ");
 }

 void create1(){
	int i;
	FILE *fp;
	char a[10],path[100];
	strcpy(path, "/home/rlk/test/");
	printf("input file name :");
	scanf("%s",a);	
	getchar();
    strcat(path,a);
    fp=fopen(path,"w");
	if(fp==NULL) 
	{
		printf("\nopen file error");
		getchar();
	}
	for (i = 0; i < strlen(a); i++)
              a[i] = '\0' ;  
	fclose(fp);
 }

void towrite1(){
	FILE *fp;
	char a[10],path[100],buf[100];
	strcpy(path, "/home/rlk/test/");
	printf("input file name :");
	scanf("%s",a);	
	getchar();
    strcat(path,a);
	printf("input write words :");
	scanf("%s",buf);	
	getchar();
	fp=fopen(path,"w");
	if(fp==NULL) 
	{
		printf("\nopen file error");
		getchar();
	}
	fwrite(buf, strlen(buf), 1, fp);
	fclose(fp);
}

void toread1(){
	FILE *fp;
 	char a[10],path[100],buf[100],bufread[10240] = {0};
	strcpy(path, "/home/rlk/test/");
	printf("input file name :");
	scanf("%s",a);	
	getchar();
    strcat(path,a);
	fp=fopen(path,"r");
	if(fp==NULL) 
	{
		printf("\nopen file error");
		getchar();
	}
    fread(bufread, 1024, 10, fp);
    printf("%s\n", bufread);
    fclose(fp);
}

void seeroot1(){
 	FILE *fp;
 	char a[10],path[100],bufread[10240] = {0};
 	struct stat bufstat;
	strcpy(path, "/home/rlk/test/");
	printf("input file name :");
	scanf("%s",a);	
	getchar();
    strcat(path,a);
	stat(path, &bufstat);
 	printf(" file size = %d\n", bufstat.st_size);
}


