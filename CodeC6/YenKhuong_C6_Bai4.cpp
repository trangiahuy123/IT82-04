// CHUONG 6 - BAI 4: CAY BAO TRUM TOI TIEU (PRIM)
#include<stdio.h>
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

// Khai bao ma tran bang mang hai chieu
const int MAX = 100;
int a[MAX][MAX];
int n; // so dinh cua do thi
char vertex[MAX]; //ten dinh cua do thi

// Khoi tao do thi
void Init_Graph()
{
	n = 0;
}

// Nhap ma tran trong so tu FILE *TXT
void Input_Graph_fromText()
{
	string line;
	ifstream myfile("matrantrongso.txt");
	if (myfile.is_open())
	{
		myfile >> n;
		for (int i = 0; i < n; i++)
			myfile >> vertex[i];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				myfile >> a[i][j];
	}
}

// Nhap ma tran trong so
void Input_Graph()
{
	cout << "Nhap so dinh cua do thi: ";
	cin >> n;
	cout << "Nhap ten dinh: ";
	for (int i = 0; i < n; i++)
		cin >> vertex[i];
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap dong thu " << (i + 1) << ": ";
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	}
}

// Xuat ma tran trong so
void Output_Graph()
{
	cout << setw(5) << left;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << setw(5) << left;
		cout << endl;
	}
}

// Khoi tao tap E
int E1[MAX];
int E2[MAX];
int wE[MAX];
int nE = 0; // so phan tu cua tap E

// Khoi tao tap T
int T1[MAX];
int T2[MAX];
int wT[MAX];
int nT = 0; // so phan tu cua tap T

int TonTai(int d, int D[], int nD)
{
	for (int i = 0; i < nD; i++)
		if (D[i] == d)
			return 1;
	return 0;
}

void XoaViTriE(int i)
{
	for (int j = i; j < nE; j++)
	{
		E1[j] = E1[j + 1];
		E2[j] = E2[j + 1];
		wE[j] = wE[j + 1];
	}
	nE--;
}

void XoaCanhE(int u, int v)
{
	for (int i = 0; i < nE; i++)
		if ((E1[i] == u) && (E2[i] == v))
		{
			XoaViTriE(i);
			break;
		}
}

void Prim(int s) // s la dinh bat dau
{
	int u = s;
	int min, i, d1, d2;

	while (nT < (n - 1))
	{
		for (int v = 0; v < n; v++)
			if (a[u][v] != 0)
				if (TonTai(v, T2, nT) == 0)
				{
					E1[nE] = u;
					E2[nE] = v;
					wE[nE] = a[u][v];
					nE++;
				}

		for (i = 0; i < nE; i++)
			if (TonTai(E2[i], T2, nT) == 0)
			{
				min = wE[i];
				d1 = E1[i];
				d2 = E2[i];
				break;
			}

		for (i = 0; i < nE; i++)
			if (TonTai(E2[i], T2, nT) == 0)
				if (min > wE[i])
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
		{
			cout << endl;
			cout << "(" << vertex[T1[i]] << ", " << vertex[T2[i]] << ") = " << wT[i];
		}
		else
		{
			cout << endl;
			cout << "(" << T1[i] << ", " << T2[i] << ") = " << wT[i];
		}
		tong = tong + wT[i];
	}
	cout << endl << "Tong trong so: " << tong << endl;
}

int main()
{
	int choice, x, i;

	system("cls");

	cout << "---------- CHUONG 6 - BAI 4: CAY BAO TRUM TOI TIEU (PRIM) ----------" << endl;
	cout << "1. Khoi tao MA TRAN KE rong" << endl;
	cout << "2. Nhap MA TRAN KE tu file *txt" << endl;
	cout << "3. Nhap MA TRAN KE" << endl;
	cout << "4. Xuat MA TRAN KE" << endl;
	cout << "5. Tim CAY BAO TRUM TOI TIEU (su dung PRIM)" << endl;
	cout << "6. Thoat" << endl;

	do
	{
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			Init_Graph();
			cout << "Khoi tao MA TRAN KE thanh cong!" << endl;
			cout << endl;
			break;
		case 2:
			Input_Graph_fromText();
			cout << "Nhap MA TRAN KE tu file *txt thanh cong!" << endl;
			cout << "MA TRAN KE hien tai la: " << endl;
			Output_Graph();
			cout << endl;
			break;
		case 3:
			Input_Graph();
			cout << endl;
			break;
		case 4:
			Output_Graph();
			cout << endl;
			break;
		case 5:
			cout << "Nhap dinh bat dau: ";
			cin >> x;
			Prim(x);
			cout << "Cay khung toi tieu (su dung Prim) la:";
			Output(true);
			cout << endl;
			break;
		case 6:
			cout << "Goodbye...!" << endl;
			cout << endl;
			break;
		default:
			break;
		}
	} while (choice != 6);

	system("pause");

	return 0;
}