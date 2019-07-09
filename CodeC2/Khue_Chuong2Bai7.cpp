// Bai 7, chuong 2: DS han che, hang doi, QUEUE
// QUEUE su dung DS DAC
#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 100

// Cau 7.2 Khoi tao QUETE rong
void init(int a[], int &front, int &rear) {
	front = -1;
	rear = -1;
}

// Cau 7.3 kiem tra QUETE rong
int isEmpty( int a[],int &front, int &rear)
{
	if(front == rear)
		return 1;
	else 
		return 0;
}

// Cau 7.4 kiem tra QUETE day
int isFull( int a[], int &front, int &rear)
{
	if((front == 0 && rear == MAX-1) || (front - rear ==1))
		return 1;
	else
		return 0;
}

// Cau 7.5 Them phan tu vao QUETE
int Push(int a[], int &front, int &rear, int x) {
	if( rear - front == MAX -1)
		return 0;
	else {
		if(front == -1)
			front =0;
		if (rear == MAX -1) {
			for (int i = front ; i<= rear; i++){
				a[i-front] = a[i];
			}
			rear = MAX -1 - front;
			front = 0;
		}
		a[++rear] = x;
		return 1;
	}
	return 0;

}

// Cau 7.6 lay mot phan tu ra khoi QUETE
int Pop(int a[], int &front, int &rear, int &x) {
	if (front == -1)
		return 0;
	else {
		x = a[front ++];
		if (front > rear) {
			front = -1;
			rear = -1;
		}
		return 1;
	}
	return 0;
}

// Xuat QUETE
void Process_quete( int a[], int f, int r)
{
	cout<<"f="<<f<<"\t r="<<r<<endl;
	if( f<=r && f!= -1)
	{
		cout<<"<--   ";
		for( int i=f; i<r+1; i++)
		{
			cout<<a[i]<<"   ";
		}
		cout<<"<--"<<endl;
	}
}

int main()
{
	int a[MAX];
	int choice, f,r, x, i;
	system("cls");
	cout<<"------BAI TAP 7, CHUONG 1 , QUETE (HANG DOI)------"<<endl;
	cout<<"1. Khoi tao QUETE rong"<<endl;
	cout<<"2. Them phan tu vao QUETE"<<endl;
	cout<<"3. Lay phan tu ra khoi QUETE"<<endl;
	cout<<"4. Kiem tra QUETE co rong hay khong"<<endl;
	cout<<"5. Kiem tra QUETE co day hay khong"<<endl;
	cout<<"6. Xuat QUETE"<<endl;
	cout<<"7. Thoat"<<endl;
	do
	{
		cout<<"\n Vui long chon so de thuc hien: ";
		cin>> choice;
		switch(choice)
		{
		case 1:
			init(a, f, r);
			cout<<" Ban vua khoi tao QUETE rong thanh cong!\n";
			break;
		case 2:
			init(a, f, r);
			cout<<" Vui long nhap gia tri x=";
			cin>>x;
			i=Push(a, f, r,x);
			cout<<" QUETE sau khi them la: ";
			Process_quete(a, f,r);
			break;
		case 3:
			i = Pop(a, f, r,x );
			cout<<" Phan tu lay ra tu QUETE la x ="<<x<<endl;
			cout<<"QUETE sau khi lay ra la: ";
			Process_quete(a,f,r);
			break;
		case 4:
			i= isFull(a, f, r);
			if(i==0)
				cout<<"QUETE chua day!"<<endl;
			else
				cout<<" QUETE da day!"<<endl;
			break;
		case 5:
			i= isEmpty(a, f, r);
			if(i==0)
				cout<<"QUETE khong rong!"<<endl;
			else
				cout<<"QUETE rong!"<<endl;
			break;
		case 6:
			cout<<" QUETE hien tai la: ";
			Process_quete(a, f, r);
			break;
		case 7:
			cout<<"---Goodbye---"<<endl;
			break;
		default: 
			break;
		}
				
	}while(choice!=7);
	system("pause");
	return 0;
}

