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
  double lift_min, lift_max, chute, payload, balloon = 0;

  std::cout << "Parachute Weight (.33 lbs) : ";
  std::cin >> chute;
  std::cout << "Balloon Weight (3.8 lbs) : ";
  std::cin >> balloon;
  std::cout << "Payload Weight (lbs) : ";
  std::cin >> payload;
  std::cout << "Estimate MAX Balloon Lift (lbs) : ";
  std::cin >> lift_max;

  calcAscent(lift, chute, payload, balloon);

  while (true)
  {
    char ch;
    std::cin >> ch;
    if (ch == 'm')
      lift += .1;
    else if (ch == 'l')
      lift -= .1;
    else if (ch == 'e')
      break;

    std::cout << "lift : " << lift << std::endl;
    calcAscent(lift, chute, payload, balloon);
  }
}
