#include "uhead.h"

int compar(const void *a,const void *b)
{
	int *aa=(int *)a,*bb = (int *)b;
	if(*aa>*bb)return 1;
	if(*aa==*bb)return 0;
	if(*aa<*bb)return -1;
}

void syssort(int *a,int n){
	qsort(a,n,sizeof(int),compar);
}

void mysort(int *a,int n){
	int i,j,t;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;		
			}		
		}
	}
}

int writefile(int* arr, int len, const char* filename)
{
	int file;
	char buffer[BUFFER_SIZE];
	int n = 0;
	int i;
	int flags= O_CREAT | O_RDWR| O_TRUNC;
	if((file = open(filename, flags, 0644)) != -1)
	{
		/* 清空文件 */
		ftruncate(file, 0);
		/* 重新设置文件偏移量 */
		lseek(file, 0, SEEK_SET);

		for(i = 0; i < len;)
		{
			if(n <= BUFFER_SIZE - 4)
			{
				n += sprintf(buffer + n, "%d ", arr[i++]);
			}
			else
			{
				write(file, buffer, n);
				n = 0;
			}
		}
		if(n <= BUFFER_SIZE - 1)
		{
			n += sprintf(buffer + n, "\n");
			write(file, buffer, n);
			n = 0;
		}
		else
		{
			write(file, buffer, n);
			n = 0;
			n += sprintf(buffer + n, "\n");
			write(file, buffer, n);
			n = 0;
		}

		close(file);
		return 0;
	}
	else
	{
		printf("file can not be found!\n");
		return -1;
	}
}

int showfile(const char* filename)
{
	printf("\n%s:\n", filename);
	int file;
	int n = 0;
	char buffer[BUFFER_SIZE];

	if((file = open(filename, O_RDWR)) != -1)
	{
		do
		{
			n = read(file, buffer, BUFFER_SIZE-1);
			printf("%s",buffer);
			//memset(buffer, 0, BUFFER_SIZE*sizeof(char));
		}while(n != 0);
		return 0;
	}
	else
	{
		printf("file can not be found!\n");
		return -1;
	}
}
