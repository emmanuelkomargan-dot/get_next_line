# 📜 Get Next Line (GNL) — Edisi Gulungan Kertas Tandas

*This project has been created as part of the 42 curriculum by <ekomarga>.*

---

## 🧻 Analogi Gulungan Kertas Tandas

Bayangkan anda sedang bercangkung di atas jamban sambil membaca mesej panjang yang ditulis pada **gulungan kertas tandas** standard 42.

Anda mahu membaca **satu baris lengkap pada satu-satu masa** (sehingga jumpa `\n`). Namun, ada satu syarat: tangan anda hanya boleh menarik panjang kertas yang tetap setiap kali — panjang tetap ini ialah **`BUFFER_SIZE`** anda.

* **Senario A (`BUFFER_SIZE = 1`):** Anda tarik kertas 1 milimeter demi 1 milimeter. Memang lambat, tetapi anda tidak akan terlebih tarik melepasi garisan pemisah (`\n`).
* **Senario B (`BUFFER_SIZE = 9999`):** Anda terus tarik 10 meter kertas sekaligus! Anda jumpa garisan pemisah dengan cepat, tetapi sekarang ada lambakan baki kertas bertaburan di atas lantai.
* **Dilema Baki Kertas (`static char *leftover`):** Apa yang perlu dibuat dengan baki kertas di atas lantai itu? Anda tidak boleh buang begitu sahaja! Anda simpan baki kertas itu dengan selamat di atas peha anda (pembolehubah `static`). Apabila fungsi `get_next_line()` dipanggil semula, anda akan membaca kertas di atas peha anda **terlebih dahulu** sebelum menarik kertas baharu dari gulungan.

---

## Description

**Get Next Line** ialah projek dalam kurikulum 42 yang bertujuan untuk mereka bentuk dan mengodkan fungsi C bagi membaca teks daripada *file descriptor* (`fd`), satu baris pada satu-satu masa. 

Matlamat utama projek ini adalah untuk memahami penggunaan pembolehubah statik (*static variables*), pengurusan memori dinamik (*heap allocation*), dan pengendalian penimbal (*buffer handling*) tanpa berlaku kebocoran memori (*memory leaks*).

### Penjelasan & Justifikasi Algoritma

Algoritma projek ini dibahagikan kepada tiga fasa utama:

1. **Membaca ke Penimbal Baki (`read_to_leftover`):** 
   Fungsi membaca data dari *file descriptor* menggunakan saiz `BUFFER_SIZE` dan menggabungkannya ke dalam pembolehubah statik `leftover` secara berulang sehinggalah karakter baris baharu (`\n`) ditemui atau fail mencapai penghujung (*End of File / EOF*). Algoritma ini dipilih supaya panggilan sistem `read()` dipinimumkan mengikut saiz penimbal yang ditetapkan.
   
2. **Mengekstrak Baris (`extract_line`):** 
   Fungsi mengira panjang rentetan teks sehingga `\n` pertama, memohon memori (*malloc*) mengikut saiz tepat baris tersebut (termasuk karakter `\n` dan `\0`), lalu menyalinnya untuk dipulangkan kepada pengguna.
   
3. **Mengemas Kini Baki (`update_leftover`):** 
   Selepas baris diekstrak, baki rentetan teks *selepas* `\n` disimpan semula ke dalam `leftover`, manakala memori `leftover` yang lama dibebaskan (*free*). Jika tiada lagi baki teks, `leftover` ditetapkan kepada `NULL`.

---

## Instructions

### Kompilasi

