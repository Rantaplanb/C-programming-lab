/*
    Loukas Mertzanis 4457
    HY255 - Ex02
    mystring.h
*/
#ifndef _MYSTRING_H_ /*Prevents double declaration*/
#define _MYSTRING_H_

#include <stddef.h>

/* Returns the length of string pointed to by src.
Checked runtime error: If src is NULL*/
size_t ms_length(const char* src);

/* Copies the string pointed to by src, to the buffer
pointed to by dest. Then, adds NULL char at the end.
The buffer must have enough allocated space.
Checked runtime errors: If src or dest are NULL*/
char* ms_copy(char* dest, const char* src);

/*Similar to ms_copy, except that AT MOST n bytes
of src are copied to the buffer pointed to by dest.
Checked runtime errors: If src or dest are NULL*/
char* ms_ncopy(char* dest, const char* src, size_t n);

/*Appends string pointed to by src, to the buffer
pointed to by dest, then adds NULL char. The buffer must
have enough space.
Checked runtime errors: If src or dest are NULL*/
char* ms_concat(char* dest, const char* src);

/*Similar to ms_concat, except that at most n bytes
of src are appended.
Checked runtime errors: If src or dest are NULL*/
char* ms_nconcat(char* dest, const char* src, size_t n);

/*Compares the strings str1-str2 char by char. Returns an int
less than, equal to, or greater than 0 if str1 is,
respectively, less, match or greater than str2.
Checked runtime errors: If str1 or str2 are NULL*/
int ms_compare(const char* str1, const char* str2);

/*Similar to ms_compare, except it compares only the
first (at most) n characters of str1 and str2.
Checked runtime errors: If src or dest are NULL*/
int ms_ncompare(const char* str1, const char* str2, size_t n);

/*Finds the first occurrence of string subStr
in string str. Returns pointer to the beginning
of the substring of str, if found, otherwise NULL.*/
char* ms_search( char* str, const char* subStr);

#endif