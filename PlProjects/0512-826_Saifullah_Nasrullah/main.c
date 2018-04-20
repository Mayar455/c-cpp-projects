#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include<conio.h>
int main()
{
    system("COLOR 0E");
    FILE *fptr;
    FILE *yaz_dos;
    char file_name[]=" .ba";
    char c,ch='\0';
    char *identifier="identifier";
    char Keywords[9][6]= {"out","int","loop","move","add","sub","to","times"};
    char lexim_types[9][50]= {"Output statement","Data Type","Loop","Assignment Statement","Addition statement",
                              "Subtraction statement","Assignment Operator","loop condition"
                             };
    int i=0,j,a=0,opnblockPrts=0,clblkprs=0,KeywodSay=0;
    int eofLineCount=0,undeclared_error=0,clcmntprts=0,opncmntprths=0,idenCount=0;
    printf("Please Enter the file. ");
    printf("(x).ba : ");
    scanf("%c",&c);
    file_name[0]=c;
    if( (fptr=fopen(file_name,"r"))==NULL )
    {
        printf("The File is not found.");
        return;
    }
    else
    {
        yaz_dos = fopen("b.txt","w");//dosya yaratýlýyor..
        printf("Lexical Analyzer for the %s file:\n\nThe list of Lexemes within its type:\n",file_name);
        printf("Lexeme         Type\n");
        printf("-----------   ---------------------\n");
        fseek(fptr,0,SEEK_SET);
        fseek(yaz_dos,0,SEEK_SET);
        fprintf(yaz_dos, "Lexical Analyzer for the %s file:\n\nThe list of Lexemes within its type:\n",file_name);
        fprintf(yaz_dos, "Lexeme         Type\n-----------   ---------------------\n");//yaratýlan dosyaya yazdýrlýyor..

        while(!feof(fptr))
        {
            char str[50]="";
            ch=fgetc(fptr);
            for(j=0; ch!=32 && ch!=46 && ch!='\n' && !(feof(fptr)); j++)
            {
                str[j]=ch;
                ch=fgetc(fptr);
                if(ch==32){
                    for(i=0; i<9; i++)
                    {
                        if(strcmp(str,Keywords[i])==0)
                        {
                            printf("%-13s %s\n", str, lexim_types[i]);
                            fprintf(yaz_dos, "%-13s %s\n",str, lexim_types[i]);
                            if(strcmp(str,"int")==0 || strcmp(str,Keywords[i])==0)
                            {
                                ch=fgetc(fptr);
                                j=0;
                                while(!feof(fptr))
                                {
                                    str[j]=ch;
                                    ch=fgetc(fptr);
                                    if(ch==32 || ch==46 || ch=='[' || ch=='{' || ch==',')
                                    {
                                        printf("%-13s %s\n",str,identifier);
                                        fprintf(yaz_dos,"%-13s %s\n",str,identifier);
                                        idenCount++;
                                        break;
                                    }
                                    j++;
                                }
                                KeywodSay++;
                            }else{
                               printf("%-13s  Tanimlanmamis\n",str);break;
                           }
                        }

                    }
              }else if(ch=='\n'){
                    ch=fgetc(fptr);
                    if(ch=='[')
                    {
                        opnblockPrts++;
                        ch=fgetc(fptr);
                        a=0;
                        while(ch!=']')
                        {
                            str[j]=ch;
                            ch=fgetc(fptr);
                            if((ch==32 || ch==46) && strcmp(str,Keywords[a])==0)
                            {
                                printf("%-13s %s\n", str, lexim_types[a]);
                                fprintf(yaz_dos, "%-13s %s\n",str, lexim_types[a]);
                                KeywodSay++;
                                break;
                            }
                            else
                            {
                                printf("%-13s %s\n",str,identifier);
                                fprintf(yaz_dos,"%-13s %s\n",str,identifier);
                                idenCount++;
                                break;
                            }
                            a++;
                        }
                        clblkprs++;
                    }
                }
            }if(ch==46){
                    eofLineCount++;
                    ch=fgetc(fptr);
                    if(ch=='\n')
                    {
                        ch=fgetc(fptr);
                        if(ch=='{')
                        {
                            opncmntprths++;
                            ch=fgetc(fptr);
                            while(ch!='}')
                            {
                                printf("%c",ch);
                                fprintf(yaz_dos,"%c",ch);
                                ch=fgetc(fptr);
                            }
                            clcmntprts++;
                            printf("\t <-- Comment which has been Written\n");
                            fprintf(yaz_dos,"\t <-- Comment which has been Written\n");
                            ch=fgetc(fptr);
                        }
                    }
                }
        }
        printf("\n");
        printf("Open Block Parenthesis  Close Block Parenthesis\n----------------------  -----------------------\n");
        fprintf(yaz_dos,"Open Block Parenthesis  Close Block Parenthesis\n----------------------  -----------------------\n");
        printf("%10d %20d\n",opnblockPrts,clblkprs);
        fprintf(yaz_dos,"%10d %20d\n",opnblockPrts,clblkprs);
        printf("Open Comment Parenthesis  Close Comment Parenthesis  End Of Line\n------------------------  ---------------------  ---------------\n");
        fprintf(yaz_dos,"Open Comment Parenthesis  Close Comment Parenthesis  End Of Line\n------------------------  ---------------------  ---------------\n");
        fprintf(yaz_dos,"%10d %20d %25d\n\n",opncmntprths,clcmntprts,eofLineCount);
        printf("%10d %20d %25d\n\n",opncmntprths,clcmntprts,eofLineCount);
        printf("%d identifier is found\n",idenCount);
        fprintf(yaz_dos,"%d identifier is found\n",idenCount);
        printf("%d Keywords is found\n",KeywodSay);
        fprintf(yaz_dos,"%d Keywords is found\n",KeywodSay);
        getch();

        fclose(fptr);
    }


    return 0;
}

