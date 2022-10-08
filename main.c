#include <stdio.h>
#include <stdlib.h>
char numerals[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

int num_digits(int);
int add_1_3(int, char*, int, int*);
int add_5_8(int, char*, int, int*);

int main (int argc, char *argv[]) {
    char *a = argv[1];
    int num = atoi(a); 
    int digits = num_digits(num);
    char* roman = (char*)malloc(sizeof(char) * 10);
    printf("%d\n", digits);
    int curr_digit;
    int last_pos = 0;
     
    for (int i = 0; i < digits; i++) {
        curr_digit = num % 10;
        num /= 10;
        printf("LOOP:\n");
        switch (curr_digit) {
            case 1 ... 3:
                printf("%d case 1 ... 3\n", i);
                add_1_3(curr_digit, roman, i, &last_pos);
                break;
            case 4:
                break;
            case 5 ... 8:
                printf("Case 5 ... 8:\n");
                add_5_8(curr_digit, roman, i, &last_pos);
                break;
            case 9:
                break;
        }
        
    }
    
    roman[last_pos] = '\0';
    printf("%s", roman);

    return 0;
}

int num_digits(int num) {
    if (num >= 10) 
        return 1 + num_digits(num / 10);
    else 
        return 1;
}

// Generates roman numerals I,II,III
int add_1_3(int curr_digit, char* roman, int i, int* last_pos) {
    printf("%d %c\n", curr_digit, roman[i+2]);
    for (int count = 0; count < curr_digit; count++) {
        roman[*last_pos] = (char)numerals[i * 2];
        *last_pos = *last_pos + 1;
    }
}

// Generates roman numerals V, VI, VII, III
int add_5_8(int curr_digit, char* roman, int i, int* last_pos) {
    roman[*last_pos] = numerals[i * 2 + 1]; 
    *last_pos = *last_pos + 1;
    add_1_3(curr_digit - 5, roman, 0, last_pos);
}
