#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

std::string getCode(const std::string& nick, unsigned long long int exp)
{
	std::stringstream code;

	auto sz = nick.size();
	auto SB = ((sz * exp) % (exp + 1)) + 1;
	auto sum1 = 1;
	auto sum2 = 1;
	auto lw = nick;
	transform(lw.begin(), lw.end(), lw.begin(), ::tolower);
	for (size_t i = 0; i < sz; i++)
	{
		auto cur = lw[i];
		if (cur == 'a' || cur == 'e' || cur == 'g')
		{
			sum1 += 2;
			sum2 = (sum2 + 1) * sum1;
		}
		else if (cur == 'm' || cur == 'n' || cur == 'l')
		{
			sum1 = (sum1 + 1) * 3 - 1;
			sum2 = sum2 + sum1;
		}
		else if (cur == '1' || cur == '7' || cur == '9')
		{
			sum1 = sum1 + sum2;
			sum2 = sum2 + 4;
		}
	}
	int res = ((exp + sum1) * (SB - sum2)) % (8999) + 1000;

	code << res << exp;
	return code.str();
}

int main()
{
	std::string nick;
	unsigned long long int exp = 10000;//1e4
	std::cout << "Hi! This program will generate the code for " << exp << " experience points in Terrania (Warcraft III: The Frozen Throne) game.\nAt the start of the game type -load <YOUR_CODE>\n\n";
	std::cout << "Write your nickname: ";
	std::cin >> nick;

	std::cout << "Your code is: " << getCode(nick, exp) << "\n\n";
	std::cin.get();
	system("pause");
}
