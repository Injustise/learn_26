#include "circle.h"


        void Circle::set_o(Point o) {
            mo = o;
        }
        void Circle::set_r(int r) {
            mr = r;
        }
        Point Circle::get_o() {
            return mo;
        }
        int Circle::get_r() {
            return mr;
        }
