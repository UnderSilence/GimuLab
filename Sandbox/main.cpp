//
// Created by Metal on 2020/11/14.
//

#include <iostream>
using namespace std;

namespace Gimu {
    __declspec(dllimport) void Print();
}

int main() {
    Gimu::Print();
    return 0;
}