#include "SoHongDatPhiNongNghiep.h"
#include <iostream>
using namespace std;
int SoHongDatPhiNongNghiep::dem=0;
SoHongDatPhiNongNghiep::~SoHongDatPhiNongNghiep(){
    cout<<"Da huy mot so hong dat phi nong nghiep"<<endl;
    --dem;
}
SoHongDatPhiNongNghiep::SoHongDatPhiNongNghiep():SoHong(){
    ++dem;
}
SoHongDatPhiNongNghiep::SoHongDatPhiNongNghiep(string sogiaycn, DSCongDan chudat, int sothuadat, string sotobando, string diachithuadat, double dientich, Ngay ngaycap, double dongiathue):SoHong(sogiaycn, chudat, sothuadat, sotobando, diachithuadat, dientich, ngaycap, dongiathue){
    ++dem;
}
SoHongDatPhiNongNghiep::SoHongDatPhiNongNghiep(const SoHongDatPhiNongNghiep& other):SoHong(other){
    ++dem;
}
SoHongDatPhiNongNghiep& SoHongDatPhiNongNghiep::operator=(const SoHongDatPhiNongNghiep& other){
    SoHong::operator=(other);
    return *this;
}
int SoHongDatPhiNongNghiep::GetDem(){
    return dem;
}
void SoHongDatPhiNongNghiep::Nhap(){
    SoHong::Nhap();
}
void SoHongDatPhiNongNghiep::Xuat(){
    SoHong::Xuat();
}
string SoHongDatPhiNongNghiep::GetLoai(){
    return "Dat phi nong nghiep";
}