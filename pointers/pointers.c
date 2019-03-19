#include <stdio.h>
#include <string.h>

/*
    Given an empty (NULL) character pointer x and a character pointer y,
    copies the character contents of y over to x. Pointer arithmetic
    is necessary here. Also, make sure x points to a null terminator at its 
    end to terminate it properly. 
*/
void string_copy(char *x, char *y)
{
    char *final = x;

    // while the Y pointer hasn't terminated
    while (*y != '\0')
    {
        *x = *y; // copy the y pointer over to the x pointer
        // increment
        x++;
        y++;
    }
    // terminate x
    *x = '\0';
}

/*
    Searches the input string `str` for the first instance of the 
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, int c)
{
    while (*str != '\0')
    {
        if (*str == c)
        {
            return str;
        }
        str++;
    }
    return NULL;
}

/*
    Searches the input string `haystack` for the first instance of
    the string `needle`. This function returns a pointer that points
    to the first instance of the string `needle` in the input
    string `haystack`. 

    Do not use the `strstr` function from the standard library.
*/
char *find_string(char *haystack, char *needle)
{
    char *temp;
    char *answer;
    while (*haystack != '\0')
    {
        temp = needle;
        answer = haystack;
        if (*temp == *haystack)
        {
            while (*temp == *haystack)
            {
                if (*(temp + 1) == '\0')
                {
                    return answer;
                }
                temp++;
                haystack++;
            }
            haystack--;
        }
        haystack++;
    }
    return NULL;
}

#ifndef TESTING
int main(void)
{
    char *found_char = find_char(hello, 'e');
    char *found_string = find_string(world, "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif
