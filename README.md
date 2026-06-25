# Sunda Programming Language

Sunda Programming Language (SundaLang) adalah bahasa pemrograman unik dengan sintaksis berbahasa Sunda. Proyek ini dibuat sebagai eksperimen pembuatan interpreter bahasa pemrograman menggunakan dialek/bahasa daerah Sunda.

## Sintaksis & Keyword

### Tipe Data
| Sunda | C / Standard |
| :--- | :--- |
| `nomer` | `int` (Integer) |
| `koma` | `float` (Desimal) |
| `legeg` | `char` (Karakter) |
| `legegpican` | `string` (Teks) |

### Operator Logika
| Sunda | Operator |
| :--- | :--- |
| `jeung` | `&&` |
| `atawa` | `||` |
| `gede` | `>` |
| `letik` | `<` |
| `saruagede` | `>=` |
| `sarualetik` | `<=` |
| `sarua` | `==` |
| `teusarua` | `!=` |
| `nyaeta` | `=` (Assignment) |

### Fungsi & Kontrol Aliran
| Sunda | Fungsi / C Equivalent |
| :--- | :--- |
| `asupkeun` | `scanf` (Input) |
| `ngagorowok` | `printf` (Output) |
| `mun` | `if` |
| `munte` | `else if` |
| `nte` | `else` |
| `Keur` | `while` |
| `muter` | `for` |
| `sok` | `continue` |
| `}` | Menutup blok fungsi |
| `nuhun` | Mengakhiri program (`return 0`) |

## Contoh Program

Berikut adalah contoh kode sederhana (`contoh.sun`):

```sunda
nomer umur
asupkeun umur

mun umur letik 18 :
    ngagorowok "Anjeun masih leutik"
munte umur sarua 18 :
    ngagorowok "Anjeun geus dewasa"
nte
    ngagorowok "Anjeun geus kolot"
}

nuhun
```
