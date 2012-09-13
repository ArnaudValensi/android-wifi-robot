#include <QtGui/QApplication>
#include "Gui.h"

int run(int argc, char *argv[])
{
  QApplication a(argc, argv);
  Gui w;

  w.init(argv[1]);
  w.show();

  return a.exec();
}

int main(int argc, char *argv[])
{
  if (argc != 2)
    {
      std::cout << "Usage: " << argv[0]
		<< " <devicePath> (v4l:///dev/video1, dshow://, ...)"
		<< std::endl;
      return (1);
    }

  return run(argc, argv);
}
