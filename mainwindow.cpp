#include "mainwindow.h"
#include "groupboxcollapser.h"

MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainWindowClass())
{
    ui->setupUi(this);

    QGroupBoxCollapser::installIntoGroupBox(ui->groupBox_1);
    QGroupBoxCollapser::installIntoGroupBox(ui->groupBox_2, ui->pushButton);  // corner widget

    ui->groupBox_4->setCornerWidget(ui->pushButton_2); // corner widget
}

MainWindow::~MainWindow()
{
    delete ui;
}
