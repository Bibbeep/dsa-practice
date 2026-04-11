#include <ctype.h>
#include <stdio.h>

int main() {
    char s1[101];
    char s2[101];
    unsigned long str_len = 0;

    scanf("%s %s", s1, s2);

    while (s1[str_len] != '\0') {
        str_len++;
    }

    for (int i = 0; i < str_len; i++) {
        if (s1[i] < 97) {
            s1[i] = tolower(s1[i]);
        }

        if (s2[i] < 97) {
            s2[i] = tolower(s2[i]);
        }

        if (s1[i] < s2[i]) {
            printf("-1\n");
            break;
        } else if (s2[i] < s1[i]) {
            printf("1\n");
            break;
        } else if (i == str_len - 1) {
            printf("0\n");
            break;
        }
    }

    return 0;
}
