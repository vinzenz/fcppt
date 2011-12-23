//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_REF_HPP_INCLUDED
#define FCPPT_REF_HPP_INCLUDED

#include <fcppt/reference_wrapper.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/ref.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{

/**
\brief Creates a reference wrapper

\ingroup fcpptref

Creates a \link fcppt::reference_wrapper \endlink to <code>T</code> from \a
_ref

\tparam T Can be any type and might be incomplete

\param _ref The reference to wrap
*/
template<
	typename T
>
fcppt::reference_wrapper<
	T
> const
ref(
	T &_ref
)
{
	return
		boost::ref(
			_ref
		);
}

}

#endif
