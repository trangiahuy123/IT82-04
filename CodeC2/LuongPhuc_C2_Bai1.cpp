#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 100
int a[MAX];
int n;

//1.2 nhap ds
void input(int a[], int &n)
{
	cout << "Nhap vao so luong ptu cua danh sach:";
	cin >> n;
	for (int i = 0; i<n; i ++)
	{
		cout << "Nhap a[" << i << "] = ";
		cin >> a[i];
	}
}

//1.3 xuat ds
void output(int a[], int n)
{
	for(int i = 0; i < n; i ++)
		cout << a[i] << "\t";
	cout << endl;
}

//1.4 tim phan tu
int Search(int a[], int n, int x)
{
	int i =0;
	while (i < n && a[i] != x)
	{
		i++;
		if (i == n)
			return -1;
	}
	return i;
}

//1.5 them cuoi ds
int Insert_last(int a[], int &n, int x)
{
	if(n < MAX)
	{
		a[n] = x;
		n++;
		return 1;
	}
	else
		return 0;
}

//1.6 xoa cuoi ds
int Delete_last(int a[], int &n)
{
	if(n > 0 )
	{
		n--;
		return 1;
	}
	return 0;
}


//1.7 xoa ptu bat ki
int Delete(int a[], int &n, int i)
{
	if(i >= 0 && i < n)
	{
		for(int j = i; j < n-1; j++)
		{
			a[j] = a[j + 1];
		}
		n --;
		return 1;
	}
	return 0;
}

//1.8 tim 1 ptu trong ds, neu tim thay xoa ptu do
int SearchAndDelete(int a[], int &n, int x)
{
	for(int i = 0; i < n; i++)
	{
		if(a[i] == x)
		{
			Delete(a, n, i);
			return 1;

		}
	}
	return 0;
}



int main()
{
	int choice = 0;
	int x, i;
	system("cls");
	cout << "-----CHUONG2, BAI1, DANH SACH LIEN KET-----" << endl;
	cout << "1. Nhap danh sach" << endl;
	cout << "2. Xuat danh sach" << endl;
	cout << "3. Tim ptu co gia tri x trong ds" << endl;
	cout << "4. Them ptu vao cuoi ds" << endl;
	cout << "5. Xoa ptu tai cuoi ds" << endl;
	cout << "6. Xoa ptu tai vi tri i" << endl;
	cout << "7. Tim ptu voi gtri x va xoa neu co" << endl;
	cout << "8. Thoat " << endl;

	do
	{
		cout << " Vui long chon so de thuc hien";
		cin >> choice;
		switch(choice)
		{
		case 1:
			input(a, n);
			cout << " Nhap ds thanh cong!\n";
			break;
		case 2:
			cout << " Ds vua nhap la:\n";
			output(a, n);
			break;
		case 3:
			cout << " Vui long nhap x can tim: ";
			cin >> x;
			i = Search(a, n ,x);
			if(i == -1)
				cout << " Khong co " << x << endl;
			else
				cout << " Tim thay tai vi tri i=" << i << endl;
			break;
		case 4:
			cout << " Vui long nhap x can them vao cuoi ds: ";
			cin >> x;
			i = Insert_last(a, n, x);
			if(i == 0)
				cout << " Danh sach day, khong the them " << x << endl;
			else
			{
				cout << " Da them ptu x=" << i << " vao cuoi ds" << endl;
				cout << " Ds sau khi them la: ";
				output(a, n);
			}
			break;
		case 5:
			i = Delete_last(a, n);
			if (i > 0)
			{
				cout << " Xoa thanh cong! " << endl;
				cout << " DS sau khi xoa ptu cuoi la: \n";
				output(a, n);
			}
			else
				cout << " Danh sach rong, ko co ptu nao!" << endl;
			break;
		case 6:
			cout << " Vui long nhap vi tri can xoa i=";
			cin >> i;
			i = Delete(a, n ,i);
			if(i == 1)
			{
				cout << " Xoa thanh cong!" << endl;
				cout << " Ds sau khi xoa la: \n";
				output(a, n);
			}
			else
				cout << " khong co phan tu nao de xoa!" << endl;
			break;
		case 7:
			cout << " Vui long nhap gia tri can xoa x=";
			cin >> x;
			i = SearchAndDelete(a, n, x);
			if(i == 1)
			{
				cout << " Xoa thanh cong ptu co gia tri x=" << x << endl;
				cout << " Danh sach sau khi xoa la: \n";
				output(a, n);
			}
			else
				cout << " Ko co ptu nao de xoa!!" << endl;
			break;
		case 8:
			cout << "Goodbye!";
			break;
		default:
			break;
		}
	}while(choice != 8);
	system("pause");
	return 0;
}
