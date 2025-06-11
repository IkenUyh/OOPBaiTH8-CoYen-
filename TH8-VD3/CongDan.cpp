#include "CongDan.h"
#include <ctime>
#include <iostream>
using namespace std;
int CongDan::dem=0;
CongDan::~CongDan(){
    cout<<"Da huy mot cong dan"<<endl;
    --dem;
}
CongDan::CongDan():hoten(""), namsinh(2000), cccd(""), diachi(""){
    ++dem;
}
CongDan::CongDan(string hoten, int namsinh, string cccd, string diachi):hoten(hoten), namsinh(namsinh), cccd(cccd), diachi(diachi){
    ++dem;
}
CongDan::CongDan(const CongDan& other){
    this->hoten=other.hoten;
    this->namsinh=other.namsinh;
    this->cccd=other.cccd;
    this->diachi=other.diachi;
    ++dem;
}
CongDan& CongDan::operator=(const CongDan& other){
    this->hoten=other.hoten;
    this->namsinh=other.namsinh;
    this->cccd=other.cccd;
    this->diachi=other.diachi;
    return *this;
}
string CongDan::GetHoTen(){
    return this->hoten;
}
int CongDan::GetNamSinh(){
    return this->namsinh;
}
string CongDan::GetCCCD(){
    return this->cccd;
}
string CongDan::GetDiaChi(){
    return this->diachi;
}
int CongDan::GetDem(){
    return dem;
}
void CongDan::SetHoTen(string hoten){
    this->hoten=hoten;
}
void CongDan::SetNamSinh(int namsinh){
    time_t t=time(nullptr);
    tm* ltm=localtime(&t);
    int namhientai=ltm->tm_year+1900;
    while(namsinh>namhientai-18||namsinh<1900){
        cout<<"Nam sinh khong hop le! Moi ban nhap lai: ";
        cin>>namsinh;
    }
    this->namsinh=namsinh;
}
void CongDan::SetCCCD(string cccd){
    this->cccd=cccd;
}
void CongDan::SetDiaChi(string diachi){
    this->diachi=diachi;
}
void CongDan::Nhap(){
    cin.ignore();
    cout<<"Nhap ho ten: "; getline(cin, hoten);
    time_t t=time(nullptr);
    tm* ltm=localtime(&t);
    int namhientai=ltm->tm_year+1900;
    cout<<"Nhap nam sinh (1900-"<<namhientai-18<<"): "; cin>>namsinh;
    while(namsinh>namhientai-18||namsinh<1900){
        cout<<"Nam sinh khong hop le! Moi ban nhap lai: ";
        cin>>namsinh;
    }
    cin.ignore();
    cout<<"Nhap CCCD: "; getline(cin, cccd);
    cout<<"Nhap dia chi: "; getline(cin, diachi);
}
void CongDan::Xuat(){
    cout<<"Ho ten: "<<hoten<<endl;
    cout<<"Nam sinh: "<<namsinh<<endl;
    cout<<"CCCD: "<<cccd<<endl;
    cout<<"Dia chi: "<<diachi<<endl;
}