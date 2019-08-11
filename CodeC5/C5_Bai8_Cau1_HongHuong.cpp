//Câu 1, bài 8, chương 5: hàm đọc file va lưu mảng hai chiều
#include <stdio.h>
#include <iostream>
#include <fstream> //cófile

using namespace std;
#define MAX 20
int A[MAX][MAX];
int vertex [MAX];
int n;
// mảng rỗng
void initG ()
{
	n=0;
}
//Mat từ file txt
void inputGraphFromText()
{
	string line;
	ifstream myfile ("do_thi_1.txt");
	if (myfile.is_open())
	{
		myfile >> n;
		for (int i = 0; i <n; i ++)
			myfile >>vertex[i];
		for (int i = 0; i <n; i++)
		{
			for(int j = 0; j < n; j++)
				myfile>>A[i][j];
		}
	}
}
// xuất
void outputG()
{
	for(int i = 0; i <n; i++)
	{
		for( int j = 0; j <n; j++)
			cout<<A[i][j]<<" ";
		cout<<endl;
	}
}

int main()
{
	int choice;
	system("cls");
	cout<<"------- BAI TAP 8, CHUONG 5: DO THI -------"<<endl;
	cout<<"1. Khoi tao MA TRAN KE rong"<<endl;
	cout<<"2. Nhap MA TRAN KE tu file text"<<endl;
	cout<<"3. Xuat MA TRAN KE"<<endl;
	cout<<"4. Thoat"<<endl;

	do
	{
		cout<<"\nVui long chon so de thuc hien: ";
		cin>> choice;
		switch (choice)
		{
		case 1:
			initG();
			cout<<"Ban vua khoi tao MA TRAN KE rong thanh cong!\n";
			break;
		case 2:
			inputGraphFromText();
			cout<< "Ban vua nhap MA TRAN KE tu file: \n";
			outputG();
			break;
		case 3:
			outputG();
			break;
		case 4:
			cout<<"Goodbye...!"<<endl;
			break;
		default:
			break;
		}
	}
	while (choice!=4);
	system("pause");
	return 0;
}
