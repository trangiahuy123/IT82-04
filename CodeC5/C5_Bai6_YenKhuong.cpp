//CHUONG 5 - BAI 6.1 & 6.2: DO THI
#include<stdio.h>
#include<iostream>
#include<fstream>
using namespace std;

//KHAI BAO 
const int MAX = 100;
int A[MAX][MAX];
int n;
char vertex[MAX];

//NHAP DO THI TU FILE *TXT
void Input_Graph_fromText()
{
	string line;
	ifstream myfile("matranke1.txt");

	if (myfile.is_open())
	{
		//doc n tu file txt
		myfile >> n;

		//doc ten dinh tu file txt
		for (int i = 0; i < n; i++)
			myfile >> vertex[i];

		//doc ma tran ke tu file txt
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				myfile >> A[i][j];
	}
}

//CAU 6.1: Nhap ma tran ke tu do thi vi du 5.1
void Input_Graph()
{
	cout << "Nhap so dinh (n) cua do thi: ";
	cin >> n;

	cout << "Nhap ten dinh cua do thi: ";
	for (int i = 0; i < n; i++)
		cin >> vertex[i];

	for (int i = 0; i < n; i++)
	{
		cout << "Nhap dong thu " << (i + 1) << ": ";
		for (int j = 0; j < n; j++)
			cin >> A[i][j];
	}	
}

//CAU 6.2: Xuat ma tran ke cua do thi
void Output_Graph()
{
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			cout << "\t";
		if (i == (n - 1))
			cout << vertex[i] << endl;
		else
			cout << vertex[i] << "\t";
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (j == 0)
				cout << vertex[i] << "\t";
			if (j == (n - 1))
				cout << A[i][j] << endl;
			else
				cout << A[i][j] << "\t";
		}
}

int main()
{
	int choice;

	system("cls");

	cout << "---------- CHUONG 5 - BAI 6.1 & 6.2: DO THI ----------" << endl;
	cout << "1. Nhap do thi cua vi du 5.1 tu FILE *TXT" << endl;
	cout << "2. Nhap do thi cua vi du 5.1 tu MAN HINH" << endl;
	cout << "3. Xuat MA TRAN KE cua do thi ra man hinh" << endl;
	cout << "4. Thoat" << endl;

	do
	{
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			Input_Graph_fromText();
			cout << "Nhap do thi tu FILE *TXT thanh cong!" << endl;
			cout << endl;
			break;
		case 2:
			Input_Graph();
			cout << "Nhap do thi tu MAN HINH thanh cong!" << endl;
			cout << endl;
			break;
		case 3:
			cout << "Do thi cua vi du 5.1 co MA TRAN KE nhu sau:" << endl;
			Output_Graph();
			cout << endl;
			break;
		case 4:
			cout << "Goodbye...!" << endl;
			cout << endl;
			break;
		default:
			break;
		}
	} while (choice != 4);

	system("pause");

	return 0;
}