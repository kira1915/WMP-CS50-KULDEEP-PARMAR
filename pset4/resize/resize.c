#include<stdio.h>
#include<cs50.h>
#include "bmp.h"

int main(int argc, char* argv[])
{
    if(argc!=4)
    {
        printf("Usage : ./resize resize factor infile outfile.\n");
        return 1;
    }

    int factor = atoi(argv[1]);
    char* infile=argv[2];
    char* outfile=argv[3];

    if(factor<1 || factor>100)
    {
        printf("Factor must be in a range of [1,100]\n");
        return 1;
    }

    FILE* inptr=fopen(infile,"r");
    if(inptr==NULL)
    {
        printf("Could not open %s.\n",infile);
        return 1;
    }

    FILE* outptr = fopen(outfile,"w");
    if(outptr==NULL)
    {
        fclose(inptr);
        fprintf(stderr,"Unsupported file format.\n");
        return 1;
    }

    BITMAPINFOHEADER bi;
    BITMAPINFOHEADER bi_new;
    fread(&bi,sizeof(BITMAPINFOHEADER),1,inptr);

    bi_new = bi;

    BITMAPFILEHEADER bf;
    BITMAPFILEHEADER bf_new;
    fread(&bf,sizeof(BITMAPINFOHEADER),1,inptr);

    bf_new = bf;

    if(bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr,"Unsupported File Format.\n");
        return 0;
    }

    bi_new.biWidth = bi.biWidth * factor;
    bi_new.biHeight = bi.biHeight * factor;

    int padding=(4-(bi.biWidth*sizeof(RGBTRIPLE))%4)%4;
    int new_padding=(4-(bi_new.biWidth*sizeof(RGBTRIPLE))%4)%4;

    bf_new.bfSize = 54 + (bi_new.biWidth * sizeof(RGBTRIPLE) + new_padding) * abs(bi_new.biHeight);
    bi_new.biSizeImage = bf_new.bfSize - 54;

    fwrite(&bf_new,sizeof(BITMAPINFOHEADER),1,outptr);
    fwrite(&bi_new,sizeof(BITMAPINFOHEADER),1,outptr);

    for(int i=0,biHeight = abs(bi.biHeight); i<biHeight;i++)
    {
        int rowcounter = 0;

        while( rowcounter < factor)
        {
            for(int j=0; j < bi.biWidth;j++)
            {
                RGBTRIPLE triple;
                int pixelcounter = 0;
                fread(&triple, sizeof(RGBTRIPLE),1,inptr);

                while(pixelcounter < factor)
                {
                   fwrite(&triple, sizeof(RGBTRIPLE),1,outptr);
                   pixelcounter++;
                }
            }

            for(int k=0; k<new_padding;k++)
            {
                fputc(0x00,outptr);
             }

            if(rowcounter<(factor-1))
            {
                fseek(inptr, -(bi.biWidth*sizeof(RGBTRIPLE)),SEEK_CUR);
            }

            rowcounter++;
        }

        fseek(inptr,padding,SEEK_CUR);
    }


    fclose(inptr);
    fclose(outptr);

    return 0;



}

