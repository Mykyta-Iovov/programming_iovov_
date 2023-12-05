


Дисципліна: Програмування
Aвтор: Іовов Микита Павлович
Група: КН-923Б






Звіт

Іовов Микита Павлович
Лабораторна Робота №7
Функції
Хід роботи 
-  Створив нову папку lab07

-  Перемістив потрібні файли для роботи в папку lab07 після чого отримали таку структуру директорій:

└── lab07
 ├── Makefile 
├── README.md 
├── doc 
 │        └── lab07.txt
 └── src 
          └── main.c



1.   Лабораторна робота №5
          
1)  Зайшов до файлу main.c і почав роботу;

Вихідний код програми знаходиться у файлі main.c. 
Програма складається з двох функцій: vypadkove_chyslo() та main(). Перша функція vypadkove _chyslo() генерує випадкове число в межах від 0 до 9 і повертає його значення. Для отримання випадкових чисел використовується функція rand() з встановленою вихідною точкою time(NULL) для ініціалізації генератора випадкових чисел.
Точка входу в програму - це функція  main(). Ця функція є основною точкою входу в програму, яка виконує всі необхідні обчислення та операції.
2)  Створюємо функцію vypadkove _chyslo(), де 
виконується генерація випадкових, цілих чисел від 0 до 9.
3) Оголосив змінну   result для збереження цілих чисел (показника результату)
4) Задав умову за допомогою if:

if (num == 0){
return 0; // Число нуль не є простим числом
}

Якщо число num буде дорівнювати нулю, то програма закінчує роботу.


5) Скористався умовним оператором if:
  if (num <= 1) {
    result = 0;
Якщо число <= 1, то змінна result = 0.  
6) У блоці else ми використовуємо цикл for. 
int i = 2;: Спочатку визначається змінна “I” i дорівнює 2. Це стартове значення для ітерації. В даному випадку, ми починаємо перевірку з поточного значення i рівного 2.
i * i <= num;: Це умова циклу. Поки ця умова виконується (тобто квадрат i менше або дорівнює числу num), цикл продовжує виконувати своє тіло. Це означає, що цикл буде тривати до тих пір, поки i не стане більше або рівним квадратному кореню числа num.
i++: Після кожної ітерації циклу значення змінної i збільшується на 1. Це означає, що на кожній новій ітерації цикл перевіряє наступне число (наприклад, з 2 переходить до 3, потім до 4 і так далі), і перевірка продовжується до тих пір, поки умова циклу не стане невірною.

7) Після чого, скористався оператором if:
 if (result == 1) {
  //Число є простим 
}

Else {
//число не є простим
}
Якщо змінна result буде дорівнювати 1, то число є простим.
В інакшому випадку число не є простим.

