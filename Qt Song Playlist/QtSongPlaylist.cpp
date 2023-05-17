#include "QtSongPlaylist.h"
#include <qmessagebox.h>
#include <algorithm>

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

        // delete from all songs
        /*std::string songTitle;
        for (int i = 0; char(it->text()[i].toLatin1()) != ","; i++)
            songTitle[i] = char(it->text()[i].toLatin1());
       
        std::vector<Song>::iterator itr;
        for (auto& itr : m_allSongs) {
            if (itr.getTitle() == songTitle)
            {
                break;
            }
        }
        if (itr != m_allSongs.end())
            m_allSongs.erase(itr);*/

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

    if (ui.artistLineEdit->text() != "" && ui.titleLineEdit->text() != "" ) {
        ui.listWidget->addItem(ui.titleLineEdit->text() + ", " + ui.artistLineEdit->text());
        m_allSongs.push_back(Song{ ui.artistLineEdit->text().toStdString(), ui.titleLineEdit->text().toStdString(), ui.linkLineEdit->text().toStdString(), ui.durationLineEdit->text().toFloat() });
    }
    
    ui.titleLineEdit->clear();
    ui.artistLineEdit->clear();
    ui.durationLineEdit->clear();
    ui.linkLineEdit->clear();
}