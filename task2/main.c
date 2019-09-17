#include <stdio.h>
#include <stdlib.h>

long long gcd(long long a, long long b) {
    while (b) {
        long long c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    long long x, y, z;
    printf("Please enter natural numbers x, y, z (separated by space without commas) to find out if they are a Pythagorean triple\n");
    scanf("%lld %lld %lld", &x, &y, &z);

    if (x * x + y * y == z * z || x * x + z * z == y * y || y * y + z * z == x * x) {
        long long d = gcd(gcd(x, y), z);
        if (d == 1) {
            printf("This is a primitive Pythagorean triple");
        } else {
            printf("This is a Pythagorean triple");
        }
    } else {
        printf("This is not a Pythagorean triple");
    }

    return 0;
}
