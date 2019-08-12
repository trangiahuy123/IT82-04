//Chuong 4 bai 2.8 Duyet cay theo LRN dung queue
#include <iostream>
#include <stdio.h>
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

// Khai bao cau truc Queue
struct Node_Queue
{
	int info;
	Node_Queue *link;
};

Node_Queue *front, *rear;

// Khoi tao Queue rong
void Init_Queue_Empty()
{
	front = NULL;
	rear = NULL;
}

// Them mot phan tu vao Stack
void Push(int x)
{
	Node_Queue *p;
	p = new Node_Queue;
	p ->info = x;
	p->link = NULL;
	if( rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}

// Lay mot phan tu ra khoi Stack
int Pop(int &x)
{
	if (front != NULL)
	{
		Node_Queue *p = front;
		x = p->info;
		front = front->link;
		if(front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}

// Duyet cay theo tu tu LRN (dung Queue)
void Process_LRN(Node_Tree *p)
{
	if (p != NULL)
	{
		Process_LRN(p->left);
		Process_LRN(p->right);
		Push(p->info);
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
	cout << "2. Khoi tao Queue rong" << endl;
	cout << "3. Them phan tu vao Cay nhi phan tim kiem" << endl;
	cout << "4. Duyet Cay nhi phan tim kiem" << endl;
	cout << "5. Duyet Cay nhi phan tim kiem theo LRN (su dung Queue)" << endl;
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
			Init_Queue_Empty();
			cout << "Khoi tao Queue rong thanh cong!" << endl;
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
			Process_LRN(root);
			while (front != NULL)
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
