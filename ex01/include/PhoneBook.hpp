#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "../include/head.hpp"

class PhoneBook
{
    private:
        const int   max_contacts;
        int         current_nb;
        int         contact_nb;
        int         array[8];
    public:
        PhoneBook();
        ~PhoneBook();
        void add_contacts();
        void search_contacts();
};
#endif