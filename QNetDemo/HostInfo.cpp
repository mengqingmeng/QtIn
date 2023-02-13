#include "HostInfo.h"
#include "ui_HostInfo.h"

HostInfo::HostInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HostInfo)
{
    ui->setupUi(this);

    // 获取本机名称和网络连接信息
    connect(ui->btnHostInfo,&QPushButton::clicked,this,[&](){
       QString hostName = QHostInfo::localHostName(); // 本地主机名
       ui->plainTextEdit->appendPlainText("本地主机名：" + hostName + "\n");
       QHostInfo hostInfo = QHostInfo::fromName(hostName);

       showHostInfo(hostInfo);
    });

    // 清除文本
    connect(ui->btnClear,&QPushButton::clicked,this,[&](){
        ui->plainTextEdit->clear();
    });

    // looksup
    connect(ui->btnIpOnfo,&QPushButton::clicked,this,[&](){
        QString ip = ui->lineEdit->text();

        if(ip.isEmpty()) return;

        QHostInfo::lookupHost(ip,this,[&](const QHostInfo hostInfo){
            showHostInfo(hostInfo);
        });
    });

    // 接口
    connect(ui->btnAllInterfaces,&QPushButton::clicked,this,[&](){
        QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();
        for(auto& interface:interfaces){
            if(!interface.isValid())
                continue;

            ui->plainTextEdit->appendPlainText("设备名称：" + interface.humanReadableName());
            ui->plainTextEdit->appendPlainText("硬件地址：" + interface.hardwareAddress());
            QList<QNetworkAddressEntry> entries = interface.addressEntries();
            for(auto& entry:entries){
                ui->plainTextEdit->appendPlainText("ip：" + entry.ip().toString());
                ui->plainTextEdit->appendPlainText("子网掩码：" + entry.netmask().toString());
                ui->plainTextEdit->appendPlainText("广播地址：" + entry.broadcast().toString());
                ui->plainTextEdit->appendPlainText("\n");
            }

            ui->plainTextEdit->appendPlainText("--------------");
        }
    });

    // 地址
}

HostInfo::~HostInfo()
{
    delete ui;
}

QString HostInfo::protocolName(QAbstractSocket::NetworkLayerProtocol protocol)
{
    switch (protocol) {
    case QAbstractSocket::IPv4Protocol:
        return "IPv4 Protocol";
    case QAbstractSocket::IPv6Protocol:
        return "IPv6 Protocol";
    default:
        return "Unknown Network Layer Protocol";
    }
}

void HostInfo::showHostInfo(const QHostInfo hostInfo)
{
    QList<QHostAddress> addresses = hostInfo.addresses();

    bool onlyIpv4 = ui->checkIpv4->isChecked();
    for(auto& address:addresses){
         auto protocol = address.protocol();
         if(protocol != QAbstractSocket::IPv4Protocol && onlyIpv4){

         }else{
             ui->plainTextEdit->appendPlainText("协议：" + protocolName(protocol));
             ui->plainTextEdit->appendPlainText("本机IP地址：" + address.toString());
             ui->plainTextEdit->appendPlainText("");
         }
    }
}
