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

/*
* Weird case; the .h should be enough by normal expectations.
* This was done this way to allow the original .cpp to remain in place
* as closely to the original as possible.
*/
#include "LocalizedText.h"

#include <sstream>

namespace OpenXcom
{


/**
 * Replace the next argument placeholder with @a val.
 * @tparam T The type of the replacement value. It should be streamable to std::owstringstream.
 * @param val The value to place in the next placeholder's position.
 * @return A translated string with all occurrences of the marker replaced by @a val.
 */
template <typename T>
LocalizedText LocalizedText::arg(T val) const
{
	std::ostringstream os;
	os << '{' << _nextArg << '}';
	std::string marker(os.str());
	size_t pos = _text.find(marker);
	if (std::string::npos == pos)
		return *this;
	std::string ntext(_text);
	os.str("");
	os << val;
	std::string tval(os.str());
	for (/*empty*/ ; std::string::npos != pos; pos = ntext.find(marker, pos + tval.length()))
	{
		ntext.replace(pos, marker.length(), tval);
	}
	return LocalizedText(ntext, _nextArg);
}

/**
 * Replace the next argument placeholder with @a val.
 * @tparam T The type of the replacement value. It should be streamable to std::owstringstream.
 * @param val The value to place in the next placeholder's position.
 * @return The translated string with all occurrences of the marker replaced by @a val.
 */
template <typename T>
LocalizedText &LocalizedText::arg(T val)
{
	std::ostringstream os;
	os << '{' << _nextArg << '}';
	std::string marker(os.str());
	size_t pos = _text.find(marker);
	if (std::string::npos != pos)
	{
		os.str("");
		os << val;
		std::string tval(os.str());
		for (/*empty*/ ; std::string::npos != pos; pos = _text.find(marker, pos + tval.length()))
		{
			_text.replace(pos, marker.length(), tval);
		}
		++_nextArg;
	}
	return *this;
}

}
