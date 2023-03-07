#pragma once

#include <QObject>
#include <QGraphicsItem>
#include <QPixMap>
#include <QTimerEvent>
#include <QPainter>
#include <QGraphicsScene>
#include <QRandomGenerator>

class ButterflyItem  : public QObject,public QGraphicsItem
{
	Q_OBJECT

public:
	explicit ButterflyItem(QObject *parent= nullptr);
	~ButterflyItem();
	void timerEvent(QTimerEvent* event); // 用于重绘蝴蝶
	/// @brief 获取图片区域的边框
	/// @return QRectF 边框
	QRectF boundingRect() const override;

protected:
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option,QWidget* widget);

private:
	bool up; // 蝴蝶翅膀上下的位置
	qreal angle;
	QPixmap pixUp;
	QPixmap pixDown;
};
