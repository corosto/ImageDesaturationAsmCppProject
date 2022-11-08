#pragma once

#ifdef CPP_LIBRARY
#define CPP_LIBRARY_API __declspec(dllexport)
#else
#define CPP_LIBRARY_API __declspec(dllexport)
#endif

//funkcja kompilowana w jezyku C, ktora zwraca odpowiedni szary odcien pixela
extern "C" CPP_LIBRARY_API float CppConversion(int, int, int);
