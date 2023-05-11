#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtSongPlaylist.h"

class QtSongPlaylist : public QMainWindow
{
    Q_OBJECT

public:
    QtSongPlaylist(QWidget *parent = nullptr);
    ~QtSongPlaylist();

private:
    Ui::QtSongPlaylistClass ui;
};
