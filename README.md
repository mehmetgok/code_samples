# time.c

Bu dosyada Ctrl+C ile program nasıl kesildiği ve Linux'ta zaman bilgisi nasıl alındığı gösterilmiştir. Program dosyasını derlemek için:

gcc time.c -o timetest

komut satırı kullanılmaktadır.

Referanslar:
http://stackoverflow.com/questions/588307/c-obtaining-milliseconds-time-on-linux-clock-doesnt-seem-to-work-properl
http://stackoverflow.com/questions/4217037/catch-ctrl-c-in-c

# test1.c

Bu program ile ncurses ve posix thread kütüphaneleri kullanarak basit thread uygulaması yapılmıştır. Oluşturulan thread ncurses ile çalışmakta ve sonlandırılmaktadır.

Program dosyasını derlemek için:

gcc test1.c -lncurses -o test1 -lpthread

komut satırı kullanılmaktadır.


