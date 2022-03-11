/*
** EPITECH PROJECT, 2019
** my_header
** File description:
** my_header
*/
#ifndef _MY_H_
#define _MY_H_

#include <stdarg.h>

int my_free(void *);

char *cut_str(char *str, char cut);

int is_alphanum(char *str);

char *my_strndup(char *str, int n);

char *my_itoa(int);

int my_put_nbr_long(long long int);

int my_put_long_base(unsigned long long int, char const *);

int skip_flag(int i, char *str);

void check_flag(char *, va_list list, int, int);

void check_modifiers(char *, va_list, int);

int my_char_isnum(char c);

int is_flag(char *, int);

int my_printf(char *str, ...);

int my_putnbr_base(int nb, char const *base);

int my_getnbr_base(char const *, char const *base);

int my_putchar(char);

int my_putstr(char *);

int *concat_params(int, char**);

int my_compute_power_rec(int, int);

int my_compute_power_it(int, int);

int my_find_prime_sup(int);

int my_getnbr(char const*);

int my_isneg(int);

int my_is_prime(int);

int my_put_nbr(int);

char *my_revstr(char *);

int my_showmem(char const*, int);

int my_showstr(char const*);

void my_sort_int_array(int*, int);

char *my_strcapitalize(char*);

char *my_strcat(char*, char*);

int my_strcmp(char const*, char const*);

char *my_strcpy(char*, char const*);

char *my_strdup(char const*);

int my_str_isalpha(char const*);

int my_str_islower(char const*);

int my_str_isnum(char const*);

int my_str_isprintable(char const*);

int my_str_isupper(char const*);

int my_strlen(char const*);

char my_strlowcase(char*);

char *my_strncat(char*, char*, int);

int my_strncmp(char *, char *, int);

char *my_strncpy(char*, char const*, int);

char *my_strstr(char*, char *);

char **my_str_to_word_array(char *str);

char my_strupcase(char*);

void my_swap(int*, int*);

int argv_length(int, char**);

int my_compute_square_root(int);

int check_prime2(int, int, int);

int my_is_prime2(int);

int check_prime(int, int, int);

int check_new_word(char*, int);

char uppercase(char*, int);

char *check_return(char*, char const*);

int check_same(char, char);

int delete_rest(char*, int);

int allocate_size(char *const*);

int check_alpha_num(char);

#endif
