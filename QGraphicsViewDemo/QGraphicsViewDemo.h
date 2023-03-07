#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QGraphicsViewDemo.h"
#include <QLabel>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include "QWGraphicsView.h"

class QGraphicsViewDemo : public QMainWindow
{
    Q_OBJECT

public:
    QGraphicsViewDemo(QWidget *parent = nullptr);
    ~QGraphicsViewDemo();

private:
    Ui::QGraphicsViewDemoClass ui;

    QGraphicsScene* scene = nullptr;
    QLabel* labelViewCord = nullptr;
    QLabel* labelSceneCord = nullptr;
    QLabel* labelItemCord = nullptr;
    void initGraphicsSystem();

protected:
    void resizeEvent(QResizeEvent* event);

};
