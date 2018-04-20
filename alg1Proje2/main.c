#include <stdio.h>
#include <stdlib.h>
void siralama(int dizi[20][4],int );
void duzeltme(int dizi[20][4],int );
void yazdirma(int dizi[20][4],int );
void ozel_siralama(int dizi[20][4],int ,int );
int main()
{
    int secim,yarismaci_say,hafta_say, i, j,k,s, oyuncu1,oyuncu2,puan_verilecek_oyuncu,secim2;
    int bilgiler[20][4],genelBilgiler[20][4],kocBilgileri[20][20],haftaBilgileri[20][11];
    char cevap='h';
    do
    {
        printf("*************ANA MENU*****************\n");
        printf("1-Yeni Yarisma Duzenleme\n");
        printf("2-Son Duzenlenen Yarismanin Istatistiklerini Goruntuleme\n");
        printf("3-Cikis\n");
        do
        {
            printf("Lutfen Seciminizi Giriniz:\n");
            scanf("%d",&secim);
        }
        while(secim>3 || secim<1);
        switch(secim)
        {
        case 1:
        {
            do
            {
                printf("Lutfen Yarismaci Sayisini (en az 5 en cok 20) Giriniz:\n");
                scanf("%d",&yarismaci_say);
            }
            while(yarismaci_say>20 || yarismaci_say<5);
            do
            {
                printf("Lutfen Hafta Sayisini (en az 3 en cok 10) Giriniz:\n");
                scanf("%d",&hafta_say);
            }
            while(hafta_say<3 || hafta_say>10);
            for(i=0; i<yarismaci_say; i++)
            {
                genelBilgiler[i][0]=i+1;
                genelBilgiler[i][1]=0;
                genelBilgiler[i][2]=0;
                genelBilgiler[i][3]=0;
            }
            for(i=0; i<yarismaci_say; i++)
            {
                for(j=0; j<yarismaci_say; j++)
                {
                    kocBilgileri[i][j]=0;
                }
            }
            for(i=0; i<yarismaci_say; i++)
            {
                for(j=0; j<hafta_say; j++)
                {
                    haftaBilgileri[i][j]=0;
                }
                haftaBilgileri[i][10]=0;
            }
            for(i=0; i<hafta_say; i++)
            {
                for(s=0; s<yarismaci_say; s++)
                {
                    bilgiler[s][0]=s+1;
                    bilgiler[s][1]=0;
                    bilgiler[s][2]=0;
                    bilgiler[s][3]=0;
                }
                for(j=0; j<yarismaci_say; j++)
                {
                    for(k=0; k<3; k++)
                    {
                        if(k==0)
                        {
                            do
                            {
                                printf("Lutfen %d. kocun 1 puan verdigi oyuncuyu giriniz:",j+1);
                                scanf("%d",&puan_verilecek_oyuncu);
                                oyuncu1=puan_verilecek_oyuncu;
                            }
                            while(oyuncu1==(j+1) || oyuncu1<1 || oyuncu1>yarismaci_say);
                            bilgiler[puan_verilecek_oyuncu-1][1]+=1;
                            genelBilgiler[puan_verilecek_oyuncu-1][1]+=1;
                            kocBilgileri[puan_verilecek_oyuncu-1][j]+=1;
                            haftaBilgileri[puan_verilecek_oyuncu-1][i]+=1;
                        }
                        else if(k==1)
                        {
                            do
                            {
                                printf("Lutfen %d. kocun 2 puan verdigi oyuncuyu giriniz:",j+1);
                                scanf("%d",&puan_verilecek_oyuncu);
                                oyuncu2=puan_verilecek_oyuncu;
                            }
                            while(oyuncu1==oyuncu2 || oyuncu2==j+1 || oyuncu2<1 ||oyuncu2>yarismaci_say);
                            bilgiler[puan_verilecek_oyuncu-1][1]+=2;
                            genelBilgiler[puan_verilecek_oyuncu-1][1]+=2;
                            kocBilgileri[puan_verilecek_oyuncu-1][j]+=2;
                            haftaBilgileri[puan_verilecek_oyuncu-1][i]+=2;
                        }
                        else if(k==2)
                        {
                            do
                            {
                                printf("Lutfen %d. kocun 3 puan verdigi oyuncuyu giriniz:",j+1);
                                scanf("%d",&puan_verilecek_oyuncu);
                            }
                            while(puan_verilecek_oyuncu==oyuncu1 || puan_verilecek_oyuncu==oyuncu2 || puan_verilecek_oyuncu==j+1 || puan_verilecek_oyuncu<1 ||puan_verilecek_oyuncu>yarismaci_say);
                            bilgiler[puan_verilecek_oyuncu-1][1]+=3;
                            genelBilgiler[puan_verilecek_oyuncu-1][1]+=3;
                            kocBilgileri[puan_verilecek_oyuncu-1][j]+=3;
                            haftaBilgileri[puan_verilecek_oyuncu-1][i]+=3;
                        }
                    }
                }
                for(k=0; k<3; k++)
                {
                    if(k==0)
                    {
                        do
                        {
                            printf("Lutfen seyircilerin %d puan verdigi oyuncuyu giriniz:",k+1);
                            scanf("%d",&puan_verilecek_oyuncu);
                            oyuncu1=puan_verilecek_oyuncu;
                        }
                        while(oyuncu1<1 || oyuncu1>yarismaci_say);
                        bilgiler[puan_verilecek_oyuncu-1][2]+=(k+1)*(yarismaci_say-1);
                        genelBilgiler[puan_verilecek_oyuncu-1][2]+=(k+1)*(yarismaci_say-1);
                        haftaBilgileri[puan_verilecek_oyuncu-1][i]+=(k+1)*(yarismaci_say-1);
                    }
                    else if(k==1)
                    {
                        do
                        {
                            printf("Lutfen seyircilerin %d puan verdigi oyuncuyu giriniz:",k+1);
                            scanf("%d",&puan_verilecek_oyuncu);
                            oyuncu2=puan_verilecek_oyuncu;
                        }
                        while(oyuncu2<1 || oyuncu2>yarismaci_say || oyuncu1==oyuncu2);
                        bilgiler[puan_verilecek_oyuncu-1][2]+=(k+1)*(yarismaci_say-1);
                        genelBilgiler[puan_verilecek_oyuncu-1][2]+=(k+1)*(yarismaci_say-1);
                        haftaBilgileri[puan_verilecek_oyuncu-1][i]+=(k+1)*(yarismaci_say-1);
                    }
                    else if(k==2)
                    {
                        do
                        {
                            printf("Lutfen seyircilerin %d puan verdigi oyuncuyu giriniz:",k+1);
                            scanf("%d",&puan_verilecek_oyuncu);
                        }
                        while(oyuncu2<1 || oyuncu2>yarismaci_say || oyuncu1==oyuncu2 || puan_verilecek_oyuncu==oyuncu1 || puan_verilecek_oyuncu==oyuncu2);
                        bilgiler[puan_verilecek_oyuncu-1][2]+=(k+1)*(yarismaci_say-1);
                        genelBilgiler[puan_verilecek_oyuncu-1][2]+=(k+1)*(yarismaci_say-1);
                        haftaBilgileri[puan_verilecek_oyuncu-1][i]+=(k+1)*(yarismaci_say-1);
                    }
                }
                for(s=0; s<yarismaci_say; s++)
                {
                    bilgiler[s][3]=bilgiler[s][2]+bilgiler[s][1];
                    genelBilgiler[s][3]=genelBilgiler[s][2]+genelBilgiler[s][1];
                }
                printf("\n");
                printf("%d. Haftanin Sonuclari\n",i+1);
                printf("----------------------\n");
                siralama(bilgiler,yarismaci_say);
                haftaBilgileri[bilgiler[0][0]-1][10]+=1;
                yazdirma(bilgiler,yarismaci_say);
                printf("\n");
                printf("%d. Hafta Sonunda Puan Durumu\n",i+1);
                printf("-----------------------------\n");
                siralama(genelBilgiler,yarismaci_say);
                yazdirma(genelBilgiler,yarismaci_say);
                printf("\n");
                duzeltme(genelBilgiler,yarismaci_say);

            }
            break;
        }
        case 2:
        {
            do
            {
                printf(" Istatistik ALT MENUSU\n");
                printf("------------------------\n");
                printf("1.Sadece koclarin puanlari dikkate alindiginda genel durumun listelenmesi:\n");
                printf("2.Sadece seyircilerin puanlari dikkate alindiginda genel durumun listelenmesi:\n");
                printf("3.Yarismacilarin her hafta aldiklari toplam puanlarin listelenmesi:\n");
                printf("4.Yarismacilarin her koctan aldiklari toplam puanlarin listelenmesi:\n");
                printf("5.ANA MENU:\n");
                do
                {
                    printf("Seciminizi Giriniz:");
                    scanf("%d",&secim2);
                }
                while(secim2<1 || secim2>5);
                switch(secim2)
                {
                case 1:
                {
                    printf("Sadece Koclarin Puanlarina Gore Genel Durum:\n");
                    printf("--------------------------------------------\n");
                    printf("Sira No  Yarismaci No Puan\n");
                    printf("-------  ------------ ---- \n");
                    ozel_siralama(genelBilgiler,yarismaci_say,1);
                    for(i=0; i<yarismaci_say; i++)
                    {
                        printf("%d           %d          %d\n",i+1,genelBilgiler[i][0],genelBilgiler[i][1]);
                    }

                    break;
                }
                case 2:
                {
                    printf("Sadece Seyircilerin Puanlarina Gore Genel Durum:\n");
                    printf("-------------------------------------------------\n");
                    printf("Sira No  Yarismaci No Puan\n");
                    printf("-------  ------------ ---- \n");
                    ozel_siralama(genelBilgiler,yarismaci_say,2);
                    for(i=0; i<yarismaci_say; i++)
                    {
                        printf("%d            %d          %d\n",i+1,genelBilgiler[i][0],genelBilgiler[i][2]);
                    }
                    break;
                }
                case 3:
                {
                    printf("Yarismacilarin her hafta aldiklari toplam Puanlar:\n ");
                    printf("---------------------------------------------------\n");
                    printf("Yarismaci No  ");
                    for(i=0; i<hafta_say; i++)
                    {
                        printf("%d.Hafta  ",i+1);
                    }
                    printf(" 1.lik sayisi");
                    printf("\n");
                    printf("-----------   ");
                    for(i=0; i<hafta_say; i++)
                    {
                        printf("-------  ");
                    }
                    printf(" -------------");
                    printf("\n");
                    for(i=0; i<yarismaci_say; i++)
                    {
                        printf("      %d    ",i+1);
                        for(j=0; j<hafta_say; j++)
                        {
                            printf("%8d  ",haftaBilgileri[i][j]);
                        }
                        printf("%10d  ",haftaBilgileri[i][10]);
                        printf("\n");
                    }
                    break;
                }
                case 4:
                {
                    printf("Yarismacilarin Her koctan aldiklari toplam Puanlar:\n");
                    printf("----------------------------------------------------\n");
                    printf("Yarismaci No   ");
                    for(i=0; i<yarismaci_say; i++)
                    {
                        printf("Koc %d       ",i+1);
                    }
                    printf("\n");
                    printf("-----------   ");
                    for(i=0; i<yarismaci_say; i++)
                    {
                        printf("-------     ");
                    }
                    printf("\n");
                    for(i=0; i<yarismaci_say; i++)
                    {
                        printf("    %d    ",i+1);
                        for(j=0; j<yarismaci_say; j++)
                        {
                            printf("%10d  ",kocBilgileri[i][j]);
                        }
                        printf("\n");
                    }
                    break;
                }
                case 5:
                {
                    break;
                }


                }
            }
            while(secim2<5);
        }
        break;
        case 3:
        {
            printf("Cikis yapmak istediginize emin misiniz?:(Evet icin:e/E Hayir icin:h/H)\n");
            fflush(stdin);
            cevap=getchar();
            break;
        }
        }
    }
    while(cevap=='h' || cevap=='H');
    return 0;
}
void siralama(int dizi[20][4],int yarismaci_say)
{
    int i,j,gecici,degisim=1;
    while(degisim==1)
    {
        degisim=0;
        for(i=0; i<yarismaci_say-1; i++)
        {
            if(dizi[i][3]<dizi[i+1][3])
            {
                for(j=0; j<4; j++)
                {
                    gecici=dizi[i][j];
                    dizi[i][j]=dizi[i+1][j];
                    dizi[i+1][j]=gecici;
                    degisim=1;
                }
            }
            else if(dizi[i][3]==dizi[i+1][3] && dizi[i][1]<dizi[i+1][1])
            {
                for(j=0; j<4; j++)
                {
                    gecici=dizi[i][j];
                    dizi[i][j]=dizi[i+1][j];
                    dizi[i+1][j]=gecici;
                    degisim=1;
                }
            }
            else if(dizi[i][3]==dizi[i+1][3] && dizi[i][1]==dizi[i+1][1] && dizi[i][2]<dizi[i+1][2])
            {
                for(j=0; j<4; j++)
                {
                    gecici=dizi[i][j];
                    dizi[i][j]=dizi[i+1][j];
                    dizi[i+1][j]=gecici;
                    degisim=1;
                }
            }
        }
    }
}
void duzeltme(int dizi[20][4],int yarismaci_say)
{
    int degisim=1,i,j,gecici;
    while(degisim==1)
    {
        degisim=0;
        for(i=0; i<yarismaci_say-1; i++)
        {
            if(dizi[i][0]>dizi[i+1][0])
            {
                for(j=0; j<4; j++)
                {
                    gecici=dizi[i][j];
                    dizi[i][j]=dizi[i+1][j];
                    dizi[i+1][j]=gecici;
                    degisim=1;
                }
            }
        }
    }
}
void yazdirma(int dizi[20][4],int yarismaci_say)
{
    int i;
    printf("Sira No Yarismaci No Koc Puan  Seyirci Puan   Toplam Puan\n");
    printf("------- ------------ --------  ------------   -------------\n");
    for(i=0; i<yarismaci_say; i++)
    {
        printf("%d %10d %13d %10d %14d \n",i+1,dizi[i][0],dizi[i][1],dizi[i][2],dizi[i][3]);
    }

}
void ozel_siralama(int dizi[20][4],int yarismaci_say,int sayi)
{

    int degisim=1,i,j,gecici;
    while(degisim==1)
    {
        degisim=0;
        for(i=0; i<yarismaci_say-1; i++)
        {
            if(dizi[i][sayi]<dizi[i+1][sayi])
            {
                for(j=0; j<4; j++)
                {
                    gecici=dizi[i][j];
                    dizi[i][j]=dizi[i+1][j];
                    dizi[i+1][j]=gecici;
                    degisim=1;
                }
            }
        }
    }
}
