#include "termColors.hpp"
#include <cmath>
#include <iostream>

double calcAscent(double lift, double chute, double payload, double balloon)
{
  double top = 465.878 * sqrt((lift * 454.0) -
                              ((chute / 16.0 * 454.0) + (payload * 454.0)));
  double bot =
    pow(((lift * 454.0) - ((chute / 16.0 * 454.0) + (payload * 454.0))) +
          balloon + (payload * 454) + (chute / 16.0 * 454.0),
        1.0 / 3.0);

  double ft_min = top / bot;
  double m_s = ft_min * .00508;

  return m_s;
}

int main()
{
  double lift_min, lift_max, chute, payload, balloon, ascent_target = 0;

  std::cout << "Parachute Weight (.33 lbs) : ";
  std::cin >> chute;
  std::cout << "Balloon Weight (3.8 lbs) : ";
  std::cin >> balloon;
  std::cout << "Payload Weight (lbs) : ";
  std::cin >> payload;
  std::cout << "Estimate MAX Balloon Lift (lbs) : ";
  std::cin >> lift_max;
  std::cout << "Estimate MIN Balloon Lift (lbs) : ";
  std::cin >> lift_min;
  std::cout << "Target Ascent Rate (m/s) : ";
  std::cin >> ascent_target;

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
