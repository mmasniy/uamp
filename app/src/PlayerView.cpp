#include "PlayerView.h"

#include "FileTag.h"

PlayerView::PlayerView(QWidget *parent) : QWidget(parent), ui(new Ui::PlayerView) {
    ui->setupUi(this);
    setDefaultImage();

   m_timer = new QTimer(this);
   connect(m_timer, &QTimer::timeout, this, &PlayerView::UpdateSlider);
}

PlayerView::~PlayerView() {
    delete ui;
}

void PlayerView::ChangeVolume(int value) {
    m_player.SetVolume(value);
}

void PlayerView::Play(bool state) {
    if (state) {
        if (m_player.Play())
            m_timer->start(333);
        else
            emit BASSCantOpenFile(m_player.GetSong());
    }
    else {
        m_player.Pause();
        m_timer->stop();
    }
}

void PlayerView::Mute(bool state) {
    m_player.Mute(state);
}

void PlayerView::Next() {
    m_player.Next();
}

void PlayerView::Previous() {
    m_player.Previous();
}

void PlayerView::Backward() {
    m_player.Backward();
}

void PlayerView::Forward() {
    m_player.Forward();
}

void PlayerView::SetSong(FileTags *song) {
    ui->playerArtistName->setText(song->tags.artist);
    ui->playerTrackName->setText(song->tags.title);
    m_player.SetSong(song);
    ui->horizontalSlider->setMaximum(m_player.GetSongTime());
    if (song->getImage() != nullptr)
        ui->playerAlbumImage->setPixmap(*song->getImage());
    else
        setDefaultImage();
    Play(true);
}

void PlayerView::setDefaultImage() {
    QImage def_cover(":/playerIcons/default.png");
    m_picture = new QPixmap(QPixmap::fromImage(def_cover));
    ui->playerAlbumImage->setPixmap(*m_picture);
}

void PlayerView::SetImage(QPixmap *img) {
    if (img != nullptr)
        ui->playerAlbumImage->setPixmap(*img);
    else
        setDefaultImage();
}

void PlayerView::UpdateSlider() {
    if (static_cast<int>(m_player.GetCurrentSongTime()) == ui->horizontalSlider->maximum() && m_repeat) {
        m_player.SetPosition(0);
    }
    else if (static_cast<int>(m_player.GetCurrentSongTime()) == ui->horizontalSlider->maximum()) {
        emit SongEnded();
        return;
    }
    ui->horizontalSlider->setValue(m_player.GetCurrentSongTime());
}

void PlayerView::SliderClicked() {
    m_player.SetPosition(ui->horizontalSlider->value());
}

void PlayerView::EqualizerSettingsApply(FXData data) {
    m_player.ApplySettings(data);
}

void PlayerView::Stop() {
    ui->horizontalSlider->setValue(0);
    m_player.Stop();
    m_timer->stop();
}
