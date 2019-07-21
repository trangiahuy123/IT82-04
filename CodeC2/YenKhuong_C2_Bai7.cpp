//CHUONG 2 - BAI 7: QUEUE (DANH SACH DAC)
#include<stdio.h>
#include<iostream>
using namespace std;

//CAU 7.1: Khai bao Queue
const int MAX = 100;
int a[MAX];
int front, rear;

//CAU 7.2: Khoi tao Queue rong
void Init_Empty(int a[], int &front, int &rear)
{
	front = -1;
	rear = -1;
}

//CAU 7.3: Kiem tra Queue rong
int isEmpty(int a[], int &front, int &rear)
{
	if (front == rear)
		return 1;
	else
		return 0;
}

//CAU 7.4: Kiem tra Queue day
int isFull(int a[], int &front, int &rear)
{
	if (((front == 0) && (rear == (MAX - 1))) || (front - rear == 1))
		return 1;
	else
		return 0;
}

//CAU 7.5: Them mot phan tu vao Queue
int Push(int a[], int &front, int &rear, int x)
{
	int result = isFull(a, front, rear);

	if (result != 1) /* Neu Queue chua day */
	{
		if (front == -1)
			front = 0;
		if (rear == (MAX - 1)) /* Su dung phuong phap tinh tien Queue */
		{
			for (int i = front; i < rear; i++)
				a[i - front] = a[i];
			rear = MAX - 1 - front;
			front = 0;
		}
		rear = rear + 1;
		a[rear] = x;

		return 1;
	}
	else
		return 0;
}

//CAU 7.6: Xoa mot phan tu trong Queue
int Pop(int a[], int &front, int &rear, int &x)
{
	int result = isEmpty(a, front, rear);

	if (result != 1)
	{
		front = front + 1;
		x = a[front - 1];
		if (front > rear) /* Queue co 1 phan tu */
		{
			front = -1;
			rear = -1;
		}
		return 1;
	}
	else
		return 0;
}

//CAU 7.7: Xuat Queue
void Process_Queue(int a[], int front, int rear)
{
	cout << "front = " << front << "\t" << "rear = " << rear << endl;
	if ((front <= rear) && (front != -1))
	{
		cout << "<--" << "\t";
		for (int i = front; i <= rear; i++)
				cout << a[i] << "\t";
		cout << "<--" << endl;
	}
}

int main()
{
	int choice, x, result;
	int front, rear;

	system("cls");

	cout << "---------- CHUONG 2 - BAI 7: QUEUE (DANH SACH DAC) --------" << endl;
	cout << "1. Khoi tao Queue rong" << endl;
	cout << "2. Kiem tra Queue rong" << endl;
	cout << "3. Kiem tra Queue day" << endl;
	cout << "4. Them phan tu vao Queue" << endl;
	cout << "5. Lay phan tu ra khoi Queue" << endl;
	cout << "6. Xuat Queue" << endl;
	cout << "7. Thoat" << endl;

	do
	{
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			Init_Empty(a, front, rear);
			cout << "Khoi tao Queue rong thanh cong!" << endl;
			cout << endl;
			break;
		case 2:
			result = isEmpty(a, front, rear);
			if (result == 1)
				cout << "Queue dang rong!" << endl;
			else
				cout << "Queue khong rong!" << endl;
			cout << endl;
			break;
		case 3:
			result = isFull(a, front, rear);
			if (result == 1)
				cout << "Queue da day!" << endl;
			else
				cout << "Queue chua day!" << endl;
			cout << endl;
			break;
		case 4:
			cout << "Nhap phan tu muon them vao Queue: ";
			cin >> x;
			result = Push(a, front, rear, x);
			if (result == 1)
			{
				cout << "Them phan tu vao Queue thanh cong!" << endl;
				Process_Queue(a, front, rear);
			}
			else
				cout << "Them phan tu that bai!" << endl;
			cout << endl;
			break;
		case 5:
			result = Pop(a, front, rear, x);
			if (result == 1)
			{
				cout << "Lay phan tu ra khoi Queue thanh cong!" << endl;
				cout << "Phan tu lay ra khoi Queue co gia tri x = " << x << "." << endl;
				Process_Queue(a, front, rear);
			}
			else
				cout << "Lay phan tu that bai!" << endl;
			cout << endl;
			break;
		case 6:
			cout << "Danh sach Queue hien tai la:" << endl;
			Process_Queue(a, front, rear);
			cout << endl;
			break;
		case 7:
			cout << "Goodbye...!" << endl;
			break;
		default:
			break;
		}	
	} while (choice != 7);

	system("pause");
	return 0;
}