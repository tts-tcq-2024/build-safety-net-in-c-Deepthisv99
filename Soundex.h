#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

char GetSoundexCode(char character);
void InitializeTheSoundex(const char *name, char *soundex);
void AppendingSoundexCharacters(const char *name, char *soundex);
void Characters(char character, char *soundex, char *prevCode);
int AppendCode(char code, char prevCode);
void SoundexCode(char *soundex);
char GetSoundexCode(char character);
char *GenerateSoundex(const char *name);

char *GenerateSoundex(const char *name) {
    
    if (name == NULL || *name == '\0') {
        static char empty[] = "";
        return empty;
    }
    char soundex[5];
    InitializeTheSoundex(name, soundex);
    char prevCode = GetSoundexCode(name[0]);
    AppendingSoundexCharacters(name, soundex);
    SoundexCode(soundex);
    static char result[5];
    strcpy(result, soundex);
    return result;
}


void InitializeTheSoundex(const char *name, char *soundex) {
    soundex[0] = toupper(name[0]);
    soundex[1] = '\0'; // Null-terminate string
}


void AppendingSoundexCharacters(const char *name, char *soundex) {
    char prevCode = GetSoundexCode(name[0]);
    for (int i = 1; i < strlen(name) && strlen(soundex) < 4; i++) {
        Characters(name[i], soundex, &prevCode);
    }
}


void Characters(char character, char *soundex, char *prevCode) {
    if (isalpha(character)) {
        char code = GetSoundexCode(character);
        if (AppendCode(code, *prevCode)) {
            int len = strlen(soundex);
            soundex[len] = code;
            soundex[len + 1] = '\0'; // Null-terminate string
            *prevCode = code;
        }
    }
}


int AppendCode(char code, char prevCode) {
    return code != 0 && code != prevCode;
}


void SoundexCode(char *soundex) {
    while (strlen(soundex) < 4) {
        strcat(soundex, "0");
    }
}


char getSoundexCode(char character) {
    character = toupper(character);
    switch (character) {
        case 'B': case 'F': case 'P': case 'V': return '1';
        case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z': return '2';
        case 'D': case 'T': return '3';
        case 'L': return '4';
        case 'M': case 'N': return '5';
        case 'R': return '6';
        default: return '0'; // For A, E, I, O, U, H, W, Y
    }
}
// Test function (main)
int main() {
    // Testing the GenerateSoundex function
    printf("Test 1: %s\n", GenerateSoundex("")); 
    printf("Test 2: %s\n", GenerateSoundex("C")); 
    printf("Test 3: %s\n", GenerateSoundex("Code")); 
    printf("Test 4: %s\n", GenerateSoundex("CodeandBugs")); 
    printf("Test 5: %s\n", GenerateSoundex("Bugs789")); 
    printf("Test 6: %s\n", GenerateSoundex("Challenge")); 

    return 0;
}
#endif

