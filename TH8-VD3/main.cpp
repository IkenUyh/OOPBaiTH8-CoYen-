#include "QuanLySoHong.h"
#include <iostream>
using namespace std;
int main(){
    QuanLySoHong qlsh;
    cout<<"=====CHUONG TRINH QUAN LY SO HONG DAT DAI=====\n\n";
    cout<<"1. Nhap danh sach so hong:\n";
    qlsh.Nhap();
    cout<<"Danh sach vua nhap:\n";
    qlsh.Xuat();
    cout<<"\n2. Thua dat co tien thue cao nhat:\n";
    qlsh.ThuaDatCoTienThueMax();
    cout<<"\n3. Thua dat nong nghiep het han su dung:\n";
    qlsh.DatNongNghiepHetHan();
    cout<<"\n4. Thong ke:\n";
    cout<<"So luong so hong: "<<SoHong::GetDem()<<endl;
    cout<<"So luong so hong dat nong nghiep: "<<SoHongDatNongNghiep::GetDem()<<endl;
    cout<<"So luong so hong dat phi nong nghiep: "<<SoHongDatPhiNongNghiep::GetDem()<<endl;
    cout<<"\n=====KET THUC CHUONG TRINH=====\n";
    return 0;
}