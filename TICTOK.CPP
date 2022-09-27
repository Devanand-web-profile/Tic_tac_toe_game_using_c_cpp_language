#include <stdio.h>
#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

#include "border.h"
	char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

	int checkwin();
	void board();

int main()
{
    textbackground(1);
    //restart:
    clrscr();
    int player = 1, i, choice;
    char p1name[10],p2name[10];
    border();

    gotoxy(4,4);
    cprintf("Enter player name 1 :");
    cin>>p1name;
    gotoxy(4,6);
    cprintf("Enter Player name 2 : ");
    cin>>p2name;

    clrscr();
    border();

    char mark;
    do
    {
	board();

	gotoxy(45,5);
	cprintf("   %s  (X)  -  %s  (O)",p1name,p2name);
	player = (player % 2) ? 1 : 2;

	if(player==1)
	{
	 gotoxy(4,4);
	 cprintf("%s Enter a number : ",p1name);
	 scanf("%d",&choice);
	}
	else
	{
	 gotoxy(4,6);
	 cprintf("%s Enter a number : ",p2name);
	 scanf("%d", &choice);
	}

	mark = (player == 1) ? 'X' : 'O';

	if (choice == 1 && square[1] == '1')
	    square[1] = mark;

	else if (choice == 2 && square[2] == '2')
	    square[2] = mark;

	else if (choice == 3 && square[3] == '3')
	    square[3] = mark;

	else if (choice == 4 && square[4] == '4')
	    square[4] = mark;

	else if (choice == 5 && square[5] == '5')
	    square[5] = mark;

	else if (choice == 6 && square[6] == '6')
	    square[6] = mark;

	else if (choice == 7 && square[7] == '7')
	    square[7] = mark;

	else if (choice == 8 && square[8] == '8')
	    square[8] = mark;

	else if (choice == 9 && square[9] == '9')
	    square[9] = mark;

	else
	{
	    gotoxy(4,11);
	    cprintf("   Invalid move ");

	    player--;
	    getch();
	}
	i = checkwin();

	player++;

    }while (i ==  - 1);

    board();

    if (i == 1)
      {
	int play_again;
	gotoxy(4,15);
	cprintf("   ==>Player %d win ", --player);
       /*gotoxy(4,16);
	cprintf("If you Want to play again : ");
	gotoxy(4,17);
	cprintf("press 1 , exit [0] :");
	scanf("%d",&play_again);
	if(play_again == 1)
	    goto restart;
	else
	  exit(0); */
      }
    else

	{
	 int play_again1;
	   gotoxy(4,15);
	   cprintf("   ==>Game draw");
       /*
	gotoxy(4,16);
	cprintf("If you Want to play again : ");
	gotoxy(4,17);
	cprintf("press 1 , exit [0] :");
	scanf("%d",&play_again1);
	if(play_again1 == 1)
	    goto restart;
	else
	  exit(0);  */
	}
    getch();

    return 0;
}

int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])
	return 1;

    else if (square[4] == square[5] && square[5] == square[6])
	return 1;

    else if (square[7] == square[8] && square[8] == square[9])
	return 1;

    else if (square[1] == square[4] && square[4] == square[7])
	return 1;

    else if (square[2] == square[5] && square[5] == square[8])
	return 1;

    else if (square[3] == square[6] && square[6] == square[9])
	return 1;

    else if (square[1] == square[5] && square[5] == square[9])
	return 1;

    else if (square[3] == square[5] && square[5] == square[7])
	return 1;

    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
	square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
	!= '7' && square[8] != '8' && square[9] != '9')

	return 0;
    else
	return  - 1;
}


/*******************************************************************
FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
 ********************************************************************/


void board()
{


    gotoxy(28,2);
    cprintf(" Tic Tac Toe");

    gotoxy(50,8);
    cprintf("|     |     |     |\n");
    gotoxy(50,9);
    cprintf("|  %c  |  %c  |  %c  |\n", square[1], square[2], square[3]);

    gotoxy(50,10);
    cprintf("|_____|_____|_____|\n");
    gotoxy(50,11);
    cprintf("|     |     |     |\n");
    gotoxy(50,12);
    cprintf("|  %c  |  %c  |  %c  |\n", square[4], square[5], square[6]);
    gotoxy(50,13);
    cprintf("|_____|_____|_____|\n");
    gotoxy(50,14);
    cprintf("|     |     |     |\n");
    gotoxy(50,15);
    cprintf("|  %c  |  %c  |  %c  |\n", square[7], square[8], square[9]);
    gotoxy(50,16);
    cprintf("|     |     |     |\n");

}