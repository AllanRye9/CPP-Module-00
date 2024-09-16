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