#include "pch.h"
#include "CppLibrary.h"

float DesaturationFunction(float Red, float Green, float Blue) {
	return (float)(Red * 0.2627 + Green * 0.6780 + Blue * 0.0593);
}