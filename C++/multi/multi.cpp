#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n(3);
	int x(0);
	int y(0);
	unsigned long i(1);
	vector<vector<int> > tab;
	vector<int> line;
	while (x < n)
	{
		while (y < n)
		{
			line.push_back(i * (x + 1)); 
			i++;
			y++;
		}
		tab.push_back(line);
		x++;
		line.clear();
		i = 1;
		y = 0;
	}
	for(unsigned long j=0;j<tab.size();j++)
	{
		for(i=0;i<tab[i].size();i++)
		{
			cout<<tab[j][i]<<endl;
		}
	}
	return 0;
}
