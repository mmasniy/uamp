#pragma once

#include <QtMultimedia>
#include <QtMultimediaWidgets>
#include "FileTag.h"

class PlayerController : public QObject {
    Q_OBJECT
 public:
    explicit PlayerController();

    void SetSong(const FileTags *song) {m_player->setMedia(QUrl::fromLocalFile(song->tags.path));};
    void SetVolume(int value) {m_player->setVolume(value);};
    void Play() {m_player->play();};
    void Pause() {m_player->pause();};
    void Next() {};
    void Previous() {};
    void Backward() {m_player->setPosition(m_player->position() - 10000);};
    void Forward() {m_player->setPosition(m_player->position() + 10000);};
    void Mute(bool state) {m_player->setMuted(state);};
 private:
    QMediaPlayer *m_player;
};
