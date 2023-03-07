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
	void timerEvent(QTimerEvent* event); // �����ػ����
	/// @brief ��ȡͼƬ����ı߿�
	/// @return QRectF �߿�
	QRectF boundingRect() const override;

protected:
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option,QWidget* widget);

private:
	bool up; // ����������µ�λ��
	qreal angle;
	QPixmap pixUp;
	QPixmap pixDown;
};
