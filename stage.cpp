#include "stage.h"
#include "ui_stage.h"

Stage::Stage(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Stage)
{
    ui->setupUi(this);
}

Stage::~Stage()
{
    delete ui;
}
