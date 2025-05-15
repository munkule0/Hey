#include <stdio.h>


struct EngiinButarxai {
    int d; // hvrtver
    int n; // huwiar
};
typedef struct EngiinButarxai EngiinButarxai;

// hamgiin ih eronhi huwaagc
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

EngiinButarxai simplify(EngiinButarxai f) {
    int divisor = gcd(f.d, f.n);
    f.d /= divisor;
    f.n /= divisor;
    if (f.n < 0) { 
        f.d = -f.d;
        f.n = -f.n;
    }
    return f;
}

// nemeh
EngiinButarxai add(EngiinButarxai a, EngiinButarxai b) {
    EngiinButarxai result;
    result.d = a.d * b.n + b.d * a.n; 
    result.n = a.n * b.n; 
    return simplify(result); 
}

// hasah
EngiinButarxai sub(EngiinButarxai a, EngiinButarxai b) {
    EngiinButarxai result;
    result.d = a.d * b.n - b.d * a.n; 
    result.n = a.n * b.n; 
    return simplify(result); 
}

// vrjih
EngiinButarxai mult(EngiinButarxai a, EngiinButarxai b) {
    EngiinButarxai result;
    result.d = a.d * b.d; 
    result.n = a.n * b.n; 
    return simplify(result); 
}

// huwaah
EngiinButarxai div(EngiinButarxai a, EngiinButarxai b) {
    EngiinButarxai result;
    result.d = a.d * b.n; 
    result.n = a.n * b.d; 
    return simplify(result); 
}

// print
void print(EngiinButarxai a) {
    if (a.n == 1) {
        printf("%d\n", a.d); 
    } else {
        printf("%d/%d\n", a.d, a.n); 
    }
}

int main() {
    EngiinButarxai a = {3, 4}; //  3/4
    EngiinButarxai b = {2, 5}; //  2/5

    
    EngiinButarxai sum = add(a, b);
    printf("nemeh vr dun: ");
    print(sum);

    
    EngiinButarxai difference = sub(a, b);
    printf("hasah vr dvn: ");
    print(difference);

    
    EngiinButarxai product = mult(a, b);
    printf("vrjih vr dvn: ");
    print(product);

    
    EngiinButarxai quotient = div(a, b);
    printf("huwaah vr dun: ");
    print(quotient);

    return 0;
}
