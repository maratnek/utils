/*++

Copyright (c) Innopolis University

Abstract:
  Boost log adaptation. Output file has YYYYMMDD.log format, message has
  [<type>]\t[timestamp]\t[message][\n] format.
  Call LogInitializeAsync() for initialize log, LogStopAsync() for stop log.
  Examples: 
      HSSSG_LOG_ERROR << "Hello world!";
      HSSSG_LOG_WARNING << 123.456;
      HSSSG_LOG_INFO << boost::format("Hello %s,  x=%s : %d-th step") 
        %"world!" %1.234 %5;

Authors:
  Rinat Baygildin (r.baygildin@innopolis.ru)

--*/
#ifndef HSSSG_APP_LOG_H
#define HSSSG_APP_LOG_H

#include <boost/log/common.hpp>
#include <boost/log/trivial.hpp>
#include <platforms/defs.h>
#if defined(I_OS_WINDOWS)
// function marked as __forceinline not inlined
#pragma warning(disable: 4714)
#endif

namespace hsssg {
namespace app {

// Global severity_logger
BOOST_LOG_INLINE_GLOBAL_LOGGER_DEFAULT(slg, boost::log::sources::severity_channel_logger_mt<boost::log::trivial::severity_level>)

/**
 * Initialize output file(YYYYMMDD.log) and format of log message, async case.
 * By default write to logs/YYYYMMDD.log
 * Returning value is used at LogStopAsync(...)
 */
void LogInitializeAsync(const std::string& path);

/**
 * Sinks async stop
 */
void LogStopAsync();

} // namespace app

/**
 * HSSSG logger global macro
 */
#define HSSSG_LOG_FATAL   BOOST_LOG_SEV(hsssg::app::slg::get(), boost::log::trivial::severity_level::fatal)
#define HSSSG_LOG_ERROR   BOOST_LOG_SEV(hsssg::app::slg::get(), boost::log::trivial::severity_level::error)
#define HSSSG_LOG_WARNING BOOST_LOG_SEV(hsssg::app::slg::get(), boost::log::trivial::severity_level::warning)
#define HSSSG_LOG_INFO    BOOST_LOG_SEV(hsssg::app::slg::get(), boost::log::trivial::severity_level::info)
#define HSSSG_LOG_DEBUG   BOOST_LOG_SEV(hsssg::app::slg::get(), boost::log::trivial::severity_level::debug)

} // namespace hsssg

#endif // HSSSG_APP_LOG_H
