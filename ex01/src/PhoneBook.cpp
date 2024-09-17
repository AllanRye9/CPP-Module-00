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
    std::getline(std::cin, name);
    system("clear");
    std::cout << "Type Surname name: ";
    std::getline(std::cin, last);
    system("clear");
    std::cout << "Nickname: ";
    std::getline(std::cin, nick);
    system("clear");
    std::cout << "Phone number: ";
    std::getline(std::cin, phone);
    system("clear");
    std::cout << "Type Darkest Secrets: ";
    std::getline(std::cin, secret);
    system("clear");
    this->array[this->current_nb].setName(name);
    this->array[this->current_nb].setNick(nick);
    this->array[this->current_nb].setPhone(phone);
    this->array[this->current_nb].setLast(last);
    this->array[this->current_nb].setSecret(secret);
    this->current_nb++;
    if (this->current_nb < 8)
        this->contact_nb++;
}

static void drawLine(int l)
{
    for (int i = 0; i < l; i++)
    {
        std::cout << "-";
    }
    std::cout << std::endl;
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
    std::cout << std::setw(15) << "First Name" << "|";
    std::cout << std::setw(15) << "Last Name" << "|";
    std::cout << std::setw(15) << "Nick Name" << "|" << std::endl;
    drawLine(54);
    std::cout << std::endl;
    while(i < contact_nb)
    {
        std::cout << std::setw(5) << i << "|";
        name = this->array[i].getName();
        last = this->array[i].getLast();
        nick = this->array[i].getNick();
        phone = this->array[i].getPhone();
        secret = this->array[i].getSecret();
        if (name.length() > 9)
            name = name.substr(0, 9) + ".";
        if (last.length() > 9)
            last = last.substr(0, 9) + ".";
        if (nick.length() > 9)
            nick = nick.substr(0, 9) + ".";
        std::cout << std::setw(15) << name << "|";
        std::cout << std::setw(15) << last << "|";
        std::cout << std::setw(15) << nick << "|" << std::endl;
        i++;
    }
    drawLine(54);
    std::cout << std::setw(10) << "Press the index and Enter: " << std::endl;
    std::getline(std::cin, ret);
    x = atoi(ret.c_str());
    if (ret[0] == '\0' || (x < 0 && x == -2147483648) || (x > 0 && x <= 2147483647) || \
        !std::isdigit(ret.c_str()))
    {    std::cout << "Please Enter a valid Digit !" << std::endl; sleep(1); return;}
    else if (x >= this->current_nb)
    {    std::cout << "Contact Not Found ! | Aborting ..." << std::endl; sleep(1); return;}
    drawLine(50);
    std::cout << "Name:         " << this->array[x].getName() << std::endl;
    std::cout << "Last Name:    " << this->array[x].getLast() << std::endl;
    std::cout << "Nick Name:    "<< this->array[x].getNick() << std::endl;
    std::cout << "Phone No:     " << this->array[x].getPhone() << std::endl;
    std::cout << "Secret:       " << this->array[x].getSecret() << std::endl;
    drawLine(50);
    std::cout << "..........Press Any Key to Go Back Home ............" << std::endl;
    getchar();
    getchar();
}