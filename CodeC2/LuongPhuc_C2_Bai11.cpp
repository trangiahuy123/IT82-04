#include <iostream>
#include <stdio.h>
using namespace std;

struct Node
{
	int info;
	Node *link;
};

Node *front, *rear;

//11.2 khoi tao Queue rong
void init()
{
	front = NULL;
	rear = NULL;
}

//11.3 kt Queue rong
int isEmpty()
{
	if(front == NULL)
		return 1;
	return 0;
}

//11.4 Them ptu vao Queue
void Push(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = NULL;
	if(rear != NULL)
	{
		rear->link = p;
	}
	else
		 front = p;
	rear = p;
}

//11.5 Xoa 1 ptu trong Queue
int Pop(int x)
{
	if(front != NULL)
	{
		Node *p = front;
		x = p->info;
		front = front->link;
		if(front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}

//xuat Queue
void Process_queue()
{
	if(front != NULL)
	{
		Node *p = front;
		cout << "<---   ";
		do
		{
			cout << p->info << "   ";
			p = p->link;
		}while(p != NULL);
		cout << "<-- " << endl;
	}
}
int main()
{
	int choice, x, i;
	system("cls");
	cout << "----BAI11, CHUONG 2, QUEUE -----" << endl;
	cout << "1. Khoi tao Queue rong" << endl;
	cout << "2. Them ptu vao Queue" << endl;
	cout << "3. Lay ptu khoi Queue "<< endl;
	cout << "4. Kiem tra Queue co rong hay ko " << endl;
	cout << "5. Xuat QUeue " << endl;
	cout << "6. Thoat " << endl;
	do
	{
		cout << "Vui long chon so de thuc hien: " << endl;
		cin >> choice;
		switch(choice)
		{
		case 1:
			init();
			cout << "Ban vua khoi tao Queue thanh cong!\n";
			break;
		case 2:
			cout << " Nhap gia tri x=";
			cin >> x;
			Push(x);
			cout << "Queue sau khi them la: ";
			Process_queue();
			break;
		case 3:
			Pop(x);
			cout << " Phan tu lay ra tu Queue la x=" << x << endl;
			cout << " Queue sau khi lay ra la: ";
			Process_queue();
			break;
		case 4:
			i = isEmpty();
			if(i == 0)
				cout << " Queue khong rong " << x << endl;
			else
				cout << " Queue rong "<< endl;
			break;
		case 5: 
			cout << " Queue hien tai la: " << endl;
			Process_queue();
			break;
		case 6 :
			cout << " Goodbye .... !" << endl;
			break;
		default:
			break;
		}
	}while(choice != 6);
	system("pause");
	return 0;
}