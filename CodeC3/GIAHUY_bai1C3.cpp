//Bai1 , chuong 3 : xep thu tu Tim kiem
#include <stdio.h>
#include <iostream>
#include <ctime>

using namespace std;
#define MAX 100
// cau 1.1
int a[MAX];
int n;

// cau 1.0: NHAP danh sach khoi tao ngau nhien
void init(int a[], int &n)
{
	cout <<"Nhap vao so luong phan tu cua danh sach : ";
	cin >> n;
	for (int i= 0; i < n ; i++)
	{
		a[i]=rand() % 100 + 1;
	}
	cout <<"Danh sach duoc nhap ngau nhien nhu sau:" <<endl;
	for (int i = 0; i < n ; i++)
	{
		cout << a[i] << "   ";
	}
	cout<<endl;
}
// cau 1.2: NHAP DANH SACH	
void input(int a[], int &n)
{
	cout << "Nhap vao so luong phan tu cua danh sach: ";
	cin >> n;
	cout << "Nhap vao phan tu cua danh sach: " <<endl;
	for (int i = 0; i < n ; i++)
	{
		cout << "a[" << i << "]=";
		cin >> a[i];
	}
}

//cau 1.3: Xuat danh sach
void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "   ";
	}
	cout << endl;
}

void CopyArray(int a[], int b[], int n)
{
	for (int i = 0; i < n; i++)
	{
		b[i]=a[i];
	}
}
//cau 1.4 insertion sort
void insertionSort(int a[], int n)
{
	int i, key, j;
	for (i = 1; i < n;i++)
	{
		key = a[i];
		j = i - 1;

		/*di chuyen cac phan tu co gia tri lon hon gia tri key ce sau mot vi tri so voi vi tri ban dau */
		while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j = j -1;
		}
		a[j + 1]=key;
	}
}
//ham doi cho 2 so nguyen
void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}
//cau 1.5 selection sort
void selectionSort(int a[], int n)
{
	int i, j, min_idx;
	//di chuyen ranh gioi cua mang da sap xep va chua sap xep
	for (i = 0;i < n - 1; i++)
	{
		// tim phan tu nho nhat trong mang chua sap xep
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[min_idx])
				min_idx=j;

		//doi cho phan tu nho nhat vs phan tu dau tien
		swap(a[min_idx], a[i]);
	}
}
//cau 1.6 interchangeSort
void interchangeSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for(int j = i + 1; j < n; j++)
			if (a[i] > a[j])
				swap(a[i], a[j]);//doi cho a[i] va a[j]
}
//cau 1.7 bubble sort
void bubbleSort(int arr[], int n)
{
	int i,j;
	bool haveSwap = false;
	for (i = 0; i < n - 1; i++)
	{
		//i phan tu cuoi cung da duoc sap xep
		haveSwap = false;
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j]> arr[j + 1])
			{
					swap(arr[j], arr[j + 1]);
					haveSwap = true;
			}
		}
		//neu ko co swap nao duoc thuc hien => mang da duoc sap xep
		if (haveSwap == false)
		{
			break;
		}
	}
  }
//cau 1.8 quick Sort
void QuickSort(int a[], int left, int right)
{
	int x = a[(left + right)/2];
	int i = left;
	int j = right;
	while (i<j)
	{
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;
		if (i <= j)
		{
			swap(a[i], a[j]);// doi cho a[i] va a[j]
			i++;
			j--;
		}
	}
	if (left < j)
		QuickSort(a, left, j);
	if (i < right)
		QuickSort(a,i, right);
}
//cau 1.9
void heapify(int a[],int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && a[l] > a[largest])
		largest = l;
	if (r < n && a[r] > a[largest])
		largest = r;
	if (largest !=i)
	{
		swap(a[i], a[largest]);
		heapify(a, n, largest);
	}
}

