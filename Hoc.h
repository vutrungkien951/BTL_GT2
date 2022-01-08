#include <string>
#include <iostream>

using namespace std;

struct Hoc
{
	string maSV;
	string maHP;
	int ngaydk;
	int thangdk;
	int namdk;
};
struct Node_H
{
	Hoc info;
	Node_H* link;
};

void themHoc(Hoc h, Node_H *first_H){
	Node_H *p = new Node_H;
	p->info = h;
	p->link = NULL;
	if(first_H == NULL){
		first_H = p;
	}
	else{
		p->link = first_H;
		first_H = p;
	}
}

void XuatDSH(Node_H *first_H)
{
	Node_H* p = first_H;
	while (p != NULL)
	{
		cout << "Ma sinh vien:" << p->info.maSV << endl
			<< "Ma hoc phan:" << p->info.maHP << endl
			<< "Ngay dang ky:" << p->info.ngaydk << "/" << p->info.thangdk << "/" << p->info.namdk << endl;
		p = p->link;
	}
}