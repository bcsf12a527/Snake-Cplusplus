#include<windows.h>

void setCursor(int x,int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

char readFrom(int x, int y)
{
	char* str = new char;
	DWORD nLength = 1;
	COORD readCoord;
	readCoord.X = x; readCoord.Y = y;
	DWORD num_read=0;
	ReadConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), (LPTSTR)str, nLength, readCoord,(LPDWORD)&num_read);
	return *str;
}

void getCursor(int& x, int& y)
{ 
	CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;
	GetConsoleScreenBufferInfo (GetStdHandle(STD_OUTPUT_HANDLE) , &screenBufferInfo) ;
	x = screenBufferInfo.dwCursorPosition.X; 
	y = screenBufferInfo.dwCursorPosition.Y;
}