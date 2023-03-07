#include "ButterflyItem.h"
#include <math.h>

const static double PI = 3.14156;

ButterflyItem::ButterflyItem(QObject *parent)
	: QObject(parent)
{
	up = true;
	angle = 0.0;
	pixUp.load(":/Butterfly/butterfly_1.png");
	pixDown.load(":/Butterfly/butterfly_2.png");
	startTimer(100); // 启动定时器
}

ButterflyItem::~ButterflyItem()
{}

void ButterflyItem::timerEvent(QTimerEvent * event)
{
	qreal edgeX = scene()->sceneRect().right() + boundingRect().width() / 2;
	qreal edgeTop = scene()->sceneRect().top() + boundingRect().height() / 2;
	qreal edgeBottom = scene()->sceneRect().bottom() + boundingRect().height() / 2;

	if (pos().x() >= edgeX) // 超过X边界，回到左边
		setPos(scene()->sceneRect().left(), pos().y());

	if(pos().y() >= edgeBottom) // 超过Y底边，回到上面
		setPos(pos().x(),scene()->sceneRect().top());

	if (pos().y() <= edgeTop) // 超过Y上边，回到底面
		setPos(pos().x(), scene()->sceneRect().bottom());

	// qrand() % 10  0-10
	angle += QRandomGenerator::global()->bounded(10) / 20.0; // 0~0.5

	qreal dx = std::fabs(std::sin(angle * PI) * 10.0);
	qreal dy = QRandomGenerator::global()->bounded(20) - 10; // -10~10
	setPos(mapToScene(dx, dy));
}

QRectF ButterflyItem::boundingRect() const
{
	qreal adjust = 2;
	return QRectF( -pixUp.width() / 2 - adjust, -pixUp.height () / 2 - adjust,pixUp.width() + 2 * adjust,pixUp.height() + 2 * adjust);
}

void ButterflyItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	if (up) {
		painter->drawPixmap(boundingRect().topLeft(), pixUp);
	}
	else {
		painter->drawPixmap(boundingRect().topLeft(), pixDown);
	}
	up = !up;
}
