//Bai 14 Da Thuc Su dung lien ket don
#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;
struct DonThuc
{
float heso;
int somu;
};
struct node
{
DonThuc info;
node *next;
};
struct DaThuc
{
node *head;
node *tail;
};
node* getnode(DonThuc x)
{
node *p;
p=new node;
if(p==NULL)
{
cout<<"\n khong du bo nho";
return NULL;
}
p->info=x;
p->next=NULL;
return p;
}
void khoitao(DaThuc &L)
{
L.head=NULL;
L.tail=NULL;

}
void addhead(DaThuc &L,node *p)
{
if(L.tail==NULL)
{
L.head=p;
L.tail=p;
}
else
{
p->next=L.head;
L.head=p;
}

}
void themdau(DaThuc &L,DonThuc x)
{
node *p;
p=getnode(x);
addhead(L,p);
}
void nhap(DonThuc &x)
{
cout<<"\n Nhap Vao Don Thuc";
cout<<"\nNhap vao he so: ";
cin>>x.heso;
cout<<"\nNhap so mu: ";
cin>>x.somu;
}
void nhapDaThuc(DaThuc &L)
{
int n;
DonThuc x;
node *p;
p=L.head;
cout<<"Nhap Da Thuc\n";
cout<<"nhap vao so luong don thuc: ";
cin>>n;
for(int i=0;i<n;i++)
{
cout<<"\n Don Thuc "<<i+1 <<" = ";
nhap(x);

themdau(L,x);
}
}
void congdathuc(DaThuc L,DaThuc L1,DaThuc &T)
{
node *p,*q;
int flag;
p=L.head;
while(p!=NULL)
{
themdau(T,p->info);
p=p->next;
}
p=L1.head;
q=T.head;
while (q!=NULL)
{
p=L1.head;
while (p!=NULL)
{
if(p->info.somu==q->info.somu)
q->info.heso+=p->info.heso; 
p=p->next;
}
q=q->next;
}

p=L1.head;
while (p!=NULL) 
{
flag=0;
q=T.head;
while (q!=NULL)
{
if(q->info.somu==p->info.somu)
flag=1;
q=q->next;
}
if(flag==0)
themdau(T,p->info);
p=p->next; 
}

}
void trudathuc(DaThuc &L,DaThuc &L1,DaThuc &H)
{
node *p,*q;
int flag;
p=L.head;
while(p!=NULL)
{
themdau(H,p->info);
p=p->next;
}
p=L1.head;
q=H.head;
while (q!=NULL)
{
p=L1.head;
while (p!=NULL)
{
if(p->info.somu==q->info.somu)
q->info.heso-=p->info.heso; 
p=p->next;
}
q=q->next;
}

p=L1.head;
while (p!=NULL) 
{
flag=0;
q=H.head;
while (q!=NULL)
{
if(q->info.somu==p->info.somu)
flag=1;
q=q->next;
}
if(flag==0)
{
p->info.heso*=-1;
themdau(H,p->info);
p->info.heso*=-1;
}
p=p->next; 
}

}
void nhandathuc(DaThuc &L,DaThuc &L1,DaThuc &Ti)
{
node *p,*q;
int flag;
p=L.head;
while(p!=NULL)
{
themdau(Ti,p->info);
p=p->next;
}
p=L1.head;
q=Ti.head;
while (q!=NULL)
{
p=L1.head;
while (p!=NULL)
{
q->info.heso*=p->info.heso; 
q->info.somu+=p->info.somu; 
p=p->next;
}
q=q->next; 
}
}
void xuatDaThuc(DaThuc L)
{
cout<<"\n";
node *p;
p=L.head;
while(p!=NULL)
{
cout<<(p->info).heso<<"x^"<<(p->info).somu;
if(p->next!=NULL)
cout<<"+";
p=p->next;
}
}
main()
{
DaThuc L,L1,T,H,Ti;
khoitao(L);
khoitao(L1);
khoitao(T);
khoitao(H);
khoitao(Ti);
DonThuc x;
nhapDaThuc(L);
cout<<"\n Da thuc can cong ";
nhapDaThuc(L1);
cout<<"\n Hai da thuc ";
xuatDaThuc(L);cout<<"\n";
xuatDaThuc(L1);
congdathuc(L,L1,T);
xuatDaThuc(T);
cout<<"\nDa thuc 1 tru da thuc 2";
trudathuc(L,L1,H);
xuatDaThuc(H);
cout<<"\n Da thuc tich \n";
nhandathuc(L,L1,Ti);
xuatDaThuc(Ti);
getch();
}