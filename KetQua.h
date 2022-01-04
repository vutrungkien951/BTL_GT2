#include <string>
#include <iostream>

using namespace std;

struct KetQua
{
	string maSV;
	string maDT;
	float diemBC;
	float diemCD;
	float diemTB;
};

struct Node_KQ
{
	KetQua info;
	Node_KQ* link;
};

void ThemKQ(KetQua kq, Node_KQ *&first_KQ)
{
	Node_KQ* p = new Node_KQ;
	p->info = kq;
	p->link = NULL;
	if (first_KQ == NULL)
		first_KQ = p;
	else
	{
		p->link = first_KQ;
		first_KQ = p;
	}
}

void XuatDSKQ(Node_KQ *first_KQ)
{
	Node_KQ* p = first_KQ;
	while (p != NULL)
	{
		cout << "Ma sinh vien:" << p->info.maSV << endl
			<< "Ma de tai:" << p->info.maDT << endl
			<< "Diem bao cao:" << p->info.diemBC << endl
			<< "Diem cai dat:" << p->info.diemCD << endl
			<< "Diem trinh bay:" << endl;
		p = p->link;
	}
}


string maSVDiemCaoNhatToanHP(Node_KQ *first_KQ){
	Node_KQ *p = first_KQ;
	
	if(p == NULL){
		return "";
	}
	else{
		double max = 0;
		string maSV;
		double diemTam;

		while(p != NULL){
			diemTam = p->info.diemBC * 0.4 + p->info.diemTB * 0.2 + p->info.diemCD * 0.4;
			if(diemTam > max){
				max = diemTam;
				maSV = p->info.maSV;
			}
			p = p->link;
		}
		return maSV;
	}
}

double tinhDiemTong(KetQua kq){
	return (kq.diemBC * 0.4 + kq.diemTB * 0.2 + kq.diemCD * 0.4);
}

string maDeTaiSVDiemCaoNhatToanHP(Node_KQ *first_KQ){
	Node_KQ *p = first_KQ;
	
	if(p == NULL){
		return "";
	}
	else{
		double max = 0;
		string maDeTai;
		double diemTam;

		while(p != NULL){
			diemTam = p->info.diemBC * 0.4 + p->info.diemTB * 0.2 + p->info.diemCD * 0.4;
			if(diemTam > max){
				max = diemTam;
				maDeTai = p->info.maDT;
			}
			p = p->link;
		}
		return maDeTai;
	}
}

bool ketQuaThuocHP(string maHP, KetQua ketQua, Node_DT *first_DT){
	string maHPLayDuoc = layMaHPTuDeTai(layDeTaiTuMaDT(ketQua.maDT, first_DT));
	if(maHPLayDuoc == maHP){
		return true;
	}
	return false;
}


void inBangDiemKhiBietMaHP(string maHP, Node_KQ *first_KQ, Node_HP *first_HP, Node_DT *first_DT, Node_SV *first_SV){
	//file name mac dinh ketquahoctap.txt
	Node_KQ *p = first_KQ;
	HocPhan hp = timHPBangMaHP(maHP, first_HP);
	ofstream myFile;
	myFile.open("ketquahoctap.txt");

	cout << hp.maHP << "\t" << hp.tenHP << endl;
	myFile << hp.maHP << "\t" << hp.tenHP << "\n";

	while(p != NULL){
		if(ketQuaThuocHP(maHP, p->info, first_DT)){
			xuatSVTheoTask10(timSinhVienTheoMa(p->info.maSV, first_SV));
			myFile << strSVTheoTask10(timSinhVienTheoMa(p->info.maSV, first_SV));
			cout << "Diem: " << tinhDiemTong(p->info) << endl;
			myFile << "Diem: " << tinhDiemTong(p->info) << "\n";
		}
		p = p->link;
	}

	myFile.close();
}