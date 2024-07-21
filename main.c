#include <stdio.h>
#include <stdlib.h>


int ft_len(const char *str) {
    int n = 0;
    while (*str) {
        n++;
        str++;
    }
    return n;
}


void zeros(int n) {
    int size = (n * 3) + 2;
    char *zeros = malloc(size * sizeof(char));



    zeros[0] = '1';  
    int i = 1;
    while (i < size - 1) {
        zeros[i] = '0';  
        i++;
    }
    zeros[size - 1] = '\0';  

    printf("%s\n", zeros);
    free(zeros);  
}

void factorial(char one, char two, char three) {
    char *centenes = "100";
    char *decenes = "10";

    printf("%c\n", three);

    if (two > '1') {
        printf("%c0\n",two);
    }
    else if(two == '1' && three == '0')
        printf("%c%c", two, one);

    if (one > '0') {
        printf("%s\n%c\n", centenes, one);
    }
}


void detect_series(char *number, int n) {
    int groups = 0;
    
    
    
    

    while (n > 0) {
        groups++;
        factorial(number[n - 3], number[n - 2], number[n - 1]);
        zeros(groups);
        n -= 3;
    }

    printf("Total de grupos de tres: %d\n", groups);
}
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <cadena>\n", argv[0]);
        return 1;
    }

    int n = ft_len(argv[1]);
    detect_series(argv[1], n);
    printf("El número es: %s\n", argv[1]);
    printf("El array tiene: %d dígitos\n", n);

    return 0;
}
