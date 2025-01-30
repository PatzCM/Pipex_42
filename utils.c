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
	ft_printf("%s\n", message);
	exit(number);
}

char	*get_command_path(char *cmd, char **envp)
{
	int		i;
	char	*tmp;
	char	*path;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH=", 5))
		i++;
	envp[i] += 5;
	while (*envp[i])
	{
		path = ft_strjoin(envp[i], "/");
		tmp = ft_strjoin(path, cmd);
		if (!access(tmp, F_OK))
		{
			free(path);
			return (tmp);
		}
		free(path);
		free(tmp);
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
	execve(cmd_path, path, envp);
	dup2(STDERR_FILENO, STDOUT_FILENO);
	free(path);
	exit(127);
}
