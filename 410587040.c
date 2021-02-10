#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <conio.h>

char screen[30][110], hero[20];
char player[6][6];
int x=1, y=1;
int hp, atk, def, rcv, money, score;

void moveup(void);
void movedown(void);
void moveleft(void);
void moveright(void);
void gotoxy(int,int);
void clean_screen(void);
void border(void);
void print_screen(void);
void player_body(int x,int y);
void move_player(char);
void player_body_clear(int x, int y);
void obstacle_screen(void);
void flag(void);
void win(void);
void data(void);
void start(void);
void introduce(void);
void item(void);
void pickup_item(void);
void round(void);
void printfxy(void);
void round1(void);
void round2(void);
void round3(void);
void round4(void);
void easter_egg(void);
void again(void);
void dead(void);

int main(void)
{
    int ch1,ch2;
    char keyboard_stdin;//儲存鍵盤輸入的動作
    fflush(stdin);
    x=1,y=1;
    start();
    clean_screen();
    border();
    flag();
    obstacle_screen();
    item();
    player_body(x,y);
    for(;;)
    {
        system("cls");
        dead();
        win();//清屏幕後最先判定
        data();
        printfxy();
        pickup_item();
        round();
        print_screen();

        ch1 = getch();
        switch(ch1)
        {
        case 0xE0:
            switch(ch2=getch())
            {
                case 72:  moveup(); break;
                case 80:  movedown(); break;
                case 75:  moveleft(); break;
                case 77:  moveright(); break;
                default:
                    break;
            }
            break;
        default:
            break;
        }
   }

    return 0;
}
void item(void)
{
    int i, j;

    for(i=4;i<6;i++)
    {
        screen[28][i]='$';
    }
    screen[7][22]='A';
    screen[7][23]='A';

    screen[22][22]='D';
    screen[22][23]='D';
    screen[4][93]='D';
    screen[4][94]='D';
    for(i=38;i<40;i++)
    {
        screen[8][i]='$';
    }
    screen[26][59]='$';
    screen[27][59]='$';
    screen[2][38]='R';
    screen[3][38]='R';

    screen[26][23]='X';
    screen[27][23]='X';

    screen[7][58]='X';
    screen[7][59]='X';


    screen[2][49]='$';
    screen[3][49]='$';

    screen[25][93]='A';
    screen[26][93]='A';

    screen[15][24]='?';//第1關
    screen[16][24]='?';

    screen[21][38]='?';//第2關
    screen[21][39]='?';

    screen[26][77]='?';//第3關
    screen[27][77]='?';

    screen[17][77]='?';//第4關
    screen[17][78]='?';
}
void pickup_item(void)
{
    //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
    if(screen[x+5][y]=='$')//用下面第1格
    {
        if(screen[x+5][y]==screen[28][4])
        {
            money=money+100;
            Beep(1048,100);
            Beep(1320,100);
            Beep(1568,300);
            screen[28][4]=' ';
            screen[28][5]=' ';
        }
        else
            money=money+0;
    }

    if(screen[x+5][y+1]=='$')//用下面第2格
    {
        if(screen[x+5][y+1]==screen[28][4])
        {
            money=money+100;
            Beep(1048,100);
            Beep(1320,100);
            Beep(1568,300);
            screen[28][4]=' ';
            screen[28][5]=' ';
        }
        else
            money=money+0;
    }

    if(screen[x+5][y+2]=='$')//用下面第3格
    {
        if(screen[x+5][y+2]==screen[28][4])
        {
            money=money+100;
            Beep(1048,100);
            Beep(1320,100);
            Beep(1568,300);
            screen[28][4]=' ';
            screen[28][5]=' ';
        }
        else
            money=money+0;
    }

    if(screen[x+5][y+3]=='$')//用下面第4格
    {
        if(screen[x+5][y+3]==screen[28][4])
        {
            money=money+100;
            Beep(1048,100);
            Beep(1320,100);
            Beep(1568,300);
            screen[28][4]=' ';
            screen[28][5]=' ';
        }
        else
            money=money+0;
    }

    if(screen[x-1][y]=='$')//用上面第1格
    {
        if(screen[x-1][y]==screen[8][38])
        {
            money=money+100;
            Beep(1048,100);
            Beep(1320,100);
            Beep(1568,300);
            screen[8][38]=' ';
            screen[8][39]=' ';
        }
        else
            money=money+0;
    }
    if(screen[x-1][y+1]=='$')//用上面第2格
    {
        if(screen[x-1][y+1]==screen[8][38])
        {
            money=money+100;
            Beep(1048,100);
            Beep(1320,100);
            Beep(1568,300);
            screen[8][38]=' ';
            screen[8][39]=' ';
        }
        else
            money=money+0;
    }
    if(screen[x-1][y+2]=='$')//用上面第3格
    {
        if(screen[x-1][y+2]==screen[8][38])
        {
            money=money+100;
            Beep(1048,100);
            Beep(1320,100);
            Beep(1568,300);
            screen[8][38]=' ';
            screen[8][39]=' ';
        }
        else
            money=money+0;
    }
    if(screen[x-1][y+3]=='$')//用上面第4格
    {
        if(screen[x-1][y+3]==screen[8][38])
        {
            money=money+100;
            Beep(1048,100);
            Beep(1320,100);
            Beep(1568,300);
            screen[8][38]=' ';
            screen[8][39]=' ';
        }
        else
            money=money+0;
    }

    if(screen[x][y-1]=='$')//用左面第1格
    {
        if(screen[x][y-1]==screen[2][49])
        {
            money=money+100;
            Beep(1048,100);
            Beep(1320,100);
            Beep(1568,300);
            screen[2][49]=' ';
            screen[3][49]=' ';
        }
        else
            money=money+0;
    }
    if(screen[x+1][y-1]=='$')//用左面第2格
    {
        if(screen[x+1][y-1]==screen[2][49])
        {
            money=money+100;
            Beep(1048,100);
            Beep(1320,100);
            Beep(1568,300);
            screen[2][49]=' ';
            screen[3][49]=' ';
        }
        else
            money=money+0;
    }
    if(screen[x+2][y-1]=='$')//用左面第3格
    {
        if(screen[x+2][y-1]==screen[2][49])
        {
            money=money+100;
            Beep(1048,100);
            Beep(1320,100);
            Beep(1568,300);
            screen[2][49]=' ';
            screen[3][49]=' ';
        }
        else
            money=money+0;
    }
    if(screen[x+3][y-1]=='$')//用左面第4格
    {
        if(screen[x+3][y-1]==screen[2][49])
        {
            money=money+100;
            Beep(1048,100);
            Beep(1320,100);
            Beep(1568,300);
            screen[2][49]=' ';
            screen[3][49]=' ';
        }
        else
            money=money+0;
    }
    if(screen[x+4][y-1]=='$')//用左面第5格
    {
        if(screen[x+4][y-1]==screen[2][49])
        {
            money=money+100;
            Beep(1048,100);
            Beep(1320,100);
            Beep(1568,300);
            screen[2][49]=' ';
            screen[3][49]=' ';
        }
        else
            money=money+0;
    }

    if(screen[x][y+4]=='$')//用右面第1格
    {
        if(screen[x][y+4]==screen[26][59])
        {
            money=money+100;
            Beep(1048,100);
            Beep(1320,100);
            Beep(1568,300);
            screen[26][59]=' ';
            screen[27][59]=' ';
        }
        else
            money=money+0;
    }
    if(screen[x+1][y+4]=='$')//用右面第2格
    {
        if(screen[x+1][y+4]==screen[26][59])
        {
            money=money+100;
            Beep(1048,100);
            Beep(1320,100);
            Beep(1568,300);
            screen[26][59]=' ';
            screen[27][59]=' ';
        }
        else
            money=money+0;
    }
    if(screen[x+2][y+4]=='$')//用右面第3格
    {
        if(screen[x+2][y+4]==screen[26][59])
        {
            money=money+100;
            Beep(1048,100);
            Beep(1320,100);
            Beep(1568,300);
            screen[26][59]=' ';
            screen[27][59]=' ';
        }
        else
            money=money+0;
    }
    if(screen[x+3][y+4]=='$')//用右面第4格
    {
        if(screen[x+3][y+4]==screen[26][59])
        {
            money=money+100;
            Beep(1048,100);
            Beep(1320,100);
            Beep(1568,300);
            screen[26][59]=' ';
            screen[27][59]=' ';
        }
        else
            money=money+0;
    }
    if(screen[x+4][y+4]=='$')//用右面第5格
    {
        if(screen[x+4][y+4]==screen[26][59])
        {
            money=money+100;
            Beep(1048,100);
            Beep(1320,100);
            Beep(1568,300);
            screen[26][59]=' ';
            screen[27][59]=' ';
        }
        else
            money=money+0;
    }

    //AAAAAAAAAAAAAAAAAAAAAAAAAA
    if(screen[x-1][y]=='A')//用上面第1格
    {
        if(screen[x-1][y]==screen[7][22])
        {
            atk=atk+20;
            Beep(1048,100);
            Beep(1320,100);
            Beep(1568,300);
            screen[7][22]=' ';
            screen[7][23]=' ';
        }
        else
            atk=atk+0;
    }
    if(screen[x-1][y+1]=='A')//用上面第2格
    {
        if(screen[x-1][y+1]==screen[7][22])
        {
            atk=atk+20;
            Beep(1048,100);
            Beep(1320,100);
            Beep(1568,300);
            screen[7][22]=' ';
            screen[7][23]=' ';
        }
        else
            atk=atk+0;
    }
    if(screen[x-1][y+2]=='A')//用上面第3格
    {
        if(screen[x-1][y+2]==screen[7][22])
        {
            atk=atk+20;
            Beep(1048,100);
            Beep(1320,100);
            Beep(1568,300);
            screen[7][22]=' ';
            screen[7][23]=' ';
        }
        else
            atk=atk+0;
    }
    if(screen[x-1][y+3]=='A')//用上面第4格
    {
        if(screen[x-1][y+3]==screen[7][22])
        {
            atk=atk+20;
            Beep(1048,100);
            Beep(1320,100);
            Beep(1568,300);
            screen[7][22]=' ';
            screen[7][23]=' ';
        }
        else
            atk=atk+0;
    }

    if(screen[x][y+4]=='A')//用右面第1格
    {
        if(screen[x][y+4]==screen[25][93])
        {
            atk=atk+20;
            Beep(1048,100);
            Beep(1320,100);
            Beep(1568,300);
            screen[25][93]=' ';
            screen[26][93]=' ';
        }
        else
            atk=atk+0;
    }
    if(screen[x+1][y+4]=='A')//用右面第2格
    {
        if(screen[x+1][y+4]==screen[25][93])
        {
            atk=atk+20;
            Beep(1048,100);
            Beep(1320,100);
            Beep(1568,300);
            screen[25][93]=' ';
            screen[26][93]=' ';
        }
        else
            atk=atk+0;
    }
    if(screen[x+2][y+4]=='A')//用右面第3格
    {
        if(screen[x+2][y+4]==screen[25][93])
        {
            atk=atk+20;
            Beep(1048,100);
            Beep(1320,100);
            Beep(1568,300);
            screen[25][93]=' ';
            screen[26][93]=' ';
        }
        else
            atk=atk+0;
    }
    if(screen[x+3][y+4]=='A')//用右面第4格
    {
        if(screen[x+3][y+4]==screen[25][93])
        {
            atk=atk+20;
            Beep(1048,100);
            Beep(1320,100);
            Beep(1568,300);
            screen[25][93]=' ';
            screen[26][93]=' ';
        }
        else
            atk=atk+0;
    }
    if(screen[x+4][y+4]=='A')//用右面第5格
    {
        if(screen[x+4][y+4]==screen[25][93])
        {
            atk=atk+20;
            Beep(1048,100);
            Beep(1320,100);
            Beep(1568,300);
            screen[25][93]=' ';
            screen[26][93]=' ';
        }
        else
            atk=atk+0;
    }

    //DDDDDDDDDDDDDDDDDDDDDDDD
    if(screen[x-1][y]=='D')//用上面第1格
    {
        if(screen[x-1][y]==screen[4][93])
        {
            def=def+10;
            Beep(1048,100);
            Beep(1320,100);
            Beep(1568,300);
            screen[4][93]=' ';
            screen[4][94]=' ';
        }
        else
            def=def+0;
    }
    if(screen[x-1][y+1]=='D')//用上面第2格
    {
        if(screen[x-1][y+1]==screen[4][93])
        {
            def=def+10;
            Beep(1048,100);
            Beep(1320,100);
            Beep(1568,300);
            screen[4][93]=' ';
            screen[4][94]=' ';
        }
        else
            def=def+0;
    }
    if(screen[x-1][y+2]=='D')//用上面第3格
    {
        if(screen[x-1][y+2]==screen[4][93])
        {
            def=def+10;
            Beep(1048,100);
            Beep(1320,100);
            Beep(1568,300);
            screen[4][93]=' ';
            screen[4][94]=' ';
        }
        else
            def=def+0;
    }
    if(screen[x-1][y+3]=='D')//用上面第4格
    {
        if(screen[x-1][y+3]==screen[4][93])
        {
            def=def+10;
            Beep(1048,100);
            Beep(1320,100);
            Beep(1568,300);
            screen[4][93]=' ';
            screen[4][94]=' ';
        }
        else
            def=def+0;
    }

    if(screen[x][y+4]=='D')//用右面第1格
    {
        if(screen[x][y+4]==screen[4][93])
        {
            def=def+10;
            Beep(1048,100);
            Beep(1320,100);
            Beep(1568,300);
            screen[4][93]=' ';
            screen[4][94]=' ';
        }
        else
            def=def+0;
    }
    if(screen[x+1][y+4]=='D')//用右面第2格
    {
        if(screen[x+1][y+4]==screen[4][93])
        {
            def=def+10;
            Beep(1048,100);
            Beep(1320,100);
            Beep(1568,300);
            screen[4][93]=' ';
            screen[4][94]=' ';
        }
        else
            def=def+0;
    }
    if(screen[x+2][y+4]=='D')//用右面第3格
    {
        if(screen[x+2][y+4]==screen[4][93])
        {
            def=def+10;
            Beep(1048,100);
            Beep(1320,100);
            Beep(1568,300);
            screen[4][93]=' ';
            screen[4][94]=' ';
        }
        else
            def=def+0;
    }
    if(screen[x+3][y+4]=='D')//用右面第4格
    {
        if(screen[x+3][y+4]==screen[4][93])
        {
            def=def+10;
            Beep(1048,100);
            Beep(1320,100);
            Beep(1568,300);
            screen[4][93]=' ';
            screen[4][94]=' ';
        }
        else
            def=def+0;
    }
    if(screen[x+4][y+4]=='D')//用右面第5格
    {
        if(screen[x+4][y+4]==screen[4][93])
        {
            def=def+10;
            Beep(1048,100);
            Beep(1320,100);
            Beep(1568,300);
            screen[4][93]=' ';
            screen[4][94]=' ';
        }
        else
            def=def+0;
    }

    if(screen[x+5][y]=='D')//用下面第1格
    {
        if(screen[x+5][y]==screen[22][22])
        {
            def=def+10;
            Beep(1048,100);
            Beep(1320,100);
            Beep(1568,300);
            screen[22][22]=' ';
            screen[22][23]=' ';
        }
        else
            def=def+0;
    }

    if(screen[x+5][y+1]=='D')//用下面第2格
    {
        if(screen[x+5][y+1]==screen[22][22])
        {
            def=def+10;
            Beep(1048,100);
            Beep(1320,100);
            Beep(1568,300);
            screen[22][22]=' ';
            screen[22][23]=' ';
        }
        else
            def=def+0;
    }

    if(screen[x+5][y+2]=='D')//用下面第3格
    {
        if(screen[x+5][y+2]==screen[22][22])
        {
            def=def+10;
            Beep(1048,100);
            Beep(1320,100);
            Beep(1568,300);
            screen[22][22]=' ';
            screen[22][23]=' ';
        }
        else
            def=def+0;
    }

    if(screen[x+5][y+3]=='D')//用下面第4格
    {
        if(screen[x+5][y+3]==screen[22][22])
        {
            def=def+10;
            Beep(1048,100);
            Beep(1320,100);
            Beep(1568,300);
            screen[22][22]=' ';
            screen[22][23]=' ';
        }
        else
            def=def+0;
    }

    //RRRRRRRRRRRRRRRRRRRRRRR
    if(screen[x][y-1]=='R')//用左面第1格
    {
        if(screen[x][y-1]==screen[2][38])
        {
            rcv=rcv+15;
            Beep(1048,100);
            Beep(1320,100);
            Beep(1568,300);
            screen[2][38]=' ';
            screen[3][38]=' ';
        }
        else
            rcv=rcv+0;
    }
    if(screen[x+1][y-1]=='R')//用左面第2格
    {
        if(screen[x+1][y-1]==screen[2][38])
        {
            rcv=rcv+15;
            Beep(1048,100);
            Beep(1320,100);
            Beep(1568,300);
            screen[2][38]=' ';
            screen[3][38]=' ';
        }
        else
            rcv=rcv+0;
    }
    if(screen[x+2][y-1]=='R')//用左面第3格
    {
        if(screen[x+2][y-1]==screen[2][38])
        {
            rcv=rcv+15;
            Beep(1048,100);
            Beep(1320,100);
            Beep(1568,300);
            screen[2][38]=' ';
            screen[3][38]=' ';
        }
        else
            rcv=rcv+0;
    }
    if(screen[x+3][y-1]=='R')//用左面第4格
    {
        if(screen[x+3][y-1]==screen[2][38])
        {
            rcv=rcv+15;
            Beep(1048,100);
            Beep(1320,100);
            Beep(1568,300);
            screen[2][38]=' ';
            screen[3][38]=' ';
        }
        else
            rcv=rcv+0;
    }
    if(screen[x+4][y-1]=='R')//用左面第5格
    {
        if(screen[x+4][y-1]==screen[2][38])
        {
            rcv=rcv+15;
            Beep(1048,100);
            Beep(1320,100);
            Beep(1568,300);
            screen[2][38]=' ';
            screen[3][38]=' ';
        }
        else
            rcv=rcv+0;
    }

    //XXXXXXXXXXXXXXXXXXXXXXXXXX
    if(screen[x-1][y]=='X')//用上面第1格
    {
        if(screen[x-1][y]==screen[7][59])
        {
            hp=hp-50;
            Beep(330,1200);
            screen[7][58]=' ';
            screen[7][59]=' ';
        }
        else
            hp=hp-0;
    }
    if(screen[x-1][y+1]=='X')//用上面第2格
    {
        if(screen[x-1][y+1]==screen[7][59])
        {
            hp=hp-50;
            Beep(330,1200);
            screen[7][58]=' ';
            screen[7][59]=' ';
        }
        else
            hp=hp-0;
    }
    if(screen[x-1][y+2]=='X')//用上面第3格
    {
        if(screen[x-1][y+2]==screen[7][59])
        {
            hp=hp-50;
            Beep(330,1200);
            screen[7][58]=' ';
            screen[7][59]=' ';
        }
        else
            hp=hp-0;
    }
    if(screen[x-1][y+3]=='X')//用上面第4格
    {
        if(screen[x-1][y+3]==screen[7][59])
        {
            hp=hp-50;
            Beep(330,1200);
            screen[7][58]=' ';
            screen[7][59]=' ';
        }
        else
            hp=hp-0;
    }

    if(screen[x+5][y]=='X')//用下面第1格
    {
        if(screen[x+5][y]==screen[7][58])
        {
            hp=hp-50;
            Beep(330,1200);
            screen[7][58]=' ';
            screen[7][59]=' ';
        }
        else
            hp=hp-0;
    }

    if(screen[x+5][y+1]=='X')//用下面第2格
    {
        if(screen[x+5][y+1]==screen[7][58])
        {
            hp=hp-50;
            Beep(330,1200);
            screen[7][58]=' ';
            screen[7][59]=' ';
        }
        else
            hp=hp-0;
    }

    if(screen[x+5][y+2]=='X')//用下面第3格
    {
        if(screen[x+5][y+2]==screen[7][58])
        {
            hp=hp-50;
            Beep(330,1200);
            screen[7][58]=' ';
            screen[7][59]=' ';
        }
        else
            hp=hp-0;
    }

    if(screen[x+5][y+3]=='X')//用下面第4格
    {
        if(screen[x+5][y+3]==screen[7][58])
        {
            hp=hp-50;
            Beep(330,1200);
            screen[7][58]=' ';
            screen[7][59]=' ';
        }
        else
            hp=hp-0;
    }

    if(screen[x][y-1]=='X')//用左面第1格
    {
        if(screen[x][y-1]==screen[26][23])
        {
            hp=hp-50;
            Beep(330,1200);
            screen[26][23]=' ';
            screen[27][23]=' ';
        }
        else
            hp=hp-0;
    }
    if(screen[x+1][y-1]=='X')//用左面第2格
    {
        if(screen[x+1][y-1]==screen[26][23])
        {
            hp=hp-50;
            Beep(330,1200);
            screen[26][23]=' ';
            screen[27][23]=' ';
        }
        else
            hp=hp-0;
    }
    if(screen[x+2][y-1]=='X')//用左面第3格
    {
        if(screen[x+2][y-1]==screen[26][23])
        {
            hp=hp-50;
            Beep(330,1200);
            screen[26][23]=' ';
            screen[27][23]=' ';
        }
        else
            hp=hp-0;
    }
    if(screen[x+3][y-1]=='X')//用左面第4格
    {
        if(screen[x+3][y-1]==screen[26][23])
        {
            hp=hp-50;
            Beep(330,1200);
            screen[26][23]=' ';
            screen[27][23]=' ';
        }
        else
            hp=hp-0;
    }
    if(screen[x+4][y-1]=='X')//用左面第5格
    {
        if(screen[x+4][y-1]==screen[26][23])
        {
            hp=hp-50;
            Beep(330,1200);
            screen[26][23]=' ';
            screen[27][23]=' ';
        }
        else
            hp=hp-0;
    }


    if(screen[x][y+4]=='X')//用右面第1格
    {
        if(screen[x][y+4]==screen[26][23])
        {
            hp=hp-50;
            Beep(330,1200);
            screen[26][23]=' ';
            screen[27][23]=' ';
        }
        else
            hp=hp-0;
    }
    if(screen[x+1][y+4]=='X')//用右面第2格
    {
        if(screen[x+1][y+4]==screen[26][23])
        {
            hp=hp-50;
            Beep(330,1200);
            screen[26][23]=' ';
            screen[27][23]=' ';
        }
        else
            hp=hp-0;
    }
    if(screen[x+2][y+4]=='X')//用右面第3格
    {
        if(screen[x+2][y+4]==screen[26][23])
        {
            hp=hp-50;
            Beep(330,1200);
            screen[26][23]=' ';
            screen[27][23]=' ';
        }
        else
            hp=hp-0;
    }
    if(screen[x+3][y+4]=='X')//用右面第4格
    {
        if(screen[x+3][y+4]==screen[26][23])
        {
            hp=hp-50;
            Beep(330,1200);
            screen[26][23]=' ';
            screen[27][23]=' ';
        }
        else
            hp=hp-0;
    }
    if(screen[x+4][y+4]=='X')//用右面第5格
    {
        if(screen[x+4][y+4]==screen[26][23])
        {
            hp=hp-50;
            Beep(330,1200);
            screen[26][23]=' ';
            screen[27][23]=' ';
        }
        else
            hp=hp-0;
    }
}
void round(void)
{
    //?????????????????????????
    //第1關
    if(screen[x][y-1]=='?')//用左面第1格
    {
        if(screen[x][y-1]==screen[15][24])
        {
            printf("Round 1!\n");
            system("pause");
            round1();
            screen[15][24]=' ';
            screen[16][24]=' ';
        }
    }
    if(screen[x+1][y-1]=='?')//用左面第2格
    {
        if(screen[x+1][y-1]==screen[15][24])
        {
            printf("Round 1!\n");
            system("pause");
            round1();
            screen[15][24]=' ';
            screen[16][24]=' ';
        }

    }
    if(screen[x+2][y-1]=='?')//用左面第3格
    {
        if(screen[x+2][y-1]==screen[15][24])
        {
            printf("Round 1!\n");
            system("pause");
            round1();
            screen[15][24]=' ';
            screen[16][24]=' ';
        }
    }
    if(screen[x+3][y-1]=='?')//用左面第4格
    {
        if(screen[x+3][y-1]==screen[15][24])
        {
            printf("Round 1!\n");
            system("pause");
            round1();
            screen[15][24]=' ';
            screen[16][24]=' ';
        }
    }
    if(screen[x+4][y-1]=='?')//用左面第5格
    {
        if(screen[x+4][y-1]==screen[15][24])
        {
            printf("Round 1!\n");
            system("pause");
            round1();
            screen[15][24]=' ';
            screen[16][24]=' ';
        }
    }

    //第2關
    if(screen[x-1][y]=='?')//用上面第1格
    {
        if(screen[x-1][y]==screen[21][38])
        {
            printf("Round 2!\n");
            system("pause");
            round2();
            Beep(524,200);
            Beep(524,200);
            Beep(784,200);
            Beep(784,200);
            Beep(880,200);
            Beep(880,200);
            Beep(784,500);
            screen[21][38]=' ';
            screen[21][39]=' ';
        }
    }
    if(screen[x-1][y+1]=='?')//用上面第2格
    {
        if(screen[x-1][y+1]==screen[21][38])
        {
            printf("Round 2!\n");
            system("pause");
            round2();
            Beep(524,200);
            Beep(524,200);
            Beep(784,200);
            Beep(784,200);
            Beep(880,200);
            Beep(880,200);
            Beep(784,500);
            screen[21][38]=' ';
            screen[21][39]=' ';
        }
    }
    if(screen[x-1][y+2]=='?')//用上面第3格
    {
        if(screen[x-1][y+2]==screen[21][38])
        {
            printf("Round 2!\n");
            system("pause");
            round2();
            Beep(524,200);
            Beep(524,200);
            Beep(784,200);
            Beep(784,200);
            Beep(880,200);
            Beep(880,200);
            Beep(784,500);
            screen[21][38]=' ';
            screen[21][39]=' ';
        }
    }
    if(screen[x-1][y+3]=='?')//用上面第4格
    {
        if(screen[x-1][y+3]==screen[21][38])
        {
            printf("Round 2!\n");
            system("pause");
            round2();
            Beep(524,200);
            Beep(524,200);
            Beep(784,200);
            Beep(784,200);
            Beep(880,200);
            Beep(880,200);
            Beep(784,500);
            screen[21][38]=' ';
            screen[21][39]=' ';
        }
    }

    //第3關
    if(screen[x][y+4]=='?')//用右面第1格
    {
        if(screen[x][y+4]==screen[26][77])
        {
            printf("Round 3!\n");
            system("pause");
            round3();

            screen[26][77]=' ';
            screen[27][77]=' ';
        }
    }
    if(screen[x+1][y+4]=='?')//用右面第2格
    {
        if(screen[x+1][y+4]==screen[26][77])
        {
            printf("Round 3!\n");
            system("pause");
            round3();

            screen[26][77]=' ';
            screen[27][77]=' ';
        }
    }
    if(screen[x+2][y+4]=='?')//用右面第3格
    {
        if(screen[x+2][y+4]==screen[26][77])
        {
            printf("Round 3!\n");
            system("pause");
            round3();

            screen[26][77]=' ';
            screen[27][77]=' ';
        }
    }
    if(screen[x+3][y+4]=='?')//用右面第4格
    {
        if(screen[x+3][y+4]==screen[26][77])
        {
            printf("Round 3!\n");
            system("pause");
            round3();

            screen[26][77]=' ';
            screen[27][77]=' ';
        }
    }
    if(screen[x+4][y+4]=='?')//用右面第5格
    {
        if(screen[x+4][y+4]==screen[26][77])
        {
            printf("Round 3!\n");
            system("pause");
            round3();

            screen[26][77]=' ';
            screen[27][77]=' ';
        }
    }

    //第4關
    if(screen[x+5][y]=='?')//用下面第1格
    {
        if(screen[x+5][y]==screen[17][77])
        {
            printf("Round 4!\n");
            system("pause");
            round4();
            screen[17][77]=' ';
            screen[17][78]=' ';
        }
    }

    if(screen[x+5][y+1]=='?')//用下面第2格
    {
        if(screen[x+5][y+1]==screen[17][77])
        {
            printf("Round 4!\n");
            system("pause");
            round4();
            screen[17][77]=' ';
            screen[17][78]=' ';
        }
    }

    if(screen[x+5][y+2]=='?')//用下面第3格
    {
        if(screen[x+5][y+2]==screen[17][77])
        {
            printf("Round 4!\n");
            system("pause");
            round4();
            screen[17][77]=' ';
            screen[17][78]=' ';
        }
    }

    if(screen[x+5][y+3]=='?')//用下面第4格
    {
        if(screen[x+5][y+3]==screen[17][77])
        {
            printf("Round 4!\n");
            system("pause");
            round4();
            screen[17][77]=' ';
            screen[17][78]=' ';
        }
    }

    //EGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG
    if(screen[x-1][y]=='O')//用上面第1格
    {
        if(screen[x-1][y]==screen[14][98])
        {
            printf("You find the Easter Egg!\n");
            system("pause");
            easter_egg();
        }
    }
    if(screen[x-1][y+1]=='O')//用上面第2格
    {
        if(screen[x-1][y+1]==screen[14][98])
        {
            printf("You find the Easter Egg!\n");
            system("pause");
            easter_egg();
        }
    }
    if(screen[x-1][y+2]=='O')//用上面第3格
    {
        if(screen[x-1][y+2]==screen[14][98])
        {
            printf("You find the Easter Egg!\n");
            system("pause");
            easter_egg();
        }
    }
    if(screen[x-1][y+3]=='O')//用上面第4格
    {
        if(screen[x-1][y+3]==screen[14][98])
        {
            printf("You find the Easter Egg!\n");
            system("pause");
            easter_egg();
        }
    }
}
void win(void)
{
    if(y==97)
    {
        system("cls");
        printf("VICTORY!\n\n");
        score=hp+atk+def+rcv+money;
        printf("Score: %d\n\n", score);
        Beep(880,1000);
        Beep(988,200);
        Beep(784,200);
        Beep(880,1500);

        Beep(1048,1000);
        Beep(988,200);
        Beep(784,200);
        Beep(880,1500);
        fflush(stdin);
        again();
    }
}
void start(void)
{
    int a;
    introduce();
    system("pause");
    system("cls");
    printf("Hero: \n\n");
    printf("\t\t\t1. Wei-Xiaobao\t\t2. Shuang-Er\t\t3. Kang-Xi\t\t4. Ao-Bai\n\n");
    printf("Health Points:\t\t100\t\t\t80\t\t\t120\t\t\t90\n\n");
    printf("Attack:\t\t\t50\t\t\t30\t\t\t40\t\t\t20\n\n");
    printf("Defense:\t\t20\t\t\t40\t\t\t30\t\t\t50\n\n");
    printf("Recovery:\t\t15\t\t\t35\t\t\t5\t\t\t25\n\n\n\n");
    printf("Select your hero: ");
    scanf("%d", &a);

    switch(a)
    {
        case 1:
            strcpy(hero, "Wei-Xiaobao");
            hp=100,atk=50, def=20, rcv=15, money=100;
            break;
        case 2:
            strcpy(hero, "Shuang-Er");
            hp=80,atk=30, def=40, rcv=35, money=100;
            break;
        case 3:
            strcpy(hero, "Kang-Xi");
            hp=110,atk=40, def=30, rcv=5, money=200;
            break;
        case 4:
            strcpy(hero, "Ao-Bai");
            hp=90,atk=20, def=50, rcv=25, money=150;
            break;
        default:
            break;
    }
}
void data(void)
{
    gotoxy(0,31);
    printf("Hero: %s      HP: %d      Attack: %d      Defense: %d      Recovery: %d      Money: %d\n", hero, hp, atk, def, rcv, money);
    gotoxy(0,0);
}
void gotoxy(int xpos, int ypos)
{
  COORD scrn;
  HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
  scrn.X = xpos; scrn.Y = ypos;
  SetConsoleCursorPosition(hOuput,scrn);
}
void clean_screen(void)
{
	int i,j;
	for(i=0;i<30;i++){
		for(j=0;j<110;j++){
			screen[i][j]=' ';
		}
	}
}
void obstacle_screen(void)
{
    int i, j;
    for(i=1;i<12;i++)
    {
        screen[i][10]='0';
    }
    for(i=20;i<29;i++)
    {
        screen[i][10]='0';
    }
    for(i=6;i<24;i++)
    {
        screen[i][20]='0';
    }
    for(i=21;i<26;i++)
    {
        screen[6][i]='0';
        screen[23][i]='0';
    }
    for(i=7;i<13;i++)
    {
        screen[i][25]='0';
    }
    for(i=18;i<23;i++)
    {
        screen[i][25]='0';
    }
    for(i=1;i<24;i++)
    {
        screen[i][36]='0';
    }
    for(i=22;i<29;i++)
    {
        screen[i][41]='0';
    }
    screen[6][37]='0';
    screen[6][38]='0';
    screen[6][39]='0';
    screen[7][52]='0';
    screen[7][53]='0';
    screen[7][54]='0';
    for(i=6,j=40;i<24,j<58;i++,j++)
    {
        screen[i][j]='0';
    }
    for(i=1,j=45;i<18,j<62;i++,j++)
    {
        screen[i][j]='0';
    }
    for(i=58;i<64;i++)
    {
        screen[23][i]='0';
    }
    for(i=62;i<68;i++)
    {
        screen[17][i]='0';
    }
    for(i=13;i<24;i++)
    {
        screen[i][74]='0';
    }
    for(i=63;i<90;i++)
    {
        screen[7][i]='0';
    }
    for(i=80;i<95;i++)//egg
    {
        screen[14][i]='0';
    }
    screen[14][95]='0';
    screen[14][96]='0';
    screen[14][97]='0';
    screen[14][98]='O';
    for(i=70;i<94;i++)
    {
        screen[23][i]='0';
    }
    for(i=15;i<18;i++)
    {
        screen[i][94]='0';
    }
    for(i=23;i<29;i++)
    {
        screen[i][94]='0';
    }
}
void border(void)
{
    int i, j;
    for(i=0;i<30;i++)
    {
        i++;
        screen[i][0]='<';
        screen[i][99]='>';
    }
    for(i=0;i<30;i++)
    {
        screen[i][0]='>';
        screen[i][99]='<';
        i++;
    }
    for(j=0;j<100;j++)
    {
        screen[0][j]='_';
        screen[29][j]='_';
    }
    for(i=24;i<30;i++)
    {
        screen[i][99]=' ';
    }
}
void flag(void)
{
    int i, j;
    for(i=17;i<29;i++)
    {
        screen[i][102]='|';
    }
    screen[17][103]='\\';
    screen[18][104]='\\';
    screen[19][105]='\\';
    screen[20][106]='\\';
    screen[21][106]='/';
    screen[22][105]='/';
    screen[23][104]='/';
    screen[24][103]='/';
    screen[29][100]='=';
    screen[29][101]='=';
    screen[29][102]='=';
    screen[29][103]='=';
    screen[29][104]='=';
}
void print_screen(void)
{
    int i, j;
    for(i=0;i<30;i++){
		for(j=0;j<110;j++){
			printf("%c",screen[i][j]);
		}
		printf("\n");
	}
}
void player_body(int x, int y)
{
    screen[x][y]='='; screen[x][y+3]='=';
    screen[x+1][y]='^'; screen[x+1][y+1]='O'; screen[x+1][y+2]='O'; screen[x+1][y+3]='^';
    screen[x+2][y+1]='|'; screen[x+2][y+2]='|';
    screen[x+3][y]=92;screen[x+3][y+1]='('; screen[x+3][y+2]=')'; screen[x+3][y+3]='/';
    screen[x+4][y]='/'; screen[x+4][y+3]=92;
}
void player_body_clear(int x, int y)
{
    screen[x][y]=' '; screen[x][y+3]=' ';
    screen[x+1][y]=' '; screen[x+1][y+1]=' '; screen[x+1][y+2]=' '; screen[x+1][y+3]=' ';
    screen[x+2][y+1]=' '; screen[x+2][y+2]=' ';
    screen[x+3][y]=' ';screen[x+3][y+1]=' '; screen[x+3][y+2]=' '; screen[x+3][y+3]=' ';
    screen[x+4][y]=' '; screen[x+4][y+3]=' ';
}
void moveup(void)
{
     if(screen[x-1][y] == ' ')
        {
            if(screen[x-1][y+1] == ' ')
            {
                if(screen[x-1][y+2] == ' ')
                {
                    if(screen[x-1][y+3] == ' ')
                    {
                        player_body_clear(x, y);
                        x = x - 1;
                        player_body(x, y);
                    }
                    else
                        player_body(x, y);
                }
                else
                    player_body(x, y);
            }
            else
                player_body(x, y);
        }
    else
        player_body(x, y);
}
void movedown(void)
{
    if(screen[x+5][y] == ' ')
        {
            if(screen[x+5][y+1] == ' ')
            {
                if(screen[x+5][y+2] == ' ')
                {
                    if(screen[x+5][y+3] == ' ')
                    {
                        player_body_clear(x, y);
                        x = x + 1;
                        player_body(x, y);
                    }
                    else
                        player_body(x, y);
                }
                else
                    player_body(x, y);
            }
            else
                player_body(x, y);
        }
    else
        player_body(x, y);
}
void moveleft(void)
{
    if(screen[x][y-1] == ' ')
        {
            if(screen[x+1][y-1] == ' ')
            {
                if(screen[x+2][y-1] == ' ')
                {
                    if(screen[x+3][y-1] == ' ')
                    {
                        if(screen[x+4][y-1] == ' ')
                        {
                            player_body_clear(x, y);
                            y = y - 1;
                            player_body(x, y);
                        }
                        else
                            player_body(x, y);
                    }
                    else
                        player_body(x, y);
                }
                else
                    player_body(x, y);
            }
            else
                player_body(x, y);
        }
    else
        player_body(x, y);
}
void moveright(void)
{
    if(screen[x][y+4] == ' ')
        {
            if(screen[x+1][y+4] == ' ')
            {
                if(screen[x+2][y+4] == ' ')
                {
                    if(screen[x+3][y+4] == ' ')
                    {
                        if(screen[x+4][y+4] == ' ')
                        {
                            player_body_clear(x, y);
                            y = y + 1;
                            player_body(x, y);
                        }
                        else
                            player_body(x, y);
                    }
                    else
                        player_body(x, y);
                }
                else
                    player_body(x, y);
            }
            else
                player_body(x, y);
        }
    else
        player_body(x, y);
}
void printfxy(void)
{
    gotoxy(0,30);
    printf("(%d,%d)", x, y);
    gotoxy(0,0);
}
void round1(void)
{
    system("cls");
    system( "c:\\TermProject\\soap.exe" );
}