Anda boleh memasukkan *header* projek ke dalam fail C anda:
```c
#include "get_next_line.h"# 📜 Get Next Line (GNL) — Edisi Gulungan Kertas Tandas

*This project has been created as part of the 42 curriculum by <ekomarga>.*

---

## 🧻 Analogi Gulungan Kertas Tandas

Bayangkan anda sedang membaca mesej panjang yang ditulis pada **gulungan kertas tandas** standard 42.

Anda mahu membaca **satu baris lengkap pada satu-satu masa** (sehingga jumpa `\n`). Namun, ada satu syarat: tangan anda hanya boleh menarik panjang kertas yang tetap setiap kali — panjang tetap ini ialah **`BUFFER_SIZE`** anda.

* **Senario A (`BUFFER_SIZE = 1`):** Anda tarik kertas 1 milimeter demi 1 milimeter. Memang lambat, tetapi anda tidak akan terlebih tarik melepasi garisan pemisah (`\n`).
* **Senario B (`BUFFER_SIZE = 9999`):** Anda terus tarik 10 meter kertas sekaligus! Anda jumpa garisan pemisah dengan cepat, tetapi sekarang ada lambakan baki kertas bertaburan di atas lantai.
* **Dilema Baki Kertas (`static char *leftover`):** Apa yang perlu dibuat dengan baki kertas di atas lantai itu? Anda tidak boleh buang begitu sahaja! Anda simpan baki kertas itu dengan selamat di atas peha anda (pembolehubah `static`). Apabila fungsi `get_next_line()` dipanggil semula, anda akan membaca kertas di atas peha anda **terlebih dahulu** sebelum menarik kertas baharu dari gulungan.

---

## Description

**Get Next Line** ialah projek dalam kurikulum 42 yang bertujuan untuk mereka bentuk dan mengodkan fungsi C bagi membaca teks daripada *file descriptor* (`fd`), satu baris pada satu-satu masa. 

Matlamat utama projek ini adalah untuk memahami penggunaan pembolehubah statik (*static variables*), pengurusan memori dinamik (*heap allocation*), dan pengendalian penimbal (*buffer handling*) tanpa berlaku kebocoran memori (*memory leaks*).

### Penjelasan & Justifikasi Algoritma

Algoritma projek ini dibahagikan kepada tiga fasa utama:

1. **Membaca ke Penimbal Baki (`read_to_leftover`):** 
   Fungsi membaca data dari *file descriptor* menggunakan saiz `BUFFER_SIZE` dan menggabungkannya ke dalam pembolehubah statik `leftover` secara berulang sehinggalah karakter baris baharu (`\n`) ditemui atau fail mencapai penghujung (*End of File / EOF*). Algoritma ini dipilih supaya panggilan sistem `read()` dipinimumkan mengikut saiz penimbal yang ditetapkan.
   
2. **Mengekstrak Baris (`extract_line`):** 
   Fungsi mengira panjang rentetan teks sehingga `\n` pertama, memohon memori (*malloc*) mengikut saiz tepat baris tersebut (termasuk karakter `\n` dan `\0`), lalu menyalinnya untuk dipulangkan kepada pengguna.
   
3. **Mengemas Kini Baki (`update_leftover`):** 
   Selepas baris diekstrak, baki rentetan teks *selepas* `\n` disimpan semula ke dalam `leftover`, manakala memori `leftover` yang lama dibebaskan (*free*). Jika tiada lagi baki teks, `leftover` ditetapkan kepada `NULL`.

---

## Instructions

### Kompilasi

Anda boleh memasukkan *header* projek ke dalam fail C anda:
```c
#include "get_next_line.h"

# Kompilasi standard (menggunakan saiz lalai BUFFER_SIZE=42)
cc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c -o gnl

# Kompilasi dengan penimbal bersaiz 1 byte
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 main.c get_next_line.c get_next_line_utils.c -o gnl

# Kompilasi dengan penimbal saiz besar
cc -Wall -Wextra -Werror -D BUFFER_SIZE=10000000 main.c get_next_line.c get_next_line_utils.c -o gnl

Contoh Penggunaan (main.c)

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("contoh.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line); // Pastikan pembebasan memori dilakukan selepas digunakan!
	}
	close(fd);
	return (0);
}

Resources
Dokumentasi C Standard: Manual read(2), malloc(3), dan free(3).

Rujukan Kurikulum 42: Subjek rasmi Get Next Line (v10).

Penggunaan AI
Model Pembelajaran Bahasa (AI) digunakan sebagai pembantu proses pembangunan projek bagi tugas-tugas berikut:

Analisis & Pembetulan Ralat Memori: Menganalisis kes-kes khas (edge cases) berkaitan kebocoran memori (memory leaks) dan dangling pointers pada pembolehubah statik.

Penjanaan Senario Ujian: Membantu membina contoh fail ujian serta perintah kompilasi pelbagai BUFFER_SIZE untuk ujian kebolehpercayaan.

Penyediaan Dokumentasi: Membantu menyusun maklumat dan melaras format templat README.md ini mengikut piawaian Chapter V dokumentasi projek 42.
