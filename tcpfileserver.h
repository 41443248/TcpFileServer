#ifndef TCPFILESERVER_H
#define TCPFILESERVER_H

#include <QDialog>
#include <QtWidgets>
#include <QtNetwork>

class TcpFileServer : public QDialog
{
    Q_OBJECT

public:
    explicit TcpFileServer(QWidget *parent = nullptr);
    ~TcpFileServer() override;
private slots:
    void start();
    void acceptConnection();
    void updateServerProgress();
private:
    QProgressBar     *serverProgressBar;
    QLabel           *serverStatusLabel;
    QPushButton      *startButton;
    QPushButton      *quitButton;
    QDialogButtonBox *buttonBox;

    QTcpServer       tcpServer;  // for listening
    QTcpSocket       tcpServerConnection; // for data transporting
    qint64           totalBytes;
    qint64           bytesReceived;
    qint64           fileNameSize;
    QString          fileName;
    QFile            *localFile;
    QByteArray       inBlock;    // for buffering
};
#endif // TCPFILESERVER_H
