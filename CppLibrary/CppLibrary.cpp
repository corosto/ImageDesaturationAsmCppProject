#include "pch.h"
#include "CppLibrary.h"

float CppConversion(int Red, int Green, int Blue) {
	return (float)(Red * 0.2627 + Green * 0.6780 + Blue * 0.0593);
}