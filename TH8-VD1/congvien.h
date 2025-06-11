#include "ve.h"
#pragma once
#ifndef CONGVIEN_H
#define CONGVIEN_H
class CongVien{
private:
    VE** dsve;
    int sl;
    static int dem;
public:
    ~CongVien();
    CongVien();
    CongVien(int);
    CongVien(int, VE**);
    CongVien(const CongVien&);
    CongVien& operator=(const CongVien&);
    int GetSL();
    static int GetDem();
    void SetSL(int);
    void Nhap();
    VE* Nhap1();
    void Xuat();
    int TinhTongTienVeTungPhan();
    void VeTungPhanCaoNhat();
    int DemVeTronGoi();
    int DemVeTungPhan();
    void SapXepVe();
};
#endif