#pragma once

#ifdef CPP_LIBRARY
#define CPP_LIBRARY_API __declspec(dllexport)
#else
#define CPP_LIBRARY_API __declspec(dllexport)
#endif

//funkcja ktora ma narzucone kompilowanie w C, ktora jest poza glownym 
//programem jako dllexport, zwraca odpowiedni szary odcien pixela
extern "C" CPP_LIBRARY_API float DesaturationFunction(float, float, float);
