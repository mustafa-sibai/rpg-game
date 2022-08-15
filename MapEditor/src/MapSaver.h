#pragma once
#include <string>
#include <core/MapData.h>

class MapSaver
{
public:
	void Save(const std::string& filename, const MapData& mapData);
};