#include <windows.h>

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}
// This function checks if any of the 4 cursor keys are pressed. 
// If any cursor key is pressed, then the function returns true, and whichKey identifies which of the 4 cursor keys is pressed.
// whichkey is assigned following values if any cursor key is pressed. 1 for left, 2 for up, 3 for right and 4 for left.
bool isCursorKeyPressed(int& whickKey)   //whichKey passed as reference.... 
{
	char key;
	key = GetAsyncKeyState(37);
	if (key == 1)
	{
		whickKey = 1;		// 1 if left key is pressed 
		return true;
	}
	key = GetAsyncKeyState(38);
	if (key == 1)
	{
		whickKey = 2;		// 2 if up key is pressed
		return true;
	}

	key = GetAsyncKeyState(39);
	if (key == 1)
	{
		whickKey = 3; // 3 if right key is pressed
		return true;
	}
	key = GetAsyncKeyState(40);
	if (key == 1)
	{
		whickKey = 4;   // 4 if down key is pressed
		return true;
	}
	key = GetAsyncKeyState(13);
	if (key == 1)
	{
		whickKey = 13;   // if enter is pressed
		return true;
	}
	return false;
}
void myLine(int x1, int y1, int x2, int y2, int R, int B, int G) //use three 3 integers if you want colored lines.
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, B, G)); //2 is the width of the pen
	SelectObject(device_context, pen);
	MoveToEx(device_context, x1, y1, NULL);
	LineTo(device_context, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
}
void myRect(int x1, int y1, int x2, int y2, int R, int G, int B, int FR, int FG, int FB)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(FR, FG, FB)); //Fill color is passed as parameter to the function!!!

	SelectObject(device_context, brush);

	Rectangle(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}
void myEllipse(int x1, int y1, int x2, int y2, int R, int G, int B, int FR, int FG, int FB)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(FR, FG, FB));  //Fill color is black
	SelectObject(device_context, brush);
	Ellipse(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}
