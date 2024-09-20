/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oallan <oallan@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 21:14:33 by oallan            #+#    #+#             */
/*   Updated: 2024/09/18 21:14:36 by oallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/head.hpp"

PhoneBook::PhoneBook(): max_contacts(8), current_nb(0), contact_nb(0){}

PhoneBook::~PhoneBook(){}

static int isSpace(const str input)
{
    int i = 0;

    while (input[i] && (input[i] == ' ' || input[i] == '\t' || input[i] == '\n') && !(input[i + 1] >= 33 && input[i + 1] <= 126))
    {
        return 1;
        i++;
    }
    return 0;
}

static int isValidInput(const str input) {
    int i = 0;

    if (input.size() <= 0)
        return 1;
    while(input[i])
    {
        if (isSpace(input))
            return 1;
        else
            i++;
    }
    return 0;
}

static int readInput(str output)
{
    if (std::cin.eof())
    {
        std::cout << std::endl;
        exit(0);
    }
    if (output.size() <= 0)
        return 0;
    if (isValidInput(output)) {
        return 0;
    } 
    return 1;
}

static void errorMessage(void)
{
    std::cout << "\033[31m" << "Error: Input cannot be empty or contain spaces, tabs, or new lines." << "\033[0m" << std::endl;
}

static void displaySuccess(void)
{
    std::cout << "\033[32m" << "Contact Added Successfully!" << "\033[0m" << std::endl;
}

static int isNumeric(str s)
{
    int i = 0;
    if (s.size() == 0 || s.size() > 15)
        return 1;
    while(s[i])
    {
        if (!(s[i] >= '0' && s[i] <= '9' && isSpace(s)))
            return 1;
        i++;
    }
    return 0;
}

int PhoneBook::add_contacts()
{
    str name;
    str last;
    str secret;
    str nick;
    str phone;
    int value = 0;

    if (current_nb >= max_contacts)
        current_nb = 0;
    system("clear");
    while (!value)
    {
        std::cout << "Type First name: ";
        std::getline(std::cin, name);
        value = readInput(name);
        if (value)
            break;
        else
            errorMessage();
    }
    displaySuccess();
    value = 0;
    while (!value)
    {
        std::cout << "Type Surname name: ";
        std::getline(std::cin, last);
        value = readInput(last);
        if (value)
            break;
        else
            errorMessage();
    }
    displaySuccess();
    value = 0;
    while (!value)
    { 
        std::cout << "Type Nick name: ";
        std::getline(std::cin, nick);
        value = readInput(nick);
        if (value)
            break;
        else
            errorMessage();
    }
    displaySuccess();
    value = 0;
    while (!value)
    {
        std::cout << "Type Phone Number: ";
        std::getline(std::cin, phone);
        value = readInput(phone);
        if (value)
        {
            displaySuccess();
            break;
        }
        if (!value && isNumeric(phone))
        {
            std::cout << "\033[31m" << "Error: Phone number must be numeric." << "\033[0m" << std::endl;
            value = 0;
        }
    }
    value = 0;
    while (!value)
    {
        std::cout << "Type Darkest Secret: ";
        std::getline(std::cin, secret);
        value = readInput(secret);
        if (value)
            break;
        else
            errorMessage();
    }
    displaySuccess();
    this->array[this->current_nb].setName(name);
    this->array[this->current_nb].setNick(nick);
    this->array[this->current_nb].setPhone(phone);
    this->array[this->current_nb].setLast(last);
    this->array[this->current_nb].setSecret(secret);
    this->current_nb++;
    if (contact_nb < max_contacts)
        contact_nb++;
    sleep(1);
    system("clear");
    return 0;
}

static void drawLine(int l)
{
    for (int i = 0; i < l; i++)
    {
        std::cout << "-";
    }
    std::cout << std::endl;
}

static int validator(str s, int x)
{
    int i = 0;
    if (!s[0])
        return 1;
    while(s[i])
    {
        if (s[0] == '\0' || (x < 0 && x == -2147483648) || (x > 7 && x >= 2147483647) 
            || !(s[i] >= '0' && s[i] <= '9') || s[i] == ' ' || s[i] == '\t')
            return 1;
        i++;
    }
    return 0;
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
    drawLine(44);
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nick Name" << "|" << std::endl;
    drawLine(44);
    std::cout << std::endl;
    while(i < contact_nb)
    {
        std::cout << std::setw(10) << i << "|";
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
        std::cout << std::setw(10) << name << "|";
        std::cout << std::setw(10) << last << "|";
        std::cout << std::setw(10) << nick << "|" << std::endl;
        i++;
    }
    drawLine(44);
    std::cout << std::setw(10) << "Press the index and Enter: " << std::endl;
    std::getline(std::cin, ret);
    x = atoi(ret.c_str());
    if (validator(ret, x))
    {std::cout << "Please Enter a valid Digit !" << std::endl; sleep(1); return;}
    else if (x >= this->contact_nb)
    {std::cout << "Contact Not Found ! | Aborting ..." << std::endl; sleep(1); return;}
    drawLine(44);
    std::cout << "First Name    :   "<< this->array[x].getName()<<std::endl;
    std::cout << "Last Name     :   "<< this->array[x].getLast()<< std::endl;
    std::cout << "Nick Name     :   "<< this->array[x].getNick()<< std::endl;
    std::cout << "Phone No      :   "<< this->array[x].getPhone()<< std::endl;
    std::cout << "Darkest Secret:   "<< this->array[x].getSecret()<< std::endl;
    drawLine(44);
    std::cout << "......Press Any Key to Go Back Home ........" << std::endl;
    getchar();
    getchar();
}
