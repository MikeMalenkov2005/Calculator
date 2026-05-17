#include <main.h>
#include <stdio.h>

LPWSTR ProcessMultiplication(LPWSTR lhs, LPWSTR rhs)
{
	// Извлечение аргументов
	double left_arg = wcstod(lhs, NULL);
	double right_arg = wcstod(rhs, NULL);

	// Вычисление результата умножения
	double mul_res = left_arg * right_arg;

	// Выделение памяти для результата
	static wchar_t buffer[256];

	// Перевод результата в строку
	swprintf(buffer, 256, L"%.10g", mul_res);

	return buffer;
}

LPWSTR ProcessDivision(LPWSTR lhs, LPWSTR rhs)
{
	// Извлечение аргументов
	double left_arg = wcstod(lhs, NULL);
	double right_arg = wcstod(rhs, NULL);

	// Вычисление результата деления
	double div_res = left_arg / right_arg;

	// Выделение памяти для результата
	static wchar_t buffer[256];

	// Перевод результата в строку
	swprintf(buffer, 256, L"%.10g", div_res);

	return buffer;
}