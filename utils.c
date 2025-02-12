/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:32:10 by palexand          #+#    #+#             */
/*   Updated: 2025/02/12 20:49:57 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


int	set_commands(t_pipex **pipex, char **av, char **path, int size)
{
	char *magic;
	char	*tmp2;	
	int		i;
	int		j;
	int		n;

	i = 2;
	j = -1;
	n = 0;

	while(path[++j] && i + n < size - 1)
	{
		ft_printf("Error checks are needed here\n");
		ft_printf("When first command is invalid, we have memory leaks\n");
		ft_printf("Check valgrind\n");
		tmp2 = ft_substr(av[i + n], 0, (ft_strchrlen(av[i + n], ' ')));
		(*pipex)->cmd[n] = ft_strdup(av[i + n]);
		magic = ft_strjoin(path[j], "/");
		(*pipex)->path[n] = ft_strjoin(magic, tmp2);
		free(magic);
		if (path[j + 1] == NULL && n == 0 && access((*pipex)->path[n], F_OK) == -1 && ++n)
			j = -1;
		if (access((*pipex)->path[n], F_OK) != -1 
			&& open((*pipex)->path[n], O_DIRECTORY) == -1
			&& ++n)
			j = -1;
		free_loop(tmp2, &(*pipex)->cmd[n], &(*pipex)->path[n], j);
	}
	free_path(path);
	if (!(*pipex)->path[i - 1] || access((*pipex)->path[i - 1], F_OK == -1))
		return(0);
	return (i == n);
}
void	free_path(char **path)
{
	int	j;

	j = 0;
	while(path[j])
		free(path[j++]);
	free(path);
}

void	free_loop(char *s, char **cmd, char **path, int j)
{
	if (s)
		free(s);
	if (j != -1 && *path)
	{
		free(*path);
		*path = NULL;
	}
	if (j != -1 && *cmd)
	{
		free(*cmd);
		*cmd = NULL;
	}
}

int	ft_strchrlen(char *str, char c)
{
	int	i;

	i = 0;
	while(str[i] && str[i] != c)
		i++;
	return(i);
}
