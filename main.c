/*!
 * @file main.c
 * program calculates summary of numbers separated by space, comma, semicolon and ignore invalid parameters
 * @brief simple demonstration of 'strings.h' functions
 * @author Sergei Kachkov
 */

#include <stdio.h>
#include "strings.h"

#define STRING_LENGTH 256

int main()
{
    char str[STRING_LENGTH];
    while (1)
    {
        puts ("Input string: (type 'exit' to complete the work) ");
        fgets (str, STRING_LENGTH, stdin);

        if (str_str (str, "exit"))
            return 0;

        char *token = str_tok (str, " ,;");
        double sum = 0.0;
        while (token)
        {
            sum += str_to_d (token, NULL);
            token = str_tok (NULL, " ,;");
        }
        printf ("Sum: %.4f\n", sum);
    }
    return 0;
}
