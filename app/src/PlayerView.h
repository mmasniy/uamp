#ifndef PLAYERVIEW_H
#define PLAYERVIEW_H

#include <QWidget>

namespace Ui {
class PlayerView;
}

class PlayerView : public QWidget
{
    Q_OBJECT

public:
    explicit PlayerView(QWidget *parent = nullptr);
    ~PlayerView();

private:
    Ui::PlayerView *ui;
};

#endif // PLAYERVIEW_H
