//CHUONG 2 - BAI 11: QUEUE (DANH SACH LIEN KET)
#include<stdio.h>
#include<iostream>
using namespace std;

//CAU 11.1: Khai bao cau truc
struct Node
{
	int info;
	Node *link;
};

Node *front, *rear;

//CAU 11.2: Khoi tao Queue rong
void Init_Empty()
{
	front = NULL;
	rear = NULL;
}

//CAU 11.3: Kiem tra Queue rong
int isEmpty()
{
	if (front == NULL)
		return 1;
	else
		return 0;
}

//CAU 11.4: Them mot phan tu vao Queue
void Push(int x)
{
	int result = isEmpty();

	Node *p = new Node;
	p->info = x;
	p->link = NULL;

	if (result == 0)
	{
		rear->link = p;
		rear = p;
	}
	else
	{
		front = p;
		rear = p;
	}
}

//CAU 11.5: Lay mot phan tu ra khoi Queue
int Pop(int &x)
{
	int result = isEmpty();

	if (result == 0)
	{
		Node *p = new Node;
		p = front;
		x = p->info;
		front = front->link;
		if (front == NULL) /* Truong hop Queue chi co 1 phan tu */
			rear = NULL;
		delete p;

		return 1;
	}
	else
		return 0;
}

void Process_Queue()
{
	int result = isEmpty();

	if (result == 0)
	{
		Node *p = new Node;
		p = front;
		cout << "<---" << "\t";
		do
		{
			cout << p->info << "\t";
			p = p->link;
		} while (p != NULL);
		cout << "<---" << endl;
	}
}

int main()
{
	int choice, result, x;

	system("cls");

	cout << "---------- CHUONG 2 - BAI 11: QUEUE (DANH SACH LIEN KET) ----------" << endl;
	cout << "1. Khoi tao Queue rong" << endl;
	cout << "2. Kiem tra Queue rong" << endl;
	cout << "3. Them mot phan tu vao Queue" << endl;
	cout << "4. Lay mot phan tu ra khoi Queue" << endl;
	cout << "5. Xuat Queue" << endl;
	cout << "6. Thoat" << endl;

	do
	{
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			Init_Empty();
			cout << "Khoi tao Queue rong thanh cong!" << endl;
			cout << endl;
			break;
		case 2:
			result = isEmpty();
			if (result == 1)
				cout << "Queue dang rong!" << endl;
			else
				cout << "Queue khong rong!" << endl;
			cout << endl;
			break;
		case 3:
			cout << "Nhap gia tri phan tu muon them vao Queue: ";
			cin >> x;
			Push(x);
			cout << "Them phan tu vao Queue thanh cong!" << endl;
			cout << "Danh sach hien tai la: " << endl;
			Process_Queue();
			cout << endl;
			break;
		case 4:
			result = Pop(x);
			if (result == 1)
			{
				cout << "Lay phan tu ra khoi Queue thanh cong!" << endl;
				cout << "Phan tu vua duoc lay ra co gia tri x = " << x << endl;
				cout << "Danh sach hien tai la:" << endl;
				Process_Queue();
			}
			else
				cout << "Khong the lay phan tu ra khoi Queue!" << endl;
			cout << endl;
			break;
		case 5:
			cout << "Danh sach hien tai la:" << endl;
			Process_Queue();
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