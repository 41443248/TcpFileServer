#include "tcpfileserver.h"

TcpFileServer::TcpFileServer(QWidget *parent)
    : QDialog(parent)
{
    totalBytes = 0;
    bytesReceived = 0;
    fileNameSize = 0;
    serverProgressBar = new QProgressBar;
    serverStatusLabel = new QLabel(tr("伺服器就緒"));
    startButton = new QPushButton("接收");
    quitButton = new QPushButton("退出");
    buttonBox = new QDialogButtonBox;
    buttonBox->addButton(startButton,QDialogButtonBox::ActionRole);
    buttonBox->addButton(quitButton,QDialogButtonBox::RejectRole);
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(serverProgressBar);
    mainLayout->addWidget(serverStatusLabel);
    mainLayout->addStretch();
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);
    setWindowTitle("接收檔案");
    connect(startButton,SIGNAL(clicked()), this, SLOT(start()));
    connect(quitButton,SIGNAL(clicked()), this, SLOT(close()));
    connect(&tcpServer, SIGNAL(newConnection()), this, SLOT(acceptConnection()));


}


TcpFileServer::~TcpFileServer() = default;

void TcpFileServer::start()
{
    startButton->setEnabled(false);
    bytesReceived = 0;
    fileNameSize  = 0;
    while(!tcpServer.isListening()) tcpServer.listen(QHostAddress::AnyIPv4, 16998);
    serverStatusLabel->setText("監聽中....");

}


void TcpFileServer::acceptConnection()
{

}

void TcpFileServer::updateServerProgress()
{

}
