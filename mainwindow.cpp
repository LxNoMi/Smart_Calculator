#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myText = "";
    connect(ui->bt_1, SIGNAL(clicked(bool)), this, SLOT(getKeyBoard()));
    connect(ui->bt_2, SIGNAL(clicked(bool)), this, SLOT(getKeyBoard()));
    connect(ui->bt_3, SIGNAL(clicked(bool)), this, SLOT(getKeyBoard()));
    connect(ui->bt_4, SIGNAL(clicked(bool)), this, SLOT(getKeyBoard()));
    connect(ui->bt_5, SIGNAL(clicked(bool)), this, SLOT(getKeyBoard()));
    connect(ui->bt_6, SIGNAL(clicked(bool)), this, SLOT(getKeyBoard()));
    connect(ui->bt_7, SIGNAL(clicked(bool)), this, SLOT(getKeyBoard()));
    connect(ui->bt_8, SIGNAL(clicked(bool)), this, SLOT(getKeyBoard()));
    connect(ui->bt_9, SIGNAL(clicked(bool)), this, SLOT(getKeyBoard()));
    connect(ui->bt_cifang, SIGNAL(clicked(bool)), this, SLOT(getKeyBoard()));
    connect(ui->bt_clear, SIGNAL(clicked(bool)), this, SLOT(getKeyBoard()));
    connect(ui->bt_count, SIGNAL(clicked(bool)), this, SLOT(getKeyBoard()));
    connect(ui->bt_delete, SIGNAL(clicked(bool)), this, SLOT(getKeyBoard()));
    connect(ui->bt_you, SIGNAL(clicked(bool)), this, SLOT(getKeyBoard()));
    connect(ui->bt_zuo, SIGNAL(clicked(bool)), this, SLOT(getKeyBoard()));
    connect(ui->add, SIGNAL(clicked(bool)), this, SLOT(getKeyBoard()));
    connect(ui->sub, SIGNAL(clicked(bool)), this, SLOT(getKeyBoard()));
    connect(ui->plus, SIGNAL(clicked(bool)), this, SLOT(getKeyBoard()));
    connect(ui->chufa, SIGNAL(clicked(bool)), this, SLOT(getKeyBoard()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getKeyBoard()
{
    myText = ui->textLineEdit->text();
    QString retVal = "0";
    QPushButton *bt = static_cast<QPushButton*>(this->sender());
    QString text = bt->text();
    QString result = "0";
    if(text == "➕")
        myText.append("+");
    else if(text == "➖")
        myText.append("-");
    else if(text == "x")
        myText.append("*");
    else if(text == "➗")
        myText.append("/");
    else if(text == "Λ")
        myText.append("^");
    else if(text == "计算"){
        retVal = Run(myText);
        qDebug() << retVal << endl;
        result = retVal;
    }
    else if(text == "清空"){
        myText = "";
        ui->value->setText("");
    }

    else if(text == "退格")
        myText.chop(1);
    else
        myText.append(text);
    ui->textLineEdit->setText(myText);
    ui->value->setText(result);
}

