#include "main.h"
#include <stdlib.h>
#include <wchar.h>

LPWSTR ProcessSubtraction(LPWSTR lhs, LPWSTR rhs)
{
    wchar_t* endptr;
    double num1 = wcstod(lhs, &endptr);
    double num2 = wcstod(rhs, &endptr);

    double s = num1 - num2;

    static wchar_t buffer[256];

    swprintf(buffer, 256, L"%.100g", s);
    return buffer;
}

LPWSTR ProcessAddition(LPWSTR lhs, LPWSTR rhs)
{
    wchar_t* endptr;
    double num1 = wcstod(lhs, &endptr);
    double num2 = wcstod(rhs, &endptr);

    double s = num1 + num2;

    static wchar_t buffer[256];

    swprintf(buffer, 256, L"%.100g", s);
    return buffer;
}
