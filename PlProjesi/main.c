#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>

void SetColor(int ForgC);
int main()
{
    FILE *dosya;
    char ch;
    char renk1[5]="blue";
    char renk2[4]="red";
    char renk3[6]="green";
    int i=0;
    bool atla=false;
    dosya = fopen("try.htx","r");
    while(!feof(dosya))
    {
        char str[50]="";
        ch=getc(dosya);
        if(ch == '[')
        {
            ch=getc(dosya);
            for(i=0;ch !=']';i++)
            {
                str[i]=ch;
                ch=getc(dosya);
            }ch=NULL;
             if(strcmp(str,renk1)==0){
              SetColor(9);
            }else if(strcmp(str,renk2)==0){
               SetColor(4);
            }else if(strcmp(str,renk3)==0){
                 SetColor(2);
            }else SetColor(15);
        }else if(ch =='/' || ch=='*'){
              ch=NULL;
              do{
                ch=NULL;
              }while(ch!='*' || ch!='/');
              if(ch=='*/') continue;
        }
         printf("%c",ch);

    }
return 0;
}
void SetColor(int ForgC)
{
    WORD wColor;
    //We will need this handle to get the current background attribute
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    //We use csbi for the wAttributes word.
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        //Mask out all but the background attribute, and add in the forgournd color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}
