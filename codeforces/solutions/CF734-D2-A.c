#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned int n;
    scanf("%d", &n);

    char* s = malloc(sizeof(char) * (n + 1));
    scanf("%s", s);

    unsigned int anton = 0, danik = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            anton++;
        } else if (s[i] == 'D') {
            danik++;
        }
    }

    if (anton == danik) {
        printf("Friendship\n");
    } else if (anton > danik) {
        printf("Anton\n");
    } else {
        printf("Danik\n");
    }

    free(s);
    return 0;
}
