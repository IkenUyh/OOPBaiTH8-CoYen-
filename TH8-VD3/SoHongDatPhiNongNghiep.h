#pragma once
#ifndef SOHONGDATPHINONGNGHIEP_H
#define SOHONGDATPHINONGNGHIEP_H
#include "SoHong.h"
class SoHongDatPhiNongNghiep : public SoHong{
    protected:
        static int dem;
    public:
        ~SoHongDatPhiNongNghiep();
        SoHongDatPhiNongNghiep();
        SoHongDatPhiNongNghiep(string, DSCongDan, int, string, string, double, Ngay, double);
        SoHongDatPhiNongNghiep(const SoHongDatPhiNongNghiep&);
        SoHongDatPhiNongNghiep& operator=(const SoHongDatPhiNongNghiep&);
        static int GetDem();
        void Nhap();
        void Xuat();
        string GetLoai();
};
#endif