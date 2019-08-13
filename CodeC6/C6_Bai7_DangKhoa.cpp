// Bài 7: Thực hiện biểu diễn G (bằng ma trận kề) lên trên máy tính và
//đặt tên là do_thi_1.txt (dạng file TEXT) sau đó thực hiện viết chương trình tìm cây khung tối thiểu cho đồ thị G:
// 7.1. Bằng thuật giải Prim.
// 7.2. Bằng thuật giải Kruskal.
// 7.3. Bằng thuật giải Kruskal cải tiến.

#include <stdio.h>
#include <fstream>
#include <iomanip>
#include <iostream>
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
	ifstream myfile ("do_thi_1.txt");
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
	cout << setw(5) << left;
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

void TaoCanhE()
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if (a[i][j] != 0)
			{
				E1[nE] = i;
				E2[nE] = j;
				wE[nE] = a[i][j];
				a[i][j] = 0;
				a[j][i] = 0;
				nE++;
			}
}

// Hàm hoán vị.
void Swap(int &a, int &b)
{
	int c;
	c = a;
	a = b;
	b = c;
}

void SapXep()
{
	for(int i = 0; i < nE - 1; i++)
		for(int j = i + 1; j < nE; j++)
			if (wE[i] > wE[j])
			{
				Swap(wE[i],wE[j]);
				Swap(E1[i],E1[j]);
				Swap(E2[i],E2[j]);
			}
}

void Kruskal()
{
	for (int i = 0; i < nE; i++)
	{
		if (TonTai(E1[i], T1, nT) == 1 && TonTai(E2[i], T2, nT) == 1)
			continue;
		if (TonTai(E1[i], T2, nT) == 1 && TonTai(E2[i], T1, nT) == 1)
			continue;
		T1[nT] = E1[i];
		T2[nT] = E2[i];
		wT[nT] = wE[i];
		nT++;
		if(nT == n-1)
			break;
	}
}

// 7.1. Bằng thuật giải Prim.
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

// 7.2. Bằng thuật giải Kruskal.
// 7.3. Bằng thuật giải Kruskal cải tiến (khác nhau ở các hoán vị cặp cạnh).
void Kruskal()
{
	for (int i = 0; i < nE; i++)
	{
		if (TonTai(E1[i], T1, nT) == 1 && TonTai(E2[i], T2, nT) == 1)
			continue;
		if (TonTai(E1[i], T2, nT) == 1 && TonTai(E2[i], T1, nT) == 1)
			continue;
		T1[nT] = E1[i];
		T2[nT] = E2[i];
		wT[nT] = wE[i];
		nT++;
		if(nT == n-1)
			break;
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
	cout << "------------------- Bai tap chuong 6 - BTLT - Bai 7 ----------------------" << endl << endl;
	cout << "0. Khoi tao ma tran ke rong." << endl;
	cout << "1. Nhap ma tran ke tu file text." << endl;
	cout << "2. Nhap ma tran ke." << endl;
	cout << "3. Xuat ma tran ke." << endl;
	cout << "4. Tim cay khung toi thieu bang PRIM." << endl;
	cout << "5. Tim cay khung toi thieu bang Krustal." << endl;
	cout << "6. Tim cay khung toi thieu bang Krustal cai tien." << endl;
	cout << "7. Thoat." << endl;
	do
	{
		do{
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		if (choice < 0 || choice > 7)
			cout << "Nhap sai roi! Nhap lai." << endl;
		} while(choice < 0 || choice > 7);
		switch (choice)
		{
			case 0:
				InitGraph();
				cout << "Ban vua khoi tao ma tran ke rong thanh cong." << endl;
				break ;

			case 1:
				InputGraphFromText();
				cout << "Ban vua nhap ma tran ke tu file:" << endl;
				OutputGraph();
				break ; 
		
			case 2:
				InitGraph();
				break ;

			case 3:
				OutputGraph();
				break ; 
			
			case 4:
				cout << "Vui long nhap dinh xuat phat: ";
				cin >> x;
				Prim(x);
				cout << "Cay khun toi thieu voi PRIM:" << endl; 
				Output(true );
				break; 
		
			case 5:
				TaoCanhE();
				Kruskal();
				cout << "Cay khung toi thieu voi Kruskal:" << endl; 
				Output(true );
				break;
		
			case 6:
				TaoCanhE();
				SapXep();
				Kruskal();
				cout << "Cay khung toi thieu voi Kruskal cai tien:" << endl; 
				Output(true );
				break ; 
		
			case 7: 
				cout << "Goodbye...!" << endl; 
				break; 
			default:
				break ; 
		}
	} while (choice!= 7);
	system("pause");
	return 0;
}