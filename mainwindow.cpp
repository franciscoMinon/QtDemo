#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "./ui_dialogNonModale.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pbFermer, &QPushButton::released, this, &MainWindow::handleButton);
    connect(ui->pbCoucou, &QPushButton::released, this, &MainWindow::handleBtnCoucou);
    connect(ui->pbRecopier, &QPushButton::released, this, &MainWindow::handlePbRecopierClicked);
    //connect(ui->menubar, &QMenuBar::triggered, this, &MainWindow::handleMenuFermer);
    connect(ui->actionFermer, &QAction::triggered, this, &MainWindow::handleMenuFermer);
    connect(ui->actionRecopier, &QAction::triggered, this, &MainWindow::handlePbRecopierClicked);
    connect(ui->pbX, &QPushButton::released, this, &MainWindow::handleX);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleButton()
{
    QCoreApplication::exit();
}
void MainWindow::handleBtnCoucou()
{
   ui->lblCoucou->setText( "Coucou");

   uiDialog =  new Ui::Dialog;
   dialog = new QDialog();
   uiDialog->setupUi( dialog);
   dialog->show();
}

void MainWindow::handlePbRecopierClicked()
{
    ui->lblCoucou->setText( ui->lineEdit->text());
    ui->pbRecopier->setStyleSheet("background-color: rgb(255,255,0);");
}


void MainWindow::handleMenuFermer()
{
    QMessageBox msgBox;
    msgBox.setText("Le document a été modifié.");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();
    if (ret==QMessageBox::Ok)
        QCoreApplication::exit();
}


void MainWindow::on_actionCoucou_triggered()
{
    ui->lblCoucou->setText( "Coucou");
}
 void MainWindow::mouseMoveEvent(QMouseEvent *qMouseEvent)
 {

     QMainWindow::mouseMoveEvent( qMouseEvent);
 }

 void MainWindow::mousePressEvent(QMouseEvent *mouseEvent)
 {
     x = mouseEvent->position().x();y = mouseEvent->position().y();
     ui->lblCoucou->setText( QString::number( x) + ":" + QString::number( y));
     QMainWindow::mousePressEvent( mouseEvent);

 }
 void MainWindow::handleX()
 {

 }


