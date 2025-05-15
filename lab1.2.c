#include <stdio.h>

typedef struct {
    int a[2];
    double d;
} struct_t;

double fun(int i) {
    volatile struct_t s;

    if (i < 0 || i >= 2) {
        printf("hetersen baina..\n");
        return -1; 
    }
    s.d = 3.14;
    s.a[i] = 1073741824;
    return s.d;
}

int main() {
    int index = 3;  
    double result = fun(index);
    if (result != -1) {
        printf("vr dvn: %f\n", result);
    }
    return 0;
}
