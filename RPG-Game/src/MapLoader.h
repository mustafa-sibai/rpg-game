#pragma once
#include <iostream>
#include <core/MapData.h>

class MapLoader
{
public:
	void Load(std::string filename, MapData& mapData);
};