#pragma once
/*
 * Copyright 2010-2016 OpenXcom Developers.
 *
 * This file is part of OpenXcom.
 *
 * OpenXcom is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OpenXcom is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OpenXcom.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "RuleRegion.h"

#include <yaml-cpp/yaml.h>

namespace YAML
{
	template<>
	struct convert<OpenXcom::MissionArea>
	{
		static Node encode(const OpenXcom::MissionArea& rhs)
		{
			Node node;
			node.push_back(Rad2Deg(rhs.lonMin));
			node.push_back(Rad2Deg(rhs.lonMax));
			node.push_back(Rad2Deg(rhs.latMin));
			node.push_back(Rad2Deg(rhs.latMax));
			return node;
		}

		static bool decode(const Node& node, OpenXcom::MissionArea& rhs)
		{
			if (!node.IsSequence() || node.size() < 4)
				return false;

			rhs.lonMin = Deg2Rad(node[0].as<double>());
			rhs.lonMax = Deg2Rad(node[1].as<double>());
			rhs.latMin = Deg2Rad(node[2].as<double>());
			rhs.latMax = Deg2Rad(node[3].as<double>());
			if (rhs.latMin > rhs.latMax)
				std::swap(rhs.latMin, rhs.latMax);
			if (node.size() >= 5) rhs.texture = node[4].as<int>();
			if (node.size() >= 6) rhs.name = node[5].as<std::string>();
			return true;
		}
	};

	template<>
	struct convert<OpenXcom::MissionZone>
	{
		static Node encode(const OpenXcom::MissionZone& rhs)
		{
			Node node;
			node = rhs.areas;
			return node;
		}

		static bool decode(const Node& node, OpenXcom::MissionZone& rhs)
		{
			if (!node.IsSequence())
				return false;

			rhs.areas = node.as< std::vector<OpenXcom::MissionArea> >(rhs.areas);
			return true;
		}
	};
}

