/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oallan <oallan@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 21:14:48 by oallan            #+#    #+#             */
/*   Updated: 2024/09/18 21:14:51 by oallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/head.hpp"

static int checker(const str cmd, const str arg)
{
    if (!arg.compare(cmd))
        return 0;
    else
        return 1;
}

int main()
{
    PhoneBook PhoneBook;
    str line;
    system("clear");
    while(1)
    {
        std::cout << "\033[44;37m"
        << "---------------- CONTACT MANAGER ----------------" << std::endl
        << "COMMANDS TO USE: " << std::setw(10) << "(1. ADD)" \
        << std::setw(10) << " (2. SEARCH) " << std::setw(10) << "(3. EXIT)" "\033[0m" << std::endl;
        std::cout <<  "\033[32m" << "ENTER COMMAND: " << "\033[0m";
        std::getline(std::cin, line);
        if (std::cin.eof())
        {
            std::cout << std::endl;
            break;
        }
        if (!checker(line, "ADD"))
            PhoneBook.add_contacts();
        else if (!checker(line, "SEARCH"))
            PhoneBook.search_contacts();
        else if (!checker(line, "EXIT"))
        {
            std::cout << "EXITING..." <<std::endl;
            sleep(1);
            break;
        }
        else if (checker(line, "ADD") || checker(line, "SEARCH") || checker(line, "EXIT"))
        {
            std::cout << "\033[31m" << "Error: Invalid command. Please use the provided commands." << "\033[0m" << std::endl;
            sleep(1);
            system("clear");
        }
        system("clear");
    }
    return 0;
}
