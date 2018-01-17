#include<stdio.h>
#include<cs50.h>
#include "bmp.h"

int main(int argc, char* argv[])
{
    if(argc!=3)
    {
        printf("Usage : ./whodunit infile outfile\n");
        return 1;
    }

    char* infile=argv[1];
    char* outfile=argv[2];

    FILE* inptr=fopen(infile,"r");
    if(inptr==NULL)
    {
        printf("Could not open %s.\n",infile);
        return 2;
    }

    FILE* outptr = fopen(outfile,"w");
    if(outptr==NULL)
    {
        fclose(inptr);
        fprintf(stderr,"Unsupported file format.\n");
        return 4;
    }

    BITMAPFILEHEADER bf;
    fread(&bf,sizeof(BITMAPFILEHEADER),1,inptr);

    BITMAPINFOHEADER bi;
    fread(&bi,sizeof(BITMAPINFOHEADER),1,inptr);

    if(bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr,"Unsupported File Format.\n");
        return 4;
    }

    fwrite(&bi,sizeof(BITMAPINFOHEADER),1,outptr);
    fwrite(&bi,sizeof(BITMAPINFOHEADER),1,outptr);

    int padding=(4-(bi.biWidth*sizeof(RGBTRIPLE))%4)%4;

    for(int i=0, biHeight = abs(bi.biHeight);i<biHeight;i++)
    {
        for(int j=0; j<bi.biWidth;j++)
        {
            RGBTRIPLE triple;

            fread(&triple,sizeof(RGBTRIPLE),1,inptr);

            if(triple.rgbtRed==255 && triple.rgbtGreen==0 && triple.rgbtBlue==0 )
            {
                triple.rgbtGreen=255, triple.rgbtBlue=255;
            }

            fwrite(&triple,sizeof(RGBTRIPLE),1,outptr);
        }

        fseek(inptr,padding,SEEK_CUR);

        for(int k=0; k<padding;k++)
        {
            fputc(0x00,outptr);
        }
    }

    fclose(inptr);
    fclose(outptr);

    return 0;

}


