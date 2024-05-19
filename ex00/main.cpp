/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:58:26 by asaber            #+#    #+#             */
/*   Updated: 2024/05/19 21:36:11 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <iostream>

int	main(int ac, char **av)
{
	(void) av;
	bitcoin_data btc;
	if (ac == 2)
		btc.start(av[1]);
	else
		std::cout << ICYAN << "Bad passing data!! try agin\n" << RESET;
	return (0);	
}
