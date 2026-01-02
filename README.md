# push_swap
# Push_swap

*This project has been created as part of the 42 curriculum by <alsagir>.*

## 🗣️ Description (Proje Açıklaması)

**Push_swap**, 42 okulunun müfredatında yer alan, verileri sıralama (sorting) üzerine odaklanmış bir algoritma projesidir.

Projenin temel amacı, `Stack A` ve `Stack B` adında iki yığın ve kısıtlı sayıda talimat (instructions) kullanarak, rastgele verilmiş tamsayıları en az hamleyle sıralamaktır. Bu proje, C programlama dilindeki yetkinliği artırmayı, temel algoritmaları ve bunların Karmaşıklıklarını (Complexity) kavramayı hedefler.

Bu projede, performans ve hamle sayısı optimizasyonu için **"Turk Algorithm"** (Cost-Based Greedy Algorithm) kullanılmıştır.

### 🎯 Objectives (Hedefler)
* **Sıralama:** Verilen sayıları `Stack A` içinde küçükten büyüğe sıralamak.
* **Performans:**
    * 100 rastgele sayı için < 700 hamle.
    * 500 rastgele sayı için < 5500 hamle.

---

## ⚙️ Algorithm (Kullanılan Algoritma)

Bu projede **Turk Algorithm** (Maliyet Odaklı Algoritma) tercih edilmiştir. Algoritmanın çalışma mantığı şöyledir:

1.  **Push to B:** Stack A'daki sayılar (3 tane kalana kadar), Stack B'ye itilir. (İlk etapta 2 sayı itilir, sonrasında maliyet hesabı yapılabilir veya direkt itilebilir).
2.  **Sort Three:** A'da kalan son 3 sayı kendi içinde sıralanır.
3.  **Cost Analysis (Maliyet Hesabı):** Stack B'deki her bir elemanın Stack A'daki doğru yerine (kendisinden büyük en küçük sayı) gitmesi için gereken hamle sayısı hesaplanır.
4.  **Cheapest Move:** En az hamle gerektiren (cheapest) eleman seçilir.
5.  **Execution:** Seçilen eleman için gerekli rotasyonlar (ikili rotasyon `rr`, `rrr` optimizasyonları dahil) yapılır ve eleman A'ya itilir (`pa`).
6.  **Final Rotation:** Tüm sayılar A'ya geçtikten sonra, en küçük sayı en üste gelecek şekilde son bir döndürme yapılır.

---

## 🛠️ Installation & Usage (Kurulum ve Kullanım)

Projeyi derlemek ve çalıştırmak için aşağıdaki adımları izleyin:

### 1. Derleme
Makefile dosyası kullanılarak proje derlenir:
```bash
make
