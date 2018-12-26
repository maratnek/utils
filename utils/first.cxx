//
//  first.cxx
//  utils
//
//  Created by Marat on 20/12/2018.
//

#include "first.h"
#include <boost/log/trivial.hpp>

int trivialLog()
{
	BOOST_LOG_TRIVIAL(trace) << "A trace severity message";
	BOOST_LOG_TRIVIAL(debug) << "A debug severity message";
	BOOST_LOG_TRIVIAL(info) << "An informational severity message";
	BOOST_LOG_TRIVIAL(warning) << "A warning severity message";
	BOOST_LOG_TRIVIAL(error) << "An error severity message";
//	BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message";

	return 0;
}
