#include <stdio.h>
#include <stdlib.h>
int menu();
int dogrusal_ar(int[],int,int);
void gecisFonk(int [],int [],int [],int [],int);
void buyuktenKucugeSirala(int [],int [],int [],int [],int);
int main()
{
    char devam;
    int yarismaciSay,haftaSay,i,j,k,m,yarismacNum,kocPuan,seyercipuan,choice;
    int yarismacilar[21]={0};
    int puanlarKoc[21]={0};
    int puanlarSeyirci[21] = {0};
    int koclar[21]={0};
    int seyirciler[21]={0};
    int genelPuan[21]={0};
    int herHaftaGenelpuan[21]={0};
    choice=menu();
    switch(choice)
    {
    case 1:
        printf("Yarismaci sayisini giriniz:");
        scanf("%d",&yarismaciSay);
          /*while(yarismaciSay<5 || yarismaciSay>20){
            printf("yarismaci sayisini 5-20 arasinda giriniz:");
            scanf("%d",&yarismaciSay);
          }*/
       for(i=1;i<yarismaciSay+1;i++){//ilkleme yapiliyor..
           yarismacilar[i]=i;
           koclar[i]=i;
           seyirciler[i]=i;
       }
        printf("Yarismanin devam edecegi hafta sayisini giriniz:");
        scanf("%d",&haftaSay);
       /*while(haftaSay<3 || haftaSay>10){
            printf("Yarismanin devam edecegi hafta sayisi en az 3 olmali:");
            scanf("%d",&haftaSay);
        }*/
//-----------------------------------------------------------------------------------------------------------------------
    for(i=0;i<haftaSay;i++){
        printf("%d.Hafta icin yarisma duzenleniyor..\n\n\n",i+1);

      //yarismaciSay kocSay ve seyirciSay icin girildi.
      //her yarismaci icin bir islem yapýlmiyor, her koc ve seyirci icin yapiliyor.
      for(j=0;j<yarismaciSay;j++){
         int puanVerilenyarismaci = -1;
         int puanVerilenyarismaci2 = -1;
         for(k=0;k<3;k++){
            printf("%d.Koctan %d puani alan yarismacinin numarasini giriniz:",j+1,k+1);
            scanf("%d",&yarismacNum);
            while(yarismacilar[yarismacNum]==j+1 || puanVerilenyarismaci == yarismacNum || puanVerilenyarismaci2 == yarismacNum || yarismacNum>yarismaciSay){
               printf("Bu yarismaci ya kendi koucundan puan almaya calisiyor veya daha once almis %d puani almasi icin baska yarismaci giriniz:",k+1);
               scanf("%d",&yarismacNum);
            }
            if(puanVerilenyarismaci == -1)
                puanVerilenyarismaci = yarismacNum;
            else
                puanVerilenyarismaci2 = yarismacNum;
            puanlarKoc[yarismacNum]+=k+1;
            herHaftaGenelpuan[yarismacNum]+=k+1;
         }
         puanVerilenyarismaci = -1;
         puanVerilenyarismaci2 = -1;
         for(i=0;i<3;i++){
            printf("%d.Seyirci'den %d puani alan yarismacinin numarasini giriniz:",j+1,i+1);
            scanf("%d",&yarismacNum);
             while(puanVerilenyarismaci == yarismacNum || puanVerilenyarismaci2 == yarismacNum){
               printf("%d.Seyirci ayni yarismaciyi tekrar puan veremez baska numara giriniz:");
               scanf("%d",&yarismacNum);
            }
            if(puanVerilenyarismaci == -1)
                puanVerilenyarismaci = yarismacNum;
            else
                puanVerilenyarismaci2 = yarismacNum;
            puanlarSeyirci[yarismacNum]+=(i+1)*(yarismaciSay-1);
            herHaftaGenelpuan[yarismacNum]+=(i+1)*(yarismaciSay-1);
         }
       }
    }
       for(m=1;m<yarismaciSay+1;m++){
            genelPuan[m] = puanlarKoc[m]+puanlarSeyirci[m];
            herHaftaGenelpuan[m]=herHaftaGenelpuan[m]+herHaftaGenelpuan[m];

       }
        buyuktenKucugeSirala(yarismacilar,puanlarKoc,puanlarSeyirci,genelPuan,yarismaciSay);
        //for(i=1;i<=haftaSay;i++){
            printf("%d Hafta sonuclari\n",i+1);
            printf("Sira Yarismaci No Koc Puan  Seyerci Puan   Toplam Puan\n");
            printf("---- ------------ --------  -------------  ------------\n");
            for(j=1;j<yarismaciSay+1;j++){
                printf("%d %8d %11d %14d %13d \n",j,yarismacilar[j],puanlarKoc[j],puanlarSeyirci[j],genelPuan[j]);
            }
            printf("%d.Hafta sonunda Puan durumu\n",i+1);
            printf("Sira Yarismaci No Koc Puan  Seyerci Puan   Toplam Puan\n");
            printf("---- ------------ --------  -------------  ------------\n");
            buyuktenKucugeSirala(yarismacilar,puanlarKoc,puanlarSeyirci,herHaftaGenelpuan,yarismaciSay);
            for(k=1;k<yarismaciSay+1;k++)
                printf("%d %8d %11d %14d %13d \n",k,yarismacilar[k],puanlarKoc[k],puanlarSeyirci[k],herHaftaGenelpuan[k]);

        break;
//--------------------------------------------------------------------------------------------------------------------------------
    case 2:
        printf("istatistiksel alt menu:");
        break;
    case 3:
         do{
         printf("Cikmak istediginizden emin misiniz(e/E/e/h/H)?\n");
         devam=getch();
         }while(devam!='e' && devam!='E' || devam=='h' && devam=='H');
         break;
    }
        return 0;
}
int menu()
{
        int secim;
        char karakater;
        printf("\tANA MENU\n");
        printf("1.Yeni yarisma duzenlenme\n");
        printf("2.Son duzenlenen yarismanin istatistiksel bilgilerini goruntuleme\n");
        printf("3.Cikis\n");
        do
        {
            printf("Seciminizi giriniz:");
            scanf("%d",&secim);
        }
        while(secim<1 || secim>3);
        return secim;
}
//------------------------------------------------------------------------------------------------------------------------
void gecisFonk(int yarismacilar[20],int koclarpuan[20], int seyirciPuan[20], int puan[20],int j){
    int gecici;
     gecici=puan[j];
     puan[j]=puan[j+1];
     puan[j+1]=gecici;

     gecici=koclarpuan[j];
     koclarpuan[j]=koclarpuan[j+1];
     koclarpuan[j+1]=gecici;

     gecici = seyirciPuan[j];
     seyirciPuan[j] = seyirciPuan[j+1];
     seyirciPuan[j+1] = gecici;

     gecici=yarismacilar[j];
     yarismacilar[j]=yarismacilar[j+1];
     yarismacilar[j+1]=gecici;
}
//------------------------------------------------------------------------------------------------------------------------------
void buyuktenKucugeSirala(int yarismacilar[20],int koclarpuan[20], int seyirciPuan[20], int puan[20],int yarismaciSay){
     int i,j;
     for(i=0;i<yarismaciSay;i++){
        for(j=1;j<yarismaciSay;j++){
          if(puan[j]<puan[j+1] || (puan[j] == puan[j+1] && koclarpuan[j]<koclarpuan[j+1])){
            gecisFonk(yarismacilar,koclarpuan,seyirciPuan,puan,j);
          }else if(puan[j]==puan[j+1] && koclarpuan[j]==koclarpuan[j+1] && yarismacilar[j]>yarismacilar[j+1]){
                gecisFonk(yarismacilar,koclarpuan,seyirciPuan,puan,j);
          }
        }
     }
}
//-------------------------------------------------------------------------------------------------------------------------------
int dogrusal_ar(int yarismacilar[20],int elemanSay,int aranan){
    int i;
    for(i=1;i<elemanSay;i++){
        if(yarismacilar[i]==aranan){
           return 1;
        }
    }
    return -1;
}


