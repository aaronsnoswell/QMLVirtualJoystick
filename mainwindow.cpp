
#include <QtQuick/QQuickView>
#include <QtQuick/QQuickItem>
#include <QUrl>
#include <QDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QQuickView *view = new QQuickView();
    QWidget *container = QWidget::createWindowContainer(view, this);
    container->setMinimumSize(160, 160);
    container->setMaximumSize(160, 160);
    container->setFocusPolicy(Qt::TabFocus);
    view->setSource(QUrl("qrc:/res/virtual_joystick.qml"));
    ui->verticalLayout->addWidget(container);

    // Attach to the 'mouse moved' signal
    QQuickItem *root = view->rootObject();
    connect(root, SIGNAL(joystick_moved(double, double)), this, SLOT(joystick_moved(double, double)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::mouse_moved Called when the virtual joystick is moved
 * @param x Mouse x position
 * @param y Mouse y position
 */
void MainWindow::joystick_moved(double x, double y) {
    qDebug() << x << ", " << y;
}



