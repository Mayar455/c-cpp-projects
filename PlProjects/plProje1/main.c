#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 39
#define OPR 13
#define PRTHE 7
#define DTYPE 7


void uzanti_ekleme(char *, char *, int ,int );

int main()
{
    FILE *yaz_dos, *oku_dos;
    int i,j,k,a,b,sayac_keywords=0,hata=0;
    int sayac_operator =0;
    int sayac_paranthesis=0;
    int sayac_identifiers=0;

    char girilen_isim[50], okunan_dosya_ismi[54], yazdirilan_dosya_ismi[54], ch;
    char passtr[5] = ".for", lexstr[5] = ".txt";

    char keywords[KEY][12]={"assign","backspace","call","block data","close","common","continue","data","demenssion","do","else","if",
                  "else if","end","endfile","endif","entry","equivalence","external","function","goto","implicit","inquire","intrinsic",
                  "open","parameter", "pause", "print", "program", "read", "return", "rewind", "rewrite", "save","stop", "subroutine", "then", "write"};

    char operators[OPR][6]={"+","-","*","/",".OR.",".NOT.",".AND.",".EQ.",".NE.",".LT.",".LE.",".GT.",".GE."};
    char parenthesis[PRTHE][2]={"[","]","(",")","{","}"};
    char data_types[DTYPE][17] = {"character","complex","double precision","integer","logical","real"};

    printf("Dosyanin adini giriniz: ");
    scanf("%s",girilen_isim);

    int girilen_uzunluk = strlen(girilen_isim);
    strncpy(okunan_dosya_ismi,girilen_isim,girilen_uzunluk);
    uzanti_ekleme(okunan_dosya_ismi, passtr, strlen(girilen_isim), strlen(passtr));

    strncpy(yazdirilan_dosya_ismi,girilen_isim,girilen_uzunluk);
    uzanti_ekleme(yazdirilan_dosya_ismi, lexstr, strlen(girilen_isim), strlen(lexstr));

    if((oku_dos = fopen(okunan_dosya_ismi,"r")) == NULL)
        printf("Dosya bulunamadi..!\n");
    else{
        yaz_dos = fopen(yazdirilan_dosya_ismi,"w");
        printf("Lexical Analyzer for the %s file:\n\nThe amount of errors:\n",okunan_dosya_ismi);
        printf("Error\n");
        printf("-----------\n");
        fseek(oku_dos,0,SEEK_SET);
        fseek(yaz_dos,0,SEEK_SET);
        fprintf(yaz_dos, "Lexical Analyzer for the %s file:\n\nThe list of lexemes:\n",okunan_dosya_ismi);
        fprintf(yaz_dos, "Lexeme         Type\n-----------   ---------------\n");

        while(!feof(oku_dos)){
            char str[50]="";
            ch = fgetc(oku_dos);
            if(ch == '\n'  || ch == ' ')
                continue;
            int flag =0;
            for(i=0;!feof(oku_dos) && ch != '\n' && ch !=' ';i++){

                str[i] = ch;
                ch = fgetc(oku_dos);
             }
               for(j=0;j<KEY;j++){
                if( strcmp(str,keywords[j])== 0){
                 fseek(yaz_dos,1,SEEK_CUR);
                 fprintf(yaz_dos,"%s         keyword\n",str);
                 sayac_keywords++;
                 flag = 1;
               }
             }
            if (flag == 0){
                for(k=0;k<OPR;k++){
                 if(strcmp(str,operators[k])== 0){
                   fseek(yaz_dos,1,SEEK_CUR);
                   fprintf(yaz_dos,"%s          operator.\n",str);
                   sayac_operator++;
                   flag = 1;
                 }
                }
                if(flag == 0){
                    for(a=0;a<PRTHE;a++){
                      if(strcmp(str,parenthesis[a])== 0){
                        fseek(yaz_dos,1,SEEK_CUR);
                        fprintf(yaz_dos,"%s         parenthesis.\n",str);
                        sayac_paranthesis++;
                         flag = 1;
                      }
                    }
                    if(flag == 0){
                      for(b=0;b<DTYPE;b++){
                        if(strcmp(str,data_types[b])== 0){
                          fseek(yaz_dos,1,SEEK_CUR);
                          fprintf(yaz_dos,"%s         data type.\n",str);
                          sayac_identifiers++;
                          flag=1;
                        }
                      }
                      if(flag == 0){
                        hata++;
                      }
                    }
                }
            }
            // printf(" %s   \n",str);
        }
         printf("%d errors found during analysis.\n\n",hata);
         printf("The ratio of Keywords is %d.\n",(sayac_keywords));
         printf("The ratio of Operators is %d.\n",(sayac_operator));
         printf("The ratio of Parenthesis is %d.\n",(sayac_paranthesis));
         printf("The ratio of identifier/Data Type is %d.\n",(sayac_identifiers));

         printf("The txt file has been created and Lexical Analyzer has been written to txt file .\n");
         fclose(oku_dos);
    }
    return 0;
}
void uzanti_ekleme(char *hedef, char *kaynak, int uzunluk, int kaynak_uzunlugu){

    int i;
    for(i=0; i<uzunluk; i++){
        hedef++;
    }
    for(i=0; i<kaynak_uzunlugu; i++){
        *hedef = *kaynak;
        kaynak++;
        hedef++;
    }
    *hedef = '\0';
}
