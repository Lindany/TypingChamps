#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <windows.h>
#include <fstream>
#include <ctime>
#include <QTimer>
#include <QVector>
#include <QDebug>


using namespace std;

/*To initialise the global variables*/
static int countdown_sec, score=0, countEntered=0,stage=1;
static QString  str_stage="1",previous, currentpic;
static QTimer *timer;
static QVector<QString> imgIcon;
static QVector<QLabel> *vecLabel;
QVector<int> usedPos;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/images/PictureWord/logo.png");
    ui->label_pic->setPixmap(pix);
    ui->label_pic->setScaledContents(true);
    countdown_sec=60+1;

    //vecLabel.append(ui->chck_5);

    //gamebgsound = new QMediaPlayer();
    //gamebgsound->setMedia(QUrl("qrc:/sound_theme/bgsoundtrack.mp3"));
    //gamebgsound->play();
    //gamebgsound->volume(50);

    //bgsound = new QMediaPlayer();
    //bgsound->setMedia(QUrl("qrc:/sound_theme/gametheme.mp3"));


}

MainWindow::~MainWindow()
{
    delete ui;
}

const void MainWindow::showTime(){
    /**Displays count down second every time being called at constructor slot
     * but it stops when it reaches zero and disable input box(line edit)
     * to restrict more input words. Also displays game over image.
     **/
   // bgsound->stop();
    if (countdown_sec<=0){
        timer->stop();
        ui->lineEdit->setEnabled(false);
        QPixmap pix(":/images/Math_Test/gameover.png");
        ui->label_pic->setPixmap(pix);
        ui->label_pic->setScaledContents(true);
        ui->pushButton_5->setEnabled(true);
        //put gameover image
    //    bgsound->stop();
      //  gamebgsound->play();

        /** outputResult(checkWord());
         timer->start();
         countdown_sec=10+1;
        countEntered++;*/
    }else{
        ui->pushButton_5->setEnabled(false);
    countdown_sec--;
    QString time_text = QString::number(countdown_sec);
    ui->label_timer->setText(time_text);
    }
}


void MainWindow::on_pushButton_5_clicked()//Sart button
{
    /**This function generate the following picture name(START)**/
    if (score>=40 && stage<3){
           stage++;
    }

    countEntered=0;

    if(stage==3){
        loadImages_3(imgIcon);
        str_stage="3";
    }else if(stage==2){
        loadImages_2(imgIcon);
        str_stage="2";
    }else if(stage==1){
        loadImages_1(imgIcon);
        str_stage="1";
    }

    ui->label_11->setText("Stage "+str_stage);

    countdown_sec=60+1;
    score=0;
    ui->lineEdit->setEnabled(true);

    clearFeedback();
    changePicture();
    ui->lineEdit->setFocus();

    //gamebgsound->stop();

    //bgsound->play();


          /**Timer start counting down from 60**/
     timer = new QTimer(this);
     connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
     timer->start(1000); //Every 1 second.

}

