#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int freq[26] = {0};

    printf("Enter a string: ");
    gets(str);

    strlwr(str);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            freq[str[i] - 'a']++;
        }
    }

    printf("Frequency of each letter:\n");
    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0) {
            printf("%c : %d\n", i + 'a', freq[i]);
        }
    }

    return 0;
}