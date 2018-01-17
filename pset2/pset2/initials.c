#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
#include<string.h>

int main(void)
{
    int i,n;
    string name = get_string();
    if(name[0]!=' ')
    {
        printf("%c",toupper(name[0]));
        for(i=0,n=strlen(name);i<n;i++)
        {
            if(name[i]!=' ' && name[i-1] == ' ')
            {
                 printf("%c",toupper(name[i]));
            }
        }
        printf("\n");
    }

    else
    {
        for(i=0,n=strlen(name);i<n;i++)
        {
            if(name[i]!=' ' && name[i-1]==' ')
            {
                printf("%c",toupper(name[i]));
            }
        }
        printf("\n");
    }
}