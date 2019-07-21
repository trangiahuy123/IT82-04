//CHUONG 2 - BAI 15: DANH SACH DAC
#include<stdio.h>
#include<iostream>
using namespace std;

const int MAX = 100;

//CAU 15.1: Xuat cac phan tu thuoc tap hop cua hai danh sach
void PhepHop(int a[], int b[], int n, int m)
{
	/* Dung de kiem tra b[j] co bi trung voi a[i] hay khong
	   - Khong trung: TRUE
	   - Trung: FALSE */
	bool test = true; 

	/* XUAT DANH SACH A TRUOC */
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";

	/* KIEM TRA VA XUAT DANH SACH B */
	for (int j = 0; j < m; j++) /* Duyet va kiem tra b[j] so voi a[i] */
	{
		for (int i = 0; i < n; i++)
		{
			if (b[j] == a[i]) /*Neu b[j] bi trung voi a[i] thi test = false */
				test = false;
		}
		if (test == true) /* Neu khong bi trung thi xuat */
			cout << b[j] << "\t";
		else
			test = true;
	}
}

//CAU 15.2: Xuat cac phan tu thuoc tap hop giao cua hai danh sach
void PhepGiao(int a[], int b[], int n, int m)
{
	/* Dung de kiem tra a[i] co bi trung voi b[j] hay khong
	   - Trung: TRUE
	   - Khong trung: FALSE*/
	bool test;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i] == b[j])
			{
				test = true;
				cout << a[i] << "\t";
				break;
			}
			else
				test = false;
		}
		if ((i == (n- 1) && (test == false)))
			cout << "Khong co phan tu giao" << endl;
	}
}

void PhepBu(int a[], int b[], int n, int m)
{
	/* Dung de kiem tra a[i] co bi trung voi b[j] hay khong
	   - Khong trung: TRUE
	   - Trung: FALSE */
	bool test = true;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			if (a[i] == b[j]) /* Chi can co mot phan tu bi trung thi break */
			{
				test = false;
				break;
			}
		if (test == true)
			cout << a[i] << "\t";
		else
			test = true;
	}
}

int main()
{
	int a[MAX];
	int b[MAX];
	int n, m;
	int choice;
	char x;

	system("cls");

	cout << "---------- CHUONG 2 - BAI 15: DANH SACH DAC ----------" << endl;
	cout << "1. Nhap danh sach A va B" << endl;
	cout << "2. Xuat danh sach A va B" << endl;
	cout << "3. Xuat cac phan tu thuoc TAP HOP cua A va B" << endl;
	cout << "4. Xuat cac phan tu thuoc TAP GIAO cua A va B" << endl;
	cout << "5. Xuat cac phan tu thuoc PHAN BU cua A va B" << endl;
	cout << "6. Thoat" << endl;

	do
	{
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Nhap so phan tu cua danh sach A: ";
			cin >> n;
			cout << "Nhap danh sach a:" << endl;
			for (int i = 0; i < n; i++)
			{
				cout << "a[" << i << "] = ";
				cin >> a[i];
			}
			cout << endl;

			cout << "Nhap so phan tu cua danh sach B: ";
			cin >> m;
			cout << "Nhap danh sach a:" << endl;
			for (int j = 0; j < m; j++)
			{
				cout << "b[" << j << "] = ";
				cin >> b[j];
			}

			cout << endl;
			break;
		case 2:
			cout << "Danh sach A la:" << endl;
			for (int i = 0; i < n; i++)
				cout << a[i] << "\t";
			cout << endl;

			cout << "Danh sach B la:" << endl;
			for (int j = 0; j < m; j++)
				cout << b[j] << "\t";
			cout << endl;

			cout << endl;
			break;
		case 3:
			cout << "Danh sach cac phan tu thuoc TAP HOP cua A va B la:" << endl;
			PhepHop(a, b, n, m);
			cout << endl;

			cout << endl;
			break;
		case 4:
			cout << "Danh sach cac phan tu thuoc TAP GIAO cua A va B la:" << endl;
			PhepGiao(a, b, n, m);
			cout << endl;

			cout << endl;
			break;
		case 5:
			cout << "a. Phan bu cua B trong A (A\B)" << endl;
			cout << "b. Phan bu cua A trong B (B\A)" << endl;
			cout << endl;

			cout << "Chon a hoac b de thuc hien: ";
			cin >> x;
			if (x == 'a')
			{
				cout << "Danh sach cac phan tu thuoc phan bu cua A va B (A\\B) la:" << endl;
				PhepBu(a, b, n, m);
				cout << endl;
			}
			if (x == 'b')
			{
				cout << "Danh sach cac phan tu thuoc phan bu cua A va B (A\\B) la:" << endl;
				PhepBu(b, a, m, n);
				cout << endl;
			}

			cout << endl;
			break;
		case 6:
			cout << "Goodbye...!" << endl;

			cout << endl;
			break;
		default:
			break;
		}
	} while (choice !=6);

	system("pause");

	return 0;
}