#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QQuickView>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    enum JoyType {
        XY,
        HorizontalOnly,
        VerticalOnly
    };
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void addJoyStick(QLayout *layout_, JoyType type = XY);

private slots:
    void joystick_moved(double x, double y);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
