//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_FROM_VOID_PTR_HPP_INCLUDED
#define FCPPT_CAST_FROM_VOID_PTR_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/and.hpp>
#include <boost/utility/enable_if.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace cast
{

/**
\brief Converts a void pointer to a different pointer

\ingroup fcpptcasts

Converts the void pointer \a _ptr to the pointer type specified by \a Dest.
This cast is unsafe.
*/
template<
	typename Dest,
	typename Source
>
typename
boost::enable_if<
	boost::mpl::and_<
		std::is_pointer<
			Dest
		>,
		std::is_void<
			typename
			std::remove_cv<
				Source
			>::type
		>
	>,
	Dest
>::type
from_void_ptr(
	Source *const _ptr
)
{
	return
		static_cast<
			Dest
		>(
			_ptr
		);
}

}
}

#endif
