//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/detail/context_tree.hpp>
#include <fcppt/log/detail/outer_context_node.hpp>
#include <fcppt/src/log/optional_outer_context_node.hpp>
#include <fcppt/src/log/to_outer_node.hpp>
#include <fcppt/variant/to_optional.hpp>


fcppt::log::optional_outer_context_node const
fcppt::log::to_outer_node(
	fcppt::log::detail::context_tree &_node
)
{
	return
		fcppt::variant::to_optional<
			fcppt::log::detail::outer_context_node
		>(
			_node.value().get()
		);
}