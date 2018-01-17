#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

#define MIN 3
#define MAX 9
int board [MAX][MAX];
int d;

void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int title);
bool won(void);
void save(void);

int main(int argc, string argv[])
{
    greet();

    if(argc!=2)
    {
        printf("Usage : ./fifteen d\n");
        return 1;
    }

    d=atoi(argv[1]);
    if(d<MIN || d>MAX)
    {
        printf("Board must be between %i * %i & %i * %i, inclusive.\n",MIN,MIN,MAX,MAX);
        return 2;
    }

    init();

    while(true)
    {
        clear();
        draw();
        save();

        if(won())
        {
            printf("ftw/n");
            break;
        }

        printf("Tile to move :");
        int tile = get_int();

        if(!move(tile))
        {
            printf("Illegal Move.\n");
            sleep(50000);
        }

        sleep(50000);
    }
}

void clear(void)
{
    printf("\033[2J");
    printf("\033[%d,%dH",0,0);
}

void greet(void)
{
    clear();
    printf("Game Of Fifteen\n");
    sleep(50000);
}

void init(void)
{
    int c=1;
    for(int i=0;i<d;i++)
    {
        for(int j=0;j<d;j++)
        {
            board[i][j]=d*d-c;
            c++;
        }
    }

    board[d-1][d-1]=99;
    if((d*d)%2==0)
    {
        board[d-1][d-2]=2;
        board[d-1][d-3]=1;
    }
}

void draw(void)
{
    for(int i=0;i<d;i++)
    {
        for(int j=0;j<d;j++)
        {
            if(board[i][j]==99)
            {
                printf(" _ ");
            }
            else
            {
                printf("%2d",board[i][j]);
            }
            printf("\n");
        }
    }
}

bool move(int tile)
{
    for(int i=0;i<d;i++)
    {
        for(int j=0;j<d;j++)
        {
            if(board[i][j]==tile)
            {
                if(j+1 <= d-1 && board[i][j+1]==99)
                {
                    board[i][j+1]=tile;
                    board[i][j]=99;
                    return true;
                }
                else if(j-1>=0 && board[i][j-1]==99)
                {
                    board[i][j-1]=tile;
                    board[i][j]=99;
                    return true;
                }
                else if(i-1>=0 && board[i-1][j]==99)
                {
                    board[i-1][j]=tile;
                    board[i][j]=99;
                    return true;
                }
                else if(i+1<=d-1 && board[i+1][j]==99)
                {
                    board[i+1][j]=tile;
                    board[i][j]=99;
                    return true;
                }
            }
        }
    }
    return false;
}

bool won(void)
{
    int n=1;
    if(board[d-1][d-1]!=99)
    {
        return false;
    }

    for(int i=0;i<d;i++)
    {
        for(int j=0;j<d;j++)
        {
            if(i==d-1 && j==d-1)
            {
                return true;
            }
            if(n != board[i][j])
            {
                return false;
            }
            n++;
        }
    }
    return false;
}

void save(void)
{
    const string log = "log.txt";

    static bool saved = false;
    if(!saved)
    {
        unlink (log);
        saved=true;
    }

    FILE* p=fopen(log,"a");
    if(p==NULL)
    {
        return ;
    }

    fprintf(p,"{");
    for(int i=0;i<d;i++)
    {
        fprintf(p,"{");
        for(int j=0;j<d;j++)
        {
            fprintf(p,"%i",board[i][j]);
            if(j<d-1)
            {
                fprintf(p,",");

            }
        }
        fprintf(p,"}");
        if(i<d-1)
        {
            fprintf(p,",");
        }
    }
    fprintf(p,"}");
    fclose(p);
}
