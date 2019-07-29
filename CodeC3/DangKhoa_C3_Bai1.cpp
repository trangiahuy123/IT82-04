// Bài 1: Quản lý danh sách đặc 100 phần tử kiểu số nguyên (int).
// 1.1 Khai báo cấu trúc danh sách.
// 1.2 Viết thủ tục nhập danh sách.
// 1.3 Viết thủ tục xuất danh sách.
// 1.4 Viết thủ tục sắp xếp danh sách theo thứ tự tăng dần bằng thuật toán InsertionSort. Đánh giá độ phức tạp của thuật toán.
// 1.5 Viết thủ tục sắp xếp danh sách theo thứ tự tăng dần bằng thuật toán SelectionSort. Đánh giá độ phức tạp của thuật toán.
// 1.6 Viết thủ tục sắp xếp danh sách theo thứ tự tăng dần bằng thuật toán InterchangeSort. Đánh giá độ phức tạp của thuật toán.
// 1.7 Viết thủ tục sắp xếp danh sách theo thứ tự tăng dần bằng thuật toán BubbleSort. Đánh giá độ phức tạp của thuật toán.
// 1.8 Viết thủ tục sắp xếp danh sách theo thứ tự tăng dần bằng thuật toán QuickSort. Đánh giá độ phức tạp của thuật toán.
// 1.9 Viết thủ tục sắp xếp danh sách theo thứ tự tăng dần bằng thuật toán HeapSort. Đánh giá độ phức tạp của thuật toán.
// 1.10 Viết thủ tục tìm kiếm một phần tử trong danh sách có thứ tự (dùng phương pháp tìm kiếm tuần tự). Đánh giá độ phức tạp của thuật toán.
// 1.11 Viết thủ tục tìm kiếm một phần tử trong danh sách có thứ tự (dùng phương pháp tìm kiếm nhị phân). Đánh giá độ phức tạp của thuật toán.

#include <ctime>
#include <iostream>
using namespace std;

// 1.1 Khai báo cấu trúc danh sách.
#define MAX 100
int a[MAX];
int n;

// 1.1.1 Khởi tạo mảng tự động.
void Init(int a[], int &n)
{
	do{
		cout << "Nhap so luong phan tu n can khoi tao (n > 0): ";
		cin >> n;
		if (n < 0)
			cout << "Nhap sai roi! Nhap lai." << endl;
	} while (n < 0);
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 10000 +1;
	}
	cout << "Danh sach da duoc khoi tao ngau nhien la: " <<endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] <<" ";
	}
	cout << endl;
}

// 1.2 Viết thủ tục nhập danh sách.
void Input(int a[], int &n)
{
	do{
		cout << "Nhap so luong phan tu n (n > 0): ";
		cin >> n;
		if (n < 0)
			cout << "Nhap sai roi! Nhap lai." << endl;
	} while (n < 0);
	cout << "Nhap vao cac phan tu cua danh sach: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap a["<<i<<"]= ";
		cin >> a[i];
	}
}

// 1.3 Viết thủ tục xuất danh sách.
void Output(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}

// Hàm tạo thêm 1 mảng.
void CopyArray(int a[], int b[], int n)
{
	for (int i = 0; i < n; i++)
	{
		b[i] = a[i];
	}
}

// 1.4 Viết thủ tục sắp xếp danh sách theo thứ tự tăng dần bằng thuật toán InsertionSort. Đánh giá độ phức tạp của thuật toán.
void InsertionSort(int a[], int n)
{
	int key, i, j;
	for (int i = 1; i < n; i++)
	{
		key = a[i]; // biến key lưu giá trị a[i]
		j = i - 1;
		while (0 <= j && key < a[j])
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}
}

// Hàm hoán vị
void Swap(int &a, int &b)
{
	int c;
	c = a;
	a = b;
	b = c;
}

// 1.5 Viết thủ tục sắp xếp danh sách theo thứ tự tăng dần bằng thuật toán SelectionSort. Đánh giá độ phức tạp của thuật toán.
void SelectionSort(int a[], int n)
{
	int min_pos; // min_pos là vị trí chứa giá trị nhỏ nhất
	int i, j;
	for (int i = 0; i < n-1; i++)
	{
		min_pos = i;
		for (j = i + 1; j < n; j++)
			if ( a[j] < a[min_pos] )
				min_pos = j;
		Swap (a[min_pos], a[i]);
	}
}

