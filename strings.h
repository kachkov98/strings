#ifndef STRINGS_H_INCLUDED
#define STRINGS_H_INCLUDED

typedef unsigned int str_size;

str_size str_len (const char *str);
char *str_cat (char *destination, const char *source);
char *str_chr (const char *str, char c);
char *str_str (const char *str, const char *sample);
unsigned long int str_to_ul (const char *str, char **str_end, int base);
double str_to_d (const char *str, char **str_end);
char *str_tok (char *str, const char *delimiters);

#endif // STRINGS_H_INCLUDED