void round2(void)
{
    system("cls");
    system( "c:\\TermProject\\pushbox.exe" );
}

void round3(void)
{
    int count=6;
    srand(time(NULL));
    int result = (rand()%100)+1;
    int answer;
    int num;
    int i;
    system("cls");

    printf("   OGCOGCOGCOGCOGCOGCOGCOGCOGC\n\n");
    printf("        Guess Number Game  \n\n");
    printf("   OGCOGCOGCOGCOGCOGCOGCOGCOGC\n\n\n");
    printf("Game rules:\n\n");
    printf("1.There is a number between 1~100.\n\n");
    printf("2.You have 6 times chances to guess.\n\n");
    printf("3.If the number you guess is smaller than the answer, the system will print 'Bigger'.\n\n");
    printf("4.If the number you guess is bigger than the answer, the system will print 'Smaller'.\n\n");
    printf("5.If you bingo, the award is: Money+1000, and HP*1.5 !\n\n");
    printf("6.If you don't hit the answer, the punishment is: HP-50 !\n\n\n");
    system("pause");
    printf("\n\n");

    for(i=1;i<=count;i++)
    {
        num=i;
        printf("Enter the number you guess:  ");
        scanf("%d", &answer);
        if(answer==result)
        {
            printf("\n\nCongratulations, Bingo!\n");
            printf("Total guessed %d times.\n\n", i);
            printf("Your award is: Money+1000, and HP*1.5!\n\n\n");
            Beep(524,200);
            Beep(524,200);
            Beep(784,200);
            Beep(784,200);
            Beep(880,200);
            Beep(880,200);
            Beep(784,500);
            money=money+1000;
            hp=hp*1.5;
            system("pause");
            system("cls");
            break;
        }
        else
        {
            if(answer<result)
                printf("Bigger, you still have %d chance.\n\n\n", 6-num);
            if(answer>result)
                printf("Smaller, you still have %d chance.\n\n\n", 6-num);
        }
    }
    if(num==6 && answer!=result)
    {
        printf("Game over......\n");
        printf("The answer is : %d\n\n", result);
        printf("Your punishment is: HP-50! = =\n\n\n");
        Beep(494,500);
        Beep(392,500);
        Beep(330,500);
        hp=hp-50;
        system("pause");
        system("cls");
    }
}
void round4(void)
{
    int i;
    int runTime=5;
    int die1;
    int die2;
    int die3;
    int temp;
    int total;
    char guess;
    int count = 0;
    int e=0, f=0;
    srand(time(NULL));

    die1 = ( (rand() % 6) + 1);
    die2 = ( (rand() % 6) + 1);
    die3 = ( (rand() % 6) + 1);
    total = (die1 + die2 + die3);

        system("cls");
        printf("   OGCOGCOGCOGCOGCOGCOGCOGCOGC\n\n");
        printf("         Dice Roll Game  \n\n");
        printf("   OGCOGCOGCOGCOGCOGCOGCOGCOGC\n\n\n");
        printf("Game rules:\n\n");
        printf("1.Each time will roll three dice, sum up the total number.\n");
        printf("2.According to the result, guess the next throw will higer, the same, or lower than the previous total.\n\n");
        printf("3.Enter your guess, higer: 'h', the same: 's', lower: 'l'.\n\n");
        printf("4.You will play 5 times, bingo more than 3 times win.\n\n");
        printf("5.If you win, the award is: Money+800, Attack*1.5, and Defense*2 !\n\n");
        printf("6.If you lose, the punishment is: Money-300, and Revovery*0.5 !\n\n\n\n\n");
        system("pause");

        printf("\n\n");
        printf("Die 1: %d\n", die1);
        printf("Die 2: %d\n", die2);
        printf("Die 3: %d\n", die3);
        printf("-------------------\n");
        printf("Total: %d\n\n", total);
        temp = total;

        for(i = 0; i <=runTime - 1; i++){
            printf("Do you think the next total will be higher, the same, or lower than the previous total? (h, s, l) \n\n");
            scanf(" %c", &guess);

            die1 = ( (rand() % 6) + 1);
            die2 = ( (rand() % 6) + 1);
            die3 = ( (rand() % 6) + 1);
            total = (die1 + die2 + die3);

            printf("Die 1: %d\n", die1);
            printf("Die 2: %d\n", die2);
            printf("Die 3: %d\n", die3);
            printf("-------------------");
            printf("Total: %d\n", total);

            if( (total > temp) && (guess == 'h') ){
                printf("You guessed correctly!\n\n\n");
                count++;
                e++;
            }else if( (total == temp) && (guess == 's') ){
                printf("You guessed correctly!\n\n\n");
                count++;
                e++;
            }else if( (total < temp) && (guess == 'l') ){
                printf("You guessed correctly!\n\n\n");
                count++;
                e++;
            }else{
                printf("You guessed incorrectly :(\n\n\n");
                f++;
            }
            temp = total;
        }

    printf("You got a total of %d guesses correct!\n\n", count);
    if(e>f)
    {
        printf("You win!\n");
        printf("Your award is: Money+800, Attack*1.5, and Defense*2 !\n\n\n");
        Beep(524,200);
        Beep(524,200);
        Beep(784,200);
        Beep(784,200);
        Beep(880,200);
        Beep(880,200);
        Beep(784,500);
        money=money+800;
        atk=atk*1.5;
        def=def*2;
    }
    else
    {
        printf("You lose!\n");
        printf("Your punishment is: Money-300, and Revovery*0.5 ! = =\n\n\n");
        Beep(494,500);
        Beep(392,500);
        Beep(330,500);
        money=money-300;
        rcv=rcv*0.5;
    }
    system("pause");
    system("cls");
}

