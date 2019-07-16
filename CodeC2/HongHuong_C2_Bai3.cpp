//Bai 3, Chuong 1: Danh sach lien ket don
#include <stdio.h>
#include <iostream>
using namespace std;

//Cau 3.1: Khai bao cau truc danh sach
struct Node
{
	int info;
	Node *link;
};
Node *first;

//Cau 3.2: Khoi tao danh sach rong
void Init()
{
	first = NULL;
}

//Cau 3.3: Xuat cac phan tu trong DS
void Process_list()
{
	Node *p;
	p = first;
	while (p != NULL)
	{
		cout<< p->info<<"\t";
		p=p->link;
	}
	cout<<endl;
}

//Cau 3.4:Tim mot phan tu trong DS
Node *Search(int x)
{
	Node *p=first;
	while (p!=NULL && p->info != x)
	{
		p=p->link;
	}
	return p;
}

//Cau 3.5: Them phan tu vao dau DS
void Insert_first(int x)
{
	Node *p;
	p = new Node;
	p->info = x;
	p->link = first;
	first = p;
}

//Cau 3.6: Xoa phan tu dau danh sach
int Delete_first()
{
	if(first != NULL)
	{
		Node *p =first;
		first = first->link;
		delete p;
		return 1;
	}
	return 0;
}

//Cau 3.7: them phan tu cuoi danh sach
void Insert_last(int x)
{
	Node *p;
	p =new Node;
	p->info = x;
	p->link = NULL;
	if(first==NULL)
	{
		first = p;
	}
	else
	{
		Node *q = first;
		while (q->link != NULL)
		{
			q=q->link;
		}
		q->link=p;
	}
}


//Cau 3.8: Xoa phan tu cuoi danh sach
int Delete_last()
{
	if (first != NULL)
	{
		Node *p, *q;
		p = first;
		q =first;
		while (p->link !=NULL)
		{
			q = p;
			p = p->link;
		}
		if(p!=first)
		{
			q->link =NULL;
		}
		else first = NULL;
		delete p;

		return 1;
	}
	return 0;
}

//Cau 3.9: Tim phan tu trong DS, roi xoa phan tu do neu co
int SearchAndDelete(int x)
{
	if (first != NULL)
	{
		Node *p,*q;
		p = first;
		q =first;
		while (p->info != x)
		{
			q = p;
			p = p->link;
		}
		if(p!=first && p!=NULL)
		{
			if(p->link != NULL)
				q->link = p->link;
			else
				q->link = NULL;
			delete p;
			return 1;
		}
		else if(p==first)
		{
			first = p->link;
			delete p;
			return 1;
		}
		else
			return 0;
	}
	return 0;
}

//Cau 3.10: Sap xep danh sach co thu tu tang dan DSLKDon
// ham doi gia tri cua 2 phan tu
void swap(Node *a, Node *b)
{
	int t = a->info;
	a->info = b->info;
	b->info = t;
}
//3.10:sap xep danh sach co thu tu tang dan
// su dung Selection_sort
void Sort()
{
	Node *p, *q, *min;
	p=first;
	while (p!=NULL)
	{
		min = p;
		q=p->link;
		while (q!=NULL)
		{
			if (q->info < min->info)
				min = q;
			q=q->link;
		}
		swap(min, p);
		p=p->link;
	}
}
//3.10:sap xep danh sach co thu tu giam dan
void SortDesc()
{
	Node *p, *q, *min;
	p=first;
	while (p!=NULL)
	{
		min = p;
		q=p->link;
		while (q!=NULL)
		{
			if (q->info > min->info)
				min = q;
			q=q->link;
		}
		swap(min, p);
		p=p->link;
	}
}

int main()
{
	int choice = 0;
	int x,i;
	Node* p;
	system("cls");
	cout<<"------- BAI TAP 3, CHUONG 1, DANH SACH LIEN KET DON -------"<<endl;
	cout<<"1. Khoi tao DSLK DON " <<endl;
	cout<<"2. Them phan tu vao dau DSLK DON"<<endl;
	cout<<"3. Them phan tu vao cuoi DSLK DON"<<endl;
	cout<<"4. Xoa phan tu vao dau cua DSLK DON"<<endl;
	cout<<"5. Xoa phan tu vao cuoi cua DSLK DON"<<endl;
	cout<<"6. Xuat DSLK DON" <<endl;
	cout<<"7. Tim mot phan tu gia tri x trong DSLK DON"<<endl;
	cout<<"8. Tim mot phan tu gia tri x va xoa no neu co" <<endl;
	cout<<"9. Sap xep DSLK DON tang dan"<<endl;
	cout<<"10. Sap xep DSLK DON giam dan"<<endl;
	cout<<"11. Thoat" <<endl;
	do
	{
		cout<<"\nVui long chon so de thuc hien: ";
		cin>> choice;
		switch(choice)
		{
		case 1:
			Init();
			cout<<"Ban vua khoi tao DSLK DON thanh cong! \n";
			break;
		case 2:
			cout<< "Vui long nhap gia tri x= ";
			cin>>x;
			Insert_first(x);
			cout<<"DS sau khi them la: ";
			Process_list();
			break;
		case 3:
			cout<<"Vui long nhap gia tri x= ";
			cin>>x;
			Insert_last(x);
			cout<<"DS sau khi them la: ";
			Process_list();
			break;
		case 4:
			i = Delete_first();
			if(i==0)
				cout<<"DS rong, khong the xoa!"<<x<<endl;
			else
			{
				cout<<"Da xoa thanh cong phan tu dau cua DSLK DON! "<<endl;
				cout<<"DS sau khi xoa la: ";
				Process_list();
			}
			break;
		case 5:
			i = Delete_last();
			if(i==0)

				cout<<"DS rong, khong the xoa!"<<x<<endl;
			else
			{
				cout<<"Da xoa thanh cong phan tu cuoi cua DSLK DON! "<<endl;
				cout<<"DS sau khi xoa la: ";
				Process_list();
			}
			break;
		case 6:
			cout<<" DS hien tai la: ";
			Process_list();
			break;
		case 7:
			cout<<"Vui long nhap gia tri can tim x= ";
			cin>>x;
			p = Search (x);
			if(p!=NULL)
			{
				cout<<"Tim thay phan tu co gia tri x= "<<endl;
			}
			else
				cout<<"khong tim thay phan tu co gia tri x="<<x<<"!"<<endl;
			break;
		case 8:
			cout<<"vui long nhap gia tri can tim x= ";
			cin>>x;
			i= SearchAndDelete(x);
			if(i==1)
			{
				cout<<"tim thay x= "<<x<<"va da xoa thanh cong"<<endl;
				cout<<"Danh sach sau khi xoa la: ";
				Process_list();
			}
			else
				cout<<"khong tim thay phan tu co gia tri x="<<x<<"!"<<endl;
			break;
		case 9:
			Sort();
			cout <<"Danh Sach sau khi sap xep tang dan la: ";
			Process_list();
			break;
		case 10:
			SortDesc();
			cout <<"Danh Sach sau khi sap xep giam dan la: ";
			Process_list();
			break;

		case 11:
			cout<< "GoodBye.....!" <<endl;
			break;
		default:
			break;
		}
	}
	while(choice!=11);
	system("pause");
	return 0;
}