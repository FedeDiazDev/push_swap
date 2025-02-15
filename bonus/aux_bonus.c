#include "../include/push_swap_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	size_len;

	size_len = ft_strlen(s1);
	ptr = (char *)malloc(size_len + 1);
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s1, size_len);
	ptr[size_len] = '\0';
	return (ptr);
}
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (!size)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && (i < size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (ft_strlen(src));
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;

	i = 0;
	d = dst;
	s = src;
	if (!dst && !src)
		return (dst);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

int	ft_lstsize_ps(t_stack **stack)
{
	int	i;

	i = 0;
	while (*stack)
	{
		stack = &(*stack)->next;
		i++;
	}
	return (i);
}