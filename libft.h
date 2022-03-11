/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:30:15 by flcollar          #+#    #+#             */
/*   Updated: 2022/03/11 10:18:18 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdarg.h>

# ifdef _WIN32
#  include <io.h>
# else
#  include <unistd.h>
# endif

/*********************************************************/
/*                                                       */
/*                     DEFINITIONS                       */
/*  Various macros for easier handling across functions  */
/*                                                       */
/*********************************************************/

/* Definitions of booleans */

# define TRUE 1
# define FALSE 0

/* Definitions of various basic bases */

# define BINARY "01"
# define OCTAL "01234567"
# define DECIMAL "0123456789"
# define HEXA_LOW "0123456789abcdef"
# define HEXA_UP "0123456789ABCDEF"
# define HEXA HEXA_LOW

/* Definitions of colors for texts */

# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define PURPLE "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"
# define COLORLESS "\033[39m"

# define BOLD "\033[1m"
# define FAINTCOLOR "\033[2m"
# define ITALIC "\033[3m"
# define UNDERLINE "\033[4m"
# define FONTLESS "\033[22;23m"

# define RESETFONT "\033[0m"

/*********************************************************/
/*                                                       */
/*                      STRUCTURES                       */
/*    Various structures for easier variable handling    */
/*                                                       */
/*********************************************************/

/* Color structure for specifying colors
Variables: (unsigned char) r, g, b */
typedef struct s_color {
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_color;

/* Vector 3 structure for 3D coordinates
Variables: (int) x, y, z */
typedef struct s_vector3 {
	int		x;
	int		y;
	int		z;
}	t_vector3;

/* Vector 2 structure for 2D coordinates
Variables: (int) x, y */
typedef struct s_vector2 {
	int		x;
	int		y;
}	t_vector2;

/* Chained list structure
Variables: (void*) content, (s_list*) next */
typedef struct s_list {
	void			*content;
	struct s_list	*next;
}	t_list;

/*********************************************************/
/*                                                       */
/*                  CHARACTER TESTINGS                   */
/*      Functions for testing specifics characters       */
/*                                                       */
/*********************************************************/

/* Test if C is a lower case character
Return: 1 (TRUE) or 0 (FALSE) */
int				ft_islower(int c);

/* Test if C is an upper case character
Return: 1 (TRUE) or 0 (FALSE) */
int				ft_isupper(int c);

/* Test if C is alphabetic
Return: 1 (TRUE) or 0 (FALSE) */
int				ft_isalpha(int c);

/* Test if C is digital
Return: 1 (TRUE) or 0 (FALSE) */
int				ft_isdigit(int c);

/* Test if C is alphanumeric
Return: 1 (TRUE) or 0 (FALSE) */
int				ft_isalnum(int c);

/* Test if C is part of the ASCII table
Return: 1 (TRUE) or 0 (FALSE) */
int				ft_isascii(int c);

/* Test if C is printable
Return: 1 (TRUE) or 0 (FALSE) */
int				ft_isprint(int c);

/* Test if C is a whitespace
Return: 1 (TRUE) or 0 (FALSE) */
int				ft_isspace(int c);

/* Test if C is a sign positive or negative
Return: 1 (POSITIVE) or 0 (FALSE) or -1 (NEGATIVE) */
int				ft_issign(int c);

/* Test if C exist within a definied SET 
Return: 1 (TRUE) or 0 (FALSE) */
int				ft_isset(int c, const char *set);

/*********************************************************/
/*                                                       */
/*                  CHARACTERS FINDER                    */
/*       Functions to locate specifics characters        */
/*                                                       */
/*********************************************************/

/* Counts how many times C apears in the string S
Return: number of times C was found */
size_t			ft_strnchr(const char *s, int c);

/* Locates the first C in the string S
Return: address of first C found */
char			*ft_strchr(const char *s, int c);

/* Locates the last C in the string S
Return: address of last C found */
char			*ft_strrchr(const char *s, int c);

/* Counts how many times NEEDLE appears in string STR within LEN characters
Return: number of times NEEDLE was found */
char			*ft_strnstr(const char *str, const char *needle, size_t len);

/* Locates the first occurance of NEEDLE in string STR within LEN character
Return: address of NEEDLE's first character found */
size_t			ft_strlstr(const char *str, const char *needle, size_t len);

/* Converts the lowercase C into its uppercase variant
Return: uppercase variant of C if it exists */
int				ft_toupper(int c);

/* Converts the uppercase C into its lowercase variant
Return: lowercase variant of C if it exists */
int				ft_tolower(int c);

/*********************************************************/
/*                                                       */
/*                 STRING MANIPULATIONS                  */
/*      Functions to modify strings in various ways      */
/*                                                       */
/*********************************************************/

/* Copies DSTSIZE characters of the string SRC into DST
Return: length of the string it tried to create */
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);

