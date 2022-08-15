#include "MapSaver.h"
#include <fstream>

#define RMAP_VERSION_NUMBER 1

void MapSaver::Save(const std::string& filename, const MapData& mapData)
{
	std::ofstream file;
	file.open(filename);
	file << "[Map]" << std::endl;
	file << "version=" << RMAP_VERSION_NUMBER << std::endl;
	file << "tilesheet=" << mapData.GetTilesheet() << std::endl;
	file << "mapName=" << mapData.GetName() << std::endl;

	file << "mapPositionX=" << mapData.GetMapPositionX() << std::endl;
	file << "mapPositionY=" << mapData.GetMapPositionY() << std::endl;

	file << "cellSizeX=" << mapData.GetCellSizeX() << std::endl;
	file << "cellSizeY=" << mapData.GetCellSizeY() << std::endl;

	file << "totalCellsX=" << mapData.GetTotalCellsX() << std::endl;
	file << "totalCellsY=" << mapData.GetTotalCellsY() << std::endl;

	file << "mapScaleX=" << mapData.GetMapScaleX() << std::endl;
	file << "mapScaleY=" << mapData.GetMapScaleY() << std::endl;
	
	file << "dataLength=" << mapData.GetDataLength() << std::endl;
	file << "data=" << std::endl;

	for (size_t y = 0; y < 5; y++)
	{
		for (size_t x = 0; x < 10; x++)
		{
			int i = x + y * 10;
			file << mapData.GetData()[i] << ",";
		}
		file << std::endl;
	}

	file.close();
}