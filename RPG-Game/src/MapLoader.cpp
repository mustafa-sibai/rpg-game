#include "MapLoader.h"
#include <fstream>
#include <string>

void MapLoader::Load(std::string filename, MapData& mapData)
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
				try
				{
					int count = line.find('=');
					std::string varaible = line.substr(0, count);
					std::string value = line.substr(count + 1, line.length() - count);

					if (varaible == "version")
					{
						mapData.version = std::stoi(value);
					}
					else if (varaible == "tilesheet")
					{
						mapData.tilesheet = value;
					}
					else if (varaible == "name")
					{
						mapData.name = value;
					}
					else if (varaible == "mapWidth")
					{
						mapData.mapWidth = std::stoi(value);
					}
					else if (varaible == "mapHeight")
					{
						mapData.mapHeight = std::stoi(value);
					}
					else if (varaible == "tileWidth")
					{
						mapData.tileWidth = std::stoi(value);
					}
					else if (varaible == "tileHeight")
					{
						mapData.tileHeight = std::stoi(value);
					}
					else if (varaible == "scaleX")
					{
						mapData.scaleX = std::stoi(value);
					}
					else if (varaible == "scaleY")
					{
						mapData.scaleY = std::stoi(value);
					}
					else if (varaible == "dataLength")
					{
						mapData.dataLength = std::stoi(value);
					}
					else if (varaible == "data")
					{
						//TODO:DELETE ME LATER!
						mapData.data = new int[mapData.dataLength];

						int offset = 0;
						int i = 0;

						while (true)
						{
							int count = value.find(',', offset);
							std::string mapIndex = value.substr(offset, count - offset);

							if (mapIndex == ";")
								break;

							mapData.data[i] = std::stoi(mapIndex);

							offset = count + 1;
							i++;
						}
					}
				}
				catch (const std::exception&)
				{
					std::cout << "Something went wrong while reading file " << filename << std::endl;
				}
			}
		}

		file.close();
	}
	else
	{
		std::cout << "Unable to open " << filename << std::endl;
	}
}