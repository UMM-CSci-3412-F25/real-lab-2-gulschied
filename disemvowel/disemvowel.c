#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

static bool is_vowel(char c) {
    char lower = (c >= 'A' && c <= 'Z') ? c + 32 : c; 
    return (lower == 'a' || lower == 'e' || lower == 'i' ||
            lower == 'o' || lower == 'u');
}

char *disemvowel(char *str) {
    int len = strlen(str);
    int count = 0;

    for (int i = 0; i < len; i++) {
        if (!is_vowel(str[i])) {
            count++;
        }
    }

    char *result = (char *) calloc(count + 1, sizeof(char));

    int j = 0;
    for (int i = 0; i < len; i++) {
        if (!is_vowel(str[i])) {
            result[j++] = str[i];
        }
    }
    result[j] = '\0';

    return result; 
}