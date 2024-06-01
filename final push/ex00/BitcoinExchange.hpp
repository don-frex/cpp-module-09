/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:55:38 by asaber            #+#    #+#             */
/*   Updated: 2024/05/19 21:36:24 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP


#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <map>

#define ICYAN "\033[1;33m"
#define RESET "\033[0m"

class bitcoin_data
{
	private:
		std::map<std::string, float> databtc;
	public:
		bitcoin_data();
		bitcoin_data(std::map<std::string, float> o_databtc);
		bitcoin_data(const bitcoin_data& other);
		bitcoin_data& operator = (const bitcoin_data& other);
		~bitcoin_data();
		void set_data(std::string data, float value);
		void start(std::string input_file);
		void print_data();
		float search_date(std::string date);
		
};

#endif