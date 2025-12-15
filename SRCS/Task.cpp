/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Task.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:21:32 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/12/15 16:28:03 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Task.hpp"

Task::Task(const std::string& task, const std::string& tag, bool status,std::chrono::system_clock::time_point creation_date, 
           std::optional<std::chrono::system_clock::time_point> completion_date)
{
    _task = task;
    _tag = tag;
    _completed = status;
    _creation_date = creation_date;
    _completion_date = completion_date;
}
     
Task::Task(const std::string& task, const std::string& tag)
{
    _task = task;
    _tag = tag;
    _completed = false;
    _creation_date = std::chrono::system_clock::now();
    _completion_date = std::nullopt;
}

Task::Task(const Task& other)
{
    _task = other._task;
    _tag = other._tag;
    _completed = false;
    _creation_date = std::chrono::system_clock::now();
    _completion_date = std::nullopt;
}

Task::~Task() {}

Task& Task::operator=(const Task& other)
{
    if (this != &other)
    {
        _task = other._task;
        _tag = other._tag;
        _completed = false;
        _creation_date = std::chrono::system_clock::now();
        _completion_date = std::nullopt;
    }
    return (*this);
}

std::string Task::get_task(void) const
{
    return (this->_task);
}

std::string Task::get_tag(void) const
{
    return (this->_tag);
}

bool        Task::get_status(void) const
{
    return (this->_completed);
}

std::chrono::system_clock::time_point Task::get_date(void) const
{
    return (this->_creation_date);
}

std::optional<std::chrono::system_clock::time_point> Task::get_completion_date(void) const
{
    return (this->_completion_date);
}

void        Task::complete(void)
{
    this->_completed = true;
}

std::ostream& operator<<(std::ostream& os, const Task& task)
{
    std::chrono::year_month_day ymd(
        std::chrono::time_point_cast<std::chrono::days>(task.get_date())
    );

    os  << std::setw(30) << task.get_task() << " | "
        << std::setw(8) << task.get_tag() << " | "
        << std::setw(10) << ymd << " | ";
    if (task.get_status() == true)
        os << "Completed";
    else
        os << "Not completed";
    return (os);
}