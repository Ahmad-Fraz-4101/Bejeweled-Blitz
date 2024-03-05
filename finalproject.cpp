// Ahmad Fraz (22L-6735)

#include<iostream>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include"Header.h"
using namespace std;
int score=0;
void egg(int x, int y)
{
	myEllipse(x + 3, y, x + 15, y + 20, 255, 255, 0);

}
void vrectangle(int x, int y)//vertical triangle
{
	myRectangle(x, y, x + 15, y + 25, 0, 255, 0);

}
void triangle(int x, int y)//triangle
{
	myLine(x - 5, y + 5, x + 10, y + 20, 255, 150, 0);
	myLine(x + 10, y + 20, x + 25, y + 5, 255, 150, 0);
	myLine(x + 25, y + 5, x - 5, y + 5, 255, 150, 0);
}
void circle(int x, int y)
{
	myEllipse(x, y, x + 20, y + 20, 255, 255, 255);//circle
}
void hrectangle(int x, int y)//horizontal rectangle
{
	myRectangle(x - 5, y + 5, x + 20, y + 20, 255, 0, 0);
}

//special shapes
void specialtriangle(int x, int y)
{
	myLine(x - 5, y + 5, x + 10, y + 20, 0, 0, 255);
	myLine(x + 10, y + 20, x + 25, y + 5, 255, 0, 0);
	myLine(x + 25, y + 5, x - 5, y + 5, 0, 255, 0);
}
void specialegg(int x, int y)
{
	myEllipse(x + 3, y, x + 15, y + 20, 0, 0, 255); 
	myLine(x + 4, y + 5, x + 13, y + 5, 255, 0, 0);
	myLine(x + 3, y + 10, x + 15, y + 10, 255, 0, 0);
	myLine(x + 4, y + 15, x + 13, y + 15, 255, 0, 0);
}
void specialhrect(int x, int y)//for horizontal rectangle
{
	myRectangle(x - 5, y + 5, x + 20, y + 20, 255, 0, 0);
	myRectangle(x - 3, y + 9, x + 17, y + 16, 255, 255, 0);
}
void specialcircle(int x, int y)
{
	myEllipse(x, y, x + 20, y + 20, 255, 255, 0);
	myEllipse(x + 2, y + 2, x + 18, y + 18, 255, 0, 0);
	myEllipse(x + 6, y + 6, x + 14, y + 14, 255, 255, 255);
}
void specialvrect(int x, int y)
{
	myRectangle(x, y, x + 15, y + 25, 0, 255, 0);
	myRectangle(x + 3, y + 5, x + 12, y + 20, 0, 0, 255);
}

//check board if matching column or row appears it will return truen  else false.

bool samefound(int brd[][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (((brd[i][j])%5 == (brd[i][j + 1])%5) && ((brd[i][j])%5 == (brd[i][j + 2])%5))
				return true;
		}
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if(((brd[j][i])%5 == (brd[j+1][i])%5) && ((brd[j][i])%5 == (brd[j+2][i])%5))
				return true;
		}
	}
	return false;
}

 


//search for same shapes in a row and swap it with uper row till it reaches first row.
 //after that it destroy same shapes and replce them with new ones.
void chkrow(int arr[][8], int row)
{
	srand(time(0));

	for (int i = 0; i < 7; i++)
	{
		int r = row;
		while (r != 0)
		{

			if (arr[r][i] == (arr[r][i + 1]) && (arr[r][i]) == (arr[r][i + 2]))
			{
				swap(arr[r][i], arr[r - 1][i]);
				swap(arr[r][i + 1], arr[r - 1][i + 1]);
				swap(arr[r][i + 2], arr[r - 1][i + 2]);

			}

			r--;
		}
		if ((arr[0][i]) == (arr[0][i + 1]) && (arr[0][i]) == (arr[0][i + 2]))
		{
			for (int j = i; j < i + 3; j++)
			{
				arr[0][j] = rand() % 5;
			}
			score = score + 500;
		}
	}

	return;
}
// when special shape matches with 2 simple same shapes it will destroy whole row.
void chkrowsp(int arr[][8], int row)
{
	srand(time(0));

	for (int i = 0; i < 6; i++)
	{
		int r = row;
		if ((arr[row][i]) % 5 == (arr[row][i + 1]) % 5 && (arr[row][i]) % 5 == (arr[row][i + 2]) % 5)
		{
			for (int j = 0; j < 8; j++)
			{
				arr[row][j] = rand() % 5;
			}
			score = score + 1000;
		}
	}
	return;
}

