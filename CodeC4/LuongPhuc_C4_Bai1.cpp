#include <iostream>
#include <stdio.h>
using namespace std;

#define COUNT 10

//1.1 khai bao cau truc NPTK
struct Node
{
	int info;
	Node *left;
	Node *right;
};

Node *root;

//1.2 Tao cay rong
void init()
{
	root = NULL;

}

//1.3them ptu vao cay
void InsertNode (Node *&p, int x)
{
	if(p == NULL)
	{
		p = new Node;
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	else
	{
		if(p->info == x)
			return;
		else if( p->info > x)
			return InsertNode(p->left, x);
		else
			return InsertNode(p->right, x);
	}
}
//them ptu khong su dung De quy, khong dung dia chi con tro
int Insert_Node_Recursive(int x, Node *q)
{
	if(q->info == x)
		return 0;
	else if(q->info > x)
	{
		
		if(q->left == NULL){
			Node *p = new Node;
			p->info = x;
			p->left = NULL;
			p->right = NULL;
			q->left = p;
			return 1;
		}
		else
			return Insert_Node_Recursive(x, q->left);
	}
	else
	{
		if(q->right == NULL)
		{
			Node *p = new Node;
			p->info = x;
			p->left = NULL;
			p->right = NULL;
			q->right = p;
			return 1;
		}
		else
			return Insert_Node_Recursive(x, q->right);
	}
}

//1.4 tim 1 ptu dung Dequy
Node *Search(Node *p, int x)
{
	if(p != NULL)
	{
		if(p->info == x)
			return p;
		else
			if(x > p->info)
				return Search(p->right, x);
			else
				return Search(p-> left, x);
	}
	return NULL;
}

//1.5 xoa 1 ptu dung de quy
void SearchStandFor(Node *&p, Node *&q)
{
	if(q->left == NULL)
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
	if(T ==NULL)
		return 0;
	if(T ->info == x)
	{

		Node *p = T;
		if(T->left == NULL)
			T= T->right;
		else if(T->right == NULL)
			T = T->left;
		else
			SearchStandFor(p, T->right);
		delete p;
		return 1;
	}
	if(T->info < x)
		return Delete(T->right, x);
	if(T->info > x)
		return Delete(T->left, x);
}

//1.6 duyet cay theo NLR, dung dequy
void DuyetNLR(Node *p)
{
	if(p != NULL)
	{
		cout << p->info  << " ";
		DuyetNLR(p->left);
		DuyetNLR(p->right);
	}
}

//1.7 Duyet cay theo LNR dungdequy
void DuyetLNR(Node *p)
{
	if(p != NULL)
	{
		DuyetLNR(p->left);
		cout << p->info  << " ";
		DuyetLNR(p->right);
	}
}

//1.8 Duyet cay theo LRN dungdequy
void DuyetLRN(Node *p)
{
	if(p != NULL)
	{
		DuyetLRN(p->left);
		DuyetLRN(p->right);
		cout << p->info  << " ";
	}
}

void print20Util(Node *p, int space)
{
	//Base case
	if(p == NULL)
		return;
	//Increase distance between levels
	space += COUNT;
	
	//Process right child first
	print20Util(p->right, space);

	//print current node after space
	cout << endl;
	for(int i = COUNT; i < space; i ++)
		cout << " ";
	cout << p->info << "\n";

	//Process left child
	print20Util(p->left, space);
}

//wrapper over print20Util()
void Process_tree()
{
	//pass initial space count as 0
	print20Util(root, 0);
}

int main()
{
	int choice = 0;
	int x, i;
	Node *p;
	system("cls");
	cout <<  "-----BAITAP1, CHUONG 4: CAY NHI PHAN TIM KIEM ----" <<	endl;
	cout << "1. khoi tao cay NPTK rong" << endl;
	cout << "2. Them ptu vao cay NPTK rong" << endl;
	cout << "3. Tim ptu co gia tri x trong cay NPTK" << endl;
	cout << "4. Xoa ptu co gtri x trong cay NPTK " << endl;
	cout << "5. Duyet cay NPTK theo NLR " << endl;
	cout << "6. Duyet cay NPTK theo LNR " << endl;
	cout << "7. Duyet cay NPTK theo LRN" << endl;
	cout << "8. Xuat cay NPTK " << endl;
	cout << "9. Thoat " << endl;
	do
	{
		cout << " Vui long chon so thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			init();
			cout << " Ban vua khoi tao cay NPTK thanh cong \n";
			break;
		case 2:
			cout << " Nhap gia tri x can them vao : ";
			cin >> x;
			InsertNode(root, x);
			cout << "Cay NPTK sau khi them la: ";
			Process_tree();
			break;
		case 3:
			cout << " Nhap x can tim: ";
			cin >> x;
			p = Search(root, x);
			if(p != NULL)
				cout <<" Tim thay x= " << x << " trong cay NPTK " <<endl;
			else
				cout << " khong tim thay ";
			break;
		case 4:
			 cout << " Vui long nhap x can xoa" <<endl;
			 cin >> x;
			 i = Delete(root, x);
			 if(i == 0)
				 cout << " khong tim thay " << x << endl;
			 else
			 {
				 cout << " Xoa thanh cong "<< x << " trong cay NPTK" <<endl;
				 cout << " cay NPTK sau khi xoa la: ";
				 Process_tree();
			 }
			 break;
		case 5:
			 cout << " Cay NPTK duyet theo NLR la: ";
			 DuyetNLR(root);
			 break;
		case 6:
			 cout << " Cay NPTK duyet theo LNR la: ";
			 DuyetLNR(root);
			 break;
		case 7:
			 cout << " Cay NPTK duyet theo LRN la: ";
			 DuyetLRN(root);
			 break;
		case 8:
			cout << " Cay NPTK sau cung: ";
			Process_tree();
			break;
		case 9:
			cout << " Thoat ";
			break;
		default:
			break;

		}
	}while(choice != 9);
	system("pause");
	return 0;
}