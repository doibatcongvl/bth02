#include<stdio.h>
#include<stdlib.h>
typedef struct{
	char hoten[30];
	int masv;
	float d1,d2,d3;
	
}Data;
typedef struct tagNode{
	Data infor;
	struct tagNode*link;
}Node;
typedef struct{
	Node*pH;
	Node*pT;
	int spt;
}LList;
/////////////////////
void initList(LList*L){
	L->pH=NULL;
	L->pT=NULL;
	L->spt=0;
}
int emptyList(LList L){
	return (L.spt==0);
}
void insertDau(LList*L,Data x){
	Node*pp;
	pp=(Node*)malloc(sizeof(Node));
	pp->infor=x;
	pp->link=NULL;
	if(emptyList(*L)){
		L->pH=pp;
		L->pT=pp;
	}else{
		pp->link=L->pH;
		L->pH=pp;
	}
	L->spt++;
}
void insertCuoi(LList*L,Data x){
	Node*pp;
	pp=(Node*)malloc(sizeof(Node));
	pp->infor=x;
	pp->link=NULL;
	if(emptyList(*L)){
		L->pH=pp;
		L->pT=pp;
	}else{
		L->pT->link=pp;
		L->pT=pp;
	}
	L->spt++;
}
void insertSau(LList*L,Node*q,Data x){
	Node*pp;
	if(NULL==q) return;
	else{
		pp=(Node*)malloc(sizeof(Node));
		pp->infor=x;
		pp->link=q->link;
		q->link=pp;
		if(q==L->pT){
			L->pT=pp;
		}
		L->spt++;
	}	
}
void xoaDau(LList*L){
	Node*pp;
	if(emptyList(*L)) return;
	else{
		pp=L->pH;
		L->pH=pp->link;
		free(pp);
		L->spt--;
		if(L->pH==NULL){
			L->pT=NULL;
		}
	}
}
void xoaSau(LList*L,Node*q){
	Node*pp;
	if(q==NULL||q->link==NULL) {
	return;
}else{

	pp=q->link;
	q->link=pp->link;
	if(pp==L->pT){
		L->pT=q;
	}
	free(pp);
	L->spt--;
	}
}
void chen_tang(LList*L,Data x){
	Node*pp=L->pH,*q=NULL;
	while(pp!=NULL && pp->infor.masv<x.masv){
		q=pp;
		pp=pp->link;
	}
	if(q==NULL){
		insertDau(L,x);
	}else{
		insertSau(L,q,x);
	}
}
void tach(LList L,LList *L1,LList *L2){
	initList(L1);
	initList(L2);
	Node*pp=L.pH;
	while(pp!=NULL){
		float dtb=(pp->infor.d1+pp->infor.d2+pp->infor.d3)/3;
		if(dtb>=5)
			insertDau(L1,pp->infor);
		else{
			insertDau(L2,pp->infor);
		}
		pp=pp->link;
	}
}
void ghep(LList L1,LList L2,LList *L){
	initList(L);
	Node *p1=L1.pH;
	Node*p2=L2.pH;
	
		while(p1!=NULL && p2!=NULL){
			insertCuoi(L,p1->infor);
			insertCuoi(L,p2->infor);
			p1=p1->link;
			p2=p2->link;
		}
		while(p1!=NULL){
			insertCuoi(L,p1->infor);
			p1=p1->link;
		}
	
		while(p2!=NULL){
			insertCuoi(L,p2->infor);
			p2=p2->link;	
		}
		
	}

void nhap(Data *x){
	printf("Nhap ma sv:");
	scanf("%d",&(x->masv));
	if(x->masv>0){
		printf("Nhap ho ten:");
		scanf("%s",(x->hoten));
		printf("Nhap diem mon 1:");
		scanf("%f",&(x->d1));
		printf("Nhap diem mon 2:");
		scanf("%f",&(x->d2));
		printf("Nhap diem mon 3:");
		scanf("%f",&(x->d3));
	}
}

void in(Data x){
	printf("Ten: %s,Ma sv: %d,Diem mon 1: %.2f,Diem mon 2:%.2f,Diem mon 3:%.2f\n",x.hoten,x.masv,x.d1,x.d2,x.d3);
}
void processList(LList L){
	Node*pp=L.pH;
	while(pp!=NULL){
		in(pp->infor);////in du lieu trong node
		pp=pp->link;
	}
}
////////////////
int main(){
	LList L,L1,L2,L3;
	int kt=0;
	Data x;
	initList(&L);///tao ds
	initList(&L1);
	initList(&L2);
	initList(&L3);
	int chon,ma;
	Node*p;
	do{
		printf("\nChuong trinh lam viec voi DSLKD sinh vien\n");
		printf("1.Them nut vao dau danh sach\n");
		printf("2.Them nut vao cuoi danh sach\n");
		printf("3.Them nut vao sau 1 nut khac trong danh sach\n");
		printf("4:Xoa nut dau\n");
		printf("5:Xoa nut sau\n");
		printf("6:Chen tang\n");
		printf("7:Tach\n");
		printf("8:Ghep\n");
		printf("9.Exit\n");
		printf("Hay lua chon:");
		
		scanf("%d",&chon);
		switch(chon){
			case 1:
				printf("Nhap so thong tin sinh vien can them\n");
				nhap(&x);
				if(x.masv>0){
					insertDau(&L,x);
				}
				break;
			case 2:
				nhap(&x);
				if(x.masv>0){
					insertCuoi(&L,x);
				}
				break;
			case 3:
				nhap(&x);
				if(x.masv>0){
					printf("Nhap ma sv muon chen:");
					scanf("%d",&ma);
					p=L.pH;
					while(p!=NULL && p->infor.masv!=ma){
						p=p->link;
					}
					if(p!=NULL){
					insertSau(&L,p,x);
				}else{
					printf("Khong tim thay sinh vien\n");
				}
			}
			break;
		    case 4:
		    	xoaDau(&L);
		    	break;
		    case 5:
		    	printf("Nhap ma sv muon xoa: ");
		    	scanf("%d",&ma);
		    	p=L.pH;
		    	while(p!=NULL && p->infor.masv!=ma){
		    		p=p->link;
				}
		    
		    	if(p!=NULL && p->link!=NULL){
		    		xoaSau(&L,p);
				}else{
					printf("Khong tim thay sinh vien\n");
				}
		    	break;
		    case 6:
		    	nhap(&x);
		    	if(x.masv>0){
		    		chen_tang(&L,x);
				}
				break;
			case 7:
				tach(L,&L1,&L2);
				kt=1;
				printf("\nDanh sach thu 1\n");
				processList(L1);
				printf("\nDanh sach thu 2\n");
				processList(L2);
				break;
			case 8:
				if(kt==1){
					ghep(L1,L2,&L3);
					printf("\nDanh sach da ghep\n");
					processList(L3);
				}else{
					printf("Chua co danh sach tach san\n");
				}
				break;
			case 9:
				printf("Closed!\n");
				break;
			default:
				printf("Lua chon khong hop le\n");
			}
			if(chon>=1 && chon<=6){
				printf("\nDanh sach hien tai\n");
				processList(L);
			}		
		}while(chon!=9);
		
	
}


