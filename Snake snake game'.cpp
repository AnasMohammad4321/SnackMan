#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
bool gameOver;
const int width = 20; //width of map.
const int height = 20; //height of map
int x, y; //snake coordinates
int fruitX, fruitY; //fruit coordinates
int score; //score vairable
int tailX[100], tailY[100];
int nTail;
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;
void Setup()
{
	gameOver = false;
	dir = STOP;
	x = width / 2;//initial x coordinate position of snake
	y = height / 2; //initial y coordinate position of snake
	fruitX = rand() % width; //x coordinate of fruit (width - 1)
	fruitY = rand() % height; //y coordinate of fruit (height - 1)
	score = 0;
}
void Draw()
{
	system("cls");
	for (int i = 0; i < width + 2; i++)
		cout << "_";
	cout << endl;
	for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
				{
					if (j == 0)
						cout << "|";
					if (i == y && j == x)
						cout << "O";
					else if (i == fruitY && j == fruitX)
						cout << "F";
					else
						{
							for (int k = 0; k < nTail; k++)
								{
									bool print = false;
									if(tailX[k] == j && tailY[k] == i)
										{
											cout << "o";
											print = true;
										}
									if (!print)
										cout << " ";
								}
							cout << " ";
						}
							
					if (j == width - 1)
						cout << "|";
				
			cout << endl;
		}
	for (int i = 0; i < width + 2; i++)
		cout << "_";
	cout << endl;
	cout << "Score: " << score << endl;	
	
}
}
void Input()
{
	if((kbhit()))
		{
			switch (_getch())
				{
					case 'a':
						dir = LEFT;
						break;
					case 's':
						dir = DOWN;
						break;
					case 'w':
						dir = UP;
						break;
					case 'd':
						dir = RIGHT;
						break;
					case 'x':
						gameOver = true;
						break;
				}
		}
}

void Logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	for (int i = 1; i < nTail; i++)
		{
			prev2X = tailX[i];
			prev2Y = tailY[i];
			tailX[i] = prevX;
			tailY[i] = prevY;
			prevX = prev2X;
			prevY = prev2Y;
			
			
		}
	switch (dir)
	{
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case DOWN:
			y++;
			break;
		case UP:
			y--;
			break;
		default:
			break;
			
	}
	if (x > width || x < 0 || y > height || y < 0)
		{
		gameOver = true;	
		cout << "GAME OVER";
		}
	if (x == fruitX && y == fruitY)
		{
			score += 1;
			fruitX = rand() % width; //x coordinate of fruit (width - 1)
			fruitY = rand() % height; //y coordinate of fruit (height - 1)
			nTail += 1;
		}

	
}

int main()
{
	Setup();
	while(!gameOver)
		{
			Draw();
			Input();
			Logic();
			Sleep(100);
		}
	return 0;
}
