//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DYNAMIC_CAST_HPP_INCLUDED
#define FCPPT_DYNAMIC_CAST_HPP_INCLUDED

#include <fcppt/type_info.hpp>
#include <fcppt/bad_dynamic_cast.hpp>
#include <boost/type_traits/is_reference.hpp>
#include <boost/type_traits/is_pointer.hpp>
#include <boost/utility/enable_if.hpp>
#include <typeinfo>
#include <stdexcept>

namespace fcppt
{

template<
	typename Dest,
	typename Src
>
typename boost::enable_if<
	boost::is_reference<
		Dest
	>,
	Dest
>::type
dynamic_cast_(
	Src &src
)
{
	try
	{
		return
			dynamic_cast<
				Dest
			>(
				src
			);
	}
	catch(
		std::bad_cast const &
	)
	{
		throw
			bad_dynamic_cast(
				type_info(
					typeid(
						Src
					)
				),
				type_info(
					typeid(
						Dest
					)
				)
			);	
	}
}

template<
	typename Dest,
	typename Src
>
typename boost::enable_if<
	boost::is_reference<
		Dest
	>,
	Dest
>::type
dynamic_cast_(
	Src const &src
)
{
	return
		dynamic_cast_<
			Dest
		>(
			const_cast<
				Src &
			>(
				src
			)
		);
}

template<
	typename Dest,
	typename Src
>
typename boost::enable_if<
	boost::is_pointer<
		Dest
	>,
	Dest
>::type
dynamic_cast_(
	Src const src
)
{
	return
		dynamic_cast<
			Dest
		>(
			src
		);
}

}

#endif