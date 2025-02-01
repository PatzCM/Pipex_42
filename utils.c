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

void	error_exit(const char *message, int number)
{
	perror(message);
	exit(number);
}

char	*get_command_path(char *cmd, char **envp)
{
	int		i;
	char	*tmp;
	char	*path;
	char	**cmd_paths;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH=", 5))
		i++;
	cmd_paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (cmd_paths[i])
	{
		path = ft_strjoin(cmd_paths[i], "/");
		tmp = ft_strjoin(path, cmd);
		if (!access(tmp, F_OK))
		{
			free(tmp);
			return (NULL);
		}
		i++;
	}
	return (cmd);
}
void	ft_free_split(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		free(str[i]);
	}
	free(str);
	(void)str;
}

void	run_command(char *cmd, char **envp)
{
	char	*cmd_path;
	char	**path;

	path = ft_split(cmd, ' ');
	cmd_path = get_command_path(path[0], envp);
	if (!cmd_path)
	{
		error_exit("Error: Command not found", 127);
	}
	if (execve(cmd_path, path, envp) == -1)
	{
		free(cmd_path);
		ft_free_split(path);
		error_exit("Error", 127);
	}
	dup2(STDERR_FILENO, STDOUT_FILENO);
	exit(127);
}
