#include <stdio.h>

int main() {
    double x;
    
    scanf("%lf", &x);
    
    double poly = 0;
    double deriv = 0;
    double coefficient;
    
    while (scanf("%lf", &coefficient) == 1) {
        deriv = deriv * x + poly;
        poly = poly * x + coefficient;
    }
    
    printf("%.10g\n", poly);
    printf("%.10g\n", deriv);
    
}
