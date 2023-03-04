#include <stdio.h>
#include <conio.h> 
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#define level_bir_adet 12
#define level_iki_adet 16
#define level_uc_adet 20
#define genislik 6
#define yukseklik 7
#define yanyana 4
#define puansinir 15
#define adsinir 15

void gotoxy(int x, int y) {
     
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

void anasayfa();
void level_bir();
void level_iki();
void level_uc();
void kart_yukle();
void ters_kart_diz();
void yazi_yaz(int);
int kart_ac_yazi(int);
void kart_ac(int);
void kontrol_et(int, int);
void kart_kapat(int);
void kart_sil(int);
void yazilari_sil(int);
void bilgisayar_hamle_yap();
int cozum_var_mi();
int aynisi_var_mi();
void level_bitti();
void puan_kaydet(int, int);
void puanlari_sirala();
void puanlari_yaz();
void ipucu();

char level_bir_kartlar[level_bir_adet][yukseklik][genislik];
int level_bir_xy[level_bir_adet][2]={{1,1},{10,1},{19,1},{28,1},{1,10},{10,10},{19,10},{28,10},{1,19},{10,19},{19,19},{28,19}};
char level_bir_ad[level_bir_adet];
int level_bir_acik[level_bir_adet];
char level_bir_acildi[level_bir_adet];

char level_iki_kartlar[level_iki_adet][yukseklik][genislik];
int level_iki_xy[level_iki_adet][2]={{1,1},{10,1},{19,1},{28,1},{1,10},{10,10},{19,10},{28,10},{1,19},{10,19},{19,19},{28,19},{1,28},{10,28},{19,28},{28,28}};
char level_iki_ad[level_iki_adet];
int level_iki_acik[level_iki_adet];
char level_iki_acildi[level_iki_adet];

char level_uc_kartlar[level_uc_adet][yukseklik][genislik];
int level_uc_xy[level_uc_adet][2]={{1,1},{10,1},{19,1},{28,1},{1,10},{10,10},{19,10},{28,10},{1,19},{10,19},{19,19},{28,19},{1,28},{10,28},{19,28},{28,28},{1,37},{10,37},{19,37},{28,37}};
char level_uc_ad[level_uc_adet];
int level_uc_acik[level_uc_adet];
char level_uc_acildi[level_uc_adet];

int pcpuan=0, puan=0, puan2=0, level, adet, dogru=0, no1, no2, hamle=0, secenek, ipucuda=0, ipucu_deger=0;

main(){
       
      anasayfa();
      getch();

}

void anasayfa(){
      int i,j;
      char tus, tus2;
      
      system("CLS");
      
      gotoxy(50,20);
      printf("(TAM EKRAN OYNAYINIZ.)");

      for(j=0; j<6; j++){
          gotoxy(60,2+(j*1));         
          for(i=0; i<7;i++){
                printf("%c",176);
          }
      }

      for(j=0; j<6; j++){
          gotoxy(63,4+(j*1));         
          for(i=0; i<7;i++){
                printf("%c",219);
          }
      }
      
      gotoxy(9,7);
      printf(" Kartlari Eslestir Oyununa Hosgeldiniz! ");
      gotoxy(10,10);
      printf("Oyuna Baslamak Icin 1'e Basiniz...");
      gotoxy(10,13);
      printf("Puan tablosunu gormek icin 2'ye Basiniz...");
      
      while (1) {
        if (kbhit()) {
             tus = getch ();
             switch (tus) {
                   case '1':
                   system("CLS");          
                   gotoxy(10,10);
                   printf("Bilgisayara karsi oynamak icin 1'e Basiniz...");
                   gotoxy(10,13);
                   printf("Tek basina oynamak icin 2'ye Basiniz...");   
                   gotoxy(10,16);
                   printf("Iki kisi oynamak icin 3'e Basiniz...");     
                   while (1) {
                     if (kbhit()) {
                         tus2 = getch ();
                         if(tus2 == '1'){
                           secenek=1;
                           level_bir();
                           break;
                         }
                         else if(tus2 == '2'){
                           secenek=2;
                           level_bir();
                           break;
                         }
                         else if(tus2 == '3'){
                           secenek=3;
                           level_bir();
                           break;
                         }              
                     }                            
                   }
                   break;
                   case '2':
                   puanlari_yaz();
                   break;
             }              
        }                            
      }
     
}

void level_bir(){
     int i;
     level=1;
     adet=level_bir_adet;
     puan=0;
     pcpuan=0;
     puan2=0;
     hamle=0;
     dogru=0;
     ipucu_deger=0;
     system("CLS");
     
     gotoxy(15,13);
     printf("LEVEL 1");
     sleep(1000);
     system("CLS");

     for(i=0; i<level_bir_adet; i++){
           level_bir_acik[i]=0;
           level_bir_acildi[i]='i';
     }
     
     kart_yukle();
     ters_kart_diz();
}

void level_iki(){
     int i;
     level=2;
     hamle=0;
     dogru=0;
     adet=level_iki_adet;
     ipucu_deger=0;
     system("CLS");
     
     gotoxy(15,13);
     printf("LEVEL 2");
     sleep(1000);
     system("CLS");

     for(i=0; i<level_iki_adet; i++){
           level_iki_acik[i]=0;
           level_iki_acildi[i]='i';
     }

     kart_yukle();
     ters_kart_diz();
}

void level_uc(){
     int i;
     level=3;
     hamle=0;
     dogru=0;
     adet=level_uc_adet;
     ipucu_deger=0;
     system("CLS");
     
     gotoxy(15,13);
     printf("LEVEL 3");
     sleep(1000);
     system("CLS");
     
     for(i=0; i<level_uc_adet; i++){
           level_uc_acik[i]=0;
           level_uc_acildi[i]='i';
     }
     
     kart_yukle();
     ters_kart_diz();
}

void kart_yukle(){
      FILE *dosya;
      int i, j; 
      int rastgele[adet],sayi,yok=0;
      
      srand(time(NULL));
      
      if(level==1){
         dosya = fopen ("girdiler/level_1_1.txt","r"); 
          
      }
      else if(level==2){
         dosya = fopen ("girdiler/level_2_1.txt","r");  
      }
      else if(level==3){
         dosya = fopen ("girdiler/level_3_1.txt","r");  
      }
      
      for(i=0; i<adet; i++){
            rastgele[i]=-1;
      }
      
      for(i=0; i<adet; i++){
          while(1){
              yok=1;
              sayi=rand()%adet;
              for(j=0; j<adet; j++){
                    if(rastgele[j] == sayi){
                         yok=0;
                         break;
                    }
              }  
              if(yok == 1){
                   rastgele[i]=sayi;
                   break;
              }     
          } 
          
      }
      
      for(i=0; i<adet; i++){
          for(j=0; j<yukseklik; j++){
              if(level==1){
                 fscanf (dosya, "%c%c%c%c%c%c%c\n",&level_bir_kartlar[rastgele[i]][j][0],&level_bir_kartlar[rastgele[i]][j][1],&level_bir_kartlar[rastgele[i]][j][2],&level_bir_kartlar[rastgele[i]][j][3],&level_bir_kartlar[rastgele[i]][j][4],&level_bir_kartlar[rastgele[i]][j][5],&level_bir_ad[rastgele[i]]);   
              }
              else if(level==2){
                 fscanf (dosya, "%c%c%c%c%c%c%c\n",&level_iki_kartlar[rastgele[i]][j][0],&level_iki_kartlar[rastgele[i]][j][1],&level_iki_kartlar[rastgele[i]][j][2],&level_iki_kartlar[rastgele[i]][j][3],&level_iki_kartlar[rastgele[i]][j][4],&level_iki_kartlar[rastgele[i]][j][5],&level_iki_ad[rastgele[i]]);
              }
              else if(level==3){
                 fscanf (dosya, "%c%c%c%c%c%c%c\n",&level_uc_kartlar[rastgele[i]][j][0],&level_uc_kartlar[rastgele[i]][j][1],&level_uc_kartlar[rastgele[i]][j][2],&level_uc_kartlar[rastgele[i]][j][3],&level_uc_kartlar[rastgele[i]][j][4],&level_uc_kartlar[rastgele[i]][j][5],&level_uc_ad[rastgele[i]]);
              }
          }      
      }     
      
      fclose(dosya);
}

void ters_kart_diz(){
     int i, j, k, m,z=1,p=0;
     
      printf("\n");
      for(m=0; m<(adet/yanyana); m++){
          for(i=0;i<yukseklik;i++){
              printf(" ");
              for(k=0;k<yanyana;k++){
                  for(j=0; j<genislik; j++){
                        if(j==0 && i==0){
                           printf("%d",z);
                           if(z>9){
                                p=1;
                           }
                           z++;  
                        }
                        else{
                             if(p!=1){
                                printf("%c",219);
                             }
                             p--;
                        }
                  }
                  printf("   ");
              }
              printf("\n");
          }
          printf("\n\n");     
      }
      
      yazi_yaz(1);
}

void yazi_yaz(int x){
     char tus;
     int sayi=0,sonuc,sonuc2;
     
     if(secenek == 1){
          if(hamle%2==0){
             gotoxy(48,4);
             printf("  ");             
             gotoxy(48,2);
             printf("%c ", 175);               
          }
          else if(hamle%2==1){
             gotoxy(48,2);
             printf("  ");
             gotoxy(48,4);
             printf("%c ", 175);               
          }
          gotoxy(50,2);
          printf("Sizin Puaniniz:%d", puan);
          gotoxy(50,4);
          printf("Bilgisayarin Puanini:%d", pcpuan);
     }
     else if(secenek==2){
          gotoxy(50,4);
          printf("Puaniniz:%d", puan);
     }
     else if(secenek == 3){
          if(hamle%2==0){
             gotoxy(48,4);
             printf("   ");             
             gotoxy(48,2);
             printf("%c ", 175);               
          }
          else if(hamle%2==1){
             gotoxy(48,2);
             printf("  ");
             gotoxy(48,4);
             printf("%c ", 175);               
          }
          gotoxy(50,2);
          printf("1.Oyuncu Puani:%d", puan);
          gotoxy(50,4);
          printf("2.Oyuncu Puaniniz:%d", puan2);
     }
     
     if(ipucu_deger == 0){
         gotoxy(50,25);
         printf("* Ipucu icin ilk girise"); 
         gotoxy(52,27);
         printf("100 yaziniz.");
     }
     if(x==1){
         while(1){
              sonuc=kart_ac_yazi(x);
              if(sonuc!=-1){
                 x++;
                 break;          
              }
         }  
     }

     if(x==2){     
         while(1){
              sonuc2=kart_ac_yazi(x);
              if(sonuc2!=-1){
                 break;          
              }
         }
         
         kontrol_et(sonuc, sonuc2);
     }
     
     if(x==3){     
         gotoxy(50,8);
         printf("Bilgisyar hamle yapiyor...");    
     }
     
}

int kart_ac_yazi(int a){
     int sayi, sonuc,acik=0;
     
     gotoxy(50,a*7);
     printf("Acmak istediginiz kartin");
     gotoxy(50,(a*7)+2);
     printf("numarasini giriniz:");
     scanf("%d",&sayi);
     
     if(level==1){
          acik=level_bir_acik[sayi-1];
     }
     else if(level==2){
          acik=level_iki_acik[sayi-1];
     }
     else if(level==3){
          acik=level_uc_acik[sayi-1];
     }
     
     if(sayi>0 && sayi<=adet && acik == 0){
          sonuc=sayi-1; 
          if(level==1){
              kart_ac(sayi-1);
          }
          else if(level==2){
              kart_ac(sayi-1);
          }
          else if(level==3){
              kart_ac(sayi-1);
          }
     }
     else if(a == 1 && sayi == 100 && ipucu_deger == 0){
          gotoxy(50,25);
          printf("                            "); 
          gotoxy(52,27);
          printf("             ");
          ipucu();
          ipucu_deger=1;
          yazilari_sil(1);
          yazi_yaz(1);  
     }
     else{
          sonuc=-1;
          gotoxy(50,(a*7)+4);
          printf("Hatali Giris");   
          sleep (500);
          gotoxy(50,10);
          yazilari_sil(a);
          yazi_yaz(a);   
     }
     
     return sonuc;
}

void kart_ac(int a){
     int i, j;
     
     if(ipucuda == 0){
         if(level==1){
              level_bir_acildi[a]=level_bir_ad[a];
         }
         else if(level==2){
              level_iki_acildi[a]=level_iki_ad[a];
         }
         else if(level==3){
              level_uc_acildi[a]=level_uc_ad[a];
         }
     }


     if(level==1){
         level_bir_acik[a]=1;

         for(i=level_bir_xy[a][1]; i<(level_bir_xy[a][1]+yukseklik); i++){
             for(j=level_bir_xy[a][0]; j<(level_bir_xy[a][0]+genislik); j++){
                   gotoxy(j,i);
                   printf("%c",level_bir_kartlar[a][i-level_bir_xy[a][1]][j-level_bir_xy[a][0]]);
             }  
         }
     }
     else if(level==2){
         level_iki_acik[a]=1;

         for(i=level_iki_xy[a][1]; i<(level_iki_xy[a][1]+yukseklik); i++){
             for(j=level_iki_xy[a][0]; j<(level_iki_xy[a][0]+genislik); j++){
                   gotoxy(j,i);
                   printf("%c",level_iki_kartlar[a][i-level_iki_xy[a][1]][j-level_iki_xy[a][0]]);
             }  
         }
     }
     else if(level==3){
         level_uc_acik[a]=1;

         for(i=level_uc_xy[a][1]; i<(level_uc_xy[a][1]+yukseklik); i++){
             for(j=level_uc_xy[a][0]; j<(level_uc_xy[a][0]+genislik); j++){
                   gotoxy(j,i);
                   printf("%c",level_uc_kartlar[a][i-level_uc_xy[a][1]][j-level_uc_xy[a][0]]);
             }  
         }
     }
     
}

void kontrol_et(int a, int b){
     
     char ad1,ad2;     
     
     if(level==1){          
        ad1=level_bir_ad[a];
        ad2=level_bir_ad[b];          
     }   
     else if(level==2){
        ad1=level_iki_ad[a];
        ad2=level_iki_ad[b];      
     }
     else if(level==3){
        ad1=level_uc_ad[a];
        ad2=level_uc_ad[b]; 
     }
     
     if(ad1 == ad2){
          if(secenek == 2){
               puan+=10;
          }
          else if(secenek == 1 && hamle%2 == 0){
               puan+=10;
          }
          else if(secenek == 1 && hamle%2 == 1){
               pcpuan+=10;
          }
          else if(secenek == 3 && hamle%2 == 0){
               puan+=10;
          }
          else if(secenek == 3 && hamle%2 == 1){
               puan2+=10;
          }
          gotoxy(50, 20);
          printf("Kartlar Ayni!");
          sleep (2000);
          kart_sil(a);
          kart_sil(b);
          gotoxy(50, 20);
          printf("                        ");
          hamle++;
          dogru++;
          if(dogru==adet/2){
             level_bitti();               
          }
          else{
               yazilari_sil(1);
               yazilari_sil(2);
               if(secenek == 2){
                  yazi_yaz(1);
               }
               else if(secenek == 1 && hamle%2 == 0){
                  yazi_yaz(1);
               }
               else if(secenek == 3){     
                  yazi_yaz(1);
               }
               else {
                  yazi_yaz(3);
                  bilgisayar_hamle_yap();
               }
          }
     }
     else{    
          if(secenek == 2){
             puan--;
          }
          else if(secenek == 1 && hamle%2 == 0){
             puan--;
          }
          else if(secenek == 1 && hamle%2 == 1){
             pcpuan--;
          }
          else if(secenek == 3 && hamle%2 == 0){
               puan--;
          }
          else if(secenek == 3 && hamle%2 == 1){
               puan2--;
          }
          gotoxy(50, 20);
          printf("Kartlar Ayni Degil!");
          sleep (2000);
          gotoxy(50, 20);
          printf("                        ");
          kart_kapat(a);
          kart_kapat(b);
          hamle++;
          yazilari_sil(1);
          yazilari_sil(2);
          
          if(secenek == 2){
               yazi_yaz(1);
          }
          else if(secenek == 1 && hamle%2 == 0){
               yazi_yaz(1);
          }
          else if(secenek == 3){     
               yazi_yaz(1);
          }
          else {
               yazi_yaz(3);
               bilgisayar_hamle_yap();
          }
     }
}

void kart_kapat(int a){
     int i, j, p=0;
     
     if(level==1){
         level_bir_acik[a]=0;
         
         for(i=level_bir_xy[a][1]; i<(level_bir_xy[a][1]+yukseklik); i++){
             for(j=level_bir_xy[a][0]; j<(level_bir_xy[a][0]+genislik); j++){
                   gotoxy(j,i);
                   if(j==level_bir_xy[a][0] && i==level_bir_xy[a][1]){
                       printf("%d",a+1);
                       if(a+1>9){
                            p=1;
                       } 
                   }
                   else{
                       if(p!=1){
                          printf("%c",219);
                       }
                       p--;
                   }
             }  
         }
     }
     else if(level==2){
         level_iki_acik[a]=0;
         
         for(i=level_iki_xy[a][1]; i<(level_iki_xy[a][1]+yukseklik); i++){
             for(j=level_iki_xy[a][0]; j<(level_iki_xy[a][0]+genislik); j++){
                   gotoxy(j,i);
                   if(j==level_iki_xy[a][0] && i==level_iki_xy[a][1]){
                       printf("%d",a+1);
                       if(a+1>9){
                            p=1;
                       } 
                   }
                   else{
                       if(p!=1){
                          printf("%c",219);
                       }
                       p--;
                   }
             }  
         }
     }
     else if(level==3){
         level_uc_acik[a]=0;
         
         for(i=level_uc_xy[a][1]; i<(level_uc_xy[a][1]+yukseklik); i++){
             for(j=level_uc_xy[a][0]; j<(level_uc_xy[a][0]+genislik); j++){
                   gotoxy(j,i);
                   if(j==level_uc_xy[a][0] && i==level_uc_xy[a][1]){
                       printf("%d",a+1);
                       if(a+1>9){
                            p=1;
                       } 
                   }
                   else{
                       if(p!=1){
                          printf("%c",219);
                       }
                       p--;
                   }
             }  
         }
     }
          
}

void kart_sil(int a){
     int i, j;

     if(level==1){
         level_bir_acik[a]=2;

         for(i=level_bir_xy[a][1]; i<(level_bir_xy[a][1]+yukseklik); i++){
             for(j=level_bir_xy[a][0]; j<(level_bir_xy[a][0]+genislik); j++){
                   gotoxy(j,i);
                   printf(" ");
             }  
         }
     }
     else if(level==2){
         level_iki_acik[a]=2;

         for(i=level_iki_xy[a][1]; i<(level_iki_xy[a][1]+yukseklik); i++){
             for(j=level_iki_xy[a][0]; j<(level_iki_xy[a][0]+genislik); j++){
                   gotoxy(j,i);
                   printf(" ");
             }  
         }
     }
     else if(level==3){
         level_uc_acik[a]=2;

         for(i=level_uc_xy[a][1]; i<(level_uc_xy[a][1]+yukseklik); i++){
             for(j=level_uc_xy[a][0]; j<(level_uc_xy[a][0]+genislik); j++){
                   gotoxy(j,i);
                   printf(" ");
             }  
         }
     }
     
     
}

void yazilari_sil(int a){
     gotoxy(50,2);
     printf("                               ");
     gotoxy(50,4);
     printf("                               ");
     gotoxy(50,8);
     printf("                               ");
     gotoxy(50,a*7);
     printf("                           ");
     gotoxy(50,(a*7)+2);
     printf("                           ");
     gotoxy(50,(a*7)+4);
     printf("                           ");      
}

void bilgisayar_hamle_yap(){
     int i, j, var=0, var2=0, tekrar=0;
     
     
     srand(time(NULL));
    
     var=cozum_var_mi();
                  
     if(var==1){
          kart_ac(no1);
          sleep(1000);
          kart_ac(no2);
          kontrol_et(no1, no2);  
     }
     else{
              while(1){
                   
                   no1=rand()%adet;
                   if(level==1){
                        if(level_bir_acik[no1]==0){
                             break;
                        }
                   }  
                   else if(level==2){
                        if(level_iki_acik[no1]==0){
                             break;
                        }
                   }
                   else if(level==3){
                        if(level_uc_acik[no1]==0){
                             break;
                        }
                   } 
              }
              kart_ac(no1);
              sleep(1000);
              var2=aynisi_var_mi(no1);
              if(var2==1){
                   kart_ac(no2);
                   kontrol_et(no1,no2);
              }
              else{
                   while(1){
                       while(1){
                           tekrar=0;
                           no2=rand()%adet;
                           for(i=0; i<adet; i++){
                               if(level==1){
                                    if(level_bir_acildi[no2]!='i'){
                                         tekrar=1;
                                         break;
                                    }
                               }  
                               else if(level==2){
                                    if(level_iki_acildi[no2]!='i'){
                                         tekrar=1;
                                         break;
                                    }
                               }
                               else if(level==3){
                                    if(level_uc_acildi[no2]!='i'){
                                         tekrar=1;
                                         break;
                                    }
                               }
                           }
                           
                           if(tekrar==0){
                                break;
                           }
                       }
                       if(level==1){
                            if(level_bir_acik[no2]==0){
                                 break;
                            }
                       }  
                       else if(level==2){
                            if(level_iki_acik[no2]==0){
                                 break;
                            }
                       }
                       else if(level==3){
                            if(level_uc_acik[no2]==0){
                                 break;
                            }
                       } 
                   }
                   kart_ac(no2);
                   kontrol_et(no1,no2);
              }
     }
     
}

int cozum_var_mi(){
    
     int i, j, var=0;
     
     for(i=0; i<adet; i++){
         for(j=0; j<adet; j++){
               if(level==1){
                  if(level_bir_acildi[i] == level_bir_acildi[j] && level_bir_acildi[i] != 'i' && level_bir_acildi[j] != 'i' && i != j && level_bir_acik[i] == 0 && level_bir_acik[i] == 0){
                     no1=i;
                     no2=j;
                     var=1;
                     break;  
                  }
               }
               else if(level==2){
                  if(level_iki_acildi[i] == level_iki_acildi[j] && level_iki_acildi[i] != 'i' && level_iki_acildi[j] != 'i' && i != j && level_iki_acik[i] == 0 && level_iki_acik[i] == 0){
                     no1=i;
                     no2=j;
                     var=1;
                     break;  
                  }
               }
               else if(level==3){
                  if(level_uc_acildi[i] == level_uc_acildi[j] && level_uc_acildi[i] != 'i' && level_uc_acildi[j] != 'i' && i != j && level_uc_acik[i] == 0 && level_uc_acik[i] == 0){
                     no1=i;
                     no2=j;
                     var=1;
                     break;  
                  }
               }
         }           
     }
     
     return var;     
}

int aynisi_var_mi(int a){
    
     int j, var=0;

     for(j=0; j<adet; j++){
           if(level==1){
              if(level_bir_acildi[a] == level_bir_acildi[j] && a != j){
                 no2=j;
                 var=1;
                 break;  
              }
           }
           else if(level==2){
              if(level_iki_acildi[a] == level_iki_acildi[j] && a != j){
                 no2=j;
                 var=1;
                 break;  
              }
           }
           else if(level==3){
              if(level_uc_acildi[a] == level_uc_acildi[j] && a != j){
                 no2=j;
                 var=1;
                 break;  
              }
           }
     }           
     
     return var;     
}

void level_bitti(){
     
       while(1){            
           char giris, giris2;
           
           if(level==3){
                giris=50;
           }
           else{
               system("CLS");
               gotoxy(10,7);
               printf("Level %d tamamlandi.",level);
               gotoxy(10,10);
               printf("%d.Level'e gecmek icin 1'e basiniz.\n",level+1);
               gotoxy(10,13);
               printf("Oyunu bitirmek icin 2'ye basiniz.");
               giris=getch();
           }
           if(giris==49){
              if(level==1){
                   level_iki();
              }
              else if(level==2){
                   level_uc();
              }
              break;          
           }
           
           else if(giris==50){
               while(1){
                   system("CLS");
                   if(secenek==3){
                      gotoxy(10,7);
                      printf("Oyun Bitti 1.Oyuncu Puan:%d, 2.Oyuncu Puan:%d",puan,puan2);  
                   }
                   else{
                      gotoxy(10,7);
                      printf("Oyun Bitti Puaniniz:%d",puan);
                   }
                   gotoxy(10,10);
                   printf("Puaninizi kaydetmek icin 1'e basiniz.");
                   gotoxy(10,13);
                   printf("Anasayfaya gitmek icin 2'ye basiniz.");
                   giris=getch();
                   if(giris==49){
                      if(secenek==3){
                           while(1){
                               system("CLS");
                               gotoxy(10,7);
                               printf("Sadece 1.Oyuncu'nun puaninini kaydetmek icin 1'e basiniz.");
                               gotoxy(10,10);
                               printf("Sadece 2.Oyuncu'nun puaninini kaydetmek icin 2'ye basiniz.");
                               gotoxy(10,13);
                               printf("Her iki oyuncunun puaninini kaydetmek icin 3'e basiniz.");
                               giris2=getch();
                               if(giris2==49){
                                  puan_kaydet(puan,0);
                                  break;          
                               }
                               else if(giris2==50){
                                  puan_kaydet(puan2,0);
                                  break;          
                               }
                               else if(giris2==51){
                                  puan_kaydet(puan,1);
                                  puan_kaydet(puan2,0);
                                  break;          
                               }
                           } 
                      }
                      else{
                         puan_kaydet(puan,0);
                         break;
                      }          
                   }
                   else if(giris==50){
                      anasayfa();
                      break;          
                   }
               }         
           }
       }     
}

void puan_kaydet(int p, int bekle){
      FILE *dosya1;
      char kullaniciadi[adsinir]={0};
      int i;
      
      system("CLS");
      
      dosya1 = fopen ("girdiler/puantablosu.txt","a");
      
      gotoxy(15,5);
      printf("Adinizi giriniz:");
      scanf("%s", &kullaniciadi);
      
      for(i=0; i<adsinir; i++){
          fprintf (dosya1, "%c",kullaniciadi[i]);      
      }

      fprintf (dosya1, " %d\n", p);

      fclose(dosya1);
      
      if(bekle==0){
         puanlari_sirala();
         puanlari_yaz();  
      }
      
}

void puanlari_sirala(){
      FILE *dosya;
      char cumle[puansinir+1][adsinir]={0};
      int puan2[puansinir+1], puan3[puansinir+1], sira[puansinir+1];
      int i,a,son,maks,maksi;
      
      dosya = fopen ("girdiler/puantablosu.txt","r");

      
      for(a=0; a<puansinir+1; a++){
          for(i=0; i<adsinir; i++){
              fscanf (dosya, "%c",&cumle[a][i]);      
          }
          fscanf (dosya, "%d\n", &puan2[a]); 
          
          puan3[a]=puan2[a];
          
          if(feof(dosya)){
               son=a+1;
               break;
          }
          
      }
          
      fclose(dosya);
      
      for(a=0; a<son; a++){
          maks=0;         
          for(i=0; i<son; i++){
                if(puan2[i]>maks){
                    maks=puan2[i];  
                    maksi=i;      
                }
          }
          puan2[maksi]=0;
          sira[a]=maksi;
      }
      
      if(son==puansinir+1){
          son--;
      }
      
      dosya = fopen ("girdiler/puantablosu.txt","w");
      
      for(a=0; a<son; a++){
          for(i=0; i<adsinir; i++){
              fprintf (dosya,"%c",cumle[sira[a]][i]);      
          }
          fprintf(dosya," %d\n", puan3[sira[a]]);
      }

      fclose(dosya);     
}

void puanlari_yaz(){
     
      FILE *dosya1;
      char cumle[adsinir],giris;
      int deger, basla=5,sayi=1;
      
      system("CLS");
      
      gotoxy(10,basla-3);
      printf("Ad:");
      gotoxy(25,basla-3);
      printf("Puan:");
  
      dosya1 = fopen ("girdiler/puantablosu.txt","r");

      while(1){
          fscanf (dosya1, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %d\n",&cumle[0],&cumle[1],&cumle[2],&cumle[3],&cumle[4],&cumle[5],&cumle[6],&cumle[7],&cumle[8],&cumle[9],&cumle[10],&cumle[11],&cumle[12],&cumle[13],&cumle[14],&deger);
          gotoxy(7,basla);
          printf("%d) %s ",sayi,cumle);
          gotoxy(25,basla);
          printf("%d puan\n",deger);
          basla+=3;
          sayi++;
          if(feof(dosya1)){
              break; 
          }
      }
          
      fclose(dosya1);
          gotoxy(10,basla); 
          printf("Anasayfaya gitmek icin 1'e basiniz.");
      while(1){
          giris=getch();
          if(giris==49){
              anasayfa();
              break;          
          }
      }
}

void ipucu(){
     int i, j, a;

     ipucuda=1;
     
     for(a=0; a<adet; a++){
         if(level==1){
             if(level_bir_acik[a]==0){
                kart_ac(a);
             }
         }
         else if(level==2){
             if(level_iki_acik[a]==0){
                kart_ac(a);
             }
         }
         else if(level==3){
             if(level_uc_acik[a]==0){
                kart_ac(a);
             }
         }                   
     }
     
     ipucuda=0;
     
     sleep(1000);

     for(a=0; a<adet; a++){
         if(level==1){
             if(level_bir_acik[a]==1){
                kart_kapat(a);
             }
         }
         else if(level==2){
             if(level_iki_acik[a]==1){
                kart_kapat(a);
             }
         }
         else if(level==3){
             if(level_uc_acik[a]==1){
                kart_kapat(a);
             }
         }                   
     }     
     

}


