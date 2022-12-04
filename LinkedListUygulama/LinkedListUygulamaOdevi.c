#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct node 
{
	int no; 
	char ad[30]; 
	char soyad[30]; 
	int final; 
	int vize; 
	
	
	struct node *prev; 
	struct node *next; 

};

int cnt=0;
typedef struct node inf;
inf *head=NULL;


void ekleme (int n, char *a, char *s, int v, int f)
{ 
	system("cls"); 

	inf *ogr= (inf*) malloc(sizeof(inf));
	ogr->no= n; 
	strcpy(ogr->ad, a);
	strcpy(ogr->soyad, s); 
	ogr->vize= v; 
	ogr->final= f;

	if (head==NULL) 
	{
		head=ogr; 
		head->next= head; 
		head->prev= head; 
		cnt++;
		printf("%d Numarali Ogrenci Eklendi \n", head->no);  
	}

	else 
	{
		inf * p= head;
		while(p->next!=head)
		p= p->next;


		ogr->next= head;
		head->prev= ogr;  
		head=ogr;    
		p->next= head;
		head->prev= p;
		cnt++;
		printf("%d Numarali Ogrenci Listeye Eklendi \n", head->no); 
	}
}

void cikarma()
{
	system("cls");
	if (head==NULL)
	{
		printf("Listede Kayıtlı Ogrenci Yok! \n"); 
	} 
	else 
	{ 
		int ogrNo; 
		printf("\nSilinecek Ogrencinin Numarasini Giriniz \n ") ; scanf ("%d", &ogrNo); 

		if(cnt==1 && head->no == ogrNo)
		{
		printf("Kayitli Son Ogrenci de Silindi \n"); 
		free(head); 
		head==NULL;
		cnt--;
		}
		else if (cnt!=1 && head->no == ogrNo)
		{
		printf("%d Numarali Ogrenci Silindi \n", head->no); 
		inf *p = head;
		while(p->next!=head)
		p= p->next;
	
		inf *p2 = head->next;
		free(head);
		head=p2;
	
		head->prev= p;
		p->next= head;
		cnt--;
		}
		else
		{
			inf *p = head; 
			inf *p2 = head; 
			inf *p3 = head; 
	
			while(p->next!=head)
			{
				if(p->no==ogrNo)
				{
				printf("%d Nummarali Ogrenci Silindi \n", p->no );
				p3= p->next;
				free(p);
				p2->next= p3;
				p3->prev= p2;
				cnt--;
				break;
				}
	
				p2= p;
				p= p->next;
			}
			if(p->no==ogrNo)
				{
					printf("%d Nummarali Ogrenci Silindi \n", p->no );
					free(p);
					p2->next= head;
					head->prev= p2;
					cnt--;
				}
		} 
	} 
}

void yazdirma() 
{
	system("cls"); 
	if(head==NULL)
	{
		printf("Liste Bos, Listelenecek Ogrenci Yok \n"); 
	}
	else
	{
		inf * p= head;
		while(p->next!=head)
		{
			printf("%d Numarali Ogrencinin Adi: %s Soyadi: %s Vize Notu: %d Final Notu: %d \n", p->no, p->ad, p->soyad, p->vize, p->final);
			
			p= p->next;
		}
		printf("%d Numarali Ogrencinin Adi: %s Soyadi: %s Vize Notu: %d Final Notu: %d \n", p->no, p->ad, p->soyad, p->vize, p->final);	 
	}
}

void dosyayaYaz()
{
	system("cls");
	if(head==NULL)
	{ 
		printf("Liste Bos, Kaydedilecek Bilgi Yok \n"); 
	}
	else 
	{
		inf * p= head;    
		FILE *dosya = fopen("OgrenciBilgileri.txt", "a+"); 
		while(p->next!=head) 
		{   
			fprintf( dosya, "%d %s %s %d %d \n", p->no, p->ad, p->soyad, p->vize, p->final); 
			p= p->next;
		}
		fprintf( dosya, "%d %s %s %d %d ", p->no, p->ad, p->soyad, p->vize, p->final);  
		fclose(dosya); 
		printf("Girilen Bilgiler Dosyaya Kaydedildi\n");   
	}
}


void bonus()
{
	
	FILE *dosya = fopen("OgrenciBilgileri.txt", "r+");
	
	while(!feof(dosya))
	{
		int n, v, f;
		char a[30], s[30];
		fscanf(dosya, "%d%s%s%d%d", &n,a,s,&v,&f);
		ekleme(n,a,s,v,f); 
		
	}
	fclose(dosya); 
	system("cls"); 
	printf("Girilen Bilgiler Basarili Bir Sekilde Okundu Lutfen Gormek Icin 3'e Basiniz.'\n");
}

void ara()
{
	system("cls"); 
	FILE *dosya = fopen("OgrenciBilgileri.txt", "r");
	char isim[30];
	int no; 
	char ad[30]; 
	char soyad[30]; 
	int final; 
	int vize; 
	printf("Arancak Ogrencinin Ismini Giriniz: "); scanf("%s", isim);

	while(!feof(dosya))
	{
		fscanf(dosya, "%d%s%s%d%d", &no,ad,soyad,&vize,&final);
		if( strcmp (isim,ad) ==0 )
		{
			printf("Numarasi : %d \n Adi : %s \n Soyadi : %s \n Vize Notu : %d \n Final Notu : %d \n", no,ad,soyad,vize,final ); 
			break;
		}
		
	}
		
}

int main() 
{
	system("Color 1");
	int secim; 
	int no,  vize, final; 
	char ad[30], soyad[30]; 
	while(1) 
	{
		printf("\n\t\t\t\t  OGRENCI KAYIT SISTEMI MENUSU  \n"); 
		printf("\n\t\t\t\t      Lutfen Secim Yapiniz \n"); 
		printf("\n\t\t\t\t 1 EKLE "); 
		printf("\n\t\t\t\t 2 SIL "); 
		printf("\n\t\t\t\t 3 LISTELE "); 
		printf("\n\t\t\t\t 4 DOSYAYA YAZ "); 
		printf("\n\t\t\t\t 5 DOSYADAN ONCE OKU SONRA YAZ "); 
		printf("\n\t\t\t\t 6 TEK TEK OGRENCI CAGIR");
		printf("\n\t\t\t\t 0 CIKIS YAP "); 
		scanf("%d", &secim); 
		switch(secim) 
		{ 
			case 1: 
	
			printf("\t Ogrenci Numara  :"); 
			scanf("%d", &no); 
			printf("\t Ogrenci Ad  :");
			scanf("%s", &ad); 
			printf("\t Ogrenci Soyad :"); 
			scanf("%s", &soyad); 
			printf("\t Ogrenci Vize  :"); 
			scanf("%d", &vize); 
			printf("\t Ogrenci Final :"); 
			scanf("%d", &final); 
			ekleme(no, ad, soyad, vize, final); 
			break; 
	
			case 2: cikarma(); 
			break; 
			
			case 3: yazdirma(); 
			break; 
			
			case 4: dosyayaYaz(); 
			break; 
			
			case 5: bonus();
			break;
			
			case 6: ara();
			break;
			
			case 0: return 0;
		   	
			default : printf("\n YANLIS ISLEM! \n\n\n"); 
		}
	}
}