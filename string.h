#pragma once

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct {
    char* buffer;
    size_t bufferSize;
    size_t size;
} String;

void dump_string(String* str);
void print_error(const char* func, const char* msg);
String* new_string();
void free_string(String* str);
size_t string_size(String* str);
char* c_string(String* str);
char get_index(String* str, size_t index);
void set_index(String* str, size_t index, char c);
void string_set(String* str, const char* src);
String* new_set_string(const char* str);
String* new_copy_string(String* str);
void print_string(String* str);
String* to_lowercase(String* str);
String* to_uppercase(String* str);
String* lstrip(String* str);
String* rstrip(String* str);
void string_copy_c(String* dest, char* src);
void string_copy(String* dest, String* src);
void string_n_copy_c(String* dest, char* src, size_t num);
void string_n_copy(String* dest, String* src, size_t num);
void string_append_c(String* dest, char* src);
void string_append(String* dest, String* src);
void string_n_append_c(String* dest, char* src, size_t num);
void string_n_append(String* dest, String* src, size_t num);
int string_compare_c(String* str1, char* str);
int string_compare(String* str1, String* str2);
int string_equal_c(String* str1, char* str2);
int string_equal(String* str1, String* str2);
size_t find_char(String* str, char c);
String** tokenize_c(String* str, const char* delimiters, unsigned int* c);
String** tokenize(String* str, String* delimiters, unsigned int* c);
size_t find_substring_c(String* str1, char* str2);
size_t find_substring(String* str1, String* str2);
String* get_substring(String* str, size_t location, size_t length);


// ##########################################################
//                  Internal Use Functions
// ##########################################################

void dump_string(String* str) {
    if(str == NULL) 
        return;
    printf("buffer: %s\n", str->buffer);
    printf("buffer size: %lu\n", str->bufferSize);
    printf("string size: %lu\n", str->size);
}

void print_error(const char* func, const char* msg) {
    fprintf(stderr, "Error in function %s: %s\n", func, msg);
    exit(EXIT_FAILURE);
}

// ##########################################################
//                     Utility Functions
// ##########################################################

/*
 * @brief    Allocates the memory needed for the String, and initializes the internal buffer and the size variables
 * @param    none
 * @returns  A pointer to the newly created String
 */
String* new_string() {
    String* str;
    str = (String*)malloc(sizeof(String));
    str->buffer = (char*)malloc(1*sizeof(char));
    str->buffer[0] = '\0';
    str->bufferSize = 1;
    str->size = 0;
    return str;
}

/*
 * @brief    Allocates the memory needed for the String, and initializes the internal buffer and the size variables. 
             Sets the newly allocated String's buffer to str
 * @param    none
 * @returns  A pointer to the newly created String
 */
String* new_set_string(const char* str) {
    String* newstr = new_string();
    string_set(newstr, str);
    return newstr;
}

/*
 * @brief    Allocates the memory needed for the String, and initializes the internal buffer and the size variables. 
             Sets the newly allocated String's buffer to a copy of str's buffer
 * @param    none
 * @returns  A pointer to the newly created String
 */
String* new_copy_string(String* str) {
    if(str == NULL)
        print_error("new_copy_string", "argument str cannot be NULL");
    String* newstr = (String*)malloc(sizeof(String));
    newstr->size = str->size;
    newstr->bufferSize = str->bufferSize;
    newstr->buffer = (char*)malloc(sizeof(char)*newstr->bufferSize);
    strcpy(newstr->buffer, str->buffer);
    return newstr;
}

/*
 * @brief    Frees the memory allocated to str. 
             Exits with code 1 if str is NULL
 * @param    str - The String being freed
 * @returns  none
 */
void free_string(String* str) {
    if(str == NULL) 
        print_error("free_string", "argument str cannot be NULL");
    free(str->buffer);
    free(str);
}

/*
 * @brief    Returns the size of the string. 
             Exits with code 1 if str is NULL
 * @param    str - The String for which the size is queried
 * @returns  str->size
 */
size_t string_size(String* str) {
    if(str == NULL) 
        print_error("string_size", "argument str cannot be NULL");
    return str->size;
}

/*
 * @brief    Returns the internal buffer as a c-style string. 
             Exits with code 1 if str is NULL
 * @param    str - The String for which the buffer is requested
 * @returns  str->buffer
 */
char* c_string(String* str) {
    if(str == NULL) 
        print_error("c_string", "argument str cannot be NULL");
    return str->buffer;
}

/*
 * @brief    Returns the character at index within the internal buffer of str. 
             Exits with code 1 if str is NULL. 
             Exits with code 1 if index >= str->size
 * @param    str - The String for which the character at index is requested
 * @param    index - a location within the buffer of str
 * @returns  the character at index c within the buffer
 */
char get_index(String* str, size_t index) {
    if(str == NULL) 
        print_error("get_index", "argument str cannot be NULL");
    if(index >= str->size)
        print_error("get_index", "argument index must be in the range [0, str->size)");
    return str->buffer[index];
}

/*
 * @brief    sets the character at index within the internal buffer of str to c. 
             Exits with code 1 if str is NULL. 
             Exits with code 1 if index >= str->size
 * @param    str - The String for which the character at index is set
 * @param    index - a location within the buffer of str
 * @returns  none
 */
void set_index(String* str, size_t index, char c) {
    if(str == NULL) 
        print_error("set_index", "argument str cannot be NULL");
    if(index >= str->size)
        print_error("set_index", "argument index must be in the range [0, str->size)");
    str->buffer[index] = c;
}

/*
 * @brief    Sets the internal buffer of the string to a specified value, overwriting anything that may have been there already. 
             Exits with code 1 if str is NULL
 * @param    str - the String that has its buffer set
 * @param    src - the source  c-style string. The buffer of str is changed to match src exactly.
 * @returns  none
 */
void string_set(String* str, const char* src) {
    if(str == NULL) 
        print_error("string_set", "argument str cannot be NULL");
    size_t s = strlen(src);
    if(s >= str->bufferSize) {
        str->bufferSize = s*sizeof(char)+1;
        str->buffer = (char*)realloc(str->buffer, str->bufferSize);
    }
    memset(str->buffer, '\0', str->bufferSize);
    strcpy(str->buffer, src);
    str->size = s;
}

/*
 * @brief    Clears the contents of the string. The size of the allocated buffer remains the same
 * @param    str - the String that has its buffer cleared
 * @returns  none
 */
void string_clear(String* str) {
    if(str == NULL)
        print_error("string_clear", "argument str cannot be NULL");
    memset(str->buffer, '\0', str->bufferSize);
    str-> size = 0;
}

/*
 * @brief    Prints the buffer of str to stdout 
 * @param    str - the String that has its buffer printed
 * @returns  none
 */
void print_string(String* str) {
    if(str == NULL) 
        return;
    printf("%s\n", str->buffer);
}

/*
 * @brief    Makes the string entirely lowercase
 * @param    str - the String that is converted to lowercase
 * @returns  the paramater str
 */
String* to_lowercase(String* str) {
    if(str == NULL)
        print_error("to_lowercase", "argument str cannot be NULL");
    for(size_t i=0; i<str->size; i++) {
        char c = get_index(str, i);
        if(c >= 65 && c <= 90)
            set_index(str, i, (c+32));
    }
    return str;
}

/*
 * @brief    Makes the string entirely uppercase
 * @param    str - the String that is converted to uppercase
 * @returns  the parameter str
 */
String* to_uppercase(String* str) {
    if(str == NULL)
        print_error("to_uppercase", "argument str cannot be NULL");
    for(size_t i=0; i<str->size; i++) {
        char c = get_index(str, i);
        if(c >= 97 && c <= 122)
            set_index(str, i, (c-32));
    }
    return str;
}

/*
 * @brief    Removes all whitespace characters from the start of the string, up to the first non-whitespace character
 * @param    str - the String that has whitespace characters removed
 * @returns  the parameter str
 */
String* lstrip(String* str) {
    if(str == NULL)
        print_error("lstrip", "argument str cannot be NULL");
    size_t s = str->size;
    if(s == 0)
        return str;
    size_t first = 0;
    for(size_t i=0; i<s; i++) {
        char c = get_index(str, i);
        if(c != ' ' && c != '\t' && c != '\r' && c != '\n' && c != '\x0b'){
            first = i;
            break;
        }
        ++first;
    }
    if(first == s) {
        string_set(str, "");
        return str;
    }
    String* temp = get_substring(str, first, s-first);
    string_copy(str, temp);
    free_string(temp);
    return str;
}

/*
 * @brief    Removes all whitespace characters from the end of the string, up to the first non-whitespace character
 * @param    str - the String that has whitespace characters removed
 * @returns  the parameter str
 */
String* rstrip(String* str) {
    if(str == NULL)
        print_error("lstrip", "argument str cannot be NULL");
    size_t s = str->size;
    if(s == 0)
        return str;
    size_t first = s-1;
    for(size_t i=0; i<s; i++) {
        char c = get_index(str, s-i-1);
        if(c != ' ' && c != '\t' && c != '\r' && c != '\n' && c != '\x0b'){
            first = s-i-1;
            break;
        }
        --first;
    }
    if(first == 0) {
        string_set(str, "");
        return str;
    }
    String* temp = get_substring(str, 0, first+1);
    string_copy(str, temp);
    free_string(temp);
    return str;
}

/*
 * @brief    Removes all whitespace characters from the start and end of the String
 * @param    str - the String that has whitespace characters removed
 * @returns  the parameter str
 */
String* strip(String* str) {
    return rstrip(lstrip(str));
}

// ##########################################################
//                     Copying Functions
// ##########################################################

/*
 * @brief    Copies src into the buffer of dest, overwriting anything that may have been in the buffer previously. 
             Exits with code 1 if either dest or src are NULL
 * @param    dest - the destination String that has its buffer overwritten
 * @param    src - the source c-style string. The buffer of dest is changed to match src exactly.
 * @returns  none
 */
void string_copy_c(String* dest, char* src) {
    if(dest == NULL) 
        print_error("string_copy_c", "argument dest cannot be NULL");
    if(src == NULL) 
        print_error("string_copy_c", "argument src cannot be NULL");
    size_t s = strlen(src);
    if(s >= dest->bufferSize) {
        dest->bufferSize = s*sizeof(char)+1;
        dest->buffer = (char*)realloc(dest->buffer, dest->bufferSize);
    }

    memset(dest->buffer, '\0', dest->bufferSize);
    strcpy(dest->buffer, src);
    dest->size = s;
}

/*
 * @brief    Copies the buffer of src into dest, overwriting anything that may have been in the buffer of dest. 
             Exits with code 1 if either dest or src are NULL
 * @param    dest - the destination String that has its buffer overwritten
 * @param    src - the source String. The buffer of dest is changed to match src exactly.
 * @returns  none
 */
void string_copy(String* dest, String* src) {
    if(dest == NULL) 
        print_error("string_copy", "argument dest cannot be NULL");
    if(src == NULL) 
        print_error("string_copy", "argument src cannot be NULL");
    string_copy_c(dest, src->buffer);
}

/*
 * @brief    Copies num characters from src into the buffer of dest, overwriting anything that may have been in the buffer previously. 
             Exits with code 1 if either dest or src are NULL. 
             Exits with code 1 if num is longer than strlen(src)
 * @param    dest - the destination String that has its buffer overwritten
 * @param    src - the source c-style string. The buffer of dest is changed to match num chars from src exactly
 * @returns  none
 */
void string_n_copy_c(String* dest, char* src, size_t num) {
    size_t s = strlen(src);
    if(dest == NULL) 
        print_error("string_n_copy_c", "argument dest cannot be NULL");
    if(src == NULL) 
        print_error("string_n_copy_c", "argument src cannot be NULL");
    if(num > s)
        print_error("string_n_copy_c", "num cannot be greater than strlen(src)");

    if(num >= dest->bufferSize) {
        dest->bufferSize = num*sizeof(char)+1;
        dest->buffer = (char*)realloc(dest->buffer, dest->bufferSize);
    }
    memset(dest->buffer, '\0', dest->bufferSize);
    strncpy(dest->buffer, src, num);
    dest->size = num;
}

