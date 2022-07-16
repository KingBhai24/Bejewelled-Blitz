#include <iostream>
#include <conio.h>
#include <ctime>
#include <fstream>
#include "header.h"
using namespace std;
void initialvaluesofboard(char arr[][33], char arr2[][33], int r)   //initializing board
{
	for (int i = 0; i < r; i++)                  //loop for controlling rows
		for (int j = 0; j <= 28; j = j + 4)      //loop for controlling coloumns
		{
			arr[i][j] = '|';
			arr[i][j + 1] = ' ';
			arr[i][j + 2] = ' ';
			arr[i][j + 3] = ' ';
		}
	for (int i = 0; i < r; i = i++)
		arr[i][32] = '|';
	for (int i = 0; i < r; i++)                  //loop for controlling rows
		for (int j = 0; j <= 28; j = j + 4)      //loop for controlling coloumns
		{
			arr2[i][j] = '|';
			arr2[i][j + 1] = ' ';
			arr2[i][j + 2] = ' ';
			arr2[i][j + 3] = ' ';
		}
	for (int i = 0; i < r; i = i++)
		arr2[i][32] = '|';
}
void gemgenerator(char arr[][33], int r)   //generates random gems
{
	srand((int)time(0));
	for (int i = 0; i < r; i++)                   //loop for controlling rows
		for (int j = 2; j <= 30; j = j + 4)       //loop for controlling coloumns
			arr[i][j] = rand() % 5 + 49;        //generating random elements on the indexes
}
void printboard(char arr[][33], char arr2[][33], int score, int time)   //prints updated board  add timer
{
	cout << endl << "         Welcome to JeWel WorlD\n" << endl << "        Time:" << time << endl << endl;
	for (int i = 0; i <= 7; i++)                //loop for controlling rows
	{
		cout << "  ";
		for (int j = 0; j <= 32; j++)  //loop for controlling coloumns
			cout << arr2[i][j];
		cout << endl;
		cout << "  ";
		for (int j = 0; j <= 32; j++)           //loop for controlling coloumns
		{
			if (arr[i][j] >= 49 && arr[i][j] <= 80)
				cout << " ";
			else
				cout << arr[i][j];                //printing array
			if (i == 2 && j == 32)
				cout << "     S = save game";
			if (i == 3 && j == 32)
				cout << "     L = load game";
			if (i == 4 && j == 32)
				cout << "     Q = Quit Game";
		}
		cout << endl << endl;
	}
	cout << endl << endl;
	cout << "    Score :" << score << endl << endl;   //prints score
}
void shapegenerator(char arr[][33])         //generates graphical shapes
{
	for (int row = 0; row < 8; row++)
		for (int coloumn = 2; coloumn <= 30; coloumn = coloumn + 4)
		{
			if (arr[row][coloumn] == 49)
				mycircle(row, coloumn, 241, 196, 15, 241, 196, 15); //function call;draws circle
			else if (arr[row][coloumn] == 50)
				mytriangle(row, coloumn, 123, 36, 28, 123, 36, 28);   //function call;draws triangle
			else if (arr[row][coloumn] == 51)
				mysquare(row, coloumn, 91, 44, 111, 91, 44, 111);    //function call;draws square
			else if (arr[row][coloumn] == 52)
				mydiamond(row, coloumn, 31, 97, 141, 31, 97, 141);  //function call;draws diamond
			else if (arr[row][coloumn] == 53)
				mypolygon(row, coloumn, 0, 100, 0, 0, 100, 0);     //function call;draws polygon

			else if (arr[row][coloumn] == 54)
				mycircle(row, coloumn, 255, 0, 0, 241, 196, 15);       //function call;draws circle
			else if (arr[row][coloumn] == 55)
				mytriangle(row, coloumn, 255, 0, 0, 123, 36, 28);        //function call;draws triangle
			else if (arr[row][coloumn] == 56)
				mysquare(row, coloumn, 255, 0, 0, 50, 100, 200);         //function call;draws square
			else if (arr[row][coloumn] == 57)
				mydiamond(row, coloumn, 255, 0, 0, 31, 97, 141);           //function call;draws diamond
			else if (arr[row][coloumn] == 58)
				mypolygon(row, coloumn, 255, 0, 0, 0, 100, 0);            //function call;draws polygon

			else if (arr[row][coloumn] == 59)
				mycircle(row, coloumn, 0, 255, 0, 241, 196, 15);      //function call;draws circle
			else if (arr[row][coloumn] == 60)
				mytriangle(row, coloumn, 0, 255, 0, 123, 36, 28);     //function call;draws triangle
			else if (arr[row][coloumn] == 61)
				mysquare(row, coloumn, 0, 255, 0, 50, 100, 200);       //function call;draws square
			else if (arr[row][coloumn] == 62)
				mydiamond(row, coloumn, 0, 255, 0, 31, 97, 141);      //function call;draws diamond
			else if (arr[row][coloumn] == 63)
				mypolygon(row, coloumn, 0, 255, 0, 0, 100, 0); //function call;draws polygon

			else if (arr[row][coloumn] == 80)
				mycube(row, coloumn, 255, 255, 255, 255, 255, 255);          //function call;draws cube
		}
}
void cursormovement(int input, int& x, int& y)    //function for controlling pointer movement
{
	if (input == 'd' && x > 4)    //left key
		x = x - 4;
	else if (input == 'r' && y > 6)     //up key
		y = y - 3;
	else if (input == 'g' && x <= 28)      //right key
		x = x + 4;
	else if (input == 'f' && y <= 24)     //down key
		y = y + 3;
}
void assignflamevalue(char arr[][33], int i, int j)   //creates flame gem 
{
	if (arr[i][j] == 49)
		arr[i][j] = 54;
	else if (arr[i][j] == 50)
		arr[i][j] = 55;
	else if (arr[i][j] == 51)
		arr[i][j] = 56;
	else if (arr[i][j] == 52)
		arr[i][j] = 57;
	else if (arr[i][j] == 53)
		arr[i][j] = 58;
}
void userinterface(char arr[][33], char arr2[][33], int score, int x, int y, int timer)
{
	system("cls");         //clear screen
	printboard(arr, arr2, score, timer);  //prints updated board
	shapegenerator(arr);           //function call;prints shapes
	gotoxy(x, y);               //funtion call;commands the ointer to a coordiante
	Sleep(250);        //slows down         
}
int checkelbow(char arr[][33], char arr2[][33], int row, int coloumn, int& score, int x, int y, int slideshow, int timer)     //for checking elbow condition and to replace it
{
	srand((int)time(0));
	int firstup = 0, firstdown = 0, lastup = 0, lastdown = 0, flag = 0;      //value initialization
	int a;
	a = row;
	for (int i = 0; i < 2; i++)          //loop for checking consecutive same elements
	{
		if (arr[a][coloumn] == arr[a - 1][coloumn] || arr[a][coloumn] == arr[a - 1][coloumn] + 5 || arr[a][coloumn] == arr[a - 1][coloumn] - 5)   //checking consecutive elements
		{
			firstup++;           //increment for indication
		}
		if (arr[a][coloumn + 8] == arr[a - 1][coloumn + 8] || arr[a][coloumn + 8] == arr[a - 1][coloumn + 8] + 5 || arr[a][coloumn + 8] == arr[a - 1][coloumn + 8] - 5)   //checking consecutive elements
		{
			lastup++;              //increment for indication
		}
		a--;               //decrement
	}
	a = row;     //updating value
	for (int i = 0; i < 2; i++)    //loop for checking consecutive same elements
	{
		if (arr[a][coloumn] == arr[a + 1][coloumn] || arr[a][coloumn] == arr[a + 1][coloumn] + 5 || arr[a][coloumn] == arr[a + 1][coloumn] - 5) //checking consecutive same elements
		{
			firstdown++;             //increment for indication
		}
		if (arr[a][coloumn + 8] == arr[a + 1][coloumn + 8] || arr[a][coloumn + 8] == arr[a + 1][coloumn + 8] + 5 || arr[a][coloumn + 8] == arr[a + 1][coloumn + 8] - 5)//checking consecutive same elements
		{
			lastdown++;         //increment for indication
		}
		a++;              //increment
	}
	a = row;         //updating value
	if (firstup == 2)                    //uses increment to judge the situation
	{
		flag = 1;                        //indication
		score = score + 5;
		arr[a][coloumn] = arr[a][coloumn] + 10;            //updating value
		arr[a - 1][coloumn] = ' ';       //updating value
		arr[a - 2][coloumn] = ' ';       //updating value
		arr[a][coloumn + 4] = ' ';      //updating value
		arr[a][coloumn + 8] = ' ';      //updating value
		if (slideshow == 1)
			userinterface(arr, arr2, score, x, y, timer);   //function call;slows down and shows process
		for (a; a >= 3; a--)                                      //loop for vertical line swaping
		{
			swap(arr[a - 1][coloumn], arr[a - 3][coloumn]);      //vertical line swaping
			if (slideshow == 1)
				userinterface(arr, arr2, score, x, y, timer);   //function call;slows down and shows process
		}
		for (int i = 1; i >= 0; i--)                  //loop for filling random numbers in leftovers
		{
			arr[i][coloumn] = rand() % 5 + 49;         //filling random numbers in leftovers
			if (slideshow == 1)
				userinterface(arr, arr2, score, x, y, timer);   //function call;slows down and shows process
		}
		for (int i = 4; i <= 8; i = i + 4)                          //loop for horizontal line movement
		{
			a = row;                                        //updating value
			for (a; a >= 1; a--)                                       //loop for vertical line swaping
			{
				swap(arr[a][coloumn + i], arr[a - 1][coloumn + i]);  //vertical line swaping
				if (slideshow == 1)
					userinterface(arr, arr2, score, x, y, timer);   //function call;slows down and shows process
			}
			arr[a][coloumn + i] = rand() % 5 + 49;                   //filling random values in leftovers
			if (slideshow == 1)
				userinterface(arr, arr2, score, x, y, timer);   //function call;slows down and shows process
		}
	}
	else if (lastup == 2)             //uses increment to judge the situation
	{
		flag = 1;                       //indication
		score = score + 5;           //increment
		a = row;                  //updating value
		arr[a][coloumn + 8] = arr[a][coloumn + 8] + 10;     //updating value
		arr[a - 1][coloumn + 8] = ' '; //updating value
		arr[a - 2][coloumn + 8] = ' ';   //updating value
		arr[a][coloumn + 4] = ' ';   //updating value
		arr[a][coloumn] = ' ';  //updating value
		if (slideshow == 1)
			userinterface(arr, arr2, score, x, y, timer);   //function call;slows down and shows process
		for (a; a >= 3; a--)                                           //loop for vertical line swaping
		{
			swap(arr[a - 1][coloumn + 8], arr[a - 3][coloumn + 8]); //vertical line swaping
			if (slideshow == 1)
				userinterface(arr, arr2, score, x, y, timer);   //function call;slows down and shows process
		}
		for (int i = 1; i >= 0; i--)                                      //loop for filling random numbers in leftovers
		{
			arr[i][coloumn + 8] = rand() % 5 + 49;          //filling random numbers in leftovers
			if (slideshow == 1)
				userinterface(arr, arr2, score, x, y, timer);   //function call;slows down and shows process
		}
		for (int i = 4; i >= 0; i = i - 4)       //loop for horizontal line movement
		{
			a = row;                          //updating value
			for (a; a >= 1; a--)                //loop for vertical line swaping
			{
				swap(arr[a][coloumn + i], arr[a - 1][coloumn + i]);   //vertical line swaping
				if (slideshow == 1)
					userinterface(arr, arr2, score, x, y, timer);   //function call;slows down and shows process
			}
			arr[a][coloumn + i] = rand() % 5 + 49;                      //filing random number in leftovers
			if (slideshow == 1)
				userinterface(arr, arr2, score, x, y, timer);   //function call;slows down and shows process
		}
	}
	else if (firstdown == 2) //uses increment to jude the situation
	{
		flag = 1;             //indication
		score = score + 5;     //increment in score
		a = row;               //updating value
		arr[a][coloumn] = arr[a][coloumn] + 10;    //updating value
		arr[a + 1][coloumn] = ' '; //updating value
		arr[a + 2][coloumn] = ' ';  //updating value
		arr[a][coloumn + 4] = ' ';   //updating value
		arr[a][coloumn + 8] = ' ';  //updating value
		if (slideshow == 1)
			userinterface(arr, arr2, score, x, y, timer);   //function call;slows down and shows process
		for (a; a >= 0; a--)                                         //loop for vertical line swaping
		{
			swap(arr[a + 2][coloumn], arr[a][coloumn]);             //vertical line swaping
			if (slideshow == 1)
				userinterface(arr, arr2, score, x, y, timer);   //function call;slows down and shows process
		}
		for (int i = 1; i >= 0; i--)                                         //loop for filling random values in leftovers
		{
			arr[i][coloumn] = rand() % 5 + 49;                           //filling random values in leftovers
			if (slideshow == 1)
				userinterface(arr, arr2, score, x, y, timer);   //function call;slows down and shows process
		}
		for (int i = 4; i <= 8; i = i + 4)                                           //loop for horizontal line movement
		{
			a = row;                             //updating value
			for (a; a >= 1; a--)                                           //loop for vertical line swaping
			{
				swap(arr[a][coloumn + i], arr[a - 1][coloumn + i]);       //vertical line swaping
				if (slideshow == 1)
					userinterface(arr, arr2, score, x, y, timer);   //function call;slows down and shows process
			}
			arr[a][coloumn + i] = rand() % 5 + 49;                        //filing random numbers
			if (slideshow == 1)
				userinterface(arr, arr2, score, x, y, timer);   //function call;slows down and shows process
		}
	}
	else if (lastdown == 2)      //uses increment to judge the situation
	{
		flag = 1;        //indication
		score = score + 5; //increment in score
		a = row;      //updating value
		arr[a][coloumn + 8] = arr[a][coloumn + 8] + 10;  //updating value
		arr[a + 1][coloumn + 8] = ' ';  //updating value
		arr[a + 2][coloumn + 8] = ' ';  //updating value
		arr[a][coloumn + 4] = ' ';   //updating value
		arr[a][coloumn] = ' ';  //updating value
		if (slideshow == 1)
			userinterface(arr, arr2, score, x, y, timer);   //function call;slows down and shows process
		for (a; a >= 0; a--)                                                   //loop for vertical line swaping
		{
			swap(arr[a + 2][coloumn + 8], arr[a][coloumn + 8]);              //vertical line swaping
			if (slideshow == 1)
				userinterface(arr, arr2, score, x, y, timer);   //function call;slows down and shows process
		}
		for (int i = 1; i >= 0; i--)                                         //loop for filling random values in leftovers
		{
			arr[i][coloumn + 8] = rand() % 5 + 49;                           //filling random values in leftovers
			if (slideshow == 1)
				userinterface(arr, arr2, score, x, y, timer);   //function call;slows down and shows process
		}
		for (int i = 4; i >= 0; i = i - 4)                                           //loop for horizontal movement
		{
			a = row;                                          //updating value
			for (a; a >= 1; a--)                                           //loop for vertical line swaping
			{
				swap(arr[a][coloumn + i], arr[a - 1][coloumn + i]);         //vertical line swaping
				if (slideshow == 1)
					userinterface(arr, arr2, score, x, y, timer);   //function call;slows down and shows process
			}
			arr[a][coloumn + i] = rand() % 5 + 49;                        //filing random numbers
			if (slideshow == 1)
				userinterface(arr, arr2, score, x, y, timer);   //function call;slows down and shows process
		}
	}
	return flag;                                                      //returns 0 or 1
}
int checkforflamegeminrow(char arr[][33], char arr2[][33], int row, int coloumn, int x, int y, int& score, int slideshow, int timer)
{
	srand((int)time(0));
	int i, flag;
	flag = 0;
	if (arr[row][coloumn] >= 54 && arr[row][coloumn] <= 58)
	{
		flag = 1;
		arr[row][coloumn - 4] = ' ';
		arr[row][coloumn] = ' ';
		arr[row][coloumn + 4] = ' ';
		arr[row][coloumn + 8] = ' ';
		arr[row - 1][coloumn - 4] = ' ';
		arr[row - 1][coloumn] = ' ';
		arr[row - 1][coloumn + 4] = ' ';
		arr[row + 1][coloumn - 4] = ' ';
		arr[row + 1][coloumn] = ' ';
		arr[row + 1][coloumn + 4] = ' ';
		userinterface(arr, arr2, score, x, y, timer);
		for (int j = -4; j <= 4; j = j + 4)
		{
			i = row;
			for (i; i >= 2; i--)
			{
				swap(arr[i + 1][coloumn + j], arr[i - 2][coloumn + j]);
				if (slideshow == 1)
					userinterface(arr, arr2, score, x, y, timer);
			}
			for (int k = 2; k >= 0; k--)
			{
				arr[k][coloumn + j] = rand() % 5 + 49;
				if (slideshow == 1)
					userinterface(arr, arr2, score, x, y, timer);
			}
		}
		i = row;
		for (i; i >= 1; i--)
		{
			swap(arr[i][coloumn + 8], arr[i - 1][coloumn + 8]);
			if (slideshow == 1)
				userinterface(arr, arr2, score, x, y, timer);
		}
		arr[i][coloumn + 8] = rand() % 5 + 49;
		if (slideshow == 1)
			userinterface(arr, arr2, score, x, y, timer);

		score = score + 10;
	}
	else if (arr[row][coloumn + 4] >= 54 && arr[row][coloumn + 4] <= 58)
	{
		flag = 1;
		arr[row][coloumn - 4] = ' ';
		arr[row][coloumn] = ' ';
		arr[row][coloumn + 4] = ' ';
		arr[row - 1][coloumn - 4] = ' ';
		arr[row - 1][coloumn] = ' ';
		arr[row - 1][coloumn + 4] = ' ';
		arr[row + 1][coloumn - 4] = ' ';
		arr[row + 1][coloumn] = ' ';
		arr[row + 1][coloumn + 4] = ' ';
		userinterface(arr, arr2, score, x, y, timer);
		for (int j = 0; j <= 8; j = j + 4)
		{
			i = row;
			for (i; i >= 2; i--)
			{
				swap(arr[i + 1][coloumn + j], arr[i - 2][coloumn + j]);
				if (slideshow == 1)
					userinterface(arr, arr2, score, x, y, timer);
			}
			for (int k = 2; k >= 0; k--)
			{
				arr[k][coloumn + j] = rand() % 5 + 49;
				if (slideshow == 1)
					userinterface(arr, arr2, score, x, y, timer);
			}
		}
		score = score + 10;
	}
	else if (arr[row][coloumn + 8] >= 54 && arr[row][coloumn + 8] <= 58)
	{
		flag = 1;
		arr[row][coloumn] = ' ';
		arr[row][coloumn + 4] = ' ';
		arr[row][coloumn + 8] = ' ';
		arr[row][coloumn + 12] = ' ';
		arr[row - 1][coloumn + 4] = ' ';
		arr[row - 1][coloumn + 8] = ' ';
		arr[row - 1][coloumn + 12] = ' ';
		arr[row + 1][coloumn + 4] = ' ';
		arr[row + 1][coloumn + 8] = ' ';
		arr[row + 1][coloumn + 12] = ' ';
		i = row;
		for (i; i >= 1; i--)
		{
			swap(arr[i + 1][coloumn], arr[i - 1][coloumn]);
			if (slideshow == 1)
				userinterface(arr, arr2, score, x, y, timer);
		}
		arr[0][coloumn] = rand() % 5 + 49;
		if (slideshow == 1)
			userinterface(arr, arr2, score, x, y, timer);
		for (int j = 4; j <= 12; j = j + 4)
		{
			i = row;
			for (i; i >= 2; i++)
			{
				swap(arr[i + 1][coloumn + j], arr[i - 2][coloumn + j]);
				if (slideshow == 1)
					userinterface(arr, arr2, score, x, y, timer);
			}
			for (int k = 2; k >= 0; k--)
			{
				arr[k][coloumn + j] = rand() % 5 + 49;
				if (slideshow == 1)
					userinterface(arr, arr2, score, x, y, timer);
			}
		}
	}
	return flag;
}
void checkflamegemincoloumn(char arr[][33], char arr2[][33], int row, int coloumn, int& score, int x, int y, int slideshow, int timer)
{
	srand((int)time(0));
	int i, flag;
	flag = 0;
	if (arr[row][coloumn] >= 54 && arr[row][coloumn] <= 58)
	{
		arr[row][coloumn] = ' ';
		arr[row - 1][coloumn] = ' ';
		arr[row - 1][coloumn - 2] = ' ';
		arr[row - 1][coloumn + 2] = ' ';
		arr[row][coloumn - 2] = ' ';
		arr[row][coloumn + 2] = ' ';
		arr[row + 1][coloumn] = ' ';
		arr[row + 1][coloumn - 2] = ' ';
		arr[row + 1][coloumn + 2] = ' ';
		arr[row][coloumn + 4] = ' ';



	}
}
int checkcoloumn(char arr[][33], char arr2[][33], int& score, int x, int y, int slideshow, int timer)  //function for checking conseccutive same elements in a coloumn and to replace them
{
	int a, flag;                         //declaration
	flag = 0;                          //initialization
	srand((int)time(0));
	for (int j = 2; j <= 30; j = j + 4)       //loop for vertical checking
		for (int i = 0; i < 8; i++)
		{
			if ((i + 4 <= 7) && (arr[i][j] == arr[i + 1][j] || arr[i][j] == arr[i + 1][j] + 5 || arr[i][j] == arr[i + 1][j] - 5 || arr[i][j] == arr[i + 1][j] + 10 || arr[i][j] == arr[i + 1][j] - 10) && (arr[i][j] == arr[i + 2][j] || arr[i][j] == arr[i + 2][j] + 5 || arr[i][j] == arr[i + 2][j] - 5 || arr[i][j] == arr[i + 2][j] + 10 || arr[i][j] == arr[i + 2][j] - 10) && (arr[i][j] == arr[i + 3][j] || arr[i][j] == arr[i + 3][j] + 5 || arr[i][j] == arr[i + 3][j] - 5 || arr[i][j] == arr[i + 3][j] + 10 || arr[i][j] == arr[i + 3][j] - 10) && (arr[i][j] == arr[i + 4][j] || arr[i][j] == arr[i + 4][j] + 5 || arr[i][j] == arr[i + 4][j] - 5 || arr[i][j] == arr[i + 4][j] + 10 || arr[i][j] == arr[i + 4][j] - 10))  //condition for checking 5 same consecutive numbers
			{
				arr[i][j] = 80;        //updating value
				arr[i + 1][j] = ' ';   //updating value
				arr[i + 2][j] = ' ';   //updating value
				arr[i + 3][j] = ' ';   //updating value
				arr[i + 4][j] = ' ';   //updating value
				if (slideshow == 1)
					userinterface(arr, arr2, score, x, y, timer);   //function call;slows down and shows process
				flag = 1;       //updating value
				a = i + 4;     //updating value
				for (a; a >= 4; a--)             //loop for swaping vertically
				{
					swap(arr[a][j], arr[a - 4][j]);   //vertical swaping
					if (slideshow == 1)
						userinterface(arr, arr2, score, x, y, timer);   //function call;slows down and shows process
				}
				for (a = 3; a >= 0; a--)               //loop for placing random values in leftovers
				{
					arr[a][j] = rand() % 5 + 49;     //placing random values
					if (slideshow == 1)
						userinterface(arr, arr2, score, x, y, timer);   //function call;slows down and shows process
				}
				score = score + 5;                    //increment in score
			}
			else if ((i + 3 <= 7) && (arr[i][j] == arr[i + 1][j] || arr[i][j] == arr[i + 1][j] + 5 || arr[i][j] == arr[i + 1][j] - 5 || arr[i][j] == arr[i + 1][j] + 10 || arr[i][j] == arr[i + 1][j] - 10) && (arr[i][j] == arr[i + 2][j] || arr[i][j] == arr[i + 2][j] + 5 || arr[i][j] == arr[i + 2][j] - 5 || arr[i][j] == arr[i + 2][j] + 10 || arr[i][j] == arr[i + 2][j] - 10) && (arr[i][j] == arr[i + 3][j] || arr[i][j] == arr[i + 3][j] + 5 || arr[i][j] == arr[i + 3][j] - 5 || arr[i][j] == arr[i + 3][j] + 10 || arr[i][j] == arr[i + 3][j] - 10))  //condition for checking 4 same consecutive numbers 
			{
				assignflamevalue(arr, i, j);   //function call; it assigns values for flame gems
				flag = 1;                      //indication
				a = i + 3;                      //initialization
				arr[i + 1][j] = ' ';            //updating value
				arr[i + 2][j] = ' ';           //updating value
				arr[i + 3][j] = ' ';           //updating value
				if (slideshow == 1)
					userinterface(arr, arr2, score, x, y, timer);   //function call;slows down and shows process
				for (a; a >= 3; a--)             //loop for swaping vertically
				{
					swap(arr[a][j], arr[a - 3][j]);   //vertical swaping
					if (slideshow == 1)
						userinterface(arr, arr2, score, x, y, timer);   //function call;slows down and shows process
				}
				for (a = 2; a >= 0; a--)               //loop for placing random values in leftovers
				{
					arr[a][j] = rand() % 5 + 49;     //placing random values
					if (slideshow == 1)
						userinterface(arr, arr2, score, x, y, timer);   //function call;slows down and shows process
				}
				score = score + 4;                    //increment in score
			}
			else if (i + 2 <= 7 && (arr[i][j] == arr[i + 1][j] || arr[i][j] == arr[i + 1][j] + 5 || arr[i][j] == arr[i + 1][j] - 5 || arr[i][j] == arr[i + 1][j] + 10 || arr[i][j] == arr[i + 1][j] - 10) && (arr[i][j] == arr[i + 2][j] || arr[i][j] == arr[i + 2][j] + 5 || arr[i][j] == arr[i + 2][j] - 5 || arr[i][j] == arr[i + 2][j] + 10 || arr[i][j] == arr[i + 2][j] - 10)) //condition for checking three same consecutive numbers
			{
				flag = 1;        //indication
				a = i + 2;       //initialization
				arr[i][j] = ' ';      //updating value 
				arr[i + 1][j] = ' ';   //updating value
				arr[i + 2][j] = ' ';   //updating value
				if (slideshow == 1)
					userinterface(arr, arr2, score, x, y, timer);   //function call;slows down and shows process
				for (a; a >= 3; a--)    //loop for swaping vertical line
				{
					swap(arr[a][j], arr[a - 3][j]);   //swaping vertical line
					if (slideshow == 1)
						userinterface(arr, arr2, score, x, y, timer);   //function call;slows down and shows process
				}
				for (a = 2; a >= 0; a--)               //loop for assigning random values
				{
					arr[a][j] = rand() % 5 + 49;    //assigning random values
					if (slideshow == 1)
						userinterface(arr, arr2, score, x, y, timer);   //function call;slows down and shows process
				}
				score = score + 3;                    //increment in score
			}
		}
	return flag;                        //returns 0 or 1
}
int checkrow(char arr[][33], char arr2[][33], int& score, int x, int y, int slideshow, int timer) //function for checking same consecutive elements in a row
{
	srand((int)time(0));
	int a, b, l, m, flag;   //declaration
	l = 0;              //initialization
	m = 0;            //initialization
	flag = 0;              //initialization
	for (int i = 0; i < 8; i++) //loop for horizontal checking
		for (int j = 2; j <= 30; j = j + 4)
		{
			if (j + 16 <= 30 && (arr[i][j] == arr[i][j + 4] || arr[i][j] == arr[i][j + 4] + 5 || arr[i][j] == arr[i][j + 4] - 5 || arr[i][j] == arr[i][j + 4] + 10 || arr[i][j] == arr[i][j + 4] - 10) && (arr[i][j] == arr[i][j + 8] || arr[i][j] == arr[i][j + 8] + 5 || arr[i][j] == arr[i][j + 8] - 5 || arr[i][j] == arr[i][j + 8] + 10 || arr[i][j] == arr[i][j + 8] - 10) && (arr[i][j] == arr[i][j + 12] || arr[i][j] == arr[i][j + 12] + 5 || arr[i][j] == arr[i][j + 12] - 5 || arr[i][j] == arr[i][j + 12] + 10 || arr[i][j] == arr[i][j + 12] - 10) && (arr[i][j] == arr[i][j + 16] || arr[i][j] == arr[i][j + 16] + 5 || arr[i][j] == arr[i][j + 16] - 5 || arr[i][j] == arr[i][j + 16] + 10 || arr[i][j] == arr[i][j + 16] - 10)) //condition for checking 5 same consecutive elements in a row
			{
				arr[i][j] = ' ';     //updating value
				arr[i][j + 4] = ' ';   //updating value
				arr[i][j + 8] = 80;   //updating value
				arr[i][j + 12] = ' ';	  //updating value
				arr[i][j + 16] = ' ';   //updating value
				if (slideshow == 1)
					userinterface(arr, arr2, score, x, y, timer);   //function call;slows down and shows process
				flag = 1;   //updating value
				b = j;    //updating
				for (int k = 1; k <= 2; k++)              //loop for horizontal movement
				{
					a = i;                    //initialization
					for (a; a >= 1; a--)                     //loop for vertical swaping
					{
						swap(arr[a][b], arr[a - 1][b]);    //vertical swaping
						if (slideshow == 1)
							userinterface(arr, arr2, score, x, y, timer);   //function call;slows down and shows process
					}
					arr[a][b] = rand() % 5 + 49;        //assigning random values 
					if (slideshow == 1)
						userinterface(arr, arr2, score, x, y, timer);   //function call;slows down and shows process
					b = b + 4;                  //increment in coloumn
				}
				b = b + 4;    //updating value 
				for (int k = 1; k <= 2; k++)
				{
					a = i;                    //initialization
					for (a; a >= 1; a--)                     //loop for vertical swaping
					{
						swap(arr[a][b], arr[a - 1][b]);    //vertical swaping
						if (slideshow == 1)
							userinterface(arr, arr2, score, x, y, timer);   //function call;slows down and shows process
					}
					arr[a][b] = rand() % 5 + 49;        //assigning random values
					if (slideshow == 1)
						userinterface(arr, arr2, score, x, y, timer);   //function call;slows down and shows process
					b = b + 4;                          //increment in coloumn
				}
				score = score + 5;         //increment in score
			}
			else if (j + 12 <= 30 && (arr[i][j] == arr[i][j + 4] || arr[i][j] == arr[i][j + 4] + 5 || arr[i][j] == arr[i][j + 4] - 5 || arr[i][j] == arr[i][j + 4] + 10 || arr[i][j] == arr[i][j + 4] - 10) && (arr[i][j] == arr[i][j + 8] || arr[i][j] == arr[i][j + 8] + 5 || arr[i][j] == arr[i][j + 8] - 5 || arr[i][j] == arr[i][j + 8] + 10 || arr[i][j] == arr[i][j + 8] - 10) && (arr[i][j] == arr[i][j + 12] || arr[i][j] == arr[i][j + 12] + 5 || arr[i][j] == arr[i][j + 12] - 5 || arr[i][j] == arr[i][j + 12] + 10 || arr[i][j] == arr[i][j + 12] - 10)) //condition for checking 4 same consecutive elements in a row
			{
				assignflamevalue(arr, i, j);         //function call; it assigns the values of flame gem
				arr[i][j + 4] = ' ';     //updating value
				arr[i][j + 8] = ' ';   //updating value
				arr[i][j + 12] = ' ';   //updating value
				if (slideshow == 1)
					userinterface(arr, arr2, score, x, y, timer);   //function call;slows down and shows process
				flag = 1;                             //indication
				b = j + 4;                             //initialization
				for (int k = 1; k <= 3; k++)              //loop for horizontal movement 
				{
					a = i;                    //initialization
					for (a; a >= 1; a--)                     //loop for vertical swaping
					{
						swap(arr[a][b], arr[a - 1][b]);    //vertical swaping
						if (slideshow == 1)
							userinterface(arr, arr2, score, x, y, timer);   //function call;slows down and shows process
					}
					arr[a][b] = rand() % 5 + 49;        //assigning random values 
					if (slideshow == 1)
						userinterface(arr, arr2, score, x, y, timer);   //function call;slows down and shows process
					b = b + 4;                          //increment in coloumn
				}
				score = score + 4;         //increment in score
			}
			else if (j + 8 <= 30 && (arr[i][j] == arr[i][j + 4] || arr[i][j] == arr[i][j + 4] + 5 || arr[i][j] == arr[i][j + 4] - 5 || arr[i][j] == arr[i][j + 4] + 10 || arr[i][j] == arr[i][j + 4] - 10) && (arr[i][j] == arr[i][j + 8] || arr[i][j] == arr[i][j + 8] + 5 || arr[i][j] == arr[i][j + 8] - 5 || arr[i][j] == arr[i][j + 8] + 10 || arr[i][j] == arr[i][j + 8] - 10)) // condition for checking 3 consecutive same elements in a row
			{
				l = checkelbow(arr, arr2, i, j, score, x, y, slideshow, timer);      //function call; it check the condition of elbow
				if (l == 1)
					flag = 1;   //updating value
				else if (l == 0)
				{
					m = checkforflamegeminrow(arr, arr2, i, j, x, y, score, slideshow, timer);
					if (m == 1)
						flag = 1;
					else if (m == 0)
					{
						arr[i][j] = ' ';   //updating value
						arr[i][j + 4] = ' ';   //updating value
						arr[i][j + 8] = ' ';  //updating value
						if (slideshow == 1)
							userinterface(arr, arr2, score, x, y, timer);   //function call;slows down and shows process
						flag = 1;   //updating vlaue
						b = j;  //initialization
						for (int k = 1; k <= 3; k++)    //loop for horizontal movement
						{
							a = i;             //initialization
							for (a; a >= 1; a--)    //loop for vertical swaping
							{
								swap(arr[a][b], arr[a - 1][b]);    //vertical swaping
								if (slideshow == 1)
									userinterface(arr, arr2, score, x, y, timer);   //function call;slows down and shows process
							}
							arr[a][b] = rand() % 5 + 49;        //assining random values
							if (slideshow == 1)
								userinterface(arr, arr2, score, x, y, timer);   //function call;slows down and shows process
							b = b + 4;             //increment
						}
						score = score + 3;     //increment in score
					}
				}
			}
		}
	return flag;                 //returns 0 or 1
}
void checkswapcondition(char arr[][33], char arr2[][33], int firstx, int firsty, int secondx, int secondy, int& score, int timer)
{
	int a, b;
	a = checkrow(arr, arr2, score, secondy + 2, (secondx + 2) * 3, 1, timer);        //function call;checks consecutive same elements in a row
	while (a == 1)
		a = checkrow(arr, arr2, score, secondy + 2, (secondx + 2) * 3, 1, timer);        //function call;checks consecutive same elements in a row
	b = checkcoloumn(arr, arr2, score, secondy + 2, (secondx + 2) * 3, 1, timer);    //function call;checks consecutive same elements in coloumn
	if (a == 0 && b == 0)              //conditon if swap is invalid
	{
		swap(arr[firstx][firsty], arr[secondx][secondy]);   //reswap the swaped elements
		Sleep(500);
		system("cls");       //clear the screen
		printboard(arr, arr2, score, timer);   //function call; prints the updated board
		shapegenerator(arr); //function call;generates shapes
		gotoxy((secondy + 2), (secondx + 2) * 3);   //function call;commands the pointer to a coordinate
	}
	if (a == 1 || b == 1)        //condition if swap is valid
	{
		Sleep(500);
		system("cls");          //clears the screen
		printboard(arr, arr2, score, timer);   //function call;prints the updated board
		shapegenerator(arr); //function call;generates shapes
		gotoxy((secondy + 2), (secondx + 2) * 3);    //function call;commands the pointer to a coordinate
		a = checkrow(arr, arr2, score, secondy + 2, (secondx + 2) * 3, 1, timer);         //function call;checks consecutive same elements in a row
		while (a == 1)
			a = checkrow(arr, arr2, score, secondy + 2, (secondx + 2) * 3, 1, timer);        //function call;checks consecutive same elements in a row
		b = checkcoloumn(arr, arr2, score, secondy + 2, (secondx + 2) * 3, 1, timer);     //function call;checks consecutive same elements in a coloumn
		while (a == 1 || b == 1)       //terminates only when no same consecutive element is found in row or coloumn
		{
			Sleep(500);               //slows down
			system("cls");             //clear screen
			printboard(arr, arr2, score, timer);    //function call;prints updated board
			shapegenerator(arr); //function call;generates shapes
			gotoxy((secondy + 2), (secondx + 2) * 3);    //function call;commands the pointer to a coordinate
			a = checkrow(arr, arr2, score, secondy + 2, (secondx + 2) * 3, 1, timer);      //function call;checks same consecutive elements in a coloumn
			while (a == 1)
				a = checkrow(arr, arr2, score, secondy + 2, (secondx + 2) * 3, 1, timer);        //function call;checks consecutive same elements in a row
			b = checkcoloumn(arr, arr2, score, secondy + 2, (secondx + 2) * 3, 1, timer);    //function call;check same consecutive elements in a coloumn
		}
	}
}
void savegame(char arr[][33], char name[6], int number, int score)
{
	if (number == 1)
	{
		ofstream fout("game1.txt");
		if (!fout.is_open())
			cout << "Error: File Not Found";
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 33; j++)
				fout << arr[i][j];
			fout << " ";
		}
		fout << endl;
		fout << " " << score;
	}
	if (number == 2)
	{
		ofstream fout("game2.txt");
		if (!fout.is_open())
			cout << "Error: File Not Found";
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 33; j++)
				fout << arr[i][j];
			fout << " ";
		}
		fout << endl;
		fout << " " << score;
	}
	if (number == 3)
	{
		ofstream fout("game3.txt");
		if (!fout.is_open())
			cout << "Error: File Not Found";
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 33; j++)
				fout << arr[i][j];
			fout << " ";
		}
		fout << endl;
		fout << " " << score;
	}
}
void loadgame(char arr[][33], char arr2[][33], char name[6], int number, int& score)
{
	if (number == 1)
	{
		ifstream fin("game1.txt");
		if (!fin.is_open())
			cout << "Error: File Not Found";
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 33; j = j + 2)
				fin >> arr[i][j];
		for (int i = 0; i < 8; i++)
			for (int j = 1; j < 33; j = j + 2)
				arr[i][j] = ' ';
		fin >> score;
	}
	if (number == 2)
	{
		ifstream fin("game2.txt");
		if (!fin.is_open())
			cout << "Error: File Not Found";
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 33; j = j + 2)
				fin >> arr[i][j];
		for (int i = 0; i < 8; i++)
			for (int j = 1; j < 33; j = j + 2)
				arr[i][j] = ' ';
		fin >> score;
	}
	if (number == 3)
	{
		ifstream fin("game3.txt");
		if (!fin.is_open())
			cout << "Error: File Not Found";
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 33; j = j + 2)
				fin >> arr[i][j];
		for (int i = 0; i < 8; i++)
			for (int j = 1; j < 33; j = j + 2)
				arr[i][j] = ' ';
		fin >> score;
	}
}
int main()
{
	int x, y, a, b, input, firstx, firsty, secondx, secondy, score, key, slideshow, number;   //declaration
	char val[8][33];      //character array declaration
	char val2[8][33];     //char array declaration
	char name[6];         //char array declaration

	score = 0;            //initialization
	x = 4;               //initialization
	y = 6;               //initialization
	input = 0;           //initialization
	slideshow = 0;       //initialization
	int startingtime = time(NULL);     //starting time
	time_t end = time(NULL) + 60;          // one min time control

	initialvaluesofboard(val, val2, 8);    //function call;initializes board
	gemgenerator(val, 8);           //fucntion call;generates random elements in character array
	shapegenerator(val);             //function call;generates shapes
	printboard(val, val2, score, 60);        //function call;prints updated board
	shapegenerator(val);             //function call;generates shapes
	gotoxy(x, y);                 //function call;commands the pointer to a coordiante
	a = checkrow(val, val2, score, x, y, slideshow, 60);        //function call;checks same consecutive elements in a row
	b = checkcoloumn(val, val2, score, x, y, slideshow, 60);    //function call;checks same consecutive elements in a coloumn

	while (a == 1 || b == 1)        //terminates only when no same consecutive element is found in row or coloumn
	{
		system("cls");    //clear the screen
		score = 0;     //initialization
		printboard(val, val2, score, 60);    //function call;prints the updated board
		shapegenerator(val);             //function call;generates shapes
		gotoxy(x, y);            //function call;commands the pointer to a coordinate
		a = checkrow(val, val2, score, x, y, slideshow, 60);        //function call;checks same consecutive elements in  a row
		b = checkcoloumn(val, val2, score, x, y, slideshow, 60);    //function call;checks same consecutive elements in a coloumn	
	}
	//isCursorKeyPressed(key);    //function call;checks if any cursor key is pressed
	input = _getch();

	while (time(NULL) <= end && input != 113)
	{
		int timer = 60 - (time(NULL) - startingtime);
		while (input != 'q' && input != 'Q' && input != 13 && input != 's' && input != 'S' && input != 'L' && input != 'l')      //terminates when 'q', 's', 'l', 'S', 'l' or enter is pressed
		{
			cursormovement(input, x, y);  //function call;gives directions to pointer
			gotoxy(x, y);                 //function call;commands th pointer to a coordinate
										  //isCursorKeyPressed(key);    //function call;checks if any cursor key is pressed
			input = _getch();              //takes an ASCII
		}
		if (input != 'q' && input != 'Q' && input != 's' && input != 'S' && input != 'L' && input != 'l')      //terminates when 'q', 's', 'l', 'S' or 'l' is pressed
		{
			firstx = y / 3 - 2;                 //updates x-coordinate of first elements to be swapped
			firsty = x - 2;        //updates y-coordinate of first elements to be swapped
			input = _getch();
			//isCursorKeyPressed(key);    //function call;checks if any cursor key is pressed
		}
		while (input != 'q' && input != 'Q' && input != 13 && input != 's' && input != 'S' && input != 'L' && input != 'l')      //terminates when 'q', 's', 'l', 'S', 'l' or enter is pressed
		{
			cursormovement(input, x, y);   //function call;gives directions to pointer
			gotoxy(x, y);                 //function call;commands th pointer to a coordinate
			input = _getch();
			//isCursorKeyPressed(key);    //function call;checks if any cursor key is pressed
		}
		if (input != 113 && input != 's' && input != 'S' && input != 'L' && input != 'l')      //terminates when 'q', 's', 'l', 'S'or 'l' is pressed
		{
			secondx = y / 3 - 2;          //updates x-coordinate of second elements to be swapped
			secondy = x - 2;            //updates y-coordinate of second elements to be swapped
			if ((firstx - secondx == 1 || firstx - secondx == -1 || firstx - secondx == 0) && (firsty - secondy == 4 || firsty - secondy == -4 || firsty - secondy == 0) && (firstx - secondx == 0 || firsty - secondy == 0))
			{
				swap(val[firstx][firsty], val[secondx][secondy]);    //swaps first and second element
				system("cls");
				printboard(val, val2, score, timer);     //prints updated board
				shapegenerator(val);             //function call;generates shapes
				gotoxy((secondy + 2), (secondx + 2) * 3);    //function call;commands the pointer to a coordinate
				Sleep(150);
				checkswapcondition(val, val2, firstx, firsty, secondx, secondy, score, timer);  //checks if swap is valid or not
			}
		}
		if (input == 's' || input == 'S')  //if user presses 's' the game is saved
		{
			gotoxy(12, 33);              //redirecting the cursor
			cout << "save game?" << endl;
			cout << "1-Game 1" << endl;
			cout << "2-Game 2" << endl;
			cout << "3-Game 3" << endl;
			cin >> number;        //takes a number
			savegame(val, name, number, score);  //function call;saves the character array in a file
			system("cls");      //clear screen
			printboard(val, val2, score, timer);  //function call;prints board
			shapegenerator(val);   //function call;prints shapes
			gotoxy(x, y);   //redirects the cursor
		}
		if (input == 'l' || input == 'L')  //if user presses 'l' the game is loaded
		{
			gotoxy(12, 33);          //redirects the cursor
			cout << "load game?" << endl;
			cout << "1-Game 1" << endl;
			cout << "2-Game 2" << endl;
			cout << "3-Game 3" << endl;
			cin >> number;      //takes a number
			loadgame(val, val2, name, number, score); //function call;loads the saved game
			system("cls");   //clear screen
			printboard(val, val2, score, timer);  //function call;prints board
			shapegenerator(val);   //function call;prints shapes
			gotoxy(x, y);   //redirects the cursor
		}
		if (input != 'q' || input == 'Q')   //'q' for quiting game
			input = _getch();  //takes an ascii
							   //isCursorKeyPressed(key);    //function call;checks if any cursor key is pressed
	}
	if (input == 'q' || input == 'Q')    //if user presses 'q' the game ends
	{
		gotoxy(12, 33);
		cout << "Game End" << endl << "press any key to return";
	}
	gotoxy(12, 33);
	cout << "Time up\nPress any key to return\n";
	_getch();
}