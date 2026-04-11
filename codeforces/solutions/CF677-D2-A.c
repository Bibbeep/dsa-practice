#include <stdio.h>

int main() {
    int n, h;
    scanf("%d %d", &n, &h);

    int w = 0;

    while (n--) {
        int p;
        scanf("%d", &p);

        if (p > h) {
            w += 2;
        } else {
            w++;
        }
    }

    printf("%d\n", w);
    return 0;
}
