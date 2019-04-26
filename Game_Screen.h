#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include <QMainWindow>

namespace Ui {
class Game_Screen;
}

class Game_Screen : public QMainWindow
{
    Q_OBJECT

public:
    explicit Game_Screen(QWidget *parent = nullptr);
    ~Game_Screen();

private:
    Ui::Game_Screen *ui;
};

#endif // GAME_SCREEN_H
