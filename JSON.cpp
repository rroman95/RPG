#include "JSON.h"

void JSON::jsonparser(std::ifstream& in)
{
	std::string line;
	std::string key = "";
	char key_sign = '"';
	std::string key_value = "";
	int counter = 0;
	if (!in.good()) { throw  MISSINGFILE; }
	else if (in.good())
	{
		while (!in.eof())
		{
			getline(in, line);
			for (unsigned int i = 0; i < line.size() && counter < 2; i++) //FINDING KEY
			{
				if (line[i] == key_sign)
					counter++;
				if (counter == 1 && (isalpha(line[i]) || isdigit(line[i])))
					key += line[i];
			}
			unsigned int find = 0;
			find = line.find(key) + key.size() + 1;
			for (unsigned int i = find; i < line.size(); i++) //FINDING KEY_VALUE
			{
				if (isalpha(line[i]) || isdigit(line[i]) || line[i] == '.')
					key_value += line[i];

			}
			if (key.size() != 0 && key_value.size() != 0)
				charData.insert(std::pair<std::string, std::string>(key, key_value));// std::cout << key << " " << key_value << " inserted\n";
			counter = 0;
			key = "";
			key_value = "";
		}
	}
}

JSON::JSON(std::ifstream& mystream)
{
	jsonparser(mystream);
}

JSON::JSON(std::string& argstring)
{
	std::ifstream in(argstring);
	jsonparser(in);
}

JSON::JSON(const char* charin)
{
	std::ifstream in(charin);
	jsonparser(in);
}
