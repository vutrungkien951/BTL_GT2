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

void nhapSV(SinhVien &sv){
	cout << "Nhap vao cac thong tin" << endl <<
	"Ma SV: ";
	getline(cin, sv.maSV);
	cout << "Ho: ";
	getline(cin, sv.holot);
	cout << "Ten: ";
	getline(cin, sv.ten);
	cout << "Ngay sinh: ";
	cin >> sv.ngaysinh;
	cout << "Thang sinh: ";
	cin >> sv.thangsinh;
	cout << "Nam sinh: ";
	cin >> sv.namsinh;
	cin.ignore(1);
	cout << "SDT: ";
	getline(cin, sv.sodienthoai);
}

void ThemSV(SinhVien sv, Node_SV *&first_SV)
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

void ThemCuoiSV(SinhVien sv, Node_SV *&first_SV){
	Node_SV* p = new Node_SV;
	p->info = sv;
	p->link = NULL;
	if(first_SV == NULL){
		first_SV = p;
	}
	else{
		Node_SV *q = first_SV;

		while(q->link != NULL){
			q = q->link;
		}

		q->link = p; 
	}
}

SinhVien laySVDau(Node_SV *&first_SV){
	Node_SV *p = first_SV;
	Node_SV *q = first_SV->link;

	first_SV = q;
	SinhVien sv = p->info;

	delete p;

	return sv;
}
string strSVTheoTask10(SinhVien sv){
	string str = "Ma sinh vien: " + sv.maSV + "\tHo ten: " + sv.holot + " " +
	sv.ten + "\t";
	return str; 
}
void xuatSVTheoTask10(SinhVien sv){
	cout << "Ma sinh vien: "<< sv.maSV << "\t" << "Ho ten: " << sv.holot << " " << sv.ten << 
	"\t";
}

void xuatSV(SinhVien sv){
	cout << "Ma sinh vien: " << sv.maSV << endl <<
	"Ho ten sinh vien: " << sv.holot << " " << sv.ten << endl <<
	"Ngay sinh: " << sv.ngaysinh << "/" << sv.thangsinh << "/" << sv.namsinh << endl << 
	"So dien thoai: " << sv.sodienthoai << endl;
}
void XuatDSSV(Node_SV *first_SV)
{
	Node_SV* p = first_SV;
	while (p != NULL)
	{
		xuatSV(p->info);
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


// stack sv
struct Node{
	SinhVien sv;
	Node *link;
};

struct Stack{
	Node *head;
};
void initStack(Stack &stack){
	stack.head = NULL;
}
bool isEmpty(Stack stack){
	return stack.head == NULL;
}
Node *createNode(SinhVien sv){
	Node *p = new Node;
	if(p == NULL){
		return NULL;
	}
	p->sv = sv;
	p->link = NULL;

	return p;
}

int demSoPhanTuTrongStack(Stack stack){
	int i = 0;
	Node *p = stack.head;
	while(p != NULL){
		i++;
		p = p->link;
	}
	return i;
}

void push(SinhVien sv, Stack &stack){
	Node *p = createNode(sv);

	p->link = stack.head;
	stack.head = p;
}

SinhVien pop(Stack &stack){
	SinhVien sv;
	if(stack.head != NULL){
		Node *p = stack.head;
		stack.head = p->link;
		
		sv = p->sv;
		delete p;
	}
	return sv;
}

void xuatStack(Stack stack){
	Node *p = stack.head;
	while(p != NULL){
		xuatSV(p->sv);
		p = p->link;
	}
}

void reverseSV(Node_SV *&first_SV, Stack &stack){
	initStack(stack);

	while(first_SV != NULL){
		push(laySVDau(first_SV), stack);
	}

	while(!isEmpty(stack)){
		ThemCuoiSV(pop(stack), first_SV);
	}
}

