#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 2;
    long long cur = 2;
    while (n < 32) {
        cur *= 2;
        n++;
        int fl = 1;
        for (int i = 2; i < (int)sqrt(cur - 1) + 1; i++) {
            if ((cur - 1) % i == 0) {
                fl = 0;
                break;
            }
        }
        if (fl)
            printf("%lld\n", cur - 1);
    }
    return 0;
}
