// Nhat-HNTower.cpp : Defines the entry point for the console application.
//
//#include "pch.h"
#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

struct Item_Tower { // khai báo kiểu dữ liệu tên Item_Tower
	int num; // số đĩa 
	char sour, midl, dest; // khai bóa 3 cột như trong trò chơi
	void assign(int n, char a, char b, char c){ // hàm gán từng giá trị cho các thuộc tính 
		num = n; sour = a; midl = b, dest = c; 
	} 
}; 

void haNoi_Tower(int n, char a, char b, char c) { // Hàm chuyển dĩa 
	stack<Item_Tower> sTower; // Khai báo stack kiểu Item_Tower 
	Item_Tower t; //
	int d = 0; // khai báo d = số bước
	t.assign(n, a, b, c);// gán 4 giá trị n, a, b, c cho biến t
	sTower.push(t); // đẩy t vào stack sTower
	while (sTower.empty() == false) { // stack k rỗng
		Item_Tower temp = sTower.top(); // gán giá trị trên cùng của stack = temp
		sTower.pop(); // lấy giá trị trên cùng ra
		if (temp.num == 1) {// nếu giá trị temp  được gán = 1
			d = d + 1; // số bước = số bước + 1
			cout << "Buoc thu: ";
			cout << d;
			cout << " tu ";
			cout << temp.sour;
			cout << " den ";
			cout <<	temp.dest;
			cout << "\n";
		}
		else {
			t.assign(temp.num - 1, temp.midl, temp.sour, temp.dest); // gán những giá trị này lần lượt cho n , a ,b ,c
			sTower.push(t); // đẩy biến t vừa gán vào stack
			t.assign(1, temp.sour, temp.midl, temp.dest);
			sTower.push(t);
			t.assign(temp.num - 1, temp.sour, temp.dest, temp.midl);
			sTower.push(t);
		}
	}
}



int main()
{
	int n;
	cout<<"nhap so luong phan tu : "<<endl;
	cin>>n;
	Item_Tower t;
	t.assign(n,'A','B','C');
	haNoi_Tower(n, 'A', 'B', 'C');
	system("pause");
    return 0;

}

