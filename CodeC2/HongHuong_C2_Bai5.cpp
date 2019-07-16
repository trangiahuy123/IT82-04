//Bài 5, chương 2: DS hạn chế, ngăn xếp, STACK
#include <stdio.h>
#include <iostream>
using namespace std;

//Câu 5.1: Khai báo cấu trúc Stack
#define MAX 100

//Câu 5.2: Khởi tạo Stack rỗng
void init (int a[], int &sp)
{
	sp=-1;
}

//Câu 5.3: Kiểm tra ngăn xếp rỗng
int isEmpty(int a[], int sp)
{
	if(sp = -1)
		return 1;
	return 0;
}

//Câu 5.4: Kiểm tra ngăn xếp đầy
int isFull(int a[], int sp)
{
	if (sp == MAX -1)
		return 1;
	return 0;
}

//Câu 5.5: Thêm phần tử vào ngăn xếp
int Push(int a[], int &sp, int x)
{
	if(sp < MAX -1)
	{
		a[++sp] =x;
		return 1;
	}
	return 0;
}

//Câu 5.6: Xóa 1 phần tử
int Pop(int a[], int &sp, int &x)
{
	if (sp != -1)
	{
		x=a[sp--];
		return 1;
	}
	return 0;
}

//Xuat Stack
void Process_stack(int a[], int sp)
{
	for(int i = 0; i< sp+1; i++)
	{
		cout<<a[i]<<"\t";
	}
	cout<<endl;
}

int main()
{
	int a[MAX];
	int choice,sp,x,i;
	system("cls");
	cout<<"------- BAI TAP 5, CHUONG 1: STACK( NGAN XEP- DANH SACH ĐAC) -------"<<endl;
	cout<<"1. Khoi tao Stack rong"<<endl;
	cout<<"2. Them phan tu vao STACK"<<endl;
	cout<<"3. Lay phan tu ra khoi STACK"<<endl;
	cout<<"4. Kiem tra STACK co rong hay khong"<<endl;
	cout<<"5. Kiem tra STACK co day hay khong"<<endl;
	cout<<"6. Xuat STACK"<<endl;
	cout<<"7. Thoat"<<endl;
	do
	{
		cout<<"\n Vui long chon so de thuc hien: ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			init (a, sp);
			cout<<"Ban vua khoi tao STACK rong thanh cong!\n";
			break;
		case 2:
			cout<<"Vui long nhap gia tri x= ";
			cin>>x;
			i = Push(a, sp, x);
			cout<<"STACK sau khi them la: ";
			Process_stack(a,sp);
			break;
		case 3:
			i = Pop(a,sp,x);
		    cout<<"Phan tu lay ra tu Stack la: "<<x<<endl;
			cout<<"Stack sau khi lay ra la: ";
			Process_stack(a,sp);
			break;
		case 4: 
			i = isFull(a, sp);
			if(i==0)
				cout<<"Stack chua day!"<<x<<endl;
			else
				cout<<"Stack da day!"<<endl;
			break;
		case 5:
			i=isEmpty(a,sp);
			if(i==0)
				cout<<"Stack khong rong!"<<x<<endl;
			else
				cout<<"Stack rong!"<<endl;
			break;
		case 6:
			cout<<"Stack hien tai la: ";
			Process_stack(a,sp);
			break;
		case 7:
			cout<<"Goodbye...!"<<endl;
			break;
		default:
			break;
		}
	}
	while (choice !=7);
	system("pause");
	return 0;
}
