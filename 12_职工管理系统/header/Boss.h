#pragma once

#include <iostream>
#include <string>
#include "Staff.h"

using namespace std;

class Boss : public Staff {
public:
    Boss(int id, string name, int pos);
    void showifo();
};