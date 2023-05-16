#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtSongPlaylist.h"
#include "Song.h"
#include <vector>

class QtSongPlaylist : public QMainWindow
{
    Q_OBJECT

public slots:
    void on_UpdateButton_clicked();
    void on_addButton_clicked();
    void on_Next_in_Playlist_clicked();
    void on_deleteButton_clicked();

signals:


public:
    QtSongPlaylist(QWidget *parent = nullptr);
    ~QtSongPlaylist();

private:
    Ui::QtSongPlaylistClass ui;
    std::vector<Song> m_allSongs;
    std::vector<Song> m_playlist;
};
