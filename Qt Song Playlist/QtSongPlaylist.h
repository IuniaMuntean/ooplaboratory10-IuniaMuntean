#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtSongPlaylist.h"
#include "SongController.h"
#include "Playlist.h"

class QtSongPlaylist : public QMainWindow
{
    Q_OBJECT

public slots:
    void on_LyricsButton_clicked();
    void on_addButton_clicked();
    void on_deleteButton_clicked();
    void on_Next_in_Playlist_clicked();
    void on_deletePlaylistButton_clicked();
    void on_SortbyTitleButton_clicked();
    void on_sortByArtistsButton_clicked();
    void on_RandomiseButton_clicked();
    void on_playButton_clicked();

signals:


public:
    QtSongPlaylist(QWidget *parent = nullptr);

    void setUp_List_Widget();

    ~QtSongPlaylist();

private:
    Ui::QtSongPlaylistClass ui;
    SongController m_allSongsController{ "file.txt" };
    Playlist m_playlist;
};