void easter_egg(void)
{
    system("cls");

    printf("OGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGC\n");
    printf("OGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGC\n");
    printf("OGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGC\n");
    printf("OGC                                                                                    OGC\n");
    printf("OGC                                                                                    OGC\n");
    printf("OGC                                                                                    OGC\n");
    printf("OGC                                  Merry Christmas!!                                 OGC\n");
    printf("OGC                                                                                    OGC\n");
    printf("OGC                                  Happy New Year!!                                  OGC\n");
    printf("OGC                                                                                    OGC\n");
    printf("OGC                                                                                    OGC\n");
    printf("OGC                                                                                    OGC\n");
    printf("OGC                                                                                    OGC\n");
    printf("OGC                                                                                    OGC\n");
    printf("OGC                              Created by: Zhan Hong-Chi                             OGC\n");
    printf("OGC                                                                                    OGC\n");
    printf("OGC                                                                                    OGC\n");
    printf("OGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGC\n");
    printf("OGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGC\n");
    printf("OGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGCOGC\n\n\n\n\n\n\n\n\n\n\n");
    Beep(588,800);
    Beep(784,800);
    Beep(784,400);
    Beep(880,400);
    Beep(784,400);
    Beep(740,400);
    Beep(660,800);
    Beep(660,800);

    Beep(660,800);
    Beep(880,800);
    Beep(880,400);
    Beep(984,400);
    Beep(880,400);
    Beep(784,400);
    Beep(740,800);
    Beep(588,800);

    Beep(588,800);
    Beep(988,800);
    Beep(988,400);
    Beep(1048,400);
    Beep(988,400);
    Beep(880,400);
    Beep(784,800);
    Beep(660,800);

    Beep(588,400);
    Beep(588,400);
    Beep(660,800);
    Beep(880,800);
    Beep(740,800);
    Beep(784,800);

    system("pause");
    system("cls");
}

