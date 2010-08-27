#ifndef MEDIA_BROWSER_MUSIC_BROWSER_VIEW_H
#define MEDIA_BROWSER_MUSIC_BROWSER_VIEW_H

#include "MediaBrowserView.h"

#include <QTreeView>

class QLineEdit;
class QMediaPlayer;
class QSortFilterProxyModel;
class QToolButton;
class QTreeView;

class MusicListModel;

class MusicBrowserView : public MediaBrowserView
{
    Q_OBJECT

public:
    MusicBrowserView(QWidget *parent = NULL);
    virtual void addMediaParsers();

protected:
    virtual void showEvent(QShowEvent *event);

private Q_SLOTS:
    void playButtonPressed();
    void selectionChanged(const QItemSelection &selected, const QItemSelection &deselected);
    void textChanged(const QString &text);

    // argh. can't Qt just handle pressed buttons properly?
    void playPressed();

private:
    QTreeView *m_music_list_view;
    MusicListModel *m_music_list_model;
    QSortFilterProxyModel *m_proxy_music_list_model;
    QMediaPlayer *m_player;
    QString m_current_file_path;
    QLineEdit *m_search_field;
    QToolButton *m_play_button;
};

class MusicBrowserTreeView : public QTreeView
{
    Q_OBJECT
public:
    MusicBrowserTreeView(MusicListModel *music_list_model, QSortFilterProxyModel *proxy_music_list_model)
        : m_music_list_model(music_list_model)
        , m_proxy_music_list_model(proxy_music_list_model)
    { }
    void paintEvent(QPaintEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
Q_SIGNALS:
    void playMusic();
private:
    MusicListModel *m_music_list_model;
    QSortFilterProxyModel *m_proxy_music_list_model;
};

#endif // MEDIA_BROWSER_MUSIC_BROWSER_VIEW_H
