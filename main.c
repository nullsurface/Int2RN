#include <stdio.h>
#include <stdlib.h>
char numerals[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

int num_digits(int);
int add_numerals(int, char*, int, int*);
int main () {
    int num = 5; 
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
                switch (i) {
                    case 0:
                        add_numerals(curr_digit, roman, i, &last_pos);
                        break;
                    case 1 ... 3:
                        add_numerals(curr_digit, roman, i, &last_pos); // need to fix tmr
                        break;
                }
                break;
            case 4:
                break;
            case 5 ... 8:
                printf("Case 5 ... 8:\n");
                add_numerals(curr_digit, roman, i+1, &last_pos);
                break;
            case 9:
                break;
        }
        
    }
    
    roman[last_pos] = '\0';
    printf("%s/n", roman);

    return 0;
}

int num_digits(int num) {
    if (num >= 10) 
        return 1 + num_digits(num / 10);
    else 
        return 1;
}

int add_numerals(int curr_digit, char* roman, int i, int* last_pos) {
    printf("%d %c\n", curr_digit, roman[i+2]);
    for (int count = 0; count < curr_digit; count++) {
        roman[*last_pos] = (char)numerals[i * 2];
        *last_pos = *last_pos + 1;
    }
}
