# sundaLang 🇮🇩

Bahasa pemrograman berbasis Bahasa Sunda yang mentranspilasi kode ke C. Tulis logika programmu dalam Bahasa Sunda, biarkan compiler yang menerjemahkan ke C dan menjalankannya!

## 📋 Fitur

- **Tipe Data Sunda**: `nomer` (int), `koma` (float), `legeg` (char), `legegpican` (string)
- **Operator Logika**: `jeung` (&&), `atawa` (||), `gede` (>), `letik` (<), dll
- **Kontrol Alur**: `mun` (if), `Keur` (while), `muter` (for)
- **I/O**: `ngagorowok` (printf), `asupkeun` (scanf)
- **Transpilation**: Kode Sunda → C → Executable

## 🚀 Cara Pemasangan

### Prasyarat
- GCC Compiler (untuk compile hasil transpile)
- Node.js (untuk CLI wrapper)
- Make (opsional, untuk build manual)

### Instalasi

1. **Clone repository**
```bash
git clone https://github.com/nluthfi/sundaLang.git
cd sundaLang
```

2. **Install dependencies**
```bash
npm install
```

3. **Build interpreter C**
```bash
make
```

4. **Install ke system (opsional)**
```bash
sudo make install
```

## 💻 Cara Penggunaan

### Menjalankan file .sun

```bash
sun contoh.sun
```

atau langsung pakai binary C:

```bash
./sun contoh.sun
```

### Contoh Program

Buat file `halo.sun`:

```sunda
legegpican pesen nyaeta "Halo Dunia!"
ngagorowok(pesen)
nuhun
```

Jalankan:
```bash
sun halo.sun
```

Output:
```
Halo Dunia!
Interpretation successful!
```

### Contoh dengan Input

```sunda
nomer umur
ngagorowok("Masukkan umur: ")
asupkeun("%d", &umur)
mun umur gede 17 {
    ngagorowok("Sudah dewasa")
} nte {
    ngagorowok("Belum dewasa")
}
nuhun
```

### Contoh Loop

```sunda
muter i ti 0 nepi 5 : {
    ngagorowok("%d\n", i)
}
nuhun
```

## 📖 Dokumentasi Lengkap

Lihat [COMMAND.md](COMMAND.md) untuk daftar lengkap perintah dan sintaks.

## 🏗️ Struktur Proyek

```
sundaLang/
├── sundaLang.c          # Interpreter utama (C)
├── cli.js               # CLI wrapper (Node.js)
├── lib/
│   └── logics/
│       ├── lexer/       # Tokenizer
│       └── parser/      # Parser
├── Makefile             # Build script
└── COMMAND.md           # Dokumentasi perintah
```

## 🔧 Development

### Compile Manual
```bash
gcc sundaLang.c lib/logics/lexer/*.c lib/logics/parser/*.c -o sun
```

### Menambah Fitur Baru
1. Tambahkan token baru di `lib/logics/lexer/`
2. Update parser di `lib/logics/parser/`
3. Test dengan file `.sun` sederhana

## 📄 Lisensi

Proyek ini bersifat open-source. Silakan fork dan kontribusi!
