#include<conio.h>             //for getch function          
#include <iostream>                   
#include<cstdlib>              // for ramdom function       
#include<cmath>                // for any kind of math function       
#include<time.h>               // for srand function
#include<windows.h>			   // for system cls 

using namespace std;

const char plane = '^';
const char corner = '$';
const char edge = '$';
const int row = 30;
const int col = 50;
char arr[row][col];
int random;
int health = 10;
int points = 0;
char move;
void boarders(int _row, int _col)
{

	system("cls");

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i == 0 || i == row - 1)
			{
				arr[i][j] = '$';
			}
			else if (j == 0 || j == col - 1)
			{
				arr[i][j] = '$';
			}
			else if (i == 24 && j == 25)
			{

				arr[i][j] = plane;
			}
			else
			{
				arr[i][j] = ' ';
			}


		}
	}
}
void frontscreen()
{
	/*cout << "points:" << points << endl;
	cout << "health" << health;*/
	system("CLS");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}
}
void planemove(char mov)
{
	if (mov == 'w' || mov == 'W')
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (arr[i][j] == plane)
				{
					swap(arr[i - 1][j], arr[i][j]);
				}
			}
		}
	}
	else if (mov == 'a' || mov == 'A')
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (arr[i][j] == plane)
				{
					swap(arr[i][j - 1], arr[i][j]);

				}



			}
		}
	}
	else if (mov == 's' || mov == 'S')
	{
		for (int i = row; i >= 0; i--)
		{
			for (int j = 0; j < col; j++)
			{
				if (arr[i][j] == plane)
				{
					swap(arr[i + 1][j], arr[i][j]);

				}
			}
		}
	}
	else if (mov == 'd' || mov == 'D')
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (arr[i][j] == plane)
				{
					swap(arr[i][j + 1], arr[i][j]);
					break;
				}
			}
		}

	}
	if (mov == ' ')
	{

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (arr[i][j] == plane)
				{
					arr[i - 1][j] = 'x';

				}
			}
		}

	}

}
bool enemyloc()
{
	for (int i = 0; i < 5; i++)
	{

		for (int j = 0; j < 49; j++)
		{
			if (arr[i][j] == '#')
			{
				return true;
			}
		}
	}      return false;
}
void enemies()
{
	static int speed = 0;
	speed++;
	if (!enemyloc())
	{
		int pos = rand() % 48 + 1;
		arr[1][pos] = '#';         // location of enemy

	}
	if (speed == 1)
	{
		speed = 0;
		for (int i = 29; i >= 0; i--)
		{
			for (int j = 48; j >= 0; j--)
			{
				if (arr[i][j] == '#' && i == 28)
				{
					arr[i][j] = ' ';
				}
				if (arr[i + 1][j] == '^' && arr[i][j] == '#')
				{
					health--;
				}
				if (arr[i][j] == '#')
				{
					arr[i][j] = ' ';
					arr[i + 1][j] = '#';


				}
			}
		}
	}
}
void enemyattack()
{
	for (int i = 1; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] == '#')
			{

				arr[i + 2][j] = '!';

			}
			if (arr[i][j] == 'x' && arr[i - 1][j] == '#')
			{
				arr[i][j] = ' ';
			}
		}
	}

}
void fireplacement()	// enimies fire movement    
{
	{
		static int speed = 0;
		speed++;

		if (speed == 2)
			speed = 0;
		for (int i = 29; i >= 0; i--)
		{
			for (int j = 48; j >= 0; j--)
			{
				if (arr[i][j] == '!' && i == 28)
				{
					arr[i][j] = ' ';
				}
				else if (arr[i + 1][j] == '@' && arr[i][j] == '!')                //for health    
				{
					health--;
				}
				else if (health == 0)
				{
					cout << "Game Over";
					system("pause");
					break;
				}
			}
		}
	}
}
void planefiring() //movement of plane firing
{
	static int speed_fire = 0;
	speed_fire++;
	if (speed_fire >= 2)
	{
		for (int i = 0; i < 29; i++)
		{
			for (int j = 0; j < 49; j++)
			{
				if (arr[i][j] == 'x' && i == 1)
				{
					arr[i][j] = ' ';

				}
				if (arr[i - 1][j] == '#' && arr[i][j] == 'x')
				{
					arr[i - 1][j] = ' ';
					arr[i][j] = ' ';
					points += 2;
				}
				if (arr[i][j] == 'x' && i != 1)
				{
					arr[i][j] = ' ';
					arr[i - 1][j] = 'x';

				}

			}
		}

	}
}
void enemymovement2()
{
	srand(time(0));
	int speed = 2;
	speed++;
	if (!enemyloc())
	{
		for (int i = 2; i < 4; i++)
		{

			for (int j = 1; j < 48; j++)
			{
				srand(time(0));
				int pos = rand() % 48 + 1;
				arr[pos][i] = '#';
				arr[pos + 1][i] = '#';
				arr[pos + 2][i] = '#';
				arr[pos + 3][i] = '#';
				arr[i][pos] = '#';
				arr[i][pos + 1] = '#';
				arr[i][pos + 2] = '#';
				arr[i][pos + 3] = '#';

			}
		}

	}
	if (speed == 2)
	{
		speed = 0;
		for (int i = 2; i <= 4; i++)
		{
			for (int j = 48; j >= 0; j--)
			{
				if (arr[i][j] == '#' && j == 48)
				{
					arr[i][j] = ' ';
				}
				if (arr[i + 1][j] == '^' && arr[i][j] == '#')
				{
					health--;
				}
				if (arr[i][j] == '#')
				{
					arr[i][j] = ' ';
					arr[i][j + 1] = '#';
				}
			}
		}
	}
}
int main()
{
	system("pause");
	srand(time(0));
	int temp = 0;
	boarders(24, 25);
	char move;
	int gift = 0;
	int ef = 0;

	int em = 0;

	while (points < 20)
	{
		//stage 1
		em++;
		if (em == 7)
		{
			enemies();
			em = 0;
		}

		ef++;
		if (ef == 9)
		{
			enemyattack();
			ef = 0;
		}
		fireplacement();
		frontscreen();


		if (_kbhit())
		{
			move = _getch();
			planemove(move);
		}



		planefiring();
		cout << "points:" << points << endl;
		cout << "health" << health << endl;

	}
	//stage#02
//	system("pause");

	temp = 0;
	boarders(24, 25);

	gift = 0;
	ef = 0;

	em = 0;
	planefiring();

	while (points >= 20)
	{

		em++;
		if (em == 7)
		{
			enemymovement2();
			em = 0;
		}
		enemyattack();
		fireplacement();
		frontscreen();
		if (_kbhit())
		{
			move = _getch();
			planemove(move);
		}
		planefiring();
		cout << "points:" << points << endl;
		cout << "health" << health << endl;
		if (points >= 30)
		{
			cout << "you won" << endl;
		}
		system("CLS");
	}
}
