#pragma once
#include <iostream>
using namespace std;

class Point {
    private:
        int mx, my;
    public: 
        void set_x(int x); 

        void set_y(int y); 

        int get_x(); 

        int get_y();
};