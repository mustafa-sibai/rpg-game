#include "MapLoader.h"
#include <fstream>
#include <string>

void MapLoader::Load(std::string filename)
{
	std::string line;
	std::ifstream file(filename);

	bool isMapValid = false;

	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			if (!isMapValid)
			{
				if (line == "[Map]")
				{
					isMapValid = true;
					continue;
				}
				else
				{
					std::cout << "rmap file is not valid" << std::endl;
					break;
				}
			}

			if (isMapValid)
			{
				int count = line.find('=');
				std::string varaible = line.substr(0, count); //substr 
				std::string value = line.substr(count + 1, line.length() - count);

				std::cout << "My varailbe is called " << varaible << std::endl;
				std::cout << "My value is " << value << std::endl;

				break;
			}
		}

		file.close();
	}
	else
	{
		std::cout << "Unable to open " << filename << std::endl;
	}
}