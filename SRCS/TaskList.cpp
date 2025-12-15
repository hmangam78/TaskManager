/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TaskList.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:45:40 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/12/15 15:10:24 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/TaskList.hpp"

TaskList::TaskList(void) {}

TaskList::~TaskList(void) {}

void    TaskList::addToList(Task& new_task)
{
    this->_list.push_back(new_task);
}
void    TaskList::deleteTask(size_t index)
{
    if (index < this->_list.size())
        this->_list.erase(this->_list.begin() + index); 
}

Task    TaskList::getTask(size_t index) const
{
    return (this->_list[index]);
}

void    TaskList::displayTasks(void) const
{
    std::cout   << std::right
                << std::setw(3) << "Id" << " | "
                << std::setw(30) << "Task" << " | "
                << std::setw(8) << "Tag" << " | "
                << std::setw(10) << "Insertion" << " | "
                << std::setw(10) << "Status" << std::endl;
    for (size_t i = 0; i < this->_list.size(); i++)
        std::cout << std::setw(3) << i << " | " << this->getTask(i) << std::endl;
}