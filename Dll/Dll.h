#pragma once
#ifndef _DLL_H_
#define _DLL_H_

#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <chrono>

#ifdef DLL_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

const int studentoId = 1613226;

extern "C"
DLL_API void F1(std::chrono::steady_clock::time_point);

extern "C"
DLL_API void F2();

extern "C"
DLL_API void F3();

extern "C"
DLL_API void F4(float, float, float, float);

extern "C"
DLL_API void F5(float);

extern "C"
DLL_API void F6();

#endif