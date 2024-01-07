/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskartal <iskartal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:41:10 by iskartal          #+#    #+#             */
/*   Updated: 2023/11/28 12:02:44 by iskartal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr(int nbr)
{
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
		write(1, &"0123456789"[nbr], 1);
}

void	handle(int signal)
{
	static char	a;
	static int	i;

	i++;
	a <<= 1;
	if (signal == SIGUSR1)
		a++;
	if (i == 7)
	{
		i = 0;
		write(1, &a, 1);
		a = 0;
	}
}

int	main(void)
{
	write(1, "pid is: ", 8);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, handle);
	signal(SIGUSR2, handle);
	while (1)
	{
		sleep(1);
	}
	return (0);
}