/* Copies DSTSIZE characters of the string SRC into DST
Return: length of the string it tried to create */
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);

/* Check the length of the string S
Return: length of S */
size_t			ft_strlen(const char *s);

/* Check the length of the string S before the character C appears
Return: length of S */
size_t			ft_strlenlimit(const char *s, char c);

/* Check the length of the string S before the character C disappears
Return: length of S */
size_t			ft_strlenlimitrev(const char *s, char c);

/* Check the length of the string S before any specified characters in
SET appears
Return: length of S */
size_t			ft_strlenlimitset(const char *s, char *set);

/* Check the length of the string S before any specified characters in
SET disapears
Return: length of S */
size_t			ft_strlenlimitsetrev(const char *s, char *set);

/* Compare the strings S1 and S2 within N characters
Return: difference between S1 and S2 */
int				ft_strncmp(const char *s1, const char *s2, size_t n);

/* Create a clone of the string S1
Return: newly created string or NULL if allocation failed
REQUIERD: malloc() !*/
char			*ft_strdup(const char *s1);

/* Create a clone of the string S1, starting at index START and limits at
LEN characters
Return: newly created string or NULL if allocation failed
REQUIERD: malloc() !*/
char			*ft_substr(const char *s, unsigned int start, size_t len);

/* Joins togheter the strings S1 and S2 into a new string
Return: newly created string or NULL if allocation failed
REQUIERD: malloc() ! */
char			*ft_strjoin(const char *s1, const char *s2);

/* Create a clone of the string S1, but removes every characters in SET at
the beginning and the end of the string
Return: newly created string or NULL if allocation failed
REQUIERD: malloc() !*/
char			*ft_strtrim(const char *s1, const char *set);

/* Splits the string S into a table, using C as a seperator
Return: newly created table of strings or NULL if allocation failed
REQUIERD: malloc() and free() !*/
char			**ft_split(const char *s, char c);

/* Apply a function F() to every characters of a string S */
void			ft_striteri(char *s, void (*f)(unsigned int, char *));

/* Clone the string S and apply the function F() on every characters
Return: newly created string or NULL if allocation failed
REQUIERD: malloc() !*/
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));

/*********************************************************/
/*                                                       */
/*                     MATHEMATICS                       */
/*       Functions to help solving maths problems        */
/*                                                       */
/*********************************************************/

/* Creates a new vector 3 structure with specified coordinates
Return: newly created vector3 */
t_vector3		ft_vector3_new(int x, int y, int z);

/* Check the length of the number X but allows massive numbers
Return: length of X */
size_t			ft_nbrlen_long(unsigned long long x);

/* Check the length of the number X
Return: length of X */
size_t			ft_nbrlen(unsigned int x);

/* Check the length of the number X within the size of another BASE
Return: length of X in BASE */
size_t			ft_nbrlen_base(unsigned long long x, size_t base);

/* Limits the number X in a range between MIN and MAX
Return: MIN or X or MAX */
int				ft_clamp(int x, int min, int max);

/* Limits the number X in a range between MIN and inf
Return: MIN or X */
int				ft_min(int x, int min);

/* Limits the number X in a range between -inf and MAX
Return: X or MAX */
int				ft_max(int x, int max);

/*********************************************************/
/*                                                       */
/*                      CONVERTERS                       */
/*   Functions to convert various things into anything   */
/*                                                       */
/*********************************************************/

/* Interpret and converts the number N into a string
Return : string counterpart found
REQUIERD: malloc() !*/
char			*ft_itoa(int n);

/* Interpret and converts the string STR into an int
Return: number counterpart found */
int				ft_atoi(const char *str);

/* Interpret and converts the number N into a string but allows massive numbers
Return : string counterpart found
REQUIERD: malloc() !*/
char			*ft_itoa_long(long long n);

/* Interpret and converts the unsigned number N into a string
Return : string counterpart found
REQUIERD: malloc() !*/
char			*ft_itoa_unsigned(unsigned int n);

/* Interpret and converts the unsigned number N into a string but
allows massive numbers
Return : string counterpart found
REQUIERD: malloc() !*/
char			*ft_itoa_unsigned_long(unsigned long long n);

