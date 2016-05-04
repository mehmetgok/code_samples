# time.c

Bu dosyada Ctrl+C ile program nasıl kesildiği ve Linux'ta zaman bilgisi nasıl alındığı gösterilmiştir. Program dosyasını derlemek için:

gcc time.c -o timetest

komut satırı kullanılmaktadır.

Referanslar:

http://stackoverflow.com/questions/588307/c-obtaining-milliseconds-time-on-linux-clock-doesnt-seem-to-work-properl

http://stackoverflow.com/questions/4217037/catch-ctrl-c-in-c

Linux'ta milisaniye düzeyinde zaman almak için:

http://stackoverflow.com/questions/18650057/how-to-calculate-milliseconds-using-timeval-structure

# test1.c

Bu program ile ncurses ve posix thread kütüphaneleri kullanarak basit thread uygulaması yapılmıştır. Oluşturulan thread ncurses ile çalışmakta ve sonlandırılmaktadır.

Program dosyasını derlemek için:

```
gcc test1.c -o test1 -lpthread -lncurses
```

komut satırı kullanılmaktadır. ncurses kütüphanesinin kurulması için 

> sudo apt-get install libncurses5 libncurses-dev

# sqlitetest.c

Bu program ile pre-emptive çalışan bir çekirdek ile delayus fonksiyonu test edilmiş ve gerçek zaman testi Linux gettime ile yapılmıştır. Her adımda zaman değeri tabloya yazılmış ve sistemin gerçek zaman cevabı irdelenmiştir.

Ubuntu üzerinde sqlite ve dev kütüphanelerini kurmak için.

sudo apt-get install sqlite3
sudo apt-get install libsqlite3-dev

komut satırları kullanılır. Programın kaynak kodunu derlemek için:

# queue_test.cpp

Bu program örneği C++ ile FIFO kuyruk çalışmasının nasıl yapıldığını göstermektedir.



Referanslar:

http://stackoverflow.com/questions/18776812/problems-linking-to-sqlite3-h-with-gcc

-- SQLite ile hızlı veri insertion:

http://blog.quibb.org/2010/08/fast-bulk-inserts-into-sqlite/





