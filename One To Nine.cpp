//yaaaay :D

#include <windows.h>
#include <string>
#include <chrono>


HMENU hMenu;
HWND slot1, slot2, slot3, slot4, slot5, slot6, slot7, slot8, slot9, Out, hMainWindow, hPW, PwEdit1;

void AddMenus(HWND hWnd)
{
	hMenu = CreateMenu();

	AppendMenu(hMenu, MF_STRING, 11, L"Clear");
	AppendMenu(hMenu, MF_STRING, 12, L"Test");

	SetMenu(hWnd, hMenu);
}

void AddWindows(HWND hWnd)
{
	slot1 = CreateWindowW(L"Button", L"1", WS_VISIBLE | WS_CHILD | WS_BORDER, 115, 50, 50, 50, hWnd, (HMENU)1, NULL, NULL);
	slot2 = CreateWindowW(L"Button", L"2", WS_VISIBLE | WS_CHILD | WS_BORDER, 165, 50, 50, 50, hWnd, (HMENU)2, NULL, NULL);
	slot3 = CreateWindowW(L"Button", L"3", WS_VISIBLE | WS_CHILD | WS_BORDER, 215, 50, 50, 50, hWnd, (HMENU)3, NULL, NULL);
	slot4 = CreateWindowW(L"Button", L"4", WS_VISIBLE | WS_CHILD | WS_BORDER, 115, 100, 50, 50, hWnd, (HMENU)4, NULL, NULL);
	slot5 = CreateWindowW(L"Button", L"5", WS_VISIBLE | WS_CHILD | WS_BORDER, 165, 100, 50, 50, hWnd, (HMENU)5, NULL, NULL);
	slot6 = CreateWindowW(L"Button", L"6", WS_VISIBLE | WS_CHILD | WS_BORDER, 215, 100, 50, 50, hWnd, (HMENU)6, NULL, NULL);
	slot7 = CreateWindowW(L"Button", L"7", WS_VISIBLE | WS_CHILD | WS_BORDER, 115, 150, 50, 50, hWnd, (HMENU)7, NULL, NULL);
	slot8 = CreateWindowW(L"Button", L"8", WS_VISIBLE | WS_CHILD | WS_BORDER, 165, 150, 50, 50, hWnd, (HMENU)8, NULL, NULL);
	slot9 = CreateWindowW(L"Button", L"9", WS_VISIBLE | WS_CHILD | WS_BORDER, 215, 150, 50, 50, hWnd, (HMENU)9, NULL, NULL);

	Out = CreateWindowW(L"Static", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 10, 300, 363, 20, hWnd, NULL, NULL, NULL);
}

void Timer()
{
	std::chrono::steady_clock::time_point _a = std::chrono::steady_clock::now();

	Sleep(1000);

	std::chrono::steady_clock::time_point _b = std::chrono::steady_clock::now();

	std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>> (_b - _a);

	std::wstring _ab = std::to_wstring(time_span.count());
	LPCWSTR _abcd = _ab.c_str();

	if (time_span.count() > 1.01)
	MessageBox(NULL, _abcd, L"more than 1.01 seconds", MB_OK);
	else
	MessageBox(NULL, _abcd, L"timer", MB_OK);
}

void ClearText()
{
	SetWindowText(Out, L"");
}

void TextSlots(int slot)
{
	int slotsize;

	switch (slot)
	{
	case 1:
		slotsize = GetWindowTextLength(slot1);
		break;
	case 2:
		slotsize = GetWindowTextLength(slot2);
		break;
	case 3:
		slotsize = GetWindowTextLength(slot3);
		break;
	case 4:
		slotsize = GetWindowTextLength(slot4);
		break;
	case 5:
		slotsize = GetWindowTextLength(slot5);
		break;
	case 6:
		slotsize = GetWindowTextLength(slot6);
		break;
	case 7:
		slotsize = GetWindowTextLength(slot7);
		break;
	case 8:
		slotsize = GetWindowTextLength(slot8);
		break;
	case 9:
		slotsize = GetWindowTextLength(slot9);
		break;
	default:
		slotsize = 1;
	}

	int outtextsize = GetWindowTextLength(Out);
	wchar_t* wcslot = new wchar_t[slotsize + 1];
	wchar_t* wcouttext = new wchar_t[outtextsize + 1];
	LPCWSTR lslot;

	switch (slot)
	{
	case 1:
		GetWindowText(slot1, wcslot, slotsize + 1);
		break;
	case 2:
		GetWindowText(slot2, wcslot, slotsize + 1);
		break;
	case 3:
		GetWindowText(slot3, wcslot, slotsize + 1);
		break;
	case 4:
		GetWindowText(slot4, wcslot, slotsize + 1);
		break;
	case 5:
		GetWindowText(slot5, wcslot, slotsize + 1);
		break;
	case 6:
		GetWindowText(slot6, wcslot, slotsize + 1);
		break;
	case 7:
		GetWindowText(slot7, wcslot, slotsize + 1);
		break;
	case 8:
		GetWindowText(slot8, wcslot, slotsize + 1);
		break;
	case 9:
		GetWindowText(slot9, wcslot, slotsize + 1);
		break;
	default:
		wchar_t idk[1] = L"";
		wcslot = idk;
	}

	GetWindowText(Out, wcouttext, outtextsize + 1);

	std::wstring wsslot = wcslot;
	std::wstring wsouttext = wcouttext;

	wsouttext += wsslot;
	lslot = wsouttext.c_str();

	SetWindowText(Out, lslot);

	if (wsouttext == L"1119")
	{
		SetWindowText(Out, L"");
		MessageBox(NULL, L"Yes.", L":)", MB_OK);
	}

	delete[] wcslot;
	delete[] wcouttext;
}

