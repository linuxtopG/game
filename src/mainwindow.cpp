#include "mainwindow.h"
#include <QWebEngineView>
#include <QVBoxLayout>
#include <QWidget>
#include <QDir>
#include <QUrl>
#include <QTimer>
#include <QProcess>
#include <QStandardPaths>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    webView = new QWebEngineView(this);
    setCentralWidget(webView);

    // ابدأ الخادم الداخلي
    startInternalServer();

    // انتظر قليلاً ثم حمل الصفحة
    QTimer::singleShot(2000, [this]() {
        webView->load(QUrl("http://localhost:8080"));
    });
}

void MainWindow::startInternalServer()
{
    // استخدم المسار النسبي من مكان بناء التطبيق
    QString webPath = "../web";

    if (!QDir(webPath).exists()) {
        qCritical() << "مجلد web غير موجود في" << webPath;
        return;
    }

    // ابدأ خادم Python
    serverProcess = new QProcess(this);
    QStringList args;
    args << "-m" << "http.server" << "8080" << "--directory" << webPath;

    serverProcess->start("python3", args);

    // اطبع ما يخرج من الخادم للتحقق
    connect(serverProcess, &QProcess::readyReadStandardOutput, [=]() {
        qDebug() << "Server Output:" << serverProcess->readAllStandardOutput();
    });

    connect(serverProcess, &QProcess::readyReadStandardError, [=]() {
        qWarning() << "Server Error:" << serverProcess->readAllStandardError();
    });

    serverProcess->waitForStarted();
}

MainWindow::~MainWindow()
{
    if (serverProcess) {
        serverProcess->terminate();
        serverProcess->waitForFinished(3000);  // انتظر 3 ثواني لإيقاف الخادم
    }
}
