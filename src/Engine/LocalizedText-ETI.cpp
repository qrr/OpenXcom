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

#include "LocalizedText.ipp"

/*
* ETI stands for Externalized Template Instantiation.
*/

namespace OpenXcom
{

template LocalizedText LocalizedText::arg(int val) const OX_REQUIRED_RESULT;
template LocalizedText LocalizedText::arg(char const*) const OX_REQUIRED_RESULT;
template LocalizedText LocalizedText::arg(unsigned int) const OX_REQUIRED_RESULT;
template LocalizedText LocalizedText::arg(unsigned long) const OX_REQUIRED_RESULT;
template LocalizedText& LocalizedText::arg(int) OX_REQUIRED_RESULT;
template LocalizedText& LocalizedText::arg(char const*) OX_REQUIRED_RESULT;
template LocalizedText& LocalizedText::arg(unsigned int) OX_REQUIRED_RESULT;
template LocalizedText& LocalizedText::arg(unsigned long) OX_REQUIRED_RESULT;

template LocalizedText LocalizedText::arg(OpenXcom::LocalizedText) const OX_REQUIRED_RESULT;
template LocalizedText& LocalizedText::arg(OpenXcom::LocalizedText) OX_REQUIRED_RESULT;

}
