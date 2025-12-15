/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taskmanager.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:13:48 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/12/15 16:39:35 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../includes/Task.hpp"
#include "../includes/TaskList.hpp"
#include <fstream>

void    displayOptions(void);
void    add_task(char** argv, TaskList& list);