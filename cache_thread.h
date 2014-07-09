#include <QtGui>
#include "cache_type.h"

class cache_thread : public QThread
{
Q_OBJECT

  public:
    virtual void run();
    QTableWidget *cache_table;
  public slots:
    void explore_cache(QDir directory);
    //void extract_from_cache(QStringList extractlist);
    void cancel();
  private:
    bool cancelop;
    QDir runner_cache_dir;
    QMutex runner_mutex;
    //void extract_runner();
    void explore_runner();
  signals:
    void explore_cache_progress(int); //Progress, Total
    void extract_from_cache_progress(int);
};
