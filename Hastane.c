#include <stdio.h>
#include <stdlib.h>

// 20010011092 Halime Unal
typedef struct hastalar
{
    int hasta_no;
    char hasta_ad[20];
    int hasta_yas;
} Hastalar;

typedef struct hasta
{
    int bolum_no;
    char bolum_ad[20];
    int hasta_sayisi;
    Hastalar *hasta_;
} Hasta;

int adet=0;
Hasta *has;

void Ekle()
{
    int i,j,hsayisi;
    printf("Kac bolum girilecek? ");
    scanf("%d",&adet);

    has = (Hasta*) malloc (adet*sizeof(Hasta));

    for(i=0; i<adet; i++)
    {
        printf("%d.bolum numarasini giriniz: ",i+1);
        scanf("%d",&(has+i)->bolum_no);

        printf("%d.bolum adini giriniz: ",i+1);
        scanf("%s",&(has+i)->bolum_ad);

        printf("%d.bolum hasta sayisini giriniz: ",i+1);
        scanf("%d",&hsayisi);

        (has+i)->hasta_sayisi = hsayisi;
        (has+i)->hasta_ = (Hastalar *) malloc (hsayisi*sizeof(Hastalar));

        for (j=0; j<hsayisi; j++)
        {
            printf("%d. Bolum %d. hasta numarasini giriniz: ", i+1,j+1);
            scanf("%d",&((has+i)->hasta_+j)->hasta_no);
            printf("%d. Bolum %d. hasta adini giriniz: ", i+1,j+1);
            scanf("%s",&((has+i)->hasta_+j)->hasta_ad);
            printf("%d. Bolum %d. hasta yasini giriniz: ", i+1,j+1);
            scanf("%d",&((has+i)->hasta_+j)->hasta_yas);
        }
    }
}

void Guncelle() // Once hasta ekle sonra guncelle
{
    int i,j,adetsay, hassay;
    printf("Kac bolum eklenecek? ");
    scanf("%d",&adetsay);
    has = (Hasta*)realloc(has,sizeof(Hasta)*adetsay);
    for(i=adet; i<adet + adetsay; i++)
    {
        printf("%d.bolum numarasini giriniz: ",i+1);
        scanf("%d",&(has+i)->bolum_no);
        printf("%d.bolum adini giriniz: ",i+1);
        scanf("%s",&(has+i)->bolum_ad);
        printf("%d.bolum hasta sayisini giriniz: ",i+1);
        scanf("%d",&hassay);

        (has+i)->hasta_sayisi = hassay;
        (has+i)->hasta_ = (Hastalar *) malloc (hassay*sizeof(Hastalar));

        for (j=0; j<hassay; j++)
        {
            printf("%d. Bolum %d. hasta numarasini giriniz: ", i+1,j+1);
            scanf("%d",&((has+i)->hasta_+j)->hasta_no);
            printf("%d. Bolum %d. hasta adini giriniz: ", i+1,j+1);
            scanf("%s",&((has+i)->hasta_+j)->hasta_ad);
            printf("%d. Bolum %d. hasta yasini giriniz: ", i+1,j+1);
            scanf("%d",&((has+i)->hasta_+j)->hasta_yas);
        }
    }
    adet = adet + adetsay;
}
void Silme()
{
    int i,j,hsayisi;
    printf("Kac bolum girilecek? ");
    scanf("%d",&adet);

    has = (Hasta*) malloc (adet*sizeof(Hasta));

    for(i=0; i<adet; i++)
    {
        printf("%d.bolum numarasini giriniz: ",i+1);
        scanf("%d",&(has+i)->bolum_no);

        printf("%d.bolum adini giriniz: ",i+1);
        scanf("%s",&(has+i)->bolum_ad);

        printf("%d.bolum hasta sayisini giriniz: ",i+1);
        scanf("%d",&hsayisi);

        (has+i)->hasta_sayisi = hsayisi;
        (has+i)->hasta_ = (Hastalar *) malloc (hsayisi*sizeof(Hastalar));

        for (j=0; j<hsayisi; j++)
        {
            printf("%d. Bolum %d. hasta numarasini giriniz: ", i+1,j+1);
            scanf("%d",&((has+i)->hasta_+j)->hasta_no);
            printf("%d. Bolum %d. hasta adini giriniz: ", i+1,j+1);
            scanf("%s",&((has+i)->hasta_+j)->hasta_ad);
            printf("%d. Bolum %d. hasta yasini giriniz: ", i+1,j+1);
            scanf("%d",&((has+i)->hasta_+j)->hasta_yas);
        }
    }
}

