#include <iostream>
using namespace std;

struct Node
{
	int info; // lưu trữ giá trị của phần tử, giá trị khóa của node
	Node *left; // left lưu địa chỉ phần tử bên trái (cây con trái)
	Node *right; //right lưu trữ địa chỉ phần tử bên phải (cây con phải)
};
Node *root;
// Khoi tao cay rong
void tree_empty()
{
	root = NULL; 
}
