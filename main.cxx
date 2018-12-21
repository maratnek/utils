#include "qdebugstream.h"
#include "iostream"
#include "log.h"

#include <QApplication>
using namespace hsssg;

int main(int ac, char**av)
{
  QApplication app(ac, av);
	app::LogInitializeAsync("log");

  QTextEdit te;
  QDebugStream dstr(std::cout, &te, "log/out.log");
  std::cout << "My test edit test" << std::endl;
	te.show();

	app::LogStopAsync();

  app.exec();
}
