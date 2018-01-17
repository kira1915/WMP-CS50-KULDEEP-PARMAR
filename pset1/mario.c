#include<cs50.h>
#include<stdio.h>
int main(void)
{
    int i;
    do
    {
       printf("\n Height : ");
       i = get_int();
    }
    while(i<0 || i>23);

    int b,c,d,space=i;


    for(b=1;b<=i;b++)
    {
        for(d=1;d<=space;d++)
        printf(" ");
        for(c=0;c<=b;c++)
        {
            printf("#");
        }
        printf("\n");
        space--;
    }
}