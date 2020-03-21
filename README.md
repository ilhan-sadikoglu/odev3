# odev3
ödev3.c++ dosyasında static ve global değişken kullanmadan, recursive ve iteratif fonksionları yazdım. 
İteratif fonksiyon sıkıntısız şekilde çalıştı. Süreler görmezden görünebilecek kadar  düşüktü. (sisteme göre değişmekle beraber benim testimde, görüldüğü üzere, 1 mikrosaniye civarı sürdü)
Ancak recursive fonksiyonda büyüme değeri çok yüksek olduğundan değerler büyüdükçe işlem sayısı arttı ve program tıkanmaya başladı.
Her iki fonksiyonda da long long int sınırı (19 karakter) aşıldığı için 72 den sonra hatalı değerler vermeye başladı.

serbest.c++ dosyasında memoization yöntemi kullanarak recursive fonksiyondaki tıkanma sorununu çözdüm
İteratif fonksiyonda da formülü kulllanmadan nasıl çözebileceğimi denedim.
Başta vektör kullandım. Ancak süreyi optimize edebileceğimi farkederek standart diziye geçtim. 15 kata yakın süre tasarrufu sağladı.
