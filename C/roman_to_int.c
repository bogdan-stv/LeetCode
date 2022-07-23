#include <stdio.h>
#include <string.h>

/*
Given a roman numeral, convert it to an integer.
*/
int roman_to_int(char* roman_number)
{
    int tab['X' + 1] = {
           ['I'] = 1,
           ['V'] = 5,
           ['X'] = 10,
           ['L'] = 50,
           ['C'] = 100,
           ['D'] = 500,
           ['M'] = 1000,};
    int result = 0;
    for(int index = 0; roman_number[index]; index++)
        if(tab[roman_number[index]] >= tab[roman_number[index + 1]])
            result += tab[roman_number[index]];
        else
            result -= tab[roman_number[index]];
    return result;
}

// less memory use
int roman_to_int2(char* roman_number) 
{
    int num = 0;
    int result = 0;
    for(int i = strlen(roman_number) - 1; i >= 0; i--) {
        switch(*(roman_number + i))
        {
        case 'I':
            num = 1;
            break;
        case 'V':
            num = 5;
            break;
        case 'X':
            num = 10;
            break;
        case 'L':
            num = 50;
            break;
        case 'C':
            num = 100;
            break;
        case 'D':
            num = 500;
            break;
        case 'M':
            num = 1000;
            break;  
        default:
            break;
        }
        if (4 * num < result) 
            result -= num;
        else 
            result += num;
    }
    return result;
}


int main()
{
    printf("%d\n", roman_to_int("MMMDIV"));
}