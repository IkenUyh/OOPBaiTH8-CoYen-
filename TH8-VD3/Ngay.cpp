#include "Ngay.h"
#include <iostream>
using namespace std;
int Ngay::dem=0;
Ngay::~Ngay(){
    cout<<"Da huy mot ngay"<<endl;
    --dem;
}
Ngay::Ngay():ngay(1), thang(1), nam(2000){
    ++dem;
}
Ngay::Ngay(int ngay, int thang, int nam):ngay(ngay), thang(thang), nam(nam){
    ++dem;
}
Ngay::Ngay(const Ngay& other){
    this->ngay=other.ngay;
    this->thang=other.thang;
    this->nam=other.nam;
    ++dem;
}
Ngay& Ngay::operator=(const Ngay& other){
    this->ngay=other.ngay;
    this->thang=other.thang;
    this->nam=other.nam;
    return *this;
}
int Ngay::GetNgay(){
    return this->ngay;
}
int Ngay::GetThang(){
    return this->thang;
}
int Ngay::GetNam(){
    return this->nam;
}
void Ngay::SetNgay(int ngay){
    this->ngay=ngay;
}
void Ngay::SetThang(int thang){
    this->thang=thang;
}
void Ngay::SetNam(int nam){
    this->nam=nam;
}
void Ngay::Nhap(){
    do{
        cout<<"Nhap ngay thang nam (dd mm yyyy): ";
        cin>>ngay>>thang>>nam;
        if(!KiemTraHopLe()) cout<<"Ngay khong hop le! Moi ban nhap lai: ";
    }while(!KiemTraHopLe());
}
void Ngay::Xuat(){
    cout<<ngay<<"/"<<thang<<"/"<<nam<<endl;
}
bool Ngay::KiemTraHopLe(){
    if(thang<1||thang>12) return false;
    if(ngay<1||ngay>TinhSoNgayTrongThang(thang, nam)) return false;
    if(nam<1900) return false;
    return true;
}
int Ngay::TinhSoNgayTrongThang(int thang, int nam){
    switch(thang){
        case 4: case 6: case 9: case 11: return 30;
        case 2: if((nam%4==0&&nam%100!=0)||(nam%400==0)) return 29; return 28;
        default: return 31;
    }
}