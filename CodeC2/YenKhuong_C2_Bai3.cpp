//CHUONG 2 - BAI 3: DANH SACH LIEN KET DON
#include <stdio.h>
#include <iostream>
using namespace std;

//CAU 3.1: Khai bao cau truc danh sach
struct Node
{
	int info;
	Node *link;
};
Node *first;

//CAU 3.2: Khoi tao danh sach rong
void Empty()
{
	first = NULL;
}

//CAU 3.3: Xuat cac phan tu trong danh sach
void Output()
{
	Node *p;
	p = first;
	while (p != NULL)
	{
		cout << p->info << "\t";
		p = p->link;
	}
	cout << endl;
}

//CAU 3.4: Tim mot phan tu trong danh sach
Node *Search(int x)
{
	Node *p;
	p = first;

	while ((p != NULL) && (p->info != x))
	{
		p = p->link;
	}

	return p;
}

//CAU 3.5: Them mot phan tu vao dau danh sach
void Insert_first(int x)
{
	Node *p = new Node;

	p->info = x;
	p->link = first;
	first = p;
}

//CAU 3.6: Xoa mot phan tu dau danh sach
int Delete_first()
{
	if (first != NULL)
	{
		Node *p = first;
		first = first->link;
		delete p;
		return 1;
	}
	return 0;
}

//CAU 3.7: Them phan tu cuoi danh sach
void Insert_last(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = NULL;

	if (first == NULL) /* Neu la danh sach rong */
		first = p;
	else
	{
		Node *q = first;
		while (q->link != NULL) /* Duyet toi cuoi day */
			q = q->link;
		q->link = p;
	}
}

//AU 3.8: Xoa phan tu cuoi danh sach
int Delete_last()
{
	if (first != NULL) /* Neu danh sach KHONG RONG thi xoa*/
	{
		Node *p = first;
		Node *q = first;

		while (p->link != NULL)
		{
			q = p;
			p = p->link;
		}

		if (p != first)
			q->link = NULL;
		else
			first = NULL;
		delete p;

		return 1;
	}

	return 0;
}

//CAU 3.9: Tim phan tu x roi xoa phan tu (neu co)
int Search_Delete(int x)
{
	if (first != NULL)
	{
		Node *p = first;
		Node *q = first;

		while ((p->info != x) && (p->link != NULL))
		{
			q = p;
			p = p->link;
		}

		if ((p != first) && (p != NULL)) /* x nam o giua danh sach */
		{
			if (p->link != NULL)
				q->link = p->link;
			else
				q->link = NULL;
			delete p;

			return 1;
		}
		else
			if (p == first)
			{
				first = p->link;
				delete p;
				return 1;
			}
			else
				return 0;
	}
	return 0;
}

int main()
{
	int choice = 0;
	int x, i;
	Node *p;

	system("cls");

	cout << "----------- CHUONG 1 - BAI TAP 1 - DANH SACH LIEN KET DON -----------" << endl;
	cout << "1. Khoi tao DSLK DON rong" << endl;
	cout << "2. Them phan tu vao dau DSLK DON" << endl;
	cout << "3. Them phan tu vao cuoi DSLK DON" << endl;
	cout << "4. Xoa phan tu vao dau DSLK DON" << endl;
	cout << "5. Xoa phan tu vao cuoi DSLK DON" << endl;
	cout << "6. Xuat DSLK DON" << endl;
	cout << "7. Tim mot phan tu gia tri x trong DSLK DON" << endl;
	cout << "8. Tim phan tu voi gia tri x va xoa (neu co)" << endl;
	cout << "9. Sap xep DSLK DON tang dan" << endl;
	cout << "10. Sap xep DSLK DON giam dan" << endl;
	cout << "11. Thoat" << endl;

	do
	{
		cout << endl << "Vui long chon so de thuc hien: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			Empty();
			cout << "Khoi tao DSLK DON thanh cong!" << endl;
			break;
		case 2:
			cout << "Vui long nhap gia tri x muon tham vao DAU danh sach: ";
			cin >> x;
			Insert_first(x);
			cout << "Danh sach hien tai la: " << endl;
			Output();
			break;
		case 3:
			cout << "Vui long nhap gia tri x muon tham vao CUOI danh sach: ";
			cin >> x;
			Insert_last(x);
			cout << "Danh sach hien tai la: " << endl;
			Output();
			break;
		case 4:
			i = Delete_first();
			if (i == 0)
				cout << "Danh sach rong, khong the xoa!" << endl;
			else
			{
				cout << "Da xoa thanh cong phan tu DAU cua DSLK DON!" << endl;
				cout << "Danh sach hien tai la: " << endl;
				Output();
			}
			break;
		case 5:
			i = Delete_last();
			if (i == 0)
				cout << "Danh sach rong, khong the xoa!" << endl;
			else
			{
				cout << "Da xoa thanh cong phan tu CUOI cua DSLK DON!" << endl;
				cout << "Danh sach hien tai la: " << endl;
				Output();
			}
			break;
		case 6:
			cout << "Danh sach hien tai la: " << endl;
			Output();
			break;
		case 7:
			cout << "Nhap gia tri can tim: x = ";
			cin >> x;
			p = Search(x);
			if (p != NULL)
				cout << "Tim thay phan tu co gia tri x = " << x << endl;
			else
				cout << "Khong tim thay phan tu co gia tri x = " << x << endl;
			break;
		case 8:
			cout << "Vui long nhap gia tri can tim x = ";
			cin >> x;
			i = Search_Delete(x);
			if (i == 1)
			{
				cout << "Tim thay x = " << x << " va da xoa thanh cong!" << endl;
				cout << "Danh sach hien tai la: " << endl;
				Output();
			}
			else
				cout << "Khong tim thay x = " << x << " trong danh sach!" << endl;
			break;
			/*case 9:
				Sort();
				cout >> "Danh sach sau khi sap xep tang dan la: " << endl;
				Output();
				break;
			case 10:
				SortDesc();
				cout << "danh sach sau khi sap xep giam dan la: " << endl;
				Output();
				break;*/
		case 11:
			cout << "Goodbye...!" << endl;
			break;
		default:
			break;
		}
	} while (choice != 11);

	system("pause");
	return 0;
}