//destroy row  when special gem matches and brings down the upper shapes .

void Hshift(int brd[][8], int i, int j)
{
	for (int k = i; k > 0; k--)
		brd[k][j] = brd[k - 1][j];
	srand(time(0));
	brd[0][j] = rand() % 5;
}


//in case of vertical match of special shapes it destroy same shapes and replace with upper shapes.

void Vshift(int brd[][8], int i, int j)
{
	for (int k = i - 1; k >= 0; k--)
		brd[k + 3][j] = brd[k][j];
	srand(time(0));
	for (int k = 0; k < 3; k++)
		brd[k][j] = rand() % 5;
}


// if 4 shapes matches it will destroy three shapes and allocate special gem to fourth one (!!!!!for rows!!!!!!!!).

void insertflamegem(int b[][8])
{
	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			if (b[r][c] == b[r][c + 1] && b[r][c + 1] == b[r][c + 2] && b[r][c + 2] == b[r][c + 3] && b[r][c] == 1)
			{
				Hshift(b, r, c);
				Hshift(b, r, c + 1);
				Hshift(b, r, c + 2);
				b[r][c + 3] = 11;
				score = score + 800;

			}
			if (b[r][c] == b[r][c + 1] && b[r][c + 1] == b[r][c + 2] && b[r][c + 2] == b[r][c + 3] && b[r][c] == 0)
			{
				Hshift(b, r, c);
				Hshift(b, r, c + 1);
				Hshift(b, r, c + 2);
				b[r][c + 3] = 10;
				score = score + 800;
			}
			if (b[r][c] == b[r][c + 1] && b[r][c + 1] == b[r][c + 2] && b[r][c + 2] == b[r][c + 3] && b[r][c] == 2)
			{
				Hshift(b, r, c);
				Hshift(b, r, c + 1);
				Hshift(b, r, c + 2);
				b[r][c + 3] = 12;
				score = score + 800;
			}
			if (b[r][c] == b[r][c + 1] && b[r][c + 1] == b[r][c + 2] && b[r][c + 2] == b[r][c + 3] && b[r][c] == 3)
			{
				Hshift(b, r, c);
				Hshift(b, r, c + 1);
				Hshift(b, r, c + 2);
				b[r][c + 3] = 13;
				score = score + 800;
			}
			if (b[r][c] == b[r][c + 1] && b[r][c + 1] == b[r][c + 2] && b[r][c + 2] == b[r][c + 3] && b[r][c] == 4)
			{
				Hshift(b, r, c);
				Hshift(b, r, c + 1);
				Hshift(b, r, c + 2);
				b[r][c + 3] = 14;
				score = score + 800;
			}
		}
	}
}
// if 4 shapes matches it will destroy three shapes and allocate special gem to fourth one (!!!!!  for columns  !!!!!!!!).

void Vinsertflamegem(int b[][8])
{
	for (int c = 0; c < 8; c++)
	{
		for (int r = 0; r < 5; r++)
		{
			if (b[r][c] == b[r + 1][c] && b[r + 1][c] == b[r + 2][c] && b[r + 2][c] == b[r + 3][c])
			{
				if (b[r][c] == 0)
					b[r + 3][c] = 10;
				else if (b[r][c] == 1)
					b[r + 3][c] = 11;
				else if (b[r][c] == 2)
					b[r + 3][c] = 12;
				else if (b[r][c] == 3)
					b[r + 3][c] = 13;
				else if (b[r][c] == 4)
					b[r + 3][c] = 14;
				Vshift(b, r, c);
				score = score + 800;
			}
		}
	}
}





//this function checks if three same shapes are in the coloumn.
//take them to the start of column and replaces by new random shapes. 



void checkcol(int arr[][8])
{
	srand(time(0));
	for (int c = 0; c < 8; c++)
	{
		for (int r = 0; r < 5; r++)
		{

			if (arr[r][c] == arr[r + 1][c] && arr[r + 1][c] == arr[r + 2][c])
			{
				Vshift(arr, r, c);
			}

		}
	}
}


