#include <stdio.h>

int main() {
    
    // Оголошуємо та ініціалізуємо змінні для зберігання цілих чисел 
    int k = 5;
    int m = 7;
    int n = 5;
    
    // Змінна для збереження результату обміну
    int result;
    
    // Виводимо початкові значення змінних
    int initial_k = k;
    int initial_m = m;
    int initial_n = n;
    
    // Перевірка та обмін значень змінних, щоб виконувалася умова k <= m <= n
    
    // Якщо k > m, то відбувається обмін значень m та k
    if (k > m) {
        result = k;
        k = m;
        m = result;
    }
    
    // Якщо m > n, то відбувається обмін значень m та n
    if (m > n) {
        result = m;
        m = n;
        n = result;
    }
    
    // Якщо k > m, то відбувається обмін значень k та m
    if (k > m) {
        result = k;
        k = m;
        m = result;
    }
    
    
    return 0;
}
