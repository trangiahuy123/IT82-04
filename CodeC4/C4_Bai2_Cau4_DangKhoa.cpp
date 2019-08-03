// Bài 2: Quản lý một cây nhị phân (bài làm thêm)
// 2.4. Viết thủ tục tìm một phần tử trong cây (không dùng đệ quy).

#include<stdio.h>
#include<iostream>
using namespace std;

#define COUNT 10

// 2.1 Khai báo cấu trúc cây nhị phân tìm kiếm.
struct Node
{
	int info;
	Node *left;
	Node *right;
};
Node *root;

// 2.2 Viết thủ tục khởi tạo cây rỗng.
void InitTree()
{
	root = NULL;
}


// 2.3 Thêm một phần tử vào cây (không dùng đệ quy).
void InsertNode(int x)
{
	Node *p = root;
	Node *q;
	int flag = 0;
	while(p != NULL)
	{
		q= p;
		if (p->info == x)
			return;
		else if (p->info > x)
		{
			p = p->left;
			flag = 1;
		}
		else
		{
			p = p->right;
			flag = 0;
		}

	}
	p = new Node;
	p->info = x;
	p->left = NULL;
	p->right = NULL;
	
	if (root == NULL)
	{
		root = p;
		return ;
	}
	if (flag == 1) // left lưu giá trị bên trái.
		q->left = p;
	else
		q->right = p;
}

// In cây nhị phân.
void print2DUtil( Node *p, int space)
{
	// Base case
	if (p == NULL)
		return;

	// Increase distance between levels
	space += COUNT;

	// Processm right child first
	print2DUtil (p->right, space);

	// Print current node after space
	// count
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << "  ";
	cout << p->info << endl;

	//Process left child
	print2DUtil(p ->left, space);
}

// Wrapper over print2DUtuil()
void Process_Tree()
{
	// Pass initial space count as 0
	print2DUtil(root, 0);
}

//2.4 Tim mot phan tu trong cay khong dung de quy
Node *Search(Node *root, int x) 
{
	if(root == NULL)
		return NULL;
	Node *p = root;
	while(p != NULL)
		if(p->info > x)
			p = p->left;
		else
			p = p->right;
	return p;
}

int main()
{
	int choice = 0;
	int x, i;
	Node *p;
	system("cls");
	cout << "---------Bai tap chuong 4 - Bai 2---------" << endl;
	cout << "1. Khoi tao cay NPTK rong. " <<endl;
	cout << "2. Them phan tu vao cay NPTK khong dung de quy." << endl;
	cout << "3. Xuat cay nhi phan." << endl;
	cout << "4. Tim mot phan tu trong cay khong dung de quy" << endl;
	cout << "5. Thoat." << endl << endl;
	do
	{
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
			InitTree();
			cout << "Ban vua khoi tao thanh cong cay NPTK." << endl;
			break;

			case 2:
				cout << "Nhap phan tu can them: " << endl;
				cin >> x;
				InsertNode( x);
				cout << "Cay sau khi them la: " << endl;
				Process_Tree();
				break;

			case 3:
				cout<<"Cay nhi phan la: "<<endl;
				Process_Tree();
				break;

			
			case 4:
				cout << "Nhap phan tu co gia tri x muon tim trong cay nhi phan: ";
				cin >> x;
				p = Search(root, x);
				if (p != NULL)
					cout << "Tim thay phan tu co gia tri x = " << x << " trong cay nhi phan." << endl;
				else
					cout << "Khong tim thay phan tu co gia tri x = " << x << " trong cay nhi phan." << endl;
				break;

			case 5:
				cout << "Good bye...!" << endl;
				break;
			default:
				break;
		}
	}
	while(choice != 5);
	system("pause");
	return 0;

}