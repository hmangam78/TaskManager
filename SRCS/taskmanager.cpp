/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taskmanager.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:14:11 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/12/15 19:36:32 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/taskmanager.hpp"

bool    valid_command(char *str)
{
    std::string input_command = str;
    if ((input_command != "add") && (input_command != "view") &&
        (input_command != "delete") && (input_command != "complete"))
        return (false);
    return (true);
}

bool    parse_command(char **argv, t_command *command)
{
    if (!valid_command(argv[1]))
    {
        command = NULL;
        return (false);
    }
    command->command = argv[1];

    return (true);
}

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