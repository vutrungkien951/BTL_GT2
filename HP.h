#include <string>
#include <iostream>

using namespace std;


struct HocPhan
{
	string maHP;
	string tenHP;
	string ngayBD;
	string ngayKT;
};

struct Node_HP
{
	HocPhan info;
	Node_HP* link;
};

void ThemHP(HocPhan hp, Node_HP *first_HP)
{
	Node_HP* p = new Node_HP;
	p->info = hp;
	p->link = NULL;
	if (first_HP == NULL)
		first_HP = p;
	else
	{
		p->link = first_HP;
		first_HP = p;
	}
}

void XuatDSHP(Node_HP *first_HP)
{
	Node_HP* p = first_HP;
	while (p != NULL)
	{
		cout << "Ma hoc phan:" << p->info.maHP << endl
			<< "Ten hoc phan:" << p->info.tenHP << endl
			<< "Ngay bat dau:" << p->info.ngayBD << endl
			<< "Ngay ket thuc:" << p->info.ngayKT << endl;
		p = p->link;
	}
}