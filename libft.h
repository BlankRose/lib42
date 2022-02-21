/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:30:15 by flcollar          #+#    #+#             */
/*   Updated: 2022/02/21 16:03:17 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// CHAR TESTINGS
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);

// CHAR FINDER
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(char *str, int c);
char	*ft_strrchr(char *str, int c);

// STRING MANIPULATIONS
int		ft_strlen(char *str);
int		ft_strlcpy(char *dest, char *src, int length);
int		ft_strlcat(char *dest, char *src, int length);
int		ft_strncmp(char *s1, char *s2, int length);

// CONVERTERS
int		ft_atoi(char *str);

#endif
