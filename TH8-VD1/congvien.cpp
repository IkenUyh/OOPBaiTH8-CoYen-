#include "congvien.h"
#include "vetrongoi.h"
#include "vetungphan.h"
#include<iomanip>
int CongVien::dem=0;
CongVien::~CongVien(){
    if(this->dsve!=nullptr){
        for(int i=0; i<this->sl; i++)
            delete this->dsve[i];
        delete[] this->dsve;
        this->dsve=nullptr;
        this->sl=0;
    }
    --dem;
}
CongVien::CongVien():sl(0), dsve(nullptr){
    ++dem;
}
CongVien::CongVien(int sl):sl(sl), dsve(nullptr){
    if(sl>0){
        this->dsve=new VE*[sl];
        for(int i=0; i<sl; i++)
            this->dsve[i]=nullptr;
    }
    ++dem;
}
CongVien::CongVien(int sl, VE** ve):sl(sl), dsve(nullptr){
    if(sl>0&&ve!=nullptr){
        this->dsve=new VE*[sl];
        for(int i=0; i<sl; i++){
            if(ve[i]->GetLoai()=="Ve tron goi")
                this->dsve[i]=new VeTronGoi(*(VeTronGoi*)ve[i]);
            else
                this->dsve[i]=new VeTungPhan(*(VeTungPhan*)ve[i]);
        }
    }
    ++dem;
}
CongVien::CongVien(const CongVien& other):sl(other.sl), dsve(nullptr){
    if(sl>0&&other.dsve!=nullptr){
        this->dsve=new VE*[sl];
        for(int i=0; i<sl; i++){
            if(other.dsve[i]->GetLoai()=="Ve tron goi")
                this->dsve[i]=new VeTronGoi(*(VeTronGoi*)other.dsve[i]);
            else
                this->dsve[i]=new VeTungPhan(*(VeTungPhan*)other.dsve[i]);
        }
    }
    ++dem;
}
CongVien& CongVien::operator=(const CongVien& other){
    if(this!=&other){
        if(this->dsve!=nullptr){
            for(int i=0; i<this->sl; i++)
                delete this->dsve[i];
            delete[] this->dsve;
        }
        this->sl=other.sl;
        if(sl>0&&other.dsve!=nullptr){
            this->dsve=new VE*[sl];
            for(int i=0; i<sl; i++){
                if(other.dsve[i]->GetLoai()=="Ve tron goi")
                    this->dsve[i]=new VeTronGoi(*(VeTronGoi*)other.dsve[i]);
                else
                    this->dsve[i]=new VeTungPhan(*(VeTungPhan*)other.dsve[i]);
            }
        }
        else this->dsve=nullptr;
    }
    return *this;
}
int CongVien::GetSL(){
    return this->sl;
}
int CongVien::GetDem(){
    return dem;
}
void CongVien::SetSL(int sl){
    while(sl<1){
        cout<<"So luong khong hop le! Moi ban nhap lai: ";
        cin>>sl;
    }
    this->sl=sl;
}
void CongVien::Nhap(){
    int loai;
    do{
        cout<<"Nhap so luong ve: "; cin>>this->sl;
        if(this->sl<1) cout<<"So luong khong hop le! Moi ban nhap lai"<<endl;
    }while(this->sl<1);
    this->dsve=new VE*[this->sl];
    for(int i=0; i<this->sl; i++){
        cout<<"\n===========================\n";
        cout<<"Nhap thong tin ve thu "<<i+1<<": "<<endl;
        do{
            cout<<"Nhap loai (1: Ve tron goi, 2: Ve tung phan): ";
            cin>>loai;
            if(loai!=1&&loai!=2) cout<<"Loai ve khong hop le! Moi ban nhap lai"<<endl;
        }while(loai!=1&&loai!=2);
        if(loai==1)
            this->dsve[i]=new VeTronGoi;
        else
            this->dsve[i]=new VeTungPhan;
        this->dsve[i]->Nhap();
    }
}
VE* CongVien::Nhap1(){
    int loai;
    VE* ve;
    do{
        cout<<"Nhap loai (1: Ve tron goi, 2: Ve tung phan): ";
        cin>>loai;
        if(loai!=1&&loai!=2) cout<<"Loai ve khong hop le! Moi ban nhap lai"<<endl;
    }while(loai!=1&&loai!=2);
    if(loai==1)
        ve=new VeTronGoi;
    else
        ve=new VeTungPhan;
    ve->Nhap();
    return ve;
}
void CongVien::Xuat(){
    if(this->dsve==nullptr) cout<<"Danh sach ve rong"<<endl;
    else{
        cout<<"\n=====THONG TIN VE=====\n";
        for(int i=0; i<this->sl; i++){
            cout<<"---VE THU "<<i+1<<"---"<<endl;
            this->dsve[i]->Xuat();
            cout<<endl;
        }
    }
}
int CongVien::TinhTongTienVeTungPhan(){
    int tong=0;
    for(int i=0; i<this->sl; i++){
        if(this->dsve[i]->GetLoai()=="Ve tung phan")
            tong+=this->dsve[i]->TinhGiaVe();
    }
    return tong;
}
void CongVien::VeTungPhanCaoNhat(){
    int maxgia=-1;
    for(int i=0; i<this->sl; i++){
        if(this->dsve[i]->GetLoai()=="Ve tung phan"&&this->dsve[i]->TinhGiaVe()>maxgia)
            maxgia=this->dsve[i]->TinhGiaVe();
    }
    if(maxgia==-1){
        cout<<"Cong vien khong co ve tung phan"<<endl;
        return;
    }
    cout<<"\n=====VE TUNG PHAN CO GIA CAO NHAT ("<<maxgia<<")=====\n";
    for(int i=0; i<this->sl; i++){
        if(this->dsve[i]->GetLoai()=="Ve tung phan"&&this->dsve[i]->TinhGiaVe()==maxgia){
            cout<<"---VE THU "<<i+1<<"---"<<endl;
            this->dsve[i]->Xuat();
            cout<<endl;
        }
    }
}
int CongVien::DemVeTronGoi(){
    int dem=0;
    for(int i=0; i<this->sl; i++){
        if(this->dsve[i]->GetLoai()=="Ve tron goi")
            dem++;
    }
    return dem;
}
int CongVien::DemVeTungPhan(){
    int dem=0;
    for(int i=0; i<this->sl; i++){
        if(this->dsve[i]->GetLoai()=="Ve tung phan")
            dem++;
    }
    return dem;
}
void CongVien::SapXepVe(){
    for(int i=0; i<this->sl-1; i++){
        for(int j=i+1; j<this->sl; j++){
            if(this->dsve[i]->GetLoai()=="Ve tung phan"&&this->dsve[j]->GetLoai()=="Ve tron goi"){
                VE* temp=this->dsve[i];
                this->dsve[i]=this->dsve[j];
                this->dsve[j]=temp;
            }
        }
    }
    int k=-1;
    while(k+1<this->sl&&this->dsve[k+1]->GetLoai()=="Ve tron goi") k++;
    for(int i=0; i<k; i++){
        for(int j=i+1; j<=k; j++){
            if(this->dsve[i]->GetMaVe()>this->dsve[j]->GetMaVe()){
                VE* temp=this->dsve[i];
                this->dsve[i]=this->dsve[j];
                this->dsve[j]=temp;
            }
        }
    }
    for(int i=k+1; i<this->sl-1; i++){
        for(int j=i+1; j<this->sl; j++){
            if(this->dsve[i]->TinhGiaVe()<this->dsve[j]->TinhGiaVe()){
                VE* temp=this->dsve[i];
                this->dsve[i]=this->dsve[j];
                this->dsve[j]=temp;
            }
        }
    }
}