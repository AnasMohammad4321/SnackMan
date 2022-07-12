#include<iostream>
#include<windows.h>
#include<conio.h>
#include<stdio.h>
using namespace std;
void gotoxy(short x, short y)           //definition of gotoxy function                                              
{
 COORD c ={x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
int main()
{
	int points,x=0,y=0;
	char a;
	cout<<"Enter maximum points : ";
	cin>>points;
	system("cls");
	for(int i=0;i<points;i++)
	{	
	a = getch();
    if(a==77)
    {
    	x++;
	}
	else if(a==75)
	{
		x--;
	}
	else if(a==72)
	{
		y--;
	}
	else if(a==80)
	{
		y++;
	}
	system("cls");
	gotoxy(x,y);
	cout<<"*";
    }
}
