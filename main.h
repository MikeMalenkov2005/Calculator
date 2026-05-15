#ifndef MAIN_H
#define MAIN_H

#pragma once

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <Windows.h>

#define ID_1    101
#define ID_2    102
#define ID_3    103
#define ID_4    104
#define ID_5    105
#define ID_6    106
#define ID_7    107
#define ID_8    108
#define ID_9    109
#define ID_0    110

#define ID_CLR  111
#define ID_DOT  112

#define ID_ADD  113
#define ID_SUB  114
#define ID_MUL  115
#define ID_DIV  116
#define ID_EQU  117

void OnButtonPress(int id);

void OnKeyPress(int key);

LPWSTR ProcessAddition(LPWSTR lhs, LPWSTR rhs);

LPWSTR ProcessSubtraction(LPWSTR lhs, LPWSTR rhs);

LPWSTR ProcessMultiplication(LPWSTR lhs, LPWSTR rhs);

LPWSTR ProcessDivision(LPWSTR lhs, LPWSTR rhs);

#endif
