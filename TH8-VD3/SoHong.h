#pragma once
#ifndef SOHONG_H
#define SOHONG_H
#include "DSCongDan.h"
#include "Ngay.h"
#include <string>
class SoHong{
    protected:
        string sogiaycn;
        DSCongDan chudat;
        int sothuadat;
        string sotobando;
        string diachithuadat;
        double dientich;
        Ngay ngaycap;
        double dongiathue;
        static int dem;
    public:
        virtual ~SoHong();
        SoHong();
        SoHong(string, DSCongDan, int, string, string, double, Ngay, double);
        SoHong(const SoHong&);
        SoHong& operator=(const SoHong&);
        string GetSoGiayCN();
        DSCongDan GetChuDat();
        int GetSoThuaDat();
        string GetSoToBanDo();
        string GetDiaChiThuaDat();
        double GetDienTich();
        Ngay GetNgayCap();
        double GetDonGiaThue();
        static int GetDem();
        void SetSoGiayCN(string);
        void SetChuDat(DSCongDan);
        void SetSoThuaDat(int);
        void SetSoToBanDo(string);
        void SetDiaChiThuaDat(string);
        void SetDienTich(double);
        void SetNgayCap(Ngay);
        void SetDonGiaThue(double);
        virtual void Nhap();
        virtual void Xuat();
        virtual string GetLoai()=0;
        double TinhTienThue();
};
#endif