void CheckPass()
{
	int passlength = GetWindowTextLength(PwEdit1);

	wchar_t* wcpass = new wchar_t[passlength + 1];

	GetWindowText(PwEdit1, wcpass, passlength + 1);

	std::wstring wspass = wcpass;

	if (wspass == L"1119")
	{
		EnableWindow(hMainWindow, true);
		DestroyWindow(hPW);
	}
	else
	{
		SetWindowText(PwEdit1, L"");
	}
	delete[] wcpass;
}

void displayPassWindow(HWND hWnd)
{
	hPW = CreateWindowW(L"passWindow", L"Enter password...", WS_VISIBLE | WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, 250, 250, 300, 250, hWnd, NULL, NULL, NULL);

	PwEdit1 = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_PASSWORD, 100, 50, 80, 30, hPW, NULL, NULL, NULL);

	CreateWindowW(L"Button", L"Continue", WS_VISIBLE | WS_CHILD | WS_BORDER, 100, 100, 80, 30, hPW, (HMENU)1, NULL, NULL);
}

LRESULT CALLBACK PassWindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{
	case WM_COMMAND:
		switch (wp)
		{
		case 1:
			CheckPass();
			break;
		}
		break;
	case WM_CLOSE:
		PostQuitMessage(1);
		break;
	default:
		return DefWindowProcW(hWnd, msg, wp, lp);
	}
}

void registerPassWindow(HINSTANCE hPwInst)
{
	WNDCLASSW pw = { 0 };

	pw.hbrBackground = (HBRUSH)COLOR_WINDOW;
	pw.hCursor = LoadCursor(NULL, IDC_ARROW);
	pw.hInstance = hPwInst;
	pw.lpszClassName = L"passWindow";
	pw.lpfnWndProc = PassWindowProcedure;

	RegisterClassW(&pw);
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{
	case WM_CREATE:
		displayPassWindow(hWnd);
		AddMenus(hWnd);
		AddWindows(hWnd);
		break;
	case WM_COMMAND:
		switch (wp)
		{
		case 1:
			TextSlots(1);
			break;
		case 2:
			TextSlots(2);
			break;
		case 3:
			TextSlots(3);
			break;
		case 4:
			TextSlots(4);
			break;
		case 5:
			TextSlots(5);
			break;
		case 6:
			TextSlots(6);
			break;
		case 7:
			TextSlots(7);
			break;
		case 8:
			TextSlots(8);
			break;
		case 9:
			TextSlots(9);
			break;
		case 11:
			ClearText();
			break;
		case 12:
			Timer();
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProcW(hWnd, msg, wp, lp);
	}
}

int WINAPI WinMain(_In_ HINSTANCE hInst, _In_opt_ HINSTANCE hPrevInst, _In_ LPSTR args, _In_ int nShowCmd)
{
	WNDCLASSW wm = { 0 };
	wm.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wm.hCursor = LoadCursor(NULL, IDC_ARROW);
	wm.hInstance = hInst;
	wm.lpszClassName = L"windowClass";
	wm.lpfnWndProc = WindowProcedure;

	RegisterClassW(&wm);

	registerPassWindow(hInst);

	hMainWindow = CreateWindowW(L"windowClass", L"OneToNine", WS_VISIBLE | WS_DISABLED | WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
		100, 100, 400, 400, NULL, NULL, NULL, NULL);

	MSG msg = { 0 };
	while (GetMessage(&msg, NULL, NULL, NULL))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}