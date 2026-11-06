#include<stdio.h>
#include<stdlib.h>
typedef struct{
	char hoTen[100];
	int maSV;
	float d1,d2,d3;
}Data;
void nhap(Data *a,int n){
	int i;
	for( i=0;i<n;i++){
	
	printf("Sinh vien thu %d\n",i+1);
	printf("Ho ten: ");
	scanf(" %[^\n]",a[i].hoTen);
	printf("Ma sv: ");
	scanf("%d",&a[i].maSV);
	printf("Diem 1: ");
	scanf("%f",&a[i].d1);
	printf("Diem 2: ");
	scanf("%f",&a[i].d2);
	printf("Diem 3: ");
	scanf("%f",&a[i].d3);
	
}
}
void in(Data *a,int n){
	int i;
	printf("Danh sach sv=======\n");
	for(i=0;i<n;i++){
		printf("Ho ten: %s\n",a[i].hoTen);
		printf("Ma sv: %d\n",a[i].maSV);
		printf("Diem 1: %.2f\n",a[i].d1);
		printf("Diem 2: %.2f\n",a[i].d2);
		printf("Diem 3: %.2f\n",a[i].d3);
		
	}
}
int main(){
	Data *a;
	int n;
	printf("Nhap so sinh vien:");
	scanf("%d",&n);
	a=(Data*)malloc(n*sizeof(Data));
	if(a==NULL){
		printf("Ko du bo nho");
		return 1;
	}
	nhap(a,n);
	in(a,n);
	free(a);
	a=NULL;
	
}
