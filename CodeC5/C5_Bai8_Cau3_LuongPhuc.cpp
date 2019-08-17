//Bai 8, chuong 5
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

#define MAX 20
int A[MAX][MAX];
int n;
char verter[MAX];

///QUEUE

struct Node
{
	int info;
	Node *link;
};

Node *front, *rear;
void InitQueue()
{
	front = NULL;
	rear = NULL;
}
int isEmptyQ()
{
	if(front == NULL)
		return 1;
	return 0;
}
void PushQ(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = NULL;
	if(rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}
int PopQ(int &x)
{
	if(front != NULL)
	{
		Node *p = front;
		front = p->link;
		x = p->info;
		if(front == NULL)
		{
			rear = NULL;
		}
		delete p;
		return 1;
	}
	return 0;
}
///end QUEUE

void InitGraph()
{
	n=0;
}

void inputGraphFromText()
{
	string line;
	ifstream myfile("matranke1.txt");
	if(myfile.is_open())
	{
		myfile >> n;
		for(int i=0; i<n; i++)
			myfile>>verter[i];
		for(int i=0;i<n;i++)
		{
			for(int j=0; j<n; j++)
				myfile>>A[i][j];
		}
	}
}


void inputGraph()
{
	cout << "Nhap so dinh do thi n: ";
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cout << "Nhap ten dinh: ";
		cin >> verter[i];
		cout << "Nhap vao dong thu " << i+1 << ": ";
		for(int j=0; j<n; j++)
			cin >> A[i][j];
	}
}

void outputGraph()
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			cout << A[i][j]<< "  ";
		cout << endl;
	}
}
void output(int a[], int n)
{
	for(int i=0; i<n; i++)
		cout << verter[a[i]] << "  ";
}

//BFS
int C[100], bfs[100];
int nbfs=0;
void InitC()
{
	for(int i=0; i<n; i++)
		C[i]=1;
}
void BFS(int v)
{
	int w, p;
	PushQ(v);
	C[v]=0;
	while(front != NULL)
	{
		PopQ(p);
		bfs[nbfs]=p;
		nbfs++;
		for(w=0; w<n; w++)
			if(C[w] && A[p][w]==1)
			{
				PushQ(w);
				C[w]=0;
			}
	}
}
int main()
{
	int a[MAX];
	int b[MAX];
	int choice, sp, sp_b, x, i;
	system("cls");
	cout << "-----BAI TAP 4, CHUONG 5, DO THI-----\n";
	cout << "1. Khoi tao MA TRAN KE rong\n";
	cout << "2. Nhap MA TRAN KE tu file text\n";
	cout << "3. Nhap MA TRAN KE\n";
	cout << "4. Xuat MA TRAn KE\n";
	cout << "5. Duyet do thi theo chieu rong BFS - DSLK\n";
	cout << "6. Thoat\n";
	do{
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			InitGraph();
			cout << "Ban vua khoi tao MA TRAN KE rong thanh cong!\n";
			break;
		case 2:
			inputGraphFromText();
			cout << "Ban vua nhap MA TRAN KE tu file: \n";
			outputGraph();
			break;
		case 3:
			inputGraph();
			break;
		case 4:
			outputGraph();
			break;
		case 5:
			InitQueue();
			InitC();
			cout << "Vui long nhap dinh xuat phat: ";
			cin >> x;
			nbfs=0;
			BFS(x);
			cout << "Thu tu dinh sau khi duyet BFS: \n";
			output(bfs, n);
			break;
		case 6:
			cout << "Good bye...!!!\n";
			break;
		default:
			break;
		}
	}while(choice!=6);
	system("pause");
	return 0;
}