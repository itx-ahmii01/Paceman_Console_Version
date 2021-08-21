//This Game is coded by Muhammad Ahmad

#include<iostream>
#include<windows.h>
#include <time.h>
using namespace std;

char array1[22][68] = {
	"*************************************************************",
	"*                                                           *",
	"*                          +++++                            *",
	"*                                     +     ++++++++++      *",
	"* ++     ########                     +                     *",
	"*                         |    |      +                     *",
	"*    |              |     |    |      +      |     |    |   *",
	"*    |     +++++    |     |    |      +      |     |    |   *",
	"*    |              |                        |     |    |   *",
	"*    |                            |                         *",
	"*    |    +++++++++  +++++        |    ++++++++++           *",
	"*    |     Ahmad     Arshad            |                 +  *",
	"*    | +++++                                        +       *",
	"*                  +++++                   +++++            *",
	"*                                                           *",
	"*       ########                 ########          ++++++++ *",
	"*                                                           *",
	"*                                                           *",
	"*                                                           *",
	"*                                               Map - X     *",
	"*************************************************************",
};

/*I will be using gotoxy function in my program to avoid screen flickering so i don't have to
Print the map again after every move*/

void gotoxy(int x, int y)         
{
	COORD c;         /* Using column number as x-coordinate and row number as y-coordinate*/
	c.X = y;					
	c.Y = x;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

/*The below fuctions give me the new co-ordinates of Ghosts/monsters after 
every loop*/

int monstermotion(int &x1, int &y1, int &flag1)
{
	if (flag1 == 0) {
		if (array1[x1][y1 + 1] == ' ' || array1[x1][y1 + 1] == '.')
		{
			y1++;
		}
		else if (array1[x1 + 1][y1] == ' ' || array1[x1 + 1][y1] == '.')
			x1++;
		else if (array1[x1 + 1][y1] == '*')
			flag1 = 1;
	}

	if (flag1 == 1)
	{
		if (array1[x1 + 1][y1] == '*')
		{
			y1--;
			if (y1 == 2)
			{
				flag1 = 0;
				return x1 = 7;
			}
		}
	}
	return x1;
}
int monstermotion2(int &x2, int &y2, int &flag2)
{
	if (flag2 == 0) {
		if (array1[x2][y2 + 1] == ' ' || array1[x2][y2 + 1] == '.')
		{
			y2++;
		}
		else if (array1[x2 + 1][y2] == ' ' || array1[x2 + 1][y2] == '.')
			x2++;
		else if (array1[x2 + 1][y2] == '*')
			flag2 = 1;
	}

	if (flag2 == 1)
	{
		if (array1[x2 + 1][y2] == '*')
		{
			y2--;
			if (y2 == 2)
			{
				flag2 = 0;
				return x2 = 3;
			}
		}
	}
	return x2;
}
int monstermotion3(int &x3, int &y3, int &flag3)
{
	if (flag3 == 0) {
		if (array1[x3][y3 + 1] == ' ' || array1[x3][y3 + 1] == '.')
		{
			y3++;
		}
		else if (array1[x3 + 1][y3] == ' ' || array1[x3 + 1][y3] == '.')
			x3++;
		else if (array1[x3 + 1][y3] == '*')
			flag3 = 1;
	}

	if (flag3 == 1)
	{
		if (array1[x3 + 1][y3] == '*')
		{
			y3--;
			if (y3 == 2)
			{
				flag3 = 0;
				return y3 = 17;
			}
		}
	}


	return x3;


}




int main()
{
	clock_t t1, t2;
	t1 = clock(); /*Note's the time at the start of Program execution */

	int flag = 0; int flag1 = 0, flag2 = 0, flag3 = 0;
	/*Initial Coordinates of the hero and Ghosts/Monsters*/
	int x = 19, y = 32, x1 = 3, y1 = 3, x2 = 12, y2 = 20, x3 = 6, y3 = 57;
	int points = 0, lifecounter = 1;

	for (int i = 0; i < 22; i++)          /*Prints The map of the game*/
	{
		for (int j = 0; j < 68; j++)
		{
			cout << array1[i][j];
		}
		cout << endl;
	}

	int count = 0;

	while (flag == 0)
	{
		/*Count is the number of time while loop has executed*/
		if (count == 30 || count == 100 || count == 150)    /*Gives Extra life as bonus*/
		{
			if (count == 30)
			{
				array1[1][30] = 'L';
				gotoxy(1, 30); cout << "L";
			}
			if (count == 100)
			{
				array1[2][50] = 'L';
				gotoxy(2, 50); cout << "L";
			}
			if (count == 150)
			{
				array1[2][10] = 'L';
				gotoxy(2, 10); cout << "L";
			}
		}
		gotoxy(4, 68); cout << "Points :" << points;
		gotoxy(6, 68); cout << "Lifes :" << lifecounter;

		t2 = clock();                     
		float diff = ((float)t2 - (float)t1);   /*Gives the time since the start of Execution*/
		gotoxy(2, 68);
		cout << "Time: " << int(diff / CLOCKS_PER_SEC) << " seconds" << endl;


		int oldx = x, oldy = y;          /*Saving the old coordinates as the will be later used*/
		int oldx1 = x1, oldy1 = y1;
		int oldx2 = x2, oldy2 = y2;
		int oldx3 = x3, oldy3 = y3;

		/*I will be using GetAsyncKeyState() instead of _getch() to take input
		for my HERO's motion in my program because _getch() stops the execution of loop
		till i give it an input which is annoying*/
		
		if (GetAsyncKeyState(VK_UP))         /*Moves to the upper row*/
		{
			if (array1[x - 1][y] == 'L')
			{
				array1[x - 1][y] = ' ';
				lifecounter++;
				x--;

			}
			else if (array1[x - 1][y] == '.')
			{
				array1[x - 1][y] = ' ';
				x--;
				points++;
			}
			else if (array1[x - 1][y] == ' ')
			{
				x--;
			}
		}
		if (GetAsyncKeyState(VK_DOWN))       /*Moves to the below row*/
		{
			if (array1[x + 1][y] == 'L')
			{
				array1[x + 1][y] = ' ';
				x++;
				lifecounter++;
			}
			else if (array1[x + 1][y] == '.')
			{
				array1[x + 1][y] = ' ';
				x++; 
				points++;
			}
			else if (array1[x + 1][y] == ' ')
			{
				x++;
			}
		}
		if (GetAsyncKeyState(VK_LEFT))          /*Moves 1 column back */
		{
			if (array1[x][y - 1] == 'L')
			{
				array1[x][y - 1] = ' ';
				y--; 
				lifecounter++;
			}

			else if (array1[x][y - 1] == '.')
			{
				array1[x][y - 1] = ' ';
				y--; 
				points++;
			}
			else if (array1[x][y - 1] == ' ')
			{
				y--;
			}
		}
		if (GetAsyncKeyState(VK_RIGHT))        /*Moves to the next column*/
		{
			if (array1[x][y + 1] == 'L')
			{
				array1[x][y + 1] = ' ';
				y++; 
				lifecounter++;
			}
			else if (array1[x][y + 1] == '.')
			{
				array1[x][y + 1] = ' ';
				y++; 
				points++;
			}

			else if (array1[x][y + 1] == ' ')
			{
				y++;
			}
		}

		/* These Fuctions give the new Coordinates of Monsters/Ghosts */

		monstermotion(x1, y1, flag1);
		monstermotion2(x2, y2, flag2);
		monstermotion2(x3, y3, flag3);

		gotoxy(x, y); cout << "P";

		gotoxy(x1, y1); cout << "G";

		gotoxy(x2, y2);  cout << "G";

		gotoxy(x3, y3); cout << "G";

		/*If the old and new coordinates of Ghosts or hero are not same it performs certain tasks*/

		if (x != oldx || y != oldy)      /*Prints space in the last coordinates of HERO*/
		{
			gotoxy(oldx, oldy); cout << ' ';
			array1[oldx][oldy] == ' ';
		}
		if (x1 != oldx1 || y1 != oldy1)    /*Prints points in the last coordinates of Ghosts*/
		{
			array1[oldx1][oldy1] = '.';
			gotoxy(oldx1, oldy1); cout << '.';
		}
		if (x2 != oldx2 || y2 != oldy2)
		{
			array1[oldx2][oldy2] = '.';
			gotoxy(oldx2, oldy2); cout << '.';
		}
		if (x3 != oldx3 || y3 != oldy3)
		{
			array1[oldx3][oldy3] = '.';
			gotoxy(oldx3, oldy3); cout << '.';
		}

		Sleep(100);

		/*If the Coordinates of the Ghosts and Hero are same and lifes are zero 
		                    the Game/program ends*/
		if (x1 == x &&y1 == y)
		{
			lifecounter--;
			if (lifecounter == 0) 
			{
				system("cls");
				gotoxy(5, 5);
				cout << "You have lost the Game" << endl;
				cout << endl; gotoxy(7, 5);
				cout << "Your score is " << points << "  ";
				cout << endl; gotoxy(9, 5);
				cout << "You Survived in the game for " << int(diff / CLOCKS_PER_SEC) << " seconds" << endl;
				cout << endl; cout << endl; cout << endl;
				flag = 1;
			}
		}
		if (x2 == x &&y2 == y)
		{
			lifecounter--;
			if (lifecounter == 0)
			{
				system("cls");
				gotoxy(5, 5);
				cout << "You have lost the Game " << endl;
				cout << endl; gotoxy(7, 5);
				cout << "Your score is " << points << "  ";
				cout << endl; gotoxy(9, 5);
				cout << "You Survived in the game for " << int(diff / CLOCKS_PER_SEC) << " seconds" << endl;
				cout << endl; cout << endl; cout << endl;
				flag = 1;
			}
		}
		if (x3 == x && y3 == y)
		{
			lifecounter--;
			if (lifecounter == 0) 
			{
				system("cls");
				gotoxy(5, 5);
				cout << "You have lost the Game " << endl;
				cout << endl; gotoxy(7, 5);
				cout << "Your score is " << points << "   ";
				cout << endl; gotoxy(9, 5);
				cout << "You Survived in the game for " << int(diff / CLOCKS_PER_SEC) << " seconds" << endl;
				cout << endl; cout << endl; cout << endl;
				flag = 1;
			}
		}
		count++;
	}    /*While loop body ends here*/
}


