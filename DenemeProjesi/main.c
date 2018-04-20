#include <stdio.h>
#include <stdlib.h>
#define EL_SAY 3

int r1(int,int);
void r2(int);
void f1(int [][EL_SAY]);
void f2(int [][EL_SAY]);
char *f3(char,char*);

int main()
{
    int i;
    int kare [EL_SAY][EL_SAY]={{0}};
    char metin[]="bir iki uc!";
    char *s1,*s2;
    char *mail="soyad@ege.edu.tr";
    char kar[EL_SAY]={'e','f','e'};
    char *p;
    char kelime[EL_SAY][5]={"bjk","fb","gs"};

    printf("sonuc = %d\n",r1(2,4));

    r2(1357);

    for (i=1;i<=EL_SAY;i++)
        kare [i-1][i-1]=i*i;

    f1(kare);

    f2(kare);

    p=f3('@',mail);
    printf("sunucu = %s \n",p+1);

    for (i=0;i<EL_SAY;i++)
        {
            p=f3(kar[i],mail);
            printf("%c karakteri",kar[i]);
            if (*p=='\0')
                printf("yok\n");
            else
                printf("var , konumu %d \n",p-mail+1);
        }

            s1=metin;
            printf("harf=%c\n",metin[4]);
            printf("harf=%c\n",s1[8]);
            printf("harf=%c\n",*(metin+9));
            printf("harf=%c\n",*(s1+2));
            printf("metin=%s\n",s1+8);

            s1=&(metin[8]);
            s2=kar;
            for (i=0;i<EL_SAY;i++)
                {
                    *s1=*s2;
                    s1++;
                    s2++;
                }
            printf("metin=%s\n",metin);

            for(i=EL_SAY;i>0;i--)
                printf("%d kelime =%s\n",i,kelime[i-1]);


    return 0;
}

    int r1(int say1, int say2)
        {
            if(say2>1)
                return say1*r1(say1,say2-1);
            else
                return say1;
        }
    void r2 (int sayi)
    {
        if (sayi < 10)
            printf("%d \n",sayi);
        else
            {
                printf("%d",sayi%10);
                r2(sayi/10);
            }
        return;
    }

    void f1 ( int m [][EL_SAY])
    {
        int i,j;

        f2 (m);

        for (i=0;i<EL_SAY;i++)
            for(j=0;j<EL_SAY;j++)
                m[i][j]=i+j;

         f2(m);

         for(i=0;i<EL_SAY;i++)
            printf("%d\n",m[i][i]);

         for (i=0;i<EL_SAY;i++)
            for(j=0;j<EL_SAY;j++)
                if((i+j)%2==0)
                    m[i][j]=1;
                else
                    m[i][j]=0;

            return;

        }

        void f2 (int m[][EL_SAY])
        {
            int i,j;

            for (i=0;i<EL_SAY;i++)
            {
                for (j=0;j<EL_SAY;j++)
                    printf("%d",m[i][j]);
                printf("\n");
            }
            return;
        }

        char *f3(char k , char*s)
        {
            while(k!=*s && *s != '\0')
                s++;
            return s;
        }
