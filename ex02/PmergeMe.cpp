/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 01:32:06 by asaber            #+#    #+#             */
/*   Updated: 2024/05/11 22:47:17 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

Pmergeme::Pmergeme()
{
	std::cout << "just a default constracter!!" << std::endl;
}

Pmergeme::Pmergeme(const Pmergeme& other)
{
	(void)other;
}

Pmergeme& Pmergeme::operator = (const Pmergeme& other)
{
	(void)other;
	return *this;
}

template <typename T>
void	display(T& conatiner)
{
	typename T::iterator it;
	for(it = conatiner.begin(); it != conatiner.end(); ++it) std::cout <<*it << " ";
	std::cout << std::endl;
}

void check_atoi(long long nbr, std::string av, bool error)
{
	if (nbr <= 0 || nbr > INT_MAX || error)
	{
		std::cerr << "fatal: invalid input value \"" << av << "\" try agin !!" << std::endl;
		exit(1);
	}
}

template <typename T>
void split(T& res, std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    long long token;
	std::string tmp_sub;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
		tmp_sub = s.substr(pos_start, pos_end - pos_start);
		if (tmp_sub.length() > 10)
			check_atoi(1, tmp_sub, 1);
        token = std::stoll(tmp_sub);
		check_atoi(token, tmp_sub, 0);
		pos_start = pos_end + delim_len;
        res.push_back (token);
    }
	tmp_sub = s.substr (pos_start);
	if (tmp_sub.length() > 10)
			check_atoi(1, tmp_sub, 1);
	token = std::stoll(tmp_sub);
	check_atoi(token, tmp_sub, 0);
    res.push_back (token);
}

template <typename T>
void	fill_conatiner(int ac, char **av, T& container)
{
	for(int i = 1; i < ac; i++) split(container, av[i], " ");
}

void Vector_sort_and_merge(std::vector<int>& container)
{
	std::vector<int>::iterator it1;
	std::vector<int>::iterator it2;
	int tmp;

	for(it1 = container.begin() + 1; it1 != container.end(); ++it1)
	{
		tmp = *it1;
		it2 = it1;
		while (it2 != container.begin() && *(std::prev(it2)) > tmp)
		{
			*it2 = *(std::prev(it2));
			std::advance(it2, -1);
		}
		*it2 = tmp;
	}
}
void Deque_sort_and_merge(std::deque<int>& container)
{
	std::deque<int>::iterator it1;
	std::deque<int>::iterator it2;
	int tmp;

	for(it1 = container.begin() + 1; it1 != container.end(); ++it1)
	{
		tmp = *it1;
		it2 = it1;
		while (it2 != container.begin() && *(std::prev(it2)) > tmp)
		{
			*it2 = *(std::prev(it2));
			std::advance(it2, -1);
		}
		*it2 = tmp;
	}
}


Pmergeme::Pmergeme(int ac, char **av)
{
	std::deque<int> listDeque;
	std::vector<int> listVector;
	fill_conatiner(ac, av, listDeque);
	fill_conatiner(ac, av, listVector);
	std::cout << "Before : ";
	display(listVector);
	clock_t start = clock();
	Deque_sort_and_merge(listDeque);
	std::cout << "After : ";
	display(listDeque);
	clock_t end = clock();
	double diff = (end - start) * 1000.0 / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << listDeque.size() << " elements with std::deque : " << diff << " us\n";
	start = clock();
	Vector_sort_and_merge(listVector);
	end = clock();
	diff = (end - start) * 1000.0 / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << listVector.size() << " elements with std::Vector : " << diff << " us\n";
}

Pmergeme::~Pmergeme()
{
	
}