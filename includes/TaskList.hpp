/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TaskList.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:37:31 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/12/15 15:15:33 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Task.hpp"
#include <iomanip>
#include <vector>

class   TaskList
{
    private:
        std::vector<Task>   _list;
    public:
        TaskList(void);
        ~TaskList(void);
        void    addToList(Task& new_task);
        void    deleteTask(size_t index);
    
    //getters
        Task    getTask(size_t index) const;
    //Display tasks
        void    displayTasks(void) const; 
    
};

std::ostream& operator<<(std::ostream& os, const Task& task);