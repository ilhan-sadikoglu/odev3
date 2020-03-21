#include <iostream>
#include <vector>
#include <iomanip>
#include <chrono>

using namespace std;

// Bu odevde global veya statik degisken tanimlanamaz!!!

/* Ozyinelemeli olarak zip zip kurbaganin kac farkli yoldan gittigini bulan fonksiyondur.
 * Bu fonksiyon icinde for ve while kullanamazsiniz ve en az bir kez recursiveFunction
 * fonksiyonu cagri yapilmalidir.
 */
long long recursiveFunction(int n)
{
	static long long int denenenler[100];//kodun optimize cal��mas� i�in memoization kulland�m
	//2 , 0 ve 1 �zel durum-basecase olur 
	if (n == 2) 
		return 2;
	
	if (n == 0) 
		return 1;
	
	if (n == 1) 
		return 1;
	
	if(n>2) {//e�er basecase de�ilse
		long long int yol, uc, iki;

		if (denenenler[n] != 0)//e�er daha �nceden hesaplanm��sa o de�eri kullan�r
			uc = denenenler[n];
		else
			uc = recursiveFunction(n - 3);

		if (denenenler[n] != 0)//e�er daha �nceden hesaplanm��sa o de�eri kullan�r
			iki = denenenler[n];
		else
			iki = recursiveFunction(n - 2);

		yol = uc + iki;


		if (denenenler[n] != 0)//e�er daha �nceden hesaplanm��sa o de�eri kullan�r
			return denenenler[n];

		else {


			denenenler[n] = yol + recursiveFunction(n - 1);

			return denenenler[n];
		}
	}




	
}

/* Yinelemeli olarak zip zip kurbaganin kac farkli yoldan gittigini bulan fonksiyondur.
 * Bu fonksiyon icinde for ve while dongusu kullanilmalidir.
 * Bu fonksiyon icinde baska bir fonksiyona (kendisi dahil) cagri yapilamaz.
 */
long long iterativeFunction(int n)
{
	int iki = 0, uc = 0, a = n;
	long long adim = 0;
	while (0 <= a) { //olabilecek maksimum 3 ad�m say�s�n� hesapl�yoruz
		a -= 3;
		uc++;
	}
	uc--;

	for (int i = 0; i <= uc; ++i) { // 3 ad�m say�s� 0 olacak �ekilde ba�l�yoruz. sonra artt�rarak tekrar ediyoruz
		int b = n - i * 3;

		iki = 0;
		while (0 <= b) {// ayn� �ekilde maksimum 2 say�s�n� hesapl�yoruz
			b -= 2;
			iki++;
		}
		iki--;
		for (int c = 0; c <= iki; ++c) {
			int bir = n - (i * 3 + c * 2);
			//cout << "uc " << i << endl << "iki " << c << endl << "bir " << bir << endl << endl;
			//burdan itibaren permutasyon hesaplanacak
			
			int factop[100];
			int fac3[100];
			int fac2[100];


			for (int k = 0; k < (c + i); k++)
				factop[k]= bir + k+1; //birleri g�rmezden gelerek toplam s�ralanacak �ge miktar�n� ekler
			for (int k = 1; k <= i; k++)
				fac3[k - 1] = k;
			for (int k = 1; k <= c; k++)
				fac2[k - 1] = k;
			//sadele�tirme yap�yoruz
			int k = c + i-1 ;//tekrar bak
			for (; k >= 0; k--) {// toplam dizisinin eleman indexi
				for (int l = c - 1; l >= 0; l--) {
					if (factop[k] % fac2[l] == 0 && fac2[l] != 1) {
						factop[k] /= fac2[l];
						fac2[l] = 1;
					}
				}
			}
			k = c + i-1 ;
			for (; k >= 0; k--) {// toplam dizisinin eleman indexi
				for (int l = i - 1; l >= 0; l--) {
					if (factop[k] % fac3[l] == 0 && fac3[l] != 1) {
						factop[k] /= fac3[l];
						fac3[l] = 1;
					}
				}
			}




			unsigned long long facttop = 1, factiki = 1, factuc = 1;

			//sadele�mi� hali ile permutasyon hesapl�yoruz
			if (i > 0)
				for (int k = 0; k < i; ++k)
					factuc *= fac3[k];
			if (c > 0)
				for (int k = 0; k < c; ++k)
					factiki *= fac2[k];
			if (c + i > 0)
				for (int k = 0; k < c + i; ++k)
					facttop *= factop[k];


			

			if (factiki * factuc != 0)
				adim += facttop / (factiki * factuc); //��,iki ve bir say�lar�n�n permutasyonunu bularak toplam yol say�s�na ekliyor.

			else cout << "sifira bolme hatasi" << endl;//s�n�r� a�mas� durumunda farkedebilmek i�in ekledim
		}
	}
	if (adim < 0)
		cout << "long long siniri asilmistir." << endl << endl;
	return adim;
}




// Test icin kullanilacaktir ve bu fonksiyonda bir duzenleme yapilamaz
int main()
{
	cout << setfill(' ');

	for (auto i = 1; i < 73; ++i)
	{
		{
			long long tempResult = { 0 };

			auto start = std::chrono::steady_clock::now();
			tempResult = iterativeFunction(i);
			auto stop = std::chrono::steady_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();

			cout << "iterative" << setw(4) << i << " -> " << tempResult << "\t( " << duration << "us )\n";
		}

		{
			long long tempResult = { 0 };

			auto start = std::chrono::steady_clock::now();
			tempResult = recursiveFunction(i);
			auto stop = std::chrono::steady_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();

			cout << "recursive" << setw(4) << i << " -> " << tempResult << "\t( " << duration << "us )\n\n";
		}
	}

	return 0;
}



