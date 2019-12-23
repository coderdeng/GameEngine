/*************************************************************************
	> File Name: helloengine_win.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2018/3/26 18:14:18
 ************************************************************************/
#include <windows.h>
#include <windowsx.h>
#include <tchar.h>
#include <GL/gl.h>
#include <fstream>
#include "math.h"


using namespace std;


/////////////
// DEFINES //
/////////////

#define WGL_DRAW_TO_WINDOW_ARB				0x2001
#define WGL_ACCELERATION_ARB				0x2003
#define WGL_SWAP_METHOD_ARB 				0x2007
#define WGL_SUPPORT_OPENGL_ARB				0x2010
#define WGL_DOUBLE_BUFFER_ARB				0x2011
#define WGL_PIXEL_TYPE_ARB				0x2013
#define WGL_COLOR_BITS_ARB				0x2014
#define WGL_DEPTH_BITS_ARB				0x2022
#define WGL_STENCIL_BITS_ARB				0x2023
#define WGL_FULL_ACCELERATION_ARB			0x2027
#define WGL_SWAP_EXCHANGE_ARB				0x2028
#define WGL_TYPE_RGBA_ARB				0x202B
#define WGL_CONTEXT_MAJOR_VERSION_ARB			0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB			0x2092
#define WGL_ARRAY_BUFFER				0x8892
#define WGL_STATIC_DRAW					0x88E4
#define WGL_FRAGMENT_SHADER				0x8B30
#define WGL_VERTEX_SHADER				0x8B31
#define WGL_COMPILE_STATUS				0x8B81
#define WGL_LINK_STATUS					0x8B82
#define WGL_INFO_LOG_LENGTH				0x8B84
#define WGL_TEXTURE0					0x84C0
#define WGL_BGRA					0x80E1
#define WGL_ELEMENT_ARRAY_BUFFER			0x8893

//////////////
// TYPEDEFS //
//////////////

LRESULT CALLBACK WindowProc(HWND hWnd,
							UINT message,
							WPARAM wParam,
							LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance,
				   HINSTANCE hPrevInstance,
				   LPTSTR lpCmdLine,
				   int nCmdShow)
{
	HWND hWnd;
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpszClassName = _T("WindowClass1");

	RegisterClassEx(&wc);

	hWnd = CreateWindowEx(0,
						  _T("WindowClass1"),
						  _T("Hello, Engine!"),
						  WS_OVERLAPPEDWINDOW,
						  300,
						  300,
						  500,
						  400,
						  NULL,
						  NULL,
						  hInstance,
						  NULL);

	ShowWindow(hWnd, nCmdShow);

	MSG msg;

	while(GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
		case WM_DESTROY:
			{
				PostQuitMessage(0);
				return 0;
			}break;
		case WM_PAINT:
			{
				PAINTSTRUCT ps;
				HDC hdc = BeginPaint(hWnd, &ps);
				RECT rec = {20, 20, 60, 80};
				HBRUSH brush = (HBRUSH)GetStockObject(BLACK_BRUSH);

				FillRect(hdc, &rec, brush);
				EndPaint(hWnd, &ps);
			}break;
	}
	
	return DefWindowProc(hWnd, message, wParam, lParam);
}

