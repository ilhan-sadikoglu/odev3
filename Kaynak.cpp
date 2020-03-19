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
	int adim=0;
	while (0 <= a) {
		a -= 3;
		uc++;
	}
	uc--;

	for (int i = 0; i <= uc; i++) {
		int b = n - i * 3;
		
		iki = 0;
		while (0 <= b) {
			b -= 2;
			iki++;
		}
		iki--;
		for (int c = 0; c <= iki; c++) {
			int bir = n - (i * 3 + c * 2);
			cout << "uc " << i << endl << "iki " << c << endl << "bir " << bir << endl << endl;
			
			int fact1 = 1, fact2 = 1, fact3 = 1,facttop=1;
			if (i > 0) {
				for (int k = 1; k <= i; k++)
					fact3 *= k;
			}

			if (c > 0) {
				for (int k = 1; k <= c; k++)
					fact2 *= k;
			}

			if (bir > 0) {
				for (int k = 1; k <= bir; k++)
					fact1 *= k;
			}

			if (bir+c+i > 0) {
				for (int k = 1; k <= (bir + c + i); k++)
					facttop *= k;
			}


			
			if (fact1 * fact2 * fact3 != 0)
				adim += facttop / (fact1 * fact2 * fact3);
			else cout << "sifira bolme hatasi"<<endl;
		}
		

	}
	return adim;
}


//int bir = n - (i * 3 + iki * 2);
//cout << "uc " << i << endl << "iki " << iki << endl << "bir " << bir << endl << endl;
//adim += iki + 1;

// Test icin kullanilacaktir ve bu fonksiyonda bir duzenleme yapilamaz
int main()
{
	cout << setfill(' ');

	for (auto i = 1; i < 30; ++i)
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