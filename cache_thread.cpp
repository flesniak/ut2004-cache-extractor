#include "cache_thread.h"

void cache_thread::run()
{
runner_mutex.lock();
explore_runner();
//extract_runner();
exec();
}

void cache_thread::explore_cache(QDir cache_dir)
{
runner_cache_dir=cache_dir;
runner_mutex.unlock();
}

void cache_thread::explore_runner()
{
while(1)
{
runner_mutex.lock();
QTableWidgetItem *select_item = new QTableWidgetItem;
select_item->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
QTableWidgetItem *text_item = new QTableWidgetItem;
text_item->setFlags(Qt::NoItemFlags | Qt::ItemIsEnabled);
quint32 progress = 0;

QFile *cache_ini_file = new QFile(runner_cache_dir.absolutePath()+"/Cache/cache.ini");
QTextStream *cache_ini_stream = new QTextStream(cache_ini_file);
if(cache_ini_file->open(QIODevice::Text | QIODevice::ReadOnly))
  while(!cache_ini_stream->atEnd())
    {
    progress++;
    QString line = cache_ini_stream->readLine();
    qDebug() << progress << ": processing line: " << line;
    int pos = line.indexOf('=');
    if( pos != -1 ) {
      cache_table->insertRow(cache_table->rowCount());
      cache_table->setItem(cache_table->rowCount()-1,0,select_item->clone());
      text_item->setText(line.left(pos));
      cache_table->setItem(cache_table->rowCount()-1,1,text_item->clone());
      text_item->setText(line.right(line.length()-pos-1));
      cache_table->setItem(cache_table->rowCount()-1,2,text_item->clone());
      text_item->setText(cache_type::getName(line.right(line.length()-line.indexOf('.')-1)));
      cache_table->setItem(cache_table->rowCount()-1,3,text_item->clone());
      emit explore_cache_progress(progress);
      if(cancelop) break;
      sleep(1);
      }
    }
else
  qDebug() << "Unable to open: " << runner_cache_dir.absolutePath()+"/cache.ini";
cache_table->resizeColumnsToContents();
cache_table->resizeRowsToContents();
cache_table->sortItems(2);
cancelop=false;
}
}

/*void cache_thread::extract_from_cache(QStringList extractlist)
{

}

void cache_thread::extract_runner()
{
runner_mutex.lock();
}*/

void cache_thread::cancel()
{
cancelop=true;
}