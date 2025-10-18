#include <stdio.h>
#include <stdlib.h>

char curlex; /* текущая лексема */
void getlex(void); /* выделяет из входного потока очередную лексему */
int expr(void); /* распознает выражение и вычисляет его значение */
int term(void); /* распознает слагаемое и вычисляет его значение */
int factor(void); /* распознает множитель и вычисляет его значение */
int power(void); /* распознает степень и вычисляет ее значение */
void error(void); /* сообщает об ошибке в выражении */

void error(void)
{
    exit(1);
}

void clear_input_buffer(void)
{
    while(getchar() != '\n');
}

int main()
{
    int result;
    
    while(1) {
        printf("==>");
        getlex();
        result = expr();
        if (curlex != '\n') {
            printf("\nERROR! Unexpected character\n");
            clear_input_buffer();
            continue;
        }
        printf("%d\n", result);
        
        // Спросить, хочет ли пользователь продолжить
        printf("Continue? (y/n): ");
        char answer = getchar();
        clear_input_buffer();
        if (answer != 'y' && answer != 'Y') {
            break;
        }
    }
    return 0;
}

void getlex()
{
    while ((curlex = getchar()) == ' ');
}

int expr()
{
    int e = term();
    while (curlex == '+' || curlex == '-')
    {
        char op = curlex;
        getlex();
        int t = term();
        if (op == '+')
            e += t;
        else
            e -= t;
    }
    return e;
}

int term()
{
    int t = factor();
    while (curlex == '*' || curlex == '/')
    {
        char op = curlex;
        getlex();
        int f = factor();
        if (op == '*')
            t *= f;
        else
        {
            if (f == 0) {
                printf("\nERROR! Division by zero\n");
                error();
            }
            t /= f;
        }
    }
    return t;
}

int factor()
{
    int f = power();
    while (curlex == '\'') /* используем ' для возведения в степень */
    {
        getlex();
        int p = power();
        if (p < 0) {
            printf("\nERROR! Negative exponent\n");
            error();
        }
        
        int result = 1;
        for (int i = 0; i < p; i++)
            result *= f;
        f = result;
    }
    return f;
}

int power()
{
    int p;
    switch(curlex){
        case '0': case '1': case '2': case '3': case '4': case '5':
        case '6': case '7': case '8': case '9': 
            p = curlex - '0'; 
            break;
        case '(': 
            getlex(); 
            p = expr();
            if (curlex == ')') 
                break;
            /* иначе ошибка - нет закрывающей скобки */
            printf("\nERROR! Missing closing bracket\n");
            error();
        default: 
            printf("\nERROR! Unexpected character: %c\n", curlex);
            error();
    }
    getlex();
    return p;
}
