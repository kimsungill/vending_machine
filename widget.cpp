#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    enabledcheck();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changemoney(int diff){
    money += diff;
    ui->lcdNumber->display(money);
}

void Widget::enabledcheck(){
    if (money < 200){
        ui->pbTea->setEnabled(false);
    } else {
        ui->pbTea->setEnabled(true);
    }

    if (money < 150) {
        ui->pbCola->setEnabled(false);
    } else{
        ui->pbCola->setEnabled(true);
    }

    if (money < 100) {
        ui->pbCoffee->setEnabled(false);
    } else {
        ui->pbCoffee->setEnabled(true);
    }
}

void Widget::on_pb10_clicked()
{
    changemoney(10);
    enabledcheck();
}

void Widget::on_pb50_clicked()
{
    changemoney(50);
    enabledcheck();
}

void Widget::on_pb100_clicked()
{
    changemoney(100);
    enabledcheck();
}

void Widget::on_pb500_clicked()
{
    changemoney(500);
    enabledcheck();
}

void Widget::on_pbCoffee_clicked()
{
    changemoney(-100);
    enabledcheck();
}

void Widget::on_pbCola_clicked()
{
    changemoney(-150);
    enabledcheck();
}

void Widget::on_pbTea_clicked()
{
    changemoney(-200);
    enabledcheck();
}

void Widget::on_pbreset_clicked()
{
    ohbak = money / 500;
    money = money % 500;
    bck = money / 100;
    money = money % 100;
    ohsip = money / 50;
    money = money % 50;
    sip = money / 10;
    QMessageBox::information(this, tr("Info"), QString("Money Return^_^ \n500 = %1 \n100 = %2 \n50 = %3 \n10 = %4")
                             .arg(ohbak)
                             .arg(bck)
                             .arg(ohsip)
                             .arg(sip));
    money = 0;
    ui->lcdNumber->display(money);
    enabledcheck();

}
