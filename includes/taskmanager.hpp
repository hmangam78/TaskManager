/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taskmanager.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:13:48 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/12/15 19:33:42 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../includes/Task.hpp"
#include "../includes/TaskList.hpp"
#include <fstream>

typedef struct s_command
{
    std::string command;
    std::string args;
    std::string tag;
}   t_command;

bool    parse_command(char **argv, t_command *command);
void    displayOptions(void);
void    add_task(char** argv, TaskList& list);