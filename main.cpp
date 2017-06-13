#include<graphics.h> ///Grafik ekranı oluştumak için kullandık.
#include <math.h>    ///Çember fonksiyonu için kullandık.
#include <locale.h>  ///Türkçe karakter kullanmak için tanımladık.

 ///Kullanacağımız bütün fonksiyonları global olarak tanımladık.
void bars();
int Pencil();
int Line();
int Triangle();
int Rectangle();
int Circle();
void EditColor();
void bars_foto();

///Seçim yaptığımız barlardaki simgeleri bu fonksiyonla çağırıyoruz.
void bars_foto()
{
readimagefile("folder.bmp",10,10,140,100);
readimagefile("save.bmp",160,10,290,100);
readimagefile("pencil.bmp",310,10,440,100);
readimagefile("line.bmp",460,10,590,100);
readimagefile("triangle.bmp",610,10,740,100);
readimagefile("rectagle.bmp",760,10,890,100);
readimagefile("circle.bmp",910,10,1040,100);
readimagefile("delete.bmp",1060,10,1190,100);
readimagefile("name1.bmp",1600,35,1900,75);
}

///Bu fonksiyon kullanıcı eğer fotoğraf açmamışsa ve panel de bişeyler çizmişse tüm ekranı silebiliyor.
void Temizle()
{
    readimagefile("bos.bmp",0,100,getmaxx(), getmaxy());
    clearmouseclick(WM_LBUTTONDOWN);
    setcolor(16);
    bars_foto();
}

///Yükleme ve kaydetme için bu fonksiyon kullanılıyor.
void YukleVeKaydet()
{
               if(mousex()>0 && mousex()<150 && mousey()>0 && mousey()<100){readimagefile(NULL,0,100,getmaxx(), getmaxy()); clearmouseclick(WM_LBUTTONDOWN); bars_foto();}
               if(mousex()>150 && mousex()<300 && mousey()>0 && mousey()<100){writeimagefile(NULL,0,101,getmaxx(), getmaxy());clearmouseclick(WM_LBUTTONDOWN);}
}

///RenkAyarı fonksiyonu mouse konumuna göre renk seçmemize yarıyor.
void EditColor()
{
               if(mousex()>1200 && mousex()<1250 && mousey()>0 && mousey()<50){setcolor(15);}
               if(mousex()>1250 && mousex()<1300 && mousey()>0 && mousey()<50){setcolor(7);}
               if(mousex()>1300 && mousex()<1350 && mousey()>0 && mousey()<50){setcolor(14);}
               if(mousex()>1350 && mousex()<1400 && mousey()>0 && mousey()<50){setcolor(6);}
               if(mousex()>1400 && mousex()<1450 && mousey()>0 && mousey()<50){setcolor(12);}
               if(mousex()>1450 && mousex()<1500 && mousey()>0 && mousey()<50){setcolor(3);}
               if(mousex()>1500 && mousex()<1550 && mousey()>0 && mousey()<50){setcolor(10);}
               if(mousex()>1550 && mousex()<1600 && mousey()>0 && mousey()<50){setcolor(9);}
               if(mousex()>1200 && mousex()<1250 && mousey()>50 && mousey()<100){setcolor(16);}
               if(mousex()>1250 && mousex()<1300 && mousey()>50 && mousey()<100){setcolor(8);}
               if(mousex()>1300 && mousex()<1350 && mousey()>50 && mousey()<100){setcolor(13);}
               if(mousex()>1350 && mousex()<1400 && mousey()>50 && mousey()<100){setcolor(5);}
               if(mousex()>1400 && mousex()<1450 && mousey()>50 && mousey()<100){setcolor(4);}
               if(mousex()>1450 && mousex()<1500 && mousey()>50 && mousey()<100){setcolor(11);}
               if(mousex()>1500 && mousex()<1550 && mousey()>50 && mousey()<100){setcolor(2);}
               if(mousex()>1550 && mousex()<1600 && mousey()>50 && mousey()<100){setcolor(1);}
               if(mousex()>1050 && mousex()<1200 && mousey()>0 && mousey()<100){Temizle();}
               YukleVeKaydet();
}

