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
	startTimer(100); // ������ʱ��
}

ButterflyItem::~ButterflyItem()
{}

void ButterflyItem::timerEvent(QTimerEvent * event)
{
	qreal edgeX = scene()->sceneRect().right() + boundingRect().width() / 2;
	qreal edgeTop = scene()->sceneRect().top() + boundingRect().height() / 2;
	qreal edgeBottom = scene()->sceneRect().bottom() + boundingRect().height() / 2;

	if (pos().x() >= edgeX) // ����X�߽磬�ص����
		setPos(scene()->sceneRect().left(), pos().y());

	if(pos().y() >= edgeBottom) // ����Y�ױߣ��ص�����
		setPos(pos().x(),scene()->sceneRect().top());

	if (pos().y() <= edgeTop) // ����Y�ϱߣ��ص�����
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
