#ifndef ARCFUNCS
#define ARCFUNCS

#include <cmath>
#include <iostream>
#include <sstream>

double getInput(double defaultVal)
{
  double value = defaultVal;
  std::string input;
  std::getline(std::cin, input);
  if (!input.empty())
  {
    std::istringstream stream(input);
    stream >> value;
  }
  return value;
}

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

#endif
