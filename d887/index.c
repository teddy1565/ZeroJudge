#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>



long long int catalan(int n) {
    if (n < 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }

    long long int c = 1;
    for (int i = 1; i <= n; i++) {
        c = c * 2 * (2 * (long long)i - 1) / (i + 1);
    }

    return c;
}

int main(void) {
    
    /**
     * @brief n mean, mountain top
     * 
     */
    int n = 2;
    
    while (scanf("%d", &n) != EOF) {
        long long int ans = catalan(n);
        printf("%lld\n", ans);
    }

    

    return 0;
}