// 1.6 Viết thủ tục sắp xếp danh sách theo thứ tự tăng dần bằng thuật toán InterchangeSort. Đánh giá độ phức tạp của thuật toán.
void InterchanceSort(int a[], int n)
{
	for(int i = 0; i < n-1; i++)
		for(int j = i+1; j < n; j++)
			if(a[i] > a[j])
				Swap(a[i], a[j]);
}

// 1.7 Viết thủ tục sắp xếp danh sách theo thứ tự tăng dần bằng thuật toán BubbleSort. Đánh giá độ phức tạp của thuật toán.
void BubbleSort(int a[], int n)
{
	for (int i = 0; i < n-1; i++)
		for (int j = n-1; j > i; j--)
			if(a[j-1] > a[j])
				Swap (a[j], a[j-1]);
}

// 1.8 Viết thủ tục sắp xếp danh sách theo thứ tự tăng dần bằng thuật toán QuickSort. Đánh giá độ phức tạp của thuật toán.
void QuickSort(int a[], int left, int right)
{
	int x = a[(left + right) / 2]; // x là pivot và lấy ở giữa
	int i = left;
	int j = right;
	do{
		while (a[i] <= x)
			i++;
		while (a[i] >= x)
			j--;
		if (i <= j )
		{
			Swap (a[i], a[j]);
			i++;
			j--;
		}
	} while ( i < j );
	if (left < j )
		QuickSort (a, left, j);
	if (i < right)
		QuickSort (a, i, right);
}

// 1.9 Viết thủ tục sắp xếp danh sách theo thứ tự tăng dần bằng thuật toán HeapSort. Đánh giá độ phức tạp của thuật toán.
void Shift(int a[], int i, int n)
{
	int j= (2*i) + 1;
	if (j >= n)
		return;
	if (j+1 < n)
		if (a[j] < a[j+1])
			j++;
	if (a[i] >= a[j])
		return;
	else
	{
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
		Shift (a, j, n);
	}
}

void HeapSort(int a[], int n)
{
	int i = n/2 -1;
	while (i >= 0)
	{
		Shift (a, i, n);
		i--;
	}
	int right = n-1;
	while (right > 0)
	{
		Swap(a[0], a[right]);
		right --;
		if (right > 0)
			Shift (a, 0, right);
	}	
}


// 1.10 Viết thủ tục tìm kiếm một phần tử trong danh sách có thứ tự (dùng phương pháp tìm kiếm tuần tự). Đánh giá độ phức tạp của thuật toán.
int Sequence_Search(int a[], int n, int x)
{
	int i = 0;
	while (i < n && a[i] != x) 
	{
		i++;
	}
	if (i == n)
		return -1;
	else 
	
		return i;
}

// 1.11 Viết thủ tục tìm kiếm một phần tử trong danh sách có thứ tự (dùng phương pháp tìm kiếm nhị phân). Đánh giá độ phức tạp của thuật toán.
int Binary_Search(int a[], int l, int r, int x)
{
	if (r >= l) 
	{
		int mid = l + (r - l) /2;  // tương đương (l+r)/2 nhưng ưu điểm tránh tràn số khi l, r lớn.
		// nếu a[mid] = x, trả về chỉ số và kết thúc.
		if (a[mid] == x)
			return mid;
		// nếu a[mid] > x, thực hiện tìm kiếm nửa trái của mảng.
		if (a[mid] > x)
			return Binary_Search (a, l, mid - 1, x);
		// nếu a[mid] < x, thực hiện tìm kiếm nửa phải của mảng.
		return Binary_Search (a, mid + 1, r, x);
	}
	return -1;
}

