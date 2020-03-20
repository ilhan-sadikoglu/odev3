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
	long long adim=0;
	while (0 <= a) { //olabilecek maksimum 3 adým sayýsýný hesaplýyoruz
		a -= 3;
		uc++;
	}
	uc--;

	for (int i = 0; i <= uc; ++i) { // 3 adým sayýsý 0 olacak þekilde baþlýyoruz. sonra arttýrarak tekrar ediyoruz
		int b = n - i * 3;
		
		iki = 0;
		while (0 <= b) {// ayný þekilde maksimum 2 sayýsýný hesaplýyoruz
			b -= 2;
			iki++;
		}
		iki--;
		for (int c = 0; c <= iki; ++c) {
			int bir = n - (i * 3 + c * 2);
			//cout << "uc " << i << endl << "iki " << c << endl << "bir " << bir << endl << endl;
			//burdan itibaren permutasyon hesaplanacak
			vector<int> factop(0);
			vector<int> fac3(0);
			vector<int> fac2(0);
			for(int k=bir+1;k<=(bir+c+i);k++)
				factop.push_back(k); //birleri görmezden gelerek toplam sýralanacak öge miktarýný ekler
			for (int k =1; k <= i; k++)
				fac3.push_back(k);
			for (int k =1; k <= c; k++)
				fac2.push_back(k);
			//sadeleþtirme yapýyoruz
			int k = factop.size() - 1;
			for (; k >= 0; k--) {// toplam dizisinin eleman indexi
				for (int l = fac2.size() - 1; l >= 0; l--) {
					if (factop[k] % fac2[l] == 0 && fac2[l]!=1) {
						factop[k] /= fac2[l];
						fac2[l] = 1;
					}
				}
			}
			k = factop.size() - 1;
			for (; k >= 0; k--) {// toplam dizisinin eleman indexi
				for (int l = fac3.size() - 1; l >= 0; l--) {
					if (factop[k] % fac3[l] == 0 && fac3[l] != 1) {
						factop[k] /= fac3[l];
						fac3[l] = 1;
					}
				}
			}




			unsigned long long facttop = 1, factiki = 1, factuc = 1;
			
			//sadeleþmiþ hali ile permutasyon hesaplýyoruz
			if(fac3.size()>0)
			for (int k = 0; k < fac3.size(); ++k)
				factuc *= fac3[k];
			if (fac2.size() > 0)
			for (int k = 0; k < fac2.size(); ++k)
				factiki *= fac2[k];
			if (factop.size() > 0)
			for (int k = 0; k < factop.size(); ++k)
				facttop *= factop[k];
			

			factop.clear();
			fac2.clear();
			fac3.clear();
				
			if (factiki * factuc != 0)
				adim += facttop / (factiki * factuc); //üç,iki ve bir sayýlarýnýn permutasyonunu bularak toplam yol sayýsýna ekliyor.
		
			else cout << "sifira bolme hatasi" << endl;
		}
	}
	if (adim < 0) 
		cout << "long long siniri asilmistir." << endl << endl;
	return adim;
}


//int bir = n - (i * 3 + iki * 2);
//cout << "uc " << i << endl << "iki " << iki << endl << "bir " << bir << endl << endl;
//adim += iki + 1;

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



