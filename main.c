void	init_argv_str(char *argv, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < 16)
	{
		if (i % 2 == 0)
		{
			str[j] = argv[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
}

void	set_null_arr(int board[6][6])
{
	int	i;
	int	j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	draw_board(char *argv, int board[6][6])
{
	char	str[16];

	init_argv_str(argv, str);
	board[0][1] = str[0] - '0';
	board[0][2] = str[1] - '0';
	board[0][3] = str[2] - '0';
	board[0][4] = str[3] - '0';
	board[5][1] = str[4] - '0';
	board[5][2] = str[5] - '0';
	board[5][3] = str[6] - '0';
	board[5][4] = str[7] - '0';
	board[1][0] = str[8] - '0';
	board[2][0] = str[9] - '0';
	board[3][0] = str[10] - '0';
	board[4][0] = str[11] - '0';
	board[1][5] = str[12] - '0';
	board[2][5] = str[13] - '0';
	board[3][5] = str[14] - '0';
	board[4][5] = str[15] - '0';
}

int	main(int argc, char *argv[])
{
	int	board[6][6];

	if (!(argc == 2 && check_argv_format(argv[1])))
	{
		write(2, "ERROR\n", 6);
		return (0);
	}
	if (!(check_argv_comb(argv[1])))
	{
		write(2, "ERROR\n", 6);
		return (0);
	}
	set_null_arr(board);
	draw_board(argv[1], board);
	sky_solver(board);
	if (board[0][0] == 0)
		write(2, "ERROR\n", 6);
	return (0);
}
