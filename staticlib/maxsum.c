int max(int *a,int n){
	int i;
	int max = 0;
	
	for(i=0;i<n;i++){
		if(max<a[i])
		max = a[i];
		
	}
    return max;
}
int sum(int *a,int n){
	int i;
	int sum = 0;
	
	for(i=0;i<n;i++){
		sum=sum+a[i];
		
	}
    return sum;
}
