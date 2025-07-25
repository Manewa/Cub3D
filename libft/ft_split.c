/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:28:36 by namalier          #+#    #+#             */
/*   Updated: 2025/05/20 17:19:26 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_is_pouet(char pouet, char *poueteuh)
{
	int	poueti;

	poueti = 0;
	while (poueteuh[poueti])
	{
		if (pouet == poueteuh[poueti])
			return (0);
		poueti++;
	}
	return (1);
}

int	ft_countsep(char *str, char *charset)
{
	int	i;
	int	count;
	int	poueta;
	int	pouetuiv;

	count = 0;
	i = 0;
	pouetuiv = 0;
	while (str[i])
	{
		poueta = ft_is_pouet(str[i], charset);
		if (poueta && !pouetuiv)
			count++;
		i++;
		pouetuiv = poueta;
	}
	return (count);
}

void	ft_strcpy(char *str, int j, int old_j, char *tab)
{
	int	i;

	i = 0;
	while (old_j < j)
	{	
		tab[i] = str[old_j];
		i++;
		old_j++;
	}
	tab[i] = '\0';
}

char	**ft_split(char *str, char *charset)
{
	int		old_j;
	int		j;
	int		i;
	char	**tab;

	i = 0;
	j = 0;
	tab = malloc((ft_countsep(str, charset) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	while (i < ft_countsep(str, charset))
	{
		while (str[j] && !ft_is_pouet(str[j], charset))
			j++;
		old_j = j;
		while (str[j] && ft_is_pouet(str[j], charset))
			j++;
		tab[i] = malloc((j - old_j + 1) * sizeof (char));
		if (!tab[i])
			return (NULL);
		ft_strcpy(str, j, old_j, tab[i++]);
	}
	tab[i] = 0;
	return (tab);
}
