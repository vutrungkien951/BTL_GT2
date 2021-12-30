#include <string>
#include <iostream>

using namespace std;

struct DeTai
{
	string maDT;
	string tenDT;
	int soluongSV;
	string maHP;
};

struct Node_DT
{
	DeTai info;
	Node_DT* link;
};

void ThemDT(DeTai dt, Node_DT *first_DT)
{
	Node_DT* p = new Node_DT;
	p->info = dt;
	p->link = NULL;
	if (first_DT == NULL)
		first_DT = p;
	else
	{
		p->link = first_DT;
		first_DT = p;
	}
}

void XuatDSDT(Node_DT *first_DT)
{
	Node_DT* p = first_DT;
	while (p != NULL)
	{
		cout << "Ma de tai:" << p->info.maDT << endl
			<< "Ten de tai:" << p->info.tenDT << endl
			<< "So luong sinh vien tham gia:" << p->info.soluongSV << endl
			<< "Ma hoc phan:" << p->info.maHP << endl;
		p = p->link;
	}
}

DeTai timDeTaiBangMaDT(string maDT, Node_DT *first_DT){
	Node_DT *p = first_DT;
	
}