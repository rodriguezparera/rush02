#include "includes/dict.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_VALUES 100

t_dict *p_dict;

int ft_len(const char *str) 
{
    int n = 0;
    while (*str) {
        n++;
        str++;
    }
    return n;
}



void zeros(int n,  char values[MAX_VALUES][100], int *index) 
{
    char value[100];
    int size = (n * 3) + 2;
    char *zeros = malloc(size * sizeof(char));

    zeros[0] = '1';
    int i = 1;
    while (i < size - 1) {
        zeros[i] = '0';
        i++;
    }
    zeros[size - 1] = '\0';
    get_dict_value(p_dict, zeros, value);

    // Store only if the value is not "zero"
    if (strcmp(value, "zero") != 0) {
        strcpy(values[*index], value);
        (*index)++;
    }

    free(zeros);
}

void descomp(char one, char two, char three, char values[MAX_VALUES][100], int *index) 
{
    char deu[3];
    char s_one[2];
    //char s_two[2];
    char s_three[2];
    char value[100];

    s_one[0] = one;
    s_one[1] = '\0';
    s_three[0] = three;
    s_three[1] = '\0';
    
    if (two == '1' && three != '\0') {
        deu[0] = two;
        deu[1] = three;
        deu[2] = '\0';
        get_dict_value(p_dict, deu, value);
        strcpy(values[*index], value);
        (*index)++;
        return; 
    }

    if (three != '\0') {
        get_dict_value(p_dict, s_three, value);
        strcpy(values[*index], value);
        (*index)++;
    }

    if (two != '\0') {
        if (two > '1') {
            deu[0] = two;    
            deu[1] = '0';
            deu[2] = '\0';
            get_dict_value(p_dict, deu, value);
            strcpy(values[*index], value);
            (*index)++;
        }
    }

    if (one != '\0' && one > '0') {
        get_dict_value(p_dict, "100", value);
        strcpy(values[*index], value);
        (*index)++;
        get_dict_value(p_dict, s_one, value);
        strcpy(values[*index], value);
        (*index)++;
    }
}

void detect_series(const char *number, int n, char values[MAX_VALUES][100], int *index) 
{
    int groups = 0;

    while (n > 0) {
        char one = '\0';
        char two = '\0';
        char three = '\0';

        if (n - 3 >= 0) {
            one = number[n - 3];
        }
        if (n - 2 >= 0) {
            two = number[n - 2];
        }
        if (n - 1 >= 0) {
            three = number[n - 1];
        }

        groups++;
        descomp(one, two, three, values, index);

        n -= 3;

        if (n > 0) {
            zeros(groups, values, index);
        }
    }

}

void print_values_reversed(char values[MAX_VALUES][100], int index) 
{
    int i = index - 1;
    int skip = 0;
    
    while (i >= 0) {

        if (strcmp(values[i], "zero") != 0) 
        {
            if (skip && 
                (strcmp(values[i], "hundred") == 0 || 
                 strcmp(values[i], "thousand") == 0 ||
                 strcmp(values[i], "million") == 0 ||
                 strcmp(values[i], "billion") == 0 ||
                 strcmp(values[i], "trillion") == 0 ||
                 strcmp(values[i], "quadrillion") == 0 ||
                 strcmp(values[i], "quintillion") == 0 ||
                 strcmp(values[i], "sextillion") == 0 ||
                 strcmp(values[i], "septillion") == 0 ||
                 strcmp(values[i], "octillion") == 0 ||
                 strcmp(values[i], "nonillion") == 0 ||
                 strcmp(values[i], "decillion") == 0 ||
                 strcmp(values[i], "undecillion") == 0)) {
                 skip = 1;
                i--;
                continue;
            }
            
            write (1, values[i], strlen(values[i]));
            write (1 , " ", 1);
            skip = 0;
        } 
        else 
        
            skip = 1;
        
        i--;
    }
    write (1 , "\n", 1);
}
int main(int argc, char **argv) 
{
    
    int n; 
    char values[MAX_VALUES][100];
    int index = 0;
        
    n = ft_len(argv[2]);
   
    if (argc == 2)
        {
            load_dict(&p_dict, "numbers.dict");
        }
    if (argc == 3)
        {
            load_dict(&p_dict, argv[1]);
        }
    else
        {
            load_dict(&p_dict, "numbers.dict");
        }
    //print_dict(p_dict);
    detect_series(argv[2], n, values, &index);
    print_values_reversed(values, index);
    
  
    return 0;
}
