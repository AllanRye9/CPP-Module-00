#include "../include/head.hpp"

PhoneBook::PhoneBook(): max_contacts(8), current_nb(0), contact_nb(0){}

PhoneBook::~PhoneBook(){}

void PhoneBook::add_contacts()
{
    str name;
    str last;
    str secret;
    str nick;
    str phone;

    system("clear");
    if (this->current_nb == 8)
        this->current_nb = 0;
    system("clear");
    std::cout << "Type name: ";
    std::cin >> name;
    system("clear");
    std::cout << "Type Surname name: ";
    std::cin >> last;
    system("clear");
    std::cout << "Nickname: ";
    std::cin >> nick;
    system("clear");
    std::cout << "Phone number: ";
    std::cin >> phone;
    system("clear");
    std::cout << "Type Darkest Secrets: ";
    std::cin >> secret;
    system("clear");
    this->array[this->current_nb].setName(name);
    this->array[this->current_nb].setNick(name);
    this->array[this->current_nb].setPhone(name);
    this->array[this->current_nb].setLast(name);
    this->array[this->current_nb].setSecret(name);
    this->current_nb++;
    if (this->current_nb < 8)
        this->contact_nb++;
}

void PhoneBook::search_contacts()
{
    str name;
    str last;
    str secret;
    str nick;
    str phone;
    int i = 0;
    str ret;
    int x;

    system("clear");
    if (this->current_nb == 0)
    {
        std::cout << "No Contact Found | Aborting ..." << std::endl; sleep(1); return ;
    }
    std::cout << std::setw(5) << "Index" << "|";
    std::cout << std::setw(5) << "First Name" << "|";
    std::cout << std::setw(5) << "Last Name" << "|";
    std::cout << std::setw(5) << "Nick Name" << std::endl;

    while(i < contact_nb)
    {
        std::cout << std::setw(5) << i << "|";
        name = this->array[i].getName();
        last = this->array[i].getLast();
        nick = this->array[i].getNick();
        phone = this->array[i].getPhone();
        secret = this->array[i].getSecret();
        i++;
    }
}