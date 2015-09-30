#include <assert.h>
#include <stdlib.h>
#include "strings.h"

str_size str_len (const char *string)
{
    assert (string);
    str_size ans = 0;
    while (*string++)
        ans++;
    return ans;
}

char *str_cat (char *destination, const char *source)
{
    assert (destination);
    assert (source);

    char *destination_end = destination + str_len (destination);
    do
    {
        *destination_end++ = *source;
    }
    while (*source++);

    return destination;
}

char *str_chr (const char *str, char c)
{
    while (*str)
    {
        if (*str == c)
            return str;
        str++;
    }

    return 0;
}

char *str_str (const char *string, const char *sample)
{
    assert (string);
    assert (sample);

    str_size string_len = str_len (string);
    str_size sample_len = str_len (sample);
    assert (string_len);
    assert (string_len);
    int *prefix = calloc (sample_len, sizeof (int));
    int i, j;

    //calculate prefix function
    prefix[0] = 0;
    for (i = 1; i < sample_len; i++)
    {
        j = prefix[i-1];
        while (j > 0 && sample[i] != sample[j])
            j = prefix[j-1];
        if (sample[i] == sample[j])
            j++;
        prefix[i] = j;
    }
    //finding
    j = 0;
    for (int i = 0; i < string_len; i++)
    {
        while (j > 0 && sample[j] != string[i])
            j = prefix[j-1];
        if (sample[j] == string[i])
            j++;
        if (j == sample_len)
        {
            free (prefix);
            return (char*)string + i - j + 1;
        }
    }
    free (prefix);
    return 0;
}

unsigned long int str_to_ul (const char *str, char **str_end, int base)
{
    assert (2 <= base && base <= 36);
    assert (str);

    const char *cur_symb = str;
    unsigned long int ans = 0;

    //check currect symbol on membership to number base
    while (('0' <= *cur_symb && *cur_symb <= '0' + (base  <10 ? base : 9)) ||
           ('A' <= *cur_symb && *cur_symb <= 'A' + base - 10))
    {
        int digit;
        if (*cur_symb >= '0' && *cur_symb <= '9')
            digit = *cur_symb - '0';
        else
            digit = *cur_symb- 'A' + 10;
        ans = ans * base + digit;
        cur_symb++;
    }
    if (str_end)
    {
        assert (*str_end);
        *str_end = (char*)cur_symb;
    }
    return ans;
}

double str_to_d (const char *str, char **str_end)
{
    double ans = 0;
    double base = 1.0;
    char is_minus = 0;
    char is_fractional = 0;
    assert (str);
    while (str_chr("0123456789-.", *str))
    {
        if (*str == '-')
        {
            if (is_minus)
                break;
            is_minus = 1;
        }
        else if (*str == '.')
        {
            if (is_fractional)
                break;
            is_fractional = 1;
        }
        else
        {
            if (is_fractional)
            {
                base /= 10;
                ans += base * (*str - '0');
            }
            else
                ans = ans * 10 + (*str-'0');
        }
        str++;
    }
    if (str_end)
    {
        assert (*str_end);
        *str_end = (char*)str;
    }
    return is_minus ? -ans : ans;
}

char *str_tok (char *str, const char *delimiters)
{
    static char *begin = 0;
    if (str)
        begin = str;

    assert (begin);

    //skip all delimiters in the begin of the string
    while (str_chr (delimiters, *begin))
        begin++;
    //finding end of token
    char *end = begin;
    while (*end && !str_chr(delimiters, *end))
        end++;
    char *ans = begin;
    if (*end)
    {
        *end = '\0';
        begin = end+1;
    }
    else
        begin = end; //end of the string - return empty string in the next function call
    return *ans ? ans : 0;
}
