
Іовов Микита Павлович
Лабораторна Робота №2
Вступ до програмування. Основи debug процессу


Хід роботи
1.Створив аккаунт на github та створив репозиторій з назвою
 programming-Iovov_
2. Склонувався із створеного репозиторію завдяки команді:
git clone https://github.com/Mykyta-Iovov/programming-Iovov_.git
3. Скопіював файли з репозиторію Sample_project та отримав таку структуру каталогів:
├──clang-format
├──clang-tidy
├──gitignore
├──gitlab-ci.yml
├──lab02
│  ├──Doxyfile
│  ├──Makefile
│  ├──README.md
│  ├──src
│  │  ├──lib.c
│  │  ├──lib.h
│  │  └──main.c
│  └──test
│    └──test.cpp
└──README.md
4.Зафіксував зміни за допомогою команди git commit:
-Дослідив роботу команди git commit
-Додав файли до git-індексу
-Дослідив команду git add:
git config –global user.email “iovovnikita6@gmail.com”
git config --global user.name "Mykyta-Iovov"
git add .
git commit -m “Initial copy of sample_project”
Результат команд:
13 files changed, 437 insertions(+), 1 delection (-)
 create mode 100644 lab02/README.md
 create mode 100644 clang-format
 create mode 100644 clang-tidy
 create mode 100644 gitlab-ci.yml
  create mode 100644 gitignore
 create mode 100644 lab02/Doxyfile
 create mode 100644 lab02/Makefile
 create mode 100644 lab02/src/lib.c
 create mode 100644 lab02/src/lib.h
 create mode 100644 lab02/src/main.c
 create mode 100644 lab02/test/test.cpp

5. Виконав зміни. Було додано новий тип тварини «Людина» у файлах lib.h, lib.c. Результат змін:
Інформація про тварину №01: Wolf: зріст = 96 см, маса = 37 гр. 
Інформація про тварину №02: Людина: зріст = 99 см, маса = 18 гр. 
Інформація про тварину №03: Tiger: зріст = 99 см, маса = 10 гр. 
Інформація про тварину №04: Людина: зріст = 67 см, маса = 68 гр. 
Інформація про тварину №05: Людина: зріст = 102 см, маса = 37 гр. 
Інформація про тварину №06: Bear: зріст = 7 см, маса = 116 гр. 
Інформація про тварину №07: Bear: зріст = 42 см, маса = 23 гр. 
Інформація про тварину №08: Wolf: зріст = 108 см, маса = 26 гр. 
Інформація про тварину №09: Tiger: зріст = 57 см, маса = 122 гр. 
Інформація про тварину №10: Wolf: зріст = 18 см, маса = 12 гр.

6. Відкрив у відлагоднику (debugger) lldb мій виконуючий файл. Були виконані команди: 
(lldb) target create "main.bin" 
Current executable set to '/home/osboxes/Untitled Folder/programming-Iovov_/lab02/dist/main.bin'  (x86_64).
(lldb) b main 
Breakpoint 1: where = main.bin`main + 22 at main.c:40:22, address = 0x0000000000401316

(lldb) r 
Process 1461 launched: ‘/home/osboxes/Untited Folder/programming-Iovov_/lab02/dist/main.bin’ (x86_64)
Process 1461 stopped
* thread #1, name = 'main.bin', stop reason = breakpoint 1.1
    frame #0: 0x0000000000401316 main.bin`main at main.c:40:22
   37    */
   38   int main()
   39   {
-> 40        srand((unsigned int)time(0));
   41        struct animal animals[ANIMAL_COUNT];
   42   
   43        for (unsigned int i = 0; i < ANIMAL_COUNT; i++) {
   44                    generate_animal(&animals[i]);
   45                 }
   46        show_animals(animals, ANIMAL_COUNT);


(lldb) n 
Process 1461 stopped
* thread #1, name = 'main.bin', stop reason = step over
    frame #0: 0x0000000000401322 main.bin`main at main.c:43:20
   40    srand((unsigned int)time(0));
   41    struct animal animals[ANIMAL_COUNT];
   42   
-> 43    for (unsigned int i = 0; i < ANIMAL_COUNT; i++) {
   44     generate_animal(&animals[i]);
   45    }
   46    show_animals(animals, ANIMAL_COUNT);

(lldb) p i
(unsigned int) $0 = 0
(lldb) finish

7.Зафіксував зміни завдяки команді:
git commit -m “add human and do lldb”

[main 1aeb3a6] add human and do lldb
 5 files changed, 12 insertions(+), 5 deletions(-)
 create mode 100755 lab02/dist/main.bin
8. Існують два режими компіляції для програм: з інформацією про відлагодження (debug mode) і без неї (release mode). Ці режими впливають на розмір програми, її швидкість та можливість налагодження. Зазвичай debug mode використовується під час розробки, де компілятор додає інформацію для відлагоджування, а release mode застосовується перед публікацією, де головною метою є оптимізація програми за рахунок зменшення розміру і підвищення швидкості виконання. Debug mode дозволяє відлагоджувачу контролювати виконання програми, тоді як release mode забезпечує швидшу та меншу програму, але ускладнює процес відлагодження.

9.Було створено .gitignore. Додав туди папку lab02/dist. Завантажив зміни на репозиторій за допомогою команди git push:

Username for 'https://github.com': programming-Iovov_
Password for 'https://programming-Iovov_@github.com': 
Enumerating objects: 37, done.
Counting objects: 100% (37/37), done.
Compressing objects: 100% (28/28), done.
Writing objects: 100% (36/36), 12.32 KiB | 664.00 KiB/s, done.
Total 36 (delta 7), reused 0 (delta 0)
remote: Resolving deltas: 100% (7/7), done.
To https://github.com/Mykyta-Iovov/programming-Iovov_.git
   484c56b..4e19c46  HEAD -> main
