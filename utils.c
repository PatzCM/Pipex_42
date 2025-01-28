/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:26:22 by palexand          #+#    #+#             */
/*   Updated: 2025/01/28 21:08:57 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(const char *message)
{
	ft_printf("%s\n", message);
	exit(1);
}

char	*get_command_path(char *cmd, char **envp)
{
	int		i = 0;
	char	**path;
	while (!ft_strnstr(envp[i], "PATH=", 5))
				i++;
	path = ft_split(envp[i] + 5, ':');
	i = 0;
	while (path[i])
	{
		ft_printf("first path: %s\n", path[i]);
		char *tmp = ft_strjoin(path[i], "/");
		char *cmd_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(cmd_path, F_OK) == 0)
		{
			ft_free_split(path);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	ft_free_split(path);
	error_exit("Error: Command not found");
	return (NULL);
}

void	ft_free_split(char **str)
{
	int i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	run_command(char *cmd, char **envp)
{
	char *cmd_path = get_command_path(cmd, envp);
	char **cmd_args = ft_split(cmd_path, ' ');
	ft_printf("cmd_path: %s\n", cmd_path);
	if (execv(cmd_path, cmd_args) == -1)
		error_exit("Error: Exec failed");
	ft_free_split(cmd_args);
	
}
