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

// 1-10
/*
	1. Xây dựng danh sách liên kết đơn phù hợp để tổ chức lưu trữ kết quả thực hiện đề tài của
các sinh viên.
	2. Thông tin các lớp học phần được lưu trữ trong file hocphan.txt, thông tin sinh viên được
lưu trữ trong file sinhvien.txt; thông tin đề tài được lưu trữ trong file detai.txt; kết quả thực
hiện được lưu trữ trong file ketqua.txt. Hãy đọc dữ liệu từ các file vào chương trình 
và phải đảm bảo các ràng buộc một sinh viên có thể đăng ký nhiều học phần và các học phần
đăng ký phải thuộc danh mục các học phần đã lưu trữ.
	3. Thêm một đề tài vào danh sách các đề tài, thông tin đề tài được nhập từ bàn phím.
	4. Cho phép tìm kiếm sinh viên theo các tiêu chí tìm kiếm: tên học phần hoặc mã sinh viên
hoặc tên đề tài. Cho phép người dùng lựa chọn tiêu chí tìm kiếm.
	5. In ra màn hình kết quả thực hiện của sinh viên theo tên học phần (tất cả các học phần).
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
	11.Mỗi môn học là 1 đỉnh của đồ thị. Tính chất môn học trước hay môn tiên quyết là đường
nối giữa 2 đỉnh. Hãy tìm con đường đi từ 1 môn học bất kỳ đến khi hoàn tất chương trình
đào tạo phải trải qua các môn nào theo phương pháp duyệt theo chiều sâu.
*/
Node_SV *first_SV;
Node_HP *first_HP;
Node_DT *first_DT;
Node_KQ *first_KQ;
Node_H *first_H;
Node_DT *dsDeTai;
Node_DT *sortedDeTai;

Stack stack;
void init(){
	Node_SV *first_SV = new Node_SV;
	Node_HP *first_HP = new Node_HP;
	Node_DT *first_DT = new Node_DT;
	Node_KQ *first_KQ = new Node_KQ;
	Node_H *first_H = new Node_H;
	Node_DT *dsDeTai = NULL;
	Node_DT *sortedDeTai = NULL;
}
int main()
{
	
	//Tim sv co diem tong ket cao nhat
	//Khoi tao
	init();
	//setup du lieu
	/*
	string maHP = "hp1";
	KetQua kq;
	kq.maSV = "sv1";
	kq.maDT = "dt1";
	kq.diemBC = kq.diemCD = kq.diemTB = 9.0;
	ThemKQ(kq, first_KQ);
	SinhVien sv1;
	sv1.maSV = "sv1";
	sv1.holot = "Vu";
	sv1.ten = "Trung Kien";
	ThemSV(sv1, first_SV);
	DeTai dt1;
	dt1.maDT = "dt1";
	dt1.maHP = "hp1";
	dt1.tenDT = "detai1";
	dt1.soluongSV = 1;
	ThemDT(dt1, first_DT);
	HocPhan hp1;
	hp1.maHP = "hp1";
	hp1.tenHP = "hocphan1";
	ThemHP(hp1, first_HP);
	*/
	int choice;
	bool init = false;
	DeTai dt;
	SinhVien sv;
	HocPhan hp;
	string maHP;
	do{
		cout << "---------------------MENU----------------------" << endl <<
		"1. Doc file" << endl <<
		"2. Them de tai" << endl <<
		"3. Tim kiem sinh vien" << endl << 
		"4. In ra ket qua thuc hien cua sinh vien theo ten hoc phan" << endl << 
		"5. Tim sinh vien co diem tong ket cao nhat" << endl <<
		"6. Tim lop hoc phan sv co diem tong ket cao nhat" << endl <<
		"7. Dao nguoc danh sach sv bang stack" << endl <<
		"8. In ra de tai co sinh vien thuc hien <=3, sap xep giam dan" << endl <<
		"9. In ra bang diem sinh vien khi biet ma lop hoc phan" << endl <<
		"10. Tim danh sach mon can hoc bang do thi" << endl << 
		"11. Thoat\n"<<
		"Hay dua ra lua chon: ";
		cin >> choice;
		switch(choice){
			case 1:
				//docfile
				init = true;
				break;
			case 2:
				if(init){
					nhapDT(dt);
					ThemDT(dt, first_DT);
				}
				else{
					cout << "Chua co du lieu! Chon 1 de doc file!" << endl;
				}
				break;
			case 3:
				if(init){

				}
				else{
					cout << "Chua co du lieu! Chon 1 de doc file!" << endl;
				}
				break;
			case 4:
				if(init){

				}
				else{
					cout << "Chua co du lieu! Chon 1 de doc file!" << endl;
				}
				break;
			case 5:
				if(init){
					sv = timSinhVienTheoMa(maSVDiemCaoNhatToanHP(first_KQ) , first_SV);
					xuatSV(sv);
				}
				else{
					cout << "Chua co du lieu! Chon 1 de doc file!" << endl;
				}
				break;
			case 6:
				if(init){
					hp = timHPBangMaHP(layMaHPTuDeTai(timDeTaiBangMaDT(maDeTaiSVDiemCaoNhatToanHP(first_KQ), first_DT)) , first_HP);
					xuatHP(hp);
				}
				else{
					cout << "Chua co du lieu! Chon 1 de doc file!" << endl;
				}
				break;
			case 7:
				if(init){
					initStack(stack);
					reverseSV(first_SV, stack);
					XuatDSSV(first_SV);
				}
				else{
					cout << "Chua co du lieu! Chon 1 de doc file!" << endl;
				}
				break;
			case 8:
				if(init){
					layDeTaiTu3Nguoi(first_DT, dsDeTai);
					countingSortDeTaiGiamDan(dsDeTai, sortedDeTai, 3);
					cout << "Sau khi sap xep: " << endl;
					XuatDSDT(sortedDeTai);
				}
				else{
					cout << "Chua co du lieu! Chon 1 de doc file!" << endl;
				}
				break;
			case 9:
				if(init){
					cout << "Moi ban nhap vao ma hoc phan: ";
					getline(cin, maHP);
					inBangDiemKhiBietMaHP(maHP, first_KQ, first_HP, first_DT, first_SV);
				}
				else{
					cout << "Chua co du lieu! Chon 1 de doc file!" << endl;
				}
				break;
			case 10:
				if(init){

				}
				else{
					cout << "Chua co du lieu! Chon 1 de doc file!" << endl;
				}
				break;
		}
	}while(choice >= 1 && choice <= 10);

	return 0;
}