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

	
	if (ac != 5)
		error_exit("Error: Wrong number of arguments");
	
	if ((pipe(fd) == -1))
		error_exit("Error: Pipe failed");
	pid = fork();
	if (pid == -1)
		error_exit("Error: Fork failed");
	if (pid == 0)
		child_process(fd, av, envp);
}

void	child_process(int *fd, char **av, char **envp)
{
	int fd_in;

	fd_in = open(av[1], O_RDONLY, 0777);
	if (fd_in == -1)
		error_exit("Error: File 1 not found");
	dup2(fd[1], STDOUT_FILENO);
	dup2(fd_in, STDIN_FILENO);
	close(fd[0]);
	run_command(av[2], envp);	
}



