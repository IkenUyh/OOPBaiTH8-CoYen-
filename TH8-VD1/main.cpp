#include "congvien.h"
#include "vetrongoi.h"
#include "vetungphan.h"
#include<iomanip>
int main(){
    CongVien cv;
    cout<<"===== CHUONG TRINH QUAN LY CONG VIEN DAM SEN =====\n\n";
    cout<<"1. Nhap danh sach ve:\n";
    cv.Nhap();
    cout<<"Danh sach vua nhap:\n"; cv.Xuat();
    cout<<"\n2. Tong tien ve tung phan:\n";
    cout<<"Tong tien: "<<fixed<<setprecision(0)<<cv.TinhTongTienVeTungPhan()<<endl;
    cout<<"\n3. Ve tung phan co gia cao nhat:\n";
    cv.VeTungPhanCaoNhat();
    cout<<"\n4. Thong ke:\n";
    cout<<"So luong ve: "<<VE::GetDem()<<endl;
    cout<<"So luong ve tron goi: "<<VeTronGoi::GetDem()<<endl;
    cout<<"So luong ve tung phan: "<<VeTungPhan::GetDem()<<endl;
    cout<<"\n5. Danh sach ve sau khi sap xep:\n";
    cv.SapXepVe();
    cv.Xuat();
    cout<<"\n===== KET THUC CHUONG TRINH =====\n";
    return 0;
}