/*
 * @brief    Copies num characters from the buffer of src into dest, overwriting anything that may have been in the buffer of dest. 
             Exits with code 1 if either dest or src are NULL. 
             Exits with code 1 if num is longer than src->size
 * @param    dest - the destination String that has its buffer overwritten
 * @param    src - the source String. The buffer of dest is changed to match num chars from the buffer of src exactly
 * @returns  none
 */
void string_n_copy(String* dest, String* src, size_t num) {
    if(dest == NULL) 
        print_error("string_n_copy", "argument dest cannot be NULL");
    if(src == NULL) 
        print_error("string_n_copy", "argument src cannot be NULL");
    if(num > src->size)
        print_error("string_n_copy", "num cannot be greater than strlen(src)");
    string_n_copy_c(dest, src->buffer, num);
}

// ##########################################################
//                  Concatenation Functions
// ##########################################################

/*
 * @brief    Appends the buffer from src to the buffer of dest. 
             Exits with code 1 if either dest or src are NULL
 * @param    dest - the destination String that has its buffer appended to
 * @param    src - the source c-style string. src is added to the end of the buffer of dest.
 * @returns  none
 */
void string_append_c(String* dest, char* src) {
    size_t s = strlen(src);
    if(dest == NULL) 
        print_error("string_append_c", "argument dest cannot be NULL");
    if(src == NULL) 
        print_error("string_append_c", "argument src cannot be NULL");
    
    if(dest->size+s >= dest->bufferSize) {
        dest->bufferSize = (dest->size+s)*sizeof(char)+1;
        dest->buffer = (char*)realloc(dest->buffer, dest->bufferSize);
    }
    strcat(dest->buffer, src);
    dest->size += s;
}

/*
 * @brief    Appends the buffer from the buffer of src to the buffer of dest. 
             Exits with code 1 if either dest or src are NULL
 * @param    dest - the destination String that has its buffer appended to
 * @param    src - the source String. the buffer of src is added to the end of the buffer of dest.
 * @returns  none
 */
void string_append(String* dest, String* src) {
    if(dest == NULL) 
        print_error("string_append", "argument dest cannot be NULL");
    if(src == NULL) 
        print_error("string_append", "argument src cannot be NULL");
    string_append_c(dest, src->buffer);
}

/*
 * @brief    Appends the first num characters from src to the buffer of dest.  
             Exits with code 1 if either dest or src are NULL. 
             Exits with code 1 if num is greater than strlen(src)
 * @param    dest - the destination String that has its buffer appended
 * @param    src - the source c-style string. The buffer of dest is changed to match num chars from src exactly
 * @returns  none
 */
void string_n_append_c(String* dest, char* src, size_t num) {
    size_t s = strlen(src);
    if(dest == NULL) 
        print_error("string_n_append_c", "argument dest cannot be NULL");
    if(src == NULL) 
        print_error("string_n_append_c", "argument src cannot be NULL");
    if(num > s)
        print_error("tring_n_append_c", "num cannot be greater than strlen(src)");

    if((dest->size+num) >= dest->bufferSize) {
        dest->bufferSize = (dest->size+num)*sizeof(char)+1;
        dest->buffer = (char*)realloc(dest->buffer, dest->bufferSize);
    }
    strncat(dest->buffer, src, num);
    dest->size += s;
}

/*
 * @brief    Appends the first num characters from the buffer of src to the buffer of dest.  
             Exits with code 1 if either dest or src are NULL. 
             Exits with code 1 if num is greater than src->size
 * @param    dest - the destination String that has its buffer appended
 * @param    src - the source c-style string. The buffer of dest is changed to match num chars from src exactly
 * @returns  none
 */
void string_n_append(String* dest, String* src, size_t num) {
    if(dest == NULL) 
        print_error("string_n_append", "argument dest cannot be NULL");
    if(src == NULL) 
        print_error("string_n_append", "argument src cannot be NULL");
    if(num > src->size)
        print_error("tring_n_append", "num cannot be greater than strlen(src)");
    string_n_append_c(dest, src->buffer, num);
}

