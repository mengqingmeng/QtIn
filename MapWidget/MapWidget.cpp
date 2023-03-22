#include "MapWidget.h"

MapWidget::MapWidget(QWidget *parent)
    : QGraphicsView(parent)
{
    readMap();
    zoom = 50;

    int width = map.width();
    int height = map.height();

    QGraphicsScene* scene = new QGraphicsScene(this);
    scene->setSceneRect(-width / 2, -height / 2, width, height);
    setScene(scene);
    setCacheMode(CacheBackground);

    QSlider* slider = new QSlider;
    slider->setOrientation(Qt::Vertical);
    slider->setRange(0, 100);
    slider->setTickInterval(10);
    slider->setValue(50);
    connect(slider, &QSlider::valueChanged, this, &MapWidget::slotZoom);

    QLabel* zoominLabel = new QLabel;
    zoominLabel->setScaledContents(true);
    zoominLabel->setPixmap(QPixmap(":/MapWidget/zoomin.png"));

    QLabel* zoomoutLabel = new QLabel;
    zoomoutLabel->setScaledContents(true);
    zoomoutLabel->setPixmap(QPixmap(":/MapWidget/zoomout.png"));

    QLabel* label1 = new QLabel(tr("GraphicsView:"));
    QLabel* label2 = new QLabel(tr("GraphicsScene:"));
    QLabel* label3 = new QLabel(tr("map:"));
    viewCoord = new QLabel;
    sceneCoord = new QLabel;
    mapCoord = new QLabel;

    QGridLayout* gridLayout = new QGridLayout;
    gridLayout->addWidget(label1, 0, 0);
    gridLayout->addWidget(viewCoord, 0, 1);

    gridLayout->addWidget(label2, 1, 0);
    gridLayout->addWidget(sceneCoord, 1, 1);

    gridLayout->addWidget(label3, 2, 0);
    gridLayout->addWidget(mapCoord, 2, 1);
    gridLayout->setSizeConstraint(QLayout::SetFixedSize);

    QFrame* coordFrame = new QFrame;
    coordFrame->setLayout(gridLayout);

    QVBoxLayout* zoomLayout = new QVBoxLayout;
    zoomLayout->addWidget(zoomoutLabel);
    zoomLayout->addWidget(slider);
    zoomLayout->addWidget(zoominLabel);

    QVBoxLayout* coordLayout = new QVBoxLayout;
    coordLayout->addWidget(coordFrame);
    coordLayout->addStretch();

    QHBoxLayout* mainLayout = new QHBoxLayout;
    mainLayout->addLayout(zoomLayout);
    mainLayout->addLayout(coordLayout);
    mainLayout->addStretch();
    setLayout(mainLayout);
    setWindowTitle(tr("Map Widget"));
    setMinimumSize(600, 400);
}

MapWidget::~MapWidget()
{}

void MapWidget::readMap()
{
    QString mapName;
    QFile mapFile("map.txt");
    int openOk = mapFile.open(QIODevice::ReadOnly);
    if (openOk) {
        QTextStream ts(&mapFile);
        if (!ts.atEnd()) {
            ts >> mapName;
            ts >> x1 >> x2 >> y1 >> y2;
        }
    }

    map.load(mapName);
}

QPointF MapWidget::mapToMap(QPointF point)
{
    QPointF latLon;
    qreal sceneWidth = sceneRect().width();
    qreal sceneHeight = sceneRect().height();
    qreal lon = y1 - (sceneHeight / 2 + point.y()) * abs((y1 - y2) / sceneHeight);
    qreal lat = x1 + (sceneWidth / 2 + point.y()) * abs((y1 - y2) / sceneWidth);
    latLon.setX(lat);
    latLon.setY(lon);
    return latLon;
}

void MapWidget::drawBackground(QPainter* painter, const QPointF& rect)
{
}

void MapWidget::mouseMoveEvent(QMouseEvent* event)
{
}

void MapWidget::slotZoom(int val) {
    qreal s;
    if (val > zoom) {
        s = pow(1.01, (val - zoom));
    }
    else {
        s = pow(1 / 1.01, (zoom - val));
    }

    scale(s, s);
    zoom = val;
}