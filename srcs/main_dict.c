#include "../includes/dict.h"
#include <stdio.h>

int main(void)
{
    char *file_path = "../numbers.dict";
    t_dict *dict = NULL;
    char *key = "100";
    char value[100];
    int nret;

    nret = load_dict(dict, file_path);
    printf("\nReturn: %d, p_dict: %p, Key: %s, Value: %s", nret, dict, key, value);
    // get_dict_value(dict, key, value);
    // printf("\nReturn: %d, p_dict: %p, Key: %s, Value: %s", nret, dict, key, value);
    printf("\n");
}