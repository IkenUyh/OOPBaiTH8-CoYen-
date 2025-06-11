#include "QuanLySoHong.h"
#include <ctime>
#include <iostream>
#include <iomanip>
using namespace std;
int QuanLySoHong::dem=0;
QuanLySoHong::~QuanLySoHong(){
    cout<<"Da huy mot danh sach so hong"<<endl;
    if(ds!=nullptr){
        for(int i=0; i<sl; i++) delete ds[i];
        delete[] ds;
        ds=nullptr;
        sl=0;
    }
    --dem;
}
QuanLySoHong::QuanLySoHong():sl(0), ds(nullptr){
    ++dem;
}
QuanLySoHong::QuanLySoHong(int sl):sl(sl), ds(nullptr){
    if(sl>0){
        ds=new SoHong*[sl];
        for(int i=0; i<sl; i++) ds[i]=nullptr;
    }
    ++dem;
}
QuanLySoHong::QuanLySoHong(const QuanLySoHong& other):sl(other.sl), ds(nullptr){
    if(sl>0){
        ds=new SoHong*[sl];
        for(int i=0; i<sl; i++){
            if(other.ds[i]->GetLoai()=="Dat nong nghiep")
                ds[i]=new SoHongDatNongNghiep(*(SoHongDatNongNghiep*)other.ds[i]);
            else
                ds[i]=new SoHongDatPhiNongNghiep(*(SoHongDatPhiNongNghiep*)other.ds[i]);
        }
    }
    ++dem;
}
QuanLySoHong& QuanLySoHong::operator=(const QuanLySoHong& other){
    if(this!=&other){
        if(ds!=nullptr){
            for(int i=0; i<sl; i++) delete ds[i];
            delete[] ds;
        }
        sl=other.sl;
        if(sl>0){
            ds=new SoHong*[sl];
            for(int i=0; i<sl; i++){
                if(other.ds[i]->GetLoai()=="Dat nong nghiep")
                    ds[i]=new SoHongDatNongNghiep(*(SoHongDatNongNghiep*)other.ds[i]);
                else
                    ds[i]=new SoHongDatPhiNongNghiep(*(SoHongDatPhiNongNghiep*)other.ds[i]);
            }
        }
        else ds=nullptr;
    }
    return *this;
}
int QuanLySoHong::GetSL(){
    return this->sl;
}
int QuanLySoHong::GetDem(){
    return dem;
}
void QuanLySoHong::Nhap(){
    int loai;
    do{
        cout<<"Nhap so luong so hong: "; cin>>sl;
        if(sl<1) cout<<"So luong khong hop le! Moi ban nhap lai: ";
    }while(sl<1);
    ds=new SoHong*[sl];
    for(int i=0; i<sl; i++){
        cout<<"\n---SO HONG THU "<<i+1<<"---"<<endl;
        do{
            cout<<"Nhap loai (1: Dat nong nghiep, 2: Dat phi nong nghiep): ";
            cin>>loai;
            if(loai!=1&&loai!=2) cout<<"Loai khong hop le! Moi ban nhap lai: ";
        }while(loai!=1&&loai!=2);
        if(loai==1)
            ds[i]=new SoHongDatNongNghiep;
        else
            ds[i]=new SoHongDatPhiNongNghiep;
        ds[i]->Nhap();
    }
}
void QuanLySoHong::Xuat(){
    if(sl==0||ds==nullptr){
        cout<<"Danh sach so hong rong!"<<endl;
        return;
    }
    cout<<"\n=====DANH SACH SO HONG=====\n";
    for(int i=0; i<sl; i++){
        cout<<"---SO HONG THU "<<i+1<<"---"<<endl;
        ds[i]->Xuat();
        cout<<endl;
    }
}
void QuanLySoHong::ThuaDatCoTienThueMax(){
    if(sl==0||ds==nullptr){
        cout<<"Danh sach so hong rong!"<<endl;
        return;
    }
    double maxthue=ds[0]->TinhTienThue();
    for(int i=1; i<sl; i++)
        if(ds[i]->TinhTienThue()>maxthue) maxthue=ds[i]->TinhTienThue();
    cout<<"\n=====THUA DAT CO TIEN THUE CAO NHAT ("<<fixed<<setprecision(2)<<maxthue<<" VND)=====\n";
    for(int i=0; i<sl; i++)
        if(ds[i]->TinhTienThue()==maxthue){
            ds[i]->Xuat();
            cout<<endl;
        }
}
void QuanLySoHong::DatNongNghiepHetHan(){
    time_t t=time(nullptr);
    tm* ltm=localtime(&t);
    int namhientai=ltm->tm_year+1900;
    int cnt=0;
    cout<<"\n=====THUA DAT NONG NGHIEP HET HAN=====\n";
    for(int i=0; i<sl; i++)
        if(ds[i]->GetLoai()=="Dat nong nghiep"){
            int thoihan=((SoHongDatNongNghiep*)ds[i])->GetThoiHan();
            if(thoihan<namhientai){
                ds[i]->Xuat();
                cout<<endl;
                cnt++;
            }
        }
    if(cnt==0) cout<<"Khong co thua dat nong nghiep nao het han!"<<endl;
}