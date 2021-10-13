#include <vector>
#include <cstdint>
#include <cmath>
#include <iostream>

void powers_of_two(int n) {
  std::vector<uint64_t> tab;
  int i(0);
  while (i < n)
  {
	tab.push_back(pow(2, i));
	std::cout<< tab[i]<<std::endl;
	i++;
  }
  //return tab;
}

int main()
{
	powers_of_two(3);
	return 0;
}
