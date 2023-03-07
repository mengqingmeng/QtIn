#include "QWGraphicsView.h"

QWGraphicsView::QWGraphicsView(QWidget* parent)
{
}

void QWGraphicsView::mouseMoveEvent(QMouseEvent* event)
{
	QPoint pos = event->pos();
	emit mouseMovePoint(pos);
	QGraphicsView::mouseMoveEvent(event);
}

void QWGraphicsView::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton) {
		QPoint pos = event->pos();
		emit mouseClicked(pos);
	}

	QGraphicsView::mousePressEvent(event);
}