int	check_argv_comb(char *argv)
{
	char	str[16];
	int		sum;
	int		i;
	int		j;

	i = 0;
	j = 0;
	init_argv_str(argv, str);
	while (j < 16)
	{
		if (i == 4)
			i = 8;
		j = i + 4;
		if (j < 16)
			sum = str[i] - '0' + str[j] - '0';
		if (sum < 3 || sum > 6)
			return (0);
		i++;
	}
	return (1);
}

int	check_argv_format(char *argv)
{
	int	len;
	int	idx;

	len = 0;
	while (argv[len])
		len++;
	if (len != 31)
		return (0);
	idx = 0;
	while (argv[idx])
	{
		if (idx % 2 == 1)
		{
			if (argv[idx] != ' ')
				return (0);
		}
		else
		{
			if (argv[idx] <= '0' || argv[idx] >= '5')
				return (0);
		}
		idx++;
	}
	return (1);
}
