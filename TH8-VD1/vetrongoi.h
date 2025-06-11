#include "ve.h"
#pragma once
#ifndef VETRONGOI_H
#define VETRONGOI_H
class VeTronGoi: public VE{
private:
    static int dem;
public:
    ~VeTronGoi();
    VeTronGoi();
    VeTronGoi(string, string, int);
    VeTronGoi(const VeTronGoi&);
    VeTronGoi& operator=(const VeTronGoi&);
    static int GetDem();
    void Nhap();
    void Xuat();
    string GetLoai();
    int TinhGiaVe();
};
#endif