void Yazdir ()
{

    int i,j;
    for (i=0; i<adet; i++)
    {
        printf("-------------------------------\n");
        printf("Bolum no: %d -> Bolum ad: %s \n", (has+i)->bolum_no, (has+i)->bolum_ad);
        for(j=0; j<(has+i)->hasta_sayisi; j++)
        {
            printf("Hasta no: %d\t\n",((has+i)->hasta_+j)->hasta_no);
            printf("Hasta ad: %s\t\n",((has+i)->hasta_+j)->hasta_ad);
            printf("Hasta yas: %d\t\n",((has+i)->hasta_+j)->hasta_yas);
        }
    }
}

void OrtalamaHesapla (Hasta *has)
{
    double bolum_ort,genel_ort;
    int i,j, toplamhasta=0;
    for (i=0; i<adet; i++)
    {
        bolum_ort = 0.0;
        printf("\n\n\n");
        toplamhasta += (has+i)->hasta_sayisi;
        printf ("Bolum no: %d -> Bolum ad: %s\n", (has+i)->bolum_no,(has+i)->bolum_ad);
        for (j=0; j<(has+i)->hasta_sayisi; j++);
        {
            bolum_ort += ((has+i)->hasta_+j)->hasta_yas;
        }
        genel_ort += bolum_ort;
        bolum_ort = bolum_ort / (has+i)->hasta_sayisi;
        printf ("Bolum yas ortalamasi : %lf\n",bolum_ort);
    }
    genel_ort = genel_ort / toplamhasta;
    printf ("\n\n\nGenel yas ort: %lf\n", genel_ort);
}
void UcretHesapla(Hasta *has)
{
    int sec,ksayisi;
    double ucret;
    printf("Ucreti giriniz: \n");
    scanf("%d",&ucret);
    printf("Sigorta Turunu seciniz: Yok(1), SGK (2), Yesil Kart (3), GSS (4), Ozel (5)\n ");
    scanf("%d",&sec);
    printf("Kardes sayisini giriniz: \n");
    scanf("%d",&ksayisi);
    switch(sec)
    {
    case 1:
        ucret=ucret * 2;
        ucret=ucret-ksayisi*10;
        printf("Ucret -> %lf",ucret);
        break;
    case 2:
        ucret= (ucret*80)/100;
        ucret=ucret-ksayisi*10;
        printf("Ucret -> %lf",ucret);
        break;
    case 3:
        ucret =0;
        printf("Ucret -> %lf",ucret);
        break;
    case 4:
        ucret= (ucret*90)/100;
        ucret=ucret-ksayisi*10;
        printf("Ucret -> %lf",ucret);
        break;
    case 5:
        ucret = 0;
        printf("Ucret -> %lf",ucret);
    default:
        printf("Gecersiz islem");
        break;
    }
}
int main()
{
    Hasta *_hasta;
    int secim;
    while (secim != 6)
    {
        printf("Hastane otomasyonuna hosgeldiniz.\n");
        printf("Hasta ekle (1)\n");
        printf("Hasta guncelle (2)\n");
        printf("Hasta yazdir (3)\n");
        printf("Hasta yas ortalamasini hesapla (4)\n");
        printf("Hasta ucret hesapla (5)\n");
        printf("Cikis (6)\n");
        scanf("%d",&secim);

        switch(secim)
        {
        case 1:
            Ekle();
        case 2:
            Guncelle();
        case 3:
            Yazdir();
        case 4:
            OrtalamaHesapla(_hasta);
        case 5:
            UcretHesapla(_hasta);
        }
    }
}
