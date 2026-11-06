#include<stdio.h>
#include<stdlib.h>
typedef struct{
	char hoTen[100];
	int maSV;
	float d1,d2,d3;
	 
}Data;
typedef struct tagNode{
	Data infor;
	struct tagNode*link; 
}Node;
typedef struct{
	Node*pH;Node*pT;
	int spt; 
}LList;

void taoDanhSach(LList*L){
	L->pH=NULL;
	L->pT=NULL;
	L->spt=0 ;
}
int emptyList(LList L){
	return L.pH==NULL;
}
void insert_Dau(LList*L,Data x){
	Node*pp;
	pp=(Node*) malloc(sizeof(Node));
	pp->infor=x;
	pp->link=NULL;
	if(emptyList(*L)){
		L->pH=pp;
		L->pT=pp;
		
	} else{
		pp->link=L->pH;
		L->pH=pp;
	}
	L->spt++;
}
void nhap(LList*L){
	Data x;
	int n,i;
	printf("Nhap so sinh vien: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("SV %d\n",i+1);
		printf("Ho ten: ");
		scanf(" %[^\n]",x.hoTen);
		printf("Ma sv: ");
		scanf("%d",&x.maSV);
		printf("Diem 1: ");
		scanf("%f",&x.d1);
			printf("Diem 2: ");
		scanf("%f",&x.d2);
		
			printf("Diem 3: ");
		scanf("%f",&x.d3);
		insert_Dau(L,x);
		
	}
	
}
void in(LList L){
	Node *pp=L.pH;
	printf("==========Danh sach==============\n");
	while(pp!=NULL){
		printf("Ho ten: %s\n",pp->infor.hoTen);
		printf("Ma sinh vien: %d\n",pp->infor.maSV);
		printf("Diem 1: %.2f\n",pp->infor.d1);
			printf("Diem 2: %.2f\n",pp->infor.d2);
				printf("Diem 3: %.2f\n",pp->infor.d3);
				pp=pp->link;
	}
}
int main(){
	LList L;
	taoDanhSach(&L);
	nhap(&L);
	in(L);
	
}
 
