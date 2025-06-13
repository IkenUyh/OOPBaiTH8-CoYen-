#pragma once
#ifndef DSCONGDAN_H
#define DSCONGDAN_H
#include "CongDan.h"
class DSCongDan {
private:
    CongDan* ds;
    int sl;
    static int dem;
public:
    ~DSCongDan();
    DSCongDan();
    DSCongDan(int);
    DSCongDan(const DSCongDan&);
    DSCongDan& operator=(const DSCongDan&);
    int GetSL();
    static int GetDem();
    void Nhap();
    void Xuat();
};
#endif