// ##########################################################
//                  Comparison Functions
// ##########################################################

/*
 * @brief    Compares str1 to str2.  
             Exits with code 1 if either str1 or str2 are NULL. 
 * @param    str1 - The first String to be compared
 * @param    str2 - the second c-style string to be compared
 * @returns  an integer indicating the relationship between the strings. 
 *           <0 indicates the first character that does not match has a lower value in ptr1 than in ptr2. 
 *            0 indicates the contents of both strings are equal. 
 *           >0 indicates the first character that does not match has a greater value in ptr1 than in ptr2. 
 */
int string_compare_c (String* str1, char* str2) {
    if(str1 == NULL)
        print_error("string_compare_c", "argument str1 cannot be NULL");
    if(str2 == NULL)
        print_error("string_compare_c", "argument str2 cannot be NULL");
    return strcmp(str1->buffer, str2);
}

/*
 * @brief    Compares str1 to str2.  
             Exits with code 1 if either str1 or str2 are NULL. 
 * @param    str1 - The first String to be compared
 * @param    str2 - the second String to be compared
 * @returns  an integer indicating the relationship between the strings. 
 *           <0 indicates the first character that does not match has a lower value in ptr1 than in ptr2. 
 *            0 indicates the contents of both strings are equal. 
 *           >0 indicates the first character that does not match has a greater value in ptr1 than in ptr2. 
 */
int string_compare (String* str1, String* str2) {
    if(str1 == NULL)
        print_error("string_compare", "argument str1 cannot be NULL");
    if(str2 == NULL)
        print_error("string_compare", "argument str2 cannot be NULL");
    return strcmp(str1->buffer, str2->buffer);
}

/*
 * @brief    Checks if str1 equals str2.  
             Exits with code 1 if either str1 or str2 are NULL. 
 * @param    str1 - The first String to be compared
 * @param    str2 - the second c-style string to be compared
 * @returns  1 if the strings are equal, 0 otherwise.
 */
int string_equal_c (String* str1, char* str2) {
    if(str1 == NULL)
        print_error("string_compare", "argument str1 cannot be NULL");
    if(str2 == NULL)
        print_error("string_compare", "argument str2 cannot be NULL");
    return !strcmp(str1->buffer, str2);
}

/*
 * @brief    Checks if str1 equals str2.  
             Exits with code 1 if either str1 or str2 are NULL. 
 * @param    str1 - The first String to be compared
 * @param    str2 - the second String to be compared
 * @returns  1 if the strings are equal, 0 otherwise.
 */
int string_equal (String* str1, String* str2) {
    if(str1 == NULL)
        print_error("string_compare", "argument str1 cannot be NULL");
    if(str2 == NULL)
        print_error("string_compare", "argument str2 cannot be NULL");
    return !strcmp(str1->buffer, str2->buffer);
}

// ##########################################################
//                  Searching Functions
// ##########################################################

/*
 * @brief    Finds the first occurence of c in str. 
             Exits with code 1 if str is NULL
 * @param    str - the String in which the character is seearched for
 * @param    c - the character to be located
 * @returns  The index of the first occurence of c in str, or -1 if c is not found
 */
size_t find_char(String* str, char c) {
    if(str == NULL) 
        print_error("find_char", "argument str cannot be NULL");
    char* pch = strchr(str->buffer, c);
    if(pch == NULL)
        return -1;
    return pch-str->buffer+1;
}

/*
 * @brief    Splits str into tokens, along the characters specified in delimiters. 
             It is the caller's responsibility to free the returned strings appropriately. 
             Exits with code 1 if either str or delimiters is NULL
 * @param    str - String to be tokenized
 * @param    delimiters - c-style string containing all delimiters
 * @param    c - the number of tokens found
 * @returns  If a token is found, a pointer to the beginning of the token, otherwise NULL
 */
