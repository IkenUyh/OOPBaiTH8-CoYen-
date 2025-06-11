#pragma once
#ifndef CONGDAN_H
#define CONGDAN_H
#include <iostream>
#include <string>
using namespace std;
class CongDan {
protected:
    string hoTen;
    int namSinh;
    string CCCD;
    string diaChi;
    static int dem;
public:
    ~CongDan();
    CongDan();
    CongDan(string, int, string, string);
    CongDan(const CongDan&);
    CongDan& operator=(const CongDan&);
    string GetHoTen();
    int GetNamSinh();
    string GetCCCD();
    string GetDiaChi();
    static int GetDem();
    void SetHoTen(string);
    void SetNamSinh(int);
    void SetCCCD(string);
    void SetDiaChi(string);
    void Nhap();
    void Xuat();
};
#endif