#include <stdio.h>

double str2double(char str[]) {
    double result = 0.0;
    double fraction = 0.0;
    int sign = 1;
    int exponent_sign = 1;
    int exponent = 0;
    int i = 0;
    double divisor = 1.0;
    int has_integer_part = 0;
    int has_fraction_part = 0;
    
    while (str[i] == ' ' || str[i] == '\t') {
        i++;
    }
    
    if (str[i] == '-') {
        sign = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }
    
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10.0 + (str[i] - '0');
        i++;
     }
    
    // Дробная часть
    if (str[i] == '.') {
        i++;
        while (str[i] >= '0' && str[i] <= '9') {
            fraction = fraction * 10.0 + (str[i] - '0');
            divisor *= 10.0;
            i++;
 
        }
        result += fraction / divisor;
    }
    
     
    // Экспонента
    if (str[i] == 'e' || str[i] == 'E') {
        i++;
        
        if (str[i] == '-') {
            exponent_sign = -1;
            i++;
        } else if (str[i] == '+') {
            i++;
        }
        
        while (str[i] >= '0' && str[i] <= '9') {
            exponent = exponent * 10 + (str[i] - '0');
            i++;
        }
    }
    
    if (exponent != 0) {
        double power = 1.0;
        if (exponent_sign > 0) {
            for (int j = 0; j < exponent; j++) {
                power *= 10.0;
            }
        } else {
            for (int j = 0; j < exponent; j++) {
                power /= 10.0;
            }
        }
        result *= power;
    }
    
    return sign * result;
}

int main() {
    char str[100];
    
    while (scanf("%99s", str) == 1) {
        double number = str2double(str);
        printf("%.10g\n", number);
    }
    
    return 0;
}
