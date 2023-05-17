#include "QtSongPlaylist.h"
#include <qmessagebox.h>

QtSongPlaylist::QtSongPlaylist(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    
    QObject::connect(ui.UpdateButton, SIGNAL(clicked()), this, SLOT(on_UpdateButton_clicked()));
    QObject::connect(ui.FilterButton, SIGNAL(clicked()), this, SLOT(on_UpdateButton_clicked()));

    QObject::connect(ui.addButton, SIGNAL(clicked()), this, SLOT(on_addButton_clicked()));
    QObject:connect(ui.deleteButton, SIGNAL(clicked()), this, SLOT(on_deleteButton_clicked()));
    
    QObject::connect(ui.Button_Next_in_Playlist, SIGNAL(clicked()), this, SLOT(on_Next_in_Playlist_clicked()));
}

QtSongPlaylist::~QtSongPlaylist()
{}

void QtSongPlaylist::on_deleteButton_clicked() {
   if(ui.listWidget->currentRow() != -1) {
        QListWidgetItem* it = ui.listWidget->takeItem(ui.listWidget->currentRow());
        delete it;
        ui.listWidget->setCurrentRow(-1);
    }
}

void QtSongPlaylist::on_UpdateButton_clicked() {
    QMessageBox::warning(this, tr("Message Box"), tr("Not implemented yet."));
}

void QtSongPlaylist::on_Next_in_Playlist_clicked() {
    QListWidgetItem* itm = ui.listWidget->currentItem();
    ui.playlist->addItem(itm->text());
}

void QtSongPlaylist::on_addButton_clicked() {
    m_allSongs.push_back(Song{ ui.artistLineEdit->text().toStdString(), ui.titleLineEdit->text().toStdString(), ui.linkLineEdit->text().toStdString(), ui.durationLineEdit->text().toFloat()});

    if (ui.artistLineEdit->text() != "" && ui.titleLineEdit->text() != "" )
        ui.listWidget->addItem(ui.artistLineEdit->text() + ", " + ui.titleLineEdit->text());
    
    ui.titleLineEdit->clear();
    ui.artistLineEdit->clear();
    ui.durationLineEdit->clear();
    ui.linkLineEdit->clear();
}