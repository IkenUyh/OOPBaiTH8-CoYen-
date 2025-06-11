#include "SoHong.h"
#include <iostream>
#include <iomanip>
using namespace std;
int SoHong::dem=0;
SoHong::~SoHong(){
    cout<<"Da huy mot so hong"<<endl;
    --dem;
}
SoHong::SoHong():sogiaycn(""), sothuadat(0), sotobando(""), diachithuadat(""), dientich(0), dongiathue(0){
    ++dem;
}

SoHong::SoHong(string sogiaycn, DSCongDan chudat, int sothuadat, string sotobando, string diachithuadat, double dientich, Ngay ngaycap, double dongiathue):sogiaycn(sogiaycn), chudat(chudat), sothuadat(sothuadat), sotobando(sotobando), diachithuadat(diachithuadat), dientich(dientich), ngaycap(ngaycap), dongiathue(dongiathue){
    ++dem;
}
SoHong::SoHong(const SoHong& other){
    this->sogiaycn=other.sogiaycn;
    this->chudat=other.chudat;
    this->sothuadat=other.sothuadat;
    this->sotobando=other.sotobando;
    this->diachithuadat=other.diachithuadat;
    this->dientich=other.dientich;
    this->ngaycap=other.ngaycap;
    this->dongiathue=other.dongiathue;
    ++dem;
}
SoHong& SoHong::operator=(const SoHong& other){
    this->sogiaycn=other.sogiaycn;
    this->chudat=other.chudat;
    this->sothuadat=other.sothuadat;
    this->sotobando=other.sotobando;
    this->diachithuadat=other.diachithuadat;
    this->dientich=other.dientich;
    this->ngaycap=other.ngaycap;
    this->dongiathue=other.dongiathue;
    return *this;
}
string SoHong::GetSoGiayCN(){
    return this->sogiaycn;
}
DSCongDan SoHong::GetChuDat(){
    return this->chudat;
}
int SoHong::GetSoThuaDat(){
    return this->sothuadat;
}
string SoHong::GetSoToBanDo(){
    return this->sotobando;
}
string SoHong::GetDiaChiThuaDat(){
    return this->diachithuadat;
}
double SoHong::GetDienTich(){
    return this->dientich;
}
Ngay SoHong::GetNgayCap(){
    return this->ngaycap;
}
double SoHong::GetDonGiaThue(){
    return this->dongiathue;
}
int SoHong::GetDem(){
    return dem;
}
void SoHong::SetSoGiayCN(string sogiaycn){
    this->sogiaycn=sogiaycn;
}
void SoHong::SetChuDat(DSCongDan chudat){
    this->chudat=chudat;
}
void SoHong::SetSoThuaDat(int sothuadat){
    while(sothuadat<1){
        cout<<"So thua dat khong hop le! Moi ban nhap lai: ";
        cin>>sothuadat;
    }
    this->sothuadat=sothuadat;
}
void SoHong::SetSoToBanDo(string sotobando){
    this->sotobando=sotobando;
}
void SoHong::SetDiaChiThuaDat(string diachithuadat){
    this->diachithuadat=diachithuadat;
}
void SoHong::SetDienTich(double dientich){
    while(dientich<0){
        cout<<"Dien tich khong hop le! Moi ban nhap lai: ";
        cin>>dientich;
    }
    this->dientich=dientich;
}
void SoHong::SetNgayCap(Ngay ngaycap){
    this->ngaycap=ngaycap;
}
void SoHong::SetDonGiaThue(double dongiathue){
    while(dongiathue<0){
        cout<<"Don gia thue khong hop le! Moi ban nhap lai: ";
        cin>>dongiathue;
    }
    this->dongiathue=dongiathue;
}
void SoHong::Nhap(){
    cin.ignore();
    cout<<"Nhap so giay chung nhan: "; getline(cin, sogiaycn);
    cout<<"Nhap thong tin chu dat:\n";
    chudat.Nhap();
    cout<<"Nhap so thua dat: "; cin>>sothuadat;
    while(sothuadat<1){
        cout<<"So thua dat khong hop le! Moi ban nhap lai: ";
        cin>>sothuadat;
    }
    cin.ignore();
    cout<<"Nhap so to ban do: "; getline(cin, sotobando);
    cout<<"Nhap dia chi thua dat: "; getline(cin, diachithuadat);
    cout<<"Nhap dien tich (m2): "; cin>>dientich;
    while(dientich<0){
        cout<<"Dien tich khong hop le! Moi ban nhap lai: ";
        cin>>dientich;
    }
    cout<<"Nhap ngay cap:\n";
    ngaycap.Nhap();
    cout<<"Nhap don gia thue (VND/m2): "; cin>>dongiathue;
    while(dongiathue<0){
        cout<<"Don gia thue khong hop le! Moi ban nhap lai: ";
        cin>>dongiathue;
    }
}
void SoHong::Xuat(){
    cout<<"So giay chung nhan: "<<sogiaycn<<endl;
    cout<<"Chu dat:\n";
    chudat.Xuat();
    cout<<"So thua dat: "<<sothuadat<<endl;
    cout<<"So to ban do: "<<sotobando<<endl;
    cout<<"Dia chi thua dat: "<<diachithuadat<<endl;
    cout<<"Dien tich: "<<fixed<<setprecision(2)<<dientich<<" m2"<<endl;
    cout<<"Ngay cap: "; ngaycap.Xuat();
    cout<<"Loai dat: "<<GetLoai()<<endl;
    cout<<"Tien thue: "<<fixed<<setprecision(2)<<TinhTienThue()<<" VND"<<endl;
}
double SoHong::TinhTienThue(){
    return dientich*dongiathue;
}