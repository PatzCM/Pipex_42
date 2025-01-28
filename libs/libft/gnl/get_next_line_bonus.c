/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:21:48 by palexand          #+#    #+#             */
/*   Updated: 2024/11/20 17:21:50 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*fill_line(int fd, char *left_c);
char	*line_definer(char *left_c);
char	*left_trim(char *untrimmed);

char	*get_next_line(int fd)
{
	static char	*left_c[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_c[fd] = fill_line(fd, left_c[fd]);
	if (!ft_strlen(left_c[fd]))
	{
		free(left_c[fd]);
		return (NULL);
	}
	line = line_definer(left_c[fd]);
	left_c[fd] = left_trim(left_c[fd]);
	return (line);
}

char	*fill_line(int fd, char *left_c)
{
	int		bytes_read;
	char	*temp;

	temp = malloc(sizeof(char ) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(left_c, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(temp);
			free(left_c);
			return (NULL);
		}
		temp[bytes_read] = '\0';
		left_c = ft_strjoin(left_c, temp);
	}
	free(temp);
	return (left_c);
}

char	*line_definer(char *left_c)
{
	char	*line;
	int		i;

	i = 0;
	if (!left_c[i])
		return (NULL);
	while (left_c[i] != '\n' && left_c[i])
		i++;
	line = ft_calloc((i + 2), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (left_c[i] != '\n' && left_c[i])
	{
		line[i] = left_c[i];
		i++;
	}
	if (left_c[i] == '\n')
	{
		line[i] = left_c[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

/*int	main(int argc, char **argv)*/
/*{*/
/*	char	*line;*/
/*	int		fd;*/
/*	int		i;*/
/**/
/*	i = 1;*/
/*	if (argc >= 2)*/
/*	{*/
/*		while (i < argc)*/
/*		{*/
/*			fd = open(argv[i], O_RDONLY);	*/
/*			if (fd < 0)*/
/*			{*/
/*				printf("%s\n", "File does not exist.");*/
/*			}*/
/*			else*/
/*			{*/
/*				printf("%s\n", argv[i]);*/
/*				line = get_next_line(fd);*/
/*				while(line)*/
/*				{*/
/*					printf("%s", line);*/
/*					free(line);*/
/*					line = get_next_line(fd);*/
/*				}*/
/*			}*/
/*			printf("\n");*/
/*			free(line);*/
/*			close(fd);*/
/*			i++;*/
/*		}*/
/*	}*/
/*}*/