const void MainWindow::wordfeedback(bool matchresult,int countEntered){

    if(matchresult){
        QPixmap pix(":/images/PictureWord/240px-Symbol_OK.svg.png");
        switch (countEntered) {
        case 0:
            ui->chck_a->setPixmap(pix);
            ui->chck_a->setScaledContents(true);
            break;
        case 1:
            ui->chck_b->setPixmap(pix);
            ui->chck_b->setScaledContents(true);
            break;
        case 2:
            ui->chck_c->setPixmap(pix);
            ui->chck_c->setScaledContents(true);
            break;
        case 3:
            ui->chck_d->setPixmap(pix);
            ui->chck_d->setScaledContents(true);
            break;
        case 4:
            ui->chck_e->setPixmap(pix);
            ui->chck_e->setScaledContents(true);
            break;
        case 5:
            ui->chck_g->setPixmap(pix);
            ui->chck_g->setScaledContents(true);
            break;
        case 6:
            ui->chck_h->setPixmap(pix);
            ui->chck_h->setScaledContents(true);
            break;
        case 7:
            ui->chck_i->setPixmap(pix);
            ui->chck_i->setScaledContents(true);
            break;
        case 8:
            ui->chck_j->setPixmap(pix);
            ui->chck_j->setScaledContents(true);
            break;
        case 9:
            ui->chck_k->setPixmap(pix);
            ui->chck_k->setScaledContents(true);
            break;
        case 10:
            ui->chck_l->setPixmap(pix);
            ui->chck_l->setScaledContents(true);
            break;
        case 11:
            ui->chck_m->setPixmap(pix);
            ui->chck_m->setScaledContents(true);
            break;
        case 12:
            ui->chck_n->setPixmap(pix);
            ui->chck_n->setScaledContents(true);
            break;
        case 13:
            ui->chck_o->setPixmap(pix);
            ui->chck_o->setScaledContents(true);
            break;
        case 14:
            ui->chck_p->setPixmap(pix);
            ui->chck_p->setScaledContents(true);
            break;
        case 15:
            ui->chck_q->setPixmap(pix);
            ui->chck_q->setScaledContents(true);
            break;
        case 16:
            ui->chck_r->setPixmap(pix);
            ui->chck_r->setScaledContents(true);
            break;
        case 17:
            ui->chck_s->setPixmap(pix);
            ui->chck_s->setScaledContents(true);
            break;
        case 18:
            ui->chck_t->setPixmap(pix);
            ui->chck_t->setScaledContents(true);
            break;
        case 19:
            ui->chck_u->setPixmap(pix);
            ui->chck_u->setScaledContents(true);
            break;

        default:
            ui->chck_v->setPixmap(pix);
            ui->chck_v->setScaledContents(true);
            break;
        }
    }else{
        QPixmap pix(":/images/PictureWord/wrong.jpg");
        switch (countEntered) {
        case 0:
            ui->chck_a->setPixmap(pix);
            ui->chck_a->setScaledContents(true);
            break;
        case 1:
            ui->chck_b->setPixmap(pix);
            ui->chck_b->setScaledContents(true);
            break;
        case 2:
            ui->chck_c->setPixmap(pix);
            ui->chck_c->setScaledContents(true);
            break;
        case 3:
            ui->chck_d->setPixmap(pix);
            ui->chck_d->setScaledContents(true);
            break;
        case 4:
            ui->chck_e->setPixmap(pix);
            ui->chck_e->setScaledContents(true);
            break;
        case 5:
            ui->chck_g->setPixmap(pix);
            ui->chck_g->setScaledContents(true);
            break;
        case 6:
            ui->chck_h->setPixmap(pix);
            ui->chck_h->setScaledContents(true);
            break;
        case 7:
            ui->chck_i->setPixmap(pix);
            ui->chck_i->setScaledContents(true);
            break;
        case 8:
            ui->chck_j->setPixmap(pix);
            ui->chck_j->setScaledContents(true);
            break;
        case 9:
            ui->chck_k->setPixmap(pix);
            ui->chck_k->setScaledContents(true);
            break;
        case 10:
            ui->chck_l->setPixmap(pix);
            ui->chck_l->setScaledContents(true);
            break;
        case 11:
            ui->chck_m->setPixmap(pix);
            ui->chck_m->setScaledContents(true);
            break;
        case 12:
            ui->chck_n->setPixmap(pix);
            ui->chck_n->setScaledContents(true);
            break;
        case 13:
            ui->chck_o->setPixmap(pix);
            ui->chck_o->setScaledContents(true);
            break;
        case 14:
            ui->chck_p->setPixmap(pix);
            ui->chck_p->setScaledContents(true);
            break;
        case 15:
            ui->chck_q->setPixmap(pix);
            ui->chck_q->setScaledContents(true);
            break;
        case 16:
            ui->chck_r->setPixmap(pix);
            ui->chck_r->setScaledContents(true);
            break;
        case 17:
            ui->chck_s->setPixmap(pix);
            ui->chck_s->setScaledContents(true);
            break;

        case 18:
            ui->chck_t->setPixmap(pix);
            ui->chck_t->setScaledContents(true);
            break;
        case 19:
            ui->chck_u->setPixmap(pix);
            ui->chck_u->setScaledContents(true);
            break;

        default:
            ui->chck_v->setPixmap(pix);
            ui->chck_v->setScaledContents(true);
            break;
        }
    }

}

