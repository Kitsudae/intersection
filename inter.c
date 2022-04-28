#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int ft_is_unique(int i, char *str)
{
	size_t	j;

	j = 0;
	while(j < i)
	{
		if (str[j] == str[i])
			return (0);
		j++;
	}
	return (1);
}

int	ft_is_in_the_set(char c, char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i ++;
	return (i);
}

char	*ft_inter(char *str1, char *str2)
{
	int		i;
	int		k;
	int		inter_len;
	char	*picker_str;
	char	*inter_str;
	
	picker_str = malloc(ft_strlen(str1) + 1);
	i = 0;
	while (str1[i])
	{
		picker_str[i] = ft_is_in_the_set(str1[i], str2);
		if ((i >= 1) && picker_str[i] == 1)
		{
			picker_str[i] = ft_is_unique(i, str1);
			if (picker_str[i] == 1)
				inter_len += 1;
		}
		i++;
	}
	picker_str[i] = '\0';
	inter_str = malloc(inter_len + 1);
	i = 0;
	k = 0;
	while (k <= inter_len)
	{
		if (picker_str[i] == 1)
		{
			inter_str[k] = str1[i];
			i++;
		}
		while (picker_str[i] == 0)
			i++;
		k++;
	}
	inter_str[k] = '\0';
	free(picker_str);
	return(inter_str);
}

int main (int argc, char *argv[])
{
	char	*inter_str;

	inter_str = ft_inter(argv[1], argv[2]);
	if (argc != 3)
		write(1, "\n", 1);
	else
		write(1, inter_str, ft_strlen(inter_str));
	free(inter_str);
	return (0);
}
