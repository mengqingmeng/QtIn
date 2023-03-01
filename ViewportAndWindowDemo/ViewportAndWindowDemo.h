#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ViewportAndWindowDemo.h"
#include <QPainter>

class ViewportAndWindowDemo : public QMainWindow
{
    Q_OBJECT

public:
    ViewportAndWindowDemo(QWidget *parent = nullptr);
    ~ViewportAndWindowDemo();

    void paintEvent(QPaintEvent* event) override;

private:
    Ui::ViewportAndWindowDemoClass ui;
};
