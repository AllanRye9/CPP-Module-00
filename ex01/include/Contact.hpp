#ifndef CONTACT_H
#define CONTACT_H

#include "../include/head.hpp"

class Contact
{
    private:
        str name;
        str last;
        str secret;
        str nick;
        str phone;
    public:
        Contact();
        ~Contact();
        void setName(str name);
        void setLast(str last);
        void setNick(str nick);
        void setPhone(str phone);
        void setSecret(str secret);
        str     getName() const;
        str     getLast() const;
        str     getNick() const;
        str     getPhone() const;
        str     getSecret() const;      
};

#endif