const void MainWindow::outputResult(bool matchresult){
    /**Function to display tick if did match the word else wrong
     * sign and also increases the user score point
     **/\
    wordfeedback(matchresult,countEntered);
    if (matchresult){
        score+=5;
        QString score_text = QString::number(score);
        ui->label_3->setText(score_text);
    }
    qDebug()<<"outputresults is ok";
    changePicture();

}

void MainWindow::on_lineEdit_returnPressed()
{/**Loads images aand call functions to check the word and display relevant
   images**/
    outputResult(checkWord());
   countEntered++;

}

const void MainWindow::changePicture(){

     ui->label_pic->clear();
     int genPos = generatePos();

     if (genPos != -1){
        currentpic = imgIcon[genPos];
     }else{
         currentpic = imgIcon[usedPos.at(usedPos.length()-1)];
     }
     QPixmap pix(":/images/PictureWord/EnglishLevel"+str_stage+"/"+currentpic);
     ui->label_pic->setPixmap(pix);
     ui->label_pic->setScaledContents(true);
     ui->lineEdit->clear();

}

bool MainWindow::checkWord(){
    /**Checks if the user input word is equals to the picture name and returns a booleand value
     * @param : variable word string to check with the input word**/

     QString userWord = ui->lineEdit->text();
   int dotindex = currentpic.indexOf(".");
   QString correctWord = currentpic.left(dotindex);
   //previous = correctWord;
    qDebug()<<correctWord;
   ui->label_10->setText(correctWord+":"+userWord);
  // ui->lineEdit->clear();

   if(correctWord.compare(userWord)==0)
       return true;
   return false;
}

int MainWindow::generatePos(){

    srand(unsigned(time(0)));
    if(usedPos.length()==imgIcon.length()-1) usedPos.clear();

    int imgPos = rand()%imgIcon.length();
    while(usedPos.contains(imgPos)){
        imgPos = rand()%imgIcon.length();
    }
    usedPos.append(imgPos);
    return imgPos;
}

const void MainWindow::clearFeedback(){
    ui->chck_a->clear();
    ui->chck_b->clear();
    ui->chck_c->clear();
    ui->chck_d->clear();
    ui->chck_e->clear();
    ui->chck_g->clear();
    ui->chck_h->clear();
    ui->chck_i->clear();
    ui->chck_j->clear();
    ui->chck_k->clear();
    ui->chck_l->clear();
    ui->chck_m->clear();
    ui->chck_n->clear();
    ui->chck_o->clear();
    ui->chck_p->clear();
    ui->chck_q->clear();
    ui->chck_r->clear();
    ui->chck_s->clear();
    ui->chck_t->clear();
    ui->chck_u->clear();
    ui->chck_v->clear();
}

