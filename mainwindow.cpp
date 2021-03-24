
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
    addJoyStick(ui->gridLayoutXY);
    addJoyStick(ui->gridLayoutHorizontal, HorizontalOnly);
    addJoyStick(ui->gridLayoutVertical, VerticalOnly);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addJoyStick(QLayout *layout_, JoyType type)
{
    QQuickView *view = new QQuickView();
    /* NB: We load the QML from a .qrc file becuase the Qt build step
     * that packages the final .app on Mac forgets to add the QML
     * if you reference it directly
     */
    view->setSource(QUrl("qrc:/res/virtual_joystick.qml"));

    /* Enable transparent background on the QQuickView
     * Note that this currently does not work on Windows
     */
#ifndef _WIN32
    view->setClearBeforeRendering(true);
    view->setColor(QColor(Qt::transparent));
#endif

    // Attach to the 'mouse moved' signal
    auto *root = view->rootObject();
    if (type == HorizontalOnly)
        root->setProperty("horizontalOnly", true);
    else if (type == VerticalOnly)
        root->setProperty("verticalOnly", true);
    connect(
        root,
        SIGNAL(joystick_moved(double, double)),
        this,
        SLOT(joystick_moved(double, double))
    );

    // Create a container widget for the QQuickView
    QWidget *container = QWidget::createWindowContainer(view, this);
    container->setMinimumSize(160, 160);
    container->setMaximumSize(160, 160);
    container->setFocusPolicy(Qt::TabFocus);
    layout_->addWidget(container);
}

/**
 * @brief MainWindow::mouse_moved Called when the virtual joystick is moved
 * @param x Mouse x position
 * @param y Mouse y position
 */
void MainWindow::joystick_moved(double x, double y) {
    qDebug() << x << ", " << y;
}



