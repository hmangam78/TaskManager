/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Task.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 12:09:29 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/12/15 15:15:24 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <chrono>

class	Task
{
	private:
		std::string	_task;
		std::string	_tag;
		std::chrono::system_clock::time_point	_creation_date;
		std::optional<std::chrono::system_clock::time_point>	_completion_date;
		bool		_completed;

	public:
		Task(const std::string& task, const std::string& tag);
		Task(const Task& other);
		~Task();
		Task& operator=(const Task& other);

		//getters and setters
		std::string	get_task(void) const;
		std::string get_tag(void) const;
		bool		get_status(void) const;
		std::chrono::system_clock::time_point get_date(void) const;
		void		complete(void);
};