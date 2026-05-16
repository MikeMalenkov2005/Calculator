#include "main.h"

#define LEN	1024

static SIZE_T len[2], i;
static WCHAR buffer[2][LEN];

void SwitchCurrentText(void)
{
	i = 1 - i;
}

LPWSTR GetCurrentText(void)
{
	return buffer[i];
}

BOOL SetCurrentText(LPWSTR text)
{
	SIZE_T l = lstrlenW(text);
	if (l >= LEN) return FALSE;
	if (l) memcpy(buffer, text, l * sizeof(*text));
	buffer[i][len[i] = l] = 0;
}

BOOL AddToCurrentText(WCHAR chr)
{
	if (len[i] + 1 >= LEN) return FALSE;
	buffer[i][len[i]++] = chr;
	buffer[i][len[i]] = 0;
}
