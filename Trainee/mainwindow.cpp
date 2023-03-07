#include "mainwindow.h"
#include "ui_mainwindow.h"

double primeiroNum;
bool digitandoSegNum = false;


MainWindow::MainWindow(QWidget *parent):
     QMainWindow(parent),
     ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(released()),this,SLOT(digito()));
    connect(ui->pushButton_1,SIGNAL(released()),this,SLOT(digito()));
    connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(digito()));
    connect(ui->pushButton_3,SIGNAL(released()),this,SLOT(digito()));
    connect(ui->pushButton_4,SIGNAL(released()),this,SLOT(digito()));
    connect(ui->pushButton_5,SIGNAL(released()),this,SLOT(digito()));
    connect(ui->pushButton_6,SIGNAL(released()),this,SLOT(digito()));
    connect(ui->pushButton_7,SIGNAL(released()),this,SLOT(digito()));
    connect(ui->pushButton_8,SIGNAL(released()),this,SLOT(digito()));
    connect(ui->pushButton_9,SIGNAL(released()),this,SLOT(digito()));

    connect(ui->pushButton_soma,SIGNAL(released()),this,SLOT(operacao_binaria()));
    connect(ui->pushButton_sub,SIGNAL(released()),this,SLOT(operacao_binaria()));

    ui->pushButton_soma->setCheckable(true);
    ui->pushButton_sub->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digito()
{
    QPushButton * Button = (QPushButton*)sender();

    double numero;
    QString novonumero;

    if ((ui->pushButton_soma->isChecked() || ui->pushButton_sub->isChecked()) && (!digitandoSegNum))
    {
        numero = Button->text().toDouble();
        digitandoSegNum = true;
    }

    else
    {
        numero = (ui->label->text() + Button->text()).toDouble();
    }

    novonumero = QString::number(numero,'g',9);

    ui->label->setText(novonumero);
}

void MainWindow::on_pushButton_clear_released()
{
    ui->pushButton_soma->setChecked(false);
    ui->pushButton_sub->setChecked(false);

    digitandoSegNum = false;

    ui->label->setText("0");
}

void MainWindow::on_pushButton_igual_released()
{

    double numero, segNum;
    QString novoNum;

    segNum = ui->label->text().toDouble();

    if (ui->pushButton_soma->isChecked())
    {
        numero = primeiroNum + segNum;
        novoNum = QString::number(numero,'g',9);
        ui->label->setText(novoNum);
        ui->pushButton_soma->setChecked(false);
    }

    else if (ui->pushButton_sub->isChecked())
    {
        numero = primeiroNum - segNum;
        novoNum = QString::number(numero,'g',9);
        ui->label->setText(novoNum);
        ui->pushButton_sub->setChecked(false);
    }

    digitandoSegNum = false;
}

void MainWindow::operacao_binaria()
{
    QPushButton * Button = (QPushButton*)sender();

    primeiroNum = ui->label->text().toDouble();

    Button->setChecked(true);
}









