// Bài 3: Quản lý môt danh sách có số phần tử khá lớn, biến động. Mỗi phần tử có kiểu int (dùng cấu trúc danh sách liên kết đơn).
// 3.1. Khai báo cấu trúc danh sách.
// 3.2. Viết thủ tục khởi tạo danh sách rỗng.
// 3.3. Viết thủ tục xuất các phần tử trong danh sách.
// 3.4. Viết thủ tục tìm một phần tử trong danh sách.
// 3.5. Viết thủ tục thêm một phần tử vào đầu danh sách.
// 3.6. Viết thủ tục xóa một phần tử đầu danh sách.
// 3.7. Viết thủ tục thêm một phần tử vào cuối danh sách.
// 3.8. Viết thủ tục xóa một phần tử cuối danh sách.
// 3.9 Viết thủ tục tìm một phần tử trong danh sách. Nếu tìm thấy, hãy xóa phần tử này.

#include<iostream>
using namespace std;

// 3.1. Khai báo cấu trúc danh sách.
struct Node
{
	int info;
	Node *link;
};
Node *first;

// 3.2. Viết thủ tục khởi tạo danh sách rỗng.
void Init()
{
	first = NULL;
}

// 3.3. Viết thủ tục xuất các phần tử trong danh sách.
void Process_List()
{
	Node *p;
	p = first;
	while (p != NULL)	
	{
		cout << p->info << endl;
		p = p->link;
	}
}

// 3.4. Viết thủ tục tìm một phần tử trong danh sách.
Node * Search(int x)
{
	Node *p=first;
	while ((p!=NULL) && (p ->info != x))
		p=p->link;
	return p;
}

// 3.5. Viết thủ tục thêm một phần tử vào đầu danh sách.
void Insert_First(int x)
{
	Node *p;
	p = new Node;
	p->info = x;
	p->link = first;
	first = p;
}

// 3.6. Viết thủ tục xóa một phần tử đầu danh sách.
int Delete_First()
{
	if (first != NULL)
	{
		Node *p = first;
		first = first->link;
		delete p;
		return 1;
	}
	return 0;
}

// 3.7. Viết thủ tục thêm một phần tử vào cuối danh sách.
void Insert_Last(int x)
{
	Node *p;
	p = new Node;
	p->info = x;
	p->link = NULL;
	if (first == NULL)
	{
		first = p;
	}
	else
	{
		Node *q = first;
		while (q->link != NULL)
		{
			q = q->link;
		}
		q->link = p;
	}
}

// 3.8. Viết thủ tục xóa một phần tử cuối danh sách.
int Delete_Last()
{
	if (first != NULL)
	{
		Node *p, *q;
		p = first;
		q = NULL;
		if (p != NULL)
			while (p->link != NULL)
			{
				q = p;
				p = p->link;
			}
			if (p != first)
				q->link = NULL;
			else
				first = NULL;
			delete p;
			return 1;
	}
	return 0;
}

//3.9 Viết thủ tục tìm một phần tử trong danh sách. Nếu tìm thấy, hãy xóa phần tử này.
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

// 3.10. Từ danh sách trên hãy chuyển thành danh sách có thứ tự.
// Hàm hoán vị
void Swap(Node *a, Node *b)
{
	int t = a->info;
	a->info = b->info;
	b->info = t;
}

void Sort_Asc()
{
	Node *p, *q, *min;
	p = first;
	while (p != NULL)
	{
		min = p;
		q = p->link;
		while (q != NULL)
		{
			if (q->info < min->info)
				min = q;
			q = q->link;
		}
		Swap(min, p);
		p = p->link;
	}
}
void Sort_Desc()
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
	int choice;
	int x, i;
	Node *p;
	system("cls");
	cout << "--------Bai tap chuong 2 - BTTH So 2 - Bai 3---------" << endl << endl;
	cout << "1. Xin chao." << endl;
	cout << "2. Khoi tao DSLK don rong." << endl;
	cout << "3. Xuat cac phan tu trong DSLK don." << endl;
	cout << "4. Tim mot phan tu trong DSLK don." << endl;
	cout << "5. Them mot phan tu vao dau DSLK don." << endl;
	cout << "6. Xoa mot phan tu dau DSLK don." << endl;
	cout << "7. Them mot phan tu vao cuoi DSLK don." << endl;
	cout << "8. Xoa phan tu cuoi DSLK don." << endl;
	cout << "9. Tim va xoa phan tu trong DSLK don." << endl;
	cout << "10. Sap xep DSLK don cho co thu tu (tang dan)." << endl;
	cout << "11. Sap xep DSLK don cho co thu tu (giam dan)." << endl;
	cout << "12. Thoat." << endl;
	do
	{
		do{
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		if (choice <= 0 || choice > 11)
			cout << "Nhap sai roi! Nhap lai." << endl;
		} while(choice <= 0 || choice > 11);
		switch (choice)
		{
		case 1:
			cout << "Hello you, <3" << endl;
			break;

		case 2:
			Init();
			cout << "Ban vua khoi tao DSLK don thanh cong. \n";
			break;

		case 3:
			cout << "Danh sach hien tai la: ";
			Process_List();
			break;

		case 4:
			cout << "Vui long nhap gia tri x can tim: ";
			cin >> x;
			p = Search(x);
			if(p != NULL)
			{
				cout << "Tim thay phan tu co gia tri x = " << x << endl;
			}
			else
				cout << "Khong tim thay phan tu co gia tri x = " << x << endl;
			break;

		case 5:
			cout << "Vui long nhap gia tri x = ";
			cin >> x;
			Insert_First(x);
			cout << "Danh sach sau khi them la: \n";
			Process_List();
			break;

		case 6:
			i = Delete_First();
			if(i == 0)
				cout << "Danh sach rong, khong the xoa." << endl;
			else
			{
				cout << "Da xoa thanh cong phan tu dau cua ds." << endl;
				cout << "Danh sach sau khi xoa la: ";
				Process_List();
			}
			break;

		case 7:
			cout << "Vui long nhap gia tri x = ";
			cin >> x;
			Insert_Last(x);
			cout<< "Danh sach sau khi them la: \n";
			Process_List();
			break;

		case 8:
			i = Delete_Last();
			if (i == 0)
				cout << "Danh sach rong, khong the xoa." << endl;
			else
			{
				cout << "Da xoa thanh cong phan tu cuoi."<< endl;
				cout << "Danh sach sau khi xoa la: ";
				Process_List();
			}
			break;

		case 9:
			cout << "Vui long nhap gia tri x can tim: ";
			cin >> x;
			i = SearchAndDelete(x);
			if(i == 1)
			{
				cout << "Tim thay x va xoa thanh cong." << endl;
				cout << "Danh sach sau khi xoa la: ";
				Process_List();
			}
			else
				cout <<" Khong tim thay phan tu co gia tri x ="<<x<<" !!"<<endl;
				break;

		case 10:
			Sort_Asc();
			cout << "Danh Sach sau khi sap xep tang dan la: ";
			Process_List();
			break;
		case 11:

			Sort_Desc();
			cout << "Danh Sach sau khi sap xep giam dan la: ";
			Process_List();
			break;

		case 12:
			cout<< "Goodbye!" << endl;
		default:
			break;
		}
	} while(choice != 12);
	system("pause");
	return 0;
}