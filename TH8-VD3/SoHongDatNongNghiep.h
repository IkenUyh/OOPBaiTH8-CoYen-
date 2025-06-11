#pragma once
#ifndef SOHONGDATNONGNGHIEP_H
#define SOHONGDATNONGNGHIEP_H
#include "SoHong.h"
class SoHongDatNongNghiep : public SoHong{
    protected:
        int thoihan;
        static int dem;
    public:
        ~SoHongDatNongNghiep();
        SoHongDatNongNghiep();
        SoHongDatNongNghiep(string, DSCongDan, int, string, string, double, Ngay, double, int);
        SoHongDatNongNghiep(const SoHongDatNongNghiep&);
        SoHongDatNongNghiep& operator=(const SoHongDatNongNghiep&);
        int GetThoiHan();
        static int GetDem();
        void SetThoiHan(int);
        void Nhap();
        void Xuat();
        string GetLoai();
};
#endif