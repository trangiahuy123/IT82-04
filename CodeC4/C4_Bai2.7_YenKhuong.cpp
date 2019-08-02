// CHUONG 4 - BAI 2.7: CAY NHI PHAN TIM KIEM
#include<stdio.h>
#include<iostream>
using namespace std;

#define COUNT 10

// Khai bao cau truc Cay nhi phan
struct Node_Tree
{
	int info;
	Node_Tree *left, *right;
};

Node_Tree *root;

// Khoi tao Cay nhi phan rong
void Init_Tree_Empty()
{
	root = NULL;
}

// Them phan tu vao cay
void Insert_Node(Node_Tree *&p, int x)
{
	if (p == NULL)
	{
		p = new Node_Tree;
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	else
	{
		if (p->info == x)
			return;
		else
		{
			if (x < p->info)
				Insert_Node(p->left, x);
			if (x > p->info)
				Insert_Node(p->right, x);

		}
	}
}

// Khai bao cau truc Stack
struct Node_Stack
{
	int info;
	Node_Stack *link;
};

Node_Stack *sp;

// Khoi tao Stack rong
void Init_Stack_Empty()
{
	sp = NULL;
}

// Them mot phan tu vao Stack
void Push(int x)
{
	Node_Stack *p = new Node_Stack;
	p->info = x;
	p->link = sp;
	sp = p;
}

// Lay mot phan tu ra khoi Stack
int Pop(int &x)
{
	if (sp != NULL)
	{
		Node_Stack *p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}

// Duyet cay theo tu tu LNR (dung Stack)
void Process_LNR(Node_Tree *p)
{
	if (p != NULL)
	{
		Process_LNR(p->right);
		Push(p->info);
		Process_LNR(p->left);
	}
}

// DUYET CAY NHI PHAN
void print2DUtill(Node_Tree *p, int space)
{
	//BASE CASE
	if (p == NULL)
		return;

	//INCREASE DISTANCE BETWEEN LEVELS
	space = space + COUNT;

	//PROCESS RIGHT CHILD FIRST;
	print2DUtill(p->right, space);

	//PRINT CURRENT NODE AFTER SPACE
	//COUNT
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << p->info << endl;

	//PROCESS LEFT CHILD
	print2DUtill(p->left, space);
}

void Process_Tree()
{
	//PASS INITIAL SPACE COUNT AS 0
	print2DUtill(root, 0);
}

int main()
{
	int choice, result, x;

	cout << "---------- CHUONG 4 - BAI 2.7: CAY NHI PHAN TIM KIEM ----------" << endl;
	cout << "1. Khoi tao Cay nhi phan rong" << endl;
	cout << "2. Khoi tao Stack rong" << endl;
	cout << "3. Them phan tu vao Cay nhi phan tim kiem" << endl;
	cout << "4. Duyet Cay nhi phan tim kiem" << endl;
	cout << "5. Duyet Cay nhi phan tim kiem theo LNR (su dung Stack)" << endl;
	cout << "6. Thoat" << endl;
	
	do
	{
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			Init_Tree_Empty();
			cout << "Khoi tao Cay nhi phan rong thanh cong!" << endl;
			cout << endl;
			break;
		case 2:
			Init_Stack_Empty();
			cout << "Khoi tao Stack rong thanh cong!" << endl;
			cout << endl;
			break;
		case 3:
			cout << "Nhap phan tu (x) muon them vao Cay nhi phan: ";
			cin >> x;
			Insert_Node(root, x);
			cout << "Cay nhi phan hien tai la: " << endl;
			Process_Tree();
			cout << endl;
			break;
		case 4:
			cout << "Cay nhi phan hien tai la: " << endl;
			Process_Tree();
			cout << endl;
			break;
		case 5:
			cout << "Cay nhi phan tim kiem duyet theo LRN la: " << endl;
			Process_LNR(root);
			while (sp != NULL)
			{
				Pop(x);
				cout << x << "\t";
			}
			cout << endl << endl;
			break;
		case 6:
			cout << "Goodbye...!" << endl;
			cout << endl;
			break;
		default:
			break;
		}
	} while (choice != 6);
}