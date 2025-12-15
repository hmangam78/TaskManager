/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TaskList.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:45:40 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/12/15 16:39:03 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/TaskList.hpp"
#include <string>

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

void    TaskList::loadFromFile(std::ifstream& file)
{
    std::string line, task, tag, status_str, creation_str, completion_str;
    bool status;
    std::chrono::system_clock::time_point creation_date;
    std::optional<std::chrono::system_clock::time_point> completion_date;

    while (std::getline(file, line))
    {
        size_t pos1 = line.find('|');
        size_t pos2 = line.find('|', pos1 + 1);
        size_t pos3 = line.find('|', pos2 + 1);
        size_t pos4 = line.find('|', pos3 + 1);
        
        task = line.substr(0, pos1);
        tag = line.substr(pos1 + 1, pos2 - pos1 - 1);
        status_str = line.substr(pos2 + 1, pos3 - pos2 - 1);
        creation_str = line.substr(pos3 + 1, pos4 - pos3 - 1);
        completion_str = line.substr(pos4 + 1);
        
        status = (status_str == "1");
        creation_date = std::chrono::system_clock::time_point(
            std::chrono::seconds(std::stoll(creation_str))
        );
        
        if (completion_str.empty() || completion_str == "0") {
            completion_date = std::nullopt;
        } else {
            completion_date = std::chrono::system_clock::time_point(
                std::chrono::seconds(std::stoll(completion_str))
            );
        }
        
        Task t(task, tag, status, creation_date, completion_date);
        this->_list.push_back(t);
    }
}

void    TaskList::saveToFile(std::ofstream& file) const
{
    for (const auto& task : this->_list)
    {
        int status = task.get_status() ? 1: 0;
        auto    creation_tp = task.get_date();
        auto    creation_seconds = std::chrono::duration_cast<std::chrono::seconds>(
            creation_tp.time_since_epoch()
        ).count();
        
        auto    comp_date = task.get_completion_date();
        long    comp_seconds = 0;
        if (comp_date.has_value()) {
            comp_seconds = std::chrono::duration_cast<std::chrono::seconds>(
                comp_date.value().time_since_epoch()
            ).count();
        }
        
        file    << task.get_task() << "|"
                << task.get_tag() << "|"
                << status << "|"
                << creation_seconds << "|"
                << comp_seconds << "\n";
    }
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