//when special shape matches with 2 simple shapes in column, this function will destroy whole column 
void checkcolsp(int arr[][8], int col)
{
	srand(time(0));
	for (int i = 0; i < 8; i++)
	{

		if ((arr[i][col]) % 5 == (arr[i + 1][col]) % 5 && (arr[i + 1][col]) % 5 == (arr[i + 2][col]) % 5)
		{

			for (int j = 0; j < 9; j++)
			{
				arr[j][col] = rand() % 5;
			}
			score = score + 1000;
		}
	}
}

// fills the array with random number

void filler(int brd[][8], int size)
{
	srand(time(0));
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			brd[i][j] = rand() % 5;

		}
	}
	
	for (int i = 7; i >= 0; i--)
	{
		chkrow(brd, i);

	}
	
	
		checkcol(brd);
		
	
}


//draw the cursor
void cursor(int cx1, int cy1)
{
	myLine(cx1, cy1, cx1 + 20, cy1, 255, 255, 255);
}



//this function print the board (diffrent shapes for different number).

void printarray(int arr[][8], int i, int j, int cx2, int cy2)
{
	HANDLE  h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 4);
	gotoxy(16, 0);
	cout << "Bejeweled Blitz";
	int x, y = 100;  // cordinates for position of shapes 

	// 5 lines of code ahead are for grid background and borders 
	myRectangle(80, 80, 570, 500, 0, 0, 0);
	myLine(80, 80, 570, 80, 255, 255, 255);
	myLine(80, 80, 80, 500, 255, 255, 255);
	myLine(570, 80, 570, 500, 255, 255, 255);
	myLine(80, 500, 570, 500, 255, 255, 255);
	//lines for checks
	int f = 80, g=140; // cordinates for horizontal lines 
	for (int i = 0; i < 7; i++)
	{
		myLine(f,g,f+490,g,255,255,255);
		
		g = g + 50;
	
	}
	int l=140, k=80; // cordinates for verrical lines
	for (int i = 0; i < 7; i++)
	{
		myLine(l, k, l , k + 420, 255, 255, 255);
		l =  l + 60;
	}



	cursor(cx2, cy2); // places the cursor

	for (int k = 0; k < 8; k++)
	{
		x = 100;
		for (int l = 0; l < 8; l++)
		{

			if (k == i && l == j)
			{

				if (arr[k][l] == 0)//egg for 0
				{
					egg(x, y);

				}
				if (arr[k][l] == 1)//vertical rectanglee for 1
				{
					vrectangle(x, y);

				}
				if (arr[k][l] == 2)//circle for 2
				{
					circle(x, y);

				}
				if (arr[k][l] == 3)// horizontal rectangle for 3
				{
					hrectangle(x, y);

				}
				if (arr[k][l] == 4)//triangle for 0
				{
					triangle(x, y);

				}
				if (arr[k][l] == 10)
				{
					specialegg(x, y);
				}
				if (arr[k][l] == 11)
				{

					specialvrect(x, y);
				}


				if (arr[k][l] == 12)
				{
					specialcircle(x, y);
				}
				if (arr[k][l] == 13)
				{
					specialhrect(x, y);
				}
				if (arr[k][l] == 14)
				{
					specialtriangle(x, y);

				}



			}
			else
			{
				if (arr[k][l] == 0)//0
				{
					egg(x, y);

				}
				if (arr[k][l] == 1)//1
				{
					vrectangle(x, y);

				}
				if (arr[k][l] == 2)//2
				{
					circle(x, y);

				}
				if (arr[k][l] == 3)//3
				{
					hrectangle(x, y);

				}
				if (arr[k][l] == 4)//0
				{
					triangle(x, y);

				}
				if (arr[k][l] == 10)
				{
					specialegg(x, y);
				}
 				if (arr[k][l] == 11)
				{
					specialvrect(x, y);
				}
				if (arr[k][l] == 12)
				{
					specialcircle(x, y);
				}
				if (arr[k][l] == 13)
				{
					specialhrect(x, y);
				}
				if (arr[k][l] == 14)
				{
					specialtriangle(x, y);

				}

			}
			x = x + 60; //print the next shape after 60 pixels on x axis
			
		}
		y = y + 50;   //print the next shape after 50 pixels on y axis
		
	}
}



