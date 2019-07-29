//CHUONG 3 - BAI 1: SAP XEP THU TU & TIM KIEM
#include<stdio.h>
#include<iostream>
#include<ctime>
using namespace std;

// CAU 1.1: Khai bao cau truc danh sach
const int MAX = 100;
int a[MAX];
int n;

// CAU HOI THEM: Nhap danh sach tu dong
void Init(int a[], int &n)
{
	cout << "Nhap so luong phan tu (n) cua danh sach: ";
	cin >> n;

	for (int i = 0; i < n; i++)
		a[i] = rand() % 10000 + 1;
	
	cout << "Danh sach hien tai la: " << endl;
	for (int i = 0; i < n; i++)
	{
		if (i == (n - 1))
			cout << a[i] << endl;
		else
			cout << a[i] << "\t";
	}
}

// CAU HOI THEM: Sao chep mang
void CoppyArray(int a[], int b[], int n)
{
	for (int i = 0; i < n; i++)
		b[i] = a[i];
}

// CAU 1.2: Nhap danh sach
void Input(int a[], int &n)
{
	cout << "Nhap so luong phan tu (n) cua danh sach: ";
	cin >> n;

	do
	{
		if (n <= 0)
			cout << "So luong phan tu khong dat yeu cau (n > 0). Yeu cau nhap lai!" << endl;
		else
			if (n > MAX)
				cout << "So luong phan tu vuot qua muc cho phep (n <= 100). Yeu cau nhap lai!" << endl;
			else
			{
				for (int i = 0; i < n; i++)
				{
					cout << "Nhap phan tu a[" << i << "] = ";
					cin >> a[i];
				}
			}
	} while ((n <= 0) || (n > MAX));
}

// CAU 1.3: Xuat danh sach
void Output(int a[], int n)
{
	cout << "Danh sach hien tai la: " << endl;
	for (int i = 0; i < n; i++)
	{
		if (i == (n - 1))
			cout << a[i] << endl;
		else
			cout << a[i] << "\t";
	}
}

// CAU 1.4: Su dung INSERTION SORT theo thu tu tang dan
void InsertionSort(int a[], int n)
{
	int i, j;
	int x;

	for (i = 1; i < n; i++)
	{
		x = a[i];
		j = i - 1;

		while ((j >= 0) && (a[j] > x))
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}

// CAU 1.5: Su dung SELECTION SORT theo thu tu tang dan
void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void SelectionSort(int a[], int n)
{
	int min;

	for (int i = 0; i < n; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[min])
				min = j;
		Swap(a[i], a[min]);
	}
}


// CAU 1.6: Su dung INTERCHANGE SORT theo thu tu tang dan
void InterchangeSort(int a[], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a[j] < a[i])
				Swap(a[i], a[j]);
}

// CAU 1.7: Su dung BUBBLE SORT theo thu tu tang dan
void BubbleSort(int a[], int n)
{
	bool haveSwap = true; /*Kiem tra Swap*/

	for (int i = 0; i < n; i++)
	{
		for (int j = (n - 1); j > i; j--)
		{
			if (a[j] < a[j - 1])
			{
				Swap(a[j], a[j - 1]);
				haveSwap = false;
			}
		}

		if (haveSwap == true)  /*Neu khong co Swap nao thi mang da duoc sap xep*/
			break;
	}
}

int partition(int a[], int low, int high)
{
	int pivot = a[high];
	int left = low;
	int right = high - 1;
	while (true)
	{
		while (left <= right && a[left] < pivot) left++;
		while (right >= left && a[right] > pivot) right--;
		if (left >= right) break;
		swap(a[left], a[right]);
		left++;
		right--;
	}
	swap(a[left], a[high]);
	return left;
}

// CAU 1.8: Su dung QUICK SORT theo thu tu tang dan
void QuickSort(int a[], int left, int right)
{
	int x = a[(left + right) / 2];
	int i = left;
	int j = right;

	while (i < j)
	{
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;
		if (i <= j)
		{
			Swap(a[i], a[j]);
			i++;
			j--;
		}
	}

	if (left < i)
		QuickSort(a, left, j);
	if (right > j)
		QuickSort(a, i, right);
}

// CAU 1.9: Su dung HEAP SORT theo thu tu tang dan
void Shift(int a[], int i, int n)
{
	int max = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if ((left < n) && (right < n)) /*DS khong ton tai vi tri j*/
	{
		if (a[left] > a[max])
			max = left;
		if (a[right] > a[max])
			max = right;
		if (max != i)
		{
			Swap(a[i], a[max]);
			Shift(a, max, n);
		}
	}
}
void HeapSort(int a[], int n)
{

	for (int i = (n / 2) - 1; i >= 0; i--)
		Shift(a, i, n);

	for (int j = (n - 1); j >= 0; j--)
	{
		Swap(a[0], a[j]);
		Shift(a, 0, j);
	}
}

//CAU 1.10: Tim kiem phan tu x bang TIM KIEM TUAN TU
int SearchSequence(int a[], int n, int x)
{
	int i;
	for (i = 0; i < n; i++)
		if (a[i] == x)
			return 1;
	if (i == n)
		return 0;
}

