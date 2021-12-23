#ifndef _MUL_H_
#define _MUL_H_

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int _putchar(char c);
int main(int argc, char *argv[]);
void easy_exit(void);
int get_length(char *word);
int *easy_convert(int length, char *word);
int *easy_multiply(int *word1, int *word2, int len1, int len2);
int *buffer(int length1, int length2);
int *not_easy_multiply(int *w1, int l1, int n, int *buff, int size);
void check_tens(int *buff, int length);
void print_arr(int *array, int size);
#endif