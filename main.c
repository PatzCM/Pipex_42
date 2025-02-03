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
#include <fcntl.h>

int	main(int ac, char **av, char **envp)
{
	int fd[2];
	int pipex[2];

	if (ac == 5)
	{
	fd[0] = open(av[1], O_RDONLY);	
	fd[1] = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if(parsing(av) == -1)
		exit(EXIT_FAILURE);
	pipe(pipex);
	redirect_process(av, envp, fd, pipex);
	second_process(av, envp, fd, pipex);
	}
	else
	{
		ft_putstr_fd("Error: Invalid number of arguments\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	wait(NULL);
	wait(NULL);
	
}

void	redirect_process(char **av, char **envp, int *fd, int *pipex)
{
	pid_t pid;
	pid = fork();
	if (pid)
	{
		close(fd[1]);
		close(pipex[0]);
		dup2(fd[0], 0);
		dup2(pipex[1], 1);
		run_command(av[2], envp);
	}
	else
	{
		waitpid(pid, NULL, 0);
	}
}
void	second_process(char **av, char **envp, int *fd, int *pipex)
{
	pid_t pid;
	pid = fork();
	if (pid)
	{
		close(fd[0]);
		close(pipex[1]);
		dup2(pipex[0], 0);
		dup2(fd[1], 1);
		run_command(av[3], envp);
	}
}

int	parsing(char **argv)
{
		if (access(argv[1], F_OK) == -1)
		{
			ft_putstr_fd("Error: File does not exist\n", 2);
			return (-1);
		}
		if (access(argv[4], W_OK) == -1)
		{
			ft_putstr_fd("Error: File is not readable\n", 2);
			return (-1);
		}
	return (0);
}	
