#include<stdio.h>
#include<cs50.h>
int main(void)
{
    float i;
    do
    {
    printf("\n Minutes : ");
    i = get_float();
    }
    while(i>=0);

    printf("\n Bottels : %.2f \n",(float)i*12);


}