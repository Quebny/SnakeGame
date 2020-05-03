#include <iostream>
#include <conio.h>
#include <windows.h>


using namespace std;
//Variables Globales
int snakeX[100];
int snakeY[100];
int snakeSize=3;
int snake_x=5;
int snake_y=3;
int fruit=65;
int fruitX;
int fruitY;
int speed=100;
int score=0;
bool eaten=true;
bool alive=true;
int X; int Y;
int direccion=4; //1 arriba, 2 abajo, 3 izq, 4 der

void drawSnake()
{

    for (int i=0;i<snakeSize;i++)
    {
    textbackground(GREEN);
    textcolor(YELLOW);
        if(i==0)
        {
            textbackground(RED);
        }
        gotoxy(snakeX[i],snakeY[i]);
        cprintf("@");
    }
}
void moveSnake()
{
    gotoxy(snakeX[snakeSize-1],snakeY[snakeSize-1]);
    cout<<" ";

    for(int i=snakeSize-1;i>0;i--)
    {
        snakeX[i]=snakeX[i-1];
        snakeY[i]=snakeY[i-1];
    }

    switch(direccion)
    {
        case 1:
            snakeY[0]--;
        break;
        case 2:
            snakeY[0]++;
        break;
        case 3:
            snakeX[0]--;
        break;
        case 4:
            snakeX[0]++;
        break;
    }
}

int main()
{
    srand(time(NULL));
    int j;
    for (j = 1; j < 80; j++)
    {
      gotoxy(j, 1);
      printf("%c", 177);

      gotoxy(j, 35);
      printf("%c", 177);
    }

  int d;
  for (d = 2; d < 35; d++)
    {
        gotoxy(1, d);
        printf("%c", 178);

        gotoxy(79, d);
        printf("%c", 178);
    }
    gotoxy(1, 1);
    printf("%c", 02);

    gotoxy(79, 1);
    printf("%c", 02);

    gotoxy(1, 35);
    printf("%c", 01);

    gotoxy(79, 35);
    printf("%c", 01);


    for(int i=0;i<100;i++)
    {
        snakeX[i]=1;
        snakeY[i]=1;
    }
    snakeX[0]=5;
    snakeY[0]=5;

    snakeX[1]=4;
    snakeY[1]=5;

    snakeX[2]=3;
    snakeY[2]=5;

    drawSnake();
    while(alive==true)
    {
        /*119 arriba
         *115 abajo
         *97  izquierda
         *100 derecha */


        if(kbhit())
        {
            int movement=(int)getch();
            switch(movement)
            {
                case 119:
                    direccion=1;
                break;
                case 115:
                    direccion=2;
                break;
                case 97:
                    direccion=3;
                break;
                case 100:
                    direccion=4;
                break;
            }
        }

        gotoxy(85,5);
        cout<<"SCORE: "<<score;
                                        //FRUITXY DEBUGGING
                                        gotoxy(85,7);
                                        if (fruitX<10)
                                            cout<<"0";
                                        cout<<fruitX;
                                        gotoxy(85,8);
                                        if (fruitY<10)
                                            cout<<"0";
                                        cout<<fruitY;
        if(eaten==true)
        {
            fruitX=(rand()%76)+2;
            fruitY=(rand()%32)+2;
            gotoxy(fruitX,fruitY);
            cout<<"A";
            eaten=false;
        }
        if(fruitX==snakeX[0]&&fruitY==snakeY[0])
            {
                eaten=true;
                if(30<speed)
                    speed=speed-5;
                snakeSize++;
                score++;
            }
        for(int i=1;i<snakeSize;i++)
        {
            if(fruitX==snakeX[i]&&fruitY==snakeY[i])
            {
                fruitX=(rand()% 76)+3;
                fruitY=(rand()% 33)+2;
                gotoxy(fruitX,fruitY);
                cout<<"B";
            }
        }
        moveSnake();
        drawSnake();
        Sleep(speed);
        if (snakeY[0]==35 || snakeY[0]==1 || snakeX[0]==79 || snakeX[0]==1)
            alive=false;
        for(int i=1;i<snakeSize;i++)
            if(snakeX[0]==snakeX[i]&&snakeY[0]==snakeY[i])
                alive=false;
    }
    getch();
    return 0;
}
