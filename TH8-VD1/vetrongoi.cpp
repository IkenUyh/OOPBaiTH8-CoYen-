#include "vetrongoi.h"
int VeTronGoi::dem=0;
VeTronGoi::~VeTronGoi(){
    cout<<"Da huy mot ve tron goi"<<endl;
    --dem;
}
VeTronGoi::VeTronGoi():VE(){
    this->sotrochoi=30;
    ++dem;
}
VeTronGoi::VeTronGoi(string mave, string hoten, int namsinh):VE(mave, hoten, namsinh, 30){
    ++dem;
}
VeTronGoi::VeTronGoi(const VeTronGoi& vtg):VE(vtg){
    ++dem;
}
VeTronGoi& VeTronGoi::operator=(const VeTronGoi& vtg){
    VE::operator=(vtg);
    return *this;
}
int VeTronGoi::GetDem(){
    return dem;
}
void VeTronGoi::Nhap(){
    VE::Nhap();
}
void VeTronGoi::Xuat(){
    VE::Xuat();
}
string VeTronGoi::GetLoai(){
    return "Ve tron goi";
}
int VeTronGoi::TinhGiaVe(){
    return 200000;
}