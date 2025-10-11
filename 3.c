#include <stdio.h>

// Итеративная версия
int fibonacci_iterative(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    int prev2 = 0;
    int prev1 = 1;
    int current;
    
    for (int i = 2; i <= n; i++) {
        current = prev2 + prev1;
        prev2 = prev1;
        prev1 = current;
    } 
    return current;
}

// Рекурсивная версия
int fibonacci_recursive(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    return fibonacci_recursive(n - 2) + fibonacci_recursive(n - 1);
}

int main() {
    int i;
    
    while (scanf("%d", &i) == 1) {
        if (i < 0) {
            fprintf(stderr, "Ошибка: индекс Фибоначчи не может быть отрицательным\n");
            continue;
        }
        
        int result_iter = fibonacci_iterative(i);
        printf("%d\n", result_iter);
        
        int result_rec = fibonacci_recursive(i);
        printf("%d\n", result_rec);
    }
    
    return 0;
}
