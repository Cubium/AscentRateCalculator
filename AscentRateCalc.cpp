#include <cmath>
#include <iostream>
#include "termColors.hpp"
#include "ARCfuncs.hpp"

int main()
{
  double chute = 0.33;
  double balloon = 3.8;
  double payload = 6.0;
  double lift = 10.0;

  std::cout << "Enter the following values as floating point numbers in American pounds (lbs)\n";

  std::cout << BOLDWHITE 
    << "\nParachute Weight" << RESET << " (press enter for default of .33 lbs) : ";
  chute = getInput(chute);

  std::cout << BOLDWHITE << "\nBalloon Weight" << RESET << " (press enter for default of 3.8 lbs) : ";
  balloon = getInput(balloon);

  std::cout << BOLDWHITE << "\nPayload Weight" << RESET <<" (press enter for default of 6.0 lbs) : ";
  payload = getInput(payload);

  std::cout << BOLDWHITE << "\nNozzle Lift" << RESET << " (press enter for default of 10.0 lbs) : ";
  lift = getInput(lift);

  auto asc = calcAscent(lift, chute, payload, balloon);

  std::cout << std::endl
            << RED << lift << " lbs" << RESET << " of nozzle lift" << std::endl
            << "will provide " << GREEN << asc << " m/s" << RESET
            << " ascent rate" << std::endl;
}
