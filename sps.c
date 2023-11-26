#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdlib.h>
#include <conio.h>
int difference(int x, int y)
{
    if(x < y)   return y - x;
    else        return x - y;
}
int main()
{
    int matches = 5;
    int draw = 0;
    int win = 0;
    int loss = 0;
    int infinity = 0;
    printf("\n   SPS Tournament - %d Matches", matches);        getch();
    printf("\n\n");
    for(int i = 1; i <= matches; i++)
    {
        srand(time(0));
        if(i == 3 && win == 2 && draw == 0 && loss == 0)         printf("\n   Stone(1) Paper(2) Scissors(3)        Tournament Winning Match - %d", i);
        else if(i == 3 && win == 0 && draw == 0 && loss == 2)    printf("\n   Stone(1) Paper(2) Scissors(3)        Do - or - Die Match - %d", i);
        else if(i == 3 && win == 2 && draw == 0 && loss == 0)    printf("\n   Stone(1) Paper(2) Scissors(3)        Tournament Winning Match - %d", i);
        else if(i == 4 && win == 2 && draw == 1 && loss == 0)    printf("\n   Stone(1) Paper(2) Scissors(3)        Tournament Winning Match - %d", i);
        else if(i == 4 && win == 0 && draw == 2 && loss == 1)    printf("\n   Stone(1) Paper(2) Scissors(3)        Do - or - Die Match - %d", i);
        else if(i == 4 && win == 1 && draw == 0 && loss == 2)    printf("\n   Stone(1) Paper(2) Scissors(3)        Do - or - Die Match - %d", i);
        else if(i == 4 && win == 2 && draw == 0 && loss == 1)    printf("\n   Stone(1) Paper(2) Scissors(3)        Tournament Winning Match - %d", i);
        else if(i == 4 && win == 1 && draw == 2 && loss == 0)    printf("\n   Stone(1) Paper(2) Scissors(3)        Tournament Winning Match - %d", i);
        else if(i == 4 && win == 0 && draw == 1 && loss == 2)    printf("\n   Stone(1) Paper(2) Scissors(3)        Do - or - Die Match - %d", i);
        else if(i == 5 && difference(win, loss) == 1)
        {
            if(win == loss + 1)
            {
                printf("\n   Stone(1) Paper(2) Scissors(3)        SPS - Infinity War");
                infinity++;
            }
            else
            {
                printf("\n   Stone(1) Paper(2) Scissors(3)        Do - or - Die Match - %d", i);
            }
        }
        else if(i == 5 && win == loss)                           printf("\n   Stone(1) Paper(2) Scissors(3)        Final Match");
        else                                                     printf("\n   Stone(1) Paper(2) Scissors(3)        Match - %d", i);
        printf("\n\n   You : ");
        int x;
        scanf("%d", &x);
        int y = (rand()%3) + 1;
        if(i == 5 && difference(win, loss) == 1 && win == loss + 1)
        {
            if(x == 1)      y = 2;
            else if(x == 2) y = 3;
            else if(x == 3) y = 1;
        }
        printf("   AI  : %d", y);
        if(x == y)
        {
            printf("\n\n   .. Draw ..");        getch();
            printf("\n\n");
            draw++;
        }
        else if((x == 1 && y == 2) || (x == 2 && y == 3) || (x == 3 && y == 1))
        {
            printf("\n\n   # Defeat #");        getch();
            printf("\n\n");
            loss++;
        }
        else if((x == 1 && y == 3) || (x == 2 && y == 1) || (x == 3 && y == 2))
        {
            printf("\n\n   !! Victory !!");     getch();
            printf("\n\n");
            win++;
        }
    }
    lable :
    if(win == loss)
    {

        if(infinity == 0)       printf("\n   Stone(1) Paper(2) Scissors(3)        Final Match");
        else if(infinity == 1)  printf("\n   Stone(1) Paper(2) Scissors(3)        SPS - Endgame");
        printf("\n\n   You : ");
        int x;
        scanf("%d", &x);
        int y = (rand()%3) + 1;
        printf("   AI  : %d", y);
        if(x == y)
        {
            printf("\n\n   .. Draw ..");        getch();
            printf("\n\n");
            draw++;
            goto lable;
        }
        else if((x == 1 && y == 2) || (x == 2 && y == 3) || (x == 3 && y == 1))
        {
            printf("\n\n   # Defeat #");        getch();
            printf("\n\n");
            loss++;
        }
        else if((x == 1 && y == 3) || (x == 2 && y == 1) || (x == 3 && y == 2))
        {
            printf("\n\n   !! Victory !!");     getch();
            printf("\n\n");
            win++;
        }
        exit(0);
    }
    else if(win > loss)     printf("\n--------------- Tournament - Won ----------------\n\n");
    else                    printf("\n--------------- Tournament - Loss ---------------\n\n");  getch();
    return 0;
}