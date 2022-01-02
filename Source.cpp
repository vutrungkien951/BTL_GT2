#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include "SV.h"
#include "HP.h"
#include "DeTai.h"
#include "Hoc.h"
#include "KetQua.h"
using namespace std;

// 6-10
/*
	6. Tìm thông tin sinh viên có điểm tổng kết cao nhất (điểm tổng kết= điểm báo cáo *0.4 +
điểm trình bày * 0.2 + điểm code * 0.4) của tất cả các lớp học phần.
	7. Tìm lớp học phần có sinh viên có điểm tổng kết cao nhất.
	8. Đảo ngược danh sách sinh viên sử dụng stack.
	9. In ra thông tin của các đề tài có số lượng sinh viên thực hiện <=3, sắp xếp kết quả giảm
dần theo số lượng sinh viên thực hiện.
	10.Cho phép tìm kiếm in ra bảng điểm của sinh viên học lớp học phần khi biết mã lớp học
phần. Thông tin in ra màn hình và lưu trữ vào file có tên là ketquahoctap.txt gồm có các
dòng thông tin:
		+ Dòng 1: mã lớp học phần, tên học phần
	+ Các dòng theo sau hiển thị thông tin theo cấu trúc: mã sinh viên, họ tên sinh viên, điểm
tổng kết
*/
Node_SV *first_SV;
Node_HP *first_HP;
Node_DT *first_DT;
Node_KQ *first_KQ;
Node_H *first_H;

Stack stack;
void init(){
	Node_SV *first_SV = new Node_SV;
	Node_HP *first_HP = new Node_HP;
	Node_DT *first_DT = new Node_DT;
	Node_KQ *first_KQ = new Node_KQ;
	Node_H *first_H = new Node_H;
}
int main()
{
	//Tim sv co diem tong ket cao nhat
	//Khoi tao
	init();
	/*
	// 6
	SinhVien sv = timSinhVienTheoMa(maSVDiemCaoNhatToanHP(first_KQ) , first_SV);
	xuatSV(sv);
	// 7
	HocPhan hp = timHPBangMaHP(layMaHPTuDeTai(timDeTaiBangMaDT(maDeTaiSVDiemCaoNhatToanHP(first_KQ), first_DT)) , first_HP);
	xuatHP(hp);
	
	//8

	SinhVien sv1;
	nhapSV(sv1);
	SinhVien sv2;
	nhapSV(sv2);
	
	ThemSV(sv1, first_SV);
	ThemSV(sv2, first_SV);
	XuatDSSV(first_SV);

	initStack(stack);
	reverseSV(first_SV, stack);

	XuatDSSV(first_SV);
	*/
	
	return 0;
}