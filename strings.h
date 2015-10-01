#ifndef STRINGS_H_INCLUDED
#define STRINGS_H_INCLUDED

/*!
 * @file strings.h
 * @brief module that contains different functions to work with strings
 * @author Sergei Kachkov
 */

typedef unsigned int str_size;

/*!
 * Calculates length of zero-end string
 * @param str pointer to string
 * @return size of string in charcacters
 */
str_size str_len (const char *str);

/*!
 * Adds string 'source' in the end of string 'destination'
 * @warning Unsafe if size of destination buffer is less than size of sum of strings
 * @param destination pointer to string-accumulator
 * @param str pointer to string-addition
 * @return pointer to string-accumulator
 */
char *str_cat (char *destination, const char *source);

/*!
 * Finds appearence of character in string
 * @param str pointer to initial string
 * @param c required symbol
 * @return pointer to the first appearence of character in string; if there is no such a character, returns NULL
 */
char *str_chr (const char *str, char c);

/*!
 * Finds appearance of string in other string using Knuth–Morris–Pratt algorithm
 * @param str pointer to initial string
 * @param sample pointer to string for finding
 * @return pointer to the first appearence of sample in string; if there is no such a sample, returns NULL
 */
char *str_str (const char *str, const char *sample);

/*!
 * Converts string to unsigned long int in defined base
 * @param str pointer to convertible string; digits more than 9 must be writen with capital letters (EXAMPLE: AF2B)
 * @param str_end pointer to the first symbol that is not in numeric base; can be set at NULL
 * @param base numeric base: 2<=base<=36
 * @return number before the first incorrect symbol; if the first symbol is incorrect, returns 0
 */
unsigned long int str_to_ul (const char *str, char **str_end, int base);

/*!
 * Converts string to double;
 * correct string includes digits from 0 to 9 and optional one minus before the number  and one point
 * @param str pointer to convertible string;
 * @param str_end pointer to the first incorrect symbol; can be set at NULL
 * @return number before the first incorrect symbol; if the first symbol is incorrect, returns 0
 */
double str_to_d (const char *str, char **str_end);

/*!
 * Split string on tokens (warning: string changes after function work)
 * @param str pointer to initial string; if it is NULL, function work with last string from the last position
 * @param delimiters poiner to string; symbols in that string interpret as delimiters
 * @return pointer to the current token
 */
char *str_tok (char *str, const char *delimiters);

#endif // STRINGS_H_INCLUDED
