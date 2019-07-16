// CHUONG 4 - BAI 1: CAY NHI PHAN TIM KIEM
#include<stdio.h>;
#include<iostream>;
using namespace std;

#define COUNT 10

// CAU 1.1: Khai bao cau truc cay nhi phan
struct Node
{
	int info;
	Node *left;
	Node *right;
};

Node *root;


// CAU 1.2: Khoi tao cay rong
void Tree_Empty()
{
	root = NULL;
}

// CAU 1.3(a): Them mot phan tu vao cay (DE QUY) - Su dung dia chi con tro
void Insert_Node(Node *&p, int x)
{
	if (p == NULL)
	{
		p = new Node;
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	else
	{
		if (p->info == x) //Ton tai gia tri node bang x tren cay
			return;
		else
			if (x < p->info)
				Insert_Node(p->left, x);
			else
				Insert_Node(p->right, x);
	}
}

// CAU 1.3(b): Them mot phan tu vao cay (DE QUY) - Khong su dung dia chi con tro
int Insert_Node_Recursive(Node *q, int x)
{
	if (q->info == x)
		return 0;
	else
		if (x < q->info)
		{
			if (q->left == NULL)
			{
				Node *p = new Node;
				p->info = x;
				p->left = NULL;
				p->right = NULL;
				q->left = p;
				return 1;
			}
			else
				return Insert_Node_Recursive(q->left, x);
		}
		else
			if (x > q->info)
				if (q->right == NULL)
				{
					Node *p = new Node;
					p->info = x;
					p->left = NULL;
					p->right = NULL;
					q->right = p;
					return 1;
				}
				else
					return Insert_Node_Recursive(q->right, x);
}

// CAU 1.4: Tim mot phan tu x trong cay (DE QUY)
Node *Search(Node *p, int x)
{
	if (p != NULL)
		if (p->info == x)
			return p;
		else
			if (x < p->info)
				return Search(p->left, x);
			else
				return Search(p->right, x);

	return NULL;
}

// CAU 1.5: Xoa mot node trong cay (DE QUY)
void SearchStandFor(Node *p, Node *q) //Tim diem cuc TRAI cua nhanh con ben PHAI
{
	if (q->left == NULL) /*q la diem cuc TRAI*/
	{
		p->info = q->info;
		p = q;
		q = q->right;
	}
	else
		SearchStandFor(p, q->left);
}

int Delete(Node *&T, int x)
{
	if (T == NULL)
		return 0;
	if (T->info == x)
	{
		Node *p = T;
		if (T->left == NULL) //Bac 1
			T = T->right;
		else
			if (T->right == NULL) //Bac 1
				T = T->left;
			else //Bac 2
				SearchStandFor(p, T->right);
		delete p;
		return 1;
	}
	if (x > T->info)
		return Delete(T->right, x);
	if (x < T->info)
		return Delete(T->left, x);
}

// CAU 1.6: Duyet cay theo thu tu NLR (DE QUY)
void Process_NLR(Node *p)
{
	if (p != NULL)
	{
		cout << p->info << "\t";
		Process_NLR(p->left);
		Process_NLR(p->right);
	}
}

// CAU 1.7: Duyet cay theo thu tu LNR (DE QUY)
void Process_LNR(Node *p)
{
	if (p != NULL)
	{
		Process_LNR(p->left);
		cout << p->info << "\t";
		Process_LNR(p->right);
	}
}

// CAU 1.8: Duyet cay theo thu tu LRN (DE QUY)
void Process_LRN(Node *p)
{
	if (p != NULL)
	{
		Process_LRN(p->left);
		Process_LRN(p->right);
		cout << p->info << "\t";
	}
}

// DUYET CAY NHI PHAN
void print2DUtill(Node *p, int space)
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
	int choice;
	int x;
	int i;
	Node *p;

	system("cls");

	cout << "---------- CHUONG 4 - BAI 1: CAY NHI PHAN TIM KIEM ----------" << endl;
	cout << "1. Khoi tao Cay nhi phan tim kiem" << endl;
	cout << "2. Them phan tu vao Cay nhi phan tim kiem" << endl;
	cout << "3. Tim phan tu co gia tri x trong Cay nhi phan tim kiem" << endl;
	cout << "4. Xoa phan tu co gia tri x trong Cay nhi phan tim kiem" << endl;
	cout << "5. Duyet Cay nhi phan tim kiem theo LNR" << endl;
	cout << "6. Duyet Cay nhi phan tim kiem theo NLR" << endl;
	cout << "7. Duyet Cay nhi phan tim kiem theo LRN" << endl;
	cout << "8. Duyet Cay nhi phan tim kiem" << endl;
	cout << "9. Thoat" << endl;

	do
	{
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			Tree_Empty();
			cout << "Ban vua khoi tao Cay nhi phan tim kiem thanh cong!" << endl;
			break;
		case 2:
			cout << "Nhap phan tu co gia tri x muon them vao Cay nhi phan: ";
			cin >> x;
			Insert_Node(root, x);
			cout << "Cay nhi phan hien tai la: " << endl;
			Process_Tree();
			break;
		case 3:
			cout << "Nhap phan tu co gia tri x muon tim trong Cay nhi phan: ";
			cin >> x;
			p = Search(root, x);
			if (p != NULL)
				cout << "Tim thay phan tu co gia tri x = " << x << " trong Cay nhi phan." << endl;
			break;
		case 4:
			cout << "Xoa phan tu co gia tri x trong trong Cay nhi phan: ";
			cin >> x;
			i = Delete(root, x);
			if (i == 0)
				cout << "Khong tim thay phan tu co gia tri x = " << x << " trong Cay nhi phan!" << endl;
			else
			{
				cout << "Da xoa thanh cong phan tu co gia tri x = " << x << " trong Cay nhi phan!" << endl;
				cout << "Cay nhi phan sau khi xoa la: " << endl;
				Process_Tree();
			}
			break;
		case 5:
			cout << "Cay nhi phan tim kiem duyet theo LNR la: " << endl;
			Process_LNR(root);
			cout << endl;
			break;
		case 6:
			cout << "Cay nhi phan tim kiem duyet theo NLR la: " << endl;
			Process_NLR(root);
			cout << endl;
			break;
		case 7:
			cout << "Cay nhi phan tim kiem duyet theo LRN la: " << endl;
			Process_LRN(root);
			cout << endl;
			break;
		case 8:
			cout << "Cay nhi phan hien tai la: ";
			Process_Tree();
			break;
		case 9:
			cout << "Goodbye...!" << endl;
			break;
		default:
			break;
		}
	} while (choice != 9);

	system("pause");
	return 0;
}