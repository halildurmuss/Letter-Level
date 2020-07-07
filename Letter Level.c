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
		f = fopen(dosyaAdi,"r"); //dosya.txt dosyasý okumak ("r") için açýlýyor
	for (i = 0; i < 26; i++) {
		siralama[i] = (char)(i + 'a'); //Siralama arrayine a'dan z ye kadar harfler atiyor
	}

	for (i = 0; i < 26; i++) {
		istatistik[i] = 0; //istatistik arrayiný 0 olarak boþaltýyor
	}
		
	if (f == NULL)
	{
		printf("Dosya okunamadi.\n"); //Dosya bulunamazsa uyarý verip uygulama sonlanýyor.
		return 0;
	}

	while ((c = fgetc(f)) != EOF) { //dosyadan fgetc ile bir karakter okunarak c deðiþkenine atanýyor ondan sonra deðiþken eðer dosya sonu (EOF) deðil ise döngü devam ediyor
		if (c >= 'A' && c <= 'Z') { //A ile Z arasýndaki harfler kontrol ediliyor
			istatistik[c - 'A']++; //Gelen karakter A-Z ise A'nýn ASCII deðeri kadar rakam çýkarlýlýp oluþturulan istatistik arrayinde bir artiþ saðlanýyor A'nýn Rakamsal deðeri 61'dir gelen harfin deðerinden 61 çýktýðý zaman index sýramýz ortaya çýkýyor
		} else if (c >= 'a' && c <= 'z') {
			istatistik[c - 'a']++; //Ayný iþlem yukarýdaki gibi bu sefer küçük harfler için yapýlýyor
		}
	}

	for (i = 0; i < 26; i++) {
		for (j = 0; j < 26; j++) {
			if (istatistik[j] < istatistik[i]) { //istatistikler arasýnda döngü yaparak karþýlaþtýrýyor 
				sayi = istatistik[i]; //eðer karþýlaþtýrdýðý deðer daha büyük ise verilerin yerleri deðiþtiriliyor
				istatistik[i] = istatistik[j];
				istatistik[j] = sayi;

				karakter = siralama[i]; //yerleri deðiþtirilen istatistik deðerlerinin hangi harfe karþýlýk geldiðini bulmak için karþýlýk gelen harfler de yer deðiþtiriliyor
				siralama[i] = siralama[j];
				siralama[j] = karakter;
			}
		}
	}

	for (i = 0; i < 26; ++i) {
		if (istatistik[i]) { //karakterin birden çok çýkýp çýkmadýðýný kontrol ediyor
			printf("%c\t%d\t", siralama[i], istatistik[i]); //siralamada tekrarlanan karakter ve kaç defa tekrarlandýðý yazýlýyor
			for (x = 0; x < istatistik[i]; x++) {
				printf("*"); //tekrarlanma sayýsý kadar yýldýz (*) iþareti konuluyor.
			}
			printf("\n");
		}
	}

diff = clock() - start;
int msec = diff * 1000 / CLOCKS_PER_SEC;
printf("%d saniye %d millisanise", msec/1000, msec%1000);
	
 	getch();//program bittikten sonra bir tuþa basýlmasý için bekliyor.
	return 0;

}

