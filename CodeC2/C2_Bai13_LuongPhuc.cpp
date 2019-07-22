#include <iostream>
#include <iostream>
#include <stdio.h>
using namespace std;
//13.1
#define MAX 100
int a[MAX], b[MAX];

//13.2
void nhap(int a[], int &n)
{
	for(int i = n; i >= 0; i--)
	{
		cout << "\nNhap he so cua bac " << i << ": ";
		cin >> a[i];
	}
}

//13.4
void xuat(int a[], int n)
{
	for(int i = n; i>0; i--)
	{
		cout << a[i] << "*x^" << i << " + ";
	}
	cout << a[0] << endl;
}

//13.5
void tong(int a[], int n1, int b[], int n2, int c[], int n3)
{
	int		max=n1 > n2 ? n1 : n2;
	n3=max;
	for (int i=max;i>=0;i--)
	{
		c[i]=b[i]+a[i];
	}
}

//13.6
void hieu(int a[], int n1, int b[], int n2, int c[], int n3)
{
	int	max = n1 > n2 ? n1 : n2;
	n3 = max;
	for (int i=max;i>=0;i--)
	{
		c[i]=b[i]-a[i];
	}
}

//13.7
void tich(int a[], int n1, int b[], int n2, int c[], int n3)
{
	n3 = n1 + n2;
	for(int i=0; i<=n1; i++)
		for(int j=0; j<=n2; j++)
			c[i+j] += a[i] * b[j];
}

//13.8
void thuong(int a[],int n1,int b[],int n2)
{
	int chia;
	if(n1==n2 || n1>n2)
		chia = a[n1]/b[n2];
	else
		chia = b[n2]/a[n1];
	if(n1==n2)
		cout << "Thuong 2 da thuc la: " << chia << endl;
	else
		cout << "Thuong 2 da thuc la: " << chia << "*x\n";
}

int main()
{
	int choice, a[MAX], b[MAX], c[MAX], n1, n2, n3;
	for (int i=0;i<10;i++)
	{
		a[i]=0;
		b[i]=0;
		c[i]=0;
	}
	cout << "-----------BAI TAP 13-CHUONG 2-DANH SACH DAC-DA THUC----------\n";
	cout << "1. Nhap da thuc thu nhat\n";
	cout << "2. Nhap da thuc thu hai\n";
	cout << "3. Xuat 2 da thuc\n";
	cout << "4. Tinh tong 2 da thuc\n";
	cout << "5. Tinh hieu 2 da thuc\n";
	cout << "6. Tinh tich 2 da thuc\n";
	cout << "7. Tinh thuong 2 da thuc\n";
	cout << "8. Thoat\n";
	do{
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			cout << "\nNhap da thuc thu nhat:\n";
			do{
				cout << "\nNhap so bac cua da thuc: ";
				cin >> n1;
				if(n1 < 1)
					cout << "\nBac da thuc phai >=1, vui long nhap lai!";
			}while(n1 < 1);
			nhap(a, n1);
			break;
		case 2:
			cout << "\nNhap da thuc thu hai:\n";
			do{
				cout << "\nNhap so bac cua da thuc: ";
				cin >> n2;
				if(n2 < 1)
					cout << "\nSo bac cua da thuc phai >= 1. Xin kiem tra lai!";
			}while(n2 < 1);
			nhap(b, n2);
			break;
		case 3:
			cout << "\nXuat da thuc thu nhat:\n";
			xuat(a, n1);
			cout << "\nXuat da thuc thu hai:\n";
			xuat(b, n2);
			break;
		case 4:
			n3=n1 > n2 ? n1 : n2;
			cout << "Tong 2 da thuc: ";
			tong(a, n1, b, n2, c, n3);
			xuat(c, n3);
			break;
		case 5:
			n3=n1 > n2 ? n1 : n2;
			cout << "Hieu 2 da thuc: ";
			hieu(a, n1, b, n2, c, n3);
			xuat(c, n3);
			break;
		case 6:
			n3 = n1 + n2;
			cout << "Tich 2 da thuc: ";
			tich(a, n1, b, n2, c, n3);
			xuat(c, n3);
			break;
		case 7:
			thuong(a, n1, b, n2);
			break;
		case 8:
			cout << "\nGood bye!!\n";
			break;
		default:
			break;
		}
	}while(choice!=8);
	system("pause");
	return 0;
}