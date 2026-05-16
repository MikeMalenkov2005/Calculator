#include "main.h"

#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#define N 20

#define _WS_BUTTON	(WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON)
#define _WS_WINDOW	(WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX)

LRESULT CALLBACK MainWindowProc(_In_ HWND hWnd, _In_ UINT Msg, _In_ WPARAM wParam, _In_ LPARAM lParam)
{
	switch (Msg)
	{
	case WM_CREATE:
		CreateWindowW(L"BUTTON", L"1", _WS_BUTTON, N * 1 , N * 5 , N * 3, N * 3, hWnd, (HMENU)ID_1  , (HINSTANCE)GetWindowLongPtrW(hWnd, GWLP_HINSTANCE), NULL);
		CreateWindowW(L"BUTTON", L"2", _WS_BUTTON, N * 5 , N * 5 , N * 3, N * 3, hWnd, (HMENU)ID_2  , (HINSTANCE)GetWindowLongPtrW(hWnd, GWLP_HINSTANCE), NULL);
		CreateWindowW(L"BUTTON", L"3", _WS_BUTTON, N * 9 , N * 5 , N * 3, N * 3, hWnd, (HMENU)ID_3  , (HINSTANCE)GetWindowLongPtrW(hWnd, GWLP_HINSTANCE), NULL);
		CreateWindowW(L"BUTTON", L"4", _WS_BUTTON, N * 1 , N * 9 , N * 3, N * 3, hWnd, (HMENU)ID_4  , (HINSTANCE)GetWindowLongPtrW(hWnd, GWLP_HINSTANCE), NULL);
		CreateWindowW(L"BUTTON", L"5", _WS_BUTTON, N * 5 , N * 9 , N * 3, N * 3, hWnd, (HMENU)ID_5  , (HINSTANCE)GetWindowLongPtrW(hWnd, GWLP_HINSTANCE), NULL);
		CreateWindowW(L"BUTTON", L"6", _WS_BUTTON, N * 9 , N * 9 , N * 3, N * 3, hWnd, (HMENU)ID_6  , (HINSTANCE)GetWindowLongPtrW(hWnd, GWLP_HINSTANCE), NULL);
		CreateWindowW(L"BUTTON", L"7", _WS_BUTTON, N * 1 , N * 13, N * 3, N * 3, hWnd, (HMENU)ID_7  , (HINSTANCE)GetWindowLongPtrW(hWnd, GWLP_HINSTANCE), NULL);
		CreateWindowW(L"BUTTON", L"8", _WS_BUTTON, N * 5 , N * 13, N * 3, N * 3, hWnd, (HMENU)ID_8  , (HINSTANCE)GetWindowLongPtrW(hWnd, GWLP_HINSTANCE), NULL);
		CreateWindowW(L"BUTTON", L"9", _WS_BUTTON, N * 9 , N * 13, N * 3, N * 3, hWnd, (HMENU)ID_9  , (HINSTANCE)GetWindowLongPtrW(hWnd, GWLP_HINSTANCE), NULL);
		CreateWindowW(L"BUTTON", L"0", _WS_BUTTON, N * 5 , N * 17, N * 3, N * 3, hWnd, (HMENU)ID_0  , (HINSTANCE)GetWindowLongPtrW(hWnd, GWLP_HINSTANCE), NULL);
		CreateWindowW(L"BUTTON", L"C", _WS_BUTTON, N * 13, N * 1 , N * 3, N * 3, hWnd, (HMENU)ID_CLR, (HINSTANCE)GetWindowLongPtrW(hWnd, GWLP_HINSTANCE), NULL);
		CreateWindowW(L"BUTTON", L".", _WS_BUTTON, N * 1 , N * 17, N * 3, N * 3, hWnd, (HMENU)ID_DOT, (HINSTANCE)GetWindowLongPtrW(hWnd, GWLP_HINSTANCE), NULL);
		CreateWindowW(L"BUTTON", L"+", _WS_BUTTON, N * 13, N * 5 , N * 3, N * 3, hWnd, (HMENU)ID_ADD, (HINSTANCE)GetWindowLongPtrW(hWnd, GWLP_HINSTANCE), NULL);
		CreateWindowW(L"BUTTON", L"-", _WS_BUTTON, N * 13, N * 9 , N * 3, N * 3, hWnd, (HMENU)ID_SUB, (HINSTANCE)GetWindowLongPtrW(hWnd, GWLP_HINSTANCE), NULL);
		CreateWindowW(L"BUTTON", L"*", _WS_BUTTON, N * 13, N * 13, N * 3, N * 3, hWnd, (HMENU)ID_MUL, (HINSTANCE)GetWindowLongPtrW(hWnd, GWLP_HINSTANCE), NULL);
		CreateWindowW(L"BUTTON", L"/", _WS_BUTTON, N * 13, N * 17, N * 3, N * 3, hWnd, (HMENU)ID_DIV, (HINSTANCE)GetWindowLongPtrW(hWnd, GWLP_HINSTANCE), NULL);
		CreateWindowW(L"BUTTON", L"=", _WS_BUTTON, N * 9 , N * 17, N * 3, N * 3, hWnd, (HMENU)ID_EQU, (HINSTANCE)GetWindowLongPtrW(hWnd, GWLP_HINSTANCE), NULL);
		break;
	case WM_DESTROY:
		PostQuitMessage(EXIT_SUCCESS);
		return 0;
	case WM_COMMAND:
		if (LOWORD(wParam) > 100 && LOWORD(wParam) < 118) OnButtonPress(hWnd, LOWORD(wParam));
		break;
	}
	return DefWindowProcW(hWnd, Msg, wParam, lParam);
}

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	HWND hWnd;
	MSG msg = { 0 };
	WNDCLASSW wc = { 0 };
	RECT rect = { 0, 0, N * 17, N * 21 };
	wc.lpfnWndProc = MainWindowProc;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIconW(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursorW(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszClassName = L"MainWindowClass";
	if (!RegisterClassW(&wc))
	{
		MessageBoxW(NULL, L"Failed to register a window class!", L"Error!", MB_ICONERROR);
		return EXIT_FAILURE;
	}
	AdjustWindowRect(&rect, _WS_WINDOW, NULL);
	if (!(hWnd = CreateWindowW(wc.lpszClassName, L"Calculator", _WS_WINDOW, CW_USEDEFAULT, CW_USEDEFAULT, rect.right - rect.left, rect.bottom - rect.top, NULL, NULL, hInstance, NULL)))
	{
		MessageBoxW(NULL, L"Failed to create a main window!", L"Error!", MB_ICONERROR);
		return EXIT_FAILURE;
	}
	ShowWindow(hWnd, nCmdShow);
	while (GetMessageW(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}
	return (int)msg.wParam;
}

void OnButtonPress(HWND hWnd, int id)
{
	static BOOL dot;
	static LPWSTR lhs;
	static LPWSTR(*op)(LPWSTR, LPWSTR);
	switch (id)
	{
	case ID_1:
		AddToCurrentText(L'1');
		break;
	case ID_2:
		AddToCurrentText(L'2');
		break;
	case ID_3:
		AddToCurrentText(L'3');
		break;
	case ID_4:
		AddToCurrentText(L'4');
		break;
	case ID_5:
		AddToCurrentText(L'5');
		break;
	case ID_6:
		AddToCurrentText(L'6');
		break;
	case ID_7:
		AddToCurrentText(L'7');
		break;
	case ID_8:
		AddToCurrentText(L'8');
		break;
	case ID_9:
		AddToCurrentText(L'9');
		break;
	case ID_0:
		AddToCurrentText(L'0');
		break;
	case ID_CLR:
		if (!GetCurrentText()[0])
		{
			lhs = NULL;
			op = NULL;
		}
		SetCurrentText(NULL);
		dot = FALSE;
		break;
	case ID_DOT:
		if (!dot)
		{
			AddToCurrentText(L'.');
			dot = TRUE;
		}
		break;
	case ID_EQU:
		if (op) SetCurrentText(op(lhs, GetCurrentText()));
		MessageBox(hWnd, GetCurrentText(), L"Result", MB_ICONINFORMATION);
		break;
	}
}
