/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2009 Carl Philipp Reh (sefi@s-e-f-i.de)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


#ifndef FCPPT_MATH_MATRIX_DETAIL_TRANSLATION_IMPL_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_DETAIL_TRANSLATION_IMPL_HPP_INCLUDED

#include <fcppt/math/matrix/basic_impl.hpp>

template<
	typename T
>
typename fcppt::math::matrix::static_<T, 4, 4>::type const
fcppt::math::matrix::translation(
	T const x,
	T const y,
	T const z)
{
	return typename static_<T, 4, 4>::type
	       (static_cast<T>(1), static_cast<T>(0), static_cast<T>(0), x,
	        static_cast<T>(0), static_cast<T>(1), static_cast<T>(0), y,
	        static_cast<T>(0), static_cast<T>(0), static_cast<T>(1), z,
	        static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(1));
}

#endif