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

void ThemDT(DeTai dt, Node_DT *&first_DT)
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

void xuatDT(DeTai dt){
	cout << "Ma de tai: " << dt.maDT << endl << 
	"Ten de tai: " << dt.tenDT << endl << 
	"So luong sv tham gia: " << dt.soluongSV << endl <<
	"Ma hoc phan: " << dt.maHP << endl;
}

void XuatDSDT(Node_DT *first_DT)
{
	Node_DT* p = first_DT;
	while (p != NULL)
	{
		xuatDT(p->info);
		p = p->link;
	}
}

DeTai timDeTaiBangMaDT(string maDT, Node_DT *first_DT){
	Node_DT *p = first_DT;
	DeTai dt;
	if(first_DT == NULL){
		return dt;
	}
	else{
		while(p != NULL){
			if(p->info.maDT == maDT){
				return p->info;
			}
			p = p->link;
		}
		return dt;
	}
}

string layMaHPTuDeTai(DeTai dt){
	return dt.maHP;
}