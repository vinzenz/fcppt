//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[logcomplex
#include <fcppt/function/object.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/log/context.hpp>
#include <fcppt/log/debug.hpp>
#include <fcppt/log/define_context.hpp>
#include <fcppt/log/error.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/location.hpp>
#include <fcppt/log/object.hpp>
#include <fcppt/log/output.hpp>
#include <fcppt/log/parameters/with_context.hpp>
#include <fcppt/tr1/functional.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/from_std_string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <fcppt/config/external_end.hpp>

namespace engine
{

// Function to retrieve the global log context
fcppt::log::context &
log_context();

// Helper function to create our logger parameters
inline
fcppt::log::parameters::all const
create_logger(
	fcppt::log::location const &_location
)
{
	return
		fcppt::log::parameters::with_context(
			engine::log_context(),
			fcppt::io::cout(),
			_location
		)
		.level_defaults(
			fcppt::log::level::debug
		);
}

// Helper function to return the engine's log location
inline
fcppt::log::location const
logger_location()
{
	return
		fcppt::log::location(
			FCPPT_TEXT("engine")
		);
}

// The engine's root logger
fcppt::log::object &
root_logger();

// Define two subsystem loggers.
namespace renderer
{

fcppt::log::object &
logger();

}

namespace audio
{

fcppt::log::object &
logger();

}

}

//
// Translation unit for the global log context
//

FCPPT_LOG_DEFINE_CONTEXT(
	engine::log_context
)

//
// Translation unit for the root logger
//

namespace
{

fcppt::log::object root_logger_obj(
	engine::create_logger(
		engine::logger_location()
	)
);

}

fcppt::log::object &
engine::root_logger()
{
	return root_logger_obj;
}

//
// Translation unit for the renderer logger
//

namespace
{

fcppt::log::object renderer_logger_obj(
	engine::create_logger(
		engine::logger_location()
		/
		FCPPT_TEXT("renderer")
	)
);

}

fcppt::log::object &
engine::renderer::logger()
{
	return renderer_logger_obj;
}

//
// Translation unit for the audio logger
//

namespace
{

fcppt::log::object audio_logger_obj(
	engine::create_logger(
		engine::logger_location()
		/
		FCPPT_TEXT("audio")
	)
);

}

fcppt::log::object &
engine::audio::logger()
{
	return audio_logger_obj;
}

int
main(
	int argc,
	char **argv
)
try
{
	// Each command line parameter specifies a logger to activate.
	// Example: "./example renderer" will activate the renderer's logger so we can
	// diagnose a problem there.
	for(
		int i = 1;
		i < argc;
		++i
	)
		engine::log_context().apply(
			fcppt::log::location(
				FCPPT_TEXT("engine")
			)
			/
			fcppt::from_std_string(
				argv[i]
			),
			std::tr1::bind(
				&fcppt::log::object::enable,
				std::tr1::placeholders::_1,
				true
			)
		);

	FCPPT_LOG_DEBUG(
		engine::renderer::logger(),
		fcppt::log::_
			<< FCPPT_TEXT("test")
	)

	FCPPT_LOG_DEBUG(
		engine::audio::logger(),
		fcppt::log::_
			<< FCPPT_TEXT("test")
	)
}
catch(
	fcppt::exception const &_error
)
{
	fcppt::io::cerr()
		<< _error.string()
		<< FCPPT_TEXT('\n');

	return EXIT_FAILURE;
}
//]
