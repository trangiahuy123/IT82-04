// Bài 4: Quản lý một danh sách có thứ tự, số phần tử khá lớn, biến động. Mỗi phần tử có kiểu int. (Dùng cấu trúc danh sách liên kết đơn).
// 4.1. Khai báo cấu trúc danh sách.
// 4.2. Viết thủ tục khởi tạo danh sách rỗng.
// 4.3. Viết thủ tục thêm một phần tử vào danh sách (thêm một phần tử vào vị trí phù hợp trong danh sách đã có thứ tự. Lưu ý: Không xếp thứ tụ danh sách.
// 4.4. Viết thủ tục xuất các phần tử trong danh sách.
// 4.5. Viết thủ tục tìm một phần tử trong danh sách (lưu ý: danh sách đã có thứ tự).
// 4.6. Viết thủ tục tìm một phần tử trong danh sách. Nếu tìm thấy, xóa phần tử này (lưu ý: danh sách đã có thứ tự).

#include<stdio.h>
#include<iostream>
using namespace std;

// 4.1 Khai báo cấu trúc danh sách.
struct Node
{
	int info;
	Node *link;
};
Node *first;

// 4.2. Viết thủ tục khởi tạo danh sách rỗng.
void Init()
{
	first = NULL;
}

// 4.3. Viết thủ tục thêm một phần tử vào danh sách (thêm một phần tử vào vị trí phù hợp trong danh sách đã có thứ tự
// Hàng kiểm tra tăng.
bool Check_Up()
{
	bool kq = false;
	Node *p, *q;
	if (first != NULL)
	{
		p = first;
		q = first;
		while (p ->link != NULL)
		{
			q = p;
			p = p->link;
			if (q->info < p->info)
				kq = true;
			else
			{
				return kq;
			}
		}	
	}
	return kq;
}

// Hàng kiểm tra giảm.
bool Check_Down()
{
	bool kq = false;
	Node *p, *q;
	if (first != NULL)
	{
		p = first;
		q = first;
		while (p ->link != NULL)
		{
			q = p;
			p = p->link;
			if (q->info > p->info)
				kq = true;
			else
			{
				return kq;
			}
		}
	}
	return kq;
}

int Insert(int x)
{
	bool tang, giam;
	Node *p,*q;
	tang = Check_Up();
	giam = Check_Down();
	p = new Node;
	p->info = x;
	q = first;
	if (first != NULL)
	{
		if (tang == true)
		{
			cout << "Tang: " <<tang << endl;
			while (q->link != NULL && q->info > x)
			{
				q = q->link;
			}
			p->link = q->link;
			q->link = p;
		}
		else
			if( giam == true)
		{
				cout <<"Giam: "<< giam << endl;
				while (q->link != NULL && q->info < x)
				{
					q = q->link;
				}
				p->link = q->link;
				q->link = p;
		}
			else
			{
				// Thêm vào đầu danh sách
				p->link = first;
				first = p;
			}
	}
	else {
		// Trường hợp first = NULL
		p->link = first;
		first = p;
	}
	return 1;
}

// 4.4. Viết thủ tục xuất các phần tử trong danh sách.
void  Process_List()
{
	Node *p;
	p = first;
	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->link;
	}
	cout << endl;
}

// 4.5. Viết thủ tục tìm một phần tử trong danh sách (lưu ý: danh sách đã có thứ tự).
Node *Search(int x)
{
	Node *p;
	p = first;
	while (p != NULL && p->info != x )
		p = p->link;
	return p;
}

int Search_Delete(int x)
{
	// Kiểm tra rỗng
	if (first == NULL)
		return 0;
	else
	{
		Node *p, *q;
		p = first;
		q = first;
		while (q!=NULL && q->info != x)
		{
			p = q;
			q = q->link;
		}
		// Kiểm tra tìm thấy hay không.
		if (q == NULL)
		{
			return -1;
		}
		else
		{
			// Kiểm tra đầu.
			if (q == first)
			{
				first = q->link;
				delete q;
				return 1;
			}
			else
				// Kiểm tra cuối.
				if (q->link == NULL)
				{
					p->link = q->link;
					delete q;
					return 1;
				}
				else
				{
					p->link = q->link;
					return 1;
				}
		}
	}
}

int main()
{
	int x, i;
	Node *p;
	int choice = 0;
	system("cls");
	cout << "--------Bai tap chuong 2 - BTTH So 2 - Bai 4---------" << endl << endl;
	cout << "1. Xin chao." << endl;
	cout << "2. Khoi tao DSLK don rong." << endl;
	cout << "3. Them mot phan tu vao dau DSLK don." << endl;
	cout << "4. Xuat cac phan tu trong DSLK don." << endl;
	cout << "5. Tim mot phan tu trong DSLK don." << endl;
	cout << "6. Tim va xoa phan tu trong DSLK don." << endl;
	cout << "7. Thoat." << endl;
	do
	{
		do{
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		if (choice <= 0 || choice > 7)
			cout << "Nhap sai roi! Nhap lai." << endl;
		} while(choice <= 0 || choice > 7);
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
			cout << "Nhap vao phan tu muon them: ";
			cin >> x;
			i = Insert(x);
			if (i == 1)
				cout << "Them thanh cong.\n";
			cout << "Danh sach sau khi them:\n";
			Process_List();
			break;

		case 4:
			cout << "Xuat danh sach: \n";
			Process_List();
			break;

		case 5: 
			cout << "Nhap vao gia tri x can tim: \n";
			cin >> x;
			p = Search(x);
			if (p != NULL)
			{
				cout << "Tim thay x.\n";
			}
			else
				cout << "Khong tim thay x\n";
			break;
		
		case 6:
			cout << "Nhap vao gia tri x can tim va xoa: \n";
			cin >> x;
			i = Search_Delete(x);
			if (i == 0)
				cout << "Danh sach rong, khong the tim va xoa gia tri.\n";
			else
				if (i == -1)
					cout << "Khong tim thay x.\n";
				else
				{
					cout << "Tim thay x va xoa thanh cong x.\n";
					cout << "Danh sach sau khi xoa x.\n";
					Process_List();
				}
			break;

		case 7:
			cout<< "Goodbye!" << endl;
			default:
				break;
		}
	} while(choice != 7);
	system("pause");
	return 0;
}