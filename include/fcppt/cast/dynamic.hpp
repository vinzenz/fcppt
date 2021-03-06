//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_DYNAMIC_HPP_INCLUDED
#define FCPPT_CAST_DYNAMIC_HPP_INCLUDED

#include <fcppt/cast/detail/dynamic.hpp>
#include <fcppt/optional/reference.hpp>
#include <fcppt/type_traits/is_base_of.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace cast
{

/**
\brief Tries a <code>dynamic_cast</code>, returning an empty optional value if
it failed

\ingroup fcpptcasts

\tparam Derived The type to cast to. This has to be a reference type (see the
example below)

\tparam Base The type to cast from (must not be a reference)

This cast is basically the same as <code>dynamic_cast</code> with pointers, but
with optional references. Note that you can only cast to a reference type (be
that const or nonconst). Here's a usage example:

\snippet cast.cpp dynamic
*/
template<
	typename Derived,
	typename Base
>
inline
fcppt::optional::reference<
	Derived
>
dynamic(
	Base &_base
)
{
	static_assert(
		fcppt::type_traits::is_base_of<
			typename
			std::remove_cv<
				Base
			>::type,
			typename
			std::decay<
				Derived
			>::type
		>::value,
		"dynamic can only cast from references to base classes to references to derived classes"
	);

	return
		fcppt::cast::detail::dynamic<
			Derived
		>(
			_base
		);
}

}
}

#endif
