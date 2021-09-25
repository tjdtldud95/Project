#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif


#include <iostream>
#include <conio.h> // console io
#include <cstring> // string.h
#include <cstdlib> // stdlib.h
#include <string> // c++ string class
#include <Windows.h>
#include "Utils.h"

static HANDLE hStdin;
static DWORD fdwSaveOldMode;

class Screen;
class Mine;
class MineManager;

class Screen {
private:
	int		width; // visible width
	int		height;
	int		size;
	char* canvas;

public:

	// constructor (������ �Լ�) �޸𸮰����� ����Ǵ� ���� ȣ��Ǵ�
	Screen(int width = 10, int height = 10)
		: width(width), height(height), canvas(new char[(width + 1) * height])
	{
		bool faultyInput = false;
		if (this->width <= 0) {
			this->width = 10;
			faultyInput = true;
		}
		if (this->height <= 0) {
			this->height = 10;
			faultyInput = true;
		}
		size = (this->width + 1) * this->height;
		if (faultyInput == true) {
			delete canvas;
			canvas = new char[size];
		}
	}
	// destructor (�Ҹ��� �Լ�) �޸𸮰����󿡼� �������� ���� ȣ��Ǵ� �Լ�
	~Screen()
	{
		delete[] canvas;
		canvas = nullptr;
		width = 0; height = 0;
	}

	int get_NumEmptyCanvas()
	{
		int num=0;

		for (int i = 0;i < size;i++)
		{
			if (canvas[i] == 127)
				num++;
		}

		return num;
	}

	int getWidth()
	{
		return width;
	}
	int getHeigt()
	{
		return height;
	}

	void clear()
	{
		memset(canvas, 127, size);
	}
	 
	void render()
	{
		Borland::gotoxy(0, 0);
		for (int h = 0; h < height; h++)
			canvas[(width + 1) * (h + 1) - 1] = '\n';
		canvas[size - 1] = '\0';
		printf("%s", canvas);
	}

	void draw(int x,int y ,MineManager* mines);
	void draw(MineManager* mines);
};

class Mine
{
private:
	Position pos;
public:
	Mine()
	{
		srand(time(nullptr));			
	}

	void Set_Pos_XY(int Screen_wid, int Screen_hei)
	{
		pos.x = rand() % Screen_wid;
		pos.y = rand() % Screen_hei;
	}

	int Get_PosX()
	{
		return pos.x;
	}
	int Get_PosY()
	{
		return pos.y;
	}
};

class MineManager //mines num_size check // pos_x,y check 
{
private :
	Mine* mines;
	int minesNumSize;
public :
	MineManager(int minesNumSize) :minesNumSize(minesNumSize)
	{
		mines = (new Mine[minesNumSize]);
	}

	void SetMinesPos(Screen* screen)
	{
		for (int i = 0;i < minesNumSize;i++)
		{
			mines[i].Set_Pos_XY(screen->getWidth(), screen->getHeigt());

			//same position block 
			for (int j = 0;j < i;j++)
			{
				if ( i != j && mines[i].Get_PosX() == mines[j].Get_PosX() && mines[i].Get_PosY() == mines[j].Get_PosY())
				{
					i--;
					break;
				}
			}
		}
	}

	//Ŭ���ϸ� false �ƴϸ� true --> islooping ���붧��
	bool Check_Click_Mine(int pos_X,int pos_Y)
	{
		for (int i = 0;i < minesNumSize;i++)
		{
			if (mines[i].Get_PosX()== pos_X && mines[i].Get_PosY() == pos_Y)
			{
				return false;
			}
		}
		return true;
	}

	// ����ó���� ��� �ұ�.... return ����.... -->���ʿ� �޼��尡 �߸��ƴ�?
	Mine GetMIne(int arrNum)
	{
		return mines[arrNum];
	}

	int GetminesNumSize()
	{
		return minesNumSize;
	}

	~MineManager()
	{
		delete[] mines;
		mines = nullptr;
		minesNumSize = 0;
	}
};

