#include "cacheext.h"

cacheext::cacheext()
{
setWindowTitle("UT2k4 Linux Cache Extractor");
menubar = new QMenuBar(this);
QMenu *file_menu = menubar->addMenu("File");
QAction *quit_action = file_menu->addAction(QIcon::fromTheme("application-exit"),"Q&uit");
quit_action->setShortcuts(QKeySequence::Quit);
QMenu *cache_menu = menubar->addMenu("Cache");
QAction *clear_action = cache_menu->addAction("Clear cache");
QAction *copy_all_action = cache_menu->addAction("C&opy all entries to UT installation");

cache_table = new QTableWidget(this);
cache_table->setColumnCount(4);
QStringList table_header_list;
table_header_list << "Select" << "Cache file name" << "Real file name" << "Type";
cache_table->setHorizontalHeaderLabels(table_header_list);

QPushButton *extract_button = new QPushButton(this);
extract_button->setText("Extract selected Cache Entries");

progress_dlg = new QProgressDialog(this);

QDir ut_dir(QDir::homePath()+"/.ut2004");
if( !ut_dir.isReadable() ) {
  QMessageBox::critical(this,"Error!","UT2004 directory not found. Make sure your UT is installed under\n"+ut_dir.absolutePath());
  exit(1);
  }

QGridLayout *layout = new QGridLayout(this);
layout->setMenuBar(menubar);
layout->addWidget(cache_table,0,0);
layout->addWidget(extract_button,1,0);

ct = new cache_thread;
ct->cache_table = cache_table;
ct->start();

connect(quit_action,SIGNAL(triggered()),this,SLOT(close()));
connect(extract_button,SIGNAL(clicked()),this,SLOT(extract()));

explore_cache(ut_dir);
}

void cacheext::explore_cache(QDir directory)
{
QDir cache_dir(directory.absolutePath()+"/Cache");
if( !cache_dir.isReadable() ) {
  QMessageBox::critical(this,"Error!","Cache not found. Make sure your UT is installed under\n"+directory.absolutePath());
  exit(1);
  }

progress_dlg->setLabelText("Reading cache");
progress_dlg->setRange(0,cache_dir.count()-1);
progress_dlg->setValue(0);
progress_dlg->show();

connect(ct,SIGNAL(explore_cache_progress(int)),progress_dlg,SLOT(setValue(int)));
connect(progress_dlg,SIGNAL(canceled()),ct,SLOT(cancel()));
ct->explore_cache(directory);
}
