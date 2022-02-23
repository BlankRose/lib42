/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:30:15 by flcollar          #+#    #+#             */
/*   Updated: 2022/02/23 11:33:43 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_vector3 {
	int		x;
	int		y;
	int		z;
}	t_vector3;

// CHAR TESTINGS
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_isspace(int c);

// CHAR FINDER
size_t		ft_strnchr(const char *s, int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
size_t		ft_strlstr(const char *haystack, const char *needle, size_t len);
int			ft_toupper(int c);
int			ft_tolower(int c);

// STRING MANIPULATIONS
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
/* Warning: Requierds 'malloc' below! */
char		*ft_strdup(const char *s1);
char		*ft_substr(const char *s, unsigned int start, size_t len);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strtrim(const char *s1, const char *set);
char		**ft_split(const char *s, char c);

// STRING APPLY FUNCTIONS
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
/* Warning: Requierds 'malloc' below! */
char		*ft_strmapi(const char *s, char (*f)(unsigned int, char));

// MATHS
t_vector3	ft_vector3_new(int x, int y, int z);
size_t		ft_nbrlen(unsigned int x);
int			ft_clamp(int x, int min, int max);

// CONVERTERS
int			ft_atoi(const char *str);
/* Warning: Requierds 'malloc' below! */
char		*ft_itoa(int n);

// MEMORY MANIPULATIONS
void		*ft_memset(void *b, int c, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
/* Warning: Requierds 'malloc' below! */
void		*ft_calloc(size_t count, size_t size);

// OUTPUTS
/* Warning: Requierds 'write' below! */
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

#endif
