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

int main()
{
    PhoneBook PhoneBook;

    str line;
    str add = "ADD";
    str search = "SEARCH";
    str exit = "EXIT";
    system("clear");
    std::cout << "---------------- CONTACT MANAGER ----------------" << std::endl;
    while(1)
    {
        std::cout << "COMMANDS TO USE:" << std::setw(10) << "(1. ADD)" \
        << std::setw(10) << " (2. SEARCH) " << std::setw(10) << "(3. EXIT)" << std::endl;
        std::getline(std::cin, line);
        if (!line.compare(add))
            PhoneBook.add_contacts();
        else if (!line.compare(search))
            PhoneBook.search_contacts();
        else if (!line.compare(exit))
        {
            std::cout << "EXITING..." <<std::endl;
            break;
        }
        system("clear");
    }
    sleep(1);
    return 0;
}