//main function to do heap sort
void heapSort(int a[],int n)
{
	for(int i = n / 2- 1; i >= 0; i--)
		heapify(a,n,i);
	for (int i= n -1; i>=0; i--)
	{
		swap (a[0],a[i]);
		heapify(a, i , 0);
	}
}
//cau 1,9 HeapSort sgk
void shift(int a[], int i, int n)
{
	int j = 2 * i + 1;
	if (j >= n) //neu vi tri j khong ton tai trong danh sach dang xet thi thoat
		return;
	if (j+1 < n) //neu ton tai vi tri j+1 trong danh sach dang xet
		if (a[j] <a[j+1])//neu phan tu a[j] < a[j+1]
			j++; // luu vi tri phan tu lan hon trong hai phan tu vi tri j
	if (a[i] >= a[j])//xet a[i] la phan tu lon nhat trong 2 phan tu a[i], a[2*i+1], a[2*i+2]
		return; //Thoat khoi chuong trinh
	else // a[i] khong la phan tu lon nhat trog 3 phan tu  a[i], a[2*i+1], a[2*i+2]
	{
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
		shift(a, j, n); //xet tinh lan truyen tai vi tri phan tu vua hoan doi
	}
}

void HeapSort(int a[], int n)
{
	int i = n / 2 - 1;
	while (i >= 0) // Tao heap ban dau
	{
		shift(a, i, n);
		i--;
	}
	int right = n - 1;//Right la vi tri cuoi cung heap dang xet
	while (right > 0)
	{
		swap(a[0], a[right]);//hoan vi phan tu a[0] cho phan tu cuoi heap dang xet
		right--;//gioi han phan tu cuoi day dang xet
		if(right > 0)//kiem tra day dang xet con nhieu hon 1 phan tu
			shift(a, 0, right);// tao heap lai vi tri 0
	}
}
//cau 1.10
void searchSequence(int a[], int n, int x)
{
	int i = 0;
	while (i < n &&a[i] != x)
	{
		i++;
	}
	if (i == n)
	{
		cout << "khong tim thay";
	}
	else
	{
	cout <<" tim thay vi tri " << i;
	}
}
//cau 1.11
int searchBinary(int a[], int l, int r, int x)
{
	if (r >= 1)
	{
		int mid = 1 + (r - 1)/2;
		// neu a[mid] = x, tra ve chi so va ket thuc
		if (a[mid] == x)
			return mid;

		//neu a[mid] > x, thuc hien tim kiem nua trai cua mang
		if (a[mid] > x)
			return searchBinary(a, l, mid - 1, x);

		//neu a[mid] < x, thuc hien tim kiem nua phai cua mang
		return searchBinary(a, mid + 1,r ,x);
	}

	//neu ko tim thay
	return -1;
}

