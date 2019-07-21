//CHUONG 2 - BAI 1: DANH SACH DAC
#include <stdio.h>
#include <iostream>
using namespace std;

//CAU 1.1: Khai bao cau truc danh sach
const int MAX = 100;
int a[MAX];
int n;

//CAU 1.2: Nhap danh sach
void Input(int a[], int &n)
{
	cout << "Nhap so luong phan tu cua danh sach: ";
	cin >> n;
	do
	{
		if ((n > 0) || (n <= MAX))
		{
			cout << "Nhap cac phan tu cho danh sach: " << endl;
			for (int i = 0; i < n; i++)
			{
				cout << "a[" << i << "] = ";
				cin >> a[i];
			}
		}
		if (n <= 0)
			cout << "So luong phan tu khong dat yeu cau (n > 0)" << endl << "Yeu cau nhap lai!" << endl;
		else
			if (n > MAX)
				cout << "So luong phan tu qua muc cho phep (toi da 100 phan tu)" << endl << "Yeu cau nhap lai!" << endl;
	} while ((n <= 0) || (n > MAX));
}

//CAU 1.3: Xuat danh sach
void Output(int a[], int n)
{
	cout << "Danh sach hien tai la: " << endl;
	for (int i = 0; i < n; i++)
	{
		if (i == n - 1)
			cout << a[i] << endl;
		else
			cout << a[i] << "\t";
	}
}

//CAU 1.4: Tim phan tu x trong danh sach
int Search(int a[], int n, int x)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (a[i] != x)
			continue;
		else
			break;
	}

	if (i == n)
		return -1;
	return i;
}

//CAU 1.5: Them phan tu cuoi danh sach
void Insert_last(int a[], int &n, int x)
{
	if (n == MAX)
		cout << "Danh sach da day, khong the them!" << endl;
	else
	{
		a[n] = x;
		n++;
	}
	Output(a, n);
}

//CAU 1.6: Xoa phan tu cuoi danh sach
void Delete_last(int a[], int &n)
{
	for (int i = 0; i < n; i++)
	{
		if (i == (n - 1))
		{
			n--;
		}
	}
	Output(a, n);
}

//CAU 1.7: Xoa phan tu tai vi tri i
void Delete(int a[], int &n, int x)
{
	if ((x >= 0) || (x < n))
	{
		for (int i = x; i < n; i++)
		{
			if (x == (n - 1))
			{
				Delete_last(a, n);
				break;
			}
			else
				a[i] = a[i + 1];
		}
		n--;
	}
}

//CAU 1.8: Tim phan tu va xoa phan tu vua tim
void Search_Delete(int a[], int &n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
			Delete(a, n, i);
	}
	Output(a, n);
}

int main()
{
	int choice = 0;
	int x, i;

	system("cls");

	cout << "----------- CHUONG 1 - BAI TAP 1 - DANH SACH DAC -----------" << endl;
	cout << "1. Nhap danh sach" << endl;
	cout << "2. xuat danh sach" << endl;
	cout << "3. Tim vi tri cua phan tu co gia tri x" << endl;
	cout << "4. Them phan tu cuoi danh sach" << endl;
	cout << "5. Xoa phan tu cuoi danh sach" << endl;
	cout << "6. Xoa phan tu tai vi tri i" << endl;
	cout << "7. Tim phan tu voi gia tri x va xoa (neu co)" << endl;
	cout << "8. Thoat" << endl;

	do
	{
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			Input(a, n);
			cout << "Nhap danh sach thanh cong!" << endl;
			break;
		case 2:
			Output(a, n);
			break;
		case 3:
			cout << "Nhap gia tri x can tim: ";
			cin >> x;
			i = Search(a, n, x);
			if (i != -1)
				cout << "Tim thay gia tri " << x << " tai vi tri i = " << i << "." << endl;
			else
				cout << "Khong tim thay gia tri " << x << " trong danh sach!" << endl;
			break;
		case 4:
			cout << "Nhap gia tri phan tu muon them vao cuoi danh sach: ";
			cin >> x;
			Insert_last(a, n, x);
			cout << "Them thanh cong!" << endl;
			break;
		case 5:
			Delete_last(a, n);
			cout << "Xoa phan tu cuoi danh sach thanh cong!" << endl;
			break;
		case 6:
			cout << "Nhap vi tri muon xoa phan tu: ";
			cin >> i;
			Delete(a, n, i);
			Output(a, n);
			cout << "Xoa thanh cong!" << endl;
			break;
		case 7:
			cout << "Nhap gia tri phan tu can xoa: ";
			cin >> x;
			Search_Delete(a, n, x);
			cout << "Xoa thanh cong!" << endl;
			break;
		case 8:
			cout << "Goodbye!" << endl;
			break;
		default:
			break;
		}
	} while (choice != 8);

	system("pause");
	return 0;
}