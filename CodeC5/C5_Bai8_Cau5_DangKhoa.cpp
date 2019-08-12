// Bài 8: Biểu diễn G ở ví dụ 5.11 (bằng ma trận kề) lên trên máy tính 
//và đặt tên là do_thi_1.txt (dạng file TEXT) sau đó thực hiện viết chương trình với các hàm sau:
// 8.1. Hàm đọc file do_thi_1.txt và lưu vào mảng 2 chiều.
// 8.2. Thực hiện xuất các đỉnh đồ thị theo phép duyệt DFS (dùng Queue với kỹ thuật cài đặt bằng danh sách liên kết).
// 8.3. Thực hiện xuất các đỉnh đồ thị theo phép duyệt BFS (dùng Satck với kỹ thuật cài đặt bằng danh sách liên kết).
// 8.4. Thực hiện xuất các đỉnh đồ thị theo phép duyệt BFS (dùng kỹ thuật đệ quy).
// 8.5. Thực hiện nhập vào một đỉnh x, kiểm tra x có phải là một đỉnh của đồ thị hay không?

#include <stdio.h>
#include <queue>
#include <conio.h>
#include <iostream>
#include <fstream>
using namespace std;

#define MAX 50

int n; // Số đỉnh trên đồ thị.
char vertex[MAX]; // Tên đỉnh.
int a[MAX][MAX]; // Khai báo 1 mảng 2 chiều.

void InitGraph()
{
	n=0;
}

// 8.1. Hàm đọc file do_thi_1.txt và lưu vào mảng 2 chiều.
void inputGraphFromText()
{
	string line;
	ifstream myfile ("do_thi_1.txt");
	if (myfile.is_open())
	{
		myfile >> n;
		for (int i = 0; i < n; i++)
			myfile >> vertex[i];
		for (int i = 0; i <n; i++)
		{
			for (int j = 0; j < n; j++)
				myfile >> a[i][j];
		}
	}
}

void OutputGraph()
{
	for( int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}


// Định nghĩa lớp đồ thị.
class Graph
{
private:
	int n;
	int **edge;
public:
	Graph(int size = 2);
	Graph();
	bool isConnected(int, int);
	void addEdge(int, int);
	void breadthFirstSearch(int, int);
};

Graph::Graph(int size)
{
	int i, j;
	// Xác định số đỉnh của đồ thị.
	if (size < 2)
		n = 2;
	else
		n = size;

	// Tạo ra các đỉnh của đồ thị.
	edge = new int *[n];
	for (i = 0; i < n; i++)
		edge[i] = new int[n];

	// Ta cho mặc định các đỉnh không kết nối với nhau.
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			edge[i][j] = 0;
}

Graph::Graph()
{
	for (int i = 0; i < n; i++)
		delete[] edge[i];
	delete[] edge;
}

// 8.5. Thực hiện nhập vào một đỉnh X, kiểm tra x có phải là một đỉnh của đồ thị hay không?
// Hàm kiểm tra hai đỉnh có phải là cạnh kề nhau không.
bool Graph::isConnected(int x, int y)
{
	if (edge[x - 1][y - 1] == 1)
		return true;

	return false;
}

// Tạo một cạnh nối giữa 2 đỉnh làm cho 2 đỉnh kề nhau.
void Graph::addEdge(int x, int y)
{
	if (x < 1 || x > n || y < 1 || y > n)
		return;

	edge[x - 1][y - 1] = edge[y - 1][x - 1] = 1;
}

// Hàm kiểm tra x có phải là đỉnh của đồ thị.
void Graph::breadthFirstSearch(int s, int g)
{
	if (s > n || s < 0 || g > n || g < 0)
	{
		cout << "Khong the di qua bieu do nay voi yeu cau cua ban." <<endl;
		return;
	}
	queue <int> open;
	bool* close = new bool[n];
	int i;
	int p;

	// Mặc định các đỉnh chưa được duyệt.
	for (i = 0; i < n; i++)
		close[i] = false;

	// Đưa đỉnh gốc s vào Queue open để chuẩn bị duyệt.
	open.push(s);
	cout << "Tim kiem dau tien chung ta da tim thay dinh (s): " << endl;
	while (!open.empty())
	{
		// Lấy một đỉnh ra khỏi kết nối trở thành đỉnh đang xét p.
		do
		{
			if (open.empty())
				break;

			p = open.front();
			open.pop();
		} while (close[p - 1] == true);

		// In ra đỉnh đang xét.
		cout<<p;

		// p đã được duyệt qua.
		close[p - 1] = true;

		// Kết thúc duyệt kết thúc duyệt khi tìm ra kết quả cần tìm.
		if (p == g)
			break;

		// Tìm đỉnh kề với đỉnh đang xét, đỉnh nào chưa được duyệt thì mở kết nối.
		for (i = 1; i <= n; i++)
		{
			if (isConnected(p, i) && !close[i - 1])
			{
				open.push(i);
			}
		}
	}
	cout << endl;
	delete[] close;
}

int main()
{
	int s;
	int g;
	int choice;
	system("cls");
	cout << "------------------- Bai tap chuong 5 - BTTH - Bai 8 ----------------------" << endl << endl;
	cout << "0. Khoi tao ma tran ke rong." << endl;
	cout << "1. Nhap ma tran ke tu file text." << endl;
	cout << "2. Xuat ma tra ke tu file text." << endl;
	cout << "3. Kiểm tra x có phải là một đỉnh của đồ thị hay không?" << endl;
	cout << "4. Thoat." << endl;
	do
	{
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
			case 0:
				InitGraph();
				cout << "Ban vua khoi tao ma tran ke rong thanh cong. " << endl;
				break;

			case 1:
				inputGraphFromText();
				cout<< "Ban vua nhap ma tran ke tu file: " << endl;
				OutputGraph();
				break;

			case 2:
				OutputGraph();
				break;

			case 3:
				cout << "Nhap vao dinh s can kiem tra: ";
				cin >> s;
				Graph::breadthFirstSearch(s, g);

			case 4:
				cout<<"Goodbye...!"<<endl;
				break;
			default:
				break;
		}
	}
	while (choice != 4);
	system("pause");
	return 0;
}