int main()
{
	int b[MAX];
	clock_t start;
	double duration;
	int choice, x, i;
	system("cls");
	cout<<" bai tap 1, chuong 3 , xep thu tu va tim kiem";
	cout<<" 0. Khoi tao danh sach ngau nhien"<<endl;
	cout<<" 1. Nhap danh sach" <<endl;
	cout<<" 2. Xuat danh sach" <<endl;
	cout<<" 3. Xep thu tu danh sach bang SELECTION SORT" <<endl;
	cout<<" 4. Xep thu tu danh sach bang INSETION SORT" <<endl;
	cout<<" 5. Xep thu tu danh sach bang BUBBLE SORT" <<endl;
	cout<<" 6. Xep thu tu danh sach bang INTERCHANGE SORT" <<endl;
	cout<<" 7. Xep thu tu danh sach bang  QUICK SORT" <<endl;
	cout<<" 8. Xep thu tu danh sach bang  HEAP SORT" <<endl;
	cout<<" 9. Tim kiem phan tu x bang TIM KIEM TUAN TU" <<endl;
	cout<<" 10. Tim kiem phan tu x bang TIM KIEM NHI PHAN" <<endl;
	cout<<" 11. Thoat" <<endl;
	do
	{
		cout<<"\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		    case 0:
				init(a,n);
				break;
			case 1:
				input(a,n);
				break;
			case 2:
				cout << "Danh sach la" <<endl;
				output(a,n);
				break;
			case 3:
				CopyArray(a,b,n);
				start = clock();
				selectionSort(b,n);
				duration = (clock() - start / (double) CLOCKS_PER_SEC);
				if (n<100)
				{
					cout<<"DS sau khi xep thu tu voi SELECTION SORT la: "<<endl;
					output(b,n);
				}
				if(duration > 0)
					cout<<"thoi gian SELECTION SORT :"<< duration * 1000000 <<"Micriosecond"<<endl;
				break;
			case 4:
				CopyArray(a,b,n);
				start = clock();
				insertionSort(b,n);
				duration = (clock() - start) / (double) CLOCKS_PER_SEC;
				if(n<100)
				{
					cout<<"DS sau khi xep thu tu vs INSERTION SORT"<<endl;
					output(b,n);
				}
				if(duration > 0)
					cout<<"thoi gian INSERTION SORT :"<< duration * 1000000 <<"Micriosecond"<<endl;
				break;
				case 5:
					CopyArray(a,b,n);
					start = clock();
					bubbleSort(b,n);
					duration = (clock() - start) / (double) CLOCKS_PER_SEC;
					if(n<100)
					{
						cout<<"DS sau khi xep thu tu vs BUBBLE SORT"<<endl;
						output(b,n);
					}
					if(duration > 0)
						cout<<"thoi gian BUBBLE SORT :"<< duration * 1000000 <<"Micriosecond"<<endl;
				break;
				case 6:
					CopyArray(a,b,n);
					start = clock();
					interchangeSort(b,n);
					duration = (clock() - start) / (double) CLOCKS_PER_SEC;
					if(n<100)
					{
						cout<<"DS sau khi xep thu tu vs INTERCHANGE SORT la: "<<endl;
						output(b,n);
					}
				if(duration > 0)
					cout<<"thoi gian INTERCHANGE SORT :"<< duration * 1000000 <<"Micriosecond"<<endl;
				break;
				case 7:
					CopyArray(a,b,n);
					start = clock();
					QuickSort(b,0,n-1);
					duration = (clock() - start) / (double) CLOCKS_PER_SEC;
					if(n<100)
					{
						cout<<"DS sau khi xep thu tu vs Quick SORT la: "<<endl;
						output(b,n);
					}
				if(duration > 0)
					cout<<"thoi gian Quick SORT :"<< duration * 1000000 <<"Micriosecond"<<endl;
				break;
				case 8:
					CopyArray(a,b,n);
					start = clock();
					heapSort(b,n);
					duration = (clock() - start) / (double) CLOCKS_PER_SEC;
					if(n<100)
					{
						cout<<"DS sau khi xep thu tu vs Heap SORT la: "<<endl;
						output(b,n);
					}
				if(duration > 0)
					cout<<"thoi gian Heap SORT :"<< duration * 1000000 <<"Micriosecond"<<endl;
				break;
				case 9:
					cout<<"Vui long nhap gia tri x=";
					cin>>x;
					start = clock();
					searchSequence(a,n,x);
					duration = (clock() - start) / (double) CLOCKS_PER_SEC;
					if(duration > 0)
						cout<<"\n-thoi gian tim kiem tuan tu la :"<< duration * 1000000 <<"Micriosecond"<<endl;
					break;
				case 10:
					cout<<"Vui long nhap gia tri x=";
					cin>>x;
					start = clock();
					i=searchBinary(b,0,n,x);
					duration = (clock() - start) / (double) CLOCKS_PER_SEC;
					if(i==-1)
						cout<<"khong tim thay x="<<x<<"trong day !"<<endl;
					else
						cout<<"tim thay x="<<x<<"tai vi tri i="<<i<<endl;
					if(duration > 0)
						cout<<"\n-Thoi gian tim kiem nhi phan la :"<< duration * 1000000 <<"Micriosecond"<<endl;
					break;
				case 11:
					cout<< "Goodbye ....!"<<endl;
					break;				
			default:
				break;
		}
	}while(choice!=11);

	system("pause");
	return 0;
}

