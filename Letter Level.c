#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
	int dosya;
	int istatistik[26];
	FILE * f;
	int i,j,x;
	char c;
	char dosyaAdi[100];
	char siralama[26];
	int sayi;
	int karakter;
clock_t start, diff;

start = clock();
	printf("Dosya adi giriniz :");
	scanf("%s",&dosyaAdi);
		f = fopen(dosyaAdi,"r"); //dosya.txt dosyas� okumak ("r") i�in a��l�yor
	for (i = 0; i < 26; i++) {
		siralama[i] = (char)(i + 'a'); //Siralama arrayine a'dan z ye kadar harfler atiyor
	}

	for (i = 0; i < 26; i++) {
		istatistik[i] = 0; //istatistik arrayin� 0 olarak bo�alt�yor
	}
		
	if (f == NULL)
	{
		printf("Dosya okunamadi.\n"); //Dosya bulunamazsa uyar� verip uygulama sonlan�yor.
		return 0;
	}

	while ((c = fgetc(f)) != EOF) { //dosyadan fgetc ile bir karakter okunarak c de�i�kenine atan�yor ondan sonra de�i�ken e�er dosya sonu (EOF) de�il ise d�ng� devam ediyor
		if (c >= 'A' && c <= 'Z') { //A ile Z aras�ndaki harfler kontrol ediliyor
			istatistik[c - 'A']++; //Gelen karakter A-Z ise A'n�n ASCII de�eri kadar rakam ��karl�l�p olu�turulan istatistik arrayinde bir arti� sa�lan�yor A'n�n Rakamsal de�eri 61'dir gelen harfin de�erinden 61 ��kt��� zaman index s�ram�z ortaya ��k�yor
		} else if (c >= 'a' && c <= 'z') {
			istatistik[c - 'a']++; //Ayn� i�lem yukar�daki gibi bu sefer k���k harfler i�in yap�l�yor
		}
	}

	for (i = 0; i < 26; i++) {
		for (j = 0; j < 26; j++) {
			if (istatistik[j] < istatistik[i]) { //istatistikler aras�nda d�ng� yaparak kar��la�t�r�yor 
				sayi = istatistik[i]; //e�er kar��la�t�rd��� de�er daha b�y�k ise verilerin yerleri de�i�tiriliyor
				istatistik[i] = istatistik[j];
				istatistik[j] = sayi;

				karakter = siralama[i]; //yerleri de�i�tirilen istatistik de�erlerinin hangi harfe kar��l�k geldi�ini bulmak i�in kar��l�k gelen harfler de yer de�i�tiriliyor
				siralama[i] = siralama[j];
				siralama[j] = karakter;
			}
		}
	}

	for (i = 0; i < 26; ++i) {
		if (istatistik[i]) { //karakterin birden �ok ��k�p ��kmad���n� kontrol ediyor
			printf("%c\t%d\t", siralama[i], istatistik[i]); //siralamada tekrarlanan karakter ve ka� defa tekrarland��� yaz�l�yor
			for (x = 0; x < istatistik[i]; x++) {
				printf("*"); //tekrarlanma say�s� kadar y�ld�z (*) i�areti konuluyor.
			}
			printf("\n");
		}
	}

diff = clock() - start;
int msec = diff * 1000 / CLOCKS_PER_SEC;
printf("%d saniye %d millisanise", msec/1000, msec%1000);
	
 	getch();//program bittikten sonra bir tu�a bas�lmas� i�in bekliyor.
	return 0;

}

