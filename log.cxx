/*++

Copyright (c) Innopolis University

Abstract:
  Boost log adaptation.

--*/

//#include "stdafx.h"
//#include "app_log.h"

#include <boost/log/sinks/async_frontend.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/sinks/text_ostream_backend.hpp>
#include <boost/log/core.hpp>
#include <boost/log/expressions/formatter.hpp>
#include <boost/log/expressions/formatters.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/keywords/severity.hpp>
#include <boost/log/trivial.hpp>

#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/detail/config.hpp>
#include <boost/log/keywords/severity.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/detail/header.hpp>
#include <boost/log/detail/config.hpp>
#include <boost/log/attributes/attribute_name.hpp>
#include <boost/log/attributes/fallback_policy.hpp>
#include <boost/log/attributes/value_visitation.hpp>
#include <boost/log/detail/light_function.hpp>
#include <boost/log/detail/date_time_fmt_gen_traits_fwd.hpp>
#include <boost/log/detail/custom_terminal_spec.hpp>
#include <boost/log/detail/attr_output_terminal.hpp>
#include <boost/log/expressions/attr_fwd.hpp>
#include <boost/log/expressions/keyword_fwd.hpp>
#include <boost/log/utility/formatting_ostream.hpp>
#include <boost/log/utility/functional/bind.hpp>
#include <boost/log/detail/header.hpp>

namespace hsssg {
namespace app {

/**
 * Static sink. Needed for stopping async logging.
 */
using sink_async_t = boost::log::sinks::asynchronous_sink<boost::log::sinks::text_file_backend>;
static boost::shared_ptr<sink_async_t> s_sink;

/**
 * Static console sink. Needed for stopping async logging.
 */
using sink_async_console_t = boost::log::sinks::asynchronous_sink<boost::log::sinks::text_ostream_backend>;
static boost::shared_ptr<sink_async_console_t> s_sink_console;

/**
 *
 */
void LogInitializeAsync(const std::string& path) {
  boost::shared_ptr<boost::log::core> core = boost::log::core::get();
  boost::shared_ptr<boost::log::sinks::text_file_backend> backend = boost::make_shared<boost::log::sinks::text_file_backend>();
  // filename format;
  backend->set_file_name_pattern(path + "/%Y%m%d.log");
  // create new file at midnight
  backend->set_time_based_rotation(boost::log::sinks::file::rotation_at_time_point(0, 0, 0));
  backend->auto_flush(true);
  // reopen existing file
  backend->set_open_mode(std::ios::out | std::ios::app);

  // wrap it into the front-end and register in the core
  boost::shared_ptr<sink_async_t> sink = boost::make_shared<sink_async_t>(backend);
  core->add_sink(sink);

  auto format = boost::log::expressions::format("[%1%] [%2%] %3%")
                  % boost::log::trivial::severity
                  % boost::log::expressions::format_date_time< boost::posix_time::ptime >("TimeStamp", "%Y-%m-%d %H:%M:%S")
                  % boost::log::expressions::smessage;

  // set custom formatter
  sink->set_formatter(format);
  // save sink
  s_sink = sink;

#ifdef _I_DEBUG_
  // writing to console in debug
  boost::shared_ptr<sink_async_console_t> sink_console = boost::make_shared<sink_async_console_t>();

  // we have to provide an empty deleter
  // to avoid destroying the global stream object
  boost::shared_ptr<std::ostream> stream(&std::clog, boost::null_deleter());

  // add a stream to write log to
  sink_console->locked_backend()->add_stream(stream);

  // register the sink in the logging core
  core->add_sink(sink_console);

  // set the same formatter
  sink_console->set_formatter(format);

  // save console sink
  s_sink_console = sink_console;
#else
  // don't show debug message in not debug mode
  //s_sink->set_filter(boost::log::expressions::attr<boost::log::trivial::severity_level>("Severity") >
  //                   boost::log::trivial::trace);
  s_sink_console = nullptr;
#endif // _I_DEBUG_

  boost::log::add_common_attributes();
}

/**
 *
 */
void LogStopAsync() {
  boost::shared_ptr<boost::log::core> core = boost::log::core::get();
  // remove the sink from the core, so that no records are passed to it
  core->remove_sink(s_sink);
  // break the feeding loop
  s_sink->stop();
  // flush all log records that may have left buffered
  s_sink->flush();
  s_sink.reset();

  // handling console sink if necessary
  if (s_sink_console != nullptr) {
    core->remove_sink(s_sink_console);
    s_sink_console->stop();
    s_sink_console->flush();
    s_sink_console.reset();
  }
}

} // namespace app
} // namespace hsssg
