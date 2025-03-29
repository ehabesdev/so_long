# 👾 So Long 🚀

[![42 Intra Badge](https://img.shields.io/badge/42_Okulu-Projesi-00babc?style=for-the-badge&logo=42)](https://www.42kocaeli.com.tr) [![Language](https://img.shields.io/badge/Dil-C-blue?style=for-the-badge&logo=c)](https://en.wikipedia.org/wiki/C_(programming_language))

Bu repo, 42 okulları müfredatının bir parçası olan `so_long` projesini içerir. MiniLibX grafik kütüphanesi kullanılarak C dilinde yazılmış basit bir 2D oyundur. Amacımız, haritadaki tüm toplanabilir öğeleri (💎) toplayıp çıkış kapısına (🚪) ulaşmak!

---

## 🎯 Oyunun Amacı

Oyundaki sevimli karakterimizi ( P ) kontrol ederek:
1. Haritadaki tüm koleksiyon öğelerini ( C - 💎 ) topla.
2. Tüm öğeler toplandıktan sonra çıkış kapısını ( E - 🚪 ) bul ve oraya ulaş.
3. Duvarlara ( 1 - 🧱 ) çarpmamaya dikkat et!
4. En az hamle ile oyunu bitirmeye çalış! 🏆

---

## ✅ Temel Özellikler

* **🗺️ Harita Okuma ve Doğrulama:** `.ber` uzantılı harita dosyalarını okur ve kurallara uygunluğunu kontrol eder (dikdörtgen mi, duvarlarla çevrili mi, P, E, C elemanları doğru sayıda mı vb.).
* **🖼️ Grafiksel Gösterim:** MiniLibX kütüphanesi ile oyun haritasını, karakteri, duvarları, toplanabilirleri ve çıkışı ekranda gösterir.
* **🕹️ Oyuncu Kontrolü:** Klavye (W, A, S, D) ile oyuncu hareketlerini yönetir.
* **💎 Toplanabilirlik Mekanizması:** Oyuncunun 'C' karakterlerinin üzerinden geçerek onları toplamasını sağlar.
* **🚪 Çıkış Mekanizması:** Tüm 'C'ler toplandıktan sonra 'E' kapısını aktif hale getirir ve oyuncunun oyunu kazanmasını sağlar.
* **📊 Hamle Sayacı:** Oyuncunun yaptığı hamle sayısını terminalde gösterir.
* **🎉 Başarılı Bitiş Ekranı:** Oyun başarıyla tamamlandığında özel bir tebrik mesajı gösterir.
* **❌ Temiz Çıkış:** ESC tuşu veya pencere kapatma butonu ile programı düzgün bir şekilde sonlandırır, ayrılan belleği serbest bırakır.

---

## 🗺️ Harita Formatı (`.ber`)

Oyun, `.ber` uzantılı dosyalarla tanımlanan haritaları kullanır. Haritalar şu kurallara uymalıdır:

1.  **Dikdörtgen Olmalı:** Haritanın her satırı aynı uzunlukta olmalıdır.
2.  **Kapalı Olmalı:** Haritanın etrafı tamamen duvarlarla ('1') çevrili olmalıdır.
3.  **Karakterler:** Yalnızca şu karakterleri içerebilir:
    * `1`: Duvar 🧱
    * `0`: Boş Alan (Zemin) ⬜
    * `C`: Toplanabilir Öğe 💎
    * `E`: Çıkış Kapısı 🚪
    * `P`: Oyuncu Başlangıç Noktası 👾
4.  **Eleman Sayıları:**
    * Tam olarak **bir** tane 'P' (Oyuncu) olmalıdır.
    * Tam olarak **bir** tane 'E' (Çıkış) olmalıdır.
    * En az **bir** tane 'C' (Toplanabilir) olmalıdır.

**Örnek Geçerli Harita:**
```ber
11111111
1P0C00E1
10111001
10C100C1
11111111
```

---

## 📚 Bu Projede Pekiştirilen Beceriler

Bu proje, 42 müfredatı kapsamında aşağıdaki temel programlama ve problem çözme becerilerini pekiştirmeyi amaçlamaktadır:

* **🖥️ Grafik Programlama (MiniLibX):**
    * Pencere yönetimi (oluşturma, kapatma).
    * Görsel (sprite) yükleme ve ekrana çizdirme (`.xpm` dosyaları).
    * Klavye ve pencere olaylarını (event) yönetme (tuş basımları, pencere kapanması, yeniden çizim).
* **📄 Dosya Okuma ve İşleme:**
    * Harita (`.ber`) dosyalarını açma, satır satır okuma (`get_next_line`).
    * Okunan veriyi yorumlayarak oyun haritasını oluşturma.
* **🧠 Algoritma ve Mantık:**
    * Harita doğrulama algoritmaları (duvar kontrolü, eleman sayısı ve türü kontrolü).
    * Oyuncu hareket mantığı ve basit çarpışma (duvar) kontrolü.
    * Oyun durumu yönetimi (toplanabilir sayımı, kazanma koşulu).
* **💾 Bellek Yönetimi:**
    * Dinamik bellek ayırma (`malloc`) ve serbest bırakma (`free`) (harita matrisi, MiniLibX nesneleri vb. için).
    * Bellek sızıntılarını önleme (özellikle `exit_game` fonksiyonunda).
* **🧩 Modüler Programlama:**
    * Kodun farklı işlevlere göre (`src/` altındaki `.c` dosyaları) mantıksal olarak ayrılması.
    * Header dosyaları (`.h`) ile fonksiyon prototiplerinin ve yapı tanımlarının düzenlenmesi.
* **🔧 Hata Yönetimi:**
    * Fonksiyon dönüş değerlerini kontrol etme (örn: `mlx_init`, `mlx_new_window`, dosya açma).
    * Anlaşılır hata mesajları (`error_handler`) gösterme ve programı güvenli bir şekilde sonlandırma.
* **⚙️ Derleme Süreci:**
    * `Makefile` kullanarak projenin derlenmesi ve bağımlılıkların (Libft, MiniLibX vb.) yönetilmesi.
* **📚 Kütüphane Kullanımı:**
    * Kendi yazdığımız `Libft`, `ft_printf`, `get_next_line` gibi kütüphaneleri projeye entegre etme ve etkin kullanma.
    * Harici (MiniLibX) bir kütüphanenin fonksiyonlarını anlama ve kullanma.

---

## 🛠️ Kurulum ve Derleme

Projeyi derlemek için sisteminizde `make` ve C derleyicisinin (örn: `gcc`) kurulu olması gerekir. Ayrıca MiniLibX kütüphanesinin de sisteminizde ayarlı olması önemlidir (42 ortamlarında genellikle hazırdır).

1.  **Repoyu Klonla:**
    ```bash
    git clone git@github.com:ehabesdev/so_long.git so_long
    cd so_long
    ```

2.  **Derle:**
    ```bash
    make
    ```
    Bu komut, gerekli kütüphaneleri (Libft, ft_printf, get_next_line, MiniLibX) ve ana oyun programını derleyecektir.

---

## 🚀 Kullanım

Derleme başarılı olduktan sonra, oyunu çalıştırmak için yürütülebilir dosyaya argüman olarak bir harita dosyası vermeniz yeterlidir:

```bash
./so_long maps/map.ber
```
---

## ⌨️ Kontroller

* **W**: Yukarı Hareket **⬆️**
* **A**: Sola Hareket **⬅️**
* **S**: Aşağı Hareket **⬇️**
* **D**: Sağa Hareket **➡️**
* **ESC**: Oyundan Çıkış ❌

---

## 📁 Proje Yapısı

```text
so_long/
├── assets/         # Görsel dosyaları (.xpm)
│   ├── player.xpm
│   ├── wall.xpm
│   ├── collectible.xpm
│   ├── exit.xpm
│   └── floor.xpm
├── include/        # Projeye özel header dosyası
│   └── so_long.h
├── libs/           # Kullanılan harici ve kişisel kütüphaneler
│   ├── ft_printf/
│   ├── get_next_line/
│   ├── libft/
│   └── minilibx/
├── maps/           # Harita dosyaları (.ber)
│   └── map.ber
│   └── big_map.ber
│   └── miss_map.ber
│   └── ...
├── src/            # Projenin ana kaynak kod dosyaları
│   ├── main.c
│   ├── graphics.c
│   ├── game_manager.c
│   ├── map_read.c
│   ├── map_validate.c
│   ├── map_validate_structure.c
│   ├── output.c
│   └── setup.c
├── .gitignore      # (Opsiyonel: Git'in takip etmeyeceği dosyalar)
├── Makefile        # Derleme ve temizleme script'i
└── README.md       # Bu dosya!
```

---
*So Long, and Thanks for All the Fish!* 🐬
