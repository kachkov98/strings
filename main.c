#include <stdio.h>
#include "strings.h"

int main()
{
    char str[256];
    while (1)
    {
        puts ("Input string: ");
        gets (str);

        if (str_str(str, "exit"))
            break;

        char *token = str_tok (str, " ,;");
        double sum = 0;
        while (token)
        {
            sum += str_to_d(token, NULL);
            token = str_tok (NULL, " ,;");
        }
        printf ("Sum: %.4f\n", sum);
    }
    return 0;
}
