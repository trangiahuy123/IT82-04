//Bài 1, Chương 4: CÂY NHỊ PHÂN TÌM KIẾM
#include <stdio.h>
#include <iostream>
using namespace std;

#define COUNT 10

//Câu 1.1: Khai báo cấu trúc cây NPTK
struct Node
{
	int info;
	Node *left;
	Node *right;
};
Node *root;

//Câu 1.2: Khởi tạo cây rỗng
void init()
{
	root = NULL;
}

//Câu 1.3: Thêm một phần tử sử dụng Đệ Quy, sử dụng địa chỉ con trỏ
void InsertNode(Node *&p, int x)
{
	if (p == NULL)
	{
		p= new Node;
		p ->info = x;
		p -> left = NULL;
		p -> right = NULL;
	}
	else
	{
		if(p->info == x)
			return; //đã có node giá trị x
		else if (p -> info > x)
			return InsertNode(p-> left,x);
		else
			return InsertNode(p->right, x);
	}
}

//Câu 1.3: Thêm một phần tử sử dụng Đệ Quy, không sử dụng địa chỉ con trỏ
int Insert_Node_Recursive(int x, Node *q)
{
	if (q -> info == x)
		return 0;
	else if (q-> info > x)
	{
		if(q->left == NULL)
		{
			Node *p = new Node;
			p -> info = x;
			p -> left = NULL;
			p -> right = NULL;
			q -> left = p;
			return 1;
		}
		else
			return Insert_Node_Recursive(x,q -> left);
	}
	else
	{
		if(q -> right == NULL)
		{
			Node *p = new Node;
			p -> info = x;
			p -> left = NULL;
			p -> right = NULL;
			q -> right = p;
			return 1;
		}
		else
			return Insert_Node_Recursive(x,q -> right);
	}
	
}

//Câu 1.4: Tìm một phần tử dùng Đệ Quy
Node *Search(Node *p, int x)
{
	if(p != NULL)
	{
		if (p -> info == x)
			return p;
		else
			if(x > p -> info)
				return Search(p -> right, x);
			else
				return Search(p -> left, x);
	}
	return NULL;
}

//Câu 1.5: Xóa một nút trong cây dùng Đệ Quy
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

//Câu 1.6: Duyệt cây theo NLR dùng Đệ Quy
void DuyetNLR(Node *p)
{
	if (p != NULL)
	{
		cout<<p->info<<" ";
		DuyetNLR(p ->left);
		DuyetNLR(p ->right);
	}
}

//Câu 1.7: Duyệt cây theo LNR dùng Đệ Quy
void DuyetLNR(Node *p)
{
	if (p != NULL)
	{
		DuyetLNR(p ->left);
		cout<<p->info<<" ";
		DuyetLNR(p ->right);
	}
}

//Câu 1.8:Duyệt cây theo LRN dùng Đệ Quy
void DuyetLRN(Node *p)
{
	if (p != NULL)
	{
		DuyetLRN(p ->left);
		DuyetLRN(p ->right);
		cout<<p->info<<" ";
	}
}

void print2DUtil(Node *p, int space)
{
	//Base case
	if (p == NULL)
		return;

	//Increase distance between levels
	space += COUNT;

	//Process right child first
	print2DUtil(p ->right, space);

	//Print current node after space
	//cout
	cout<<endl;
	for(int i = COUNT; i < space; i++)
		cout << " ";
	cout<<p ->info<<"\n";

	//Process left child
	print2DUtil(p ->left, space);
}

//Wrapper over print2DUtil()
void Process_Tree()
{
	//Pass initial space count as 0
	print2DUtil(root, 0);
}

int main()
{
	int choice = 0;
	int x,i;
	Node *p;
	system("cls");
	cout<<" -------BAI TAP 1, CHUONG 4: CAY NHI PHAN TIM KIEM------- "<<endl;
	cout<<"1. Khoi tao cay NPTK rong"<<endl;
	cout<<"2. Them phan tu vao cay NPTK"<<endl;
	cout<<"3. Tim phan tu co gia tri x trong cay NPTK"<<endl;
	cout<<"4. Xoa phan tu co gia tri x trong cay NPTK"<<endl;
	cout<<"5. Duyet cay NPTK theo NLR"<<endl;
	cout<<"6. Duyet cay NPTK theo LNR"<<endl;
	cout<<"7. Duyet cay NPTK theo LRN"<<endl;
	cout<<"8. Xuat cay NPTK"<<endl;
	cout<<"9. Thoat"<<endl;
	do
	{
		cout<<"\nVui long chon so de thuc hien: ";
		cin>>choice;
		switch(choice)
		{
		    case 1:
				init();
				cout<< "Ban vua khoi tao cay NPTK thanh cong! \n";
				break;
			case 2:
				cout<< "Vui long nhap gia tri x can them: ";
				cin>>x;
				InsertNode(root,x);
				cout<< "Cay NPTK sau khi them la: ";
				Process_Tree();
				break;
			case 3:
				cout<< "Vui long nhap gia tri x can tim: ";
				cin>>x;
				p = Search(root,x);
				if(p!= NULL)
					cout<<"Tim thay x= "<<x<< "trong cay NPTK"<<endl;
				else
					cout<<"Khong tim thay x= "<<x<< "trong cay NPTK"<<endl;
				break;
			case 4:
				cout<< "Vui long nhap gia tri x can xoa";
				cin>>x;
				i = Delete(root, x);
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
				cout << "Cay NPTK duyet theo NLR la: ";
				DuyetNLR(root);
				break;
			case 6:
				cout << "Cay NPTK duyet theo LNR la: ";
				DuyetLNR(root);
				break;
			case 7:
				cout << "Cay NPTK duyet theo LRN la: ";
				DuyetLRN(root);
				break;
			case 8:
				cout<<"Cay NPTK nhu sau: ";
				Process_Tree();
				break;
			case 9:
				cout<< "Goodbye...!"<<endl;
				break;
			default:
				break;
		}
	}
	while(choice != 9);
		system("pause");
		return 0;
}