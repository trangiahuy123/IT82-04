//Bài 4, chương 5: ĐỒ THỊ
#include <stdio.h>
#include <iostream>
#include <fstream> //cófile

using namespace std;
#define MAX 20
//Khai báo cấu trúc
int A[MAX][MAX];
int n; //số đỉnh
char vertex [MAX];//tên đỉnh

//DSLK sử dụng cho STACK và QUEUE
struct Node
{
	int info;
	Node *link;
};
Node *sp;
Node *front, *rear;

//STACK
void InitS()
{
	sp = NULL;
}
int isEmptyS()
{
	if (sp == NULL)
		return 1;
	return 0;
}
void PushS (int x)
{
	Node *p = new Node;
	p->info = x;
	p -> link =sp;
	sp = p;
}
int PopS(int &x)
{
	if (sp != NULL)
	{
		Node *p = sp;
		x = p-> info;
		sp = p -> link;
		delete p;
		return 1;
	}
	return 0;
}
//Kết thúc STACK

//QUEUE
void InitQ()
{
	front = NULL;
	rear = NULL;
}
void PushQ(int x)
{
	Node *p= new Node;
	p->info = x;
	p -> link = NULL;
	if (rear == NULL)
		front = p;
	else
		rear -> link = p;
	rear = p;
}
int PopQ(int &x)
{
	if (front != NULL)
	{
		Node *p = front;
		front = p -> link;
		x = p -> info;
		if (front == NULL)
		{
			rear = NULL;
		}
		delete p;
		return 1;
	}
	return  0;
}
// Kết thúc QUEUE

//Khởi tạo mảng rỗng
void initG ()
{
	n=0;
}

//Mat từ file txt
void inputGraphFromText()
{
	string line;
	ifstream myfile ("matranke1.txt");
	if (myfile.is_open())
	{
		myfile >> n;
		for (int i = 0; i <n; i ++)
			myfile >>vertex[i];
		for (int i = 0; i <n; i++)
		{
			for(int j = 0; j < n; j++)
				myfile>>A[i][j];
		}
	}
}
//Câu 4.1: Nhập ma trận kề đồ thị 5.1
void inputG()
{
	cout<<"Nhap so dinh do thi n: ";
	cin>>n;
	cout<<"Nhap ten dinh: ";
	for(int i =0; i <n; i++)
	{
		cin >> vertex [i];
	}
	for(int i = 0; i <n; i++)
	{
		
		cout<<"Nhap vao dong thu "<<i+1<<":";
		for( int j = 0; j <n; j++)
			cin>>A[i][j];
	}
}

//Câu 4.2: Xuất ma trận kề
void outputG()
{
	for(int i = 0; i <n; i++)
	{
		for( int j = 0; j <n; j++)
			cout<<A[i][j]<<" ";
		cout<<endl;
	}
}
void output(int a[], int n)
{
	for (int i= 0; i <n; i++)
		cout<<vertex[a[i]]<<" ";
}

//Câu 4.3: Duyệt đồ thị theo chiều rộng dùng QUEUE (bằng kỹ thuật DSLK DON)
int C[100], bfs[100];
int nbfs = 0;
void initC()
{
	for (int i = 0; i < n; i ++) //n là số đỉnh của đồ thị
		C[i] =1;
}
void BFS (int v) // v là đỉnh bắt đầu
{
	int w, p;
	PushQ(v);
	C[v] = 0;
	while ( front != NULL)
	{
		PopQ(p);
		bfs[nbfs] = p;
		nbfs++;
		for (w =0; w < n; w++)
			if(C[w] && A[p][w]==1)
			{
				PushQ(w);
				C[w] = 0;
			}
	}

}

//Câu 4.4: Duyệt đồ thị theo chiều sâu dùng STACK (bằng kỹ thuật DSLK DON)
int dfs[100];
int ndfs =0;
void DFS(int s)
{
	PushS(s);
	dfs [ndfs] =s;
	ndfs++;
	C[s] = 0;
	int v = -1, u=s;
	while (isEmptyS() ==0)
	{
		if (v==n)
			PopS(u);
		for (v =0; v< n; v++)
			if(A[u][v] != 0 && C[v] == 1)
			{
				PushS(u);
				PushS(v);
				dfs[ndfs] = v;
				ndfs++;
				C[v] = 0;
				u=v;
				break;
			}
	}

}

//Câu 4.5: Kiểm tra x có tồn tại trên đồ thị không (BFS)
void Search_BFS(int x, int v)
{
	int w,p;
	PushQ(v);
	C[v]=0;
	while (front != NULL)
	{
		PopQ(p);
		if (x == p)
		{
			cout<<"Tim thay x= "<<x<<endl;
			return;
		}
		nbfs =0;
		
		for (w =0; w <n; w++)
			if (C[w] && A[p][w] == 1)
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
	int choice, x,i;
	system("cls");
	cout<<"------- BAI TAP 4, CHUONG 5: DO THI -------"<<endl;
	cout<<"1. Khoi tao MA TRAN KE rong"<<endl;
	cout<<"2. Nhap MA TRAN KE tu file text"<<endl;
	cout<<"3. Nhap MA TRAN KE"<<endl;
	cout<<"4. Xuat MA TRAN KE"<<endl;
	cout<<"5. Duyet do thi theo chieu rong BFS -DSLK"<<endl;
	cout<<"6. Duyet do thi theo chieu sau DFS -DSLK"<<endl;
	cout<<"7. Tim dinh co gia tri x theo BFS"<<endl;
	cout<<"8. Thoat"<<endl;
	do
	{
		cout<<"\nVui long chon so de thuc hien: ";
		cin>> choice;
		switch (choice)
		{
		    case 1:
				initG();
				cout<<"Ban vua khoi tao MA TRAN KE rong thanh cong!\n";
				break;
			case 2:
				inputGraphFromText();
				cout<< "Ban vua nhap MA TRAN KE tu file: \n";
				outputG();
				break;
			case 3:
				inputG();
				break;
			case 4:
				outputG();
				break;
			case 5:
				InitQ();
				initC();
				cout<<"Vui long nhap dinh xuat phat: ";
				cin>>x;
				nbfs =0;
				BFS(x);
				cout<<"Thu tu dinh sau khi duyet BFS: "<<endl;
				output(bfs,n);
				break;
			case 6:
				InitS();
				initC();
				cout<<"Vui long nhap dinh xuat phat: ";
				cin>>x;
				ndfs =0;
				DFS(x);
				cout<<"Thu tu dinh sau khi duyet DFS: "<<endl;
				output(dfs,n);
				break;
			case 7:
				InitQ();
				initC();
				cout<<"Vui long nhap gia tri x can tim: ";
				cin>>x;
				nbfs =0;
				BFS(x);
				
				Search_BFS(x,0);
				break;
			case 8:
				cout<<"Goodbye...!"<<endl;
				break;
			default:
				break;
		}
	}
	while (choice!=8);
	system("pause");
	return 0;
}