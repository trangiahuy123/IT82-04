// Bai 3 Chuong 1: Danh Sach lien ket don
#include <stdio.h>
#include <iostream>
using namespace std;

// Cau 3.1 Khai bao cau truc DS
struct Node 
{
	int info;
	Node *link;
};
Node* first;

//Cau3.2 Khoi tao Ds rong
void Init()
{
	first = NULL;
}

//Cau3.3 Xuat cac phan tu DS
void Process_list()
{
	Node*p;
	p = first;
	while (p != NULL)
	{
		cout << p->info << "\t";
		p = p->link;
	}
	cout<<endl;
}

// Cau 3.4 Tim mot phan tu trong DS
Node* Search(int x) {
	Node*p = first;
	while( p != NULL && p ->info != x){
		p = p->link;
	}
	return p;
}

// Cau 3.5 them phan tu vao dau DS
void Insert_first(int x)
{
	Node* p ;
	p= new Node;
	p->info =x;
	p ->link = first;
	first = p;
}

// Cau3.6 Xoa phan tu dau danh sach
int Delete_first()
{
	if(first != NULL){
		Node*p = first;
		first = first->link;
		delete p;
		return 1;
	}
	return 0;
}

// Cau 3.7 Them phan tu cuoi danh sach
void Insert_last(int x)
{
	Node*p;
	p = new Node;
	p->info =x;
	p->link = NULL;
	if(first == NULL)
	{
		first = p;
	}
	else
	{
		Node*q = first;
		while(q-> link !=NULL){
			q = q->link;
		}
		q->link =p;
	}
}

// Cau 3.8 Xoa phan tu cuoi danh sach
int Delete_last()
{
	if( first != NULL)
	{
		Node*p, *q;
		p =first ;
		q= first ;
		while (p->link != NULL)
		{
			q= p;
			p= p-> link;

		}
		if(p!= first){
			q->link = NULL;
		}
		else first =NULL;
		delete p;

		return 1;
	}
	return 0;
}

// Cau 3.9 Tim phan tu trong danh sach, roi xoa phan tu nay neu co
int SearchAndDelete( int x)
{
	if(first != NULL)
	{
		Node *p, *q;
		p = first;
		q = first;
		while(p->info != x)
		{
			q=p;
			p= p->link;
		}
		if (p != first && p != NULL)
		{
			if( p != first && p!= NULL)
			{
				if(p->link != NULL)
					q->link = p->link;
				else
					q->link = NULL;
				delete p;
				return 1;
			}
			else if( p== first)
			{
				first= p->link;
				delete p;
				return 1;
			}
			else
				return 0;
		}
		return 0;
	}
}

int main()
{
	int choice = 0;
	int x, i;
	Node*p;
	system("cls");
	cout<<"-----------BAI TAP 3, CHUONG 2, DANH SACH LIEN KET DON------------"<<endl;
	cout<<"1. Khoi tao DSLK Don rong "<<endl;
	cout<<"2. Them phan tu vao dau DS"<<endl;
	cout<<"3. Them phan tu vao cuoi DS"<<endl;
	cout<<"4. Xoa phan tu dau DS"<<endl;
	cout<<"5. Xoa phan tu cuoi DS"<<endl;
	cout<<"6. Xuat DSLK DON"<<endl;
	cout<<"7. Tim mot phan tu gia tri x trong DS"<<endl;
	cout<<"8. Tim phan tu gia tri x va gia no neu co"<<endl;
	cout<<"9. Thoat";
	do
	{
		cout<<"\n Vui long chon so de thuc hien: ";
		cin>> choice;
		switch(choice)
		{
		case 1:
			Init();
			cout<< " Ban vua khoi tao thanh cong DSLK DON!\n";
			break;
		case 2:
			cout << " Vui long nhap gia tri x =";
			cin>>x;
			Insert_first(x);
			cout <<" Danh sach sau khi them la : ";
			Process_list();
			break;
		case 3:
			cout << " Vui long nhap gia tri x=";
			cin>>x;
			Insert_last(x);
			cout<< "Danh sach sau khi them la: ";
			Process_list();
			break;
		case 4:
			i= Delete_first();
			if(i== 0)
				cout<<"Danh sach rong, khong the xoa!" <<x<<endl;
			else
			{
				cout <<"Da xoa thanh cong phan tu dau cua DSLK DON!"<<endl;
				cout<<" Danh sach sau khi xoa la:";
				Process_list();
			}
			break;
		case 5:
			i= Delete_last();
			if(i==0)
				cout<<"Danh sach rong, khong the xoa"<<x<<endl;
			else
			{
				cout<<"Da xoa thanh cong phan tu cuoi cua DSLK!"<<endl;
				cout<<"Danh sach sau khi xoa la:";
				Process_list();
			}

			break;
		case 6:
			cout<<"Danh sach hien tai la: ";
			Process_list();
			break;
		case 7:
			cout<<" Vui long nhap gia tri can tim x= ";
			cin>>x;
			p= Search(x);
			if(p!=NULL)
			{
				cout<<"Tim thay phan tu co gia tri x="<<x<<endl;

			}
			else
				cout<<"Khong tim thay phan tu co gia tri x ="<<x<<" !!"<<endl;
			break;
		case 8:
			cout<<"Vui long nhap gia tri can tim la x= ";
			cin>>x;
			i=SearchAndDelete(x);
			if(i==1)
			{
				cout<<" tim thay x ="<<x<<" va xoa thanh cong"<<endl;
				cout<< " Danh sach sau khi xoa la: ";
				Process_list();
			}
			else
				cout<<" KHong tim thay phan tu co gia tri x ="<<x<<" !!"<<endl;
				break;
		case 9:
			cout<< "GoodBye.....!" <<endl;
			break;
		default:
			break;
			
		}
	}while(choice!=11);
	system("pause");
	return 0;
}