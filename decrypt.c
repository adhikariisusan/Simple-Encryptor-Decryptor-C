#include <stdio.h>
#include <stdlib.h>

void decrypt(char* filen)
{
    char  ch;
    FILE *fpts, *fptt;
    char filename[100];
    sprintf(filename,"%s",filen);
fpts=fopen(filename, "r");

    fptt=fopen("temp.txt", "w");
    while(1)
    {
        ch=fgetc(fpts);
        if(ch==EOF)
        {
            break;
        }
        else
        {
            ch=ch-1; // Reverse encryption process
            fputc(ch, fptt);
        }
    }
    fclose(fpts);
    fclose(fptt);
    fpts=fopen(filename, "w");

    fptt=fopen("temp.txt", "r");
    while(1)
    {
        ch=fgetc(fptt);
        if(ch==EOF)
        {
            break;
        }
        else
        {
            fputc(ch, fpts);
        }
    }
    fclose(fpts);
    fclose(fptt);
}

