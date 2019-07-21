//CHUONG 2 - BAI 5: STACK (DANH SACH DAC)
#include<stdio.h>
#include<iostream>
using namespace std;

//CAU 5.1: Khai bao cau truc danh sach
const int MAX = 100;
int a[MAX];
int sp;

//CAU 5.2: Tao Stack rong
void Init_Empty(int a[], int &sp)
{
	sp = -1;
}

//CAU 5.3: Kiem tra Stack rong
int isEmpty(int a[], int sp)
{
	if (sp == -1)
		return 1;
	else
		return 0;
}

//CAU 5.4: Kiem tra Stack day
int isFull(int a[], int sp)
{
	if (sp == (MAX - 1))
		return 1;
	else
		return 0;
}

//CAU 5.5: Them mot phan tu vao Stack
int Push(int a[], int &sp, int x)
{
	if (sp < (MAX - 1)) /* Neu Stack chua day */
	{
		sp = sp + 1;
		a[sp] = x;

		return 1;
	}
	else
		return 0;
}

//CAU 5.6: Lay mot phan tu ra khoi Stack
int Pop(int a[], int &sp, int &x)
{
	if (sp != -1) /* Neu Stack khong rong */
	{
		sp = sp - 1;
		x = a[sp + 1];

		return 1;
	}
	else
		return 0;
}

//XUAT STACK
void Process_Stack(int a[], int sp)
{
	cout << "Danh sach hien tai la:" << endl;
	for (int i = 0; i <= sp; i++)
	{
		if (i == sp)
			cout << a[i] << endl;
		else
			cout << a[i] << "\t";
	}
}

int main()
{
	int sp, choice, result, x;

	system("cls");

	cout << "---------- CHUONG 2 - BAI 5: STACK (DANH SACH DAC) ----------" << endl;
	cout << "1. Khoi tao Stack rong" << endl;
	cout << "2. Kiem tra Stack rong" << endl;
	cout << "3. Kiem tra Stack day" << endl;
	cout << "4. Them mot phan tu vao Stack" << endl;
	cout << "5. Lay mot phan tu ra khoi Stack" << endl;
	cout << "6. Xuat Stack" << endl;
	cout << "7. Thoat" << endl;

	do
	{
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			Init_Empty(a, sp);
			cout << "Khoi tao Stack rong thanh cong!" << endl;
			cout << endl;
			break;
		case 2:
			result = isEmpty(a, sp);
			if (result == 1)
				cout << "Stack dang rong!" << endl;
			else
				cout << "Stack khong rong!" << endl;
			cout << endl;
			break;
		case 3:
			result = isFull(a, sp);
			if (result == 1)
				cout << "Stack da day!" << endl;
			else
				cout << "Stack chua day!" << endl;
			cout << endl;
			break;
		case 4:
			cout << "Nhap phan tu x muon them vao Stack: ";
			cin >> x;
			result = Push(a, sp, x);
			if (result == 1)
			{
				cout << "Them phan tu thanh cong!" << endl;
				Process_Stack(a, sp);
			}
			else
				cout << "Them phan tu that bai!" << endl;
			cout << endl;
			break;
		case 5:
			result = Pop(a, sp, x);
			if (result == 1)
			{
				cout << "Phan tu lay ra khoi Stack co gia tri x = " << x << "." << endl;
				Process_Stack(a, sp);
			}
			else
				cout << "Khong the lay phan ra khoi Stack!" << endl;
			cout << endl;
			break;
		case 6:
			Process_Stack(a, sp);
			cout << endl;
			break;
		case 7:
			cout << endl << "Goodbye...!" << endl;
			cout << endl;
			break;
		default:
			break;
		}
	} while (choice != 7);

	system("pause");
	return 0;
}