const void MainWindow::loadImages_1(QVector<QString> &imgIcon){ //Populate stage 1 names
    imgIcon.clear();
    imgIcon.append("africa.jpg");
    imgIcon.append("apple.jpg");
    imgIcon.append("arm.jpeg");
    imgIcon.append("bag.png");
    imgIcon.append("bag.png");
    imgIcon.append("balloons.jpg");
    imgIcon.append("banana.png");
    imgIcon.append("beans.jpg");
    imgIcon.append("bed.png");
    imgIcon.append("bird.jpg");
    imgIcon.append("book.jpg");
    imgIcon.append("bread.jpg");
    imgIcon.append("brushing.png");
    imgIcon.append("carrot.jpg");
    imgIcon.append("chair.jpg");
    imgIcon.append("chess.png");
    imgIcon.append("chick.jpg");
    imgIcon.append("chicken.png");
    imgIcon.append("chips.jpg");
    imgIcon.append("coconut.jpg");
    imgIcon.append("cow.jpg");
    imgIcon.append("cry.jpeg");
    imgIcon.append("dinner.jpg");
    imgIcon.append("doctor.png");
    imgIcon.append("dog.png");
    imgIcon.append("dog.png");
    imgIcon.append("dress.png");
    imgIcon.append("duck.png");
    imgIcon.append("mouth.jpg");
    imgIcon.append("ears.png");
    imgIcon.append("eggs.jpg");
    imgIcon.append("eyes.png");
    imgIcon.append("feet.png");
    imgIcon.append("fire.png");
    imgIcon.append("fish.png");
    imgIcon.append("flowers.jpg");
    imgIcon.append("frog.png");
    imgIcon.append("giraffe.png");
    imgIcon.append("glasses.png");
    imgIcon.append("goat.png");
    imgIcon.append("grapes.jpg");
    imgIcon.append("hair.jpg");
    imgIcon.append("hand.png");
    imgIcon.append("handbag.jpg");
    imgIcon.append("hippo.png");
    imgIcon.append("horse.png");
    imgIcon.append("house.png");
    imgIcon.append("jacket.png");
    imgIcon.append("jar.png");
    imgIcon.append("jeans.jpg");
    imgIcon.append("juice.jpg");
        imgIcon.append("lamp.jpg");
        imgIcon.append("laptop.jpg");
        imgIcon.append("lime.jpg");
        imgIcon.append("lemon.png");
        imgIcon.append("mango.jpg");
        imgIcon.append("fish.png");
        imgIcon.append("map.jpg");
        imgIcon.append("milk.jpg");
        imgIcon.append("monkey.jpg");
        imgIcon.append("monster.png");
        imgIcon.append("mouse.png");
        imgIcon.append("nose.jpg");
        imgIcon.append("orange.jpg");
        imgIcon.append("paper.jpg");
        imgIcon.append("pear.jpg");
        imgIcon.append("peas.png");
        imgIcon.append("pen.jpg");
        imgIcon.append("pencil.jpg");
        imgIcon.append("phone.jpg");
        imgIcon.append("read.jpg");
        imgIcon.append("rice.jpg");
        imgIcon.append("rubber.png");
        imgIcon.append("ruler.png");
        imgIcon.append("sausage.png");
        imgIcon.append("sheep.gif");
        imgIcon.append("shirt.jpg");
        imgIcon.append("shoes.png");
        imgIcon.append("snake.jpg");
        imgIcon.append("socks.png");
        imgIcon.append("sofa.jpg");
        imgIcon.append("sunset.jpeg");
        imgIcon.append("table.png");
        imgIcon.append("tomato.jpg");
        imgIcon.append("trousers.png");
        imgIcon.append("walk.jpeg");
        imgIcon.append("watch.jpg");
}

