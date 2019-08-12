// Bài 5: Viết chương trình với các yêu cầu sau:
// 5.1 Viết hàm nhập danh sách kề kề của đồ thị 5.1.
// 5.2 Viết hàm xuất danh sách kề kề này ra ngoài màn hình.
// 5.3 Viết hàm duyệt đồ thị theo chiều rộng (dựa trên Queue bằng kỹ thuật cài đặt danh sách liên kết đơn).
// 5.4 Viết hàm duyệt đồ thị theo chiều sâu (dựa trên Stack bằng kỹ thuật cài đặt danh sách liên kết đơn).
// 5.5 Nhập vào một đỉnh X, hãy kiểm tra X có tồn tại trên đồ thị hay không? (dựa trên phép duyệt BFS).

#include<sstream>
#include<fstream>
#include<stdio.h>
#include<iostream>
using namespace std;

#define MAX 50

int n; // Số đỉnh trên đồ thị.
char vertex[MAX]; // Tên đỉnh.



// DSLK đơn sử dụng cho STACK, QUEUE và danh sách kề.
struct Node
{
	int info;
	Node *link;
};

Node *sp;
Node *front, *rear;

Node *First[MAX]; // Danh sách các danh sách kề.

// Lưu trữ bằng Stack.
void InitStack()
{
	sp = NULL;
}

// Kiểm tra Stack rỗng.
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
	else
		return 0;
}

// Kết thúc lưu trữ bằng STACK.

// Lưu trữ bằng QUEUE.
void InitQueue()
{
	front = NULL;
	rear = NULL;
}

// Kiểm tra Queue rỗng.
int isEmptyQueue()
{
	if (front == NULL)
		return 1;
	else
		return 0;
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
		Node *p = front;
		front = p->link; 
		x = p->info;
		if (front == NULL)
		{
			rear = NULL;
		}
		delete p;
		return 1;
	}
	else
		return 0;
}

// Kết thúc lưu trữ bằng QUEUE.

void InitGraph()
{
	n=0;
}

void Insert_Last(Node *&first, Node *p)
{
	if (first == NULL)
		first = p;
	else
	{
		Node *q = first;
		while(q->link != NULL)
		{
			q = q->link;
		}
		q->link = p;
	}
}

void InputGraphFromText()
{
	string line;
	ifstream myfile ("danhsachke1.txt");
	if (myfile.is_open())
	{
		myfile >> n;
		for (int i = 0; i < n; i++)
			myfile >> vertex[i];
		string str;
		int i = 0;
		while (getline(myfile, str))
		{
			istringstream ss(str);
			int u;
			while (ss >> u)
			{
				// Dinh u.
				Node *p = new Node;
				p->info = u;
				p->link = NULL;
				Insert_Last(First[i - 1], p);
			}
			i++;
		}
	}
}

// 5.1 Viết hàm nhập danh sách kề của đồ thị 5.1.
void InputGraph()
{
	do{
		cout << "Nhap so dinh do thi n (n > 0): ";
		cin >> n;
		if (n <= 0)
			cout << "Nhap sai roi! Nhap lai." << endl;
	} while (n <= 0);
	cout << "Nhap ten dinh: ";
	for (int i = 0; i < n; i++)
		cin >> vertex[i];
	for (int i = 0; i < n + 1; i++)
	{
		if (i > 0)
			cout << "Nhap danh sach ke cua dinh thu " << i - 1 << " (" << vertex[i - 1] << ") : ";
		int u;
		string str;
		while (getline(cin, str))
		{
			istringstream ss(str);
			while (ss >> u)
			{
				Node *p = new Node;
				p->info = u;
				p->link = NULL;
				Insert_Last(First[i - 1], p);
			}
			break;
		}
	}
}

// 5.2 Viết hàm xuất danh sách kề này ra ngoài màn hình.
void OutputGraph()
{
	for (int i = 0; i < n; i++)
	{
		cout << "Dinh " << i << " (" << vertex[i] << "): ";
		Node *p = First[i];
		while (p != NULL)
		{
			cout << p->info << " ";
			p = p->link;
		}
		cout << endl;
	}
}

void Output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << vertex[a[i]] << " ";
}

// 5.3 Viết hàm duyệt đồ thị theo chiều rộng (dựa trên Queue bằng kỹ thuật cài đặt danh sách liên kết đơn).
int c[100], bfs[100];
int nbfs = 0;
void Init()
{
	for (int i = 0; i < n; i++) // n là số đỉnh của đồ thị.
		c[i] = 1;
}

void BFS(int v) // v là đỉnh bắt đầu.
{
	int p;
	Node * w;
	PushQueue(v);
	c[v] = 0;
	while (front != NULL)
	{
		PopQueue(p);
		bfs[nbfs] = p;
		w = First[p];
		nbfs ++;
		while (w != NULL)
		{
			if (c[w->info])
			{
				PushQueue (w->info);
				c[w->info] = 0;
			}
			w = w->link;
		}
	}
}
	
// 5.4 Viết hàm duyệt đồ thị theo chiều sâu (dựa trên Stack bằng kỹ thuật cài đặt danh sách liên kết đơn)
int dfs[100];
int ndfs = 0;
void DFS(int s)
{
	PushStack(s);
	dfs[ndfs] = s;
	ndfs++;
	c[s] = 0;
	int u = s;
	Node *v = NULL;
	while (isEmptyStack() == 0)
	{
		if (v == NULL)
			PopStack(u);
		v = First[u];
		while (v != NULL)
		{
			if (c[v->info] == 1)
			{
				PushStack(u);
				PushStack(v->info);
				dfs[ndfs] = v->info;
				ndfs++;
				c[v->info] = 0;
				u = v->info;
				break;
			}
			v = v->link;
		}
	}
}

// 5.5 Nhập vào một đỉnh X, hãy kiểm tra X có tồn tại trên đồ thị hay không? (dựa trên phép duyệt BFS)
void SearchX_BFS(int x, int v) //v la dinh bat dau
{
	int p;
	Node *w;
	PushQueue(v);
	c[v] = 0;

	while (front != NULL)
	{
		PopQueue(p);
		if (x == p)
		{
			cout << "Tim thay dinh x = " << x << " trong do thi." << endl;
			return;
		}
		w = First[p];
		while (w != NULL)
		{
			if (c[w->info])
			{
				PushQueue(w->info);
				c[w->info] = 0;
			}
			w = w->link;
		}
	}
	cout << "Khong tim thay dinh x = " << x << " trong do thi." << endl;
}


int main()
{
	int choice = 0,x;
	system("cls");
	cout << "------------------- Bai tap chuong 5 - BTTH - Bai 5 ----------------------" << endl << endl;
	cout << "0. Khoi tao danh sach ke rong." << endl;
	cout << "1. Nhap danh tran ke tu file text." << endl;
	cout << "2. Nhap danh sach ke." << endl;
	cout << "3. Xuat danh sach ke." << endl;
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
				cout << "Ban vua khoi tao danh sach ke rong thanh cong. " << endl;
				break;

			case 1:
				InputGraphFromText();
				cout << "Ban vua nhap danh sach ke tu file: " << endl;
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
				InitQueue();
				Init();
				nbfs = 0;
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