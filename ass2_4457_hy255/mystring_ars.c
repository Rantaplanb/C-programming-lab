/*
    Loukas Mertzanis 4457
    HY255 - Ex02
    mystring_ars.c
*/

#include "mystring.h"
#include <assert.h>
#include <stddef.h>

/* Returns the length of string pointed to by src.
Checked runtime error: If src is NULL*/
size_t ms_length(const char src[])
{
    size_t length = 0;
    assert(src);
    while(src[length])
        length++;
    return length;
}

/* Copies the string pointed to by src, to the buffer
pointed to by dest. Then, adds NULL char at the end. 
The buffer must have enough allocated space.
Checked runtime errors: If src or dest are NULL*/
char* ms_copy(char dest[], const char src[])
{
    assert(dest);
    assert(src);
    size_t i;
    for(i=0; src[i]; i++)
        dest[i]=src[i];
    dest[i]='\0';
    return dest;
}

/*Similar to ms_copy, except that AT MOST n bytes
of src are copied to the buffer pointed to by dest.
Checked runtime errors: If src or dest are NULL*/
char* ms_ncopy(char dest[], const char src[], size_t n)
{
    size_t i;
    assert(dest);
    assert(src);
	if(n==0) return dest;
    for(i=0; (i<n)&&(src[i]); i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

/*Appends string pointed to by src, to the buffer
pointed to by dest, then adds NULL char. The buffer must
have enough space.
Checked runtime errors: If src or dest are NULL*/
char* ms_concat(char dest[], const char src[])
{
    size_t i,length;
    assert(dest);
    assert(src);
    length = ms_length(dest);
    for(i=0; src[i]; i++)
        dest[length + i] = src[i];
    dest[length + i] = '\0';
    return dest;
}
/*Similar to ms_concat, except that at most n bytes
of src are appended.
Checked runtime errors: If src or dest are NULL*/
char* ms_nconcat(char dest[], const char src[], size_t n)
{
    size_t i, length = ms_length(dest);
    assert(dest);
    assert(src);
	if(n==0) return dest;
    for(i=0; i < n && src[i]; i++)
        dest[length + i] = src[i];
    dest[length + i] = '\0';
    return dest;
}

/*Compares the strings str1-str2 char by char. Returns an int
less than, equal to, or greater than 0 if str1 is,
respectively, less, match or greater than str2.
Checked runtime errors: If str1 or str2 are NULL*/
int ms_compare(const char str1[], const char str2[])
{
    size_t i=0;
    assert(str1);
    assert(str2);
    while(str1[i] || str2[i]){
        if(str1[i]==str2[i])
            i++;
        else
            return (int)(str1[i] - str2[i]);
    }
    return 0;
}

/*Similar to ms_compare, except it compares only the
first (at most) n characters of str1 and str2.
Checked runtime errors: If src or dest are NULL*/
int ms_ncompare(const char str1[], const char str2[], size_t n)
{
    size_t i = 0;
    assert(str1);
    assert(str2);
    while(str1[i] && (str1[i]==str2[i]) && n)
        i++, n--;
    if(n==0)
        return 0;
    else
        return (int)(str1[i] - str2[i]);
}

/*Finds the first occurrence of string subStr
in string str. Returns pointer to the beginning
of the substring of str, if found, otherwise NULL.*/
char* ms_search( char str[], const char subStr[])
{
    size_t i;
    assert(str);
    assert(subStr);
    if(subStr[0]=='\0') return str;
    for(i=0; str[i]; i++)
        if((str[i]==subStr[0]) && !(ms_ncompare(&str[i], subStr, ms_length(subStr))))
            return &str[i];
    return NULL;
}