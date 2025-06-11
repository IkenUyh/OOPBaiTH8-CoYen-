#pragma once
#ifndef NGAY_H
#define NGAY_H
#include<iostream>
#include<string>
using namespace std;
class Ngay{
private:
    int ngay,thang,nam;
public:
    ~Ngay();
    Ngay();
    Ngay(int,int,int);
    Ngay(const Ngay&);
    Ngay&operator=(const Ngay&);
    int GetNgay();
    int GetThang();
    int GetNam();
    void SetNgay(int);
    void SetThang(int);
    void SetNam(int);
    void Nhap();
    void Xuat();
    bool KiemTraHopLe();
    int TinhSoNgayTrongThang(int,int);
};
#endif