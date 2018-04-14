#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

   //QMediaPlayer *gamebgsound;
    QMediaPlayer* gamebgsound;
    QMediaPlayer* bgsound;


private slots:

    void on_pushButton_5_clicked();

    void on_lineEdit_returnPressed();
    const void showTime();
    bool checkWord();
    const void outputResult(bool result);
    const void changePicture();
    const void loadImages_1(QVector<QString> &imgIcon);
    const void loadImages_2(QVector<QString> &imgIcon);
    const void loadImages_3(QVector<QString> &imgIcon);
    const void clearFeedback();
    int generatePos();
    //stage *stg;
    const void wordfeedback(bool matchresult,int countEntered);

    void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;
    //int *countdown_sec;
};

#endif // MAINWINDOW_H
