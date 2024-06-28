#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
void gotoxy(int x, int y)                                                          
{
 COORD pos ={x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
};

int main()
{
	int x = 46;
	const int y = 20;
	//x and y variables for slider/man.
	int y1; 
	y1 = y;
	//y1 variable for shooter.
	char c, c1;
	//c is variable for a-d-w movement and c1 is variable for ball.
	const int character = 1;
	//character is variable for slider/man.
	int x2, y2;
	y2 = 10;
	x2 = 3;
	//x2 and y2 are variables for ball movement.
	int count1 = 0, count2 = 0;
	int count=0;
	char character2=79;
	//character2 is variable for ball appearance.
	int score=0;
	int check = 0;
	//score is variable for score and check is variable for lives.
	printf("\n\n\t\tYOU MUST SCORE 5 POINTS TO WIN THE GAME! SHOOT LASER WRONGLY FIVE TIMES AND YOU LOSE!\n\t\t\t\t\t\t GOOD LUCK!");
	//while conditions are that the loop will continue unless the score is 5 or the lives lost are 5.
	while(check != 5 && score < 5)
	{
		if(c != 'w')
		{
			system("cls");
		}
		//if we do not keep this condition, the screen will be cleared when w is pressed and the shooter will not show.
		int xs=40,ys=5;
		printf("\n\n\t\tYOU MUST SCORE 5 POINTS TO WIN THE GAME! SHOOT LASER WRONGLY FIVE TIMES AND YOU LOSE!\n\t\t\t\t\t\t GOOD LUCK!");
		gotoxy(xs,ys);
		//to print scoreboard
		printf("SCORE:\t%d",score);
	    gotoxy(x2,y2);
	    //to print ball.
	    printf("%c",character2);
	    gotoxy(x,y);
	    //to print slider/man.
	    printf("%c",character);
	    c = getch();
	    if(c == 'd')
	    {
	    	//slider/man shall move to the right.
    		x = x + 2;
    	}
    	if(c == 'a')
    	{
    		//slider/man shall move to the left.
    		x = x - 2;
		}
		if(c == 'w')
		{
			count = count - 1;
			if(count <= 0)
			{
				system("cls");
			}
			//to clear the shooter after it has been shot.
			while( y1 >= 5)
			//to shoot a line of 15 units in y direction (shooter)
			{
				gotoxy(x,y1);
			    printf("|");
			    //shoot one beam of shooter.
			    y1--;
			    //to raise the beam by one y unit.
			    if(y1 == y2 && x == x2+1)
			    //when w is pressed, the ball has already moved one unit, thus it is important to compare the x coordinate of slider with the ball's x coordinate.
			    {
			    	//if the beam hits the ball.
			        printf("\aYOU GOT IT");
			        score=score+1;
			        break;
		    	}
			}
			if(y1 != y2 && x != x2 + 1)
		    	{
		    		//if shooter beam does not hit the ball.
		    		check = check + 1;
		    		gotoxy(100,5);
		    		//placement of lives lost announcement.
		    		printf("%d LIVE(S) LOST %c",check,3);
				}
			//revert the shooter's y variable back to it's orginal value for next move.
			y1 = y;
		}
    	if(c == ' ')
    	{
    		//to forfiet the game, the user presses space.
    		return 0;
		}
		//to revert the ball back into frame after moving to extreme right or left.
		if(x2 < 116 && count1<50)
		{ 
		//to prevent the ball from being decremented and incremented again and again and remaining fixed in two x coordinates.
	    	x2++;
	    	count1 = count1 + 1;
	    	if(count1 == 49)
	    	{
	    		count1 = 0;
			}
		}
		else
		{
			x2--;
		}
		if(x2 == 115)
		{
			//revert the ball back to its original position to start movement again.
			x2 = 3;
			y2 = 10;
		}
	    if(y2<20 && count2<=10)
	    {
	    	//movement of ball in y direction downwards until it reaches the ground level (where the slider/man is).
	    	y2++;
	    	count2 = count2 + 1;
		}
		else
		{
			//movement of ball in y direction upwards until it reaches the starting y coordinate.
			y2--;
			count2 = count2 + 1;
			if(count2 == 21)
			{
				//to maintain the oscillatory movement
				count2 = 0;
				y2 = 10;
			}
		}
	}
	//conditions for status of game: win or lose.
	if(check == 5)
	{
		system("cls");
		//clear the screen and show the losing message.
		printf("\n\n\n\n\n\t\tYOU LOST THE GAME. BETTER LUCK NEXT TIME! :(");
	}
	else if(score == 5)
	{
		system("cls");
		//clear the screen and show the winning message.
		printf("\n\n\n\n\n\n\t\tYOU WON THE GAME! CONGRATULATIONS!! :))");
	}
}
