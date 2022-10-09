#include <unistd.h>

void	set_null(int str[96]);

int	forever(int x, int y, int cnt, int arr[6][6])
{	
	int	max;
	
	max = 0;
	while (x < 5)
	{
		y = 1;
		cnt = 0;
		max = arr[y][x];
		while (y < 4)
		{
			if (arr[y + 1][x] > max)
			{
				max = arr[y + 1][x];
				cnt++;
			}
			y++;
		}
		if (arr[0][x] != (cnt + 1))
			return (1);
		x++;
	}
	return (0);
}

int	check_up(int arr[6][6])
{
	int	y;
	int	x;
	int	cnt;
	int	result;

	y = 1;
	x = 1;
	cnt = 0;
	result = forever(x, y, cnt, arr);
	return (result);
}

int	down_y(int map[6][6], int y, int x, int *cnt)
{
	int	max;

	max = map[y][x];
	if (map[y - 1][x] > max)
	{
		*cnt = *cnt + 1;
		max = map[y - 1][x];
	}
	return (max);
}

int	check_down(int map[6][6])
{
	int	y;
	int	x;
	int	cnt;
	int	max;

	y = 1;
	x = 1;
	cnt = 0;
	while (x < 5)
	{
		cnt = 0;
		y = 4;
		max = map[y][x];
		while (y > 1)
		{
			max = down_y(map, y, x, &cnt);
			y--;
		}
		if (!(map[5][x++] == cnt + 1))
			return (1);
	}
	return (0);
}

void	set_null2(int str[10])
{
	int	i;

	i = 0;
	while (i < 10)
	{
		str[i] = 0;
		i++;
	}
}

int	check_overlap(int arr[6][6])
{
	int	x;
	int	y;
	int	vist[10];

	x = 1;
	y = 1;
	set_null2(vist);
	while (x <= 4)
	{
		y = 1;
		while (y <= 4)
		{
			if (vist[arr[y][x]] == 1)
				return (1);
			vist[arr[y][x]] = 1;
			y++;
		}
		set_null2(vist);
		x++;
	}
	return (0);
}

int	check_left(int arr[6][6], int y)
{
	int	x;
	int	cnt;
	int	max;

	x = 1;
	cnt = 0;
	max = arr[y][x];
	while (x < 4)
	{
		if (arr[y][x + 1] > max)
		{
			cnt++;
			max = arr[y][x + 1];
		}
		x++;
	}
	if (!(arr[y][0] == (cnt + 1)))
		return (1);
	return (0);
}

int	check_right(int arr[6][6], int y)
{
	int	x;
	int	cnt;
	int	max;

	x = 4;
	cnt = 0;
	max = arr[y][x];
	while (x > 1)
	{
		if (arr[y][x - 1] > max)
		{
			cnt++;
			max = arr[y][x - 1];
		}
		x--;
	}
	if (!(arr[y][5] == (cnt + 1)))
		return (1);
	return (0);
}

void	set_null(int str[96])
{
	int	i;

	i = 0;
	while (i < 96)
	{
		str[i] = 0;
		i++;
	}
}

void	set_co_null(int co[96][4])
{
	int	i;

	i = 0;
	while (i < 96)
	{
		co[i][0] = 0;
		i++;
	}
}

void	write_board(int board[6][6])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			c = '0' + board[i][j];
			write(1, &c, 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}// 수정 필 / 정답부분만 출력 필요

void	lastlast(int board[6][6])
{
	if (check_down(board) == 0)
	{
		if (check_up(board) == 0)
		{
			if (check_overlap(board) == 0)
			{
				board[0][0] = 1;
				write_board(board);
				write(1, "\n", 1);
			}
		}
	}
	//return ;
}

void	run2(int lev, int co[96][4], int *used2, int *path, int board[6][6], int n)// arg
{
	int	y;
	int	x;
	int	z;

	y = 0;
	if (lev == 4)
	{
		while (y < 4)
		{
			x = 1;
			while (x <= 4)
			{
				board[y + 1][x] = co[path[y] - 1][x - 1];
				x++;
			}
			y++;
		}
		lastlast(board);
		return ;
	}
	z = 1;
	while (z <= n)
	{
		if (lev > 0 && path[lev - 1] > z)
		{
			z++;
			continue ;
		}
		if (used2[z] == 1)
		{
			z++;
			continue ;
		}
		used2[z] = 1;
		path[lev] = z;
		run2(lev + 1, co, used2, path, board, n);
		used2[z] = 0;
		z++;
	}
}// 쪼개야함

void	ch(int	*path, int *y, int co[96][4], int board[6][6], int *z)//arg
{
	int	idx;
	int	boidx;

	boidx = 0;
	idx = 0;
	while (boidx < 4)
	{
		board[*y][boidx + 1] = path[boidx];
		boidx++;
	}
	if (check_right(board, *y) == 0 && check_left(board, *y) == 0)
	{
		while (idx < 4)
		{
			co[*z][idx] = path[idx];
			idx++;
		}
		*z = *z + 1;
	}
}

void	run(int lev, int *y, int used[10], int *path, int co[96][4], int board[6][6], int *z)//arg
{
	int	i;

	i = 1;
	if (lev == 4)
	{
		ch(path, y, co, board, z);
		return ;
	}
	while (i <= 4)
	{
		if (used[i] == 1)
		{
			i++;
			continue ;
		}
		used[i] = 1;
		path[lev] = i;
		run(lev + 1, y, used, path, co, board, z);
		used[i] = 0;
		i++;
	}
}

void	sky_solver(int board[6][6])
{
	int	y;
	int	used[96] = {0};
	int	used2[40] = {0};
	int	path[10];
	int	co[96][4];
	int	z;

	y = 1;
	board[0][0] = 0;
	z = 0;
	set_null(used);
	set_null(path);
	set_co_null(co);
	while (y <= 4)
	{
		run(0, &y, used, path, co, board, &z);
		y++;
	}
	set_null(used);
	run2(0, co, used2, path, board, z);
}

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
