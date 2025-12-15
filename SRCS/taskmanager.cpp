/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taskmanager.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:14:11 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/12/15 16:37:34 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/taskmanager.hpp"

void    displayOptions(void)
{
    std::cout << "Options" << std::endl;
}

void    add_task(char **argv, TaskList& list)
{
    std::string task_string;

    for (int i = 2; argv[i] != NULL; i++)
    {
        task_string += argv[i];
        if (argv[i + 1] != NULL)
            task_string.append(" ");
    }
    Task        new_task(task_string, "test");
    list.addToList(new_task);
    list.displayTasks();
}