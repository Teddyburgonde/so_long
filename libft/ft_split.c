/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:25:28 by tebandam          #+#    #+#             */
/*   Updated: 2023/12/23 15:06:09 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

#include <stdlib.h>

static int    strcount(char const *s, char c)
{
    int    i;
    int    count;

    i = 0;
    count = 0;
    while (s[i])
    {
        while (s[i] == c && s[i])
            i++;
        if (s[i] != c && s[i])
            count++;
        while (s[i] != c && s[i])
            i++;
    }
    return (count);
}

char    **ft_split(char const *s, char c)
{
    unsigned int    i;
    int                j;
    size_t            len;
    char            **split;

    i = 0;
    j = 0;
    if (!s)
        return (NULL);
    split = calloc(strcount(s, c) + 1, sizeof(char *));
    if (split == NULL)
        return (NULL);
    while (j < strcount(s, c))
    {
        len = 0;
        while (s[i] == c && s[i])
            i++;
        while (s[i + len] != c && s[i + len])
            len++;
        split[j] = ft_substr(s, i, len);
        j++;
        i += len;
    }
    split[j] = NULL;
    return (split);
}
