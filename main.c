#include <stdio.h>
#include <stdlib.h>
char numerals[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

int num_digits(int);
void add_1_3(int, char*, int, int*);
void add_5_8(int, char*, int, int*);
void add_4(int, char*, int, int*);
void add_9(int, char*, int, int*);

int main (int argc, char *argv[]) {
    char *a = argv[1];
    int num = atoi(a); 
    int digits = num_digits(num);
    char roman[16];
    int curr_digit;
    int last_pos = 0;
     
    for (int i = 0; i < digits; i++) {
        curr_digit = num % 10;
        num /= 10;
        switch (curr_digit) {
            case 1 ... 3:
                add_1_3(curr_digit, roman, i, &last_pos);
                break;
            case 4:
                add_4(curr_digit, roman, i, &last_pos);
                break;
            case 5 ... 8:
                add_5_8(curr_digit, roman, i, &last_pos);
                break;
            case 9:
                add_9(curr_digit, roman, i, &last_pos);
                break;
        }
        
    }

    char* temp = (char*)malloc(sizeof(char) * 16);
    temp[last_pos] = '\0';
    for (int i = last_pos - 1; i >= 0; i--) {
        temp[last_pos - i - 1] = roman[i];
    }

    printf("%s", temp);

    return 0;
}

int num_digits(int num) {
    if (num >= 10) 
        return 1 + num_digits(num / 10);
    else 
        return 1;
}

// Generates roman numerals I,II,III
void add_1_3(int curr_digit, char* roman, int i, int* last_pos) {
    for (int count = 0; count < curr_digit; count++) {
        roman[*last_pos] = (char)numerals[i * 2];
        *last_pos = *last_pos + 1;
    }
}

// Generates roman numerals V, VI, VII, III
void add_5_8(int curr_digit, char* roman, int i, int* last_pos) {
    add_1_3(curr_digit - 5, roman, i, last_pos);
    roman[*last_pos] = numerals[i * 2 + 1]; 
    *last_pos = *last_pos + 1;
}

// Generates roman numerals IV, XL, ect.
void add_4(int curr_digit, char* roman, int i, int* last_pos) {
    roman[*last_pos] = numerals[i * 2 + 1];
    *last_pos = *last_pos + 1;
    roman[*last_pos] = numerals[i * 2]; 
    *last_pos = *last_pos + 1;
}

// Generate Roman Numerals IX, XC, ect
void add_9(int curr_digit, char* roman, int i, int* last_pos) { 
    roman[*last_pos] = numerals[i * 2 + 2];
    *last_pos = *last_pos + 1;
    roman[*last_pos] = numerals[i * 2]; 
    *last_pos = *last_pos + 1;
}