/* Check if the BASE is valid (no whitespaces, no signs, no doubles)
Return: length of BASE or 0 if invalid base */
size_t			ft_checkbase(char *base);

/* Convert the string S from a BASE to a decimal base
Return: converted string or 0 if invalid base */
unsigned int	ft_base2dec(char *s, char *base);

/* Convert the number S from a decimal base to a BASE
Return: converted number or NULL if allocation failed or invalid base
REQUIERD: malloc() !*/
char			*ft_dec2base(unsigned int n, char *base);

/* Convert the pointer X from a decimal base to a BASE
Return: converted pointer or NULL if allocation failed or invalid base
REQUIERD: malloc() !*/
char			*ft_ptr2base(void *x, char *base);

/* Convert the string S from the base B1 to the base B2
Return: converted string or NULL if allocation failed or invalid bases
REQUIERD: malloc() and free() !*/
char			*ft_base2base(char *s, char *b1, char *b2);

/*********************************************************/
/*                                                       */
/*                  LIST MANIPULATIONS                   */
/*        Functions to handle easily chained list        */
/*                                                       */
/*********************************************************/

/* Creates a new list structure, initialized with CONTENT
Return: newly created list
REQUIERD: malloc() !*/
t_list			*ft_lstnew(void *content);

/* Fetch the last list content from the chain LST
Return: address of last list */
t_list			*ft_lstlast(t_list *lst);

/* Count the amount of content in the chained list LST
Return: length of LST */
int				*ft_lstsize(t_list *lst);

/* Add the NEW list in the chained list LST at first position */
void			ft_lstadd_front(t_list **lst, t_list *new);

/* Add the NEW list in the chained list LST at last position */
void			ft_lstadd_back(t_list **lst, t_list *new);

/*********************************************************/
/*                                                       */
/*                 MEMORY MANIPULATIONS                  */
/*          Functions to modify raw memory bits          */
/*                                                       */
/*********************************************************/

/* Check the length of the memory S
Return: length of S */
size_t			ft_memlen(const void *s);

/* Change LEN octets of given data B with data C
Return: modified data B */
void			*ft_memset(void *b, int c, size_t len);

/* Copy N octets from data SRC to DST
Return: modifed data DST */
void			*ft_memcpy(void *dst, const void *src, size_t n);

/* Move N octets from data SRC to DST
Return: modified data DST */
void			*ft_memmove(void *dst, const void *src, size_t len);

/* Locates data C within data S in the N first octets
Return: address of C found */
void			*ft_memchr(const void *s, int c, size_t n);

/* Replace N octets in data S with 0
Return: modified data S */
void			ft_bzero(void *s, size_t n);

/* Compare N octets of datas S1 and S2
Return: difference between S1 and S2 */
int				ft_memcmp(const void *s1, const void *s2, size_t n);

/* Allocate SIZE * COUNT memory and initialize eveything at 0
Return: allocated memory or NULL if allocation failed
REQUIERD: malloc() !*/
void			*ft_calloc(size_t count, size_t size);

/* Catch the address of the point P
Return: address as a string or NULL if allocation failed
REQUIERD: malloc() !*/
char			*ft_getaddress(void *p);

/* Allows to free multiples strings at once
Return: NULL
REQUIERD: free() !*/
char			*ft_release(char *s1, char *s2);

/*********************************************************/
/*                                                       */
/*                  IN & OUT HANDLER                     */
/*  Functions to handle programme's inputs and outputs   */
/*                                                       */
/*********************************************************/

/* Print out a single character C, in a specified output/file FD
REQUIERD: write() !*/
size_t			ft_putchar_fd(char c, int fd);

/* Print out the string S in a specified output/file FD
REQUIERD: write() !*/
size_t			ft_putstr_fd(char *s, int fd);

/* Print out the string S and add a new line in a specified output/file FD
REQUIERD: write() !*/
size_t			ft_putendl_fd(char *s, int fd);

/* Print out the number N in a specified output/file FD
REQUIERD: write() !*/
size_t			ft_putnbr_fd(int n, int fd);

/* Print out the string S in a specified output/file FD
REQUIERD: write() !*/
size_t			ft_putnstr_fd(const char *s, int fd, size_t n);

/* Print out the string S to the output, and converts using various flags
Return: number of caracters printed or -1 if it failed
REQUIERD: malloc(), free(), write() and va_arg() !*/
int				ft_printf(int fd, const char *s, ...);

#endif