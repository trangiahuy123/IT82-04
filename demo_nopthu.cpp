#include <iostream>
using namespace std;

# define MAX 100
int a[MAX];
int n;

//1.1 nhap ds
void input(int a[], int n)
{
	for (int i = 0; i<n; i ++)
	{
		cout << "Nhap a[" << i << "] = ";
		cin >> a[i];
	}
}

//1.2 xuat ds
void output(int a[], int n)
{
	for(int i = 0; i < n; i ++)
		cout << a[i] << endl;	
}

//1.3 tim phan tu
int Search(int a[], int n, int x)
{
	int i =0;
	while (i < n && a[i] != x)
		i++;
	if (i == n)
		return -1;
	return i;
}

//1.4 them cuoi ds
int insert_last(int a[], int &n, int x)
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

//1.5 xoa cuoi ds
int Delete_last(int a[], int &n, int i)
{
	if(i >= 0 )
	{
		n--;
		return 1;
	}
	return 0;
}


//1.6 xoa ptu bat ki
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

int main()
{
	int choice = 0;
	int x, i;
	system("cls");
	cout << "-----CHUONG1, DANH SACH LIEN KET-----" << endl;
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
			break;
		default:
			break;
		}
	}while(choice != 8);
	system("pause");
	return 0;
}
