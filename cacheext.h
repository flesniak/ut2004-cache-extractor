#include <QtGui>
#include "cache_thread.h"

class cacheext : public QWidget
{
Q_OBJECT

  public:
    cacheext();
  private:
    QMenuBar *menubar;
    QTableWidget *cache_table;
    cache_thread *ct;
    QProgressDialog *progress_dlg;
  public slots:
    void explore_cache(QDir directory);
};