///Serbest kalem fonksiyonu
int Pencil()
{
    while(1)
    {

      if(ismouseclick(WM_LBUTTONDOWN)){

       moveto(mousex(),mousey()); delay(1);

      if(mousey()>110)  ///Fare nin y ekseni 110 dan büyükse işlem yapmaz. Çünkü o kısımda seçim barları var.
      lineto(mousex(),mousey());

           if(ismouseclick(WM_LBUTTONUP) ){ ///Fareden elinizi çektiğinizde farenin basılı olduğu durum ve olmadığı durum sıfırlanır.
                  clearmouseclick(WM_LBUTTONDOWN);
                  clearmouseclick(WM_LBUTTONUP);
                }

        if(ismouseclick(WM_LBUTTONDOWN)){

               if(mousex()>300 && mousex()<1050 && mousey()>0 && mousey()<100) ///Tekrar seçim yapmak için kontrol yapıyor.
                   return 0;

                EditColor(); ///Kullanıcı renk seçimi yapıyorsa burdan kontrol ediyor.
           }
      }
      clearmouseclick(WM_LBUTTONUP);
   }
}

///Düz çizgi fonksiyonu
int Line()
{
    double a,b,z,t;

      while(1){

          if(ismouseclick(WM_LBUTTONDOWN)){ ///Farenin ilk basılı olduğu yeri alıyor.

        a=mousex();
        b=mousey();

        clearmouseclick(WM_LBUTTONDOWN);

      }

      if(ismouseclick(WM_LBUTTONUP)){

       z=mousex();
       t=mousey();

       clearmouseclick(WM_LBUTTONUP);

///Bu fonksiyon için eğimi kullandık. a1,y noktalarının farkı a2,x noktasının farkı.

       double a1=(t-b);
       double a2=(z-a);
///csn ise : kullanıcı çizgi çizdiğinde eğer noktalardan birisi barların olduğu kısıma denk gelirse bara gelene kadar çizgi çeksin ama çizgi farenin olduğu noktada değil barın bittiği noktada bitsin.
/// Bu yüzden csn :(son y konumu-100) / eğim olarak bulunur.
       double csn;
       if(a1!=0 && a2!=0){
       csn=(100-t)/(a1/a2); }
       if(csn<0){csn=csn*-1;}
///cs2 de çizginin son noktasına karşılık gelmesi gereken x degeridir.
       double cs2=z-csn;
///Çizginin ilk noktası mı barın üstünde yoksa son noktası mı diye kontrol edilmesi gerekir.
       if(b>110 && t>110)
       line(a,b,z,t);

       else if(b<110 && t<110){}

       else if(b<110)
       line(cs2,110,z,t);

       else if(t<110)
       line(a,b,cs2,110);

      }
///Kontrol Noktası
 if(ismouseclick(WM_LBUTTONDOWN)){

               if(mousex()>300 && mousex()<1050 && mousey()>0 && mousey()<100)
                   return 0;

                EditColor();

           }
      }
}

