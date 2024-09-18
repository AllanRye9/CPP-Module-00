/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oallan <oallan@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 21:11:20 by oallan            #+#    #+#             */
/*   Updated: 2024/09/18 21:11:31 by oallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
    int i, j;

    i = 0;
    j = 0;

    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    while(++i < ac)
    {
        j = 0;
        while(av[i][j])
        {
            std::cout << (char) toupper(av[i][j]);
            j++;
        }
    }
    std::cout << std::endl;
}
