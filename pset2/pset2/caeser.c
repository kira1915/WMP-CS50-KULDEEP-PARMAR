#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main(int argc, string argv[])
{
    string key=argv[1];
    if(argc!=2)
    {
        printf("Invalid Key\n");
    }
    else
    {
        int k=atoi(key)%26;
        if(k==0)
        {
            printf("Invalid Key.Try Again.\n");
        }

        string name=get_string();
        if(name!= NULL)
        {
            for(int i=0,n=strlen(name);i<n;i++)
            {
                int j=0;
                if(isupper(name[i]))
                {
                    j=(((int)name[i]-65+k)%26)+65;
                    printf("%c",(char)name[i]);
                }
                else if(islower(name[i]))
                {
                    j=(((int)name[i]-97+k)%26)+97;
                    printf("%c",(char)name[i]);
                }
                else
                {
                    printf("%c",(char)name[i]);
                }
            }
            printf("\n");
        }
    }
}