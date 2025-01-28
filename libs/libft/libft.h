/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:39:00 by palexand          #+#    #+#             */
/*   Updated: 2024/11/05 18:34:12 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <bsd/string.h>
# include <strings.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

char					*ft_strnstr(const char *haystack, const char *word, \
										size_t len);
char					*ft_strdup(const char *s);
char					*ft_substr(char const *s, unsigned int start, \
							size_t len);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_atoi(const char *str);
void					ft_bzero(void *s, size_t n);
int						ft_isalnum(int alpha);
int						ft_isalpha(int c);
int						ft_isascii(int c);
int						ft_isdigit(int a);
int						ft_isprint(int c);
size_t					ft_strlen(const char *s);
size_t					ft_strlcat(char *dest, char *src, size_t size);
unsigned int			ft_strlcpy(char *dest, char *src, unsigned int size);
char					*ft_strrchr(const char *s, int c);
int						ft_tolower(int c);
int						ft_toupper(int ch);
char					*ft_substr(char const *s, unsigned int start, \
										size_t len);
void					*ft_memcpy(void *dest_str, const void *src_str, \
										size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memset(void *s, int c, size_t n);
void					*ft_memmove(void *dest, const void *src, size_t n);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
char					*ft_strjoin(char *s1, char *s2);
char					*ft_strtrim(char const *s1, char const *set);
void					*ft_calloc(size_t nmemb, size_t size);
char					*ft_strchr(char *s, int c);
char					**ft_split(char const *s, char c);
char					*ft_itoa(int n);
void					ft_striteri(char *s, void (*f)(unsigned int, char*));
char					*ft_strmapi(const char *s, \
										char (*f)(unsigned int, char));
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char *s, int fd);
void					ft_putendl_fd(char *s, int fd);
void					ft_putnbr_fd(int n, int fd);
t_list					*ft_lstnew(void *content);
void					ft_lstadd_front(t_list **lst, t_list *new);
t_list					*ft_lstnew(void *content);
int						ft_lstsize(t_list *lst);
t_list					*ft_lstlast(t_list *lst);
void					ft_lstadd_back(t_list **lst, t_list *new);
void					ft_lstdelone(t_list *lst, void (*del)(void*));
void					ft_lstclear(t_list **lst, void (*del)(void *));
void					ft_lstiter(t_list *lst, void (*f)(void *));
t_list					*ft_lstmap(t_list *lst, void *(f)(void *), \
											void (*del)(void *));

// GNL 

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char					*get_next_line(int fd);
char					*ft_strchr(char *s, int c);
char					*ft_substr(char const *s, unsigned int start, \
										size_t len);
char					*ft_strjoin(char *s1, char *s2);
void					*ft_calloc(size_t nbytes, size_t size);
char					*left_trim(char *left_c);

// printf 

int						ft_printf(const char *argument, ...);
int						ft_pointer_printf(void *hex);
int						ft_hexa_printf(unsigned int n, int upper_or_lower);
int						ft_nbr_printf(int n);
int						ft_str_printf(char *str);
int						ft_unbr_printf(unsigned int nr);

#endif
