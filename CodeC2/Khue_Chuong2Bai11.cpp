// Bai 11, Chuong 2: DS han che, hang doi QUETE
// QUETE su dung DSLK
#include <stdio.h>
#include <iostream>
using namespace std;

// Cau 11.1 Khai bao cau truc QUETE
struct Node {
	int info;
	Node * link;
};
Node *front, *rear;

// Cau 11.2 Khoi tao QUETE rong
void init() {
	front = NULL;
	rear = NULL;
}

// Cau 11.3 Kiem trra QUETE
int isEmpty() {
	if(front == NULL)
		return -1;
	return 0;
}

// Cau 11.4 Them phan tu vao QUETE
void Push (int x) {
	Node *p = new Node;
	p->info = x;
	p->link = NULL;
	if(rear == NULL)
		front = p;
	else
		rear->link = p;

	rear = p;
}
 
// Cau 11.5 Lay phan tu ra khoi QUETE
int Pop( int &x) {
	if(front!= NULL){
		Node *p = front;
		front = p->link;
		x = p->info;
		if (front == NULL) {
			rear = NULL;
		}
		delete p;
		return 1;
	}
	return 0;
}

// Xuat QUETE
void Process_quete()
{
	if(front!=NULL)
	{
		Node *p = front;
		cout<<"<--   ";
		do
		{
			cout<<p->info<<"    ";
			p=p->link;
		} while (p!= NULL);
		cout<<"<---"<<endl;
	}
}

		
int main()
{
	int choice, x, i;
	system("cls");
	cout<<"-------BAI TAP 11, CHUONG 2, QUETE (HANG DOI - DSLK)--------"<<endl;
	cout<<"1. Khoi tao QUETE rong"<<endl;
	cout<<"2. Them phan tu vao QUETE "<<endl;
	cout<<"3. Lay phan tu ra khoi QUETE"<<endl;
	cout<<"4. Kiem tra QUETE co rong hay khong"<<endl;
	cout<<"5. Xuat QUETE"<<endl;
	cout<<"6. Thoat"<<endl;
	do
	{
		cout<<"\n Vui long chon so de thuc hien ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			init();
			cout<<" Ban vua khoi tao QUETE rong thanh cong!\n";
			break;
		case 2:
			cout<<" Vui long nhap gia tri x= ";
			cin>>x;
			Push(x);
			cout<<"QUETE sau khi them la: ";
			Process_quete();
			break;
		case 3:
			Pop(x);
			cout<< "Phan tu lay ra tu QUETE la x="<<x<<endl;
			cout<<" QUETE sau khi lay ra la: ";
			Process_quete();
			break;
		case 4:
			i = isEmpty();
			if(i==0)
				cout<<" QUETE khong rong! "<<x<<endl;
			else
				cout<<"QUETE rong !"<<endl;
			break;
		case 5:
			cout <<" QUETE hien tai la: ";
			Process_quete();
			break;
		case 6:
			cout<<"Goodbye...!"<<endl;
			break;
		default:
			break;
		}
	} while(choice!=6);
	system("pause");
	return 0;
}