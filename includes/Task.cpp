/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Task.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 12:09:29 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/12/14 12:30:47 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>
#include <chrono>

class	Task
{
	private:
		int			_id;
		std::string	_task;
		std::string	_tag;
		auto		_creation_date;
		auto		_completion_date;
	public:
		Task(std::string task, std::string tag);
		Task(const Task& other);
		~Task();
		Task& operator=(const Task& other);
		//getters and setters
		std::string	




};