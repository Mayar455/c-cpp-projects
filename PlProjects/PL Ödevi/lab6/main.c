#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int menu();

int main()
{
    int secenek;
    int tamSayi=0,i;
    char *offset;
    char *string;

    do{
      secenek=menu();
      switch(secenek){
        case 1: printf("Bir tam Sayi giriniz:");
                scanf("%d",&tamSayi);
                offset =(char *) malloc((tamSayi+1)*sizeof(char));
                printf("Girilen sayi kadar bellekte yer acildi.Boyut: %i\n\n",sizeof(*offset));
                break;
        case 2: printf("%i uzunlugunda bir kelime giriniz: ",tamSayi);
                scanf("%s",&string);
                for(i=0;i<tamSayi;i++)
                {
                    *offset=*string;
                    offset++;
                    string++;
                }
                *offset='\0';
                break;
        case 3:printf("%s",offset);break;
        case 4:offset-=tamSayi;printf("%s",offset);break;
      }
    }while(secenek!=5);

    return 0;
}
int menu(void){

    int secim;
    printf("\n");
    printf("********************MENU************************************\n");
    printf("            1. To take an integer\n");
    printf("            2. To take a string\n");
    printf("            3. To display the content of the memory block enter\n");
    printf("            4. To display the content of allocated mem\n");
     printf("            5.To Exit Enter \n");
    printf("\n");
    do {
        printf("\nSeciminizi Giriniz:  ");
        scanf("%d", &secim);

    }while(secim<1 || secim>5);

    return secim;

}
