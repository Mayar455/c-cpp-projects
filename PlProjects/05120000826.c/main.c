#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file;
    file=fopen("input.txt","r");
    char dizi[100];
    int i=0,buyukSay=0,kucukSay=0,bosSay=0,nokSay=0,isSAy=0,parSay=0;
    for(i=0;i<100;i++)
        dizi[i]=NULL;
    i=0;
    if(file==NULL)
        printf("dosya yok");
    else{
        do{
            dizi[i]=getc(file);
            // okunan karakteri ekrana yaz:
            i++;
    }while(!feof(file));
    fclose(file);
    }
    i=0;
    while(dizi[i]!=NULL){
        if((int)dizi[i]>64 && (int)dizi[i]<91)
            buyukSay++;
        if((int)dizi[i]>96 && (int)dizi[i]<123)
            kucukSay++;
        if(dizi[i]=='\t' || dizi[i]=='\v' || dizi[i]=='\n' || dizi[i]=='\f' || dizi[i]=='\r' || dizi[i]==' '){//if else versiyonu...
             bosSay++;
        }else if(dizi[i]=='\"' || dizi[i]==',' || dizi[i]=='.' || dizi[i]==':' || dizi[i]==';' || dizi[i]=='\''){
            nokSay++;
        }else if(dizi[i]=='+' || dizi[i]=='-' || dizi[i]=='*' || dizi[i]=='/' || dizi[i]=='='){
            isSAy++;
        }else if(dizi[i]=='(' || dizi[i]==')' || dizi[i]=='[' || dizi[i]==']' || dizi[i]=='{' || dizi[i]=='}'){
            parSay++;
        }/*
       switch(dizi[i]){//switch case versiyonu ikisi de doðru çalýþýyor..
            case '\t':
            case '\v':
            case '\n':
            case '\f':
            case '\r':
            case ' ':bosSay++;break;
            case '\"':
            case ',':
            case '.':
            case ':':
            case ';':
            case '\'':nokSay++;break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '=':isSAy++;break;
            case '(':
            case ')':
            case '[':
            case ']':
            case '{':
            case '}':parSay++;break;

        }*/
        i++;
    }
    printf("Buyuk Harf: ");
    for(i=0;i<buyukSay;i++)
        printf("*");
    printf("\n");


    printf("Kucuk Harf: ");
    for(i=0;i<kucukSay;i++)
        printf("*");
    printf("\n");


    printf("Bosluk: ");
    for(i=0;i<bosSay;i++)
        printf("*");
    printf("\n");


    printf("Operator: ");
    for(i=0;i<isSAy;i++)
        printf("*");
    printf("\n");

    printf("Parantez: ");
    for(i=0;i<parSay;i++)
        printf("*");
    printf("\n");

    return 0;
}