String** tokenize_c(String* str, const char* delimiters, unsigned int* c) {
    if(str == NULL) 
        print_error("tokenize_c", "argument str cannot be NULL");
    if(delimiters == NULL) 
        print_error("tokenize_c", "argument delimiters cannot be NULL");

    char* temp1 = (char*)malloc(str->size*sizeof(char)+1);
    char* temp2 = (char*)malloc(str->size*sizeof(char)+1);
    strcpy(temp1, str->buffer);
    strcpy(temp2, str->buffer);

    int count = 0;
    char* pch = strtok(temp1, delimiters);
    if(pch == NULL) {
        *c = 0;
        return NULL;
    }
    while(pch != NULL) {
        count += 1;
        pch = strtok(NULL, delimiters);
    }

    String** tokens = (String**)malloc(count*sizeof(String*));
    pch = strtok(temp2, delimiters);
    for(int i=0; i<count; i++) {
        tokens[i] = new_string();
        string_copy_c(tokens[i], pch);
        pch = strtok(NULL, delimiters);
    }

    free(temp1);
    free(temp2);
    *c = count;
    return tokens;
}

/*
 * @brief    Splits str into tokens, along the characters specified in delimiters. 
             It is the user's responsibility to free the returned strings appropriately. 
             Exits with code 1 if either str or delimiters is NULL
 * @param    str - String to be tokenized
 * @param    delimiters - String containing all delimiters
 * @param    c - the number of tokens found
 * @returns  If a token is found, a pointer to the beginning of the token, otherwise NULL
 */
String** tokenize(String* str, String* delimiters, unsigned int* c) {
    if(str == NULL)
        print_error("tokenize", "argument str cannot be NULL");
    if(delimiters == NULL)
        print_error("tokenize", "argument delimiters cannot be NULL");
    return tokenize_c(str, delimiters->buffer, c);
}

/*
 * @brief    Finds the first occurence of str2 in str1. 
             Exits with code 1 if either str1 or str2 are NULL
 * @param    str1 - the String in which the substring is seearched for
 * @param    str2 - the c-style string to be located
 * @returns  The index of the first occurence of str2 in str1, or -1 if str2 is not found
 */
size_t find_substring_c(String* str1, char* str2) {
    if(str1 == NULL)
        print_error("find_substring_c", "argument str1 cannot be NULL");
    if(str2 == NULL)
        print_error("find_substring_c", "argument str2 cannot be NULL");
    char* pch = strstr(str1->buffer, str2);
    if(pch == NULL)
        return -1;
    return pch-str1->buffer+1;
}

/*
 * @brief    Finds the first occurence of str2 in str1. 
             Exits with code 1 if either str1 or str2 are NULL
 * @param    str1 - the String in which the substring is searched for
 * @param    str2 - the String to be located
 * @returns  The index of the first occurence of str2 in str1, or -1 if str2 is not found
 */
size_t find_substring(String* str1, String* str2) {
    if(str1 == NULL)
        print_error("find_substring", "argument str1 cannot be NULL");
    if(str2 == NULL)
        print_error("find_substring", "argument str2 cannot be NULL");
    return find_substring_c(str1, str2->buffer);
}

/*
 * @brief    Gets the substring from str, as specified by location and length. It is the caller's responsibility to free the returned string appropriately. 
             Exits with code 1 if str is NULL. 
             Exits with code 1 if location is out of bounds or location+length is out of bounds
 * @param    str - the String in which the substring is searched for
 * @param    location - the start index of the substring within str
 * @param    length - the size of the substring
 * @returns  A pointer to a new String, containing the requested substring.
 */
String* get_substring(String* str, size_t location, size_t length) {
    if(str == NULL)
        print_error("get_substring", "argument str cannot be NULL");
    if(location >= str->size)
        print_error("get_substring", "argument location must be within the range [0, str->size)");
    if(location+length > str->size)
        print_error("get_substring", "sum of arguments location and length cannot exceed str->size");

    char substr[length+1];
    for(size_t i=0; i < length; i++) {
        substr[i] = str->buffer[i+location];
    }
    substr[length] = '\0';
    return new_set_string(substr);
}