8) Ввели команду gcc main.c -o myProgram. Після чого створився файл myProgram;
9) Скомпілював код за допомогою команди make all:
osboxes@osboxes:~/Untitled Folder/programming-Iovov_/lab07/Changed lab05$ make all
rm -rf dist
mkdir dist
clang  -std=gnu11 -g -Wall -Wextra -Werror -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wno-unused-variable -Wno-implicit-int-float-conversion -Werror=vla  src/main.c -o ./dist/main.bin
clang-format --verbose -dry-run --Werror src/*
Formatting src/a.out
Formatting src/main.c
Formatting src/myProg
clang-tidy src/*.c  -checks=-readability-uppercase-literal-suffix,-readability-magic-numbers,-clang-analyzer-deadcode.DeadStores,-clang-analyzer-security.insecureAPI.rand
Error while trying to load a compilation database:
Could not auto-detect compilation database for file "src/main.c"
No compilation database found in /home/osboxes/Untitled Folder/programming-Iovov_/lab07/Changed lab05/src or any parent directory
fixed-compilation-database: Error while opening fixed database: No such file or directory
json-compilation-database: Error while opening JSON database: No such file or directory
Running without flags.
rm -rf src/*.dump


10) Перевіримо роботу коду за допомогою lldb:
(lldb) target create "main.bin"
Current executable set to '/home/osboxes/Untitled Folder/programming-Iovov_/lab07/Changed lab05/dist/main.bin' (x86_64).
(lldb) breakpoint set --file main.c --line 39
Breakpoint 1: where = main.bin`main + 176 at main.c:39:1, address = 0x0000000000401230
(lldb) r
Process 6556 launched: '/home/osboxes/Untitled Folder/programming-Iovov_/lab07/Changed lab05/dist/main.bin' (x86_64)
Process 6556 stopped
* thread #1, name = 'main.bin', stop reason = breakpoint 1.1
    frame #0: 0x0000000000401230 main.bin`main at main.c:39:1
   36     }
   37   
   38     return 0;
-> 39   }
(lldb) p result
(int) $0 = 1
(lldb) p num
(int) $1 = 7
Як бачимо, код  коректно визначає випадкове число чи є воно простим.

Код програми:
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int vypadkove _chyslo(){
  srand((unsigned int)time(NULL));
  return rand() % 10;
}

int main() 
  int num = vypadkove _chyslo()
  int result =
      1; // Початкове значення result - 1 (припускаємо, що число є простим)

  if (num == 0) {
    return 0; // Число 0 не є простим
  }

  // Перевірка чи є число менше або дорівнює 2
  if (num <= 1) {
    result = 0; // Якщо число менше або дорівнює 1, то воно не є простим
  } else {
    for (int i = 2; i * i <= num; i++) {
      if (num % i == 0) {
        result = 0; // Знайдено дільник, отже число не є простим
        break;
      }
    }
  }

  if (result == 1) {
    // число є простим
  } else {
    //число не є простим
  }

  return 0;




2.  Лабораторна робота №6

1)   Зайшов до файлу main.c і почав роботу;
Вихідний код програми знаходиться у файлі main.c. 

Вихідний код програми знаходиться у файлі main.c. Точка входу в програму - це функція int main(). Ця функція є основною точкою входу в програму, яка виконує всі необхідні обчислення та операції.
2)  С початку ініцілізував функцію generate_random_number(), яка генерує випадкове число від 1 до 3.
3)    Ініцілізували змінну result для зберігання кількості слів.
4)  Створили змінну  isWord, в якості   показника, чи почалось слово.
5)  Ініцілізував  генератор випадкових чисел зі значенням часу.
6)   Використаємо функцію generate_random_number() для генерації випадкових чисел для змінної a.
7)   Створили масив text для зберігання тексту який буде передаватися з інших масивів.
8)   Ініцілізуємо  масиви
char text_1[] = "Hello world !";
   
char text_2[] = "How are you ? ";
    
    char text_3[] = "Hello everyone ! ";
Для передачі символів масиву text.
9)  Скористався умовним оператором if для того, щоб задати умову:
Якщо змінна a = 1, то перебираємо всі елементи масиву   text_1, під час якого передаємо елементи масиву text.
10)  Повторюємо такий  алгоритм з text_2, text_3.
11)  Для того, щоб порахувати кількість слів у масиві скористаємося циклом for:
Перебираємо всі елементи масиву до тих пір поки масив не закінчиться.
Задаємо умову: якщо елемент масиву змінної text дорівнює пробілу, табуляції, переходу на інший рядок, окличному знаку і знаку питання, то виконується інша умова:
Якщо слово почалося, то додаємо 1 до змінної result, й змінна isWord буде дорівнювати 1.
В інакшому випадку, якщо поточний символ дорівнює пробілу, табуляції або символу рядка, то слово закінчилось.
12)  Ввели команду gcc main.c -o myProgram. Після чого створився файл myProgram.


13)  Скомпілював код за допомогою команди make all:
osboxes@osboxes:~/Untitled Folder/programming-Iovov_/lab07/Changed lab06(1) $ make all
rm -rf dist
mkdir dist
clang  -std=gnu11 -g -Wall -Wextra -Werror -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wno-unused-variable -Wno-implicit-int-float-conversion -Werror=vla  src/main.c -o ./dist/main.bin
clang-format --verbose -dry-run --Werror src/*
Formatting src/MyProg
Stack dump:
0. Program arguments: clang-format --verbose -dry-run --Werror src/MyProg src/a.out src/main.c 
/lib/x86_64-linux-gnu/libLLVM-10.so.1(_ZN4llvm3sys15PrintStackTraceERNS_11raw_ostreamE+0x1f)[0x7fe8230f04ff]
/lib/x86_64-linux-gnu/libLLVM-10.so.1(_ZN4llvm3sys17RunSignalHandlersEv+0x50)[0x7fe8230ee7b0]
/lib/x86_64-linux-gnu/libLLVM-10.so.1(+0x981ac5)[0x7fe8230f0ac5]
/lib/x86_64-linux-gnu/libpthread.so.0(+0x14420)[0x7fe8298bf420]
/lib/x86_64-linux-gnu/libLLVM-10.so.1(_ZNK4llvm9SourceMgr10GetMessageENS_5SMLocENS0_8DiagKindERKNS_5TwineENS_8ArrayRefINS_7SMRangeEEENS6_INS_7SMFixItEEE+0xe5)[0x7fe823094795]
clang-format[0x40916d]
clang-format[0x406b64]
/lib/x86_64-linux-gnu/libc.so.6(__libc_start_main+0xf3)[0x7fe822253083]
clang-format[0x40652e]
Segmentation fault (core dumped)
make: *** [Makefile:15: check] Error 139

14)  Перевіримо роботу коду за допомогою lldb:

osboxes@osboxes:~/Untitled Folder/programming-Iovov_/lab07/Changed lab06(1) /dist$ lldb main.bin
(lldb) target create "main.bin"
Current executable set to '/home/osboxes/Untitled Folder/programming-Iovov_/lab07/Changed lab06(1) /dist/main.bin' (x86_64).
(lldb) breakpoint set --file main.c --line 81
Breakpoint 1: where = main.bin`main + 685 at main.c:81:5, address = 0x000000000040141d
(lldb) r
Process 26665 launched: '/home/osboxes/Untitled Folder/programming-Iovov_/lab07/Changed lab06(1) /dist/main.bin' (x86_64)
Process 26665 stopped
* thread #1, name = 'main.bin', stop reason = breakpoint 1.1
    frame #0: 0x000000000040141d main.bin`main at main.c:81:5
   78   
   79   
   80   
-> 81       return 0;
   82   }
(lldb) p result
(int) $0 = 2
(lldb) p text
(char [100]) $1 = "Hello everyone ! "
Результат лабораторної роботи:
Код генерує випадкове число й записує текст з одного масиву в основний, потім рахує кількість слів.


Код програми:
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int generate_random_number() {
    
    return (rand() % 3) + 1; // Генеруємо випадкове число від 1 до 3
}


int main() {
    
      int result = 0; //Змінна для зберігання кількості слів 
  int isWord = 0; // Флаг, який вказує, чи розпочалось слово

    srand((unsigned int)time(NULL)); // Ініціалізуємо генератор випадкових чисел зі значенням часу
    
    
    
    int a = generate_random_number(); // Генеруємо випадкове число
    
    
    
    
    char text[100];
    
    char text_1[] = "Hello world !";
    
    char text_2[] = "How are you ? ";
    
    char text_3[] = "Hello everyone ! ";
    
    

    if (a == 1) {
        int i; // Ініціалізуємо i перед використанням у циклі
        for (i = 0; text_1[i] != '\0'; i++) {
            text[i] = text_1[i];
        }
       
    }

    

if (a == 2) {
        int i; // Ініціалізуємо i перед використанням у циклі
        for (i = 0; text_2[i] != '\0'; i++) {
            text[i] = text_2[i];
        }
        
    }

  
    if (a == 3) {
        int i; // Ініціалізуємо i перед використанням у циклі
        for (i = 0; text_3[i] != '\0'; i++) {
            text[i] = text_3[i];
        }
       
    }

    
    
    
      for (int i = 0; text[i] != '\0'; i++) {  //Перевірка   кожного символа рядка до завершення рядка
//Перевірка на пробіли, табуляції та символом нового рядка, а також  на знак оклику, питання
    if (text[i] != ' ' && text[i] != '\t' && text[i] != '\n' && text[i] != '!' && text[i] != '?') {
      if (!isWord) {
        result++;
        isWord = 1;
      }
    } else {  //Якщо поточний символ дорівнює пробілу, табуляції або символу рядка, то слово закінчилось 
      isWord = 0;
    }
  }



    return 0;
}




3.  Додаткове завдання №1

  1)     Зайшов до файлу main.c і почав роботу;
Вихідний код програми знаходиться у файлі main.c. 

Вихідний код програми знаходиться у файлі main.c. Точка входу в програму - це функція int main(). Ця функція є основною точкою входу в програму, яка виконує всі необхідні обчислення та операції.
2)   Визначили константу N, яка  буде дорівнювати розмірності масиву.
3)   Створимо функцію find_count_of_pairs
для того, щоб знайти пари чисел, де одне чсло більше  другого.
4)  У функції find_count_of_pairs створив змінну count для збергігання кількості пар.
5)  Створили зовнішній цикл for для перебору усіх елементів масиву, внутрішній – порівнює кожен елемент з рештою.
6)  Скористався умовним оператором if:
Якщо елемент масиву I менше за елемент j, то збільшується лічильник count.

7)  Створимо масив arr для зберігання чисел.
8)  Ініцілізуємо функцію  find_count_of_pairs.
Для знаходження пар чисел, яка буде повертати змінну count.
9)  Після чого створимо змінну result де буде зберігатися кількість пар чисел.


10)  Ввели команду gcc main.c -o myProgram. Після чого створився файл myProgram.

11)  Скомпілював код за допомогою команди make all:
osboxes@osboxes:~/Untitled Folder/programming-Iovov_/lab07/Dodatkove_Zavdannya(1)$ make all
rm -rf dist
mkdir dist
clang  -std=gnu11 -g -Wall -Wextra -Werror -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wno-unused-variable -Wno-implicit-int-float-conversion -Werror=vla  src/main.c -o ./dist/main.bin
clang-format --verbose -dry-run --Werror src/*
Formatting src/MyProg
Stack dump:
0. Program arguments: clang-format --verbose -dry-run --Werror src/MyProg src/a.out src/main.c 
/lib/x86_64-linux-gnu/libLLVM-10.so.1(_ZN4llvm3sys15PrintStackTraceERNS_11raw_ostreamE+0x1f)[0x7f364a9724ff]
/lib/x86_64-linux-gnu/libLLVM-10.so.1(_ZN4llvm3sys17RunSignalHandlersEv+0x50)[0x7f364a9707b0]
/lib/x86_64-linux-gnu/libLLVM-10.so.1(+0x981ac5)[0x7f364a972ac5]
/lib/x86_64-linux-gnu/libpthread.so.0(+0x14420)[0x7f3651141420]
/lib/x86_64-linux-gnu/libLLVM-10.so.1(_ZNK4llvm9SourceMgr10GetMessageENS_5SMLocENS0_8DiagKindERKNS_5TwineENS_8ArrayRefINS_7SMRangeEEENS6_INS_7SMFixItEEE+0xe5)[0x7f364a916795]
clang-format[0x40916d]
clang-format[0x406b64]
/lib/x86_64-linux-gnu/libc.so.6(__libc_start_main+0xf3)[0x7f3649ad5083]
clang-format[0x40652e]
Segmentation fault (core dumped)
make: *** [Makefile:15: check] Error 139

12)  Перевіримо роботу коду за допомогою lldb:
osboxes@osboxes:~/Untitled Folder/programming-Iovov_/lab07/Dodatkove_Zavdannya(1)/dist$ lldb main.bin
(lldb) target create "main.bin"
Current executable set to '/home/osboxes/Untitled Folder/programming-Iovov_/lab07/Dodatkove_Zavdannya(1)/dist/main.bin' (x86_64).
(lldb) breakpoint set --file main.c --line 30
Breakpoint 1: where = main.bin`main + 63 at main.c:30:5, address = 0x00000000004011df
(lldb) r
Process 2278 launched: '/home/osboxes/Untitled Folder/programming-Iovov_/lab07/Dodatkove_Zavdannya(1)/dist/main.bin' (x86_64)
Process 2278 stopped
* thread #1, name = 'main.bin', stop reason = breakpoint 1.1
    frame #0: 0x00000000004011df main.bin`main at main.c:30:5
   27   
   28       int result = find_count_of_pairs(arr); // Ініцілізація функції для знаходження  пар чисел
   29       
-> 30       return 0;
   31   }
(lldb) p result
(int) $0 = 10
(lldb) p arr
(int [5]) $1 = ([0] = 1, [1] = 2, [2] = 3, [3] = 4, [4] = 5)
(lldb) q

Код програми:

#include <stdio.h>
#include <stdlib.h>
#define N 5

int find_count_of_pairs(int arr[],...) {
    int count = 0;     // Лічильник кількості пар
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            
            if (arr[i] < arr[j]) {
                count++;
            }
        }
    }
    return count;
}


int main() {
    
    int arr[N] = {1, 2, 3, 4,5}; //Масив для зберігання чисел 

    int result = find_count_of_pairs(arr); // Ініцілізація функції для знаходження  пар чисел
    
    return 0;
}









