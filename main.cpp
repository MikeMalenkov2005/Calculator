#include "main.h"

#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#define _WS_BUTTON	(WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON)
#define _WS_WINDOW	(WS_OVERLAPPEDWINDOW)

LRESULT CALLBACK MainWindowProc(_In_ HWND hWnd, _In_ UINT Msg, _In_ WPARAM wParam, _In_ LPARAM lParam)
{
	switch (Msg)
	{
	case WM_CREATE:
		CreateWindowW(L"BUTTON", L"1", _WS_BUTTON, 10, 10, 30, 30, hWnd, (HMENU)ID_1, (HINSTANCE)GetWindowLongPtrW(hWnd, GWLP_HINSTANCE), NULL);
		CreateWindowW(L"BUTTON", L"2", _WS_BUTTON, 50, 10, 30, 30, hWnd, (HMENU)ID_2, (HINSTANCE)GetWindowLongPtrW(hWnd, GWLP_HINSTANCE), NULL);
		CreateWindowW(L"BUTTON", L"3", _WS_BUTTON, 90, 10, 30, 30, hWnd, (HMENU)ID_3, (HINSTANCE)GetWindowLongPtrW(hWnd, GWLP_HINSTANCE), NULL);
		CreateWindowW(L"BUTTON", L"4", _WS_BUTTON, 10, 50, 30, 30, hWnd, (HMENU)ID_4, (HINSTANCE)GetWindowLongPtrW(hWnd, GWLP_HINSTANCE), NULL);
		CreateWindowW(L"BUTTON", L"5", _WS_BUTTON, 50, 50, 30, 30, hWnd, (HMENU)ID_5, (HINSTANCE)GetWindowLongPtrW(hWnd, GWLP_HINSTANCE), NULL);
		CreateWindowW(L"BUTTON", L"6", _WS_BUTTON, 90, 50, 30, 30, hWnd, (HMENU)ID_6, (HINSTANCE)GetWindowLongPtrW(hWnd, GWLP_HINSTANCE), NULL);
		CreateWindowW(L"BUTTON", L"7", _WS_BUTTON, 10, 90, 30, 30, hWnd, (HMENU)ID_7, (HINSTANCE)GetWindowLongPtrW(hWnd, GWLP_HINSTANCE), NULL);
		CreateWindowW(L"BUTTON", L"8", _WS_BUTTON, 50, 90, 30, 30, hWnd, (HMENU)ID_8, (HINSTANCE)GetWindowLongPtrW(hWnd, GWLP_HINSTANCE), NULL);
		CreateWindowW(L"BUTTON", L"9", _WS_BUTTON, 90, 90, 30, 30, hWnd, (HMENU)ID_9, (HINSTANCE)GetWindowLongPtrW(hWnd, GWLP_HINSTANCE), NULL);
		CreateWindowW(L"BUTTON", L"0", _WS_BUTTON, 50, 130, 30, 30, hWnd, (HMENU)ID_0, (HINSTANCE)GetWindowLongPtrW(hWnd, GWLP_HINSTANCE), NULL);
		return DefWindowProcW(hWnd, Msg, wParam, lParam);
	case WM_DESTROY:
		PostQuitMessage(EXIT_SUCCESS);
		return 0;
	default:
		return DefWindowProcW(hWnd, Msg, wParam, lParam);
	}
}

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	HWND hWnd;
	MSG msg = { 0 };
	WNDCLASSW wc = { 0 };
	//wc.style = 0;
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
	if (!(hWnd = CreateWindowW(wc.lpszClassName, L"Calculator", _WS_WINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 640, 480, NULL, NULL, hInstance, NULL)))
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
