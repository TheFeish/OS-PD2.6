#include "../Dll/Dll.h"

int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    F2();
    F3();
    for (int F = -2; F <= 2; F++) {
        F4(F, -(studentoId % 19), studentoId % 25, studentoId / 1000000000000.0);
        F5(F);
    }
    F6();
    F1(start);
    std::cin.get();
}
