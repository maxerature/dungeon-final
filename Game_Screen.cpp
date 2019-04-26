#include "Game_Screen.h"
#include "ui_Game_Screen.h"

Game_Screen::Game_Screen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Game_Screen)
{
    ui->setupUi(this);
}

Game_Screen::~Game_Screen()
{
    delete ui;
}
