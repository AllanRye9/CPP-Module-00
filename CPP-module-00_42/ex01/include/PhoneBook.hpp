/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oallan <oallan@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 21:13:26 by oallan            #+#    #+#             */
/*   Updated: 2024/09/18 21:13:31 by oallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "../include/head.hpp"

class PhoneBook
{
    private:
        const int   max_contacts;
        int         current_nb;
        int         contact_nb;
        Contact     array[8];
    public:
        PhoneBook();
        ~PhoneBook();
        int add_contacts();
        void search_contacts();
};
#endif
