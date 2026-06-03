# 🔱 COMMAND SundaLang

SundaLang mangrupikeun basa pamrograman anu nganggo basa Sunda anu formal. Di handap ieu mangrupikeun pituduh lengkep ngeunaan sintaksis, cara kompilasi, sareng conto panggunaanana.

---

## 💎 Sintaksis Dasar

### 1. Tipe Data
| Sundanese | C/Standard | Penjelasan |
| :--- | :--- | :--- |
| `nomer` | `int` | Angka buleud (Integer) |
| `koma` | `float` | Angka desimal (Floating point) |
| `legeg` | `char` | Karakter tunggal |
| `legegpican` | `string` | Untaian karakter (String) |

### 2. Operator Logika & Aritmatika
| Sundanese | Simbol | Penjelasan |
| :--- | :--- | :--- |
| `jeung` | `&&` | Logika AND |
| `atawa` | `||` | Logika OR |
| `gede` | `>` | Leuwih gede ti |
| `letik` | `<` | Leuwih leutik ti |
| `saruagede` | `>=` | Gede atawa sarua jeung |
| `sarualetik` | `==` | Leutik atawa sarua jeung |
| `sarua` | `==` | Sarua jeung |
| `teusarua` | `!=` | Teu sarua jeung |
| `nyaeta` | `=` | Assignment (Ngeusi nilai) |
| `aura` | `++` / `--` | Increment / Decrement |

### 3. Fungsi Kontrol & I/O
| Sundanese | Fungsi C | Penjelasan |
| :--- | :--- | :--- |
| `asupkeun` | `scanf` | Narima input ti user |
| `ngagorowok` | `printf` | Nampilkeun output ka layar |
| `mun` | `if` | Kondisi mimitian |
| `munte` | `else if` | Kondisi tambahan |
| `nte` | `else` | Kondisi ahir/salianna |
| `Keur` | `while` | Perulangan salila kondisi bener |
| `muter` | `for` | Perulangan kalayan rancingan |
| `sok` | `continue` | Neruskeun loop ka iterasi saterusna |
| `}` | `}` | Panutup blok kode |
| `nuhun` | `return 0;` | Ngahéakeun program (Sukses) |

---

## 🛠️ Cara Ngajalankeun (Compilation & Execution)

SundaLang gaduh tilu jinis interpreter anu tiasa dianggo gumantung kana kabutuhan anjeun:

### 1. Standard Interpreter (Kompilasi & Run)
Digunakeun pikeun ngajalankeun program SundaLang sacara normal.
- **Kompilasi**: `gcc sundaLang-interpreter.c lib/logics/lexer/*.c lib/logics/parser/*.c -o sun`
- **Ngajalankeun**: `.\sun.exe tes1.sun`

### 2. Tokenizer Mode (Oneple)
Digunakeun pikeun ningali kumaha basa SundaLang dipecah janten token (Lexical Analysis).
- **Kompilasi**: `gcc sunda-oneple.c lib/logics/lexer/*.c lib/logics/parser/*.c -o sun-oneple`
- **Ngajalankeun**: `.\sun-oneple.exe tes1.sun`

### 3. Intermediate Code Mode (IR / 1-Address)
Digunakeun pikeun ningali *low-level instructions* (Intermediate Representation) sapertos LOAD, STORE, ADD.
- **Kompilasi**: `gcc sunda-ir-interpreter.c lib/logics/lexer/*.c lib/logics/parser/*.c -o sun-ir`
- **Ngajalankeun**: `.\sun-ir.exe tes_ir.sun`

---

## 📝 Conto-conto Panggunaan (Examples)

### A. Hello World & Variable
```sundanese
legegpican pesen nyaeta "Wilujeng Sumping di SundaLang!"
ngagorowok pesen
nuhun
```

### B. Input & Kalkulasi Saderhana
```sundanese
nomer angka1
nomer angka2
nomer hasil

ngagorowok "Asupkeun angka kahiji: "
asupkeun angka1
ngagorowok "Asupkeun angka kadua: "
asupkeun angka2

hasil nyaeta angka1 + angka2
ngagorowok "Hasilna nyaeta: " + hasil
nuhun
```

### C. Kondisi (If-Else)
```sundanese
nomer umur nyaeta 17

mun umur gede 17 :
    ngagorowok "Anjeun geus dewasa"
nte :
    ngagorowok "Anjeun masih budak"
}
nuhun
```

### D. Perulangan (Loops)
```sundanese
nomer i nyaeta 1
Keur i letik 6 :
    ngagorowok "Iterasi ka: " + i
    i nyaeta i + 1
}
nuhun
```

---
