#include "main.h"
#include <stdio.h>

LPWSTR ProcessMultiplication(LPWSTR lhs, LPWSTR rhs)
{
	double left_arg = wcstod(lhs, NULL);
	double right_arg = wcstod(rhs, NULL);

	double mul_res = left_arg * right_arg;

	static wchar_t buffer[256];

	swprintf(buffer, 256, L"%.10g", mul_res);
	return buffer;
}

LPWSTR ProcessDivision(LPWSTR lhs, LPWSTR rhs)
{
	double left_arg = wcstod(lhs, NULL);
	double right_arg = wcstod(rhs, NULL);

	double div_res = left_arg / right_arg;

	static wchar_t buffer[256];

	swprintf(buffer, 256, L"%.10g", div_res);
	return buffer;
}