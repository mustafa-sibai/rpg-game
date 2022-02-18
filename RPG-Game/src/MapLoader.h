#pragma once
#include <iostream>
#include "MapData.h"

class MapLoader
{
public:
	void Load(std::string filename, MapData& mapData);
};