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

void ThemHP(HocPhan hp, Node_HP *&first_HP)
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

void insertFromFile_HP(Node_HP *&first_HP)
{
	HocPhan hp;
	ifstream inF;
	inF.open("HocPhan.txt");
	if (inF.is_open())
	{
		while (!inF.eof())
		{
			getline(inF, hp.maHP);
			getline(inF, hp.tenHP);
			getline(inF, hp.ngayBD);
        	getline(inF, hp.ngayKT);
			ThemHP(hp, first_HP);
		}
		inF.close();
	}
	else
		cout << "Ko doc dc file!";
}

HocPhan timHPBangMaHP(string maHP, Node_HP *first_HP){
	Node_HP *p = first_HP;
	HocPhan hp;
	if(p == NULL){
		return hp;
	}
	else{
		while(p != NULL){
			if(p->info.maHP == maHP){
				return p->info;
			}
			p = p->link;
		}
		return hp;
	}
}
void xuatHP(HocPhan hp){
	cout << "Ma hoc phan: " << hp.maHP << endl << 
	"Ten hoc phan: " << hp.tenHP << endl << 
	"Ngay bat dau: " << hp.ngayBD << endl <<
	"Ngay ket thuc: " << hp.ngayKT << endl;
}
void XuatDSHP(Node_HP *first_HP)
{
	Node_HP* p = first_HP;
	while (p != NULL)
	{
		xuatHP(p->info);
		p = p->link;
	}
}