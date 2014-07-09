#include <QApplication>
#include "cacheext.h"

int main(int argc, char **argv)
{
QApplication app(argc, argv);
cacheext widget;
widget.show();
return app.exec();
}