///Üçgen çizen fonksiyon
int Triangle()
{
      int a,b,z,t;

      while(1)
      {
          if(ismouseclick(WM_LBUTTONDOWN)){ ///Fare basıldığı anda ilk noktayı alıyor.

        a=mousex();
        b=mousey();

        clearmouseclick(WM_LBUTTONDOWN); ///Farenin basılması sıfırlanıyor ki ilk seçtiğimiz nokta değişmesin.

      }

      if(ismouseclick(WM_LBUTTONUP)){ ///Fare basılı tutuluyorken sol tuş serbest kaldığında ikinci nokta atanıyor.

        z=mousex();
        t=mousey();

        clearmouseclick(WM_LBUTTONUP);

///İki noktanında y konumları barlara değmiyorsa üçgen çiziliyor.
     if(b>110 && t>110){
       int q=2*a-z; ///Çizilen üçgenin ikizkenar olması için ilk çizilen çizgiye simetrik başka bir çizgi çiziliyor ve oluşan iki çizginin son noktalarından birdaha çizgi çekiliyor.
       line(a,b,z,t);
       line(z,t,q,t);
       line(q,t,a,b);

    }
}
///Kontrol Noktası
 if(ismouseclick(WM_LBUTTONDOWN)){

               if(mousex()>300 && mousex()<1050 && mousey()>0 && mousey()<100)
                   return 0;

                EditColor();

           }
     }
}
///Dörtgen çizen fonksiyon
   int Rectangle()
   {
      int a,b,z,t;

      while(1)
      {
        if(ismouseclick(WM_LBUTTONDOWN)){ ///İlk nokta seçildi.

        a=mousex();
        b=mousey();

        clearmouseclick(WM_LBUTTONDOWN);

      }

      if(ismouseclick(WM_LBUTTONUP)){ ///İkinci nokta seçildi.

        z=mousex();
        t=mousey();

        clearmouseclick(WM_LBUTTONUP);
///Eger iki noktada barlarda değilse...
       if(b>110 && t>110){
            ///İki tane dörtgen çiziyor çünkü seçilen iki noktada olan dörtgen aynı çizgi üzerinde olabilir. Yani ya alt ve üst tarafı yada sag ve sol tarafı kapanmayabilir.
            ///Bu yüzden onu tamamlayacak ikinci bir dörtgen ters yönde çiziliyor.
        rectangle(a,b,z,t);
        rectangle(z,t,a,b);
      }
  }
///Kontrol Noktası
 if(ismouseclick(WM_LBUTTONDOWN)){


               if(mousex()>300 && mousex()<1050 && mousey()>0 && mousey()<100)
                   return 0;

                EditColor();
           }
     }
}