void Screen::draw(int x,int y,MineManager* mines)
{
	//48 = 0
	char num = 48;
	
	for (int i = -1;i < 2;i++)
	{
		for (int j = -1;j < 2;j++)
		{
			if (i == 0 && j == 0) continue;
			if (x + i<0 || x + i >height) continue;
			if (y + j<0 || y + j >width) continue;

			if (mines->Check_Click_Mine(x + i, y + j) == false)
				num++;
		}
	}

	canvas[(width + 1) * x + y] = num;
}
//if player finish games and then show map
void Screen :: draw (MineManager* mines)
{
	for (int i = 0;i < mines->GetminesNumSize();i++)
	{
		int x = mines->GetMIne(i).Get_PosX();
		int y = mines->GetMIne(i).Get_PosY();
		canvas[(width+1)*x + y] = '*';
	}
}


static char blankChars[80];
static void ErrorExit(const char*);
static Position MouseEventProc(MOUSE_EVENT_RECORD);

int main()
{
	srand(time(nullptr));
	bool winGame = false;
	Screen  screen(10, 10);
	MineManager mines(rand()%10 +10);
	Position Mouse_Click_pos;
	mines.SetMinesPos(&screen);

	//mouse input 
	//===========================================================
	DWORD cNumRead, fdwMode, i;
	INPUT_RECORD irInBuf[128];
	int counter = 0;

	memset(blankChars, ' ', 80);
	blankChars[79] = '\0';
	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	if (hStdin == INVALID_HANDLE_VALUE)
		ErrorExit("GetStdHandle");
	if (!GetConsoleMode(hStdin, &fdwSaveOldMode))
		ErrorExit("GetConsoleMode");

	fdwMode = ENABLE_EXTENDED_FLAGS;
	if (!SetConsoleMode(hStdin, fdwMode))
		ErrorExit("SetConsoleMode");

	fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(hStdin, fdwMode))
		ErrorExit("SetConsoleMode");
	//===========================================================

	bool isLooping = true;
	screen.clear();
	while (isLooping) 
	{
		if (GetNumberOfConsoleInputEvents(hStdin, &cNumRead))
		{
			if (cNumRead > 0) 
			{
				if (!ReadConsoleInput(
					hStdin,      // input buffer handle
					irInBuf,     // buffer to read into
					128,         // size of read buffer
					&cNumRead)) // number of records read
					ErrorExit("ReadConsoleInput");

				// Dispatch the events to the appropriate handler.

				for (i = 0; i < cNumRead; i++)
				{
					if (irInBuf[i].EventType == MOUSE_EVENT)
					{
						Mouse_Click_pos = MouseEventProc(irInBuf[i].Event.MouseEvent);
					}
				}
			}
		}

		screen.render();

		//Clicked Mouse Left_button
		if(Mouse_Click_pos.x >= 0)
		{
			isLooping = mines.Check_Click_Mine(Mouse_Click_pos.y, Mouse_Click_pos.x);
			screen.draw(Mouse_Click_pos.y, Mouse_Click_pos.x, &mines);
		}

		//Click Mine
		if (!isLooping)
		{ 
			break;
		}

		//Finish Game
		if (screen.get_NumEmptyCanvas() == mines.GetminesNumSize())
		{
			winGame = true;
			break;
		}
		
		Sleep(100);
	}

	screen.draw(&mines);
	screen.render();

	if (winGame)
	{
		printf("\nGame Win\n");
	}
	else
	{
		printf("\nGame Over\n");
	}

	return 0;
}

void ErrorExit(const char* lpszMessage)
{
	fprintf(stderr, "%s\n", lpszMessage);

	// Restore input mode on exit.

	SetConsoleMode(hStdin, fdwSaveOldMode);

	ExitProcess(0);
}

static Position MouseEventProc(MOUSE_EVENT_RECORD mer)
{
	Borland::gotoxy(0, 12);
	Position pos;
	printf("%s\r", blankChars);
#ifndef MOUSE_HWHEELED
#define MOUSE_HWHEELED 0x0008
#endif
	printf("Mouse event: ");

	switch (mer.dwEventFlags)
	{
	case 0:
		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			printf("left button press %d %d\n", mer.dwMousePosition.X, mer.dwMousePosition.Y);
			pos.x = mer.dwMousePosition.X;
			pos.y = mer.dwMousePosition.Y;
		}
		else if (mer.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
		{
			printf("right button press \n");
			pos.x = -1 * mer.dwMousePosition.X;
			pos.y = -1 * mer.dwMousePosition.Y;
		}
		break;
	}

	Borland::gotoxy(0, 0);
	return pos;
}
