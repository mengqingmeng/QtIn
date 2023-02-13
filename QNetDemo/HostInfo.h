#ifndef HOSTINFO_H
#define HOSTINFO_H

#include <QDialog>
#include <QHostInfo>
#include <QPushButton>
#include <QNetworkInterface>

namespace Ui {
class HostInfo;
}

class HostInfo : public QDialog
{
    Q_OBJECT

public:
    explicit HostInfo(QWidget *parent = nullptr);
    ~HostInfo();

private:
    Ui::HostInfo *ui;

    /**
     * @brief protocolName 协议类型转名称
     * @param protocol  协议
     * @return
     */
    QString protocolName(QAbstractSocket::NetworkLayerProtocol protocol);

    /**
     * @brief showHostInfo 展示HostInfo
     * @param hostInfo
     */
    void showHostInfo(const QHostInfo hostInfo);
};

#endif // HOSTINFO_H