///Çember çizen fonksiyon
   int Circle()
{
      int a,b,z,t;

      while(1)
      {
          if(ismouseclick(WM_LBUTTONDOWN)){ ///İlk nokta seçildi.

        a=mousex();
        b=mousey();

        clearmouseclick(WM_LBUTTONDOWN);

      }

      if(ismouseclick(WM_LBUTTONUP)){ ///İkinci nokta seçildi.

        z=mousex();
        t=mousey();

        clearmouseclick(WM_LBUTTONUP);

        int deger=pow(z-a,2)+pow(t-b,2);  ///Değer fonksiyonu iki noktanın farkının karesini buluyor.
        if(deger<0)
            deger=deger*(-1);  ///Bu deger eğer negatifse pozitife çevriliyor.

        int r=sqrt(deger); /// Bulunan farkın kare kökü alınıyor.
    ///Eğer iki noktada barlarda değilse...
    if(b>110 && t>110){
       circle(a,b,r);
       bars_foto(); /// Bars_foto tekrar çalışıyor çünkü oluşan çemberin bir kısmı barlara taşarsa en azından simgeler yenilenebilir.
       }

      }

///Kontrol Noktası
 if(ismouseclick(WM_LBUTTONDOWN)){

               if(mousex()>300 && mousex()<1050 && mousey()>0 && mousey()<100)
                   return 0;

                EditColor();

           }
     }
}
///Barların tanımlandığı fonksiyon
    void bars()
    {

///Seçim kutuları

setfillstyle(1,15);
bar(0,0,150,100);
rectangle(0,0,150,100);

setfillstyle(1,15);
bar(150,0,300,100);
rectangle(150,0,300,100);


setfillstyle(1,15);
bar(300,0,450,100);
rectangle(300,0,450,100);

setfillstyle(1,15);
bar(450,0,600,100);
rectangle(450,0,600,100);


setfillstyle(1,15);
bar(600,0,750,100);
rectangle(600,0,750,100);

setfillstyle(1,15);
bar(750,0,900,100);
rectangle(750,0,900,100);

setfillstyle(1,15);
bar(900,0,1050,100);
rectangle(900,0,1050,100);

setfillstyle(1,15);
bar(1050,0,1200,100);
rectangle(1050,0,1200,100);



///Renk Kutuları

///Üst kısımdaki renkler

setfillstyle(1,15);
bar(1200,0,1250,50);
rectangle(1350,0,1400,50);

setfillstyle(1,7);
bar(1250,0,1300,50);
rectangle(1250,0,1300,50);

setfillstyle(1,14);
bar(1300,0,1350,50);
rectangle(1300,0,1350,50);

setfillstyle(1,6);
bar(1350,0,1400,50);
rectangle(1350,0,1400,50);

setfillstyle(1,12);
bar(1400,0,1450,50);
rectangle(1400,0,1450,50);

setfillstyle(1,3);
bar(1450,0,1500,50);
rectangle(1450,0,1500,50);

setfillstyle(1,10);
bar(1500,0,1550,50);
rectangle(1500,0,1550,50);

setfillstyle(1,9);
bar(1550,0,1600,50);
rectangle(1550,0,1600,50);

///Alt kısımdaki renkler

setfillstyle(1,16);
bar(1200,50,1250,100);
rectangle(1350,50,1400,100);

setfillstyle(1,8);
bar(1250,50,1300,100);
rectangle(1250,50,1300,100);

setfillstyle(1,13);
bar(1300,50,1350,100);
rectangle(1300,50,1350,100);

setfillstyle(1,5);
bar(1350,50,1400,100);
rectangle(1350,50,1400,100);

setfillstyle(1,4);
bar(1400,50,1450,100);
rectangle(1400,50,1450,100);

setfillstyle(1,11);
bar(1450,50,1500,100);
rectangle(1450,50,1500,100);

setfillstyle(1,2);
bar(1500,50,1550,100);
rectangle(1500,50,1550,100);

setfillstyle(1,1);
bar(1550,50,1600,100);
rectangle(1550,50,1600,100);

/// İsimlerin bulunduğu kutu

setfillstyle(1,15);
bar(1600,0,getmaxx(),100);
rectangle(1600,0,getmaxx(),100);

///Program ilk başlarken bars fonksiyonunun içinde simgeler için ayrı bir çağırma kullanmadık. Barlar çağırılınca simgeleride otomatik geliyor.
bars_foto();

    }


int main(){

      initwindow(getmaxwidth( ), getmaxheight( ), "Paint"); ///Pencere tanımlanması
      setlocale(LC_ALL,"Turkish");  ///Türkçe karakter kullanmak için tanımladık.
      floodfill(0,0,WHITE); ///Arka planın beyaz olmasını sağlıyor.
      ///Barlar ekrana geldi ve default renk olarak siyah seçildi.
      bars();
      setcolor(16);
      ///Sürekli olarak kontrol yapılıyor.
       while(1)
       {
       ///İlk seçim yapılıyor.
           if(ismouseclick(WM_LBUTTONDOWN))
           {

               if(mousex()>300 && mousex()<450 && mousey()>0 && mousey()<100)
                   Pencil();

               if(mousex()>450 && mousex()<600 && mousey()>0 && mousey()<100)
                   Line();

               if(mousex()>600 && mousex()<750 && mousey()>0 && mousey()<100)
                   Triangle();

               if(mousex()>750 && mousex()<900 && mousey()>0 && mousey()<100)
                   Rectangle();

               if(mousex()>900 && mousex()<1050 && mousey()>0 && mousey()<100)
                   Circle();

               if(mousex()>1050 && mousex()<1200 && mousey()>0 && mousey()<100)
                   Temizle();

                 EditColor();
           }
       }

///Program kapatılıyor.
   getch();
   closegraph();
   return 0;
}
