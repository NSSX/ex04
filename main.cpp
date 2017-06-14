#include "Fixed.class.hpp"
#include <iostream>
#include <cstdlib>

Fixed	getNumber(char **calcul)
{
	Fixed nbr;

	if (**calcul == '(')
	{
		(*calcul)++;
		nbr = inOperation(calcul);
		if (**calcul == ')')
			(*calcul)++;
		return (nbr);
	}

    std::string chaine = "";

    while(**calcul == '.' || ( **calcul >= '0' && **calcul <= '9')){
        chaine = chaine + **calcul;
        (*calcul)++;
    }

    float myFloat = std::atof(chaine.c_str());
    nbr = Fixed(myFloat);
    return(nbr);

}

Fixed	inOperation(char **calcul)
{
	Fixed		nbr;
	Fixed	    nbr2;
	char	caractere;

	nbr = getNumber(calcul);
	while (**calcul)
	{
		caractere = **calcul;
		if (caractere != '+' && caractere != '-' && caractere != '/' && caractere != '*'){
            return (nbr);
        }
		(*calcul)++;
		nbr2 = getNumber(calcul);
		if (caractere == '+')
			nbr = nbr + nbr2;
		else if(caractere == '-')
			nbr = nbr - nbr2;
        else  if (caractere == '/')
            nbr =  nbr / nbr2;
        else
            nbr = nbr * nbr2;
	}
	return (nbr);
}

void RemoveSpaces(char* source)
{
  char* i = source;
  char* j = source;
  while(*j != 0)
  {
    *i = *j++;
    if(*i != ' ')
      i++;
  }
  *i = 0;
}

Fixed	calculate(char *calcul)
{
    RemoveSpaces(calcul);
	return (inOperation(&calcul));
}

int		main(int argc, char **argv)
{
	if (argc > 1)
	{
        std::cout << calculate(argv[1]) << std::endl;
	}
    else{
        std::cout << "Bad Argument try : `(18.18 + 3.03) * 2`" << std::endl;
    }
	return (0);
}
