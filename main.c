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

	/*t_pipex *pipex;*/
	/*pipex = malloc(sizeof(t_pipex));*/
	/*if (!pipex)*/
	/*{*/
	/*	free(pipex);*/
	/*	error_exit("Error: Malloc failed", 1, pipex);*/
	/*}*/
	if (ac == 5)
	{
		fd[0] = open(av[1], O_RDONLY, 0777);
		dup2(fd[0], STDIN_FILENO);
		redirect_process(av[1], av[2], envp);
		fd[1] = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		parse(fd[1], "Error: File 2 not found");
		dup2(fd[1], STDOUT_FILENO);
		run_command(av[3], envp);
	}
}

void	redirect_process(char *file, char *cmd, char **envp)
{
	pid_t pid;
	int fd[2];

	parse(pipe(fd), "Error: Pipe");
	pid = fork();
	if (pid)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		waitpid(pid, NULL, 0);
	}
	else
	{
		parse(access(file, F_OK), file);
		dup2(fd[1], STDOUT_FILENO);
		run_command(cmd, envp);
	}
}

/*void	parent_process(int *fd, char **av, char **envp, t_pipex *pipex)*/
/*{*/
/*	int fd_out;*/
/*	fd_out = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);*/
/*	if (fd_out == -1)*/
/*		error_exit("Error: File 2 not found", 0, pipex);*/
/*	dup2(fd[0], STDIN_FILENO);*/
/*	dup2(fd_out, STDOUT_FILENO);*/
/*	close(fd[1]);*/
/*	run_command(av[3], envp, pipex);*/
/*}*/

void	parse(int result, char *msg)
{
	if (result == -1)
	{
		ft_putstr_fd("Error: ", STDERR_FILENO);
		perror(msg);
		exit(EXIT_FAILURE);
	}
}