void swapfun(int brd[][8], int i, int j)
{
	int check = 0;
	bool c = 0;
	while (c == 0)//makes sure the key is pressed
	{
		c = isCursorKeyPressed(check);//return true if  cursor key is pressed
	}
	
	
		
			if (check == 1 && c == true)//left
			{
				swap(brd[i][j], brd[i][j - 1]);
			
				if (samefound(brd) == false)
				{
					swap(brd[i][j], brd[i][j-1]);
				}

			}
			else if (check == 2 && c == true)//up
			{
				swap(brd[i][j], brd[i - 1][j]);

				if (samefound(brd) == false)
				{
					swap(brd[i][j], brd[i-1][j]);
				}


			}
			else if (check == 3 && c == true)//right
			{
				swap(brd[i][j], brd[i][j + 1]);
		
				if (samefound(brd) == false)
				{
					swap(brd[i][j], brd[i][j+1]);
				}

			}
			else if (check == 4 && c == true)//down
			{
				swap(brd[i][j], brd[i + 1][j]);
				Sleep(300);
				if (samefound(brd) == false)
				{
					swap(brd[i][j], brd[i+1][j]);
				}

			}
	


	insertflamegem(brd);
	Vinsertflamegem(brd);
	for (int i = 7; i >= 0; i--)
	{

		chkrow(brd, i);


	}
	for (int i = 7; i >= 0; i--)
	{

		chkrowsp(brd, i);


	}
	

		checkcol(brd);

	for (int i = 7; i >= 0; i--)
	{

		checkcolsp(brd, i);

	}


}
int main()
{
	static CONSOLE_FONT_INFOEX  fontex;
	fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetCurrentConsoleFontEx(hOut, 0, &fontex);
	fontex.FontWeight = 700;
	fontex.dwFontSize.X = 30;
	fontex.dwFontSize.Y = 30;
	SetCurrentConsoleFontEx(hOut, NULL, &fontex);

	
	HANDLE  h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 14);
	cout << "          \t\t  WELCOME TO BEJEWELLED BLITZ\n\n\n";
	SetConsoleTextAttribute(h, 3);
	cout << "\nINSTRUCTIONS:";
	cout << "\n              1.Use cursor keys to move cursor\n              2.Press enter followed by cursor key to swap";
	SetConsoleTextAttribute(h, 4);
	cout << endl << endl;
	cout << "\n !!!!!!!!!!! Game will run for 90 seconds !!!!!!!!!!! \n\nScore will be shown at the end of game\n";
	SetConsoleTextAttribute(h, 5);
	cout << "\nPress any cursor key to start the game!\n";
	SetConsoleTextAttribute(h, 0);
	system("pause");
	system("cls");


	int board[8][8], a = 0, b = 0, move = 0;
	filler(board, 8);       // fills the array with random numbers
	int cx = 100, cy = 130; // cordinates for controlling the cursor
	time_t start, end;
	start = time(NULL);
	end = time(NULL) + 91;     //can change time from here
	


	//make sure that no combination appear when board is printed first

	
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			chkrow(board, i);
		}

		checkcol(board);
	}
		
	
	printarray(board, a, b, cx, cy);
	score=0;
	while (start<end-1)
	{
		insertflamegem(board);
		Vinsertflamegem(board);
		for (int i = 7; i >= 1; i--)
		{

			chkrow(board, i);

		}
		


			checkcol(board);

		
		for (int i = 7; i >= 0; i--)
		{

			chkrowsp(board, i);


		}
		for (int i = 7; i >= 0; i--)
		{

			checkcolsp(board, i);

		}

		
		bool c = 0;
		while (c == 0)
		{
			c = isCursorKeyPressed(move);
		}
		if (move == 1 && c == true && b != 0)//left
		{
			b--;
			cx = cx - 60;
		}
		if (move == 2 && c == true && a != 0)//up
		{

			a--;

			cy = cy - 50;

		}
		if (move == 3 && c == true && b != 7)//right
		{
			b++;
			cx = cx + 60;
		}
		if (move == 4 && c == true && a != 7)//down
		{
			a++;
			cy = cy + 50;
		}
		if (move == 5 && c == 1)
		{
			swapfun(board, a, b);
		}
		
		system("cls");
		printarray(board, a, b, cx, cy);
		start = time(NULL);
	}
	system("cls");
	gotoxy(35,4);

	 

	
	cout << "  Time Finished!!!!!\n\n\n";

	gotoxy(35, 6);
	cout << "Your score is :" << score;
	
	SetConsoleTextAttribute(h, 0);

	return 0;
}