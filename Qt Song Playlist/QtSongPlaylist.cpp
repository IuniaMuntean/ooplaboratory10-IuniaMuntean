#include "QtSongPlaylist.h"
#include <qmessagebox.h>
#include <qinputdialog.h>
#include <algorithm>
#include <cstring>


QtSongPlaylist::QtSongPlaylist(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    setUp_List_Widget();
    
    //QObject::connect(ui.addButton, SIGNAL(clicked()), this, SLOT(on_addButton_clicked()));
    //QObject:connect(ui.deleteButton, SIGNAL(clicked()), this, SLOT(on_deleteButton_clicked()));
    //QObject::connect(ui.LyricsButton, SIGNAL(clicked()), this, SLOT(on_LyricsButton_clicked()));
    //QObject::connect(ui.UpdateButton, SIGNAL(clicked()), this, SLOT(on_UpdateButton_clicked()));
    //QObject::connect(ui.FilterButton, SIGNAL(clicked()), this, SLOT(on_UpdateButton_clicked()));

    
    QObject::connect(ui.Button_Next_in_Playlist, SIGNAL(clicked()), this, SLOT(on_Next_in_Playlist_clicked()));
    QObject:connect(ui.PlaylistDeleteButton, SIGNAL(clicked()), this, SLOT(on_deletePlaylistButton_clicked()));
}

void QtSongPlaylist::setUp_List_Widget() {
    for (auto song : m_allSongsController.getInstance().getAllSongs()) {
        new QListWidgetItem(tr((song.getTitle() + "-" + song.getArtist()).c_str()), ui.listWidget);
        /*QListWidgetItem* it->text() = QString::fromStdString(song.getTitle() + " - " + song.getArtist());
        ui.listWidget->addItem(it);*/
    } 
}

QtSongPlaylist::~QtSongPlaylist()
{}

void QtSongPlaylist::on_addButton_clicked() {

    try
    {
        //artist, title, lyrics, year, url
        m_allSongsController.add_new_song(ui.artistLineEdit->text().toStdString(), ui.titleLineEdit->text().toStdString(), ui.LyricsEdit->toPlainText().toStdString(), ui.yearLineEdit->text().toStdString(), ui.linkLineEdit->text().toStdString() );
    }
    catch (SongException e)
    {
        QMessageBox::warning(this, tr("Message Box"), tr(e.what()));
        return;
    }

    if (ui.artistLineEdit->text() != "" && ui.titleLineEdit->text() != "" ) {
        ui.listWidget->addItem(ui.titleLineEdit->text() + "-" + ui.artistLineEdit->text());
    }
    
    ui.titleLineEdit->clear();
    ui.artistLineEdit->clear();
    ui.yearLineEdit->clear();
    ui.linkLineEdit->clear();
    ui.LyricsEdit->clear();
}

void QtSongPlaylist::on_deleteButton_clicked() {
   if(ui.listWidget->currentRow() != -1) {
        QListWidgetItem* it = ui.listWidget->takeItem(ui.listWidget->currentRow());

        // delete from all songs
        try
        {
            bool ok = 0;
            std::string artist;
            std::string title;
            for (auto c : it->text().toStdString()) {
                if (c == '-')
                {
                    ok = true; continue;
                }
                if (ok == 0)
                    title += c;
                else artist += c;
            }
            m_allSongsController.remove_song(Song(artist, title, "", "", ""));
        }
        catch (SongException e)
        {
            QMessageBox::warning(this, tr("Message Box"), tr(e.what()));
            return;
        }

        delete it;
        ui.listWidget->setCurrentRow(-1);
    }
}

