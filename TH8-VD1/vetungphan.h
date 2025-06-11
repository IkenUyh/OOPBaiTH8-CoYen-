#include "ve.h"
#pragma once
#ifndef VETUNGPHAN_H
#define VETUNGPHAN_H
class VeTungPhan: public VE{
private:
    static int dem;
public:
    ~VeTungPhan();
    VeTungPhan();
    VeTungPhan(string, string, int, int);
    VeTungPhan(const VeTungPhan&);
    VeTungPhan& operator=(const VeTungPhan&);
    static int GetDem();
    void Nhap();
    void Xuat();
    string GetLoai();
    int TinhGiaVe();
};
#endif