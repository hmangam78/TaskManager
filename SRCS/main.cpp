/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:29:57 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/12/15 16:45:26 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/taskmanager.hpp"

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        displayOptions();
        return (0);
    }

    std::ifstream   file("tasks.csv");
    if (!file.is_open())
        std::cout << "Error opening file" << std::endl;
        
    TaskList    list;
    list.loadFromFile(file);
    
    std::string command = argv[1];
    if (command == "add")
        add_task(argv, list);
    else if (command == "delete")
        std::cout << "delete" << std::endl;
    else if (command == "complete")
        std::cout << "complete" << std::endl;
    else if (command == "view")
        std::cout << "view" << std::endl;
    else
        displayOptions();
    
    return (0);
}