//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONST_POINTER_CAST_HPP_INCLUDED
#define FCPPT_CONST_POINTER_CAST_HPP_INCLUDED

#include <fcppt/shared_ptr_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Casts an \link fcppt::shared_ptr \endlink using
<code>const_cast</code>

\ingroup fcpptsmartptr

Casts the pointer stored in \a _ptr to type <code>U *</code> using
<code>const_cast</code>.

\tparam T The type of the source shared_ptr
\tparam U The type of the destination shared_ptr

\param _ptr The source shared_ptr

\return The converted shared_ptr
*/
template<
	typename T,
	typename U,
	template<
		typename
	> class Deleter
>
fcppt::shared_ptr<T, Deleter> const
const_pointer_cast(
	fcppt::shared_ptr<U const, Deleter> const &_ptr
)
{
	return
		fcppt::shared_ptr<T, Deleter>(
			_ptr,
			boost::detail::const_cast_tag()
		);
}

}

#endif
