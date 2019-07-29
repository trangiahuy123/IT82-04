//Bài 8, chương 2: Dùng STACK chuyển tử hệ thập sang hệ nhị
#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 100
//Khai báo cấu trúc Stack
int a [MAX];
int sp;

//Khởi tạo Stack rỗng
void init (int a[], int &sp)
{
	sp=-1;
}

//Kiểm tra ngăn xếp rỗng
int isEmpty(int a[], int sp)
{
	if(sp = -1)
		return 1;
	return 0;
}

//Kiểm tra ngăn xếp đầy
int isFull(int a[], int sp)
{
	if (sp == MAX -1)
		return 1;
	return 0;
}

//Thêm phần tử vào ngăn xếp
int Push(int a[], int &sp, int x)
{
	if(sp < MAX -1)
	{
		a[++sp] =x;
		return 1;
	}
	return 0;
}

//Xóa 1 phần tử
int Pop(int a[], int &sp, int &x)
{
	if (sp != -1)
	{
		x=a[sp--];
		return 1;
	}
	return 0;
}

//chuyen he 10 sang he 2
void ConvertDectoBin(int d)
{
    int du;
    while(d!=0)
    {
        du = d%2;
        Push(a,sp,du);
        d = d/2;
    }
}

//In hệ 2
void printBin()
{
    int x;
    while(sp!=-1)
    {
        Pop(a, sp, x);
        cout<<x;
    }
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

void he2( int a[], int *sp, int x)
{
	int i = 0;
	while ( x> 0) {
		i = x%2;
		push(i);
		x = x/2;
	}
	while(sp != NULL) {
		Pop(i);
		cout<<i;
	}
}

int main()
{
	int a[MAX];
	int choice,sp,x,i,d;
	system("cls");
	cout<<"------- BAI TAP 8: CHUYEN HE 10 SANG HE 2 (STACK) -------"<<endl;
	cout<<"1. Khoi tao Stack rong"<<endl;
	cout<<"2. Them phan tu vao STACK"<<endl;
	cout<<"3. Lay phan tu ra khoi STACK"<<endl;
	cout<<"4. Kiem tra STACK co rong hay khong"<<endl;
	cout<<"5. Kiem tra STACK co day hay khong"<<endl;
	cout<<"6. Xuat STACK"<<endl;
	cout<<"7. Chuyen he 10 sang he 2"<<endl;
	cout<<"8. Chuyen thu"<<end;
	cout<<"9. Thoat"<<endl;
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
            cout<<"nhap so he 10: ";
            cin>>d;
            ConvertDectoBin(d);
            cout<<"he 2 cua "<<d<<" la: ";
            printBin();
            cout<<endl;
            break;
		case 8:
			cout<<" nhap x: "<<endl;
			cin>>x;
			he2(x);
			cout<<"he 2 la : "<<endl;
			/*printBin()*/
			cout<<endl;
			break;
		case 9:
			cout<<"Goodbye...!"<<endl;
			break;
		default:
			break;
		}
	}
	while (choice !=9);
	system("pause");
	return 0;
}
