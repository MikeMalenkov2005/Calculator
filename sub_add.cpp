#include "main.h"
#include <stdio.h>

LPWSTR ProcessSubtraction(LPWSTR lhs, LPWSTR rhs)
{
    double num1 = wcstod(lhs, NULL);
    double num2 = wcstod(rhs, NULL);

    double s = num1 - num2;

    static wchar_t buffer[256];

    swprintf(buffer, 256, L"%.10g", s);
    return buffer;
}

LPWSTR ProcessAddition(LPWSTR lhs, LPWSTR rhs)
{
    double num1 = wcstod(lhs, NULL);
    double num2 = wcstod(rhs, NULL);

    double s = num1 + num2;

    static wchar_t buffer[256];

    swprintf(buffer, 256, L"%.10g", s);
    return buffer;
}
