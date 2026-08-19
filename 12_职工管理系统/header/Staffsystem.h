#pragma once

#include <iostream>
#include <string>
#include "Staff.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"

using namespace std;

class Staffsystem {
    public:
        int m_num;
        Staff **StaffArray;
    public:
        Staffsystem();
        void ShowMenu();
        bool CheckEmpty();
        void ShowStaff();
        void AddStaff();
        int FindStaff();
        //int FindStaff_id(int id);
        //int FindStaff_name(string name);
        void DeleteStaff();
        void ModifyStaff();
        void SortStaff();
};