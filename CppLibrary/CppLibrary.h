#pragma once

#ifdef CPP_LIBRARY
#define CPP_LIBRARY_API __declspec(dllexport)
#else
#define CPP_LIBRARY_API __declspec(dllexport)
#endif

extern "C" CPP_LIBRARY_API float CppConversion(int, int, int);
