#include <stdio.h>
#include <iostream>
using namespace std;


#define COUNT 5


struct Node
{
	int info;
	Node*left;
	Node*right;
};
Node*Root;
// Khoi tao cay nhi phan tim kiem
void InitTree()
{
	Root = NULL;
}
// them mot phan tu khong dung de quy
void InsertNode(int x)
{
	Node *p = Root;
	Node *q;
	int flag = 0;
	while( p != NULL)
	{
		q= p;
		if(p->info == x)
			return;
		else if( p->info > x)
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
	
	if(Root == NULL)
	{
		Root = p;
		return ;
	}
	if(flag == 1) //left
		q->left = p;
	else
		q->right = p;
}

// Câu 2.5: Xóa một nút dùng đệ quy
void SearchStandFor(Node *&p, Node *&q)
{
	if (q -> left == NULL)
	{
		p-> info =q -> info;
		p =q;
		q= q -> right;
	}
	else
		SearchStandFor(p,q -> left);
}

int Delete(Node *&T, int x)
{
	if (T == NULL)
		return 0;
	if (T ->info == x)
	{
		Node *p =T;
		if (T -> left == NULL) //Bậc 1
			T = T ->right;
		else if (T ->right == NULL) //Bậc 1
			T = T-> left;
		else //có 2 con
			SearchStandFor(p, T ->right);
		delete p;
		return 1;
	}
	if (T ->info < x)
		return Delete(T->right,x);
	if (T ->info > x)
		return Delete(T->left,x);
}


// In Cay nhi phan
void print2DUtil( Node *p, int space)
{
	// Base case
	if( p == NULL)
		return;

	// Increase distance between levels
	space += COUNT;

	// Processm right child first
	print2DUtil( p->right, space);

	// Print current node after space
	// count
	cout<<endl;
	for ( int i = COUNT ; i < space; i++)
		cout<<"  ";
	cout<<p->info<<"\n";

	//Process left child
	print2DUtil(p ->left, space);
}

// Wrapper over print2DUtuil()
void Process_Tree()
{
	// Pass initial space count as 0
	print2DUtil(Root, 0);
}
int main()
{
	int choice = 0;
	int x, i;
	Node *p;
	system("cls");
	cout<<"---------BAI TAP 1, CHUONG 4: CAY NHI PHAN TIM KIEM------"<<endl;
	cout<<"1. Khoi tao cay NPTK rong "<<endl;
	cout<<"2. Them phan tu vao cay NPTK khong dung de quy "<<endl;
	cout<<"3. Xuat"<<endl;
	cout<<"4. Xoa mot phan tu dung DE QUY"<<endl;
	cout<<"5. Thoat"<<endl;
	do
	{
		cout<<" Vui long chon so de thuc hien : ";
		cin>> choice;
		switch(choice)
		{
			case 1:
			InitTree();
			cout<<" Ban vua khoi tao thanh cong cay NPTK"<<endl;
			break;
			case 2:
				cout<<" Nhap phan tu can them: "<<endl;
				cin>>x;
				InsertNode( x);
				cout<<"Cay sau khi them la: "<<endl;
				Process_Tree();
				break;
			case 3:
				cout<<"Cay nhi phan la: "<<endl;
				Process_Tree();
				break;
			case 4:
				cout<< "Vui long nhap gia tri x can xoa";
				cin>>x;
				i = Delete(Root, x);
				if( i == 0)
					cout<<"Khong tim thay x= "<<x<< "de xoa!"<<endl;
				else
				{
					cout<< "Da xoa thanh cong phan tu x= "<<x<< "trong cay NPTK"<<endl;
					cout<< "Cay NPTK sau khi xoa la: ";
					Process_Tree();
				}
				break;
			case 5:
				cout<<" Thoat "<<endl;
				break;
			default:
				break;
		}
	}
	while(choice != 5);
		system("pause");
	return 0;

}