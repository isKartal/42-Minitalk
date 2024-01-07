/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskartal <iskartal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:40:42 by iskartal          #+#    #+#             */
/*   Updated: 2023/11/28 12:03:34 by iskartal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (str[i])
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res);
}

void	send_srv(char c, int pid)
{
	int	i;

	i = 0;
	c <<= 1;
	while (i < 7)
	{
		if ((c & 128))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c <<= 1;
		i++;
		usleep(70);
	}
}

void	send_msg(char *msg, int pid)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		send_srv(msg[i], pid);
		i++;
	}
}

int	main(int ac, char **av)
{
	int		spid;

	if (ac != 3)
	{
		write(1, "wrong number of arguments..\n", 28);
		return (1);
	}
	spid = ft_atoi(av[1]);
	send_msg(av[2], spid);
	return (0);
}
