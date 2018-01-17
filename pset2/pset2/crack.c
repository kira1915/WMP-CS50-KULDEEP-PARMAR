#define _xopen_source
#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<unistd.h>

char *crypt(const char *key, const char *salt);
int main(int argc, char *argv[])
{
    if(argc!=2)
    {
        printf("Usage: ./crack hash\n");
    }
    const char*hashed_word = NULL;
    const char*hash_given = argv[1];
    const char*salt = "50";
    char word[5];
    char* alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    for(int i=0;i<52;i++)
    {
        word[0]=alphabet[i];
        hashed_word = crypt(word,salt);
        if(strcmp(hashed_word,hash_given)==0)
        {
            goto PRINT;
        }
    }

    for(int i=0;i<52;i++)
    {
        word[0]=alphabet[i];
        hashed_word=crypt(word,salt);
        if(strcmp(hashed_word,hash_given)==0)
        {
            goto PRINT;
        }

        for(int j=0;j<52;j++)
        {
            word[0]=alphabet[i];
            hashed_word=crypt(word,salt);
            if(strcmp(hashed_word,hash_given)==0)
            {
                goto PRINT;
            }
        }

    }

    for(int i=0;i<52;i++)
    {
        word[0]=alphabet[i];
        hashed_word=crypt(word,salt);
        if(strcmp(hashed_word,hash_given)==0)
        {
            goto PRINT;
        }

        for(int j=0;j<52;j++)
        {
            word[0]=alphabet[j];
            hashed_word=crypt(word,salt);
            if(strcmp(hashed_word,hash_given)==0)
            {
                goto PRINT;
            }

            for(int k=0;k<52;k++)
            {
                word[0]=alphabet[k];
                hashed_word=crypt(word,salt);
                if(strcmp(hashed_word,hash_given)==0)
                {
                    goto PRINT;
                }
            }
        }

    }

    for(int i=0;i<52;i++)
    {
        word[0]=alphabet[i];
        hashed_word=crypt(word,salt);
        if(strcmp(hashed_word,hash_given)==0)
        {
            goto PRINT;
        }

        for(int j=0;j<52;j++)
        {
            word[0]=alphabet[j];
            hashed_word=crypt(word,salt);
            if(strcmp(hashed_word,hash_given)==0)
            {
                goto PRINT;
            }

            for(int k=0;k<52;k++)
            {
                word[0]=alphabet[k];
                hashed_word=crypt(word,salt);
                if(strcmp(hashed_word,hash_given)==0)
                {
                    goto PRINT;
                }

                for(int l=0;l<52;l++)
                {
                    word[0]=alphabet[l];
                    hashed_word=crypt(word,salt);
                    if(strcmp(hashed_word,hash_given)==0)
                    {
                        goto PRINT;
                    }
                }
            }
        }

    }

    PRINT : printf("%s\n",word);




}



