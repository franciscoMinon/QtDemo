#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; class Dialog;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void mouseMoveEvent( QMouseEvent *event) override;
    void mousePressEvent( QMouseEvent *mouseEvent) override;
private slots:  // obsolète
    void on_actionCoucou_triggered();

private:
    Ui::MainWindow *ui;
    Ui::Dialog *uiDialog;
    QDialog* dialog;

    qreal x = 0, y = 0;
    void handleButton();
    void handleBtnCoucou();
    void handleMenuFermer();
    void handlePbRecopierClicked();
    void handleX();
};
#endif // MAINWINDOW_H
