#include <stdio.h>
#include <stdlib.h>
char numerals[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

int num_digits(int num);

int main () {
    int num = 12;
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
                        for (int count = 0; count < curr_digit; count++) {
                            printf("%d %c\n", count, roman[i+2]);
                            roman[last_pos] = (char)numerals[i * 2];
                            last_pos++;
                        }
                        break;
                    case 1 ... 3:
                        printf("%d %c", curr_digit, roman[i+2]);
                        for (int count = 0; count < curr_digit; count++) {
                            roman[last_pos] = (char)numerals[i * 2];
                            last_pos++;
                        }
                        break;
                }
                break;
            case 4:
                break;
            case 5 ... 8:
                break;
            case 9:
                break;
        }
        
    }
    
    roman[9] = '\0';
    printf("%s", roman);

    return 0;
}

int num_digits(int num) {
    if (num >= 10) 
        return 1 + num_digits(num / 10);
    else 
        return 1;
}
