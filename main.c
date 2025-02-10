#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_pipex	*pipex;
	pipex =	NULL;

	init_pipex(&pipex);
	if (parsing_input(&pipex, av, envp, ac) == 0)
		return(error_exit(&pipex, "ERROR"));
	pipex->fd_in = open(av[1], O_RDONLY);
	if (av[4][0] != '\0' && (access(av[4], F_OK) || !access(av[4], R_OK)))
		pipex->fd_out = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (access(av[4], F_OK))
		return(error_exit(&pipex, "ERROR"));
	else
		return (error_exit(&pipex, "ERROR"));
	dup2(pipex->fd_in, STDIN_FILENO);
	dup2(pipex->fd_out, STDOUT_FILENO);
	redirect_process(&pipex, envp);
	error_exit(&pipex, NULL);
	return(1);
}

int	redirect_process(t_pipex **pipex, char **envp)
{
	pid_t	pid[2];
	int		fd[2];

	if (pipe(fd) == -1)
		error_exit(pipex, "ERROR");
	second_process(pipex, envp, fd, pid);
	close(fd[1]);
	close(fd[0]);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
	return(1);
}

int	second_process(t_pipex **pipex, char **envp, int *fd, pid_t *pid)
{
	pid[0] = fork();
	if (pid[0] == -1)
		error_exit(pipex, "ERROR");
	if (pid[0] > 0)
		{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		run_command(pipex, 0, envp);
		}
	pid[1] = fork();
	if (pid[1] == -1)
		error_exit(pipex, "ERROR");
	if (pid[1] > 0)
		{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		run_command(pipex, 1, envp);
		}
	return(0);
}

void	run_command(t_pipex **pipex, int index, char **envp)
{
	char	**temp;
	
	temp = ft_split((*pipex)->cmd[index], ' ');
	if (!temp)
		error_exit(pipex, "ERROR");
	execve((*pipex)->path[index], temp, envp);
}

void	init_pipex(t_pipex **pipex)
{
	(*pipex) = malloc(sizeof(t_pipex));
	if ((*pipex) == NULL)
		error_exit(pipex, "ERROR");
	(*pipex)->fd_in = -1;
	(*pipex)->fd_out = -1;
	(*pipex)->cmd = ft_calloc(sizeof(char *), 3);
	(*pipex)->path = ft_calloc(sizeof(char *), 3);
	if ((*pipex)->cmd == NULL || (*pipex)->path == NULL)
		error_exit(pipex, "ERROR");
}

int	error_exit(t_pipex **pipex, char *error)
{
	if ((*pipex)->path)
	{
		free_path((*pipex)->cmd);
		free_path((*pipex)->path);
	}
	else
	{
		free((*pipex)->cmd);
		free((*pipex)->path);
	}
	free(*pipex);
	if (error != NULL)
		perror(error);
	return (1);
}

int	parsing_input(t_pipex	**pipex, char **av, char **envp, int size)
{
	int	i;
	char	**path;

	i = -1;
	if (size != 5)
		error_exit(pipex, "ERROR");
	if (access(av[1], R_OK) == -1)
		error_exit(pipex, "ERROR");
	if (av[1] == NULL || av[2] ==	NULL)
		error_exit(pipex, "ERROR");
	while(envp[++i])
		if (ft_strnstr(envp[i], "PATH=", 5))
			path = ft_split(&envp[i][5], ':');
	if (!path)
		return(error_exit(pipex, "ERROR"));
	return(set_commands(pipex, av, path, size));
}

int	set_commands(t_pipex **pipex, char **av, char **path, int size)
{
	/*char	*tmp;*/
	char	*tmp2;	
	int		i;
	int		j;
	int		n;

	i = 2;
	j = -1;
	n = 0;
	while(path[++j] && i + n < size - 1)
	{
		tmp2 = ft_substr(av[i + n], 0, (ft_strchrlen(av[i + n], ' ')));
		(*pipex)->cmd[n] = ft_strdup(av[i + n]);
		(*pipex)->path[n] = ft_strjoin(path[j], "/");
		(*pipex)->path[n] = ft_strjoin((*pipex)->path[n], tmp2);
		if (access((*pipex)->path[n], O_DIRECTORY) == -1 
			&& open((*pipex)->path[n], F_OK != -1) && ++n)
			j = -1;
		free_loop(tmp2, (*pipex)->cmd, (*pipex)->path, j);	
	}
	free_path(path);
	ft_printf("path = %s\n", (*pipex)->path[i - 1]);
	ft_printf("access = %d\n", access((*pipex)->path[i - 1], F_OK));
	if (!(*pipex)->path[i - 1] || access((*pipex)->path[i - 1], F_OK != -1))
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
	if (j != -1 && path)
	{
		while (j--)
			free(path[j]);
		free(path);
	}
	if (j != -1 && cmd)
	{
		while (j--)
			free(cmd[j]);
		free(cmd);
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
