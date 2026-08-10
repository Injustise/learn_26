#pragma once
#include <iostream>
using namespace std;
#include "point.h"

class Circle {
    private: 
        Point mo;
        int mr;
    public: 
        void set_o(Point o);

        void set_r(int r);

        Point get_o();

        int get_r(); 
};