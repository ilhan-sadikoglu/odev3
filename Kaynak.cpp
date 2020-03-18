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
	cout << uc<<endl;
	for (int i = 0; i <= uc; i++) {
		int b = n - i * 3;
		
		iki = 0;
		while (0 <= b) {
			b -= 2;
			iki++;
		}
		iki--;
		
		int bir = n - i * 3 - iki * 2;
		
		adim += iki+1;

	}
	return adim;
}


// Test icin kullanilacaktir ve bu fonksiyonda bir duzenleme yapilamaz
int main()
{
	cout << setfill(' ');

	for (auto i = 1; i < 100; ++i)
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