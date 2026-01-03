# Billionaires List Manager – C Program

This C program allows you to manage a list of billionaires. You can add, search, delete, and view records, as well as save and load data from `.txt` files. The program supports searches by name, country, activity, birth date, birth time, and net worth.

---

## Features

- **Add new billionaire**: `newbil`
- **Search by**:
  - Name (`findN`)
  - Country / City (`findC`)
  - Activity (`findS`)
- **Print lists with filters**:
  - Greater than (`print+`)
  - Equal to (`print=`)
  - Less than (`print-`)
- **Delete records**:
  - Newest (`deleteN`)
  - Oldest (`deleteO`)
- **Load and save lists**:
  - Load from file: `load [number] [filename.txt]`
  - Save to file: `save [filename.txt]`
- **Calculate total net worth**: `sum`
- **Command guide**: `help`

---

## Usage

1. Compile the program with a C compiler:

```bash
gcc -o billionaires_manager billionaires_manager.c
```

Copyright
© 2026 Nikos Dimopoulos.
Reproduction or use without permission is prohibited.