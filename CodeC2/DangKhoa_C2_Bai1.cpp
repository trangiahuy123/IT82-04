// Bài 1: Quản lý một danh sách có tối đa 100 phần tử, mỗi phần tử trong danh sách có kiểu int. (Danh sách không có thứ tự)
// 1.1. Khai báo cấu trúc danh sách.
// 1.2. Viết thủ tục nhập danh sách.
// 1.3. Viết thủ tục xuất danh sách ra màn hình.
// 1.4. Viết thủ tục tìm một phần tử trong danh sách.
// 1.5. Viết thủ tục thêm một phần tử vào cuối danh sách.
// 1.6. Viết thủ tục xóa phần tử cuối danh sách.
// 1.7. Viết thủ tục xóa phần tử tại vị trí thứ i.
// 1.8. Tìm một phần tử trong danh sách. Nếu tìm thấy, xóa phần tử đó.

#include<iostream>
using namespace std;

// 1.1. Khai báo cấu trúc danh sách.
#define MAX 100
int a[MAX];
int n;


// 1.2. Viết thủ tục nhập danh sách.
void Input (int a[], int &n)
{
	do{
		cout << "Nhap so luong phan tu n (n > 0): ";
		cin >> n;
		if (n <= 0 )
			cout << "Nhap sai roi! Nhap lai." << endl;
	} while (n <= 0 );
	cout << "Nhap vao cac phan tu cua danh sach: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap a["<<i<<"]= ";
		cin >> a[i];
	}
}

// 1.3. Viết thủ tục xuất danh sách ra màn hình.
void Output (int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
	cout << endl;
}

// 1.4. Viết thủ tục tìm một phần tử trong danh sách.
int Search (int a[], int n, int x)
{
	int i = 0;
	while (i < n && a[i] != x)
	{
		i++;
		if (i == n)
			return -1;
	}
	return i;
}

// 1.5. Viết thủ tục thêm một phần tử vào cuối danh sách.
int Insert_Last (int a[], int &n, int x)
{
	if (n < MAX)
	{
		a[n] = x;
		n++;
		return 1;
	}
	else 
		return 0;
}

// 1.6. Viết thủ tục xóa phần tử cuối danh sách.
int Delete_Last (int a[], int &n)
{
	if(n > 0)
	{
		n--;
		return 1;
	}
	else
		return 0;
}

// 1.7. Viết thủ tục xóa phần tử tại vị trí thứ i.
int Delete_i (int a[], int &n, int i)
{
	if (i >= 0 && i < n)
	{
		for (int j = i; j < n - 1; j++)
		{
			a[j] = a[j + 1];
		}
		n--;
		return 1;
	}
	return 0;
}

// 1.8. Tìm một phần tử trong danh sách. Nếu tìm thấy, xóa phần tử đó.
int SearchAndDelete (int a[], int &n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
			Delete_i(a, n, i);
		return 1;
	}
	return 0;
}


int main()
{
	int x;
	int i;
	int choice = 0;
	system("cls");
	cout<< "------------------- Bai tap chuong 2 - BTTH So 1 - Bai 1 ----------------------" << endl << endl;
	cout << "1. Xin chao." << endl;
	cout << "2. Nhap danh sach." << endl;
	cout << "3. Xuat danh sach." << endl;
	cout << "4. Tim phan tu trong danh sach." << endl;
	cout << "5. Them mot phan tu vao cuoi danh sach." << endl;
	cout << "6. Xoa phan tu cuoi danh sach." << endl;
	cout << "7. Xoa phan tu tai vi tri thu i." << endl;
	cout << "8. Tim phan tu trong danh sach, xoa neu tim thay." << endl;
	cout << "9. Thoat." << endl;
	do
	{
		do{
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		if (choice <= 0 || choice > 9)
			cout << "Nhap sai roi! Nhap lai." << endl;
		} while(choice <= 0 || choice > 9);
		switch (choice)
		{
		case 1:
			cout << "Hello you, <3" << endl;
			break;

		case 2:
			Input(a, n);
			break;

		case 3:
			Output(a, n);
			break;

		case 4:
			cout << "Vui long nhap gia tri x can tim: ";
			cin >> x;
			i = Search(a, n,x);
			if (i == -1)
				cout << "Tim khong thay phan tu co gia tri " << x << endl;
			else
				cout << "Tim thay tai vi tri i = " << i << endl;
				break;

		case 5:
				cout << "Vui long nhap x can them vao cuoi danh sachs: ";
				cin >> x;
				i = Insert_Last(a, n, x);
				if (i == 0)
					cout << "Danh sach da day, khong the them." << x << endl;
				else
				{
					cout << "Danh sach da them phan tu x = " << x << "vao cuoi danh sach!" << endl;
					cout << "Danh sach da them la: \n";
					Output(a, n);
				}
				break;

		case 6:
				i = Delete_Last(a, n);
				if (i > 0)
				{
					cout << "Xoa thanh cong!" << endl;
					cout << "Danh sach sau khi xoa phan tu cuoi la: \n";
					Output(a, n);
				}
				else 
					cout << "Danh sach dang rong, khong co phan tu nao!" << endl;
				break;

		case 7:
				cout << "Vui long nhap vi tri i can xoa: ";
				cin >> i;
				i = Delete_i(a,n,i);
				if (i == 1)
				{
					cout << "Xoa thanh cong!" << endl;
					cout << "Danh sach sau khi xoa la: \n";
					Output(a, n);
				}
				else 
					cout << "Khong co phan tu nao de xoa!" << endl;
				break;

		case 8:
				cout << "Vui long nhap gia tri x can xoa: ";
				cin >> x;
				i = SearchAndDelete(a, n ,x);
				if (i == 1)
				{
					cout << "Xoa thanh cong phan tu co gia tri x = " << x << endl;
					cout << "Danh sach sau khi xoa la: \n";
					Output(a, n);
				}
				else
					cout << "Khong co phan tu nao de xoa!" << endl;
				break;

		case 9:
			cout<< "Goodbye!" << endl;
		default:
			break;
		}
	} while(choice != 9);
	system("pause");
	return 0;
}