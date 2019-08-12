// Chương 6.
// Bài 4: Viết chương trình thực hiện tìm cây khung tối tiểu cho đồ thị G bằng thuật giải Prim (dựa trên phương pháp biểu diễn bằng ma trận kề).

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


#define MAX 100
// Khai báo ma trận bằng mảng 2 chiều.
int a[MAX][MAX];
int n; // Số đỉnh của đồ thị.
char vertex[MAX]; // Tên đỉnh.

void InitGraph()
{
	n = 0;
}

void InputGraphFromText()
{
	string line;
	ifstream myfile ("mtts1.txt");
	if (myfile.is_open())
	{
		myfile >> n;
		for (int i = 0; i < n; i++)
			myfile >> vertex[i];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				myfile >> a[i][j];
		}
	}
}

// Nhập ma trận kề của đồ thị.
void InputGraph()
{
	do{
		cout << "Nhap so dinh do thi n (n > 0): ";
		cin >> n;
		if (n < 0)
			cout << "Nhap sai roi! Nhap lai." << endl;
	} while (n < 0);
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap ten dinh: ";
		cin >> vertex[i];
		cout << "Nhap vao dong thu " << i + 1 << ": ";
		for (int j = 0; i < n; j++)
				cin >> a[i][j];
	}
}

// Xuất ma trận kề của đồ thị.
void OutputGraph()
{
	cout << setw(6) << left;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << setw(6) << left;
		cout << endl;
	}
}

// Khai báo tập E chứa các cạnh của đồ thị.
int E1[MAX];
int E2[MAX];
int wE[MAX];
int nE = 0; // Số phần tử của tập E.

// Khai báo tập T chứa các cạnh của đồ thị.
int T1[MAX];
int T2[MAX];
int wT[MAX];
int nT = 0; // Số phần tử của tập T.

int TonTai(int d, int D[], int nD)
{
	for (int i = 0; i < nD; i++)
		if (D[i] == d)
		{
			return 1;
		}
		return 0;
}

void XoaViTriE(int i)
{
	for (int j = i; i < nE; j++)
	{
		E1[j] = E1[j+1];
		E2[j] = E2[j+1];
		wE[j] = wE[j+1];
	}
	nE--;
}

void XoaCanhE(int u, int v)
{
	for (int i = 0; i < nE; i++)
		if(E1[i] == u && E2[i] == v)
		{
			XoaViTriE(i);
			break;
		}
}

void Prim(int s) // s là đỉnh bắt đầu.
{
	int u = s, min, d1, d2;
	while (nT < n - 1)
	{
		for (int v = 0; v < n; v++)
		if(a[u][v] != 0)
			if (TonTai(v, T2, nT) == 0)
			{
				E1[nE] = u;
				E2[nE] = v;
				wE[nE] = a[u][v];
				nE++;
			}

		for (int i = 0; i < nE; i++)
			if (TonTai(E2[i], T2, nT) == 0)
			{
				min = wE[i];
				d1 = E1[i];
				d2 = E2[i];
				break;
			}

		for (int i = 0; i < nE; i++)
			if (TonTai(E2[i], T2, nT) == 0)
				if ( min > wE[i])
				{
					min = wE[i];
					d1 = E1[i];
					d2 = E2[i];
				}

		T1[nT] = d1;
		T2[nT] = d2;
		wT[nT] = a[d1][d2];
		a[d1][d2] = 0;
		a[d2][d1] = 0;
		nT++;
		XoaCanhE(d1, d2);
		u = d2;
	}
}

void Output(bool VertexName)
{
	int tong = 0;
	for (int i = 0; i < nT; i++)
	{
		if (VertexName)
			cout << "("<<vertex[T1[i]] << "," << vertex[T2[i]] <<") = " << wT[i];
		else
			cout << "("<< T1[i] << "," << T2[i] <<") = " << wT[i];
		tong += wT[i];
	}
	cout << "Tong = " << tong;
}

int main()
{
	int choice = 0,x;
	system("cls");
	cout << "------------------- Bai tap chuong 6 - BTTH - Bai 4 ----------------------" << endl << endl;
	cout << "0. Khoi tao ma tran ke rong." << endl;
	cout << "1. Nhap ma tran ke tu file text." << endl;
	cout << "2. Nhap ma tran ke." << endl;
	cout << "3. Xuat ma tran ke." << endl;
	cout << "4. Tim cay khung toi thieu bang PRIM." << endl;
	cout << "5. Thoat." << endl;
	do
	{
		do{
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		if (choice < 0 || choice > 5)
			cout << "Nhap sai roi! Nhap lai." << endl;
		} while(choice < 0 || choice > 5);
		switch (choice)
		{
			case 0:
				InitGraph();
				cout << "Ban vua khoi tao danh sach ke rong thanh cong. " << endl;
				break;

			case 1:
				InputGraphFromText();
				cout << "Ban vua nhap danh sach ke tu file: " << endl;
				OutputGraph();
				break;

			case 2:
				InputGraph();
				break;

			case 3:
				OutputGraph();
				break;
		
			case 4:
				cout << "Vui long nhap dinh xuat phat: ";
				cin >> x;
				Prim(x);
				cout << "Cay khung toi thieu voi Prim: " << endl;
				Output(true);
				break;

			case 5:
				cout << "Good bye...!" << endl;
		}
	} while(choice != 5);
	system("pause");
	return 0;
}