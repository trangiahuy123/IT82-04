//chuong 2- bai 12
#include <iostream>
#include <stdio.h>
using namespace std;
struct Node
{
	int info;
	Node *next,*previous;
};
// khai báo danh sách
Node *first, *last;
//12.2 Viết hàm thủ tục khởi tạo danh sách rỗng
void init()
{
	first = NULL;
	last = NULL;
}
//12.3 Xuất các phần tử trong danh sách
void Process_list()
{
	Node *p;
	p = first;
	while (p!=NULL)
	{
		cout<< p->info <<endl;
		p=p->next;
	}
}
//12.4 viết hàm thủ tục thêm 1 phần từ vào đầu danh sách
void Insert_first (int x)
{
	Node *p;
	p = new Node;
	p ->info = x;
	p ->next;
	p ->previous = NULL;
	if(first != NULL)
		first ->previous = p;
	else 
		last = p;
	first = p;
}
//12.5 Viết hàm thủ tục thêm vào cuối danh sách
void Insert_Last(int x)
{
	Node *p;
	p = new Node;
	p->info= x;
	p->next = NULL;
	p ->previous = last;
	if (last!= NULL)
		last ->next = p;
	else 
		first = p;
	last = p;
}
//12.6 Viết hàm thủ tục xóa phần tử đầu danh sách
int Delete_first()
{
	if ( first != NULL)
	{
		Node *p = first;
		first = first ->next;
		delete p;
		if (first != NULL)
			first ->previous = NULL;
		else 
			last = NULL;
		return 1;
	}
	return 0;
}
//12.7 Viết hàm thủ tục xóa phần tử cuối danh sách 
int Delete_last()
{
	if ( last != NULL)
	{
		Node *p = last;
		last = last->previous;
		if (last != NULL)
			last ->next = NULL;
		else 
			first = NULL;
		delete p;
		return 1;
	}
	return 0;
}
//12.8 Viết hàm thủ tục tìm 1 phần tử trong danh sách , nếu tìm thấy xóa phần tử này
//Tim x trong danh sach
Node *search(int x)
{
	Node *p=first;
	while((p!=NULL)&&(p->info!=x))
		p=p->next;
	return p;
}

//Tim gia gi gan bang lon hon x

Node *search2(int x)
{
	Node *p = first, *q = first;
	int min = first->info;
	if(p == NULL)
		return NULL;
	while(p != NULL)
	{
		if(p->info == x)
			return p;
		else if((p ->info > x) && (p->info < min))
			{
				min = p->info;
				q = p;
			}
		p = p->next;
	}
	return q;
}
//Chen y vao truoc  phan tu x
int insert(int x, int y)
{
	Node*q=search2(x);
	if(q!=NULL)
	{
		if(q==last)
			Insert_first(y);
		else
		{
			Node *p=new Node;
			p->info=y;
			p->previous=q->previous;
			(q->previous)->next=p;
			q->previous=p;
			p->next=q;
		}
		return 1;
	}
	return 0;
}
int delete_x (int x)
{
	Node*q=search(x);
	if(q!=NULL)
	{
		if(q==first)
		{
			if(Delete_first())
			return 1;
		}
		else if(q==last)
		{
			if(Delete_last())
				return 1;
		}
		else
			{
				Node *p=q->previous;
				Node *r=q->next;
				p->next=r;
				r->previous=p;
				delete q;
			}
	}
	return 0;
}
int main()
{
	init();
	int choice;
	cout<<"---------BAI TAP CHUONG 2, BAI 12-------------"<<endl;
	cout<< "1. Khoi tao danh sach";
	cout<<"\n2. Duyet danh sach";
	cout<<"\n3. Them phan tu vao dau danh sach\n";
	cout<<"\n4.Them phan tu vao cuoi danh sach";
	cout<<"\n5. Xoa dau danh sach";
	cout<<"\n6. Xoa cuoi danh sach";
	cout<<"\n7. Tim va xoa phan tu x trong danh sach";
	cout<<"\n8. Chen y truoc phan tu x( hoac co gia tri gan voi x nhat va lon hon x)";
	cout<<"\n9.Thoat"<<endl;
	do{
		cout<<"Vui long chon so de thuc hien: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				init();
				cout<<"khoi tao thanh cong\n";
				break;
			case 2:
				cout<<"Danh sach: ";
				Process_list();
				break;
			case 3:
				int a;
				cout<<"nhap gia tri can them: ";
				cin >> a;
				Insert_first(a);
				cout<<"Danh sach sau khi them la: ";
				Process_list();
				break;
			case 4:
				int b;
				cout<<"nhap gia tri can them: ";
				cin >> b;
				Insert_Last(b);
				cout<<"Danh sach sau khi them la: ";
				Process_list();
				break;
			case 5:
				if(Delete_first()==1)
				{
					cout<<"Danh sach sau khi xoa la: ";
					Process_list();
				}
				else
					cout<< "xoa khong thanh cong"<<endl;
				break;
			case 6:
				if(Delete_last()==1)
				{
					cout<<"Danh sach sau khi xoa la: ";
					Process_list();
				}
				else
					cout<< "xoa khong thanh cong"<<endl;
				break;
			case 7:
				int t;
				cout<< "Nhap gia tri phan tu can xoa: ";
				cin >> t;
				if(delete_x(t))

					cout<<" xoa phan tu "<<t<<"khong thanh cong vi khong co trong danh sach\n";
				else
				{
					cout<<"Danh sach sau khi xoa la: ";
					Process_list();
				}
				break;
			case 8:
				int x, y;
				cout<<"nhap cac phan tu can tim: ";
				cin>>x;
				cout<<"Nhap gia tri phan tu can chen: ";
				cin>>y;
				cout<<y<<" se duoc chen truoc "<<search2(x)->info<<endl;
				if(insert(x,y)==1)
				{
					cout<<"Danh sach sau khi chen la: ";
					Process_list();
				}
				else
					cout<<"chen khong thanh cong vi khong tim thay gia tri"<<x<<endl;
				break;
			case 9:
				cout<<"GOOD BYE...!!!"<<endl;
			default:
				break;
		}
	}while(choice !=9);
	system("pause");
	return 0;
}