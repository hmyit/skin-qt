#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->btn, SIGNAL(clicked()), this, SLOT(loadSkin()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadSkin()
{
    QFile file(":/skin.qss");
    file.open(QFile::ReadOnly);
    QString btnstylesheet = QObject::tr(file.readAll());
    qApp->setStyleSheet(btnstylesheet);
}
