#include<iostream>
#include<string>
using namespace std;
#pragma once
#ifndef VE_H
#define VE_H
class VE{
protected:
    string mave;
    string hoten;
    int namsinh;
    int sotrochoi;
    static int dem;
public:
    virtual ~VE();
    VE();
    VE(string, string, int, int);
    VE(const VE&);
    VE& operator=(const VE&);
    string GetMaVe();
    string GetHoTen();
    int GetNamSinh();
    int GetSoTroChoi();
    static int GetDem();
    void SetHoTen(string);
    void SetNamSinh(int);
    void SetSoTroChoi(int);
    virtual void Nhap();
    virtual void Xuat();
    virtual string GetLoai()=0;
    virtual int TinhGiaVe()=0;
};

#endif