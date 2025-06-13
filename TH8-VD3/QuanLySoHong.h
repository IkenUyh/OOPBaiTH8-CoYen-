#pragma once
#ifndef QUANLYSOHONG_H
#define QUANLYSOHONG_H
#include "SoHongDatNongNghiep.h"
#include "SoHongDatPhiNongNghiep.h"
class QuanLySoHong{
    private:
        SoHong** ds;
        int sl;
        static int dem;
    public:
        ~QuanLySoHong();
        QuanLySoHong();
        QuanLySoHong(int);
        QuanLySoHong(const QuanLySoHong&);
        QuanLySoHong& operator=(const QuanLySoHong&);
        int GetSL();
        static int GetDem();
        void Nhap();
        void Xuat();
        void ThuaDatCoTienThueMax();
        void DatNongNghiepHetHan();
};
#endif
