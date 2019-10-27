#include "head.h"

 int main(){
	int x;
    while(1){
	menu1();
	scanf("%d",&x);
    printf("\n");
	if(x==0)
      break;
   
  switch(x)
  {
  case 1:  
	create1();
	break; 

  case 2:  
	towrite1();
	break;  
  case 3: 
	toread1();
	 break; 
  case 4: 
	
	 break; 
  case 5:  
	seeroot1();
	break; 
  default:  
      printf("输入的数字不正确\n");
      break;
  }	

	}
	return 0;
 }
