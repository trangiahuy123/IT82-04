// Bài 1: Quản lý một cây nhị phân (mỗi phần tử có kiểu int).
// 1.1. Khai báo cấu trúc cây nhị phân tìm kiếm.
// 1.2. Viết thủ tục khởi tạo cây rỗng.
// 1.3. Viết thủ tục thêm một phần tử vào cây (dùng đệ quy). 
// 1.4. Viết thủ tục tìm một phần tử trong cây (dùng đệ qui).
// 1.5. Viết thủ tục xóa một nut trong cây (dùng đệ quy).
// 1.6. Viết thủ tục duyệt cây theo thứ tự NLR (dùng đệ quy).
// 1.7. Viết thủ tục duyệt cây theo thứ tự LNR (dùng đệ quy).
// 1.8. Viết thủ tục duyệt cây theo thứ tự LNR (dùng đệ quy).

#include <iostream>
using namespace std;
#define COUNT 10

// 1.1. Khai báo cấu trúc cây nhị phân tìm kiếm.
struct Node
{
	int info;
	Node * left;
	Node * right;
};

Node * root;

// 1.2 Viết thủ tục khởi tạo cây rỗng.
void Init()
{
	root = NULL; // root la bien toan cuc
}

// 1.3.a Viết thủ tục thêm một phần tử vào cây (dùng đệ quy) - sử dụng địa chỉ con trỏ.
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
		if (p->info == x) // ton tai gia tri node bang x tren cay
			return;
		else
			if (x < p->info)
				Insert_Node(p->left, x);
			else
				Insert_Node(p->right, x);
	}
}

// 1.3.b Viết thủ tục thêm một phần tử vào cây (dùng đệ quy) - không sử dụng địa chỉ con trỏ.
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

// 1.4. Viết thủ tục tìm một phần tử trong cây (dùng đệ qui).
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

// 1.5. Viết thủ tục xóa một nut trong cây (dùng đệ quy).
void SearchStandFor(Node *p, Node *q) // tim diem cuc TRAI cua nhanh con ben PHAI
{
	if (q->left == NULL) //q la diem cuc TRAI
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
		if (T->left == NULL) // bac 1
			T = T->right;
		else
			if (T->right == NULL) // bac 1
				T = T->left;
			else // bac 2
				SearchStandFor(p, T->right);
		delete p;
		return 1;
	}
	if (x > T->info)
		return Delete(T->right, x);
	if (x < T->info)
		return Delete(T->left, x);
}

// 1.6. Viết thủ tục duyệt cây theo thứ tự NLR (dùng đệ quy).
void Process_NLR(Node *p)
{
	if (p != NULL)
	{
		cout << p->info << "\t";
		Process_NLR(p->left);
		Process_NLR(p->right);
	}
}

// 1.7. Viết thủ tục duyệt cây theo thứ tự LNR (dùng đệ quy).
void Process_LNR(Node *p)
{
	if (p != NULL)
	{
		Process_LNR(p->left);
		cout << p->info << "\t";
		Process_LNR(p->right);
	}
}

// 1.8. Viết thủ tục duyệt cây theo thứ tự LNR (dùng đệ quy).
void Process_LRN(Node *p)
{
	if (p != NULL)
	{
		Process_LRN(p->left);
		Process_LRN(p->right);
		cout << p->info << "\t";
	}
}

// Ham duyet cay nhi phan.
void print2DUtill(Node *p, int space)
{
	// BASE CASE
	if (p == NULL) 
		return;

	// INCREASE DISTANCE BETWEEN LEVELS
	space = space + COUNT;

	// PROCESS RIGHT CHILD FIRST;
	print2DUtill(p->right, space);

	// PRINT CURRENT NODE AFTER SPACE
	// COUNT
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << p->info << endl;

	// PROCESS LEFT CHILD
	print2DUtill(p->left, space);
}

void Process_Tree()
{
	// PASS INITIAL SPACE COUNT AS 0
	print2DUtill(root, 0);
}


int main()
{
	int choice = 0;
	int x, i;
	Node *p;
	system ("cls");
	cout << "------------------- Bai tap chuong 4 - BTTH Bai 1 ----------------------" << endl << endl;
	cout << "1. Xin chao. " << endl;
	cout << "2. Khoi tao cay nhi phan rong. " << endl;
	cout << "3. Thu tuc them mot phan tu vao cay (dung de quy). " << endl;
	cout << "4. Thu tuc tim mot phan tu vao cay (dung de quy). " << endl;
	cout << "5. Thu tuc xoa mot nut trong cay." << endl;
	cout << "6. Thu tuc duyet cay theo thu tu NLR (dung de quy). " << endl;
	cout << "7. Thu tuc duyet cay theo thu tu LNR (dung de quy). " << endl;
	cout << "8. Thu tuc duyet cay theo thu tu LRN (dung de quy). " << endl;
	cout << "9. Thoat." << endl;
	do
	{
		do{
		cout << "\nVui long chon so de thuc hien (so > 0 && so < 9): ";
		cin >> choice;
		if (choice <= 0 || choice > 9)
			cout << "Nhap sai roi! Nhap lai." << endl;
		} while (choice <= 0 || choice > 9);
		switch (choice)
		{
		case 1:
			cout << "Hello you, <3" << endl;
			break;

		case 2:
			Init();
			cout << "Ban vua khoi tao cay nhi phan tim kiem thanh cong. " << endl;
			break;

		case 3:
			cout << "Nhap phan tu co gia tri x muon them vao cay nhi phan: ";
			cin >> x;
			Insert_Node(root, x);
			cout << "Cay nhi phan hien tai la: " << endl;
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
			cout << "Xoa phan tu co gia tri x trong trong cay nhi phan: ";
			cin >> x;
			i = Delete(root, x);
			if (i == 0)
				cout << "Khong tim thay phan tu co gia tri x = " << x << " trong cay nhi phan." << endl;
			else
			{
				cout << "Da xoa thanh cong phan tu co gia tri x = " << x << " trong cay nhi phan." << endl;
				cout << "Cay nhi phan sau khi xoa la: " << endl;
				Process_Tree();
			}
			break;

		case 6:
			cout << "Cay nhi phan sau khi duyet theo thu tu NLR la: " << endl;
			Process_NLR(root);
			cout << endl;
			break;

		case 7:
			cout << "Cay nhi phan sau khi duyet theo thu tu LNR la: " << endl;
			Process_LNR(root);
			cout << endl;
			break;

		case 8:
			cout << "Cay nhi phan sau khi duyet theo thu tu LRN la: " << endl;
			Process_LRN(root);
			cout << endl;
			break;

		case 9:
			cout << "Goodbye...!" << endl;
			break;
		default:
			break;
		}
	} while(choice != 9 );
	system("pause");
	return 0;
}