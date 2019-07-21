//CHUONG 2 - BAI 10: STACK (DANH SACH LIEN KET DON)
#include<stdio.h>
#include<iostream>
using namespace std;

//CAU 10.1: Khai bao cau truc
struct Node
{
	int info;
	Node *link;
};

Node *sp;

//CAU 10.2: Khoi tao Stack rong
void Init_Empty()
{ 
	sp = NULL;
}

//CAU 10.3: Kiem tra Stack rong
int isEmpty()
{
	if (sp == NULL)
		return 1;
	else
		return 0;
}

//CAU 10.4: Them mot phan tu vao Stack
void Push(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}

//CAU 10.5: Lay mot phan tu ra khoi Stack
int Pop(int &x)
{
	if (sp != NULL)
	{
		Node *p = new Node;
		p = sp;
		x = p->info;
		sp = sp->link;
		delete p;

		return 1;
	}
	return 0;
}

//Xuat Stack
void Process_Stack()
{
	Node *p = new Node;
	p = sp;

	do
	{
		cout << p->info << "\t";
		p = p->link;
	} while (p != NULL);

	cout << endl;
}

int main()
{
	int choice, result, x;

	system("cls");

	cout << "---------- CHUONG 2 - BAI 10: STACK (DANH SACH LIEN KET DON) ----------" << endl;
	cout << "1. Khoi tao Stack rong" << endl;
	cout << "2. Kiem tra Stack rong " << endl;
	cout << "3. Them mot phan tu vao Stack" << endl;
	cout << "4. Lay mot phan tu ra khoi Stack" << endl;
	cout << "5. Xuat Stack" << endl;
	cout << "6. Thoat" << endl;

	do
	{
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			Init_Empty();
			cout << "Khoi tao Stack rong thanh cong!" << endl;
			cout << endl;
			break;
		case 2:
			result = isEmpty();
			if (result == 1)
				cout << "Stack dang rong!" << endl;
			else
				cout << "Stack khong rong" << endl;
			cout << endl;
			break;
		case 3:
			cout << "Nhap gia tri phan tu muon them vao Stack: ";
			cin >> x;
			Push(x);
			cout << "Them phan tu thanh cong!" << endl;
			cout << "Danh sach hien tai la: " << endl;
			Process_Stack();
			cout << endl;
			break;
		case 4:
			result = Pop(x);
			if (result == 1)
			{
				cout << "Phan tu lay ra khoi Stack co gia tri x = " << x << "." << endl;
				cout << "Danh sach hien tai la:" << endl;
				Process_Stack();
			}
			else
				cout << "Khong the lay phan tu ra khoi Stack!" << endl;
			cout << endl;
			break;
		case 5:
			cout << "Danh sach hien tai la:" << endl;
			Process_Stack();
			cout << endl;
			break;
		case 6:
			cout << "Goodbye...!" << endl;
			cout << endl;
			break;
		default:
			break;
		}
	} while (choice != 6);

	system("pause");

	return 0;
}