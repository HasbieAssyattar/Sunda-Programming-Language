# 🔱 SundaLang: Basa Pamrograman Sunda

**SundaLang** mangrupikeun basa pamrograman dumasar kana **Bahasa Sunda** formal anu ditranspilasi kana basa C. Proyek ieu dijieun pikeun ngagabungkeun kearifan lokal sareng téknologi modérn.

> "Tulis logika programmu dina Basa Sunda, antepkeun compiler anu menterjemahkeun ka C sarta ngajalankeunana!"

---

## 💎 Fitur Utama

- 🎨 **Sintaksis Lokal**: Ngagunakeun kekecapan asli Sunda pikeun logika program.
- ⚡ **Performance C**: Hasil transpilasi langsung jadi binary C anu gancang.
- 🛠️ **Multi-Mode**: Dilengkepan ku Standard Interpreter, Tokenizer View (Oneple), sareng Intermediate Representation (IR).
- 📦 **CLI Terintegrasi**: Ngajalankeun file `.sun` sacara gampang.

---

## 📊 Tipe Data & Kata Kunci

| Kategori | Sundanese | C Equivalent |
| :--- | :--- | :--- |
| **Variabel** | `nomer`, `koma`, `legeg`, `legegpican` | `int`, `float`, `char`, `string` |
| **Logika** | `jeung`, `atawa`, `gede`, `letik`, `sarua` | `&&`, `||`, `>`, `<`, `==` |
| **Kontrol** | `mun`, `munte`, `nte`, `Keur`, `muter` | `if`, `else if`, `else`, `while`, `for` |
| **I/O** | `ngagorowok`, `asupkeun` | `printf`, `scanf` |
| **Lainna** | `nyaeta`, `aura`, `nuhun` | `=`, `++`/`--`, `return 0` |

---

## 🚀 Cara Pamasangan & Pamakéan

### 1. Prasyarat
- **GCC Compiler** (wajib)
- **Node.js** (pikeun CLI)
- **Make** (opsional)

### 2. Instalasi
```bash
# Clone repository
git clone https://github.com/HasbieAssyattar/Sunda-Programming-Language.git
cd Sunda-Programming-Language

# Build project
make
```

### 3. Ngajalankeun Program
Anjeun tiasa ngajalankeun file `.sun` langsung nganggo CLI:
```bash
# Ngajalankeun file conto
node cli.js tes1.sun
```

Atawa langsung nganggo binary hasil build:
```bash
# Windows
.\bin\sun.exe tes1.sun

# Linux/macOS
./bin/sun tes1.sun
```

---

## 📝 Conto Kode (`halo.sun`)

```sundanese
legegpican pesen nyaeta "Wilujeng Sumping di SundaLang!"
ngagorowok pesen

nomer angka1 nyaeta 10
nomer angka2 nyaeta 20
nomer hasil nyaeta angka1 + angka2

ngagorowok "Hasil panambahan: " + hasil
nuhun
```

---

## 🏗️ Struktur Proyek

```text
sundaLang/
├── bin/                    # Lokasi binary hasil build
├── lib/logics/
│   ├── lexer/              # Lexical Analysis (Tokenizer)
│   └── parser/             # Semantic Analysis & Parsing
├── sundaLang-interpreter.c # Core Interpreter
├── cli.js                  # Node.js CLI Wrapper
├── COMMAND.md              # Dokumentasi lengkap sintaksis
└── Makefile                # Script otomatisasi build
```

---

## 🤝 Kontribusi
Wilujeng sumping pikeun saha waé anu hoyong ngembangkeun basa ieu! Mangga fork sareng kirimkeun Pull Request.

---

## 📄 Lisensi
Proyek ieu lisensina handapeun **MIT License**.
