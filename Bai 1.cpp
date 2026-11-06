#include<stdio.h>
#include<stdlib.h> 
void nhap(float *a,int m,int n) {

	int i,j; 
	for( i=0;i<m;i++){
	       for(j=0;j<n;j++){
	       	  
	       	   scanf("%f",a+i*m+j); 
		   } 
	
	} 
} 
void in(float *a,int m,int n){
	int i,j; 
	for(i=0;i<m;i++ ){
		for(j=0;j<n;j++){
			
		
		printf("%.2f ",*(a+i*m+j)); 
}
	printf("\n"); 

}
}
int main(){
	float *a;
	
	int m,n;
	printf("Nhap so hang va cot ");
	scanf("%d %d",&m,&n);

	 a=(float*) malloc(m*n*sizeof(float*));
	 
	 nhap(a,m,n);
	 printf("Mang vua nhap\n");
	 in(a,m,n);
free(a); 
	 a=NULL;
	   
}  
