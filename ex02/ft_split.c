#include <stdlib.h>
#include <stdio.h>

int check_sep(char *str, char *charset)
{
    while (*charset)
        if (*str == *charset++)
            return (1);
    return (0);
}

int ft_strlen(char *str, char *charset)
{
    int i;

    i = 0;
    while (str[i] && !check_sep(str + i, charset))
        i++;
    return (i);
}

int count_word(char *str, char *charset)
{
    int n;
    int len_word;

    n = 0;
    while (*str)
    {
        while (*str && check_sep(str, charset))
            str++;
        len_word = ft_strlen(str, charset);
        str += len_word;
        if (len_word)
            n++;
    }
    printf("%d\n", n);
    return (n);
}

char *ft_strcpy(char *str, int len)
{
    char *dest;

    int n;

    if (!(dest = malloc(sizeof(char) * (len + 1))))
        return (NULL);
    n = 0;
    while (n < len)
    {
        dest[n] = str[n];
        n++;
    }
    dest[n] = '\0';
    printf("dest: %s\n", dest);
    return (dest);
}

char **ft_split(char *str, char *charset)
{
    char **split;
    int size_split;
    int word_len;
    int i;

    size_split = count_word(str, charset);
    if (!(split = malloc(sizeof(char *) * (size_split + 1))))
        return (NULL);
    i = 0;
    while (i < size_split)
    {
        while (*str && check_sep(str, charset))
            str++;
        word_len = ft_strlen(str, charset);
        printf("wk%d: %d\n", i, word_len);
        if (!(split[i] = ft_strcpy(str, word_len)))
            return (NULL);
        str += word_len;
        i++;
    }
    split[size_split] = '\0';
    return (split);
}

int main(void)
{
    char str[] = "suis[antoine";
    char charset[] = "\\[";
    char **stack = ft_split(str, charset);

    for (int i = 0; i < 2; i++)
        printf("%s\n", stack[i]);
    free(stack);
}