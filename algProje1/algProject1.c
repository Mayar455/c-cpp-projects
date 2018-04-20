#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    bool uretimHatasi = false, maxAgFarkPozitif, maxYuzdeFarkPozitif;//true ve false döndürür...
    int bilyeSay,i,esitKutuSay=0,agirKutuSay=0,hafifKutuSay=0;
    int agirlik1=-1, agirlik2=-1, farkliAgirlik=-1,UretiHataKutu=0,kutuSay=0;
    int iadeEdilenBilyeSay = 0, kabulEdilenBilyeSay =0;
    int agirlikFarkiToplam = 0, hafiflikFarkiToplam =0;
    int maxBilyeSay = 0, maxKutuBilyeAgirlik = 0, minAgirlikKutuBilyeSay=0, minAgirlikKutuBilyeAgirlik=0;
    int maxAgFark = 0, maxYuzdeFarkAg = 0;
    float maxAgFarkYuzdesi = 0, maxYuzdeFark = 0;
    float agirlikYuzdeToplam = 0, hafiflikYuzdeToplam = 0;
    char devam;

    do{
        agirlik1=-1;
        agirlik2=-1;
        uretimHatasi = false;
        printf("Bir kutudaki bilye sayisini giriniz:");
        scanf("%d",&bilyeSay);

        while(bilyeSay<10){
            printf("Kutudaki bilye sayisi 10'dan kucuk olamaz..Lutfen bir daha giriniz:");
            scanf("%d",&bilyeSay);
        }
        kutuSay++;
        int bilyeAgirlik;
        for(i=1;i<bilyeSay+1;i++){

            printf("%d.bilyenin agirligini mg cinsinden giriniz:",i);
            scanf("%d",&bilyeAgirlik);

            while(bilyeAgirlik<=0){
                printf("Bilyenin agirligi pozitif tamsayi olmalidir. %d.bilyenin agirligini mg cinsinden giriniz:",i);
                scanf("%d",&bilyeAgirlik);
            }
            if(agirlik1==-1) agirlik1 = bilyeAgirlik;
            else if(agirlik1!=bilyeAgirlik && agirlik2 == -1) agirlik2 = bilyeAgirlik;

            else if((farkliAgirlik==1 && agirlik1==bilyeAgirlik)//hangisi farklidir...
                 || (farkliAgirlik==2 && agirlik2==bilyeAgirlik)
                 || (bilyeAgirlik!=agirlik1 && bilyeAgirlik !=agirlik2)){
                UretiHataKutu++;
                uretimHatasi = true;//uretim hatasi fark edildiginde uyarýr..
                break;
            }
            else if(agirlik1!=bilyeAgirlik) farkliAgirlik=1;
            else if(agirlik2!=bilyeAgirlik) farkliAgirlik=2;

        }
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        printf("\nSONUCLAR:\n");
        if(uretimHatasi){
                printf("Uretim hatasi!");
                iadeEdilenBilyeSay += bilyeSay;
        }else{
            kabulEdilenBilyeSay += bilyeSay;
            if(agirlik2==-1){//esit agirlikta bilyeler
               printf("Tum agirliklar esittir.");
               esitKutuSay++;
               if(bilyeSay>maxBilyeSay){
                    maxBilyeSay = bilyeSay;//icinde en fazla bilye bulunduran kutu..
                    maxKutuBilyeAgirlik = bilyeAgirlik;//kutudaki en agir bilye..
               }
               if(bilyeAgirlik>minAgirlikKutuBilyeAgirlik){
                    minAgirlikKutuBilyeSay = bilyeSay;//icinde en hafif olan bilye ve icindeki bilye sayisi..
                    minAgirlikKutuBilyeAgirlik = bilyeAgirlik;//kutudaki en hafif bilye
               }
            }else if(1==farkliAgirlik){
                if(agirlik1>agirlik2){//farkli olan bilyenin farki ve yzdesi...
                    float yuzde = (float)((agirlik1-agirlik2)*100)/agirlik1;
                    printf("Farkli olan bilye %d mg daha agirdir. (Yuzde %.2f)",agirlik1-agirlik2,yuzde);
                    agirKutuSay++;
                    agirlikFarkiToplam+=agirlik1-agirlik2;//agir olan bilyelerin agirlik farki ve toplami..
                    agirlikYuzdeToplam += yuzde;//agir olan bilyelerin yuzdesi..
                    if(agirlik1-agirlik2 > maxAgFark){
                        maxAgFark = agirlik1 - agirlik2;//en fark..
                        maxAgFarkPozitif = true;
                        maxAgFarkYuzdesi = yuzde;
                    }
                    if(yuzde > maxYuzdeFark){
                        maxYuzdeFark = yuzde;
                        maxYuzdeFarkAg = agirlik1 - agirlik2;
                        maxYuzdeFarkPozitif = true;
                    }
                }else{
                    float yuzde = ((agirlik2-agirlik1)*100)/agirlik2;
                    printf("Farkli olan bilye %d mg daha hafiftir. (Yuzde %.2f)",agirlik2-agirlik1,yuzde);
                    hafifKutuSay++;
                    hafiflikFarkiToplam += agirlik2-agirlik1;
                    hafiflikYuzdeToplam += yuzde;//hafif olanlainin toplam yüzdesi...
                    if(agirlik2-agirlik1 > maxAgFark){
                        maxAgFark = agirlik2 - agirlik1;//en agir fark..
                        maxAgFarkPozitif = false;
                        maxAgFarkYuzdesi = yuzde;//en agir olanların yuzdesi..
                    }
                    if(yuzde > maxYuzdeFark){
                        maxYuzdeFark = yuzde;
                        maxYuzdeFarkAg = agirlik2 - agirlik1;
                        maxYuzdeFarkPozitif = false;
                    }
                }
            }else if(2==farkliAgirlik){
                if(agirlik1>agirlik2){
                    float yuzde = (float)((agirlik1-agirlik2)*100)/agirlik1;
                    printf("Farkli olan bilye %d mg daha hafiftir. (Yuzde %.2f)",agirlik1-agirlik2,yuzde);
                    hafifKutuSay++;
                    hafiflikFarkiToplam += agirlik1-agirlik2;
                    hafiflikYuzdeToplam += (float)((agirlik1-agirlik2)*100)/agirlik1;
                    if(agirlik1-agirlik2 > maxAgFark){
                        maxAgFark = agirlik1 - agirlik2;
                        maxAgFarkPozitif = false;
                        maxAgFarkYuzdesi = (float)((agirlik1-agirlik2)*100)/agirlik1;
                    }
                    if(yuzde > maxYuzdeFark){
                        maxYuzdeFark = yuzde;
                        maxYuzdeFarkAg = agirlik1 - agirlik2;
                        maxYuzdeFarkPozitif = false;
                    }
                }else{
                    float yuzde = (float)((agirlik2-agirlik1)*100)/agirlik2;
                    printf("Farkli olan bilye %d mg daha agirdir. (Yuzde %.2f)",agirlik2-agirlik1,yuzde);
                    agirKutuSay++;
                    agirlikFarkiToplam+=agirlik2-agirlik1;//farkli bilye,ve kutularin agirlik farki ve yüzdes..
                    agirlikYuzdeToplam += yuzde;
                    if(agirlik2-agirlik1 > maxAgFark){
                        maxAgFark = agirlik2 - agirlik1;
                        maxAgFarkPozitif = true;
                        maxAgFarkYuzdesi = yuzde;
                    }
                    if(yuzde > maxYuzdeFark){
                        maxYuzdeFark = yuzde;
                        maxYuzdeFarkAg = agirlik2 - agirlik1;
                        maxYuzdeFarkPozitif = true;
                    }
                }
            }
        }

        printf("\nBaska kutu var mi?(Evet:e/E Hayir: Herhangi bir tus): ");
        scanf(" %c",&devam);
    }while(devam=='e' || devam=='E');
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    printf("\nISTATISTIKSEL BILGILER:\n");
    printf("Uretim hatasi olan kutu sayisi %d  ve toplam kutular icin yuzdesi %.2f dir.\n\n",UretiHataKutu,(float)UretiHataKutu*100/kutuSay);
    printf("Iade edilen bilye sayisi: %d; Kabul edilen bilye sayisi: %d\n\n",iadeEdilenBilyeSay,kabulEdilenBilyeSay);

    printf("Agirliklari esit olan kutu sayisi %d dir. uretim hatasi olmayan kutular icinde yuzdesi %.2f dir..\n",esitKutuSay,(float)(esitKutuSay*100)/(kutuSay-UretiHataKutu));
    printf("Farkli bilyenin digerlerinden daha agir oldugu kutu sayisi %d dir. uretim hatasi olmayan kutular icinde yuzdesi %.2f dir..\n",agirKutuSay,(float)(agirKutuSay*100)/(kutuSay-UretiHataKutu));
    printf("Farkli bilyenin digerlerinden daha hafif oldugu kutu sayisi %d dir. uretim hatasi olmayan kutular icinde yuzdesi %.2f dir..\n\n",hafifKutuSay,(float)(hafifKutuSay*100)/(kutuSay-UretiHataKutu));

    printf("Farkli bilyenin digerlerinden daha agir oldugu kutularin agirlik farki ortalamasi: %.2f\n",(float)agirlikFarkiToplam/agirKutuSay);
    printf("Farkli bilyenin digerlerinden daha agir oldugu kutularin agirlik yuzdesi ortalamasi: %.2f\n\n",agirlikYuzdeToplam/agirKutuSay);

    printf("Farkli bilyenin digerlerinden daha hafif oldugu kutularin agirlik farki ortalamasi: %.2f\n",(float)hafiflikFarkiToplam/hafifKutuSay);
    printf("Farkli bilyenin digerlerinden daha hafif oldugu kutularin agirlik yuzdesi ortalamasi: %.2f\n\n",hafiflikYuzdeToplam/hafifKutuSay);

    printf("Tum bilyelerin esit agirlikta oldugu kutular arasinda, icinde en cok bilye olan kutudaki bilye sayisi: %d, o kutudaki bir bilyenin agirligi: %d\n",maxBilyeSay,maxKutuBilyeAgirlik);

    printf("Tum bilyelerin esit agirlikta oldugu kutular arasinda, icinde en hafifi bilyeler olan kutudaki bilye sayisi: %d, o kutudaki bir bilyenin agirligi: %d\n\n",minAgirlikKutuBilyeSay,minAgirlikKutuBilyeAgirlik);

    char isaret = '-';
    if(maxAgFarkPozitif) isaret = '+';
    printf("Farkli olan bilyenin agirliginin diger bilyelerin agirligiyla arasindaki farkin degerinin en buyuk oldugu farkin degeri: %c%d, yuzdesi: %.2f\n\n",isaret,maxAgFark, maxAgFarkYuzdesi);

    isaret = '-';
    if(maxYuzdeFarkPozitif) isaret = '+';
    printf("Farkli olan bilyenin agirliginin diger bilyelerin agirligiyla arasindaki farkin yuzdesinin en buyuk oldugu farkin degeri: %c%d, yuzdesi: %.2f\n\n",isaret,maxYuzdeFarkAg, maxYuzdeFark);


    return 0;
}
