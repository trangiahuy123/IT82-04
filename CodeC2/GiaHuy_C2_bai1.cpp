//bai 1 chuong 2 : danh sach dac
#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 100
//cau 1.1/196
int a[MAX];
int n;

//cau 1.2
void input(int a[], int &n)
{
	cout << "Nhap vao phan tu cua danh sach: ";
	cin >> n;
	cout << "Nhap vao cac phan tu cua danh sach:" <<endl;
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]=";
		cin >> a[i];
	}
}
//cau 1.3
void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
	}
	cout<<endl;
}
//cau 1.4
int search(int a[], int n, int x)
{
	int i = 0;
		while (i < n && a[i]!=x)
		{
			i++;
			if (i==n)
				return -1;
			
		}
		return i;

}
//cau 1.5
int insert_last(int a[], int &n, int x)
{
	if(n<MAX)
	{
		a[n] = x;
		n++;
		return 1;
	}
	else
		return 0;
}


//cau 1.6
int Delete_last(int a[], int )
{
	if(n>0) 
	{
		n--;
		return 1;
	}
	return 0;
}
//cau 1.7: xoa 1 phan tu tai vi tri thu i
int Delete(int a[], int &n, int i)
{
	if (i >= 0 &&i < n)
	{
		for (int j = i; j < n - 1; i++)
		{
			a[j] = a [j + 1];
		}
		n--;
		return 1;
	}
	return 0;
}
//cau 1.8
int searchAndDelete(int a[], int &n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i]==x)
		{
			Delete(a, n, i);
			return 1;
		}
	}
	return 0;
}


int main()
{
	int choice = 0;
	int x,i;
	system("cls");
	cout<<"BT 1 Chuong 2, Danh Sach Dac"<<endl;
	cout<<"1. Nhap danh sach"<<endl;
	cout<<"2. Xuat danh sach"<<endl;
	cout<<"3. Tim phan tu co gia tri X trong danh sach"<<endl;
	cout<<"4. Them phan tu vao cuoi danh sach"<<endl;
	cout<<"5. Xoa phan tu cuoi danh sach"<<endl;
	cout<<"6. xoa phan tu vi tri thu i "<<endl;
	cout<<"7. Tim phan tu voi gia tri x va xoa neu co"<<endl;
	cout<<"8. thoat"<<endl;

	do
	{
		cout<< "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			input(a, n);
			cout << "Ban vua nhap danh sach thanh cong!\n";
			break;
		case 2:
			cout << " danh sach ban nhap la : !\n";
			output(a,n);
			break;
		case 3:
			cout << "Vui long nhap x can tim: ";
			cin >> x;
			i = search(a,n,x);
			if(i== -1)
				cout<<"Tim khong thay phan tu co gia tri x="<<x<<endl;
			else
				cout<<"Tim thay tai vi tri i="<<x<<endl;
			break;
		case 4:
			cout << "Vui long nhap x can them vao cuoi DS :";
			cin>>x;
			i = insert_last(a,n,x);
			if(i==0)
				cout<<"Danh sach da day, khong the them!" <<x<<endl;
			else
			{
				cout <<"Da them phan tu x="<<i<< " vao cuoi danh sach !"<<endl;
				cout << "Danh sach khi them la: ";
				output(a, n);
			}
			break;
		case 5:
			i = Delete_last(a,n);
			if(i>0)
			{
				cout<<"Xoa thanh cong!"<<endl;
				cout << " danh sach sau khi xoa danh sach la:\n";
				output(a,n);
			}
			else
				cout<<"Danh sach dang rong, khong co phan tu nao!!"<<endl;
			break;
		case 6:
			cout<<"vui long nhap vi tri can xoa thu i=";
			cin>>i;
			i = Delete(a,n,i);
			if (i==1)
			{
				cout<<"xoa thanh cong" <<endl;
				cout<<" danh sach sau khi xoa la:\n";
				output(a,n);
			}
			else
				cout<<"khong co phan tu nao de xoa"<<endl;
			break;
		case 7:
			cout<<"vui long nhap gia tri can xoa x=";
			cin>>x;
			i = searchAndDelete(a,n,x);
			if(i==1)
			{
				cout<<"Xoa thanh cong phan tu co gia tri x="<<x<<endl;
				cout<<"danh sach sau khi xoa la:\n";
				output(a,n);
			}
			else
				cout<<"khong co phan tu nao de xoa"<<endl;
			break;
		case 8:
			cout << "goodbye!";
			break;
		default:
			break;
		}

	}while(choice!=8);
	system("pause");
	return 0;
}

