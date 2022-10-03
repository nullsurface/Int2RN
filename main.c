#include <stdio.h>
#include <stdlib.h>
char numerals[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

int num_digits(int num);

int main () {
    int num = 4231;
    int digits = num_digits(num);
    char* roman = (char*)malloc(digits);
    
    for (int i = 0; i < digits; i++) {}

    return 0;
}

int num_digits(int num) {
    if (num > 10) 
        return 1 + num_digits(num / 10);
    else 
        return 1;
}
