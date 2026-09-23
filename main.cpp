#include "widget.h"

#include <QApplication>
#include <QByteArray>
#include <QFont>
#include <QStyleFactory>
#include <QWidget>

int main(int argc, char *argv[]) {
#ifdef Q_OS_MACOS
  if (!qEnvironmentVariableIsSet("QT_SCALE_FACTOR")) {
    qputenv("QT_SCALE_FACTOR", QByteArrayLiteral("1.25"));
  }
#endif

  QApplication a(argc, argv);
  Widget w;
#ifdef Q_OS_MACOS
  // The UI is authored with 8pt fonts; keep Mac text comfortably readable.
  constexpr qreal minUiPointSize = 10.0;
  QFont rootFont = w.font();
  if (rootFont.pointSizeF() > 0.0 && rootFont.pointSizeF() < minUiPointSize) {
    rootFont.setPointSizeF(minUiPointSize);
    w.setFont(rootFont);
  }
  for (QWidget *child : w.findChildren<QWidget *>()) {
    QFont childFont = child->font();
    if (childFont.pointSizeF() > 0.0 &&
        childFont.pointSizeF() < minUiPointSize) {
      childFont.setPointSizeF(minUiPointSize);
      child->setFont(childFont);
    }
  }
#endif
  w.show();
  return a.exec();
}