void mycircle(int row, int coloumn, int R, int G, int B, int FR, int FG, int FB)
{

	int x = (coloumn / 2 - 1) * 16 + 23;
	int y = row * 36 + 62;
	myEllipse(x, y, x + 26, y + 20, R, G, B, FR, FG, FB);
}
void mytriangle(int row, int coloumn, int R, int G, int B, int FR, int FG, int FB)
{
	int x = (coloumn / 2 - 1) * 16 + 23;
	int y = row * 36 + 62;

	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);
	MoveToEx(device_context, x + 12, y, NULL);
	LineTo(device_context, x, y + 19);
	LineTo(device_context, x + 24, y + 19);
	LineTo(device_context, x + 12, y);


	HBRUSH brush = ::CreateSolidBrush(RGB(FR, FG, FB));  //Fill color is black
	SelectObject(device_context, brush);
	FloodFill(device_context, x + 12, y + 9, RGB(R, G, B));
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
	/*myLine(x + 12, y, x, y + 19, r, g, b);
	myLine(x, y + 19, x + 24, y + 19, r, g, b);
	myLine(x + 24, y + 19, x + 12, y, r, g, b);
	*/
}
void mysquare(int row, int coloumn, int R, int G, int B, int FR, int FG, int FB)
{
	int x = (coloumn / 2 - 1) * 16 + 23;
	int y = row * 36 + 62;

	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);
	MoveToEx(device_context, x + 12, y, NULL);
	LineTo(device_context, x, y + 9);
	LineTo(device_context, x + 12, y + 19);
	LineTo(device_context, x + 24, y + 9);
	LineTo(device_context, x + 12, y);

	HBRUSH brush = ::CreateSolidBrush(RGB(FR, FG, FB));  //Fill color is black
	SelectObject(device_context, brush);
	FloodFill(device_context, x + 12, y + 9, RGB(R, G, B));
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);


	/*myLine(x + 12, y, x, y + 9, R, G, B);
	myLine(x, y + 9, x + 12, y + 19, R, G, B);
	myLine(x + 12, y + 19, x + 24, y + 9, R, G, B);
	myLine(x + 24, y + 9, x + 12, y, R, G, B);*/
}
void mydiamond(int row, int coloumn, int R, int G, int B, int FR, int FG, int FB)
{
	int x = (coloumn / 2 - 1) * 16 + 23;
	int y = row * 36 + 62;

	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);
	MoveToEx(device_context, x + 2, y, NULL);
	LineTo(device_context, x + 22, y);
	LineTo(device_context, x + 24, y + 8);
	LineTo(device_context, x + 12, y + 19);
	LineTo(device_context, x, y + 8);
	LineTo(device_context, x + 2, y);


	HBRUSH brush = ::CreateSolidBrush(RGB(FR, FG, FB));  //Fill color is black
	SelectObject(device_context, brush);
	FloodFill(device_context, x + 12, y + 9, RGB(R, G, B));
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);

	/*myLine(x + 2, y, x + 22, y, r, g, b);
	myLine(x + 22, y, x + 24, y + 8, r, g, b);
	myLine(x + 24, y + 8, x + 12, y + 19, r, g, b);
	myLine(x + 12, y + 19, x, y + 8, r, g, b);
	myLine(x, y + 8, x + 2, y, r, g, b);*/
}
void mypolygon(int row, int coloumn, int R, int G, int B, int FR, int FG, int FB)
{
	int x = (coloumn / 2 - 1) * 16 + 23;
	int y = row * 36 + 62;

	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);
	MoveToEx(device_context, x + 8, y, NULL);
	LineTo(device_context, x + 16, y);
	LineTo(device_context, x + 24, y + 12);
	LineTo(device_context, x + 16, y + 19);
	LineTo(device_context, x + 8, y + 19);
	LineTo(device_context, x, y + 12);
	LineTo(device_context, x, y + 6);
	LineTo(device_context, x + 8, y);


	HBRUSH brush = ::CreateSolidBrush(RGB(FR, FG, FB));  //Fill color is black
	SelectObject(device_context, brush);
	FloodFill(device_context, x + 12, y + 9, RGB(R, G, B));
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);

	/*myLine(x + 8, y, x + 16, y, r, g, b);
	myLine(x + 16, y, x + 24, y + 6, r, g, b);
	myLine(x + 24, y + 6, x + 24, y + 12, r, g, b);
	myLine(x + 24, y + 12, x + 16, y + 19, r, g, b);
	myLine(x + 16, y + 19, x + 8, y + 19, r, g, b);
	myLine(x + 8, y + 19, x, y + 12, r, g, b);
	myLine(x, y + 12, x, y + 6, r, g, b);
	myLine(x, y + 6, x + 8, y, r, g, b);*/
}
void mycube(int row, int coloumn, int R, int G, int B, int FR, int FG, int FB)
{
	int x = (coloumn / 2 - 1) * 16 + 23;
	int y = row * 36 + 62;

	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);
	MoveToEx(device_context, x + 6, y, NULL);
	LineTo(device_context, x + 24, y);
	LineTo(device_context, x + 24, y + 15);
	LineTo(device_context, x + 18, y + 19);
	LineTo(device_context, x, y + 19);
	LineTo(device_context, x, y + 4);
	LineTo(device_context, x + 24, y);
	LineTo(device_context, x + 18, y + 4);
	LineTo(device_context, x + 18, y + 19);
	LineTo(device_context, x + 18, y + 4);
	LineTo(device_context, x, y + 4);



	HBRUSH brush = ::CreateSolidBrush(RGB(FR, FG, FB));  //Fill color is black
	SelectObject(device_context, brush);
	FloodFill(device_context, x + 12, y + 9, RGB(R, G, B));
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);

	/*myLine(x + 6, y, x + 24, y, 255, 255, 255);
	myLine(x + 24, y, x + 24, y + 15, 255, 255, 255);
	myLine(x + 24, y + 15, x + 18, y + 19, 255, 255, 255);
	myLine(x + 18, y + 19, x, y + 19, 255, 255, 255);
	myLine(x, y + 19, x, y + 4, 255, 255, 255);
	myLine(x, y + 4, x + 6, y, 255, 255, 255);
	myLine(x + 24, y, x + 18, y + 4, 255, 255, 255);
	myLine(x + 18, y + 4, x + 18, y + 19, 255, 255, 255);
	myLine(x + 18, y + 4, x, y + 4, 255, 255, 255);*/
}
