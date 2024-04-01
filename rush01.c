/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazaffal <dazaffal@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:27:07 by dazaffal          #+#    #+#             */
/*   Updated: 2024/04/01 16:54:56 by dazaffal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#define N 4

//M[m][n]; M[i][j]= *(M+(i*n+j))
void	fill_board(int board[][N], int c)
{
	int i;
	int j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			board[i][j] = c;
			j++;
		}
		i++;
	}
}

void	print_board(int board[][N])
{
	int	i;
	int	j;
	char v;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			v = board[i][j] + 48;
			write(1, &v, 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	parsing(int views[][N], char *p)
{
	int	i;
	int	j;
	int	counter;

	//write(1, "Views are: \nUp\nDown\nLeft\nRight\n", 32);
	counter = 0;
	i = 0;
	while (*p != '\0' && i < N)
	{
		j = 0;
		while (*p != '\0' && j < N)
		{
			views[i][j] = *p - 48;
			//printf("%c ",views[i][j]+48);
			j++;
			p = p + 2;
			counter++;
		}
		//printf("\n");
		i++;
	}
	if (counter != (N * N))
		return (0);
	else
		return (1);
}

int is_valid(int board[][N], int views[][N], int position)
{
	int i;
	int acc_view[4];//up, down, left, right view
	int last_max[4];
	int row;
	int col;
	int num;

	row = position / N;
	col = position % N;
	num = board[row][col];
	i = 0;
	while (i < N)
	{
		if (board[row][i] == num && i != col)
			return (0);
		if (board[i][col] == num && i != row)
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		acc_view[i] = 0;
		last_max[i] = 0;
		i++;
	}
	i = 0;
	while (i < N)
	{
		if (board[i][col] == 0)
		{
			acc_view[0] = -1;
			acc_view[1] = -1;
		}
		if (board[row][i] == 0)
		{
			acc_view[2] = -1;
			acc_view[3] = -1;
		}
		if (acc_view[0] >= 0 && board[i][col] > last_max[0])
		{
			last_max[0] = board[i][col];
			acc_view[0]++;
		}
		if (acc_view[1] >= 0 && board[(N - 1) - i][col] > last_max[1])
		{
			last_max[1] = board[(N - 1) -i][col];
			acc_view[1]++;
		}
		if (acc_view[2] >= 0 && board[row][i] > last_max[2])
		{
			last_max[2] = board[row][i];
			acc_view[2]++;
		}
		if (acc_view[3] >= 0 && board[row][(N - 1) - i] > last_max[3])
		{
			last_max[3] = board[row][(N - 1) -i];
			acc_view[3]++;
		}
		i++;
	}
	if ((acc_view[0] == views[0][col] || acc_view[0] == -1)
		&& (acc_view[1] == views[1][col] || acc_view[1] == -1)
		&& (acc_view[2] == views[2][row] || acc_view[2] == -1)
		&& (acc_view[3] == views[3][row] || acc_view[3] == -1))
		return (1);
	else
		return (0);
}

int  solve(int board[][N], int position, int views[][N])
{
	int row;
	int col;
	int	num;
	
	num = 1;
	if (position == N * N)
		return 1;
	row = position / N;
	col = position % N;
	while (num <= 4)
	{
		board[row][col] = num;
		if (is_valid(board, views, position))
		{
			if (solve(board,(position + 1),views))
				return (1);
		}
		num++;
	}
	board[row][col] = 0;
	return (0);
}

int	main(int ac,char **av)
{
	char	*input;
	int		board[N][N];
	int		views[4][N];

	input = av[1];
	if (!parsing(views, input) && ac != 2)
	{
		write(1, "Error: unexpected number of arguments\n", 39);
		return (1);
	}
	fill_board(board, 0);
	if (solve(board, 0, views))
		print_board(board);
	else
		write(1, "Not solved\n", 11);
}
