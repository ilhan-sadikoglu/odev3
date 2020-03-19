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
long long recursiveFunction(int numberOfStones)
{


	// BURAYI DUZENLEYIN



	return 0;
}

/* Yinelemeli olarak zip zip kurbaganin kac farkli yoldan gittigini bulan fonksiyondur.
 * Bu fonksiyon icinde for ve while dongusu kullanilmalidir.
 * Bu fonksiyon icinde baska bir fonksiyona (kendisi dahil) cagri yapilamaz.
 */
long long iterativeFunction(int n)
{
	int iki=0,uc = 0, a = n;
	int yol=0;
	while (0 <= a) {  //olabilecek maksimum 3 sayısını buluyor
		a -= 3;
		uc++;
	}
	uc--;

	for (int i = 0; i <= uc; ++i) { //3lerin sayısını 0 dan başlatarak ilerliyor
		int b = n - i * 3;
		
		iki = 0; //mevcut 3 sayısında en fazla kaç tane 2 olabileceiğini buluyor
		while (0 <= b) {
			b -= 2;
			iki++;
		}
		iki--;
		for (int c = 0; c <= iki; ++c) { //iki sayısını 0dan başlatarak ilerliyor
			int bir = n - (i * 3 + c * 2); //mevcut durumda 2 ve 3lerin sayısını kullanarak 1lerin sayısını hesaplıyor
			cout << "uc " << i << endl << "iki " << c << endl << "bir " << bir << endl << endl;
			
			unsigned long long int fact2 = 1, fact3 = 1,facttop=1;
			if (i > 1) {
				for (int k = 1; k <= i; ++k)
					fact3 *= k;
			}

			if (c > 1) {
				for (int k = 1; k <= c; ++k)
					fact2 *= k;
			}
			

			if (bir+c+i > 1) {
				for (int k = bir+1; k <= (bir + c + i); ++k)
					facttop *= k;
			}


			
			if (fact2 * fact3 != 0)
				yol += facttop / (fact2 * fact3); //üç,iki ve bir sayılarının permutasyonunu bularak toplam yol sayısına ekliyor.
			else cout << "sifira bolme hatasi"<<endl;
		}
		

	}
	return yol;
}


//int bir = n - (i * 3 + iki * 2);
//cout << "uc " << i << endl << "iki " << iki << endl << "bir " << bir << endl << endl;
//adim += iki + 1;

// Test icin kullanilacaktir ve bu fonksiyonda bir duzenleme yapilamaz
int main()
{
	cout << setfill(' ');

	for (auto i = 1; i < 50; ++i)
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
