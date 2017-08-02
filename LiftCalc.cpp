#include "termColors.hpp"
#include "ARCfuncs.hpp"
#include <iostream>

int main()
{  
  double chute = 0.33;
  double balloon = 3.8;
  double payload = 6.0;
  double lift_min = 0.0;
  double lift_max = 10.0;
  double ascent_target = 7.0;

  std::cout << "Enter the following values as floating point numbers in American pounds (lbs)\n";

  std::cout << BOLDWHITE 
    << "\nParachute Weight" << RESET << " (press enter for default of .33 lbs) : ";
  chute = getInput(chute);

  std::cout << BOLDWHITE << "\nBalloon Weight" << RESET << " (press enter for default of 3.8 lbs) : ";
  balloon = getInput(balloon);

  std::cout << BOLDWHITE << "\nPayload Weight" << RESET <<" (press enter for default of 6.0 lbs) : ";
  payload = getInput(payload);

  std::cout << BOLDWHITE << "\nEstimate maximum balloon lift" << RESET << " (press enter for default of 10.0 lbs) : ";
  lift_max = getInput(lift_max);

  std::cout << BOLDWHITE << "\nEstimate minimum balloon lift" << RESET << " (press enter for default of 0.0 lbs) : ";
  lift_min = getInput(lift_min);

  std::cout << BOLDWHITE << "\nTarget ascent rate" << RESET << " (press enter for default of 7 m/s) : ";
  ascent_target = getInput(ascent_target);

  double lift_med, asc;
  // for (int i = 0; i < 20; ++i)
  do
  {
    lift_med = (lift_min + lift_max) / 2;
    asc = calcAscent(lift_med, chute, payload, balloon);

    if (asc > ascent_target)
      lift_max = lift_med;
    else if (asc < ascent_target)
      lift_min = lift_med;

  } while (fabs(ascent_target - asc) >= .001);

  std::cout << std::endl
            << RED << lift_med << " lbs" << RESET
            << " of nozzle lift are required" << std::endl
            << "to achieve " << GREEN << asc << " m/s" << RESET
            << " ascent rate" << std::endl;
}
