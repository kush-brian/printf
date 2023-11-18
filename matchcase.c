#include "main.h"
/**
 * match_specifier - matches specifier function for each conversion specifier
 * also handles modifiers of short and long
 * @dime: the arguments inventory with most commonly used arguments
 * Return: pointer to the helper function or NULL
 */
void (*matchspec(list_t *dime))(list_t *)
{
        int j, i = 0;
        char check = dime->c1;
        static const char modifiers[] = "hl+#";
        static match_t specifiers_list[] = {
                {'d', print_int}, {'i', print_int}, {'x', print_lowhex}, {'X', print_uphex},
                {'o', p_octal}, {'u', print_ulong_int}, {'c', print_char}, {'s', print_string},
                {'%', print_perct}, {'b', print_binary}, {'p', print_pointer},
                {'r', print_revstr}, {'R', print_rot13}, {'S', print_stringhex}, {'\0', NULL}
        };
        static match_t modifiers_long[] = {
                {'d', print_longint}, {'i', print_longint}, {'x', print_longlow_hex},
                {'X', print_longup_hex}, {'o', print_longoct}, {'u', print_ulong_int}, {'\0', NULL}
        };

        for (j = 0; modifiers[j] != '\0'; j++)
                if (modifiers[j] == dime->c1)
                        dime->flag = 1, check = dime->c2;
        while (TRUE)
        {
                if (specifiers_list[i].spec == '\0')
                {
                        if (dime->flag)
                                dime->i++;
                        return (NULL);
                }
                if (specifiers_list[i].spec == check)
                {
                        if (dime->flag)
                                dime->i += 2;
                        else
                                dime->i++;
                        if (dime->c1 == 'l')
                                return (modifiers_long[i].func);
                        return (specifiers_list[i].func);
                }
                i++;
        }
}