int main()
{
	int b[MAX];
	clock_t start;
	double duration;
	int choice, x, i;
	system ("cls");
	cout<< "------------------- Bai tap chuong 3 - BTTH Bai 1 ----------------------" << endl << endl;
	cout<< "0. Khoi tao mang tu dong. " << endl;
	cout<< "1. Nhap danh sach. " << endl;
	cout<< "2. Xuat danh sach. " << endl;
	cout<< "3. Sap xep danh sach theo thu tu tang dan bang thuat toan INSERTION SORT." << endl;
	cout<< "4. Sap xep danh sach theo thu tu tang dan bang thuat toan SELECTION SORT." << endl;
	cout<< "5. Sap xep danh sach theo thu tu tang dan bang thuat toan INTERCHANGE SORT." << endl;
	cout<< "6. Sap xep danh sach theo thu tu tang dan bang thuat toan BUBBLE SORT." << endl;
	cout<< "7. Sap xep danh sach theo thu tu tang dan bang thuat toan QUICK SORT." << endl;
	cout<< "8. Sap xep danh sach theo thu tu tang dan bang thuat toan HEAP SORT." << endl;
	cout<< "9. Tim kiem phan tu x bang phuong phap tim kiem tuan tu." << endl;
	cout<< "10. Tim kiem phan tu x bang phuong phap BINARY SEARCH." << endl;
	cout<< "11. Thoat." <<endl;
	do
	{
		do{
		cout << "\nVui long chon so de thuc hien (so > 0 && so < 12: ";
		cin >> choice;
		if (choice < 0 || choice > 11)
			cout << "Nhap sai roi! Nhap lai." << endl;
		} while(choice < 0 || choice > 11);
		switch (choice)
		{
		case 0:
			Init(a,n);
			break;
		case 1:
			Input(a,n);
			break;
		case 2:
			Output(a,n);
			break;
		case 3:
			CopyArray(a, b, n);
			start = clock();
			InsertionSort(b, n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "Danh sach theo thu tu tang dan bang thuat toan INSERTION SORT la: ";
				Output(b, n);
			}
			if (duration > 0)
			{
				cout << "Do phuc tap cua thuat toan INSERTION SORT la: " << duration * 1000000 << "Microseconds" << endl;
			}
			break;
		case 4:
			CopyArray(a, b, n);
			start = clock();
			InsertionSort(b, n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "Danh sach theo thu tu tang dan bang thuat toan SELECTION SORT la: ";
				Output(b, n);
			}
			if (duration > 0)
			{
				cout << "Do phuc tap cua thuat toan SELECTION SORT la: " << duration * 1000000 << "Microseconds" << endl;
			}
			break;
		case 5:
			CopyArray(a, b, n);
			start = clock();
			InsertionSort(b, n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "Danh sach theo thu tu tang dan bang thuat toan INTERCHANCE SORT la: ";
				Output(b, n);
			}
			if (duration > 0)
			{
				cout << "Do phuc tap cua thuat toan INTERCHANGE SORT la: " << duration * 1000000 << "Microseconds" << endl;
			}
			break;
		case 6:
			CopyArray(a, b, n);
			start = clock();
			InsertionSort(b, n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "Danh sach theo thu tu tang dan bang thuat toan BUBBLE SORT la: ";
				Output(b, n);
			}
			if (duration > 0)
			{
				cout << "Do phuc tap cua thuat toan BUBBLE SORT la: " << duration * 1000000 << "Microseconds" << endl;
			}
			break;
		case 7:
			CopyArray(a, b, n);
			start = clock();
			InsertionSort(b, n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "Danh sach theo thu tu tang dan bang thuat toan QUICK SORT la: ";
				Output(b, n);
			}
			if ( duration > 0 )
			{
				cout << "Do phuc tap cua thuat toan QUICK SORT la: " << duration * 1000000 << "Microseconds" << endl;
			}
			break;
		case 8:
			CopyArray(a, b, n);
			start = clock();
			InsertionSort(b, n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "Danh sach theo thu tu tang dan bang thuat toan HEAP SORT la: ";
				Output(b, n);
			}
			if (duration > 0)
			{
				cout << "Do phuc tap cua thuat toan HEAP SORT la: " << duration * 1000000 << "Microseconds" << endl;
			}
			break;
		case 9:
			cout << "Vui long nhap gia tri x = ";
			cin >> x;
			start = clock();
			i = Sequence_Search(a, n,x);
			if (i == -1)
				cout << "Khong tim thay x = " <<x<< " trong mang." << endl;
			else 
				cout << "Tim thay x = " <<x<< " tai vi tri i = " << i << endl;
			duration = (clock()- start)/ (double)CLOCKS_PER_SEC;
			if (duration > 0)
				cout << "Thoi gian tim kiem tuan tu la: " << duration * 1000000 << "Microsecond"<< endl;
			break;
		case 10:
			cout << "Vui long nhap gia tri x = ";
			cin >> x;
			start = clock();
			i = Binary_Search(b, 0, n , x);
			duration = (clock()- start)/ (double)CLOCKS_PER_SEC;
			if (i == -1)
				cout << "Khong tim thay x = "<<x<<" trong day." << endl;
			else 
				cout << "Tim thay x = " <<x<< " tai vi tri i = " <<i << endl;
			if (duration > 0)
				cout << "Thoi gian tim kiem nhi phan la: "<< duration * 1000000 << "Microsecond" << endl;
			break;
		case 11:
			cout << "Goodbye...!" << endl;
			break;
		default:
			break;
		}
	} while(choice != 11);
	system("pause");
	return 0;
}



