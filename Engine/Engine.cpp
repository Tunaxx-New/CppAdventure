#include "Engine.h"
#include <iostream>


//
// Listener for enter in output window
// @return callback message key
LRESULT CALLBACK WndProcConsoleOutput(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam);
WNDPROC          WndProcConsoleOutputHandle = {};



void Engine::initialize()
{
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi_);
    hConsole_ = GetConsoleWindow();
    WndProcConsoleOutputHandle = (WNDPROC)SetWindowLongPtr(hConsole_, GWLP_WNDPROC, (LONG_PTR)WndProcConsoleOutput);
    SendMessage(hConsole_, WM_CLOSE, 0, 0);
    
    for (int i = 0; i < getRows(); i++) 
    {
        for (int j = 0; j < getColumns(); j++)
        {
            COORD coord;
            coord.X = j;
            coord.Y = i;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            std::cout << 1;
        }
    }
}



HWND Engine::getHConsole()
{
    return hConsole_;
}



int Engine::getRows()
{
    return csbi_.srWindow.Bottom - csbi_.srWindow.Top + 1;
}



int Engine::getColumns()
{
    return csbi_.srWindow.Right - csbi_.srWindow.Left + 1;
}



LRESULT CALLBACK WndProcConsoleOutput(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    std::cout << 1;
	switch (msg)
	{
	case WM_KEYDOWN:
		break;

	default:
		return CallWindowProc(WndProcConsoleOutputHandle, hwnd, msg, wparam, lparam);
	}
	return 0;
}