#include <string>
#include <iostream>

using namespace std;

struct SinhVien
{
	string maSV;
	string holot;
	string ten;
	int ngaysinh;
	int thangsinh;
	int namsinh;
	string sodienthoai;
};
struct Node_SV
{
	SinhVien info;
	Node_SV* link;
};
void ThemSV(SinhVien sv, Node_SV *first_SV)
{
	Node_SV* p = new Node_SV;
	p->info = sv;
	p->link = NULL;
	if (first_SV == NULL)
		first_SV = p;
	else
	{
		p->link = first_SV;
		first_SV = p;
	}
}
void XuatDSSV(Node_SV *first_SV)
{
	Node_SV* p = first_SV;
	while (p != NULL)
	{
		cout << "Ma sinh vien:" << p->info.maSV << endl
			<< "Ho ten sinh vien:" << p->info.holot << " " << p->info.ten << endl
			<< "Nam sinh:" << p->info.ngaysinh << "/" << p->info.thangsinh << "/" << p->info.namsinh << endl
			<< "So dien thoai:" << p->info.sodienthoai << endl;
		p = p->link;
	}
}

SinhVien timSinhVienTheoMa(string maSV, Node_SV *first_SV){
	Node_SV *p = first_SV;
	SinhVien sv;
	if(p == NULL){	
	}
	else{
		while(p != NULL){
			if(p->info.maSV == maSV)
			{
				return p->info;
			}
			p = p->link;
		}
	}
	return sv;
}