#include <stdio.h>
void main()
{

    char k;
    FILE *f;
    f = fopen("file1.txt","w");
    printf("Write the lines of text");
    while(1)
    {

        k=fgetchar();
        if(k==EOF) break;
        fputc(k,f);
    }
    fclose(f);
    printf("file contains");
    f = fopen("file1.txt","r");
    while(1)
    {

        k=fgetc(f);
        if(k==EOF) break;
     printf("%d",k);
    }
    fclose(f);

}
