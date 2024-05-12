/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 01:32:10 by asaber            #+#    #+#             */
/*   Updated: 2024/05/11 22:46:54 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <chrono>
#include <ctime>
#include <cstdlib>


#define ALERT "\033[1;33m"
#define RESET "\033[0m]"

class	Pmergeme
{
	public:
		Pmergeme();
		Pmergeme(int ac, char **av);
		Pmergeme(const Pmergeme& other);
		Pmergeme& operator = (const Pmergeme& other);
		~Pmergeme();
};

#endif