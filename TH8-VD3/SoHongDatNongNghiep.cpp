#include "SoHongDatNongNghiep.h"
#include <iostream>
using namespace std;
int SoHongDatNongNghiep::dem=0;
SoHongDatNongNghiep::~SoHongDatNongNghiep(){
    cout<<"Da huy mot so hong dat nong nghiep"<<endl;
    --dem;
}
SoHongDatNongNghiep::SoHongDatNongNghiep():SoHong(), thoihan(2000){
    ++dem;
}
SoHongDatNongNghiep::SoHongDatNongNghiep(string sogiaycn, DSCongDan chudat, int sothuadat, string sotobando, string diachithuadat, double dientich, Ngay ngaycap, double dongiathue, int thoihan):SoHong(sogiaycn, chudat, sothuadat, sotobando, diachithuadat, dientich, ngaycap, dongiathue), thoihan(thoihan){
    ++dem;
}
SoHongDatNongNghiep::SoHongDatNongNghiep(const SoHongDatNongNghiep& other):SoHong(other){
    this->thoihan=other.thoihan;
    ++dem;
}
SoHongDatNongNghiep& SoHongDatNongNghiep::operator=(const SoHongDatNongNghiep& other){
    SoHong::operator=(other);
    this->thoihan=other.thoihan;
    return *this;
}
int SoHongDatNongNghiep::GetThoiHan(){
    return this->thoihan;
}
int SoHongDatNongNghiep::GetDem(){
    return dem;
}
void SoHongDatNongNghiep::SetThoiHan(int thoihan){
    while(thoihan<1900){
        cout<<"Thoi han khong hop le! Moi ban nhap lai: ";
        cin>>thoihan;
    }
    this->thoihan=thoihan;
}
void SoHongDatNongNghiep::Nhap(){
    SoHong::Nhap();
    cout<<"Nhap thoi han su dung (den nam): "; cin>>thoihan;
    while(thoihan<1900){
        cout<<"Thoi han khong hop le! Moi ban nhap lai: ";
        cin>>thoihan;
    }
}
void SoHongDatNongNghiep::Xuat(){
    SoHong::Xuat();
    cout<<"Thoi han su dung: "<<thoihan<<endl;
}
string SoHongDatNongNghiep::GetLoai(){
    return "Dat nong nghiep";
}