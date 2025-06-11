#include "vetungphan.h"
int VeTungPhan::dem=0;
VeTungPhan::~VeTungPhan(){
    cout<<"Da huy mot ve tung phan"<<endl;
    --dem;
}
VeTungPhan::VeTungPhan():VE(){
    this->sotrochoi=0;
    ++dem;
}
VeTungPhan::VeTungPhan(string mave, string hoten, int namsinh, int sotrochoi):VE(mave, hoten, namsinh, sotrochoi){
    ++dem;
}
VeTungPhan::VeTungPhan(const VeTungPhan& vtp):VE(vtp){
    ++dem;
}
VeTungPhan& VeTungPhan::operator=(const VeTungPhan& vtp){
    VE::operator=(vtp);
    return *this;
}
int VeTungPhan::GetDem(){
    return dem;
}
void VeTungPhan::Nhap(){
    VE::Nhap();
    cout<<"Nhap so tro choi: "; cin>>this->sotrochoi;
    while(this->sotrochoi<0){
        cout<<"So tro choi khong hop le! Moi ban nhap lai: ";
        cin>>this->sotrochoi;
    }
}
void VeTungPhan::Xuat(){
    VE::Xuat();
}
string VeTungPhan::GetLoai(){
    return "Ve tung phan";
}
int VeTungPhan::TinhGiaVe(){
    return 70000+this->sotrochoi*20000;
}