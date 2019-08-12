//Bài 5, Chương 5: DO THI
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
#define MAX 20

//DSLK sử dụng cho STACK, QUEUE và DANH SÁCH KỀ
struct Node
{
	int info;
	Node *link;
};
Node *sp;
Node *front, *rear;
Node *first[MAX];//DS các DSK
int n; // số đỉnh
char vertex [MAX];//tên đỉnh

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

// Khởi tạo mảng danh sách
void InitG()
{
	n =0;
}

//Thêm một phần tử vào danh sách
void Insert_last(Node *&first, Node *p )
{
	if (first == NULL)
		first = p;
	else
	{
		Node *q = first;
		while (q->link!=NULL)
		{
			q=q->link;
		}
		q->link = p;
	}
}

//Câu 5.1:Nhập danh sách kề của đồ thị
void InputGraphFromText()
{
	string line;
	ifstream myfile ("danhsachke1.txt");
	if (myfile.is_open())
	{
		myfile>>n;
		for (int i = 0; i<n; i++)
			myfile>>vertex[i];
		string str;
		int i = 0;
		while (getline(myfile,str))
		{
			istringstream ss(str);
			int u;
			while (ss>>u)
			{
				//Đỉnh u
				Node *p = new Node;
				p->info= u;
				p-> link = NULL;
				Insert_last(first[i-1],p);
			}
			i++;
		}
	}
}
void InputG()
{
	cout<<"Nhap so dinh do thi n: ";
	cin>>n;
	cout<<"Nhap ten dinh: ";
	for (int i=0;i<n;i++)
		cin>>vertex[i];
	for (int i=0; i<n; i++)
	{
		cout<<"Nhap danh sach lien ket cua dinh thu"<<i<<" ("<<vertex[i]<<" )";
		int u;
		while (cin>>u)
		{
			Node *p = new Node;
			p-> info= u;
			p->link = NULL;
			Insert_last(first[i-1],p);
		}
	}
}

//Câu 5.2: Xuất danh sách kề
void OutputG()
{
	for (int i = 0;i<n; i++)
	{
		cout<<"Dinh"<<i<<" ("<<vertex[i]<<" ):";
		Node *p = first[i];
		while (p!= NULL)
		{
			cout<< p -> info <<" ";
			p=p->link;
		}
		cout<<endl;
	}
}

void output(int a[], int n)
{
	for (int i= 0; i <n; i++)
		cout<<vertex[a[i]]<<" ";
}
 //Câu 5.3: Duyệt đồ thị theo BFS
int C[100],bfs[100];
int nbfs =0;
void InitC()
{
	for (int i =0; i<n; i++)
		C[i] = 1;
}
void BFS (int v)// v là đỉnh đồ thị
{
	int p;
	Node *w;
	PushQ(v);
	C[v] =0;
	while (front != NULL)
	{
		PopQ(p);
		bfs[nbfs] = p;
		w = first[p];
		nbfs++;
		while (w!= NULL)
		{
			if (C[w->info])
			{
				PushQ(w->info);
				C[w->info] = 0;
				break;
			}
			w=w->link;
		}
	}
}

//Câu 5.4: Duyệt đồ thị theo DFS
int dfs[100];
int ndfs = 0;
void DFS (int s)
{
	PushS(s);
	dfs[ndfs] =s;
	ndfs++;
	C[s]=0;
	int u =s;
	Node *v=NULL;
	while (isEmptyS()==0)
	{
		if (v==NULL)
			PopS(u);
		v= first[u];
		while (v!= NULL)
		{
			if (C[v->info]==1)
			{
				PushS(u);
				PushS(v->info);
				dfs[ndfs] = v->info;
				ndfs++;
				C[v->info]=0;
				u=v->info;
				break;
			}
			v=v->link;
		}
	}
}

//Câu 5.5: Kiểm tra x có tồn tại trên đồ thị không (BFS)
void Search_BFS(int x, int v)
{
	int p;
	Node *w;
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
		w= first[p];
		while (w!= NULL)
		{
			if (C[w->info])
			{
				PushQ(w->info);
				C[w->info] =0;
				break;
			}
			w=w->link;
		}
		cout<<"Khong tim thay"<<endl;
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
				InitG();
				cout<<"Ban vua khoi tao MA TRAN KE rong thanh cong!\n";
				break;
			case 2:
				InputGraphFromText();
				cout<< "Ban vua nhap MA TRAN KE tu file: \n";
				OutputG();
				break;
			case 3:
				InputG();
				break;
			case 4:
				OutputG();
				break;
			case 5:
				InitQ();
				InitC();
				cout<<"Vui long nhap dinh xuat phat: ";
				cin>>x;
				nbfs =0;
				BFS(x);
				cout<<"Thu tu dinh sau khi duyet BFS: "<<endl;
				output(bfs,n);
				break;
			case 6:
				InitS();
				InitC();
				cout<<"Vui long nhap dinh xuat phat: ";
				cin>>x;
				ndfs =0;
				DFS(x);
				cout<<"Thu tu dinh sau khi duyet DFS: "<<endl;
				output(dfs,n);
				break;
			case 7:
				InitQ();
				InitC();
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
