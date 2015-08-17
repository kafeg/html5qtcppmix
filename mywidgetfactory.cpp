#include "mywidgetfactory.h"
#include <QTabWidget>
#include <QPushButton>
#include <QProgressBar>
#include <QDebug>
#include <QApplication>
#include <QUrl>

MyWidgetFactory::MyWidgetFactory(QObject *parent) :
    QWebPluginFactory(parent)
{
}

QList<QWebPluginFactory::Plugin> MyWidgetFactory::plugins() const
{
    QWebPluginFactory::MimeType mimeType;
    mimeType.name = "text/qtexample";
    mimeType.description = "Comma-separated values";
    mimeType.fileExtensions = QStringList() << "txt";

    QWebPluginFactory::Plugin plugin;
    plugin.name = "PluginFactory Example";
    plugin.description = "PluginFactory Example";
    plugin.mimeTypes = QList<MimeType>() << mimeType;

    return QList<QWebPluginFactory::Plugin>() << plugin;
}

QObject *MyWidgetFactory::create(const QString &mimeType,
                                const QUrl &url, const QStringList &argumentNames,
                                const QStringList &argumentValues) const
{
    qDebug() << mimeType << url << argumentNames << argumentValues;

    if (mimeType != "text/qtexample")
        return 0;

    QTabWidget *tab = new QTabWidget();

    int max = argumentValues.last().split(",").first().toInt();
    int val = argumentValues.last().split(",").last().toInt();

    QProgressBar *progressBar = new QProgressBar();
    tab->addTab(progressBar, "Progress");
    progressBar->setMaximum(max);
    progressBar->setValue(val);

    QPushButton *pb = new QPushButton("Click me!");
    tab->addTab(pb, "Button");
    connect(pb, SIGNAL(clicked()),QApplication::instance(), SLOT(quit()));

    return tab;
}
