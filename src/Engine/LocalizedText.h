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
#include <string>

/// @file

/** @def OX_REQUIRED_RESULT
 * This is used to enable warning of unused results, to warn the user of costly function calls.
 */

#ifndef OX_REQUIRED_RESULT
#  if defined(__GNUC_) && !defined(__INTEL_COMPILER) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 1))
#    define OX_REQUIRED_RESULT __attribute__ ((warn_unused_result))
#  else
#    define OX_REQUIRED_RESULT
#  endif
#endif
namespace OpenXcom
{

/**
 * A string that is already translated.
 * Using this class allows argument substitution in the translated strings.
 */
class LocalizedText
{
public:
	/// Create from existing string.
	explicit LocalizedText(const std::string &);
	/// Create the empty string.
	LocalizedText() : _nextArg(1) { /* Empty by design. */ }
	/// Return constant string.
	operator std::string const&() const OX_REQUIRED_RESULT;
	/// Get a pointer to underlying char data.
	const char *c_str() const OX_REQUIRED_RESULT { return _text.c_str(); }

	friend std::ostream& operator<<(std::ostream &os, const LocalizedText &txt);

	// Argument substitution.
	/// Replace next argument.
	LocalizedText arg(const std::string &) const OX_REQUIRED_RESULT;
	LocalizedText &arg(const std::string &) OX_REQUIRED_RESULT;
	template <typename T> LocalizedText arg(T) const OX_REQUIRED_RESULT;
	template <typename T> LocalizedText &arg(T) OX_REQUIRED_RESULT;
private:
	std::string _text; ///< The actual localized text.
	unsigned _nextArg; ///< The next argument ID.
	LocalizedText(const std::string &, unsigned);
};

}
