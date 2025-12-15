/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:29:57 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/12/15 19:32:58 by hgamiz-g         ###   ########.fr       */
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

    std::ifstream   infile("tasks.csv");
    TaskList    list;
    if (infile.is_open())
    {
        list.loadFromFile(infile);
        infile.close();
    }
    else
        std::cout << "Creating new task file..." << std::endl;

    t_command input;
    if (!parse_command(argv, &input))
    {
        std::cout << "Invalid command, execute ./taskmanager for help" << std::endl;
        return (1);
    }
    if (input.command == "add")
        add_task(argv, list);
    else if (input.command == "delete")
        std::cout << "delete" << std::endl;
    else if (input.command == "complete")
        std::cout << "complete" << std::endl;
    else if (input.command == "view")
        std::cout << "view" << std::endl;

    std::ofstream   outfile("tasks.csv");
    if (outfile.is_open())
    {
        list.saveToFile(outfile);
        outfile.close();
        std::cout << "Tasks saved to tasks.csv" << std::endl;
    }
    else
        std::cerr << "Error: Could not save to tasks.csv" << std::endl;
    
    return (0);
}