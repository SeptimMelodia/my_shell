/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stune <stune@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:06:26 by nmisfit           #+#    #+#             */
/*   Updated: 2021/07/07 18:24:28 by stune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shellmini.h"

char	*get_key(char *str)
{
	char	*key;
	int		i;

	key = ft_strdup(str);
	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (str[i] && str[i] == '=')
		key[i] = '\0';
	return (key);
}

char	*get_value(char *str)
{
	char	*value;
	int		i;

	i = 0;
	value = NULL;
	while (str[i] && str[i] != '=')
		i++;
	if (str[i] && str[i] == '=')
		value = str + i + 1;
	return (value);
}

char	*getenvp(char *key, char **envp)
{
	int		i;
	char	*tmp;

	i = -1;
	while (envp[++i])
	{
		tmp = get_key(envp[i]);
		if (!ft_strcmp(key, tmp))
			return (get_value(envp[i]));
		free(tmp);
	}
	return (NULL);
}