const void MainWindow::loadImages_2(QVector<QString> &imgIcon){ //Populate stage 2 names
    imgIcon.clear();
    imgIcon.append("addition.png");
    imgIcon.append("alphabets.jpg");
    imgIcon.append("athlete.jpg");
    imgIcon.append("audience.jpg");
    imgIcon.append("biscuit.jpg");
    imgIcon.append("captain.jpeg");
    imgIcon.append("cemetery.jpg");
    imgIcon.append("cinnamon.jpg");
    imgIcon.append("computer.jpg");
    imgIcon.append("wardrobe.png");
    imgIcon.append("computer.png");
    imgIcon.append("computer.png");
    imgIcon.append("crocodile.jpg");
    imgIcon.append("cutleries.png");
    imgIcon.append("decimals.png");
    imgIcon.append("desert.jpg");
    imgIcon.append("dessert.jpg");
    imgIcon.append("diamond.jpeg");
    imgIcon.append("dictionary.png");
    imgIcon.append("division.gif");
    imgIcon.append("elephant.jpg");
    imgIcon.append("crocodile.jpg");
    imgIcon.append("cutleries.png");
    imgIcon.append("elephant.jpg");
    imgIcon.append("energy.jpg");
    imgIcon.append("engineer.jpg");
    imgIcon.append("equal.jpg");
    imgIcon.append("expensive.png");
    imgIcon.append("explode.png");
    imgIcon.append("factory.png");
    imgIcon.append("forward.jpg");
    imgIcon.append("fraction.png");
    imgIcon.append("frame.jpg");
    imgIcon.append("fridge.jpg");
    imgIcon.append("furniture.jpg");
    imgIcon.append("happiness.jpeg");
    imgIcon.append("graveyard.jpg");
    imgIcon.append("harvest.jpg");
    imgIcon.append("luggage.jpg");
    imgIcon.append("marriage.jpg");
    imgIcon.append("negative.png");
    imgIcon.append("newspaper.png");
    imgIcon.append("passengers.png");
    imgIcon.append("pause.jpg");
    imgIcon.append("poem.jpg");
    imgIcon.append("principal.png");
    imgIcon.append("puzzle.png");
    imgIcon.append("refrigerator.jpg");
    imgIcon.append("restaurant.png");
    imgIcon.append("shadow.png");
    imgIcon.append("shower.png");
    imgIcon.append("sneeze.jpg");
    imgIcon.append("spaghetti.jpg");
    imgIcon.append("sponge.jpg");
    imgIcon.append("statue.jpg");
    imgIcon.append("strength.jpg");
    imgIcon.append("surprise.jpg");
    imgIcon.append("sweater.png");
    imgIcon.append("timetable.jpg");
    imgIcon.append("tornado.jpeg");
    imgIcon.append("traffic.jpg");
    imgIcon.append("trophies.jpg");
    imgIcon.append("twins.jpg");
    imgIcon.append("vacuum.jpg");
    imgIcon.append("violence.jpg");
    imgIcon.append("volcano.jpg");
    imgIcon.append("wardrobe.png");
    //imgIcon.append("vacuum.jpg");
}

const void MainWindow::loadImages_3(QVector<QString> &imgIcon){ //Populate stage 3 names
    imgIcon.clear();
    imgIcon.append("achievements.jpg");
    imgIcon.append("arithmetic.png");
    imgIcon.append("gentleman.jpg");
    imgIcon.append("auditorium.jpg");
    imgIcon.append("beautiful.gif");
    imgIcon.append("calculator.jpeg");
    imgIcon.append("cantaloupe.png");
    imgIcon.append("carpenter.gif");
    imgIcon.append("cauliflower.jpg");
    imgIcon.append("caumoflage.png");
    imgIcon.append("chameleon.png");
    imgIcon.append("congratulations.png");
    imgIcon.append("deodorant.jpg");
    imgIcon.append("diarrhoea.jpg");
    imgIcon.append("disagreement.png");
    imgIcon.append("emergency.png");
    imgIcon.append("encyclopedia.jpg");
    imgIcon.append("equator.jpg");
    imgIcon.append("EXAMPAD.jpg");
    imgIcon.append("excitement.jpg");
    imgIcon.append("forgiveness.jpg");
    imgIcon.append("gossiping.png");
    imgIcon.append("handkerchief.jpg");
    imgIcon.append("hippopotamus.png");
    imgIcon.append("handkerchief.jpg");
    imgIcon.append("horizontal.png");
    imgIcon.append("imagination.png");
    imgIcon.append("information.png");
    imgIcon.append("ingredients.jpeg");
    imgIcon.append("invitation.png");
    imgIcon.append("island.png");
    imgIcon.append("jewellery.jpg");
    imgIcon.append("knives.jpg");
    imgIcon.append("laboratory.jpeg");
    imgIcon.append("notebook.jpg");
    imgIcon.append("pattern.jpg");
    imgIcon.append("questionnaire.jpg");
    imgIcon.append("rhino.jpg");
    imgIcon.append("slippery.png");
    imgIcon.append("squeeze.jpg");
    imgIcon.append("stationary.jpg");
    imgIcon.append("technology.jpg");
    imgIcon.append("telephone.jpg");
    imgIcon.append("thermometer.jpg");
    imgIcon.append("unbelievable.png");
    imgIcon.append("vehicle.png");
    imgIcon.append("vertical.jpg");
    imgIcon.append("watermelon.jpg");
    imgIcon.append("weapons.gif");
}

void MainWindow::on_pushButton_7_clicked()
{
}
