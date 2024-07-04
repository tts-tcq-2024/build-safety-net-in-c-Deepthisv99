#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
char GetSoundexCode(char character) {
    character = toupper(character);
    switch (character) {
        case 'B': case 'F': case 'P': case 'V': return '1';
        case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z': return '2';
        case 'D': case 'T': return '3';
        case 'L': return '4';
        case 'M': case 'N': return '5';
        case 'R': return '6';
        default: return '0';
    }
}

void GenerateSoundex(char name[], char soundex[]) {
    if (name == NULL || strlen(name) == 0) {
        soundex[0] = '\0';
        return;
    }

    soundex[0] = toupper(name[0]);
    soundex[1] = '\0';
    char prevCode = GetSoundexCode(name[0]);
    int soundexIndex = 1;

    for (int i = 1; i < strlen(name) && soundexIndex < 4; i++) {
        if (isalpha(name[i])) {
            char code = GetSoundexCode(name[i]);
            if (code != '0' && code != prevCode) {
                soundex[soundexIndex++] = code;
                prevCode = code;
            }
        }
    }

    while (soundexIndex < 4) {
        soundex[soundexIndex++] = '0';
    }
    soundex[soundexIndex] = '\0';
}
