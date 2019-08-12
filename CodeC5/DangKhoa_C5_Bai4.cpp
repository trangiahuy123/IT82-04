// Bài 4: Viết chương trình với các yêu cầu sau:
// 4.1 Viết hàm nhập ma trận kề của đồ thị 5.1.
// 4.2 Viết hàm xuất ma trận kề này ra ngoài màn hình.
// 4.3 Viết hàm duyệt đồ thị theo chiều rộng (dựa trên Queue bằng kỹ thuật cài đặt danh sách liên kết đơn).
// 4.4 Viết hàm duyệt đồ thị theo chiều sâu (dựa trên Stack bằng kỹ thuật cài đặt danh sách liên kết đơn).
// 4.5 Nhập vào một đỉnh X, hãy kiểm tra X có tồn tại trên đồ thị hay không? (dựa trên phép duyệt BFS).

#include<stdio.h>
#include<iostream>
using namespace std;
#include<fstream>

#define MAX 20
int a[MAX][MAX]; // Khai báo mảng 2 chiều.
int n; // Số đỉnh trên đồ thị.
char vertex[MAX]; // Tên đỉnh.

// DSLK đơn sử dụng cho STACK và QUEUE.
struct Node
{
	int info;
	Node *link;
};

Node *sp;
Node *front, *rear;


// Lưu trữ bằng Stack.
void InitStack()
{
	sp = NULL;
}

int isEmptyStack()
{
	if (sp == NULL)
		return 1;
	return 0;
}

void PushStack(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}

int PopStack(int &x)
{
	if (sp != NULL)
	{
		Node *p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}

// Kết thúc lưu trữ bằng STACK.

// Lưu trữ bằng QUEUE.
void InitQueue()
{
	front = NULL;
	rear = NULL;
}

void PushQueue(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = NULL;
	if (rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}

int PopQueue(int &x)
{
	if (front != NULL)
	{
		Node *p;
		front = p;
		x = p->info;
		if (front == NULL)
		{
			rear = NULL;
		}
		delete p;
		return 1;
	}
	return 0;
}

// Kết thúc lưu trữ bằng QUEUE.

void InitGraph()
{
	n = 0;
}

void InputGraphFromText()
{
	string line;
	ifstream myfile ("matranke1.txt");
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

// 4.1 Viết hàm nhập ma trận kề của đồ thị 5.1.
void InputGraph()
{
	do{
		cout << "Nhap so dinh phan tu n (n > 0): ";
		cin >> n;
		if (n <= 0)
			cout << "Nhap sai roi! Nhap lai." << endl;
	} while (n <= 0);
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap ten dinh: ";
		cin >> vertex[i];
		cout << "Nhap vao dong thu: " << i+1 <<": ";
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	}
}

// 4.2 Viết hàm xuất ma trận kề này ra ngoài màn hình.
void OutputGraph()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}

void Output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << vertex[a[i]] << " ";
}

// 4.3 Viết hàm duyệt đồ thị theo chiều rộng (dựa trên Queue bằng kỹ thuật cài đặt danh sách liên kết đơn)
int c[100], bfs[100];
int nbfs = 0;
void Init()
{
	for (int i = 0; i < n; i++) // n là số đỉnh của đồ thị.
		c[i] = 1;
}

void BFS(int v) // v là đỉnh bắt đầu.
{
	int w, p;
	PushQueue(v);
	c[v] = 0;
	while (front != NULL)
	{
		PopQueue(p);
		bfs[nbfs] = p;
		nbfs ++;
		for (w = 0; w < n; w++)
			if (c[w] && a[p][w] == 1)
			{
				PushQueue (w);
				c[w] = 0;
			}
	}
}

// 4.4 Viết hàm duyệt đồ thị theo chiều sâu (dựa trên Stack bằng kỹ thuật cài đặt danh sách liên kết đơn)
int dfs [100];
int ndfs = 0;
void DFS(int s)
{
	PushStack(s);
	dfs[ndfs] = s;
	ndfs++;
	c[s] = 0;
	int v = -1, u = s;
	while (isEmptyStack() == 0)
	{
		if (v == n)
			PopStack(u);
		for (v = 0; v < n; v++)
			if (a[u][v] != 0 && c[v] == 1)
			{
				PushStack(u);
				PushStack(v);
				dfs[ndfs] = v;
				ndfs++;
				c[v] = 0;
				u = v;
				break;
			}
	}
}

// 4.5 Nhập vào một đỉnh X, hãy kiểm tra X có tồn tại trên đồ thị hay không? (dựa trên phép duyệt BFS)
void SearchX_BFS(int x, int v) // v là đỉnh bắt đầu search.
{
	int w, p;
	PushQueue(v);
	c[v] = 0;
	while (front != NULL)
	{
		PopQueue(p);
		if (x == p)
		{
			cout << "Tim thay x = " << x << endl;
			return;
		}
		for (w = 0; w < n; w++)
			if (c[w] && a[p][w] == 1)
			{
				PushQueue(w);
				c[w] = 0;
			}
	}
}

int main()
{
	int a[MAX];
	int b[MAX];
	int choice = 0;
	int sp, sp_b, x, i;
	system("cls");
	cout << "------------------- Bai tap chuong 5 - BTTH - Bai 4 ----------------------" << endl << endl;
	cout << "0. Khoi tao ma tran ke rong." << endl;
	cout << "1. Nhap ma tran ke tu file text." << endl;
	cout << "2. Nhap ma tran ke." << endl;
	cout << "3. Xuat ma tran ke." << endl;
	cout << "4. Duyet do thi theo chieu rong BFS - DSLK." << endl;
	cout << "5. Duyet do thi theo chieu sau DFS - DSLK." << endl;
	cout << "6. Kiem tra dinh X theo BFS." << endl;
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
				cout << "Ban vua khoi tao ma tran ke rong thanh cong. " << endl;
				break;

			case 1:
				InputGraphFromText();
				cout << "Ban vua nhap ma tran ke tu file: " << endl;
				OutputGraph();
				break;

			case 2:
				InputGraph();
				break;

			case 3:
				OutputGraph();
				break;
		
			case 4:
				InitQueue();
				Init();
				cout << "Vui long nhap dinh xuat phat: ";
				cin >> x;
				nbfs = 0;
				BFS(x);
				cout << "Thu tu dinh sau khi duyet BFS: " << endl;
				Output(bfs, n);
				break;

			case 5:
				InitStack();
				Init();
				cout << "Vui long nhap dinh xuat phat: ";
				cin >> x;
				nbfs = 0;
				DFS(x);
				cout << "Thu tu dinh sau khi duyet DFS: " << endl;
				Output(dfs, n);
				break;

			case 6:
				cout << "Vui long nhap gia tri x can tim: ";
				cin >> x;
				SearchX_BFS(x, 0);
				break;

			case 7:
				cout << "Good bye...!" << endl;
		}
	} while(choice != 7);
	system("pause");
	return 0;
}