void introduce(void)
{
    system("cls");
    printf("                                                                                                                               \n");
    printf("                                                                                                                               \n");
    printf("                                                                                                                               \n");
    printf("                                                                                                                               \n");
    printf("    LL                 UU                   UU                DDDDDDDDDD           IIIIIIIIII     NNNNN                 NN     \n");
    printf("    LL                 UU                   UU                DDDDDDDDDDD          IIIIIIIIII     NN  NN                NN     \n");
    printf("    LL                 UU                   UU                DD        DD             II         NN   NN               NN     \n");
    printf("    LL                 UU                   UU                DD         DD            II         NN    NN              NN     \n");
    printf("    LL                 UU                   UU                DD          DD           II         NN     NN             NN     \n");
    printf("    LL                 UU                   UU                DD           DD          II         NN      NN            NN     \n");
    printf("    LL                 UU                   UU                DD            DD         II         NN       NN           NN     \n");
    printf("    LL                 UU                   UU                DD             DD        II         NN        NN          NN     \n");
    printf("    LL                 UU                   UU   ==========   DD             DD        II         NN         NN         NN     \n");
    printf("    LL                 UU                   UU                DD             DD        II         NN          NN        NN     \n");
    printf("    LL                 UU                   UU                DD            DD         II         NN           NN       NN     \n");
    printf("    LL                  UU                 UU                 DD           DD          II         NN            NN      NN     \n");
    printf("    LL                   UU               UU                  DD          DD           II         NN             NN     NN     \n");
    printf("    LL                    UU             UU                   DD         DD            II         NN              NN    NN     \n");
    printf("    LL                     UU           UU                    DD        DD             II         NN               NN   NN     \n");
    printf("    LLLLLLLLLLLLLLL         UUUUUUUUUUUUU                     DDDDDDDDDDD         IIIIIIIIIIII    NN                NN  NN     \n");
    printf("    LLLLLLLLLLLLLLL          UUUUUUUUUUU                      DDDDDDDDDD          IIIIIIIIIIII    NN                 NNNNN     \n");
    printf("                                                                                                                               \n");
    printf("                                                                                                                               \n");
    printf("                                                                                                                               \n");
    printf("                             GGGGGGGGG            EEEEEEEEEEEEEEEEEE    EEEEEEEEEEEEEEEEEE                                     \n");
    printf("                            GGGGGGGGGGG           EEEEEEEEEEEEEEEEEE    EEEEEEEEEEEEEEEEEE                                     \n");
    printf("                          GG          GG          EE                    EE                                                     \n");
    printf("                         GG            GG         EE                    EE                                                     \n");
    printf("                        GG              GG        EE                    EE                                                     \n");
    printf("                       GG                GG       EE                    EE                                                     \n");
    printf("                     GGG                          EE                    EE                                                     \n");
    printf("                    GGG                           EEEEEEEEEEEEEEEEEE    EEEEEEEEEEEEEEEEEE                                     \n");
    printf("                    GGG                           EEEEEEEEEEEEEEEEEE    EEEEEEEEEEEEEEEEEE                                     \n");
    printf("                    GGG          GGGGGGGGGGGGG    EE                    EE                                                     \n");
    printf("                     GGG         GGGGGGGGGGGGG    EE                    EE                                                     \n");
    printf("                       GG            GG   GG      EE                    EE                                                     \n");
    printf("                        GG           GG   GG      EE                    EE                                                     \n");
    printf("                         GG          GG   GG      EE                    EE                                                     \n");
    printf("                          GG         GG   GG      EE                    EE                                                     \n");
    printf("                           GGGGGGGGGGGG           EEEEEEEEEEEEEEEEEE    EEEEEEEEEEEEEEEEEE                                     \n");
    printf("                            GGGGGGGGG             EEEEEEEEEEEEEEEEEE    EEEEEEEEEEEEEEEEEE                                     \n");
    printf("                                                                                                                               \n");
    printf("                                                                                                                               \n");
    printf("                                                                                                                               \n");
    printf("                                                                                                                               \n");
    printf("                                                                                                                               \n");

    system("pause");
    system("cls");

    printf("Welcome to Lu-Din-Gee!! \n\n");
    printf("In this game, try to move your hero to the end.\n\n\n");
    printf("Game rules:\n\n");
    printf("1.Select your hero. There are 4 heros, each hero has different ability.\n\n");
    printf("2.Use up, down, left, right to control your hero.\n\n");
    printf("3.There are items in the map, pickup them to increase your ability.\n\n");
    printf("4.Items: \n\n");
    printf("         '$':   +100 Money    \n\n");
    printf("         'AA':  +20  Attack    \n\n");
    printf("         'DD':  +10  Defense \n\n");
    printf("         'RR':  +15  Recovery   \n\n");
    printf("5.Avoid to step on the BOMB 'XX', or you will get the damage.             \n\n");
    printf("         'XX':  -50  HP    \n\n");
    printf("6.In the map, you will encounter some challenge, solve it and keep going.             \n\n");
    printf("7.Some challenge has extra award after you solve it.\n\n");
    printf("8.Some challenge has punishment if you can't solve it.\n\n");
    printf("9.If your 'hp' is decrease to 0, then your hero die, Game Over.\n\n");
    printf("10.Try to move your hero to the flag, then you finish.\n\n");
    printf("11.Your final score is: hp + atk + def + rcv + money.\n\n");
    printf("12.Try your best to get the higher score.\n\n");
    printf("13.There is an Easter Egg hidden in the map. (Hits: near the flag)\n\n");
    printf("14.Keep relax to play the game.\n\n");
    printf("15.Let's Go!\n\n\n");
}
void again(void)
{
    char ch;
    printf("Play again?(y/n): \n\n");
    scanf("%c", &ch);
    switch(ch)
    {
        case'y':
            main();
            break;
        case'n':
            printf("Goodbye~!\n\n\n");
            exit(0);
            break;
        default:
            again();
            break;
    }
}
void dead(void)
{
    if(hp<=0)
    {
        printf("You dead......\n\n");
        printf("lololololololololol\n\n");
        Beep(392,1000);
        Beep(349,1000);
        Beep(294,1500);
        fflush(stdin);
        again();
    }
}
