#include <string>
#include <iostream>
#include <fstream>

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

void nhapDT(DeTai &dt){
	cout << "Nhap thong tin de tai: " << endl;
	cout << "Nhap ma de tai: ";
	getline(cin, dt.tenDT);
	cout << "Nhap ten de tai: ";
	getline(cin, dt.maDT);
	cout << "Nhap so luong sv: ";
	cin >> dt.soluongSV;
	cin.ignore(1);
	cout << "Nhap ma hoc phan: ";
	getline(cin, dt.maHP);
}
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

void insertFromFile_DT(Node_DT *&first_DT)
{
	DeTai dt;
	ifstream inF;
	inF.open("DeTai.txt");
	if (inF.is_open())
	{
		while (!inF.eof())
		{
			getline(inF, dt.maDT, ',');
			getline(inF, dt.tenDT, ',');
			inF >> dt.soluongSV;
			inF.ignore();
			getline(inF, dt.maHP);
			ThemDT(dt, first_DT);
		}
		inF.close();
	}
	else
		cout << "Ko doc dc file";
}

bool deTaiRong(DeTai dt){
	return dt.maDT == "";
}

DeTai layDeTaiTuMaDT(string maDT, Node_DT *first_DT){
	Node_DT *p = first_DT;
	DeTai dt;

	while(p != NULL){
		if(p->info.maDT == maDT){
			return p->info;
		}
		p = p->link;
	}
	
	return dt;
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

void layDeTaiTu3Nguoi(Node_DT *first_DT, Node_DT *&dsDeTai){
	//dsDeTai phai rong de chua de tai
	Node_DT *p = first_DT;
	while(p != NULL){
		if(p->info.soluongSV <= 3){
			ThemDT(p->info, dsDeTai);
		}
		p = p->link;
	}
}

void countingSortDeTaiGiamDan(Node_DT *dsDeTai, Node_DT *&sortedList, int k){
	//k = 3 , sort theo nho hon hoac bang 3
	//sortedList phai rong
	int c[k];
	for(int i = 0; i <= k; i++){
		c[i] = 0;
	}

	Node_DT *p = dsDeTai;
	while(p != NULL){
		c[p->info.soluongSV]++;
		p = p->link;
	}

	// 0 1 2 3
	for(int i = 0; i <= k; i++){
		p = dsDeTai;
		while(c[i] > 0){
			if(p->info.soluongSV == i){
				ThemDT(p->info, sortedList);
				c[i]--;
			}
			p = p->link;
		}
	}
}