//CAU 1.11: Tim kiem phan tu x bang TIM KIEM NHI PHAN
int SearchBinary(int a[], int left, int right, int x)
{
	if (right >= 1)
	{
		int mid = (left + right) / 2;

		if (a[mid] == x)
			return x;
		if (x < a[mid])
			return SearchBinary(a, left, mid - 1, x);
		if (x > a[mid])
			return SearchBinary(a, mid + 1, right, x);

	}
	
	return 0;
}

int main()
{
	int b[MAX];
	int choice, n, x;
	int result;

	clock_t start;
	double duration;

	system("cls");

	cout << "----------- CHUONG 3 - BAI 1 SAP XEP & TIM KIEM -----------" << endl;
	cout << "0. Khoi tao danh sach ngau nhien" << endl;
	cout << "1. Nhap danh sach" << endl;
	cout << "2. Xuat danh sach" << endl;
	cout << "3. Xep thu tu danh sach theo INSERTION SORT" << endl;
	cout << "4. Xep thu tu danh sach theo SELECTION SORT" << endl;
	cout << "5. Xep thu tu danh sach theo INTERCHANGE SORT" << endl;
	cout << "6. Xep thu tu danh sach theo BUBBLE SORT" << endl;
	cout << "7. Xep thu tu danh sach theo QUICK SORT" << endl;
	cout << "8. Xep thu tu danh sach theo HEAP SORT" << endl;
	cout << "9. Tim kiem phan tu x bang TIM KIEM TUAN TU" << endl;
	cout << "10. Tim kiem phan tu x bang TIM KIEM NHI PHAN" << endl;
	cout << "11. Thoat" << endl;
	

	do
	{
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;

		switch (choice)
		{
		case 0:
			Init(a, n);
			break;
		case 1:
			Input(a, n);
			break;
		case 2:
			Output(a, n);
			break;
		case 3:
			CoppyArray(a, b, n);
			start = clock();
			SelectionSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Danh sach da duoc sap xep thanh cong!" << endl;
			Output(b, n);
			if (duration > 0)
				cout << "Thoi gian Selection Sort: " << duration * 1000000 << " Microseconds" << endl;
			cout << endl;
			break;
		case 4:
			CoppyArray(a, b, n);
			start = clock();
			InsertionSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Danh sach da duoc sap xep thanh cong!" << endl;
			Output(b, n);
			if (duration > 0)
				cout << "Thoi gian Insertion Sort: " << duration * 1000000 << " Microseconds" << endl;
			cout << endl;
			break;
		case 5:
			CoppyArray(a, b, n);
			start = clock();
			InterchangeSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Danh sach da duoc sap xep thanh cong!" << endl;
			Output(b, n);
			if (duration > 0)
				cout << "Thoi gian Interchage Sort: " << duration * 1000000 << " Microseconds" << endl;
			cout << endl;
			break;
		case 6:
			CoppyArray(a, b, n);
			start = clock();
			BubbleSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Danh sach da duoc sap xep thanh cong!" << endl;
			Output(b, n);
			if (duration > 0)
				cout << "Thoi gian Bubble Sort: " << duration * 1000000 << " Microseconds" << endl;
			cout << endl;
			break;
		case 7:
			CoppyArray(a, b, n);
			start = clock();
			QuickSort(b, 0, n - 1);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Danh sach da duoc sap xep thanh cong!" << endl;
			Output(b, n);
			if (duration > 0)
				cout << "Thoi gian Quick Sort: " << duration * 1000000 << " Microseconds" << endl;
			cout << endl;
			break;
		case 8:
			CoppyArray(a, b, n);
			start = clock();
			HeapSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Danh sach da duoc sap xep thanh cong!" << endl;
			Output(b, n);
			if (duration > 0)
				cout << "Thoi gian Quick Sort: " << duration * 1000000 << " Microseconds" << endl;
			cout << endl;
			break;
		case 9:
			cout << "Nhap gia tri (x) can tim: ";
			cin >> x;
			start = clock();
			result = SearchSequence(a, n, x);
			if (result == 1)
				cout << "Tim thay phan tu x = " << x << " trong danh sach." << endl;
			else
				cout << "Khong tim thay phan tu x = " << x << " trong danh sach." << endl;
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (duration > 0)
				cout << "Thoi gian TIM KIEM TUAN TU la: " << duration * 1000000 << " Microseconds" << endl;
			cout << endl;
			break;
		case 10:
			cout << "Nhap gia tri (x) can tim: ";
			cin >> x;
			start = clock();
			result = SearchBinary(a, 0, n - 1, x);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (result == 0)
				cout << "Khong tim thay phan tu x = " << x << " trong danh sach." << endl;
			else
				cout << "Tim thay phan tu x = " << result << " trong danh sach." << endl;
			if (duration > 0)
				cout << "Thoi gian TIM KIEM NHI PHAN la: " << duration * 1000000 << " Microseconds" << endl;
			cout << endl;
			break;
		case 11:
			cout << "Goodbye...!" << endl;
			cout << endl;
			break;
		default:
			break;
		}
	} while (choice != 11);

	system("pause");
	return 0;
}