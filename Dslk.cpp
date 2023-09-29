#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int manv;
	char ten[30];
	int year;
}ElementType;


typedef struct Node* NodeType;
struct Node{
	ElementType data;
	NodeType next; 
}; 
typedef NodeType Position;
typedef Position List;

void MakeNullList (List *header){
	*header = (NodeType)malloc(sizeof(struct Node));
	(*header)->next=NULL;
}
int EmptyList (List L){
	return (L->next==NULL);
}
Position First (List L){
	return L;
}
Position Next (Position P, List L){
	return P->next;
}
ElementType Retrieve (Position P,List L){
	if (P->next!=NULL)
		return P->next->data;
}
Position EndList (List L){
	Position P;
	P=First (L);
	while (P->next!=NULL)
		P=P->next;
		return P;
}

// ham kiem tra ma nhan vien co trong danh sach hay khong
Position Find(int maso, List L){
	Position p;
	int found = 0;
	p = L;
	while(p->next != NULL && found == 0){
		if(p->next->data.manv == maso)  found = 1;
		else p = p->next;	
	}
	return p;
	
}

void InsertList (ElementType X,Position P,List *L){
	Position T;
	T=(NodeType) malloc (sizeof (struct Node));
	T->data=X;
	T->next=P->next;
	P->next=T;
}
/*
void ReadList (List *L){
	int i,N;
	ElementType X;
	MakeNullList (L);
	printf("so phan tu danh sach N= ");
	scanf("%d",&N);
	for(i=1;i<=N;i++){
		printf("Phan tu thu %d: ",i);
		scanf ("%d",&X);
		InsertList(X,EndList(*L),L);
	}
}

*/

// ham nhap nhan vien vao danh sach
void readList(List *L){
	int i, n;
	MakeNullList(L);
	printf("So phan tu trong danh sach n = ");
	scanf("%d",&n);
	for(i = 1;i<=n;i++){
		ElementType x;
		printf(" Phan tu thu %d \n", i );
		printf(" Ma so nhan vien: "); scanf("%d", &x.manv);
		getchar();
		printf("Ho ten nhan vien: ");  gets(x.ten);
		printf("Tuoi nhan vien: ");  scanf("%d", &x.year);
		if(Find(x.manv,*L) == EndList(*L))
			InsertList(x,EndList(*L),L);
		else {
			printf("ma so nhan vien da ton tai!");
		}
	}
}

/*
void PrintList (List L){
	Position P;
	P=First(L);
	while (P !=EndList(L)) {
		printf ("%d ",Retrieve (P,L));
		P=next(P,L);
	}
	printf("\n");
}     */

void printfList(List L){
	Position p;
	ElementType x;
	p = First(L);
	while(p != EndList(L)){
		x = Retrieve(p,L);
		printf("%d: %s:%d\n",x.manv,x.ten,x.year );
		p = Next(p,L);
	}
	printf("\n");
}

void Sort(List *L){
	Position p,q, smallest;
	p = First(*L);
	while(p->next != NULL){
		smallest = p;
		q = Next(p,*L);
		while (q->next != NULL){
			if( q->next->data.year < smallest->next->data.year)
				smallest = q;
			q = Next(q, *L);
		}
		ElementType x;
		x = p->next->data;
		p->next->data = smallest->next->data;
		smallest->next->data = x;
		p= Next(p,*L);
	}
   }

main(){
	List L;
	ElementType X;
	Position P;
	do{
		printf()
	}while(lc != 0)
	switch(lc)

}
