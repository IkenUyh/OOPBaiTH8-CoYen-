#include "ve.h"
#include<iomanip>
int VE::dem=0;
VE::~VE(){
    cout<<"Da huy mot ve"<<endl;
    --dem;
}
VE::VE():mave(""), hoten(""), namsinh(0), sotrochoi(0){
    ++dem;
}
VE::VE(string mave, string hoten, int namsinh, int sotrochoi):mave(mave), hoten(hoten), namsinh(namsinh), sotrochoi(sotrochoi){
    ++dem;
}
VE::VE(const VE& ve){
    this->mave=ve.mave;
    this->hoten=ve.hoten;
    this->namsinh=ve.namsinh;
    this->sotrochoi=ve.sotrochoi;
    ++dem;
}
VE& VE::operator=(const VE& ve){
    this->mave=ve.mave;
    this->hoten=ve.hoten;
    this->namsinh=ve.namsinh;
    this->sotrochoi=ve.sotrochoi;
    return *this;
}
string VE::GetMaVe(){
    return this->mave;
}
string VE::GetHoTen(){
    return this->hoten;
}
int VE::GetNamSinh(){
    return this->namsinh;
}
int VE::GetSoTroChoi(){
    return this->sotrochoi;
}
int VE::GetDem(){
    return dem;
}
void VE::SetHoTen(string hoten){
    this->hoten=hoten;
}
void VE::SetNamSinh(int namsinh){
    while(namsinh<1900||namsinh>2025){
        cout<<"Nam sinh khong hop le! Moi ban nhap lai: ";
        cin>>namsinh;
    }
    this->namsinh=namsinh;
}
void VE::SetSoTroChoi(int sotrochoi){
    while(sotrochoi<0){
        cout<<"So tro choi khong hop le! Moi ban nhap lai: ";
        cin>>sotrochoi;
    }
    this->sotrochoi=sotrochoi;
}
void VE::Nhap(){
    cin.ignore();
    cout<<"Nhap ma ve: "; getline(cin, this->mave);
    cout<<"Nhap ho ten khach hang: "; getline(cin, this->hoten);
    cout<<"Nhap nam sinh: "; cin>>this->namsinh;
    while(this->namsinh<1900||this->namsinh>2025){
        cout<<"Nam sinh khong hop le! Moi ban nhap lai: ";
        cin>>this->namsinh;
    }
}
void VE::Xuat(){
    cout<<"Ma ve: "<<this->mave<<endl;
    cout<<"Ho ten khach hang: "<<this->hoten<<endl;
    cout<<"Nam sinh: "<<this->namsinh<<endl;
    cout<<"Loai ve: "<<GetLoai()<<endl;
    cout<<"So tro choi: "<<this->sotrochoi<<endl;
    cout<<"Gia ve: "<<fixed<<setprecision(0)<<TinhGiaVe()<<endl;
}