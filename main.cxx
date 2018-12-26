#include "iostream"
#include "log.h"
#include "qdebugstream.h"

#include <QApplication>
using namespace hsssg;

int main(int ac, char**av)
{
 // QApplication app(ac, av);
  app::LogInitializeAsync("log");

//	trivialLog();
	HSSSG_LOG_DEBUG << "Log Debug";
	HSSSG_LOG_ERROR << "Log Erorr";
	HSSSG_LOG_INFO << "Log Info";
	HSSSG_LOG_TRACE << "Log Trace";
	HSSSG_LOG_WARNING << "Log Warning";
	HSSSG_LOG_FATAL << "Log Fatal";

 // QTextEdit te;
 // QDebugStream dstr(std::cout, &te, "log/out.log");
 // std::cout << "My test edit test" << std::endl;
	//te.show();

  app::LogStopAsync();

  //app.exec();
}

//#include "first.h"
//int main(int, char*[])
//{
//	trivialLog();
//	return 0;
//}
