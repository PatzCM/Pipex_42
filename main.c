/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:10:10 by palexand          #+#    #+#             */
/*   Updated: 2025/01/28 21:28:41 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	int fd[2];
	pid_t pid;

	parsing_envp(envp);
	if (ac != 5)
		error_exit("Error: Wrong number of arguments", 1);
	if (pipe(fd) == -1)
		error_exit("Error: Pipe failed", 1);
	pid = fork();
	if (pid == -1)
		error_exit("Error: Fork failed", 1);
	if (pid == 0)
		child_process(fd, av, envp);
	waitpid(pid, NULL, 0);
	parent_process(fd, av, envp);
}

void	child_process(int *fd, char **av, char **envp)
{
	int fd_in;

	fd_in = open(av[1], O_RDONLY, 0777);
	if (fd_in == -1)
		error_exit("Error: File 1 not found", 0);
	dup2(fd[1], STDOUT_FILENO);
	dup2(fd_in, STDIN_FILENO);
	close(fd[0]);
	run_command(av[2], envp);	
}

void	parent_process(int *fd, char **av, char **envp)
{
	int fd_out;

	fd_out = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd_out == -1)
		error_exit("Error: File 2 not found", 0);
	dup2(fd[0], STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close(fd[1]);
	run_command(av[3], envp);
}

void	parsing_envp(char **envp)
{
	int i = -1;
	int result;

	i = -1;
	result = 0;

	while (envp[++i])
	{
	if (!ft_strnstr(envp[i], "PATH=", 5) && envp[i][6])
			result = 1;
	}
	if	(result != 1)
		error_exit("Error: PATH not found in envp", 1);
}
