#include <stdio.h>

double absolute(double value) {
    return value < 0 ? -value : value;
}

int main() {
    double epsilon;
    scanf("%lf", &epsilon);
    
    double x;
    while (scanf("%lf", &x) != EOF) {        
        if (x == 0) {
            printf("%.10g\n", 0.0);
            continue;
        }
        
        double current = 1.0;
        double next;
        
        do {
            next = 0.5 * (current + x / current);
            if (absolute(next - current) < epsilon) {
                break;
            }
            current = next;
        } while (1);
        printf("%.10g\n", next);
    }
    
    return 0;
}