void QtSongPlaylist::on_deletePlaylistButton_clicked() {
   if(ui.playlist->currentRow() != -1) {
        QListWidgetItem* it = ui.playlist->takeItem(ui.playlist->currentRow());

        // delete from all songs
        bool ok = 0;
        std::string artist;
        std::string title;
        for (auto c : it->text().toStdString()) {
            if (c == '-')
            {
                ok = true; continue;
            }
            if (ok == 0)
                title += c;
            else artist += c;
        }
        Song s;
        try {
            s = m_allSongsController.search(artist, title);
            m_playlist.remove(s);
        }
        catch (SongException e)
        {
            QMessageBox::warning(this, tr("Message Box"), tr(e.what()));
            return;
        }

        delete it;
        ui.listWidget->setCurrentRow(-1);
    }
}

void QtSongPlaylist::on_LyricsButton_clicked() {
    if (ui.listWidget->currentRow() != -1) {
        QListWidgetItem* it = ui.listWidget->item(ui.listWidget->currentRow());

        bool ok = 0;
        std::string artist;
        std::string title;
        for (auto c : it->text().toStdString()) {
            if ( c == '-')
            {
                ok = true; continue;
            }
            if (ok == 0)
                title += c;
            else artist += c;
        }
        Song s;
        try { s = m_allSongsController.search(artist, title); }
        catch (SongException e)
        {
            QMessageBox::warning(this, tr("Message Box"), tr(e.what()));
            return;
        }
        QMessageBox::information(this, tr("Lyrics Box"), tr(s.toString().c_str()) );
    }
}

void QtSongPlaylist::on_Next_in_Playlist_clicked() {
    QListWidgetItem* itm = ui.listWidget->item(ui.listWidget->currentRow());
    bool ok = 0;
    std::string artist;
    std::string title;
    for (auto c : itm->text().toStdString()) {
        if (c == '-')
        {
            ok = true; continue;
        }
        if (ok == 0)
            title += c;
        else artist += c;
    }
    Song s;
    try {
        s = m_allSongsController.search(artist, title);
    }
    catch (SongException e)
    {
        QMessageBox::warning(this, tr("Message Box"), tr(e.what()));
        return;
    }
    m_playlist.add(s);
    ui.playlist->addItem(itm->text());
}

void QtSongPlaylist::on_SortbyTitleButton_clicked() {
    QString txt = QInputDialog::getText(this, "Entry", "Input way of sorting: ASC or DESC??");
    std::vector<Song>  sorted;
    if (txt == "ASC")
        sorted = m_allSongsController.sort_by_title(ASC);
    else if (txt == "DESC")
        sorted = m_allSongsController.sort_by_title(DESC);
    else {
        QMessageBox::warning(this, tr("Message Box"), tr("Smth went wrong"));
        return;
    }

    ui.listWidget->clear();
    for (auto song : sorted )
        new QListWidgetItem(tr((song.getTitle() + "-" + song.getArtist()).c_str()), ui.listWidget);
}

void QtSongPlaylist::on_sortByArtistsButton_clicked() {
    QString txt = QInputDialog::getText(this, "Entry", "Input way of sorting: ASC or DESC??");
    std::vector<Song>  sorted;
    if (txt == "ASC")
        sorted = m_allSongsController.sort_by_artist(ASC);
    else if (txt == "DESC")
        sorted = m_allSongsController.sort_by_artist(DESC);
    else {
        QMessageBox::warning(this, tr("Message Box"), tr("Smth went wrong"));
        return;
    }

    ui.listWidget->clear();
    for (auto song : sorted )
        new QListWidgetItem(tr((song.getTitle() + "-" + song.getArtist()).c_str()), ui.listWidget);
}

void QtSongPlaylist::on_RandomiseButton_clicked() {
    std::vector<Song> newPlaylist;
    newPlaylist = m_playlist.generateRandom((unsigned int)ui.playlist->count());
    ui.playlist->clear();
    for (auto song : newPlaylist)
        new QListWidgetItem(tr((song.getTitle() + "-" + song.getArtist()).c_str()), ui.playlist);
}


void QtSongPlaylist::on_playButton_clicked() {
    QMessageBox::warning(this, tr("Message Box"), tr("Not implemented yet."));
}

