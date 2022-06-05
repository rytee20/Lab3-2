#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef KK_HEADER_H
#define KK_HEADER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <Windows.h>
#include <locale>

using namespace std;

int controlCommand();

class Date
{
private:

public:

    int day;
    int mounth;
    int year;

    Date& operator=(const Date &equal);

    Date();
};

class Storage
{
private:

    char* name;
    double cost;
    int amount;
    int sectionnumber;

public:

    static int count;
    Date arriveddate;

    Storage& operator=(const Storage& equal);
    friend bool operator>(Storage& Obj, Date& fdate);

    char* GetName();
    double GetCost();
    int GetAmount();
    int GetSectionnumber();

    void SetName(char* new_name);
    void SetCost(double new_cost);
    void SetAmount(int new_amount);
    void SetSectionnumber(int new_sectionnumber);

    Storage();

    friend void SearchProductBySection(Storage* Obj, int fcount);
    friend void SortByAmountDescending(Storage* Obj, int fcount);
    friend int CountFor3thCase(Storage* Obj1, Date& fdate, int fcount);
    friend void For3thCase(Storage* Obj1, Storage*& Obj2, Date& fdate, int fcount);

    friend void PrintBase(Storage* Obj, int fcount);
    friend void SaveBase(Storage* Obj, int fcount);
    friend void СreateBase(Storage* Obj, int fcount);
    friend void ReadBase(Storage*& Obj, int fcount);
};

class Storage_box
{
public:
    Storage* StorageBase;

    Storage_box();

    void addElement();

    ~Storage_box();
};

#endif KK_HEADER_H
