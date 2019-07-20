#include <iostream>
#include <stdio.h>
using namespace std;

//3.1 khai bao cau truc ds
struct Node
{
	int info;
	Node *link;
};

//3.2 tao ds rong
Node *first;
void init()
{
	first = NULL;
}

//3.3 xuat cac ptu trong ds
void Process_list()
{
	Node *p;
	p = first;
	while(p != NULL)
	{
		cout << p->info << "\t";
		p = p->link;
	}
	cout << endl;
}

//3.4 tim ptu trong ds
Node *Search(int x)
{
	Node *p = first;
	while((p!= NULL) && (p->info != x))
		p = p->link;
	return p;
}

//3.5 them 1 ptu vao dau ds
void Insert_first(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = first;
	first = p;
}

//3.6 xoa 1 ptu dau ds
int Delete_first()
{
	if(first != NULL)
	{
		Node *p = first;
		first = first->link;
		delete p;
		return 1;
	}
	return 0;
}

//3.7 them 1 ptu cuoi ds
void Insert_last(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = NULL;
	if(first == NULL)
		first = p;
	else
	{
		Node *q = first;
		while(q->link != NULL)
			q = q->link;
		q->link = p;
	}
}

//3.8 xoa 1 ptu cuoi ds
int Delete_last()
{
	if(first != NULL)
	{
		Node *p, *q;
		p = first;
		q = NULL;
		if(p != NULL)
			while(p->link != NULL)
			{
				q = p;
				p = p->link;
			}
			if(p != first)
				q->link = NULL;
			else
				first = NULL;
			delete p;
			return 1;
	}
	return 0;
}

//3.9 tim va xoa 1 ptu 
int SearchAndDelete(int x)
{
	if(first != NULL)
	{
		Node *p, *q;
		p = first;
		q = first;
		while(p->info != x && p->link != NULL)
		{
			q = p;
			p = p->link;
		}

		if(p != first && p->link != NULL)
		{
			if(p->link != NULL)
				q->link = p->link;
			else
				q->link = NULL;
			delete p;
			return 1;
		}
		else if(p == first)
		{
			first = p->link;
			delete p;
			return 1;
		}
		else if(p->link == NULL && p->info == x)
		{
			q->link = NULL;
			delete p;
			return 1;
		}
		else
			return 0;
	}
	return 0;
}
//3.10 sap xep ds theo thu tu

void swap(Node *a, Node *b)
{
	int t = a->info;
	a->info = b->info;
	b->info = t;
}

void Sort()
{
	Node *p, *q, *min;
	p = first;
	while(p != NULL)
	{
		min = p;
		q = p->link;
		while(q !=NULL)
		{
			if(q->info < min->info)
				min = q;
			q = q->link;
		}
		swap(min, p);
		p = p->link;
	}
}
void SortDesc()
{
	Node *p, *q, *min;
	p = first;
	while(p != NULL)
	{
		min = p;
		q = p->link;
	}
	swap(min, p);
	p = p->link;
}
int main()
{
	int choice = 0;
	int x, i;
	Node* p;
	system("cls");
	cout << " -------- BAI TAP 3, CHUONG 2, DANH SACH LIEN KET DON --------" << endl;
	cout << "1. Khoi tao DSLK DON rong" << endl;
	cout << "2. Them phan tu vao dau DSLKD" << endl;
	cout << "3. Them phan tu vao cuoi DSLKD" << endl;
	cout << "4. Xoa phan tu dau DSLKD" << endl;
	cout << "5. Xoa phan tu cuoi DSLKD" << endl;
	cout << "6. Xuat DSLKD" << endl;
	cout << "7. Tim phan tu voi gia tri x trong DSLKD" << endl;
	cout << "8. Tim phan tu voi gia tri x va xoa no neu co" << endl;
	cout << "9. Sap xep DSLKD tang dan" << endl;
	cout << "10. Sap xep DSLKD giam dan" << endl;
	cout << "11. Thoat" << endl;
	do
	{
		cout <<"\nVui long chon so thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			init();
			cout << " Ban vua khoi tao DSLK Don thanh cong\n ";
			break;
		case 2:
			cout << " Vui long nhap gia tri x=";
			cin >> x;
			Insert_first(x);
			cout << " Ds sau khi them la: ";
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
			i = Delete_first();
			if(i == 0)
				cout << " Danh sach rong, khong the xoa " << x << endl;
			else
			{
				cout << " Da xoa thanh cong ptu dau cua ds " << endl;
				cout << " Danh sach sau khi xoa la: ";
				Process_list();
			}
			break;
		case 5:
			i = Delete_last();
			if(i == 0)
				cout << " Ds rong, khongthe xoa" << x << endl;
			else
			{
				cout << " Da xoa thanh cong ptu cuoi "<< endl;
				cout << " Danh sach sau khi xoa la: ";
				Process_list();
			}
			break;
		case 6:
			cout << " Ds hien tai la:";
			Process_list();
			break;
		case 7:
			cout << " Vui long nhap gia tri can tim x=";
			cin >> x;
			p = Search(x);
			if(p != NULL)
			{
				cout << " Tim thay ptu co gia tri x=" << x << endl;
			}
			else
				cout << " Khong tim ptu xo gia tri x=" << x << endl;
			break;
		case 8:
			cout << " Vui long nhap gia tri can tim x=";
			cin >> x;
			i = SearchAndDelete(x);
			if(i == 1)
			{
				cout << " Tim thay x ="<<x<<" va xoa thanh cong"<<endl;
				cout<< " Danh sach sau khi xoa la: ";
				Process_list();
			}
			else
				cout<<" Khong tim thay phan tu co gia tri x ="<<x<<" !!"<<endl;
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