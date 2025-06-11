#include "DSCongDan.h"
#include <iostream>
using namespace std;
int DSCongDan::dem=0;
DSCongDan::~DSCongDan(){
    cout<<"Da huy mot danh sach cong dan"<<endl;
    if(ds!=nullptr){
        delete[] ds;
        ds=nullptr;
        sl=0;
    }
    --dem;
}
DSCongDan::DSCongDan():sl(0), ds(nullptr){
    ++dem;
}
DSCongDan::DSCongDan(int sl):sl(sl), ds(nullptr){
    if(sl>0) ds=new CongDan[sl];
    ++dem;
}
DSCongDan::DSCongDan(const DSCongDan& other):sl(other.sl), ds(nullptr){
    if(sl>0){
        ds=new CongDan[sl];
        for(int i=0; i<sl; i++) ds[i]=other.ds[i];
    }
    ++dem;
}
DSCongDan& DSCongDan::operator=(const DSCongDan& other){
    if(this!=&other){
        if(ds!=nullptr) delete[] ds;
        sl=other.sl;
        if(sl>0){
            ds=new CongDan[sl];
            for(int i=0; i<sl; i++) ds[i]=other.ds[i];
        }
        else ds=nullptr;
    }
    return *this;
}
int DSCongDan::GetSL(){
    return this->sl;
}
int DSCongDan::GetDem(){
    return dem;
}
void DSCongDan::Nhap(){
    do{
        cout<<"Nhap so luong cong dan: "; cin>>sl;
        if(sl<1) cout<<"So luong khong hop le! Moi ban nhap lai: ";
    }while(sl<1);
    ds=new CongDan[sl];
    for(int i=0; i<sl; i++){
        cout<<"\n---CONG DAN THU "<<i+1<<"---"<<endl;
        ds[i].Nhap();
    }
}
void DSCongDan::Xuat(){
    if(sl==0||ds==nullptr){
        cout<<"Danh sach cong dan rong!"<<endl;
        return;
    }
    cout<<"\n=====DANH SACH CONG DAN=====\n";
    for(int i=0; i<sl; i++){
        cout<<"---CONG DAN THU "<<i+1<<"---"<<endl;
        ds[i].Xuat();
        cout<<endl;
    }
}